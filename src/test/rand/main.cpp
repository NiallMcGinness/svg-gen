#include <random>
#include <iostream>
#include "rand.h"

using namespace std;



int main()
{  
   

    GenerateRandom rand_obj;
    

   int rand_int = rand_obj.getRandom(); 
   int rand_int2 = rand_obj.getRandom(); 
   cout <<  rand_int << endl;
   cout <<  rand_int2 << endl;
   

}