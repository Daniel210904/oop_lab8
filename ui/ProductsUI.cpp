//
// Created by Daniel Pantiuc on 02.04.2024.
//

#include "ProductsUI.h"

void ProductsUI::adaugaUI() {
    string nume, tip, producator;
    double pret;

    cout << "Introduceti numele produsului: ";
    getline(cin >> ws, nume);
    cout << "Introduceti tipul produsului: ";
    getline(cin >> ws, tip);
    cout << "Introduceti pretul produsului: ";
    cin >> pret;
    cout << "Introduceti producatorul produsului: ";
    getline(cin >> ws, producator);

    try {
        service.adaugaProdus(nume, tip, pret, producator);
        cout << "Produs adaugat cu succes!\n";
    } catch (const ValidationException &exception) {
        cout << exception.getMessage() << '\n';
    }
}

void ProductsUI::stergeUI() {
    string nume, tip, producator;
    double pret;

    cout << "Introduceti numele produsului: ";
    getline(cin >> ws, nume);
    cout << "Introduceti tipul produsului: ";
    getline(cin >> ws, tip);
    cout << "Introduceti pretul produsului: ";
    cin >> pret;
    cout << "Introduceti producatorul produsului: ";
    getline(cin >> ws, producator);

    try {
        service.stergeProdus(nume, tip, pret, producator);
        cout << "Produs sters cu succes!\n";
    } catch (const ValidationException &exception) {
        cout << exception.getMessage() << '\n';
    }
}

void ProductsUI::modificaUI() {
    string nume, tip, producator, numeNou, tipNou, producatorNou;
    double pret, pretNou;

    cout << "Introduceti numele initial al produsului: ";
    getline(cin >> ws, nume);
    cout << "Introduceti tipul initial al produsului: ";
    getline(cin >> ws, tip);
    cout << "Introduceti pretul initial produsului: ";
    cin >> pret;
    cout << "Introduceti producatorul initial al produsului: ";
    getline(cin >> ws, producator);
    cout << "Introduceti noul nume al produsului: ";
    getline(cin >> ws, numeNou);
    cout << "Introduceti noul tip al produsului: ";
    getline(cin >> ws, tipNou);
    cout << "Introduceti noul pret al produsului: ";
    cin >> pretNou;
    cout << "Introduceti noul producator al produsului: ";
    getline(cin >> ws, producatorNou);

    try {
        service.modificaProdus(nume, tip, pret, producator, numeNou, tipNou, pretNou, producatorNou);
        cout << "Produs modificat cu succes!\n";
    } catch (const ValidationException &exception) {
        cout << exception.getMessage() << '\n';
    }
}

void ProductsUI::printeazaProduse(const vector <Produs> &produse) {
    if (produse.empty())
        cout << "Nu exista produse momentan!\n";
    else
        for (const Produs& produs : produse)
            cout << produs.toString() << '\n';
}

void ProductsUI::afiseazaProduseUI() {
    vector <Produs> produse = service.getAll();
    printeazaProduse(produse);
}

void ProductsUI::cautaUI() {
    string nume, tip, producator;
    double pret;
    cout << "Introduceti numele produsului: ";
    getline(cin >> ws, nume);
    cout << "Introduceti tipul produsului: ";
    getline(cin >> ws, tip);
    cout << "Introduceti pretul produsului: ";
    cin >> pret;
    cout << "Introduceti producatorul produsului: ";
    getline(cin >> ws, producator);
    try {
        cout << service.cautaProdus(nume, tip, pret, producator).toString() << '\n';
    }
    catch (const RepositoryException &exception) {
        cout << exception.getMessage() << '\n';
    }
}

