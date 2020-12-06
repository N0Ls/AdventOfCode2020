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

struct Group{
  int nbP;
  vector<string> g_v;
};

int orderGroup(Group G){

  sort(G.g_v.begin(), G.g_v.end(), [](const string & a, const string & b){ return a.size() < b.size(); });
  for (size_t i = 0; i < G.g_v.size(); i++) {
    sort(G.g_v[i].begin(), G.g_v[i].end());
    std::cout << G.g_v[i] << '\n';
  }
  int count = 0;

  for (size_t y = 0; y < G.g_v[0].size(); y++) {
    bool validator = true;
    for(size_t z=1 ; z<G.g_v.size(); z++){
      if(G.g_v[z].find(G.g_v[0][y]) == std::string::npos){
        validator=false;
      }
    }
    if(validator==true){
      count ++;
    }
  }
  return count;
}


int main(int argc, char const *argv[]) {

  std::string singleLine;
	std::vector<char> v;

  int sum = 0;

	std::ifstream file("../src/input.txt", std::ios::in);

  //Question 1
	// while (!file.eof())
	// {
	// 	std::getline(file, singleLine);
	// 	if (singleLine.empty())
	// 	{
	// 		sum += v.size();
	// 		v.clear();
	// 	}
	// 	else
	// 	{
  //     for (size_t i = 0; i < singleLine.size(); i++) {
  //       v.push_back(singleLine[i]);
  //     }
	// 		std::sort(v.begin(), v.end());
	// 		v.erase(std::unique(v.begin(), v.end() ), v.end());
	// 	}
	// }

  //Question 2
  std::vector<Group> groups;
  int count = 0;

  std::vector<string> currentLines;

  while (!file.eof())
  {
    std::getline(file, singleLine);

    if (singleLine.empty())
    {
      Group currentGroup;
      currentGroup.nbP = count;
      currentGroup.g_v=currentLines;
      groups.push_back(currentGroup);
      currentLines.clear();
      count = 0;
    }
    else{
      count ++;
      currentLines.push_back(singleLine);
    }
  }

  vector<int> yesAnswerPerLine;
  for (size_t i = 0; i < groups.size(); i++) {
    yesAnswerPerLine.push_back(orderGroup(groups[i]));
  }
  cout << std::accumulate(yesAnswerPerLine.begin(), yesAnswerPerLine.end(), 0) << endl;

  return 0;
}
