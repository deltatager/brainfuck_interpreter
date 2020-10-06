#include <iostream>
#include "Program.h"

Program::Program(const std::string &path) {
    std::ifstream in{path};
    if (in) {
        in.seekg(0, std::ios::end);
        instructions.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&instructions[0], instructions.size());
        in.close();
        return;
    }
    throw std::runtime_error("Could not read file " + path);
}

void Program::goToLoopEnd() {
    int nbLoops {1};
    unsigned char cur {0};

    while (nbLoops > 0) {
        this->nextInst();
        cur = this->readInst();
        if (cur == '[')
            nbLoops++;
        if (cur == ']')
            nbLoops--;
    }
}