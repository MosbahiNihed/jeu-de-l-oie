#include<iostream>
#include"cases.h"

#include<string>
using namespace std ;
    cases::cases(){num_case=0 ;}
    cases::cases(int n) {num_case=n;}
    int cases::getcase(){return num_case;}
    void cases::setcase(int n){num_case=n;}
