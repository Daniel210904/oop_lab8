//
// Created by Daniel Pantiuc on 26.04.2024.
//

#include "Utilities.h"

void adauga10Produse (ProductsService &service) {
    service.adaugaProdus("Hanorac", "Oversized", 359.99, "Nike");
    service.adaugaProdus("Pantaloni", "Regular", 249.90, "Nike");
    service.adaugaProdus("Tricou", "Regular", 210, "Gymshark");
    service.adaugaProdus("Stinger", "Slim", 125, "Gymshark");
    service.adaugaProdus("Hanorac", "Oversized", 400, "Gymshark");
    service.adaugaProdus("Pantaloni", "Straight", 160, "H&M");
    service.adaugaProdus("Bluza", "Oversized", 149.90, "Zara");
    service.adaugaProdus("Tricou", "Relaxed", 219.99, "Nike");
    service.adaugaProdus("Pantaloni", "Relaxed", 199.90, "Zara");
    service.adaugaProdus("Tricou", "Oversized", 100, "H&M");
}