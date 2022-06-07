#include<iostream>
#include"Game.h"
#include<string>

using namespace std ;
Game::Game () {
         int i,nb_joueurs;
          string n ;
          cout<<"entrez votre nombre"<<endl;
          cin>>nb_joueurs ;
          players=new player [nb_joueurs];
          c=new cases [63];

          for ( i =1 ; i < 64 ; i++)
            {
                c[i]=cases(i);//il faut surcharger l'op daffectatio pour la classe cases
            }

            for ( i = 1; i < nb_joueurs+1 ; i++ )
            {cout<<"donner le nom";
             cin>>n;
             player A(n,i) ;

              players[i]=A;/// on doit surcharger l operateur d'affectation;

            }
          }
 void Game::delplayer(){ for (int i=1; i<nb_joueurs ; i++)
          {if((players[i]).partieterminee())
               players[i]=players[i+1];}
 int Game::getord(player p) const {
          for(int i=1 ; i<nb_joueurs ; i++)
          { if ((p.getname())==(players[i].getname()))
            {
              return i ; }}}
 void Game::play (player p) { int i=p.gettimewait();
              if (i==0){d1=lancede();
              d2=lancede();
              p.setpos(d1 , d2 );}
              else
              {
                cout<<"joueurs bloqué"<<endl;
                p.settimewait(i-1);}}
 void Game::jouer ()
          {for ( int i =0 ; i< nb_joueurs +1 ; i++)
          {

              cases c ( tab[i].getpos());
              c.SurCasesteleport(tab[i]);
              c.SurCasesOie(tab[i]);
              c.SurCasesAttente(tab[i]);
            //c.SurCasespiege(player[i]);
              play(tab[i]);
           }
          }
