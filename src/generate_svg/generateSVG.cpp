
#include "generateSVG.h"
#include <iostream>
#include <random>
#include <string>
#include <unistd.h>

GenerateSVG::GenerateSVG() { this->outputDirectory = "output/train/svg/"; }

void GenerateSVG::setOutputDirectory(string output_directory) {

  this->outputDirectory = output_directory;
}

void GenerateSVG::genCircle(string id_string) {
  string filePath = createFilepath(id_string);
  ofstream outputFile;
  outputFile.open(filePath);

  string svg_header("<svg width='64' height='64' viewBox='0 0 64 64' "
                    "xmlns='http://www.w3.org/2000/svg'> <rect width='100%' "
                    "height='100%' fill='white'/>");
  string circle_template("<circle cx='<x>' cy='<y>' r='8' fill='white' "
                         "stroke='black' stroke-width='3' />");
  string circle = randomise_origin(circle_template);
  string svg_escape("</svg>");

  string all = svg_header + circle + svg_escape;
  outputFile << all;
  outputFile.close();
}

void GenerateSVG::genStar(string) {}

void GenerateSVG::genSquare(string) {}

void GenerateSVG::genBlank(string) {}

int random_origin_generator() {}
string randomise_origin(string) {}
string createFilepath(string) {}
string randomise_star(string) {}