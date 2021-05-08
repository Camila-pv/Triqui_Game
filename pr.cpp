#include "pr.hpp"

Tablero::Tablero(){
  for(int i = 0; i < 9; i++) {
    tablero[i] = '-';
  }
}

char Tablero::Triqui_index(int i) {
  i--;
  return tablero[i];
}

void Tablero::display(){
  bool f1e = true;
  std::cout << " -----------\n";
  for(int i = 0; i < 9; i++) {
    if(f1e){
        std::cout<< "  " << tablero[i];
        f1e = false;
    }else if((i+1)%3 == 0) {
      std::cout<< " | "<< tablero[i] <<"\n";
      std::cout << " -----------\n";
      f1e = true;
    }else{
      std::cout << " | "<< tablero[i];
    }
  }
}

void Tablero::assingment(int i, char simbolo) {
  tablero[i-1] = simbolo;
}

/*
int posi_random(){
  int num = 0;
  srand(time(0));
  num = 1 + (rand() % 9);
  //std::cout << num << '\n';
  if(num == 1 || num == 3 || num == 7 || num == 9) {
    return num;
  }else {
    return posi_random();
  }
}
*/
