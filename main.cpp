#include <iostream>
#include "Ruban.h"

int main() {

    Ruban r{5};

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j <= i; ++j)
            r.increment();

        r.moveRight();
    }
    for (int i = 0; i < 10; ++i) {
        std::cout << +r.read() << std::endl;
        r.moveLeft();
    }

    return 0;
}
