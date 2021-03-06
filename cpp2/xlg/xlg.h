
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
int sublist(string array[], int shuffled[],string out[], int start, int count);
int xlg(int x, int y, string arr[], int len);

enum err_code {SUCCESS,ERROR};

#endif