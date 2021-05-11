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

void Tablero::instruction(){
  bool f1e = true;
  std::cout << " -----------\n";
  for(int i = 0; i < 9; i++) {
    if(f1e){
        std::cout<< "  " << i;
        f1e = false;
    }else if((i+1)%3 == 0) {
      std::cout<< " | "<< i <<"\n";
      std::cout << " -----------\n";
      f1e = true;
    }else{
      std::cout << " | "<< i;
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

//Determina si toda la cuadricula esta llena con 'X' o 'O'
bool Tablero::full(){
  for(int i = 0; i < 9; i++){
    if(tablero[i] != 'O' && tablero[i] != 'X')
      return false;
  }
  return true;
}

//Determina quien gano
//Retorna 'X'-> gana maquina
//Retorna 'O'-> gana jugador
//Retorna 'N'-> ninguno gano
char Tablero::won(){
  //Fila
  for(int i = 0; i < 9 ; i = i+3){
    //std::cout << "holaaaa" <<i <<'\n';
    if((tablero[i]==tablero[i+1]) && (tablero[i+1]== tablero[i+2]) && (tablero[i]== 'O'))
      return 'O';
    if((tablero[i]==tablero[i+1]) && (tablero[i+1]== tablero[i+2]) && (tablero[i]== 'X'))
      return 'X';
  }

  //Columna
  for(int i = 0; i < 3 ; i++){
    if(tablero[i]==tablero[i+3] && tablero[i+3]== tablero[i+6] && tablero[i+6]== 'O')
      return 'O';
    if(tablero[i]==tablero[i+3] && tablero[i+3]== tablero[i+6] && tablero[i+6]== 'X')
      return 'X';
  }

  //Diagonales
  if(tablero[0]==tablero[4] && tablero[4]== tablero[8] && tablero[8]== 'O')
    return 'O';
  if(tablero[0]==tablero[4] && tablero[4]== tablero[8] && tablero[8]== 'X')
    return 'X';

  if(tablero[2]==tablero[4] && tablero[4]== tablero[6] && tablero[6]== 'O')
      return 'O';
  if(tablero[2]==tablero[4] && tablero[4]== tablero[6] && tablero[6]== 'X')
      return 'X';
  return 'N';
}
