//
// Created by Daniel Pantiuc on 27.04.2024.
//

#ifndef LAB6_UNDO_H
#define LAB6_UNDO_H

#include "../domain/Produs.h"
#include "../repository/ProductsRepo.h"

class ActiuneUndo {
public:
    virtual void doUndo() = 0;

    //destructor virtuaL
    virtual ~ActiuneUndo() = default;
};

/** Clasa pentru UndoAdauga care mosteneste actiunile clasei ActiuneUndo */
class UndoAdauga: public ActiuneUndo {
    Produs produs;
    ProductsRepo& repo;
public:
    UndoAdauga(const Produs& produs, ProductsRepo &repo): repo{repo}, produs(produs) {};
    void doUndo() override {
        repo.stergeProdusRepo(produs);
    }
};

/** Clasa UndoSterge care mostenesste actiunile clasei ActiuneUndo */
class UndoSterge: public ActiuneUndo {
    Produs produs;
    ProductsRepo& repo;
public:
    UndoSterge(const Produs& produs, ProductsRepo &repo): repo{repo}, produs(produs) {};
    void doUndo() override {
        repo.adaugaProdusRepo(produs);
    }
};

/** Clasa UndoModifica care mosteneste actiunile clasei ActiuneUndo */
class UndoModifica: public ActiuneUndo {
    Produs produsVechi;
    Produs produsNou;
    ProductsRepo& repo;
public:
    UndoModifica(const Produs& produsVechi, const Produs& produsNou, ProductsRepo &repo): repo{repo}, produsVechi(produsVechi), produsNou(produsNou) {};
    void doUndo() override {
        repo.modificaProdusRepo(produsNou, produsVechi);
    }
};

#endif //LAB6_UNDO_H
