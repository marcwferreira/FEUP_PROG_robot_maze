#include <iostream>

using namespace std;

//Function for the main menu returns the option chosen by the user
int game_start(){
  // variable to store the user input
  int option;

  //shows the menu
  cout << "1) Rules;" << endl << "2) Play;" << endl << "0) Exit" << endl;

  //asks repeatedly for an option only accpeting 1, 2 or 0
  do{
  cin >> option;
  if(option != 1 & option != 2 & option != 0){
    cout << "Input not valid, please try again." << endl;
  }
  }while(option != 1 & option != 2 & option != 0);
  return option;
}

int main() {

  // variables user input and chosen maze
  int option = game_start();
  int maze;

  //actions regarding the option chose by the user

  //rules
  if(option == 1){
    cout << "The rules are: ";
  }
  //Play the game
  else if(option == 2){

    cout << "Here we go!" << endl << "Choose the maze: ";
    //Choose an available maze
    do{
      cin >> maze;
    }while(maze != 0);

    //Return to main menu
    if(maze == 0){
      game_start();
    }
  }
  // Exit
  else{
    cout << "Bye!";
  }
  
}
