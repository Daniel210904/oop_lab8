//
// Created by Daniel Pantiuc on 03.04.2024.
//

#include "Tests.h"
#include <iostream>

using std::cout;

void Tests::testAll() {
    cout << "Running tests...\n";
    testConstructorandGetters();
    testSetters();
    testToString();
    testOperator();
    testComparators();

    testAdaugaProdusRepo();
    testStergeProdusRepo();
    testModificaProdusRepo();
    testCautaProdusRepo();
    testGetProdus();

    testCosRepo();

    testValidator();

   testAdaugaProdusService();
   testStergeProdusService();
    testModificaProdusService();
    testGetAll();
    testFilterService();
    testSortService();
    testRaportTipProdusService();
    testUndoService();

    testFileRepository();

    testCosService();

    testUtils();

    cout << "All tests passed!\n\n";
}

void Tests::testConstructorandGetters() {
    Produs produs{"nume", "tip", 10, "producator"};
    assert(produs.getNume() == "nume");
    assert(produs.getTip() == "tip");
    assert(produs.getPret() == 10);
    assert(produs.getProducator() == "producator");
    Produs produs2;
    assert(produs2.getNume().empty());
    assert(produs2.getTip().empty());
    assert(produs2.getPret() == 0);
    assert(produs2.getProducator().empty());
}

void Tests::testSetters() {
    Produs produs{"nume", "tip", 10, "producator"};
    produs.setNume("nume2");
    produs.setTip("tip2");
    produs.setPret(20);
    produs.setProducator("producator2");
    assert(produs.getNume() == "nume2");
    assert(produs.getTip() == "tip2");
    assert(produs.getPret() == 20);
    assert(produs.getProducator() == "producator2");
}

void Tests::testToString() {
    Produs produs{"nume", "tip", 10, "producator"};
    assert(produs.toString() == "Nume: nume, Tip: tip, Pret: 10.00, Producator: producator");
}

void Tests::testOperator() {
    Produs produs{"nume", "tip", 10, "producator"};
    Produs produs2{"nume", "tip", 10, "producator"};
    assert(produs == produs2);
}

void Tests::testComparators() {
    Produs produs1{"nume1", "tip1", 10, "producator1"};
    Produs produs2{"nume2", "tip2", 20, "producator2"};
    Produs produs3{"nume1", "tip2", 20, "producator2"};
    assert(cmpNume(produs1, produs2) == true);
    assert(cmpPret(produs1, produs2) == true);
    assert(cmpNumeSiTip(produs1, produs2) == true);
    assert(cmpNumeSiTip(produs2, produs1) == false);
    assert(cmpNumeSiTip(produs1, produs3) == true);
    assert(cmpNumeSiTip(produs3, produs1) == false);
    assert(cmpNumeSiTip(produs1, produs1) == false);
}

void Tests::testAdaugaProdusRepo() {
    ProductsRepo repo;
    Produs produs{"nume", "tip", 10, "producator"};
    repo.adaugaProdusRepo(produs);
    try {
        repo.adaugaProdusRepo(produs);
        assert(false);
    }
    catch (RepositoryException &exception) {
        assert(true);
    }
}

void Tests::testStergeProdusRepo() {
    ProductsRepo repo;
    Produs produs{"nume", "tip", 10, "producator"};
    repo.adaugaProdusRepo(produs);
    repo.stergeProdusRepo(produs);
    try {
        repo.stergeProdusRepo(produs);
        assert(false);
    }
    catch (RepositoryException &exception) {
        assert(true);
    }
}

void Tests::testModificaProdusRepo() {
    ProductsRepo repo;
    Produs produs{"nume", "tip", 10, "producator"};
    Produs newProdus{"nume2", "tip2", 20, "producator2"};
    repo.adaugaProdusRepo(produs);
    repo.modificaProdusRepo(produs, newProdus);
    try {
        repo.modificaProdusRepo(produs, newProdus);
        assert(false);
    }
    catch (RepositoryException &exception) {
        assert(true);
    }
}

void Tests::testCautaProdusRepo() {
    ProductsRepo repo;
    Produs produs{"nume", "tip", 10, "producator"};
    repo.adaugaProdusRepo(produs);
    assert((Produs) repo.getProdus("nume", "tip", 10, "producator") == produs);
}

void Tests::testGetProdus() {
    ProductsRepo repo;
    Produs produs{"nume", "tip", 10, "producator"};
    repo.adaugaProdusRepo(produs);
    assert((Produs) repo.getProdus("nume", "tip", 10, "producator") == produs);
}

