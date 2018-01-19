#include <random>
#include <string>
#include <iostream>

#ifndef GENERATESVG_H_INCLUDED
#define GENERATESVG_H_INCLUDED

using namespace std;

class GenerateSVG {

public:
  GenerateSVG();
  //explicit GenerateRandomScales() : mt{rd()}, distribution{1, 2} {};
  bool randomiseScale(bool);
  void setOutputDirectory(string);
  void genCircle(string);
  void genStar(string);
  void genSquare(string);
  void genBlank(string);

private:
  int random_origin_generator();
  string randomise_origin(string);
  string createFilepath(string);
  string outputDirectory;
  bool randomScaleSet;
 

  string randomise_star(string);
};

#endif