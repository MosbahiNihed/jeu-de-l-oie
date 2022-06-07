#ifndef player_H
#define player_H
#include <iostream>
#include <string>

using namespace std;
class player
{
    private:
        string name ;
        int ordre;
        int  Pos;
        int Derniere_pos  ;
        int timewait;
    public :
        player ();
        player (string k,int ordre,int position, int derniere_pos , int t ) ;
        string getname() ;
        void setname(string ch);
        int getdernierepos ()  ;
        void setdernierepos(int);
        int lancede () ;
        int getord();
        void setord(int );
        int getpos()  ;
        void setpos(int d1=0  , int d2=0  ) ;
        void settimewait(int b);
        int gettimewait()const;
        bool Depassement (int d1 , int d2 );
};
    #endif


