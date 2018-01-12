#include <random>
#include <string>

#ifndef GENERATESVG_H_INCLUDED
#define GENERATESVG_H_INCLUDED

using namespace std;

class GenerateSVG {

public:
  GenerateSVG();
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

  string randomise_star(string);
};

#endif