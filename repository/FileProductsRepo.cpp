//
// Created by Daniel Pantiuc on 27.04.2024.
//

#include "FileProductsRepo.h"
#include <fstream>

FileProductsRepo::FileProductsRepo(const std::string &name) {
    this->filename = name;
    loadRepository();
}

void FileProductsRepo::loadRepository() {
    std::ifstream fin(filename);
    string nume, tip, producator;
    double pret;
    while (fin >> nume >> tip >> pret >> producator) {
        Produs produs(nume, tip, pret, producator);
        this->adaugaProdusRepo(produs);
    }
}

void FileProductsRepo::saveRepository() {
    std::ofstream fout(filename);
    if (!fout.is_open())
        throw RepositoryException("Could not open file!\n");
    for (const auto &produs: this->getAll()) {
        fout << produs.getNume() << " " << produs.getTip() << " " << produs.getPret() << " " << produs.getProducator() << "\n";
    }
    fout.close();
}

void FileProductsRepo::emptyFile() {
    std::ofstream ofile(filename);
    ofile << "";
    ofile.close();
}