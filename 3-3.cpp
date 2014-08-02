#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;

int main(int argc, char *argv[])
{ 
  std::vector<std::string> words;
  cout << "Please input some words: ";
  string x;
  while (cin >> x) {
    words.push_back(x);
  }
  std::sort(words.begin(), words.end());

  typedef std::vector<string>::size_type str_sz;
  str_sz i = 0;
  str_sz counter = 0;
  string cur_word = "";
  string prev_word = "";
  while(i < words.size()) {
    cur_word = words[i];
    if(counter==0) {
      counter ++;
      prev_word = cur_word;
    } else if(cur_word != prev_word) {
      cout << prev_word << ": " << counter << std::endl;
      prev_word = cur_word;
      counter = 1;
    } else {
      counter ++;
    }
    i++;
  }
  cout << cur_word << ": " << counter << std::endl;
  return 0;
}
