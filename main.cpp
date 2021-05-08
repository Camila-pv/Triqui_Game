#include "pr.hpp"
#include <iostream>

int main() {
  Tablero t;
  char X = 'x';
  t.assingment(8, X);
  t.display();

  std::cout << posi_random();
  return 0;
}
