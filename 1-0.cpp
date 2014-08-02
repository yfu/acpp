#include <iostream>
#include <string>

int main() {
  std::cout << "Please enter your first name: ";

  std::string name;
  std::cin >> name;

  std::string greeting = "Hello, " + name + "!";
  const std::string spaces(greeting.size(), ' ');
  const std::string second = "* " + spaces + " *";
  
  const std::string first(second.size(), '*');

  std::cout << first << std::endl;
  std::cout << second << std::endl;
  std::cout << "* " << greeting << " *" << std::endl;
  std::cout << second << std::endl;
  std::cout << first << std::endl;

  // For 1-1
  const std::string hello = "Hello";
  const std::string message = hello + ", world" + "!";

  // For 1-2
  const std::string exclam = "!";
  // The following is not valid: redefinition
  //   const std::string message = "Hello" + ", world" + exclam;
  
  return 0;
}


