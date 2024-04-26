//
// Created by Daniel Pantiuc on 02.04.2024.
//

#ifndef LAB6_PRODUCTSVALIDATOR_H
#define LAB6_PRODUCTSVALIDATOR_H

#pragma once
#include "../exceptions/Exceptions.h"
#include "../domain/Produs.h"

using std::string;

class ProductsValidator {
private:
    static void valideazaNume(const string &nume);

    static void valideazaTip(const string &tip);

    static void valideazaPret(double pret);

    static void valideazaProducator(const string &producator);

public:
    static void valideazaProdus(const Produs &produs);
};

#endif //LAB6_PRODUCTSVALIDATOR_H
