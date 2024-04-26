//
// Created by Daniel Pantiuc on 02.04.2024.
//

#include "ProductsValidator.h"

void ProductsValidator::valideazaNume(const string &nume) {
    if (nume.empty()) {
        throw ValidationException("Numele nu poate fi vid!\n");
    }
}

void ProductsValidator::valideazaTip(const string &tip) {
    if (tip.empty()) {
        throw ValidationException("Tipul nu poate fi vid!\n");
    }
}

void ProductsValidator::valideazaPret(double pret) {
    if (pret <= 0) {
        throw ValidationException("Pretul trebuie sa fie pozitiv!\n");
    }
}

void ProductsValidator::valideazaProducator(const string &producator) {
    if (producator.empty()) {
        throw ValidationException("Producatorul nu poate fi vid!\n");
    }
}

void ProductsValidator::valideazaProdus(const Produs &produs) {
    const string &nume = produs.getNume();
    const string &tip = produs.getTip();
    double pret = produs.getPret();
    const string &producator = produs.getProducator();
    string exceptions;

    try {
        valideazaNume(nume);
    }
    catch (ValidationException &ve) {
        exceptions += ve.getMessage();
    }

    try {
        valideazaTip(tip);
    }
    catch (ValidationException &ve) {
        exceptions += ve.getMessage();
    }

    try {
        valideazaPret(pret);
    }
    catch (ValidationException &ve) {
        exceptions += ve.getMessage();
    }

    try {
        valideazaProducator(producator);
    }
    catch (ValidationException &ve) {
        exceptions += ve.getMessage();
    }

    if (!exceptions.empty()) {
        throw ValidationException(exceptions);
    }
}

