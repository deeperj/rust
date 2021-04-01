
#ifndef XLG_H
#define XLG_H

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::fstream;

int getNames(string file, string names[]);
int shuffleArray(int outArray[], int len);
int h_find(int needle[], int len, int hstack);

#endif