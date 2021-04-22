//T09_G12


//apenas um arquivo que eu estava a usar para testes
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int x,y;

const int maze_height = 10;
const int maze_lenght = 10;

//load the txt file in an array of strings
string array[maze_height][maze_lenght]; //for now is 10x10, we have to change to d.

while (getline(mazefile,line)) {
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                pos[i][j] = line[i];
                if (line[i] == 'H') {
                    player_line = i;
                    player_col = j;
                }
            }
        }
    }
    mazefile.close();



//storing the map

for(x = 0; x < maze_lenght, x++){
    for(y =0; y < maze_height, y++){
        cout << array[x][y]<<" ";
    }
    cout << endl;
}