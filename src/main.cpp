#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "./svg_gen.cpp"

using namespace std;

string generate_entry(string id_string);
string select_option(int t, string id_string);

int main(){
    // generate id
    // pick shape at random
    // add id and shape to csv file
    // generate svg for shape selected
    string csv("ID,SHAPE_TYPE");
    string comma(",");
    string id("");
    string shape_type("");
    srand(time(NULL));
    for(int i = 0; i < 20; i++){
       id = to_string(i);
       shape_type = generate_entry(id);
       csv += comma + id + comma + shape_type;
    }
  
    cout << csv;
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