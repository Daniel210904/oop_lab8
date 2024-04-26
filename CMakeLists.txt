cmake_minimum_required(VERSION 3.26)
project(lab6)

set(CMAKE_CXX_STANDARD 17, clang-tidy -checks=cppcoreguidelines-*)

add_executable(lab6 main.cpp
        domain/Produs.cpp
        domain/Produs.h
        repository/ProductsRepo.cpp
        repository/ProductsRepo.h
        exceptions/Exceptions.h
        service/ProductsService.cpp
        service/ProductsService.h
        validator/ProductsValidator.cpp
        validator/ProductsValidator.h
        ui/ProductsUI.cpp
        ui/ProductsUI.h
        tests/Tests.cpp
        tests/Tests.h
        VectorDinamic.h
        repository/CosRepo.cpp
        repository/CosRepo.h
        utils/Utilities.cpp
        utils/Utilities.h
)
