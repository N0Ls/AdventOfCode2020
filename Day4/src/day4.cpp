#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string_regex.hpp>
#include <boost/algorithm/string/classification.hpp>

using namespace std;


int main(int argc, char const *argv[]) {

  std::ifstream ifs("../src/input.txt");
  std::string content( (std::istreambuf_iterator<char>(ifs) ),
                         (std::istreambuf_iterator<char>()    ) );

  std::vector<string> strs;
  auto re = boost::regex("\n\n");
  boost::split_regex(strs, content, re);


  int answer1 = 0;
  int answer2 = 0;

  for(auto line : strs){
    std::vector<std::string> tokens;
    boost::split_regex(tokens, line, boost::regex{"\\s"});
    bool isValid = true;
    if((tokens.size()<7 || tokens.size()>8 || (tokens.size()==7 && line.find("cid")!= std::string::npos))){
      isValid=false;
      answer1++;
    }
    else{
      for(auto token : tokens){
          if(!(
             (boost::regex_match(token,boost::regex{"^(byr:+((19[2-9][0-9])|(2[0]{2}[0-2])))$"}))
          || (boost::regex_match(token,boost::regex{"^(iyr:+((201[0-9])|(2020)))$"}))
          || (boost::regex_match(token,boost::regex{"^(eyr:+((202[0-9])|(2030)))$"}))
          || (boost::regex_match(token,boost::regex{"^((hgt:+1[5-8][0-9]cm)|(hgt:19[0-3]cm)|(hgt:6[0-9]in)|(hgt:7[0-6]in)|(hgt:59in))$"}))
          || (boost::regex_match(token,boost::regex{"^(hcl:+#+([0-9a-f]{6}))$"}))
          || (boost::regex_match(token,boost::regex{"^(ecl:+(amb|blu|brn|gry|grn|hzl|oth))$"}))
          || (boost::regex_match(token,boost::regex{"^(pid:([0-9]{9}))$"}))
          || (boost::regex_search(token,boost::regex{"cid:"}))
          )){
              isValid = false;
          }
      }
    }
    if(isValid==true){
      answer2 ++;
      std::cout << endl << "OK " << '\n';
      for(auto token2 : tokens){
        std::cout << token2 << '\n';
      }
    }
  }


  std::cout << "Answer 1 : "<< strs.size() - answer1 << '\n';
  std::cout << "Answer 2 : "<< answer2 << '\n';
  return 0;
}
