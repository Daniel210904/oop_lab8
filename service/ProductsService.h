//
// Created by Daniel Pantiuc on 02.04.2024.
//

#ifndef LAB6_PRODUCTSSERVICE_H
#define LAB6_PRODUCTSSERVICE_H

#pragma once
#include "../validator/ProductsValidator.h"
#include "../repository/FileProductsRepo.h"
#include "../repository/CosRepo.h"
#include "../undo/Undo.h"
#include <string>
#include <vector>
#include <functional>
#include <random>
#include <memory>
#include <algorithm>

using std::copy_if;
using std::shuffle;
using std::string;
using std::vector;
using std::function;
using std::unordered_map;
using std::unique_ptr;

class ProductsService {
private:
    FileProductsRepo &repo;
    [[maybe_unused]] ProductsValidator &validator;
    CosRepo &cos;
    std::vector<unique_ptr<ActiuneUndo>> undoActions;

    /**
     * Functie care sorteaza produsele dupa un criteriu dat
     * cmpKey - functie care compara doua produse dupa un anumit criteriu
     * return - vector de produse sortate
     */
    //vector<Produs> generalSort(bool(*cmpKey)(const Produs &, const Produs &));

    /**
     * Functie care filtreaza produsele dupa un criteriu dat
     * filterKey - functie care verifica daca un produs respecta un anumit criteriu
     * return - doar produsele care respecta criteriul
     */
    //vector<Produs> filter(const function<bool(const Produs &)> &filterKey);

public:
    /**
     * Functie care returneaza toate produsele din cos
     * return - toate produsele din cos
     */
    const vector<Produs> &getAllCos() noexcept;

    /**
     * Functie care adauga un produs in cos
     * @param nume
     * @param tip
     * @param pret
     * @param producator
     */
    void addCos(const string &nume, const string &tip, double pret, const string &producator);

    /**
     * Functie care genereaza un cos de cumparaturi
     * @param nrProduse
     */
    void generateCos(int nrProduse);

    /**
     * Functie care exporta cosul de cumparaturi intr-un fisier
     * @param nume
     */
    void exportCos(const string &nume);

    /**
     * Functie care goleste cosul de cumparaturi
     */
    void emptyCos();

    /**
     * Functie care calculeaza pretul total al produselor din cos
     * return - pretul total al produselor din cos
     */
    double getPretTotalCos();

    ProductsService(FileProductsRepo &repo, ProductsValidator &validator, CosRepo &cos) : repo{repo}, validator{validator}, cos{cos} {}

    // nu permitem copierea obiectelor de tip ProductsService
    ProductsService(const ProductsService &other) = delete;

    /**
     * Functie care returneaza toate produsele
     * return - toate produsele
     */
    const vector<Produs> & getAll() noexcept;

    /**
     * Functie care adauga un produs in lista de produse
     * nume - numele produsului
     * tip - tipul produsului
     * pret - pretul produsului
     * producator - producatorul produsului
     */
    void adaugaProdus(const string &nume, const string &tip, double pret, const string &producator);

    /**
     * Functie care sterge un produs din lista de produse
     * nume - numele produsului
     * tip - tipul produsului
     * pret - pretul produsului
     * producator - producatorul produsului
     */
    void stergeProdus(const string &nume, const string &tip, double pret, const string &producator);

    /**
     * Functie care modifica un produs din lista de produse
     * nume - numele produsului
     * tip - tipul produsului
     * pret - pretul produsului
     * producator - producatorul produsului
     * numeNou - noul nume al produsului
     * tipNou - noul tip al produsului
     * pretNou - noul pret al produsului
     * producatorNou - noul producator al produsului
     */
    void modificaProdus(const string &nume, const string &tip, double pret, const string &producator, const string &numeNou,
                   const string &tipNou, double pretNou, const string &producatorNou);

    /**
     * Functie care cauta un produs in lista de produse
     * Throws RepositoryException - daca produsul nu exista in lista de produse
     */
    const Produs &cautaProdus(const string &nume, const string &tip, double pret, const string &producator);

    /**Filters**/
    vector<Produs> filtreazaDupaPret(double pret);

    vector<Produs> filtreazaDupaNume(const string &nume);

    vector<Produs> filtreazaDupaProducator(const string &producator);

    /**Sorts**/
    vector<Produs> sorteazaDupaNume();

    vector<Produs> sorteazaDupaPret();

    vector<Produs> sorteazaDupaNumeSiTip();

    /**
     * Functie care creeaza un raport cu toate produsele de un anumit tip.
     */
    [[maybe_unused]] unordered_map<string, int> raportTipProdus();

    /**
     * Functie care face operatia de undo
     */
    void undo();
};

#endif //LAB6_PRODUCTSSERVICE_H
