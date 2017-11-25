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

    for(int i = 0; i < 20; i++){
        random_number();
    }
    /*
    genCircle();
    genStar();
    genSquare();
    */
}

int random_number(){

    int r = rand() % 10;

    cout << " random number " << r << endl;
    test_option(r);
    return r;
}

void test_option(int t){
    enum shape_options { circle, star, square, random };

    t = shape_options(t);

    switch(t){

        case circle : cout << " circle\n "; break;
        case star : cout << " star\n "; break;
        case square : cout << " square\n "; break;
        case random : cout << " random\n "; break;
        default : cout << " blank\n ";
    }
}