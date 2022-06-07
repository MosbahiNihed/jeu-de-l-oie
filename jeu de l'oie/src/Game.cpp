#include<iostream>
#include<string>
#include "Game.h"
#include "player.h"
#include "cases.h"
#include <windows.h>
#include <unistd.h>
#include "file.h"
using namespace std ;


 Game::Game () {
        int i;
        string n ;
        cout<<"entrez votre nombres "<<endl;
        file<<"entrez votre nombres "<<endl;
        cin>> nb_joueurs ;
        players=new player [nb_joueurs];
        for ( i =0 ; i < 64 ; i++)
            {
                c[i].setcase(0);

            }

        for ( i = 0; i < nb_joueurs ; i++ )
          { cout<<" donner le nom du joueur :"<<i+1<<endl;
          file<<" donner le nom du joueur :"<<i+1<<endl;
            cin>>n;
            players[i].setname(n);
            players[i].setord(i+1);
            }

          }
 int Game::getnb(){return nb_joueurs ;}

 Game :: ~Game () {
    delete [] players;}

 void Game::maping(){
    int k=1;
    for (int j=0;j<3;j++)
    {
    for(int i=0;i<21;i++){cout<<"+----";}cout<<"+"<<endl;
    for(int i=0;i<21;i++){file<<"+----";}file<<"+"<<endl;

    for(int i=0;i<21;i++){if ( c[k+i].getcase() == 0 ) cout<<"|    ";
                        else { cout <<"| p"<<c[k+i].getcase()<<" ";}
                        if ( c[k+i].getcase() == 0 ) file<<"|    ";
                        else { file <<"| p"<<c[k+i].getcase()<<" ";}}
    cout<<"|"<<endl;
    file<<"|"<<endl;
    for(int i=0;i<21;i++){cout<<"+----";}cout<<"+"<<endl;
    for(int i=0;i<21;i++){file<<"+----";}file<<"+"<<endl;
    if (k==1){
        for(int i=0;i<9;i++){cout<<"  "<<i+k<<"  ";}
        for(int i=0;i<9;i++){file<<"  "<<i+k<<"  ";}
        for(int i=9;i<21;i++){cout<<" "<<i+k<<"  ";}
        for(int i=9;i<21;i++){file<<" "<<i+k<<"  ";}
    }
    else{for(int i=0;i<21;i++){cout<<" "<<i+k<<"  ";}
    for(int i=0;i<21;i++){file<<" "<<i+k<<"  ";}}
    k+=21;
    cout<<endl;
    file<<endl;
}}

 void Game::delplayer(player k)
 {
    player * p;
    p=new player [nb_joueurs-1];
    int incr=0;
    for (int i=0; i< nb_joueurs ;i++)
        {
            if (k.getord()!= players[i].getord())
                {   p[incr]=players[i];
                    incr++;
                }
        }
    delete [] players;
    players=p;
 }

 bool Game::calculeroiepos(int oie  )
         { return (((oie)%9)==0);}
 void Game::play(int i){
    int j=players[i].gettimewait();
    if (j==0){
        string s="";
        do{
        cout<<players[i].getname()<<" : tapez 'lance' pour lancer les DES :"<<endl;
        file<<players[i].getname()<<" : tapez 'lance' pour lancer les DES :"<<endl;
        cin>>s;
        }while(s!="lance");
        int d1=players[i].lancede();
       int d2=players[i].lancede();
        cout<<"le resultat de lancement de premier de est : "<<d1<<endl;//--------------------------
        file<<"le resultat de lancement de premier de est : "<<d1<<endl;//--------------------------
        cout<<"le resultat de lancement de deuxieme de est : "<<d2<<endl;//-------------------------
        file<<"le resultat de lancement de deuxieme de est : "<<d2<<endl;
        cout<<"le resultat de lancement est : "<<d1+d2<<endl;
        file<<"le resultat de lancement est : "<<d1+d2<<endl;
        Sleep(2000);
        system("cls");

        if((players[i].getpos()==0)&&((d1+d2)==9))
            {premiertour(i,d1,d2);
            file<<"rani fil tour louel"<<endl;
            avancer_joueur(i,0);
            }
        else{
        file<<"moch tour louel"<<endl;
        int aux = players[i].getpos();
        players[i].setpos(d1,d2);
        players[i].setdernierepos(aux);
        avancer_joueur(i,aux);
        if(aux+d1+d2==19){players[i].settimewait(2);}
        if(calculeroiepos(players[i].getpos())) //------------------------case oie-
        {file<<"bedht aadhma fi djeja"<<endl;
        if(c[players[i].getpos()+d1+d2].getcase()!=0)
                {surcaseoie(i,d1,d2);
                avancer_joueur(i,aux);}
                else surcaseoie(i,d1,d2);
                }
        if(calculeroiepos(players[i].getpos()))
        //------------------------case oie ------------------------------
                {file<<"fi djeja"<<endl;
            players[i].settimewait(2);}
        surcaseteleport(players[i].getpos());
        if ((aux+d1+d2)== 63){changer(aux,i,d1,d2);}
}  } else if (players[i].getpos()==31 || players[i].getpos()==52  ) {system("cls");} else{players[i].settimewait(j-1) ; system("cls");}}