void Tests::testCosRepo() {
    // adauga cos
    CosRepo cos;
    Produs produs{"nume", "tip", 10, "producator"};
    cos.addCos(produs);
    assert(cos.getCos().size() == 1);

    // goleste cos
    cos.emptyCos();
    assert(cos.getCos().size() == 0);

    // genereaza cos
    vector<Produs> produse;
    produse.push_back(Produs{"nume", "tip", 10, "producator"});
    produse.push_back(Produs{"nume2", "tip2", 20, "producator2"});
    produse.push_back(Produs{"nume3", "tip3", 30, "producator3"});
    cos.genereazaCos(3, produse);
    assert(cos.getCos().size() == 3);
    cos.genereazaCos(4, produse);
    assert(cos.getCos().size() == 4);


    // export cos
    cos.exportCos("test.txt");
    std::ifstream fin2("test.txt.html");
    assert(fin2.good());
    fin2.close();
    remove("test.txt.html");
    cos.exportCos("test");
    std::ifstream fin3("test.html");
    assert(fin3.good());
    fin3.close();
    remove("test.html");
    cos.exportCos("test.txt.html");
    std::ifstream fin4("test.txt.html");
    assert(fin4.good());
    fin4.close();
    remove("test.txt.html");
}

void Tests::testValidator() {
    Produs produs{"nume", "tip", 10, "producator"};
    ProductsValidator::valideazaProdus(produs);
    Produs produsGresit{"", "", -1, ""};
    try {
        ProductsValidator::valideazaProdus(produsGresit);
        assert(false);
    }
    catch (ValidationException &exception) {
        assert(true);
    }
}

void Tests::testAdaugaProdusService() {
    FileProductsRepo repo{"../data/tests.txt"};
    repo.emptyFile();
    ProductsValidator validator;
    CosRepo cos;
    ProductsService service{repo, validator, cos};
    service.adaugaProdus("nume", "tip", 10, "producator");
    assert(((Produs) service.cautaProdus("nume", "tip", 10, "producator") == Produs{"nume", "tip", 10, "producator"}));
    assert((service.getAll().size() == 1));
    repo.emptyFile();
}

void Tests::testStergeProdusService() {
    FileProductsRepo repo{"../data/tests.txt"};
    repo.emptyFile();
    ProductsValidator validator;
    CosRepo cos;
    ProductsService service{repo, validator, cos};
    service.adaugaProdus("nume", "tip", 10, "producator");
    service.stergeProdus("nume", "tip", 10, "producator");
    try {
        service.cautaProdus("nume", "tip", 10, "producator");
        assert(false);
    } catch (RepositoryException &exception) {
        assert(true);
    }
    repo.emptyFile();
}

void Tests::testModificaProdusService() {
    FileProductsRepo repo{"../data/tests.txt"};
    repo.emptyFile();
    ProductsValidator validator;
    CosRepo cos;
    ProductsService service{repo, validator, cos};
    service.adaugaProdus("nume", "tip", 10, "producator");
    service.modificaProdus("nume", "tip", 10, "producator", "nume2", "tip2", 20, "producator2");
    assert(((Produs) service.cautaProdus("nume2", "tip2", 20, "producator2") == Produs{"nume2", "tip2", 20, "producator2"}));
    repo.emptyFile();
}

void Tests::testGetAll() {
    FileProductsRepo repo{"../data/tests.txt"};
    repo.emptyFile();
    ProductsValidator validator;
    CosRepo cos;
    ProductsService service{repo, validator, cos};
    service.adaugaProdus("nume", "tip", 10, "producator");
    assert(service.getAll().size() == 1);
    repo.emptyFile();
}

void Tests::testFilterService() {
    FileProductsRepo repo{"../data/tests.txt"};
    repo.emptyFile();
    ProductsValidator validator;
    CosRepo cos;
    ProductsService service{repo, validator, cos};
    service.adaugaProdus("nume", "tip", 10, "producator");
    service.adaugaProdus("nume2", "tip2", 20, "producator2");
    service.adaugaProdus("nume3", "tip3", 30, "producator3");
    vector<Produs> produse = service.filtreazaDupaPret(10);
    assert((produse[0] == Produs{"nume", "tip", 10, "producator"}));
    vector<Produs> produse2 = service.filtreazaDupaNume("nume2");
    assert((produse2[0] == Produs{"nume2", "tip2", 20, "producator2"}));
    vector<Produs> produse3 = service.filtreazaDupaProducator("producator3");
    assert((produse3[0] == Produs{"nume3", "tip3", 30, "producator3"}));
    repo.emptyFile();
}

