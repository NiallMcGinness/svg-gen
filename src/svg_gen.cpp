#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void genCircle(){
    ofstream outputFile;
    outputFile.open("output/circle.svg");

    string svg_header ("<svg width='512' height='512' viewBox='0 0 512 512' xmlns='http://www.w3.org/2000/svg'>");
    string circle ("<circle cx='256' cy='256' r='256'/>");
    string svg_escape ("</svg>");
    cout<< svg_header + circle << endl;
    string all = svg_header + circle + svg_escape;
    outputFile << all;
    outputFile.close();
}


void genStar(){
     ofstream outputFile;
    outputFile.open("output/star.svg");

    string svg_header ("<svg width='512' height='512' viewBox='0 0 512 512' xmlns='http://www.w3.org/2000/svg'>");
    string star ("<path d='M512 198.525l-176.89-25.704-79.11-160.291-79.108 160.291-176.892 25.704 128 124.769-30.216 176.176 158.216-83.179 158.216 83.179-30.217-176.176 128.001-124.769zM256 376.749l-111.731 58.74 21.338-124.415-90.393-88.111 124.92-18.152 55.866-113.198 55.868 113.198 124.918 18.152-90.394 88.111 21.339 124.415-111.731-58.74z'></path>");
    string svg_escape ("</svg>");
    
    string all = svg_header + star + svg_escape;
    outputFile << all;
    outputFile.close();
}

void genSquare(){
    ofstream outputFile;
    outputFile.open("output/square.svg");

    string svg_header ("<svg width='512' height='512' viewBox='0 0 512 512' xmlns='http://www.w3.org/2000/svg'>");
    string square ("<rect x='256' y='256' width='256' height='256'/>");
    string svg_escape ("</svg>");
    
    string all = svg_header + square + svg_escape;
    outputFile << all;
    outputFile.close();
}

void genBlank(){
    ofstream outputFile;
    outputFile.open("output/blank.svg");

    string svg_header ("<svg width='512' height='512' viewBox='0 0 512 512' xmlns='http://www.w3.org/2000/svg'>");
    
    string svg_escape ("</svg>");
    
    string all = svg_header  + svg_escape;
    outputFile << all;
    outputFile.close();
}