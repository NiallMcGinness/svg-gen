#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int random_origin_generator(){

    int r = ( rand() % 45 ) + 5; 
    return r;
}

string randomise_origin( string input_string){
    // for rect and circle svg mark up ,  set ran x and y coordinates
    string x_placeholder("<x>");
    string y_placeholder("<y>");
    
    int x = random_origin_generator();
    int y = random_origin_generator();
    
    
    string x_value = to_string(x);
    string y_value = to_string(y);

    size_t x_start_pos = input_string.find(x_placeholder);
    input_string.replace(x_start_pos, x_placeholder.length(), x_value);

    size_t y_start_pos = input_string.find(y_placeholder);
    input_string.replace(y_start_pos, y_placeholder.length(), y_value);

    return input_string;
}

string createFilepath( string id_string){

    string filePath = "output/train/svg/" + id_string;
    return filePath;
}


void genCircle( string id_string ){

    string filePath = createFilepath(id_string);
    ofstream outputFile;
    outputFile.open(filePath);

    string svg_header ("<svg width='64' height='64' viewBox='0 0 64 64' xmlns='http://www.w3.org/2000/svg'> <rect width='100%' height='100%' fill='white'/>");
    string circle_template ("<circle cx='<x>' cy='<y>' r='8' fill='white' stroke='black' stroke-width='3' />");
    string circle = randomise_origin(circle_template);
    string svg_escape ("</svg>");
    
    string all = svg_header + circle + svg_escape;
    outputFile << all;
    outputFile.close();
}

string randomise_star(string input_string){
    
    // returns a string of x,y coordinates for svg polygon position markup
    // each value seperated by a comma
    // each pair of values spearated by a space  
    int x = rand() % 25;
    int y = rand() % 25;

    // get random number and use this to pick the sign 
    // we want positive and negative numbers to move our position around 
    // as we are modifying a base string that is centerish
    
    if ( (rand() % 2)  == 0 ) x = x * -1;
    if ( (rand() % 2)  == 0 ) y = y * -1;


   

    string coordinate_string("");
    string space(" ");
    string comma(",");
    
    vector <vector<int>> base_vector = { {40,15}, {40,20}, {50,22}, {40,25}, {47,35}, {40,30}, {30,35} ,{32,25}, {27,22},  {35,20}};
    
    for (int i = 0; i < base_vector.size(); i++)
    {
        coordinate_string += space + to_string(base_vector[i][0] + x) + comma + to_string(base_vector[i][1] + y) + space;
    }

    string p_placeholder("<p>");

    size_t p_start_pos = input_string.find(p_placeholder);

    input_string.erase( p_start_pos, p_placeholder.length() );
    input_string.insert( p_start_pos, coordinate_string );
    
    return input_string;
}

void genStar( string id_string){

    string filePath = createFilepath(id_string);
    ofstream outputFile;
    outputFile.open(filePath);

    string svg_header ("<svg width='64' height='64' viewBox='0 0 64 64' xmlns='http://www.w3.org/2000/svg'>  <rect width='100%' height='100%' fill='white'/>");
    string star ("<polygon fill='white' stroke='black'  stroke-width='3'  points=' <p> '/>");
    string svg_escape ("</svg>");
    string s = randomise_star(star);
    string all = svg_header + s + svg_escape;
    outputFile << all;
    outputFile.close();
}

void genSquare( string id_string){

    string filePath = createFilepath(id_string);
    ofstream outputFile;
    outputFile.open(filePath);

    string svg_header ("<svg width='64' height='64' viewBox='0 0 64 64' xmlns='http://www.w3.org/2000/svg'>  <rect width='100%' height='100%' fill='white'/>");
    string square_template ("<rect x='<x>' y='<y>' width='16' height='16' fill='white' stroke='black' stroke-width='3'/>");
    string square = randomise_origin(square_template);
    string svg_escape ("</svg>");
    
    string all = svg_header + square + svg_escape;
    outputFile << all;
    outputFile.close();
}


void genBlank( string id_string){

    string filePath = createFilepath(id_string);
    ofstream outputFile;
    outputFile.open(filePath);

    string svg_header ("<svg width='64' height='64' viewBox='0 0 64 64' xmlns='http://www.w3.org/2000/svg'> <rect width='100%' height='100%' fill='white'/>");
    
    string svg_escape ("</svg>");
    
    string all = svg_header  + svg_escape;
    outputFile << all;
    outputFile.close();
}