#ifndef __TRIQUI_HPP
#define __TRIQUI_HPP

#include <iostream>
#include <ctime>

struct ficha {
  char simbol; //X o O
  int pos;// 1-9

};

class Tablero {
private:
  char tablero[9];
  //char fichas = ['X', 'O'];

  char Triqui_index(int i);
public:
  Tablero();
  //~Tablero();
  void display();
  void assingment(int i, char simbolo);

};

int posi_random();
#endif
