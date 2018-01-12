#include <random>
#include <iostream>
#include "generateSVG.h"

using namespace std;



int main()
{  
   

    
   GenerateSVG svg_obj;
   string circle("circle.svg");
   svg_obj.genCircle(circle);
   
   string square("square.svg");
   svg_obj.genSquare(square);
   
   string star("star.svg");
   svg_obj.genStar(star);

   string blank("blank.svg");
   svg_obj.genBlank(blank);

    /*
    string csv2 = labels2.getExamples(number_of_examples);
    cout << " calling a second new instance the first time " << csv2 << endl;
    */

}