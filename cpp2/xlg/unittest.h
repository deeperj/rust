

#include "xlg.h"

void test_get_names(){
  //function takes in a test file an output array and returns number of lines
  //it should return at least 1 line
  int a=30;
  string fNames[a];
  int value=getNames("data.txt", fNames);
  if(value>0){
    cout << "getNames() test success! Processed .. " << value << " names!" << endl;
  }else{
    cout << "getNames() unit test failed!" << endl;
  }
}

void test_shuffle_array(){
  int a=30;
  int out[a];
  int value=shuffleArray(out, a);
  if(value>0){
    cout << "shuffleArray() test success! Processed .. " << value << " names!" << endl;
  }else{
    cout << "shuffleArray() unit test failed!" << endl;
  }
}