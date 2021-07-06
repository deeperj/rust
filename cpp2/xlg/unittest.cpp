

#include "unittest.h"
#include "expect.h"

void test_get_names(){
  //function takes in a test file an output array and returns number of lines
  //it should return at least 1 line
  const int a=30;
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

int expect_find_positive(){
    // 1. Arrange
    int hs[]={1,2,3,4};
    int hsl=sizeof(hs)/sizeof(hs[0]);
    // 2. Act and Assert
    return h_find(hs,hsl,3);
}

int expect_find_negative(){
    // 1. Arrange
    int hs[]={1,2,3,4};
    int hsl=sizeof(hs)/sizeof(hs[0]);
    // 2. Act 
    return h_find(hs,hsl,5);
}

void test_find(){
    describe("test postive and negative h_find()", [=] {
        describe("test positive h_find(hstack,len,needle) and returns an index or -1", [] {
          // 1. Arrange
          int hs[]={1,2,3,4};
          int hsl=sizeof(hs)/sizeof(hs[0]);
          it("should return the index of 0 for h_ind(hs,hsl,3) ",[=] {
          // 2. Act and assert
              expect(h_find(hs,hsl,5)).toBe(-1);
          });
        });
        describe("test negative h_find(hstack,len,needle) and returns an index or -1", [] {
          it("should return the index of 0 for h_ind(hs,hsl,3) ",[] {
              expect(expect_find_negative()).toBe(-1);
          });
        });
    });
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

void test_xlg(){
  //Arrange
  const int a=30;
  string fNames[a];
  int value=getNames("data.txt", fNames);
  //Action
  int res=xlg(2,3,fNames,value);
  //Assert
  switch(res){
    case ERROR:
      cout << "test alg() Failed!" << endl ;
      break;
    default:
      cout << "test alg() Success!" << endl;
  }
}

void test_sublist(){
  //Arrange
  string arr[]={"1,2,3,4"};
  int sh[]={1,2,3,4};
  //Action
  int res=sublist(arr,sh,arr,0,0);
  //Assert
  switch(res){
    case ERROR:
      cout << "test sublist() Failed!" << endl ;
      break;
    default:
      cout << "test sublist() Success!" << endl;
  }
}
