#include "read_and_count_words.h"
#include <iostream>
#include <ios>
#include <iomanip>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::endl;
using std::sort;
using std::istream;

int main() {
  vector<string> words;
  cout << "Please enter a few words and end them with a EOF..." << endl;    
  read_and_count_words(cin, words);
  cout << "The number of words: " << words.size() << endl;
  sort(words.begin(), words.end());
  
  int cur_word_count = 0;
  string cur_word = words[0];

  for(vector<string>::size_type i = 0; i!= words.size(); ++i) {
    if(words[i] == cur_word) {
      cur_word_count ++;
    } else {
      cout << "The word " << cur_word << " appears " << cur_word_count << " time(s)." << endl;
      cur_word = words[i];
      cur_word_count = 1;
    }
  }
  
  cout << "The final word " << cur_word << " appears " << cur_word_count << " time(s)." << endl;
  
  return 0;
}
