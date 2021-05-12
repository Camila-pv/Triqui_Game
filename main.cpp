#include "pr.hpp"
#include <iostream>

int main() {
  Tablero t;
  int posicion = posi_random();
  t.assingment(posicion,'X');
  t.display();
  std::cout <<t.translate_won();
  while(t.translate_won() == 5) {
    int pos;
    std::cin >> pos;
    t.assingment(pos, 'O');
    t.thinker();
    t.display();
  }
  return 0;
}
