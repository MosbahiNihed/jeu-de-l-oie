#include<iostream>
#include"cases.h"

#include<string>
using namespace std ;

  cases::cases(int n)
  { num_case=n;}
 bool cases::calculeroiepos(player p )
         { return ((p.getpos()%9)==0);}
 void cases::suruneoie ( player p )
        {    int i = p.getpos();
             int k = p.getdernierepos();
             if (calculeroiepos(p))
                p.setpos(i-k);
            else  cout<<"continuez";

        };
 void cases::surcaseattente (  player p  )
         {

             if (p.getpos()== 19 && p.getdernierepos()!=19)
                 p.settimewait(2);
             else
                cout<<"passez"<<endl;

         };
 void cases::surcaseteleport( player p )
      {
          int i=p.getpos();
          if (i==6)
             p.setpos(6);
          if (i==42)
             p.setpos(-12);
          if (i==58)
             p.setpos(-57);
          else cout<<"continuez";

      }
  bool cases::caseoccupee(player p) {

                  return (num_case ==p.getpos());

              }

  void cases::surcasepiege(player p )
  {
           }

