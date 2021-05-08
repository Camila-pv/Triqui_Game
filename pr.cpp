#include "pr.hpp"

Tablero::Tablero(){
  for(int i = 0; i < 9; i++) {
    t[i] = '-';
  }
}

char Tablero::Triqui_index(int i) {
  i--;
  return t[i];
}

void Tablero::display(){
  bool f1e = true;
  std::cout << " -----------\n";
  for(int i = 0; i < 9; i++) {
    if(f1e){
        std::cout<< "  " << t[i];
        f1e = false;
    }else if((i+1)%3 == 0) {
      std::cout<< " | "<< t[i] <<"\n";
      std::cout << " -----------\n";
      f1e = true;
    }else{
      std::cout << " | "<< t[i];
    }
  }
}

void Tablero::assingment(int i, ficha f) {
  t[i-1] = f.simbol;
  f.pos = i;
}
