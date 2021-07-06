
#include "xlg.h"
#include "unittest.h"


int main() {
  string array[30];
  int length=getNames("data.txt",array);
  int x, y;
  cout << "how  many lists: ";
  cin >> x;
  cout << "how  many groups: ";
  cin >> y;
  xlg(x,y,array,length);
}