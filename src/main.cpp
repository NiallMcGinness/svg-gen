#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "./svg_gen.cpp"

using namespace std;

int random_number();
void test_option(int t);

int main(){

    enum shape_options { circle, star, square, random };
    srand(time(NULL));
    for(int i = 0; i < 20; i++){
       random_number();
    }
    /*
    string in ("<circle cx='<x>' cy='<y>' r='64' fill='white' stroke='black' stroke-width='3' />");
    string t = randomise_origin(in); 
    cout << t << endl;
    */
    
    //genCircle();
    genStar();
    //genSquare();
    
}

int random_number(){
   
    int r = rand() % 10;
    test_option(r);
    return r;
}

void test_option(int t){
    enum shape_options { circle, star, square, random };

    t = shape_options(t);

    switch(t){

        case circle : genCircle(); break;
        case star : cout << " star\n "; break;
        case square : genSquare();; break;
        case random : cout << " random\n "; break;
        default : cout << " blank\n ";
    }
}