//
// Created by Daniel Pantiuc on 01.04.2024.
//

#ifndef LAB6_PRODUCTSREPO_H
#define LAB6_PRODUCTSREPO_H

#pragma once
#include <vector>
#include <string>
#include <map>
#include "../domain/Produs.h"
#include "../exceptions/Exceptions.h"

using std::vector;
using std::string;
using std::find_if;

class AbstractRepo {
public:
    virtual void adaugaProdusRepo(const Produs &produs) = 0;
    virtual void stergeProdusRepo(const Produs &produs) = 0;
    virtual void modificaProdusRepo(const Produs &produs, const Produs &newProdus) = 0;
    virtual int cautaProdusRepo(const Produs &produs) = 0;
    virtual const Produs &getProdus(const string &nume, const string &tip, double pret, const string &producator) = 0;
    virtual const vector<Produs> &getAll() const noexcept = 0;
    virtual ~AbstractRepo() = default;
};

class ProductsRepo: public AbstractRepo {
private:
    vector<Produs> produse;

public:
    ProductsRepo() = default;

    ProductsRepo(const ProductsRepo &other) = default;

    /**
     * Functie care adauga un produs in lista de produse
     * produs - produsul pe care dorim sa il adaugam
     */
    virtual void adaugaProdusRepo(const Produs &produs);

    /**
     * Functie care returneaza toate produsele
     * return - toate produsele
     */
    [[nodiscard]] virtual const vector<Produs> &getAll() const noexcept;

    /**
     * Functie care sterge un produs din lista de produse
     * produs - produsul pe care dorim sa il stergem
     */
    virtual void stergeProdusRepo(const Produs &produs);

    /**
     * Functie care modifica un produs din lista de produse
     * produs - produsul pe care dorim sa il modificam
     * newProdus - noul produs
     */
    virtual void modificaProdusRepo(const Produs &produs, const Produs &newProdus);

    /**
     * Functie care cauta un produs in lista de produse
     * produs - produsul pe care dorim sa il cautam
     * return - indexul produsului in lista de produse
     */
    virtual int cautaProdusRepo(const Produs &produs);

    /**
     * Functie care returneaza un produs din lista de produse
     * nume - numele produsului
     * tip - tipul produsului
     * pret - pretul produsului
     * producator - producatorul produsului
     * return - produsul cautat
     */
    virtual const Produs &getProdus(const string &nume, const string &tip, double pret, const string &producator);
};

class ProbabilityRepo: public AbstractRepo {
private:
    float probability;
    int numProducts;
    std::map<int, Produs> productsList;
    vector <Produs> products;
    void probabilitate() const;

public:
    /** Aceleasi functionalitati ca si abstrct repo. **/
    ProbabilityRepo() : probability{1.0}{};
    explicit ProbabilityRepo(float prob);
    void adaugaProdusRepo(const Produs &produs) override;
    void stergeProdusRepo(const Produs &produs) override;
    void modificaProdusRepo(const Produs &produs, const Produs &newProdus) override;
    int cautaProdusRepo(const Produs &produs) override;
    const Produs &getProdus(const string &nume, const string &tip, double pret, const string &producator) override;
    const vector<Produs> &getAll() const noexcept override;
    ~ProbabilityRepo() override = default;
};

#endif //LAB6_PRODUCTSREPO_H
