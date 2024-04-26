//
// Created by Daniel Pantiuc on 01.04.2024.
//

#include "ProductsRepo.h"

void ProductsRepo::adaugaProdusRepo(const Produs &produs) {
    const string &nume = produs.getNume();
    const string &tip = produs.getTip();
    double pret = produs.getPret();
    const string &producator = produs.getProducator();
    if (cautaProdusRepo(Produs(nume, tip, pret, producator)) == -1)
        this->produse.push_back(produs);
    else
        throw RepositoryException("Produsul exista deja in lista de produse!");
}

void ProductsRepo::stergeProdusRepo(const Produs &produs) {
    int index = this->cautaProdusRepo(produs);
    if (index != -1) {
        auto first = this->produse.begin();
        this->produse.erase(first + index);
    }
    else
        throw RepositoryException("Produsul nu exista in lista de produse!");
}

void ProductsRepo::modificaProdusRepo(const Produs &produs, const Produs &newProdus) {
    int index = this->cautaProdusRepo(produs);
    if (index != -1) {
        this->produse[index] = newProdus;
    }
    else {
        throw RepositoryException("Produsul nu exista in lista de produse!");
    }
}

int ProductsRepo::cautaProdusRepo(const Produs &produs) {
    auto it = find_if(this->produse.begin(), this->produse.end(), [&produs](const Produs &produsCautat) {
        if (produs.getNume() == produsCautat.getNume() && produs.getTip() == produsCautat.getTip() &&
            produs.getPret() == produsCautat.getPret() && produs.getProducator() == produsCautat.getProducator())
            return true;
        return false;
    });
    auto poz = std::distance(this->produse.begin(), it);
    if (it != this->produse.end())
        return poz;
    return -1;
}

const Produs &ProductsRepo::getProdus(const string &nume, const string &tip, double pret, const string &producator) {
    int index = this->cautaProdusRepo(Produs(nume, tip, pret, producator));
    if (index != -1) {
        return this->produse[index];
    }
    else {
        throw RepositoryException("Produsul nu exista in lista de produse!");
    }
}

const vector<Produs> &ProductsRepo::getAll() const noexcept {
    return this->produse;
}