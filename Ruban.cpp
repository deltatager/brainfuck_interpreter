#include "Ruban.h"

Ruban::Ruban(size_t length) : _position{0}, tab{TableauMemoire<unsigned char>(length)} {}

void Ruban::moveLeft() {
    if (_position == 0)
        _position = tab.size() - 1;
    else
        --_position;
}

void Ruban::moveRight() {
    if (_position == tab.size() - 1)
        _position = 0;
    else
        ++_position;
}
