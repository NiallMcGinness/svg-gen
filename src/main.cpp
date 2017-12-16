#include "./gen_train.cpp"
#include "./gen_test.cpp"
#include <iostream>

int main(){
    srand(time(NULL));

    generate_training_svg();
    generate_testing_svg();
}