//
// Created by Daniel Pantiuc on 11.04.2024.
//

#ifndef LAB6_VECTORDINAMIC_H
#define LAB6_VECTORDINAMIC_H

#define CAPACITATE_INITIALA 2

template <typename ElementGeneric>
class IteratorVector;
template <typename ElementGeneric>
class VectorDinamic {
private:
    ElementGeneric* elemente;
    int lungime;
    int capacitate;
    void ensureCapacity([[maybe_unused]] int factor = 2);
public:
    //CONSTRUCTOR - implementat
    VectorDinamic();
    //DESTRUCTOR - implementat
    ~VectorDinamic();
    //CONSTRUCTOR DE COPIERE - implementat
    VectorDinamic(const VectorDinamic& vector);

    /**OPERATORI**/
    /**assingment operator**/
    VectorDinamic& operator=(const VectorDinamic& vector);

    /**Move constructor**/
    VectorDinamic(VectorDinamic&& vector) noexcept;

    /**Move assignment operator**/
    VectorDinamic& operator=(VectorDinamic&& vector) noexcept;

    /**add to vector**/
    void pushback(const ElementGeneric& element);

    /**get a certain element**/
    [[maybe_unused]] ElementGeneric& get(int poz) const;

    /**set a certain element**/
    [[maybe_unused]] void set(int poz, const ElementGeneric& element);

    /**size**/
    [[nodiscard]] int getSize() const noexcept;

    /**delete function**/
    void erase(int poz);

    /**declare iterator as a friend class**/
    friend class IteratorVector<ElementGeneric>;

    /**vector iterators**/
    IteratorVector<ElementGeneric> begin() const;
    IteratorVector<ElementGeneric> end() const;

    [[maybe_unused]] [[nodiscard]] bool empty() const noexcept;

    [[maybe_unused]] IteratorVector<ElementGeneric> iterator() {
        return IteratorVector(*this);
    };
    ElementGeneric& operator[](int poz) const;
};

/**OPERATOR SUBSCRIPTION**/
template <typename ElementGeneric>
ElementGeneric& VectorDinamic<ElementGeneric>::operator[](int poz) const {
    return elemente[poz];
}

/**CONSTRUCTOR**/
template <typename ElementGeneric>
VectorDinamic<ElementGeneric>::VectorDinamic(): lungime(0), capacitate(CAPACITATE_INITIALA) {
    this->elemente = new ElementGeneric[CAPACITATE_INITIALA];
}

/**COPY CONSTRUCTOR**/
template<typename ElementGeneric>
VectorDinamic<ElementGeneric>::VectorDinamic(const VectorDinamic<ElementGeneric> &vector) {
    this->elemente = new ElementGeneric[vector.capacitate];
    //copy elements
    for (int i = 0; i < vector.lungime; ++i) {
        this->elemente[i] = vector.elemente[i];
    }
    lungime = vector.lungime;
    capacitate = vector.capacitate;
}

template <typename ElementGeneric>
[[maybe_unused]] [[nodiscard]] bool VectorDinamic<ElementGeneric>::empty() const noexcept {
    return lungime == 0;
}

/**ASSINGMENT OPERATOR**/
template<typename ElementGeneric>
VectorDinamic<ElementGeneric> &VectorDinamic<ElementGeneric>::operator=(const VectorDinamic<ElementGeneric> &vector) {
    if (this == vector) {
        return *this; // sunt egale, deci nu mai are rost sa mai fac altceva
    }
    delete[] elemente;
    elemente = new ElementGeneric[vector.capacitate];
    // copiaza toate elementele
    for (int i = 0; i < vector.lungime; ++i)
        elemente[i] = vector.elemente[i];
    lungime = vector.lungime;
    capacitate = vector.capacitate;
    return *this;
}

/**DESTRUCTOR**/
template<typename ElementGeneric>
VectorDinamic<ElementGeneric>::~VectorDinamic() {
    delete[] elemente;
    lungime = 0;
    capacitate = 0;
}

/**MOVE CONSTRUCTOR**/
template<typename ElementGeneric>
VectorDinamic<ElementGeneric>::VectorDinamic(VectorDinamic &&vector) noexcept {
    //copy data
    elemente = vector.elemente;
    lungime = vector.lungime;
    capacitate = vector.capacitate;

    //release all from vector
    vector.elemente = nullptr;
    vector.lungime = 0;
    vector.capacitate = 0;
}

