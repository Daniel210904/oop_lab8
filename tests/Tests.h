//
// Created by Daniel Pantiuc on 03.04.2024.
//

#ifndef LAB6_TESTS_H
#define LAB6_TESTS_H

#include "../domain/Produs.h"
#include "../repository/ProductsRepo.h"
#include "../repository/CosRepo.h"
#include "../service/ProductsService.h"
#include "../validator/ProductsValidator.h"
#include "../exceptions/Exceptions.h"
#include "../utils/Utilities.h"
#include <cassert>

class Tests {
    static void testConstructorandGetters();
    static void testSetters();
    static void testToString();
    static void testOperator();
    static void testComparators();

    static void testAdaugaProdusRepo();
    static void testStergeProdusRepo();
    static void testModificaProdusRepo();
    static void testCautaProdusRepo();
    static void testGetProdus();

    static void testCosRepo();

    static void testValidator();

    static void testAdaugaProdusService();
    static void testStergeProdusService();
    static void testModificaProdusService();
    static void testGetAll();
    static void testFilterService();
    static void testSortService();
    static void testRaportTipProdusService();

    static void testCosService();

    static void testUtils();
public:
    Tests() = default;
    void static testAll();
    ~Tests()= default;
};
#endif //LAB6_TESTS_H
