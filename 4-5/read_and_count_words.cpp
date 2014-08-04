#include <vector>
#include <iostream>

using std::istream;
using std::string;
using std::vector;
using std::cout;

istream& read_and_count_words(istream& in, vector<string>& words) {

  if(in) {
    words.clear();
    string word;

    while(in >> word) {
      words.push_back(word);
    }
    in.clear();
  }
  return in;
}