void Game::changer(int aux , int i , int d1 , int d2) {
                    players[i].setpos(d1,d2);
                    c[63].setcase(players[i].getord());
                    players[i].setdernierepos(aux);
                    c[players[i].getdernierepos()].setcase(0);
                    c[63].setcase(0);
                    cout<<"partie terminee pour le joueur "<<players[i].getord()<<"  a la position"<<players[i].getpos()<<endl;
                    file<<"partie terminee pour le joueur "<<players[i].getord()<<"  a la position"<<players[i].getpos()<<endl;
                    delplayer(players[i]);
                    nb_joueurs--;
                    cout<<"le nouveau nombre de joueurs est " <<nb_joueurs<<endl;
                    file<<"le nouveau nombre de joueurs est " <<nb_joueurs<<endl;
}

void Game::surcaseteleport(int j ) {
    int k = c[j].getcase();
    int g=players[k-1].getdernierepos();
    switch(j) {
        case 6 :
                    players[k-1].setpos(6);
                    players[k-1].setdernierepos(g);
                    c[players[k-1].getpos()].setcase(k);
                     file<<"bich ntir 12"<<endl;
                    c[6].setcase(0);
                    break;
        case 42:
                    players[k-1].setpos(-12);
                    players[k-1].setdernierepos(g);
                    c[players[k-1].getpos()].setcase(k);
                    file<<"bich ntir 30"<<endl;
                    c[42].setcase(0);
                    break;
        case 58 :   players[k-1].setpos(-57);
                    players[k-1].setdernierepos(g);
                    c[players[k-1].getpos()].setcase(k);
                     file<<"bich ntir 1"<<endl;
                    c[58].setcase(0);
                    break;
    }
}
void Game::avancer_joueur(int i, int aux) {
    if(c[players[i].getpos()].getcase()!=0){
               if (players[i].getpos()!=31 && players[i].getpos()!=52 ){
                file<<"badel aadi"<<endl;
                int q=c[players[i].getpos()].getcase();
                c[players[i].getpos()].setcase(players[i].getord());
                c[aux].setcase(0);
                c[players[q-1].getdernierepos()].setcase(q);
                players[q-1].setpos(players[q-1].getdernierepos()-players[i].getpos());
                players[q-1].setdernierepos(players[i].getpos());
                players[i].setdernierepos(aux);
                file<<"elli yal3ab pos :"<<players[i].getpos()<<endl;
                file<<"elli yal3ab derpos :"<<players[i].getdernierepos()<<endl;
                file<<"fakouli il blasa pos :"<<players[q-1].getpos()<<endl;
                file<<"fakouli il blasa derpos :"<<players[q-1].getdernierepos()<<endl;


        }else { file<<"il jdid ijaded"<<endl;
                int k=players[i].getpos();
                int q=c[k].getcase();
                players[q-1].settimewait(0);
                c[aux].setcase(q);
                players[q-1].setpos(aux - k );
                c[k].setcase(players[i].getord());
                players[i].setdernierepos(aux);
                players[q-1].setdernierepos(k);
                players[i].settimewait(1);
                file<<"elli yal3ab pos :"<<players[i].getpos()<<endl;
                file<<"elli yal3ab derpos :"<<players[i].getdernierepos()<<endl;
                file<<"fakouli il blasa pos :"<<players[q-1].getpos()<<endl;
                file<<"fakouli il blasa derpos :"<<players[q-1].getdernierepos()<<endl;
                } }

        else{ if (players[i].getpos()!=31 && players[i].getpos()!=52){
            file<<"rani jawi behi"<<endl;
        c[players[i].getpos()].setcase(players[i].getord());
        players[i].setdernierepos(aux);
        c[players[i].getdernierepos()].setcase(0);
           file<<"elli yal3ab pos :"<<players[i].getpos()<<endl;
          file<<"elli yal3ab derpos :"<<players[i].getdernierepos()<<endl;}
       else {  file << "ranitnahdart jdid"<<endl;
                players[i].settimewait(3);
                c[players[i].getpos()].setcase(players[i].getord());
                players[i].setdernierepos(aux);
                c[players[i].getdernierepos()].setcase(0);
                file<<"elli yal3ab pos :"<<players[i].getpos()<<endl;
                file<<"elli yal3ab derpos :"<<players[i].getdernierepos()<<endl;}}

}
void Game::surcaseoie (int i , int d1 , int d2) {
                int n = players[i].getpos();
                players[i].setdernierepos(n);
                players[i].setpos(d1,d2);
                c[players[i].getpos()].setcase(players[i].getord());
                c[players[i].getdernierepos()].setcase(0);
}
int Game::premiertour(int i , int d1 , int d2) {
    if (((d1==4)&&(d2==5))||((d1==5)&&(d2==4)))
            {   players[i].setpos(53);
            }
    if (((d1==6)&&(d2==3))||((d1==3)&&(d2==6)))
                 {  players[i].setpos(26);
                 }
}
bool Game::partieterminee(player k) {
    if (k.getpos() == 63)
        return true;
    else
        return false;
}