/**MOVE ASSIGNMENT**/
template <typename ElementGeneric>
VectorDinamic<ElementGeneric>& VectorDinamic<ElementGeneric>::operator = (VectorDinamic<ElementGeneric>&& vector) noexcept {
    if (this == &vector) {
        return *this;
    }
    delete[] elemente;
    // copiaza data din vector
    elemente = vector.elemente;
    lungime = vector.lungime;
    capacitate = vector.capacitate;

    //release all from vector
    vector.elemente = nullptr;
    vector.lungime = 0;
    vector.capacitate = 0;
    return *this;
}

/**ALTE OPERATII**/
template <typename ElementGeneric>
void VectorDinamic<ElementGeneric>::erase(int poz) {
    this->lungime--;
    for (int i = poz; i < this->lungime; ++i) {
        this->elemente[i] = this->elemente[i + 1];
    }
}

template <typename ElementGeneric>
void VectorDinamic<ElementGeneric>::pushback(const ElementGeneric &element) {
    ensureCapacity();
    this->elemente[this->lungime++] = element;
}

//getter
template <typename ElementGeneric>
[[maybe_unused]] ElementGeneric& VectorDinamic<ElementGeneric>::get(int poz) const {
    return this->elemente[poz];
}

//setter
template <typename ElementGeneric>
[[maybe_unused]] void VectorDinamic<ElementGeneric>::set(int poz, const ElementGeneric &element) {
    elemente[poz] = element;
}

//size
template <typename ElementGeneric>
int VectorDinamic<ElementGeneric>::getSize() const noexcept {
    return lungime;
}

//ensure capacity
template <typename ElementGeneric>
void VectorDinamic<ElementGeneric>::ensureCapacity([[maybe_unused]] int factor) {
    if (lungime < capacitate) {
        return; // nu avem nevoie de realocare
    }
    capacitate *= 2;
    auto *aux = new ElementGeneric[capacitate];
    for (int i = 0; i < lungime; ++i) {
        aux[i] = elemente[i];
    }
    delete[] elemente;
    elemente = aux;
}

template <typename ElementGeneric>
//begin for iterator
IteratorVector<ElementGeneric> VectorDinamic<ElementGeneric>::begin() const {
    return IteratorVector<ElementGeneric>(*this);
}

template <typename ElementGeneric>
IteratorVector<ElementGeneric> VectorDinamic<ElementGeneric>::end() const {
    return IteratorVector<ElementGeneric>(*this, lungime);
}

template <typename ElementGeneric>
class IteratorVector {
    private:
        const VectorDinamic<ElementGeneric>& vector;
        int poz = 0;
    public:
        explicit IteratorVector(const VectorDinamic<ElementGeneric>& vector);

    [[maybe_unused]] IteratorVector(const VectorDinamic<ElementGeneric>& vector, int poz)noexcept;

        [[maybe_unused]] [[nodiscard]] bool valid() const;
        ElementGeneric& element() const;
        void next();
        ElementGeneric& operator*() const;
        IteratorVector& operator++();
        bool operator == (const IteratorVector& iterator) noexcept;
        bool operator != (const IteratorVector& iterator) noexcept;
    };

// functii implementate
template <typename ElementGeneric>
IteratorVector<ElementGeneric>::IteratorVector(const VectorDinamic<ElementGeneric> &vector) : vector{vector} {}

template <typename ElementGeneric>
[[maybe_unused]]
IteratorVector<ElementGeneric>::IteratorVector(const VectorDinamic<ElementGeneric> &vector, int poz) noexcept : vector{vector}, poz{poz} {}


template <typename ElementGeneric>
[[maybe_unused]] bool IteratorVector<ElementGeneric>::valid() const {
    return poz < vector.getSize();
}

template <typename ElementGeneric>
ElementGeneric& IteratorVector<ElementGeneric>::element() const {
    return vector.elemente[poz];
}

template <typename ElementGeneric>
void IteratorVector<ElementGeneric>::next() {
    poz++;
}

template <typename ElementGeneric>
ElementGeneric& IteratorVector<ElementGeneric>::operator*() const {
    return element();
}

template <typename ElementGeneric>
IteratorVector<ElementGeneric>& IteratorVector<ElementGeneric>::operator++() {
    next();
    return *this;
}

template <typename ElementGeneric>
bool IteratorVector<ElementGeneric>::operator==(const IteratorVector<ElementGeneric> &iterator) noexcept {
    return poz == iterator.poz;
}

template <typename ElementGeneric>
bool IteratorVector<ElementGeneric>::operator!=(const IteratorVector<ElementGeneric> &iterator) noexcept {
    return *this != iterator;
}

#endif //LAB6_VECTORDINAMIC_H