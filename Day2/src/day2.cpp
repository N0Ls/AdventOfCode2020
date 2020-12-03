#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> getLines(const char * Url) {
  string line;
  ifstream inFile;
  vector<string> lines;

  inFile.open("../src/input.txt");
  if (!inFile) {
      cout << "Unable to open file";
      exit(1); // terminate with error
  }
  while (inFile >> line) {
    lines.push_back(line);
  }
  inFile.close();

  return lines;
}

int main(int argc, char const *argv[]) {
  vector<string> v_lines = getLines("../src/input.txt");

  int NbPassOK = 0;

  for (size_t i = 0; i < v_lines.size(); i+=3) {
    //Bounds
    int boundsIndex= v_lines[i].find('-');
    int lowerBound = std::stoi(v_lines[i].substr(0,boundsIndex));
    int upperBound = std::stoi(v_lines[i].substr(boundsIndex+1,v_lines[i].length()));

    //Question 1
    // int countOcc= std::count(v_lines[i+2].begin(),v_lines[i+2].end(),v_lines[i+1][0]);
    // std::cout << "Lower bound : " << lowerBound << " " << "Upper bound : " << upperBound << " " << countOcc << '\n';
    // if(countOcc >= lowerBound && countOcc <= upperBound){
    //   NbPassOK++;
    // }

    //Question 2
    // std::cout << "Looking for : " << v_lines[i+1][0] << endl;
    if ((v_lines[i+2][lowerBound-1] == v_lines[i+1][0] && v_lines[i+2][upperBound-1] != v_lines[i+1][0]) || (v_lines[i+2][lowerBound-1] != v_lines[i+1][0] && v_lines[i+2][upperBound-1] == v_lines[i+1][0])) {
      NbPassOK++;
    }
  }

  std::cout << NbPassOK << '\n';

  return 0;
}
