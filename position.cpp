//T09_G12


//apenas um arquivo que eu estava a usar para testes
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int main() {

    int count = -1;

    int playerx, playery;

    ifstream mazefile;
    mazefile.open("maze_01.txt");

    //linhas ficheiro
    string line;
    int posx, posy;

    while (getline(mazefile, line)) {
        cout << line << endl;
        if (count == 0) {
            posx = line.length();
        }

        count++;

    }
    mazefile.close();

    posy = count + 1;

    char maze_map[posy][posx];

     mazefile.open("maze_01.txt");

    int count2 = 0; //counting the lines

    while(getline(mazefile,line)){
        for(int i=0; i < posx; i++){
            maze_map[count2][i] = line[i];
        }
        count2++;
    }

    cout << "test" << endl;

    for(int i=0;i<posy;i++){
        for(int j=0;j<posx;j++){
            cout << maze_map[i][j] << endl;

            if(maze_map[i][j] == 'H'){
                playerx = j;
                playery = i;
            }
        }
    }

    cout << "x y:" << playerx << " " << playery << endl;



    return 0;
}