#include <string>
#include <random>
#include <iostream>
#ifndef PEOPLE_H_INCLUDED
#define PEOPLE_H_INCLUDED


using namespace std; 

class GenerateLabels{

   // using std::string;

    private:
        string csv_string, comma, carriage_return;
    public:
        GenerateLabels();
        string getExamples(int number_of_examples);
        int get_random_shape_value();
        string select_shape(int t);
        
};




#endif 