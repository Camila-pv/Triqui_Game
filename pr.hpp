#ifndef __TRIQUI_HPP
#define __TRIQUI_HPP

#include <iostream>

struct ficha {
  char simbol; //X o O
  int pos;// posicion de la ficha 1-9
};

class Tablero {
private:
  char t[9];
  ficha *pointer;

  char Triqui_index(int i);
public:
  Tablero();
  //~Tablero();
  void display();
  void assingment(int i, ficha f);
};

#endif
