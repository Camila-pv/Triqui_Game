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
  std::cout << " -----------------------------------------------------\n";
  std::cout << "                       TIC TAC TOE\n";
  std::cout << " -----------------------------------------------------\n";
  std::cout << "                 X: Machine     O: Player\n";
  std::cout << "These are the number of each box\n";
  bool f1e = true;
  std::cout << " -----------\n";
  for(int i = 0; i < 9; i++) {
    if(f1e){
        std::cout<< "  " << i+1;
        f1e = false;
    }else if((i+1)%3 == 0) {
      std::cout<< " | "<< i+1 <<"\n";
      std::cout << " -----------\n";
      f1e = true;
    }else{
      std::cout << " | "<< i+1;
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

//Determina si toda la cuadricula esta llena con 'X' o 'O'
bool Tablero::full(){
  for(int i = 0; i < 9; i++){
    if(tablero[i] == '-')
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
    return 'T';//empatados
  }
  return 'N';//no full
}

int Tablero::translate_won() {
  char plyr = won();
  if(plyr == 'X') {//gana X
    return 10;
  }else if(plyr == 'O'){//gana O
    return 1;
  }else if(plyr == 'N'){
    return -30;//no hay ganador aun
  }else{
    return 5;//empatados
  }
}

std::vector<int> Tablero::minimax(int deep, bool turn){
  if(translate_won() != -30){
    std::vector<int> vec(2);
    vec[0] = deep; //profundidad
    vec[1] = translate_won(); //valor
    return vec;
  }

  //turno de la maquina ->max
  if(turn) {// esta maximizando
    std::vector<int> vec(2);
    vec[1] = -30;
    vec[0] = 1e3;
    for(int i = 0; i < 9; i++){
      if(tablero[i] == '-'){
        tablero[i] = 'X';
        std::vector<int> new_vector;
        new_vector = minimax(deep+1, false);
        tablero[i] = '-';
        if(new_vector[0] < vec[0]){
          vec[0] = new_vector[0];
          vec[1] = new_vector[1];
        }else if(new_vector[0] == vec[0]){
          if(new_vector[1] > vec[1]){
            vec[0] = new_vector[0];
            vec[1] = new_vector[1];
          }
        }
      }
    }
    //std::cout<<"x"<< vec[0]<<" "<<vec[1]<<" "<<vec[2]<<std::endl;
    return vec;
  }else{//turno del usuario->min
    std::vector<int> vec(2);
    vec[1] = 30;
    vec[0] = 1e3;
    for(int i = 0; i < 9; i++) {
      if(tablero[i] == '-') {
        tablero[i] = 'O';
        std::vector<int> new_vector;
        new_vector = minimax(deep+1, true);
        tablero[i] = '-';
        if(new_vector[0] < vec[0]){
          vec[0] = new_vector[0];
          vec[1] = new_vector[1];
        }
        else if(new_vector[0] == vec[0]){
          if(std::abs(new_vector[1]) < vec[1]){
            vec[0] = new_vector[0];
            vec[1] = new_vector[1];
          }
        }
      }
    }
    //std::cout<<"min"<< vec[0]<<" "<<vec[1]<<" "<<vec[2]<<std::endl;
    return vec;
  }
}

void Tablero::thinker(){
  int best_position, best_deep = 1e4, best_score = -1, max_score = -1;
  std::vector<int> score(9,-1);
  std::vector<int> deep(9,1e4);
  std::vector<int> vec;
  std::cout << "Position Deep Score" << std::endl;
  for(int i = 0; i < 9; i++) {
    if(tablero[i] == '-') {
      tablero[i] = 'X';
      vec = minimax(0,false);
      std::cout << i << " " << vec[0] << " " << vec[1] << std::endl;
      tablero[i] = '-';
      score[i] = vec[1];
      deep[i] = vec[0];
    }
  }

  // Se busca max_score
  for(int i = 0; i < 9 ;i++){
    if(score[i] > max_score)
      max_score = score[i];
  }
  std::cout<<"max: " <<max_score<<std::endl;
  if(max_score == 1){
    std::cout<<"entre" <<std::endl;
    best_deep = -1;
    for(int i = 0; i < 9 ;i++){
      if(best_deep < deep[i] && deep[i] < 1e4){
        std::cout<<"entre al if" <<std::endl;
        best_deep = deep[i];
        best_position = i;
        best_score = score[i];
        std::cout << "......"<<best_position <<  " " << best_deep << ' ' << best_score << std::endl;
      }
    }
    std::cout << "----"<<best_position <<  " " << best_deep << ' ' << best_score << std::endl;
  }else{
    // DO/ WHILE -> primero se hace accion del do y luego se rectifica si el argumento del while se cumple para volver a hacer el DO
    do{   // Si el max_score es mayor a 1 entonces busca la profundidad minima donde best_score sea mayor a 1
      for(int i=0; i<9; i++){
        if(best_deep == deep[i]){
          deep[i] = 1e4;
        }
      }
      best_deep = 1e4;

      for(int i = 0; i < 9; i++){
        if(best_deep > deep[i]){
          best_deep = deep[i];
          best_position = i;
          best_score = score[i];
        }
        else if(best_deep == deep[i]){
          if(score[i] > best_score){
            best_score = score[i];
            best_position = i;
            best_deep = deep[i];
          }
        }
      }

    }while(best_score <= 1);
  }



  std::cout << best_position <<  " " << best_deep << ' ' << best_score << std::endl;
  //std::vector<int> vec;
  //vec = minimax(0,false);
  assingment(best_position+1, 'X');
  display();
}
