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

void Tablero::thinker(){
  int best_position;
  int best_score = -100;
  for(int i = 0; i < 9; i++) {
    if(tablero[i] == '-') {
      tablero[i] = 'X';
      int score = minimax(0, false);
      tablero[i] = '-';
      if(score > best_score){
        best_score = score;
        best_position = i;
      }
    }
  }
  assingment(best_position, 'X');
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

  //tablero lleno
  if(full()) {
    return 'N';//no full
  }
  return 'T';
}

int Tablero::translate_won() {
  char plyr = won();
  if(plyr == 'X') {//gana X
    return 1;
  }else if(plyr == 'O'){//gana O
    return -1;
  }else if(plyr == 'N'){
    return 5;//no hay ganador aun
  }else{
    return 0;//empatados
  }
}

int Tablero::minimax(int deep, bool turn) {
  int score = translate_won();
  //turno de la maquina ->max
  if(turn == true) {// esta maximizando
    int best_score = -100;
    for(int i = 0; i < 9; i++) {
      if(tablero[i] == '-') {
        tablero[i] = 'X';
        score = minimax(deep+1, false);
        tablero[i] = '-';
        if(score > best_score) {
          best_score = score;
        }
      }
    }
    return best_score;
  }else {//turno del usuario->min
    int best_score = 100;
    for(int i = 0; i < 9; i++) {
      if(tablero[i] == '-') {
        tablero[i] = 'O';
        score = minimax(deep+1, true);
        tablero[i] = '-';
        if(score < best_score) {
          best_score = score;
        }
      }
    }
    return best_score;
  }
}
