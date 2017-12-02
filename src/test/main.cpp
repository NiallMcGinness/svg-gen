#include <iostream>
#include <string>
#include <vector>

#include <fstream>
#include "./label_list.cpp"
#include "./svg_gen.cpp"

using namespace std;

string concat(string in_string);
string repl(int x_pos, int y_pos);

int main(){

    string label_csv("first column heading, second column heading");
    int number_of_examples = 1000;
    /*
        iterate though each example 
        for each example pick a category 
        of element to generate , square, star, circle or nothing
        add each choice to the csv with the id
        then generate the image and save svg to output dir
    */
    //string o = concat(label_csv);
    int x = 125, y = 122;
    repl(x,y);
     //cout << o << endl;

}

string repl(int x_pos, int y_pos){

    string square ("<rect x='<x>' y='<y>' width='64' height='64' fill='white' stroke='black' stroke-width='3'/>");
    
    string x_placeholder("<x>");
    string y_placeholder("<y>");
    
    string x_value = to_string(x_pos);
    string y_value = to_string(y_pos);

    size_t x_start_pos = square.find(x_placeholder);
    square.replace(x_start_pos, x_placeholder.length(), x_value);

    size_t y_start_pos = square.find(y_placeholder);
    square.replace(y_start_pos, y_placeholder.length(), y_value);

    cout << square << endl;
    return square;
}

string concat(string in_string){

    string out_string("test");
    out_string = out_string + in_string;

    return out_string;
}