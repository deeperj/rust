

#include "unittest.h"

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
  int out[]={1,2,3,4};
  int a=sizeof(out)/sizeof(int);
  int value=shuffleArray(out, a);
  bool shuffled=false;
  for(int i=0;i<a;i++){
    if(i>0){
      if(out[i]>=out[i-1]){
        continue;
      }else{
        shuffled=true;
      }
    }
  }if(shuffled){
    for(int i=0;i<a;i++){
      if(i>0){
        if(out[i]==out[i-1]){
          shuffled=false;
          continue;
        }else{
          shuffled=true;
          break;
        }
      }
    }
  }
  if(shuffled && value==0 ){
    cout << "shuffleArray() test success!" << endl;
  }else{
    cout << "shuffleArray() unit test failed!" << endl;
  }
}

void test_h_find(){
  int hs[]={1,2,3,4};
  int hsl=sizeof(hs)/sizeof(hs[0]);
  // positive test
  cout << "running positive test for h_find().." << endl;
  if(h_find(hs,hsl,3)<0){
    cout << "test failed for h_find" << endl;
  } 
  // negative test
  cout << "running negative test for h_find().." << endl;
  if(h_find(hs,hsl,5)>0){
     cout << "test failed for h_find()" << endl;
  }else{
    cout << "test passed for h_find()" << endl;
  }
}

int h_find(const int haystack[], int len, int needle){
  for(int i=0;i<len; i++){
    if(haystack[i]==needle){
      return i;
    }
  }return -1;
}