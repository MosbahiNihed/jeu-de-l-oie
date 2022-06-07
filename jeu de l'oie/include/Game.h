#ifndef Game_H
#define Game_H
#include <iostream>
#include <string>
#include "cases.h"
#include "player.h"
using namespace std ;
class Game
    {   private:
            int nb_joueurs;
            cases c [64];
            player *players ;
        public :

            Game ();
            ~Game ();
            void delplayer(player p);
            void play (int ) ;
            int getnb();
            void initialiser();
            void changer(int , int , int , int );
            bool calculeroiepos(int );
            void surcaseoie ( int, int , int  );
            void surcaseattente (  );
            void surcaseteleport( int );
            void surcasepiege( int  );
            int caseoccupee(int);
            int premiertour(int ,int ,int);
            void avancer_joueur(int , int);
            bool partieterminee(player);
            void maping();//on n'a pas encore definit cette methode au niveau de cpp
    };
#endif
