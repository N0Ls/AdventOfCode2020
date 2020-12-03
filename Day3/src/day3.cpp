#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>

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

  //Part1
  // int count = 0;
  // int index = 0;
  // for (size_t i = 0; i < v_lines.size(); i++) {
  //   if(v_lines[i][index%v_lines[i].length()]=='#')
  //     count++;
  //   index+=3;
  // }

  //Part2
  vector<int> slopes_results;

  //Odd indexes
  for (size_t y = 1; y < 8; y+=2) {
    int count = 0;
    int index = 0;
    for (size_t i = 0; i < v_lines.size(); i++) {
      if(v_lines[i][index%v_lines[i].length()]=='#')
        count++;
      index+=y;
    }
    slopes_results.push_back(count);
  }

  //Right 1 Down 2
  int count = 0;
  int index = 0;
  for (size_t i = 0; i < v_lines.size(); i+=2) {
    if(v_lines[i][index%v_lines[i].length()]=='#')
      count++;
    index++;
  }
  slopes_results.push_back(count);

  double treesProd = std::accumulate(slopes_results.begin(), slopes_results.end(), 1.0, multiplies<double>());

  cout << std::fixed << endl; //display without scientific notation
  cout << "Your code " << treesProd << endl;

  return 0;
}
