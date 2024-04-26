//
// Created by Daniel Pantiuc on 23.04.2024.
//

#ifndef LAB6_COSREPO_H
#define LAB6_COSREPO_H

#include <vector>
#include "../domain/Produs.h"
#include <random>
#include <fstream>
#include <algorithm>

using std::vector;
using std::shuffle;

class CosRepo {
private:
    vector<Produs> Contract;
public:
    /**
     * Functie care goleste cosul
     */
    void emptyCos() noexcept;

    /**
     * Functie care adauga un produs in cos
     * @param produs - produsul care va fi adaugat in cos
     */
    void addCos(const Produs& produs);

    /**
     * Functie care returneaza toate produsele din cos
     * return - toate produsele din cos
     */
    void genereazaCos(int nr_produse, const vector<Produs>& memory);

    /**
     * Functie care returneaza toate produsele din cos
     * return - toate produsele din cos
     */
    void exportCos(const string& filename);

    /**
     * Functie care returneaza toate produsele din cos
     * return - toate produsele din cos
     */
    const vector<Produs>& getCos();
};

#endif //LAB6_COSREPO_H
