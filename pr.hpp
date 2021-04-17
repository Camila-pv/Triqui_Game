#ifndef __TRIQUI_HPP
#define __TRIQUI_HPP

struct ficha {
  char *simbolo; //X o O
  int pos;// 1-9
};

class Tablero {
private:
  char f1[3] = ['-', '-', '-'];
  char f2[3] = ['-', '-', '-'];
  char f3[3] = ['-', '-', '-'];
public:
  Tablero();
  //~Tablero();
  void display();
};

#include "pr.cpp"