void ProductsUI::filtreazaUI() {
    cout << "1. Filtreaza dupa nume\n";
    cout << "2. Filtreaza dupa pret\n";
    cout << "3. Filtreaza dupa producator\n";
    cout << "Introduceti optiunea de filtrare: ";
    int optiune;
    cin >> optiune;

    if (optiune == 1) {
        string nume;
        cout << "Introduceti numele produsului: ";
        getline(cin >> ws, nume);
        vector <Produs> produse = service.filtreazaDupaNume(nume);
        printeazaProduse(produse);
    }
    else if (optiune == 2) {
        double pret;
        cout << "Introduceti pretul produsului: ";
        cin >> pret;
        vector <Produs> produse = service.filtreazaDupaPret(pret);
        printeazaProduse(produse);
    }
    else if (optiune == 3) {
        string producator;
        cout << "Introduceti producatorul produsului: ";
        getline(cin >> ws, producator);
        vector <Produs> produse = service.filtreazaDupaProducator(producator);
        printeazaProduse(produse);
    }
    else
        cout << "Optiune de filtrare invalida!\n";
}


void ProductsUI::sorteazaUI() {
    cout << "1. Sorteaza dupa nume\n";
    cout << "2. Sorteaza dupa pret\n";
    cout << "3. Sorteaza dupa nume si tip\n";
    cout << "Introduceti optiunea de sortare: ";
    int optiune;
    cin >> optiune;

    if (optiune == 1) {
        vector <Produs> produseSortate = service.sorteazaDupaNume();
        printeazaProduse(produseSortate);
    }
    else if (optiune == 2) {
        vector <Produs> produseSortate = service.sorteazaDupaPret();
        printeazaProduse(produseSortate);
    }
    else if (optiune == 3) {
        vector <Produs> produseSortate = service.sorteazaDupaNumeSiTip();
        printeazaProduse(produseSortate);
    }
    else
        cout << "Optiune de sortare invalida!\n";
}

void ProductsUI::addCosUI() {
    cout << "Ati ales sa adaugati un produs in cos.\nIntroduceti numele produsului: ";
    string nume;
    getline(cin >> ws, nume);
    auto found = service.filtreazaDupaNume(nume);
    if (found.empty()) {
        cout << "Produsul nu exista in lista de produse!\n";
    }
    else if (found.size() == 1) {
        service.addCos(nume, found[0].getTip(), found[0].getPret(), found[0].getProducator());
        cout << "Produs adaugat in cos cu succes!\n";
    }
    else {
        cout << "Exista mai multe produse cu numele " << nume << ". Aceasta este lista:\n";
        printeazaProduse(found);
        cout << "Introduceti tipul produsului: ";
        string tip;
        getline(cin >> ws, tip);
        cout << "Introduceti pretul produsului: ";
        double pret;
        cin >> pret;
        cout << "Introduceti producatorul produsului: ";
        string producator;
        getline(cin >> ws, producator);
        service.addCos(nume, tip, pret, producator);
    }
    double pret_curent = service.getPretTotalCos();
    cout << "Pretul total al cosului este: " << pret_curent << ".\n";
}

void ProductsUI::generateCosUI() {
    int nr;
    cout << "Introduceti numarul de produse pe care doriti sa le generati: ";
    cin >> nr;
    service.generateCos(nr);
    double pret_curent = service.getPretTotalCos();
    if (pret_curent == 0)
        cout << "Nu exista produse in lista.\n";
    else
        cout << "Cos generat cu succes!\n";
    cout << "Pretul total al cosului este: " << pret_curent << ".\n";
}

void ProductsUI::exportCosUI() {
    cout << "Introduceti numele fisierului in care doriti sa exportati cosul: ";
    string numeFisier;
    getline(cin >> ws, numeFisier);
    service.exportCos(numeFisier);
    cout << "Cos exportat cu succes!\n";
    double pret_curent = service.getPretTotalCos();
    cout << "Pretul total al cosului este: " << pret_curent << ".\n";
}

void ProductsUI::afiseazaCosUI() {
    vector <Produs> cos = service.getAllCos();
    if (cos.empty())
        cout << "Cosul este gol!\n";
    else {
        cout << "Cosul dumneavoastra contine urmatoarele produse:\n";
        for (const Produs &produs: cos)
            cout << produs.toString() << '\n';
    }
    double pret_curent = service.getPretTotalCos();
    cout << "Pretul total al cosului este: " << pret_curent << ".\n";
}

