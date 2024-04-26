//
// Created by Daniel Pantiuc on 02.04.2024.
//

#ifndef LAB6_PRODUCTSUI_H
#define LAB6_PRODUCTSUI_H

#pragma once
#include "../service/ProductsService.h"
#include <iostream>
#include <string>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::ws;

class ProductsUI {
    ProductsService &service;

    void adaugaUI();

    void stergeUI();

    void modificaUI();

    void afiseazaProduseUI();

    void cautaUI();

    void filtreazaUI();

    void sorteazaUI();

    static void meniu();

    static void printeazaProduse(const vector<Produs> &produse);

    void addCosUI();

    void generateCosUI();

    void exportCosUI();

    void afiseazaCosUI();

    void emptyCosUI();

    void raportTipProdusUI();

public:
    explicit ProductsUI(ProductsService &service) : service{service} {}

    // nu permitem copierea obiectelor de tip ProductsUI
    ProductsUI(const ProductsUI &productsUI) = delete;

    void start();
};

#endif //LAB6_PRODUCTSUI_H
