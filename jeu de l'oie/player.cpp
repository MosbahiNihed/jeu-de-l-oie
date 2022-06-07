
#include<iostream>
#include"player.h"
#include<string>

using namespace std ;
  player::player()
  { name="";
  ordre=0;
  pos=0;
  derniere_pos=0;
  timewait=0;

}
 player::player (string k,int ordre,int position , int derniere_pos, int t )
   {
    ordre=ordre;
    name=k;
    Pos = position ;
    Derniere_pos = derniere_pos ;
    timewait=t;}
 string player::getname()const{ return name ; }
 void player::setname(string ch){name=ch;}
 int player::getdernierepos () const { return Derniere_pos ; }
 int player::lancede () { return rand()%(6+1); }
 int player::getpos() const { return Pos ; }
 bool player::Depassement (int d1 , int d2 )
  {   return (( Pos + d1 + d2 ) > 63 ) ; }
 void player::setpos(int d1, int d2) {
    if  ( !Depassement( d1 , d2 ))
          { Derniere_pos = Pos ;
             Pos += d1 + d2 ;
            }
    else if ( Depassement(d1 , d2))
       { int n = Pos + d1 + d2 ;
         int k = n - 63  ;
         Pos=63 - k  ;

        }

    }

 void player::settimewait(int b){timewait=b;}
 int player::gettimewait()const{return timewait;}
 bool player::partieterminee ()
   {
   return ( Pos == 63);
   }


