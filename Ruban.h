#pragma once
#include <cstdio>
#include "TableauMemoire.h"

class Ruban {
public:
    Ruban() = delete;
    explicit Ruban(size_t length);
    ~Ruban() = default;
    Ruban(const Ruban &copy) = delete;
    Ruban &operator=(const Ruban &copy) = delete;

    unsigned char read() { return tab[_position]; };
    void increment() { tab[_position] = ++tab[_position]; };
    void decrement() { tab[_position] = --tab[_position]; };
    void moveLeft();
    void moveRight();

private:
    unsigned int _position;
    TableauMemoire<unsigned char> tab;
};


