#include "pr.hpp"
#include <iostream>

int main() {
  Tablero t;
  t.instruction();
  std::cout <<"\n";
  int posicion = posi_random();
  t.assingment(posicion,'X');
  t.display();
  std::cout <<"\n";

  while(t.translate_won() == -30) {
    int pos;
    std::cin >> pos;
    t.assingment(pos, 'O');
    t.display();
    t.thinker();
  }

  if(t.translate_won()== 10)
    std::cout <<"The machine won";
  else if(t.translate_won()== -10)
    std::cout <<"The player won";
  else
    std::cout <<"Tie !!"<<std::endl;
  std::cout <<"\n";
  std::cout <<"\n";

  return 0;
}
