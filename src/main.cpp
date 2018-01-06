#include <random>
#include <iostream>
#include "generate_labels.h"

using namespace std;

//random_device rd;
//mt19937 gen(rd());

struct group_s {
   int k;
   uniform_int_distribution<> dis;
} group;


int main()
{  
   /* group.dis = uniform_int_distribution<>(0,4);
    
    for (int i=0; i<100; ++i) {
        cout << group.dis(gen) << ' ' << endl;
    }

    */

    GenerateLabels labels;

    int number_of_examples = 50;

    string csv = labels.getExamples(number_of_examples);

    cout <<  csv << endl;

}