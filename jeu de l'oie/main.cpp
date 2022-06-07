#include "windows.h"
#include <iostream>
#include <string>
#include "player.h"
#include "cases.h"
#include "Game.h"
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <ctime>
#include <sstream>
#include "file.h"
using namespace std ;
ofstream file;

int main()
{   stringstream streamstring;
    streamstring << "jeu";
    file.open(streamstring.str()+".txt");
    Game g;
    player p;
//    g.initialiser();
    g.maping();
    srand(time(NULL));
    while ( g.getnb() > 1 )
    {
        for(int n =0 ; n < g.getnb()  ;n++)
        {
            g.play(n);
            g.maping();

        }

    }
    cout<<"joueur gagnant"<<endl;
    return 0 ;
}

