#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

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

int decodeRow(const string &Line){
  int numRow=0;
  unsigned int maxRowIndex = 7;
  for (size_t i = 0; i < maxRowIndex; i++) {
    if(Line[i]=='B'){
      numRow += pow(2,maxRowIndex-i-1);
    }
  }
  return numRow;
}

int decodeCol(const string &Line){
  int numCol=0;
  unsigned int maxColIndex = 3;
  for (size_t y = 0; y < maxColIndex; y++) {
    if(Line[y+7]=='R'){
      numCol += pow(2,maxColIndex-y-1);
    }
  }
  return numCol;
}

int seatId(const string &Line){
  int row=decodeRow(Line);
  int col=decodeCol(Line);

  return 8*row+col;
}


int main(int argc, char const *argv[]) {
  vector<string> v_lines = getLines("../src/input.txt");

  vector<int> seatsId;
  for(auto line : v_lines){
    seatsId.push_back(seatId(line));
  }

  sort(seatsId.begin(), seatsId.end());

  int max = seatsId.back();
  int min = seatsId.front();

  int maxSum =0;

  for (size_t i = min; i <= max; i++) {
    maxSum+=i;
  }

  int realSum = std::accumulate(seatsId.begin(), seatsId.end(), 0);

  std::cout << "Max seat id : " << max << '\n';
  std::cout << "Your seat : " << maxSum-realSum << '\n';
  return 0;
}
