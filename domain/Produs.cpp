//
// Created by Daniel Pantiuc on 01.04.2024.
//

#include "Produs.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using std::cout;

Produs::Produs(const string &nume, const string &tip, double pret, const string &producator) {
    this->nume = nume;
    this->tip = tip;
    this->pret = pret;
    this->producator = producator;
}

Produs::Produs() {
    this->nume = "";
    this->tip = "";
    this->pret = 0;
    this->producator = "";
}

Produs::~Produs() = default;

// copy constructor
Produs::Produs(const Produs &produs) {
    this->nume = produs.nume;
    this->tip = produs.tip;
    this->pret = produs.pret;
    this->producator = produs.producator;
}

const string &Produs::getNume() const {
    return nume;
}

const string &Produs::getTip() const {
    return tip;
}

double Produs::getPret() const {
    return pret;
}

const string &Produs::getProducator() const {
    return producator;
}

[[maybe_unused]] void Produs::setNume(const string &numeSetat) {
    this->nume = numeSetat;
}

[[maybe_unused]] void Produs::setTip(const string &tipSetat) {
    this->tip = tipSetat;
}

[[maybe_unused]] void Produs::setPret(double pretSetat) {
    this->pret = pretSetat;
}

[[maybe_unused]] void Produs::setProducator(const string &producatorSetat) {
    this->producator = producatorSetat;
}

string Produs:: toString() const {
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(2) << pret;
    return "Nume: " + this->nume + ", Tip: " + this->tip + ", Pret: " + ss.str() + ", Producator: " + this->producator;
}

Produs &Produs::operator = (const Produs &other) = default;

bool Produs::operator==(const Produs &other) {
    return this->nume == other.nume && this->tip == other.tip && this->pret == other.pret && this->producator == other.producator;
}

bool cmpNume(const Produs &p1, const Produs &p2) {
    return p1.getNume() < p2.getNume();
}

bool cmpPret(const Produs &p1, const Produs &p2) {
    return p1.getPret() < p2.getPret();
}

bool cmpNumeSiTip(const Produs &p1, const Produs &p2) {
    if (p1.getNume() < p2.getNume())
        return true;
    if (p1.getNume() > p2.getNume())
        return false;
    if (p1.getNume() == p2.getNume()) {
        if (p1.getTip() < p2.getTip())
            return true;
        else if (p1.getTip() > p2.getTip())
            return false;
    }
    return false;
}