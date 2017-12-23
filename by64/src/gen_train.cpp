#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "./svg_gen.cpp"
#include <unistd.h>

using namespace std;

string generate_entry(string id_string);
string select_option(int t, string id_string);

int main(){
    // generate id
    // pick shape at random
    // add id and shape to csv file
    // generate svg for shape selected
    int number_of_items = 5000;
    string csv("ID,SHAPE_TYPE");
    string comma(",");
    string carriage_return("\r");
    string id("");
    string shape_type("");

    csv += carriage_return;
    // seeding rand with time as well as getpid
    // this file might be run soon after other files
    // leaving the seed with the same value ( run within the same second ) and
    // thus not producing differeing values  
    srand((unsigned) time(NULL) * getpid() );
    
    for(int i = 0; i < number_of_items; i++){
       id = to_string(i);
       shape_type = generate_entry(id);
       csv += id + comma + shape_type + carriage_return;
    }
  
    ofstream csv_file;
    csv_file.open("output/labels/train.csv");
    csv_file << csv;
    csv_file.close();
}

string  generate_entry(string id_string){
   
    int r = rand() % 5;
   
    string shape_type = select_option(r, id_string);
    
    return shape_type;
}

string select_option(int t,  string id_string){
    enum shape_options { circle, star, square };
    id_string += ".svg";
    t = shape_options(t);
    string shape_type("blank");
    switch(t){

        case circle : {
                genCircle(id_string);
                shape_type = "circle";
            }
            break;
        case star : {
                genStar(id_string);
                shape_type = "star";
            } 
            break;
        case square : {
                genSquare(id_string);
                shape_type = "square";
            }
            break;
        default : { 
                genBlank(id_string);
            }
    }

    return shape_type;
}