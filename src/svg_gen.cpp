#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int random_origin_generator(){

   
    int r = (rand() % 500);

    cout << " random origin" << r << endl;
    return r;
}

string randomise_origin( string input_string){
    // for rect and circle svg mark up ,  set ran x and y coordinates
    string x_placeholder("<x>");
    string y_placeholder("<y>");
    
    int x = random_origin_generator();
    int y = random_origin_generator();
    cout << x << "  -  " << y  << endl;
    
    string x_value = to_string(x);
    string y_value = to_string(y);

    size_t x_start_pos = input_string.find(x_placeholder);
    input_string.replace(x_start_pos, x_placeholder.length(), x_value);

    size_t y_start_pos = input_string.find(y_placeholder);
    input_string.replace(y_start_pos, y_placeholder.length(), y_value);

    return input_string;
}



void genCircle(){
    ofstream outputFile;
    outputFile.open("output/circle.svg");

    string svg_header ("<svg width='512' height='512' viewBox='0 0 512 512' xmlns='http://www.w3.org/2000/svg'>");
    string circle_template ("<circle cx='<x>' cy='<y>' r='64' fill='white' stroke='black' stroke-width='3' />");
    string circle = randomise_origin(circle_template);
    string svg_escape ("</svg>");
    cout<< svg_header + circle << endl;
    string all = svg_header + circle + svg_escape;
    outputFile << all;
    outputFile.close();
}

string randomise_star( string input_string){
    
    int base_array[10][2] = { {259,105}, {274,135}, {308,140}, {283,162}, {289,194}, {259,179}, {228,194} ,{234,162}, {210,139},  {243,135}};

    int x = random_origin_generator();
    int y = random_origin_generator();
    return input_string;
}

void genStar(){
    ofstream outputFile;
    outputFile.open("output/star.svg");

    string svg_header ("<svg width='512' height='512' viewBox='0 0 512 512' xmlns='http://www.w3.org/2000/svg'>");
    string star ("<polygon fill='white' stroke='black'  stroke-width='3'  points='259,105 274,135 308,140 283,162 289,194 259,179 228,194 234,162 210,139 243,135 '/>");
    string svg_escape ("</svg>");
    string s = randomise_star(star);
    string all = svg_header + star + svg_escape;
    outputFile << all;
    outputFile.close();
}

void genSquare(){
    ofstream outputFile;
    outputFile.open("output/square.svg");

    string svg_header ("<svg width='512' height='512' viewBox='0 0 512 512' xmlns='http://www.w3.org/2000/svg'>");
    string square_template ("<rect x='<x>' y='<y>' width='64' height='64' fill='white' stroke='black' stroke-width='3'/>");
    string square = randomise_origin(square_template);
    string svg_escape ("</svg>");
    
    string all = svg_header + square + svg_escape;
    outputFile << all;
    outputFile.close();
}


void genBlank(){
    ofstream outputFile;
    outputFile.open("output/blank.svg");

    string svg_header ("<svg width='512' height='512' viewBox='0 0 512 512' xmlns='http://www.w3.org/2000/svg'>");
    
    string svg_escape ("</svg>");
    
    string all = svg_header  + svg_escape;
    outputFile << all;
    outputFile.close();
}