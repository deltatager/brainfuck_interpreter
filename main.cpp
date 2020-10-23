#include <iostream>
#include <stack>
#include "Program.h"
#include "Ruban.h"

int main(int argc, char *argv[]) {

    Program *program;
    Ruban *ruban;

    if (argc < 2){
        printf("%s brainfuck_file [memory_array_size (default 512)]", argv[0]);
        return 1;
    } else if (argc < 3) {
        program  = new Program{argv[1]};
        ruban = new Ruban{512};
    } else {
        char* end;
        size_t tabSize = strtol(argv[2], &end, 10);
        if (*end) {
            printf("Conversion error, non-convertible part: %s", end);
            return 2;
        }

        program  = new Program{argv[1]};
        ruban = new Ruban{tabSize};
    }



    std::stack<int> loopStack{};

    while (!program->isEndOfProgram()) {
        switch (program->readInst()) {
            case '<':
                ruban->moveLeft();
                break;
            case '>':
                ruban->moveRight();
                break;
            case '+':
                ruban->increment();
                break;
            case '-':
                ruban->decrement();
                break;
            case ',':
                unsigned char c;
                std::cin >> c;
                ruban->write(c);
                break;
            case '.':
                std::cout << ruban->read();
                break;
            case '[':
                if (ruban->read() != 0) {
                    loopStack.push(program->getCurrentIndex() - 1);
                } else
                    program->goToLoopEnd();
                break;
            case ']':
                program->goToIndex(loopStack.top());
                loopStack.pop();

                break;
            default:
                break;
        }
        program->nextInst();
    }

    delete ruban;
    delete program;
    return 0;
}
