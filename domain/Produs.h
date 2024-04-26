//
// Created by Daniel Pantiuc on 01.04.2024.
//

#ifndef LAB6_PRODUS_H
#define LAB6_PRODUS_H
#pragma once

#include <iostream>
#include <string>

using std::string;

class Produs {
private:
    string nume;
    string tip;
    double pret;
    string producator;

public:
    /**
     * Constructorul clasei Produs
     * @param nume - numele produsului
     * @param tip - tipul produsului
     * @param pret - pretul produsului
     * @param producator - producatorul produsului
     */
    Produs(const string& nume, const string& tip, double pret, const string& producator);

    /**
     * Constructor implicit al clasei Produs
     */
    Produs ();

    /**
     * Destructorul clasei Produs
     */
    ~Produs();

    /**
     * Copy constructor al clasei Produs
     */
    Produs(const Produs &produs);

    /**
     * Getters
     */
     [[nodiscard]] const string &getNume() const;
     [[nodiscard]] const string &getTip() const;
     [[nodiscard]] double getPret() const;
     [[nodiscard]] const string &getProducator() const;

    /**Setters**/
    [[maybe_unused]] void setNume(const string &nume);
    [[maybe_unused]] void setTip(const string &tip);
    [[maybe_unused]] void setPret(double pret);
    [[maybe_unused]] void setProducator(const string &producator);

    /**
     * Functie de afisare a unui produs
     */
     [[nodiscard]] string toString() const;

     /**Operatori**/
     Produs& operator=(const Produs &other);

     bool operator==(const Produs &other);
};

/**Comparatori**/

bool cmpNume(const Produs &p1, const Produs &p2);
bool cmpPret(const Produs &p1, const Produs &p2);
bool cmpNumeSiTip(const Produs &p1, const Produs &p2);

#endif //LAB6_PRODUS_H
