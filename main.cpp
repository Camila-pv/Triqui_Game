#include "pr.hpp"
#include <iostream>

int main() {
  Tablero t;
  int posicion = posi_random();
  t.assingment(posicion,'X');
  t.display();
  std::cout <<"\n";
  while(t.translate_won() == 5) {
    std::cout << t.translate_won();
    int pos;
    std::cin >> pos;
    t.assingment(pos, 'O');
    t.display();
    t.thinker();
  }
  return 0;
}
