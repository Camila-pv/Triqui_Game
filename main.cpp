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


    if(t.translate_won()== 10){
      std::cout <<"The machine won";
    }else if(t.translate_won()== 1){
      std::cout <<"The player won";
    }else if(t.translate_won() == 5){
      std::cout <<"Tie !!"<<std::endl;
    }
    std::cout <<"\n";
    std::cout <<"\n";
    t.display();

    if(t.translate_won()!= 1){
      t.thinker();
      //t.display();
      if(t.translate_won()== 10){
        std::cout <<"The machine won";
      }else if(t.translate_won()== 1){
        std::cout <<"The player won";
      }else if(t.translate_won() == 5){
        std::cout <<"Tie !!"<<std::endl;
      }
      std::cout <<"\n";
      std::cout <<"\n";
    }
  }



  return 0;
}
