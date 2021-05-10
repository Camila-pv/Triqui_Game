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


int posi_random(){
  int num;
  srand(time(0));
  num = 1 + rand() % (10 - 1);
  if(num == 3 || num == 7 || num == 9)
      return num;
  return 1;
}


int Tablero::middle(){

}


void Tablero::machine(){
  int posicion = posi_random();
  assingment(posicion,'X');
  display();
  int count = 1;
  while(count != 8){
    if(count %2 == 0){

    }else{
      int p;
      std::cout<<"Introduce la casilla: ";
      std::cin>> p;
      assingment(p, 'O');
      display();
      count++;

    }
  }
}
