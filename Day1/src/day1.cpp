#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int getCode(const char * Url) {
  int line;
  ifstream inFile;
  vector<int> inputs;

  inFile.open("../src/input.txt");
  if (!inFile) {
      cout << "Unable to open file";
      exit(1); // terminate with error
  }
  while (inFile >> line) {
    inputs.push_back(line);
  }
  inFile.close();

  // for (std::size_t i = 0; i < inputs.size(); i++){
  //   for (std::size_t y = 0; y < inputs.size(); y++){
  //     if(inputs[i]+inputs[y]==2020){
  //       return inputs[i]*inputs[y];
  //     }
  //   }
  // }

  for (std::size_t i = 0; i < inputs.size(); i++){
    for (std::size_t y = 0; y < inputs.size(); y++){
      for (std::size_t z = 0; z < inputs.size(); z++){
        if(inputs[i]+inputs[y]+inputs[z]==2020){
          return inputs[i]*inputs[y]*inputs[z];
        }
      }
    }
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  cout << "Your code is : " << getCode("../src/input.txt");

  return 0;
}
