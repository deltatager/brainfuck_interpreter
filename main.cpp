#include <iostream>
#include <stack>
#include "Program.h"
#include "Ruban.h"

int main() {
    Program program{"../samples/mandelbrot.bf"};
    Ruban ruban{512};
    std::stack<int> loopStack{};

    while (!program.isEndOfProgram()) {
        switch (program.readInst()) {
            case '<':
                ruban.moveLeft();
                break;
            case '>':
                ruban.moveRight();
                break;
            case '+':
                ruban.increment();
                break;
            case '-':
                ruban.decrement();
                break;
            case ',':
                unsigned char c;
                std::cin >> c;
                ruban.write(c);
                break;
            case '.':
                std::cout << ruban.read();
                break;
            case '[':
                if (ruban.read() != 0) {
                    loopStack.push(program.getCurrentIndex() - 1);
                } else
                    program.goToLoopEnd();
                break;
            case ']':
                program.goToIndex(loopStack.top());
                loopStack.pop();

                break;
            default:
                break;
        }
        program.nextInst();
    }
    return 0;
}
