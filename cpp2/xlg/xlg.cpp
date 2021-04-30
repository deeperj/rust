#include "xlg.h"



int getNames(string file, string names[]){
  fstream namesfile;
  namesfile.open(file);
  if(!namesfile){
    cout << "file not found" << endl;
    return 0;
  }
  int i=0;
  for (;namesfile >> names[i];i++)
  {
    cout << names[i] << endl;
  }
  namesfile.close();
  return i;
}

  // input: array, length ->output: shuffled array
int shuffleArray(int out[], int arrayLen){
  if(arrayLen<2){
    cout << "xlg::shuffleArray: Array needs at least 2 items" << endl;
    return ERROR;
  }
  // :random generator init;
  srand(time(NULL));
  // while(i<arraylen) is yes then
  for(int i=0;i<arrayLen;i++){
    // :declare -> j=random_between_1_and_arraylen;
    int j=1+(rand()%(arrayLen-1));
    //   while(output_array[j]>0) is yes then
    while(out[j]>0)
      //   :j=random_between_1_and_arraylen;
      j=1+(rand()%arrayLen);
    //:output_array[j]=i;
    out[j]=i;
    //cout << j << " " << i << endl;
  }
  // endfunction
  return 0;
}


int xlg(int x, int y, string arr[], const int len ){
  if(x==0 || y==0 || len ==0){
    return ERROR;
  }
  // :input-> x (no of groups from arr list), y (no of times), array, arraylen;
  // :declare ppg = arraylen/x;
  const int ppg = len/x;
  // :declare rem = arraylen%x;
  int rem = len%x;
  // :declare shuffleArray having length arraylen;
  int shuffle[len] = {0};
  // :call function -> shuffle_array(shuffleArray);
  cout << "debug1 alen=" << len << " " << endl;
  int res=shuffleArray(shuffle, len);
  if(res != SUCCESS){
    cout << "xlg::xlg: an error occurred!" << endl;
    return ERROR;
  }
  for(int i=0; i<y ;i++){
      cout << "Round " << (i+1) << " of " << y << endl;
      int j=0;
      for(j=0;j<x; j++) {  //   :cout << "Group " << (j+1) << endl;
        cout << "Group " << (j+1) << " of " << x << endl;
        //   :declare subArray of length ppg;
        string subl[ppg];
        //   :call function -> sublist(array,subArray,j*ppg,ppg);
        res = sublist(arr, shuffle,subl,j*ppg,ppg);
        if(res != SUCCESS){
          cout << "xlg::xlg: an error occurred!" << endl;
          return ERROR;
        }
    }
    if(rem>0){
      string subl[ppg];
      res = sublist(arr,shuffle,subl,j*ppg,ppg+rem);
      if(res != SUCCESS){
        cout << "xlg::xlg: an error occurred!" << endl;
        return ERROR;
      }
    }
  }
  return SUCCESS;
}

int sublist(string array[], int shuffled[],string out[], int start, int count){
  for(int i=0;i<count;i++){
    // :outputarray[i]=array[shuffleArray[i+start_index]];
    out[i]=array[shuffled[i+start]];   
    cout << (i+1) << ".) "<< out[i] << endl;
  }
  return SUCCESS;
}

