#pragma once
#include <fstream>
#include <stack>

class Program {
public:
    Program() = delete;
    explicit Program(const std::string& path);
    ~Program() = default;
    char readInst() { return instructions.at(current); }
    void nextInst() { current++; }
    unsigned int getCurrentIndex() const { return current; }
    void goToIndex(int index) { current = index; }
    void goToLoopEnd();
    bool isEndOfProgram()  { return current >= instructions.length(); }

private:
    std::string instructions;
    unsigned int current{0};
};


