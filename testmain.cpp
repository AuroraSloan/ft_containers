#include <vector>
#include <iostream>

int main() {
  std::vector<int> thirty(5, 5);
  std::vector<int> fourty(10, 10);
  for(std::vector<int>::iterator i = fourty.begin(); i < fourty.end(); i++) {
    std::cout << *i << ' ';
  }
  std::cout << std::endl;
  fourty.assign(thirty.begin(), thirty.end());
  for(std::vector<int>::iterator i = fourty.begin(); i < fourty.end(); i++) {
    std::cout << *i << ' ';
  }
  std::cout << std::endl;
  return 0;
}
