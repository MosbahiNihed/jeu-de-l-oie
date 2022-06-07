#ifndef cases_H
#define cases_H
#include <iostream>
#include <string>
#include "player.h"

using namespace std;

class cases
 {  private:
        int num_case ;

    public :
        cases() ;
        cases(int );
        int getcase();
        void setcase(int);
 };
#endif

