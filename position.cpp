//T09_G12


//apenas um arquivo que eu estava a usar para testes
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;
/*
void maze_load() {
    int count = -1;

    int playerx, playery;

    ifstream mazefile;
    mazefile.open("maze_01.txt");

    //linhas ficheiro
    string line;
    int posx, posy;

    while (getline(mazefile, line)) {
        //cout << line << endl;
        if (count == 0) {
            posx = line.length();
        }

        count++;

    }
    mazefile.close();

    posy = count + 1;

    //posx is the number of columns
    //posy is the number of lines

    char maze_map[posy][posx]; //creating a 2d char array to store the map

     mazefile.open("maze_01.txt");

    int count2 = 0; //counting the lines

    while(getline(mazefile,line)){
        for(int i=0; i < posx; i++){
            maze_map[count2][i] = line[i];
        }
        count2++;
    }

    mazefile.close(); //close map file

    //uset to test if map was put correctly
    cout << "testing map" << endl;

    for(int i=0;i<posy;i++){
        for(int j=0;j<posx;j++){
            cout << maze_map[i][j];

            if(maze_map[i][j] == 'H'){
                playerx = j;
                playery = i;
            }
        }
        cout << endl;
    }

    //testing player position
    cout << "x y:" << playerx << " " << playery << endl;

}
*/

int main() {

    int count = -1;

    int playerx, playery;

    ifstream mazefile;
    mazefile.open("maze_01.txt");

    //linhas ficheiro
    string line;
    int posx, posy;

    while (getline(mazefile, line)) {
        //cout << line << endl;
        if (count == 0) {
            posx = line.length();
        }

        count++;

    }
    mazefile.close();

    posy = count + 1;

    //posx is the number of columns
    //posy is the number of lines

    char maze_map[posy][posx]; //creating a 2d char array to store the map

     mazefile.open("maze_01.txt");

    int count2 = 0; //counting the lines

    while(getline(mazefile,line)){
        for(int i=0; i < posx; i++){
            maze_map[count2][i] = line[i];
        }
        count2++;
    }

    mazefile.close(); //close map file

    //uset to test if map was put correctly
    cout << "testing map" << endl;

    for(int i=0;i<posy;i++){
        for(int j=0;j<posx;j++){
            cout << maze_map[i][j];

            if(maze_map[i][j] == 'H'){
                playerx = j;
                playery = i;
            }
        }
        cout << endl;
    }

    //testing player position
    cout << "x y:" << playerx << " " << playery << endl;

    //__________________________________________________________
    while(true){
    //player movement draft
    char movement;
    cout << "choose a movement" << endl;
    cin >> movement;

    if(movement == 'w'){
        maze_map[playery-1][playerx] = 'H';
        maze_map[playery][playerx] = ' ';
        playery--;
    }

    //testing movement
    cout << "testing movement" << endl;

    for(int i=0;i<posy;i++){
        for(int j=0;j<posx;j++){
            cout << maze_map[i][j];
        }
        cout << endl;
    }
    }

    return 0;
}