void Tests::testSortService() {
    FileProductsRepo repo{"../data/tests.txt"};
    repo.emptyFile();
    ProductsValidator validator;
    CosRepo cos;
    ProductsService service{repo, validator, cos};
    service.adaugaProdus("nume", "tip", 10, "producator");
    service.adaugaProdus("nume2", "tip2", 20, "producator2");
    service.adaugaProdus("nume3", "tip3", 30, "producator3");
    vector<Produs> produse = service.sorteazaDupaNume();
    assert((produse[0] == Produs{"nume", "tip", 10, "producator"}));
    assert((produse[1] == Produs{"nume2", "tip2", 20, "producator2"}));
    assert((produse[2] == Produs{"nume3", "tip3", 30, "producator3"}));
    vector<Produs> produse2 = service.sorteazaDupaPret();
    assert((produse2[0] == Produs{"nume", "tip", 10, "producator"}));
    assert((produse2[1] == Produs{"nume2", "tip2", 20, "producator2"}));
    assert((produse2[2] == Produs{"nume3", "tip3", 30, "producator3"}));
    vector<Produs> produse3 = service.sorteazaDupaNumeSiTip();
    assert((produse3[0] == Produs{"nume", "tip", 10, "producator"}));
    assert((produse3[1] == Produs{"nume2", "tip2", 20, "producator2"}));
    assert((produse3[2] == Produs{"nume3", "tip3", 30, "producator3"}));
    repo.emptyFile();
}

void Tests::testRaportTipProdusService() {
    FileProductsRepo repo{"../data/tests.txt"};
    repo.emptyFile();
    ProductsValidator validator;
    CosRepo cos;
    ProductsService service{repo, validator, cos};
    service.adaugaProdus("nume", "tip", 10, "producator");
    unordered_map<string, int> raport = service.raportTipProdus();
    assert(raport["tip"] == 1);
    repo.emptyFile();
}

void Tests::testFileRepository() {
    FileProductsRepo repo{"../data/tests.txt"};
    repo.emptyFile();
    assert(repo.getAll().size() == 0);
    try {
        repo.loadRepository();
        assert(true);
    }
    catch (RepositoryException &exception) {
        assert(false);
    }
    try {
        repo.saveRepository();
        assert(true);
    }
    catch (RepositoryException &exception) {
        assert(false);
    }
    repo.emptyFile();
}

void Tests::testCosService() {
    FileProductsRepo repo{"../data/tests.txt"};
    repo.emptyFile();
    ProductsValidator validator;
    CosRepo cos;
    ProductsService service{repo, validator, cos};

    // adauga cos
    service.adaugaProdus("nume", "tip", 10, "producator");
    service.adaugaProdus("nume2", "tip2", 20, "producator2");
    service.adaugaProdus("nume3", "tip3", 30, "producator3");
    service.addCos("nume", "tip", 10, "producator");
    service.addCos("nume2", "tip2", 20, "producator2");
    service.addCos("nume3", "tip3", 30, "producator3");
    assert(service.getPretTotalCos() == 60);

    // goleste cos
    service.emptyCos();
    assert(service.getPretTotalCos() == 0);

    // export cos
    service.addCos("nume", "tip", 10, "producator");
    service.addCos("nume2", "tip2", 20, "producator2");
    service.addCos("nume3", "tip3", 30, "producator3");
    service.exportCos("test.txt");
    std::ifstream fin2("test.txt.html");
    assert(fin2.good());
    fin2.close();
    remove("test.txt.html");

    // genereaza cos
    service.generateCos(3);
    assert(service.getAllCos().size() == 3);
    repo.emptyFile();
}

void Tests::testUndoService() {
    FileProductsRepo repo{"../data/tests.txt"};
    repo.emptyFile();
    ProductsValidator validator;
    CosRepo cos;
    ProductsService service{repo, validator, cos};
    service.adaugaProdus("nume", "tip", 10, "producator");
    service.stergeProdus("nume", "tip", 10, "producator");
    service.undo();
    assert(service.getAll().size() == 1);
    service.modificaProdus("nume", "tip", 10, "producator", "nume2", "tip2", 20, "producator2");
    service.undo();
    assert(service.getAll().size() == 1);
    service.undo();
    assert(service.getAll().size() == 0);
    try {
        service.undo();
        assert(false);
    }
    catch (RepositoryException &exception) {
        assert(true);
    }
}

void Tests::testUtils() {
    FileProductsRepo repo{"../data/tests.txt"};
    repo.emptyFile();
    ProductsValidator validator;
    CosRepo cos;
    ProductsService service{repo, validator, cos};
    adauga10Produse(service);
    assert(service.getAll().size() == 10);
    repo.emptyFile();
}