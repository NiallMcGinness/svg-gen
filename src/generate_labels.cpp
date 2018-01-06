#include <random>
#include <iostream>
#include <string>
#include <random>
#include <iostream>
#include "generate_labels.h"

using namespace std;

GenerateLabels::GenerateLabels()
{

    this->csv_string += string("ID,SHAPE_TYPE\r");
    this->comma = string(",");
    this->carriage_return = string("\r");
}

string GenerateLabels::getExamples(int number_of_examples)
{
    
    //uniform_int_distribution<> group = uniform_int_distribution<>(0,3);
    int shape_type;
    string id, shape_selected;
    for (int i=0; i < number_of_examples; ++i) {
        shape_type = this->get_random_shape_value();
        // cout <<  shape_type << endl;
        shape_selected = this->select_shape(shape_type);
        id = to_string(i);
        //this->csv_string += ( id + comma + shape_selected + carriage_return ) ;
    }

    return this->csv_string;
}

int GenerateLabels::get_random_shape_value()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist = uniform_int_distribution<>(0,3);

    int random_value = dist(gen);
    
    return random_value; 
}

string GenerateLabels::select_shape(int t)
{
    enum shape_options { circle, star, square };
   
    t = shape_options(t);
    
    string shape_type;
    
    switch(t){

        case circle : {
                
                shape_type = "circle";
            }
            break;
        case star : {
               
                shape_type = "star";
            } 
            break;
        case square : {
               
                shape_type = "square";
            }
            break;
        default : { 
              
                shape_type = "blank";
            }
    }

    return shape_type;
}