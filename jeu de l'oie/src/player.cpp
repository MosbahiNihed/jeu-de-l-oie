#include<iostream>
#include"player.h"
#include<string>

using namespace std ;
    player::player()
  { name="";
    ordre=0;
    Pos=0;
    Derniere_pos=0;
    timewait=0;

  }
    player::player (string k,int ordre,int position , int derniere_pos, int t )
    {
        ordre=ordre;
        name=k;
        Pos = position ;
        Derniere_pos = derniere_pos ;
        timewait=t;
    }
    string player::getname(){ return name ; }
    void player::setname(string ch){name=ch;}
    int player::getord() { return ordre ;}
    void player::setord( int a ) { ordre = a ;}
    int player::getdernierepos ()  { return Derniere_pos ; }
    void player::setdernierepos(int h){Derniere_pos=h;}
    int player::lancede () { return rand()%(6)+1; }
    int player::getpos()  { return Pos ; }
    bool player::Depassement (int d1 , int d2 )
    {   return (( getpos() + d1 + d2 ) > 63 ) ; }
    void player::setpos(int d1, int d2) {
        if  ( !Depassement( d1 , d2 ))
          {
             Pos += d1 + d2 ;
            }
        else if ( Depassement(d1 , d2))
        {   int n = getpos() + d1 + d2 ;
            int k = n - 63  ;
            Pos=63 - k  ;

        }

    }

    void player::settimewait(int b){timewait=b;}
    int player::gettimewait()const{return timewait;}





