#include <random>
#include <iostream>
#include <string>
#include <sstream>
#include "generate_labels/generate_labels.h"
#include "generate_svg/generateSVG.h"

using namespace std;

void parse_svg_string(string csv);
void select_shape_to_generate(string shape_type, string file_name, GenerateSVG svg_obj);


int main()
{  
   

    GenerateLabels labels;
   // GenerateLabels labels2;

    int number_of_examples = 100;

    string test_csv = labels.getExamples(number_of_examples);
    parse_svg_string(test_csv);

}

void parse_svg_string(string csv)
{
    string row;
    stringstream stream(csv);
    vector<string>  vector_of_rows;
   

    while( getline(stream,row)  ) 
    {
        vector_of_rows.push_back(row);
    }
   
    GenerateSVG svg_obj;
    string id_number, file_name, shape_type;
    for(std::vector<string>::iterator it = vector_of_rows.begin() + 1; it != vector_of_rows.end(); ++it) 
    {
        row = *it;
        
        size_t comma_pos = row.find(",");

        id_number = row.substr(0,comma_pos);
        file_name = id_number + ".svg";
        shape_type = row.substr(comma_pos + 1 );

        select_shape_to_generate(shape_type, file_name, svg_obj);
    }


}

void select_shape_to_generate(string shape_type, string file_name, GenerateSVG svg_obj)
{
    if ( shape_type == "circle" )
        svg_obj.genCircle(file_name);
    else if ( shape_type == "square" )
        svg_obj.genSquare(file_name);
    else if ( shape_type == "star" )
        svg_obj.genStar(file_name);
    else
        svg_obj.genBlank(file_name);  
}