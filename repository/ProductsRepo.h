//
// Created by Daniel Pantiuc on 01.04.2024.
//

#ifndef LAB6_PRODUCTSREPO_H
#define LAB6_PRODUCTSREPO_H

#pragma once
#include <vector>
#include <string>
#include "../domain/Produs.h"
#include "../exceptions/Exceptions.h"

using std::vector;
using std::string;
using std::find_if;

class ProductsRepo {
private:
    vector<Produs> produse;

public:
    ProductsRepo() = default;

    ProductsRepo(const ProductsRepo &other) = default;

    /**
     * Functie care adauga un produs in lista de produse
     * produs - produsul pe care dorim sa il adaugam
     */
    void adaugaProdusRepo(const Produs &produs);

    /**
     * Functie care returneaza toate produsele
     * return - toate produsele
     */
    [[nodiscard]] const vector<Produs> &getAll() const noexcept;

    /**
     * Functie care sterge un produs din lista de produse
     * produs - produsul pe care dorim sa il stergem
     */
    void stergeProdusRepo(const Produs &produs);

    /**
     * Functie care modifica un produs din lista de produse
     * produs - produsul pe care dorim sa il modificam
     * newProdus - noul produs
     */
    void modificaProdusRepo(const Produs &produs, const Produs &newProdus);

    /**
     * Functie care cauta un produs in lista de produse
     * produs - produsul pe care dorim sa il cautam
     * return - indexul produsului in lista de produse
     */
    int cautaProdusRepo(const Produs &produs);

    /**
     * Functie care returneaza un produs din lista de produse
     * nume - numele produsului
     * tip - tipul produsului
     * pret - pretul produsului
     * producator - producatorul produsului
     * return - produsul cautat
     */
    const Produs &getProdus(const string &nume, const string &tip, double pret, const string &producator);
};

#endif //LAB6_PRODUCTSREPO_H
