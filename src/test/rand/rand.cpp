
#include <string>
//#include <random>
//#include <chrono>
#include <iostream>
#include "rand.h"
#include <unistd.h>


using namespace std;

GenerateRandom::GenerateRandom()
{

    //this->csv = "ID,SHAPE_TYPE\n";
   // srand(time(NULL));
   srand((unsigned) time(NULL) * getpid() );
}


int GenerateRandom::getRandom()
{
    //int r = 0;
    int r = ( rand() % 200 ) ;
    
    return r;
}