cmake_minimum_required(VERSION 3.26)
project(lab6)

set(CMAKE_CXX_STANDARD 17, clang-tidy -checks=cppcoreguidelines-*)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew/bin/qmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(untitled10 main.cpp)
target_link_libraries(untitled10
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

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
        undo/Undo.cpp
        undo/Undo.h
        repository/FileProductsRepo.cpp
        repository/FileProductsRepo.h
)
