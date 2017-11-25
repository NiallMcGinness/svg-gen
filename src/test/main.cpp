#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "./label_list.cpp"
#include "./svg_gen.cpp"

using namespace std;

int main(){

    string label_csv;
    int number_of_examples = 1000;
    /*
        iterate though each example 
        for each example pick a category 
        of element to generate , square, star, circle or nothing
        add each choice to the csv with the id
        then generate the image and save svg to output dir
    */

}