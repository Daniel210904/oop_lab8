//
// Created by Daniel Pantiuc on 02.04.2024.
//

#include "ProductsService.h"

/** COS **/
const vector<Produs> &ProductsService::getAllCos() noexcept {
    return cos.getCos();
}

void ProductsService::generateCos(int nrProduse) {
    cos.genereazaCos(nrProduse, repo.getAll());
}

void ProductsService::exportCos(const string &nume) {
    cos.exportCos(nume);
}

void ProductsService::emptyCos() {
    cos.emptyCos();
}

void ProductsService::addCos(const string &nume, const string &tip, double pret, const string &producator) {
    auto produs = Produs(nume, tip, pret, producator);
    cos.addCos(produs);
}

double ProductsService::getPretTotalCos() {
    double pret = 0;
    for (const auto &produs : cos.getCos()) {
        pret += produs.getPret();
    }
    return pret;
}

/** PRODUSE **/
void ProductsService::adaugaProdus(const string &nume, const string &tip, double pret, const string &producator) {
    Produs produs{nume, tip, pret, producator};
    ProductsValidator::valideazaProdus(produs);
    repo.adaugaProdusRepo(produs);
}

void ProductsService::stergeProdus(const string &nume, const string &tip, double pret, const string &producator) {
    repo.stergeProdusRepo(Produs(nume, tip, pret, producator));
}

void ProductsService::modificaProdus(const string &nume, const string &tip, double pret, const string &producator, const string &newNume, const string &newTip, double newPret, const string &newProducator) {
    repo.modificaProdusRepo(Produs(nume, tip, pret, producator), Produs(newNume, newTip, newPret, newProducator));
}

const Produs &ProductsService::cautaProdus(const std::string &nume, const std::string &tip, double pret,
                                           const std::string &producator) {
    return repo.getProdus(nume, tip, pret, producator);
}

const vector<Produs> &ProductsService::getAll() noexcept {
    return this->repo.getAll();
}

//VectorDinamic<Produs> ProductsService::generalSort(bool (*cmpKey)(const Produs &, const Produs &)) {
//    VectorDinamic<Produs> produse{repo.getAll()};
//    for (int i = 0; i < produse.getSize() - 1; i++) {
//        for (int  j = i + 1; j < produse.getSize(); j++) {
//            if (!cmpKey(produse[i], produse[j])) {
//                Produs aux = produse[i];
//                produse[i] = produse[j];
//                produse[j] = aux;
//            }
//        }
//    }
//    return produse;
//}

//VectorDinamic <Produs> ProductsService::filter(const function<bool(const Produs &) > &filterKey) {
//    VectorDinamic <Produs> rezultat;
//    for (int i = 0; i < repo.getAll().getSize(); i++) {
//        if (filterKey(repo.getAll()[i])) {
//            rezultat.pushback(repo.getAll()[i]);
//        }
//    }
//    return rezultat;
//}

vector <Produs> ProductsService::filtreazaDupaPret(double pret) {
    vector <Produs> filtered;
    copy_if(repo.getAll().begin(), repo.getAll().end(), back_inserter(filtered), [pret](const Produs &produs) {
        return produs.getPret() == pret;
    });
    return filtered;
}

vector <Produs> ProductsService::filtreazaDupaNume(const std::string &nume) {
    vector <Produs> filtered;
    copy_if(repo.getAll().begin(), repo.getAll().end(), back_inserter(filtered), [nume](const Produs &produs) {
        return produs.getNume() == nume;
    });
    return filtered;
}

vector <Produs> ProductsService::filtreazaDupaProducator(const std::string &producator) {
    vector <Produs> filtered;
    copy_if(repo.getAll().begin(), repo.getAll().end(), back_inserter(filtered), [producator](const Produs &produs) {
        return produs.getProducator() == producator;
    });
    return filtered;
}

vector <Produs> ProductsService::sorteazaDupaNume() {
    auto sorted = repo.getAll();
    sort(sorted.begin(), sorted.end(), cmpNume);
    return sorted;
}

vector <Produs> ProductsService::sorteazaDupaPret() {
    auto sorted = repo.getAll();
    sort(sorted.begin(), sorted.end(), cmpPret);
    return sorted;
}

vector <Produs> ProductsService::sorteazaDupaNumeSiTip() {
    auto sorted = repo.getAll();
    sort(sorted.begin(), sorted.end(), cmpNumeSiTip);
    return sorted;
}

[[maybe_unused]] unordered_map <string, int> ProductsService::raportTipProdus() {
    unordered_map <string, int> raport;
    for (const auto &produs : repo.getAll())
            raport[produs.getTip()]++;
    return raport;
}