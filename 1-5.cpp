#include <iostream>
#include <string>

int main() {
  std::string s = "a string";
  {
    std::string x = s + ", really";
    std::cout << s << std::endl;
    // Move the line here to make the program valid
    std::cout << x << std::endl;
  }
  // std::cout << x << std::endl;
}
