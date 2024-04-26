//
// Created by Daniel Pantiuc on 27.04.2024.
//

#ifndef LAB6_FILEPRODUCTSREPO_H
#define LAB6_FILEPRODUCTSREPO_H

#include "ProductsRepo.h"

class FileProductsRepo: public ProductsRepo {
private:
    string filename;
public:
    void loadRepository();
    void saveRepository();
    void emptyFile();
    explicit FileProductsRepo(const string &filename);

    ~FileProductsRepo() = default;
};

#endif //LAB6_FILEPRODUCTSREPO_H
