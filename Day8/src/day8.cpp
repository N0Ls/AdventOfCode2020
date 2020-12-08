#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <regex>
#include <list>
#include <set>
#include <utility>

using namespace std;

struct Instruction
{
    Instruction(string op, int v)
    {
        operation = op;
        value = v;
    }

    string operation;
    int value;
};

bool runInstructions(vector<pair<Instruction, bool>>& instructions, int& response)
{
    int currentIndex=0;
    int accumulator=0;

    vector<pair<Instruction, bool>> instr = instructions;

    while (currentIndex < instr.size() && !instr[currentIndex].second)
    {
        Instruction instruction = instr[currentIndex].first;
        instr[currentIndex].second = true;

        if (instruction.operation == "acc")
        {
            accumulator += instruction.value;
            currentIndex += 1;
        }
        else if (instruction.operation == "jmp")
        {
            currentIndex += instruction.value;
        }
        else if (instruction.operation == "nop")
        {
            currentIndex += 1;
        }
        else
        {
            cout << "Unknown instruction found" << endl;
            exit(1);
        }
    }

    bool hasLoop = false;
    if (currentIndex < instr.size())
    {
        hasLoop = instr[currentIndex].second;
    }

    response = accumulator;

    return hasLoop;
}

void loopOut(vector<pair<Instruction, bool>>& instr)
{
    bool hasLoop = true;
    int accumulator = 0;

    for (size_t i = 0; i < instr.size() && hasLoop; ++i)
    {
        accum = 0;

        //Change no operation to jump
        if (instr[i].first.operation == "nop")
        {
            vector<pair<Instruction, bool>> modifiedInstructions = instr;
            modifiedInstructions[i].first.operation = "jmp";

            hasLoop = runProgram(modifiedInstructions, accumulator);
        }

        //Change no jump to no operation
        else if (instr[i].first.operation == "jmp")
        {
            vector<pair<Instruction, bool>> modifiedInstructions = instr;
            modifiedInstructions[i].first.operation = "nop";

            hasLoop = runProgram(modifiedInstructions, accumulator);
        }
    }
    cout << accumulator << endl;
}

int main(int argc, char const *argv[]) {

  std::fstream myfile("../src/input.txt", std::ios_base::in);
  std::string line;
  std::smatch match;

  vector<pair <Instruction,bool>> v;
  while (std::getline(myfile, line)) {

    std::regex regex("(.*) (.*)");
    std::regex_search(line, match, regex);

    cout << match[1] << endl;

    v.push_back(make_pair(Instruction(match[1],std::stoi(match[2])),false));
  }
  myfile.close();

  loopOut(v);

  return 0;
}
