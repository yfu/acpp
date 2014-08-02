#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cin;
using std::cout;
int main(int argc, char *argv[])
{
  std::vector<string> words;
  string x;
  while(cin >> x) {
    words.push_back(x);
  }

  int shortest = x.size();
  int longest = x.size();
  typedef std::vector<string>::size_type str_vec_sz;
  str_vec_sz n = words.size();
  str_vec_sz i = 0;
  while(i < n) {
    string::size_type s = words[i].size();
    longest = s > longest ? s : longest;
    shortest = s < shortest ? s : shortest;
    ++i;
  }
  cout << "Length of the shortest string: " << shortest << std::endl;
  cout << "Length of the longest string: " << longest << std::endl;
  return 0;
}



