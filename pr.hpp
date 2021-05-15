#ifndef __TRIQUI_HPP
#define __TRIQUI_HPP

#include <iostream>
#include <ctime>
#include <stdlib.h>
/**
struct ficha {
  char simbol; //X o O
  int pos;// 1-9

};
**/
class Tablero {
private:
  char tablero[9];
  char simbol; //X o O
  //char fichas = ['X', 'O'];

  char Triqui_index(int i);
public:
  Tablero();
  //~Tablero();
  void display();
  void instruction();
  void assingment(int i, char simbolo);
  void thinker();
  bool full();
  char won();
  bool winner();
  int translate_won();
  int minimax(int deep, bool turn);
};

int posi_random();
#endif