void ProductsUI::emptyCosUI() {
    service.emptyCos();
    cout << "Cos golit cu succes!\n";
    cout << "Pretul curent al cosului este: 0.\n";
}

void ProductsUI::raportTipProdusUI() {
    unordered_map<string, int> raport = service.raportTipProdus();
    if (raport.empty())
        cout << "Nu exista produse in lista.\n";
    else {
        cout << "Raportul tipurilor de produse este:\n";
        for (const auto &tip : raport)
            cout << tip.first << ": " << tip.second << " produse.\n";
    }
}

void ProductsUI::meniu() {
    cout << "\n";
    cout << "-----------------MENIU-----------------\n";
    cout << "Acestea sunt optiunile disponibile:\n";
    cout << "1. Adauga produs\n";
    cout << "2. Sterge produs\n";
    cout << "3. Modifica produs\n";
    cout << "4. Afiseaza produse\n";
    cout << "5. Cauta produs\n";
    cout << "6. Filtreaza produse\n";
    cout << "7. Sorteaza produse\n";
    cout << "8. Adauga produs in cos\n";
    cout << "9. Genereaza cos\n";
    cout << "10. Exporta cos\n";
    cout << "11. Afiseaza cos\n";
    cout << "12. Goleste cos\n";
    cout << "13. Raport tip produs\n";
    cout << "14. Undo\n";
    cout << "15. Afiseaza meniu\n";
    cout << "0. Iesire din aplicatie\n";
    cout << "---------------------------------------\n";
    cout << "\n";
}

void ProductsUI::start() {
    int optiune;
    bool ruleaza = true;
    cout << "Bun venit!\n";
    meniu();

    while (ruleaza) {
        cout << "Introduceti optiunea: ";
        cin >> optiune;

        switch (optiune) {
            case 1:
                try {
                    adaugaUI();
                }
                catch (const RepositoryException &exception) {
                    cout << exception.getMessage() << '\n';
                }
                catch (const ValidationException &exception) {
                    cout << exception.getMessage() << '\n';
                }
                break;
            case 2:
                try {
                    stergeUI();
                }
                catch (const RepositoryException &exception) {
                    cout << exception.getMessage() << '\n';
                }
                catch (const ValidationException &exception) {
                    cout << exception.getMessage() << '\n';
                }
                break;
            case 3:
                try {
                    modificaUI();
                }
                catch (const RepositoryException &exception) {
                    cout << exception.getMessage() << '\n';
                }
                catch (const ValidationException &exception) {
                    cout << exception.getMessage() << '\n';
                }
                break;
            case 4:
                afiseazaProduseUI();
                break;
            case 5:
                try {
                    cautaUI();
                }
                catch (const RepositoryException &exception) {
                    cout << exception.getMessage() << '\n';
                }
                catch (const ValidationException &exception) {
                    cout << exception.getMessage() << '\n';
                }
                break;
            case 6:
                try {
                    filtreazaUI();
                }
                catch (const RepositoryException &exception) {
                    cout << exception.getMessage() << '\n';
                }
                catch (const ValidationException &exception) {
                    cout << exception.getMessage() << '\n';
                }
                break;
            case 7:
                try {
                    sorteazaUI();
                }
                catch (const RepositoryException &exception) {
                    cout << exception.getMessage() << '\n';
                }
                catch (const ValidationException &exception) {
                    cout << exception.getMessage() << '\n';
                }
                break;
            case 8:
                addCosUI();
                break;
            case 9:
                generateCosUI();
                break;
            case 10:
                exportCosUI();
                break;
            case 11:
                afiseazaCosUI();
                break;
            case 12:
                emptyCosUI();
                break;
            case 13:
                raportTipProdusUI();
                break;
            case 14:
                try {
                    service.undo();
                    cout << "Operatie de undo efectuata cu succes!\n";
                }
                catch (const RepositoryException &exception) {
                    cout << exception.getMessage() << '\n';
                }
                break;
            case 15:
                meniu();
                break;
            case 0:
                cout << "\nAplicatia se inchide. La revedere!\n";
                ruleaza = false;
                break;
            default:
                cout << "Optiune invalida!\n";
        }
    }
}