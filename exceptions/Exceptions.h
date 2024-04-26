//
// Created by Daniel Pantiuc on 01.04.2024.
//

#ifndef LAB6_EXCEPTIONS_H
#define LAB6_EXCEPTIONS_H

#pragma once
#include <exception>
#include <string>
#include <utility>

using std::string;

class RepositoryException : public std::exception {
    string message;

public:
    explicit RepositoryException(string message) : message{std::move(message)} {}

    [[nodiscard]] string getMessage() const {
        return this->message;
    }
};

class ValidationException : public std::exception {
    string message;

public:
    explicit ValidationException(string message) : message{std::move(message)} {}

    [[nodiscard]] string getMessage() const {
        return this->message;
    }
};

#endif //LAB6_EXCEPTIONS_H
