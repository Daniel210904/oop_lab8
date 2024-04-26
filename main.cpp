#include "domain/Produs.h"
//#include "repository/ProductsRepo.h"
#include "service/ProductsService.h"
#include "ui/ProductsUI.h"
#include "utils/Utilities.h"
#include "tests/Tests.h"

int main () {
    Tests::testAll();
    FileProductsRepo repo{"../data/produse.txt"};
    ProductsValidator validator;
    CosRepo cos;
    ProductsService service {repo, validator, cos};
    ProductsUI ui{service};
    adauga10Produse(service);
    ui.start();
}