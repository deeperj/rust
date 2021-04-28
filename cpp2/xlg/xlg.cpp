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
  // :set output_array values to zero;
  for(int i=0;i<arrayLen;i++)out[i]=0;
  // :random generator init;
  srand(time(NULL));
  // while(i<arraylen) is yes then
  for(int i=0;i<arrayLen;i++){
    // :declare -> j=random_between_1_and_arraylen;
    int j=1+(rand()%arrayLen);
    //   while(output_array[j]>0) is yes then
    while(out[j]>0)
      //   :j=random_between_1_and_arraylen;
      j=1+(rand()%arrayLen);
    //:output_array[j]=i;
    out[j]=i;
  }
  // endfunction
  return 0;
}


int xlg(int x, int y, string arr[], int const len ){
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
  int res=shuffleArray(shuffle, len);
  if(res != SUCCESS){
    return ERROR;
  }
for(int i=0; i<y ;i++){
    cout << "Round " << (i+1) << endl;
    int j=0;
    for(j=0;j<x-1; j++) {  //   :cout << "Group " << (j+1) << endl;
  //   :declare subArray of length ppg;
      string subl[ppg];
  //   :call function -> sublist(array,subArray,j*ppg,ppg);
      res = sublist(arr, shuffle,subl,j*ppg,ppg);
      if(res != SUCCESS){
        return ERROR;
      }
  }
    if(rem>0){
      string subl[ppg];
      res = sublist(arr,shuffle,subl,j*ppg,ppg+rem);
      if(res != SUCCESS){
        return ERROR;
      }
    }
  }
  return SUCCESS;
}

int sublist(string array[], int shuffled[],string out[], int start, int count){
  // begin function -> sublist
  // :input -> array, output_array, shuffleArray, start_index, count;
  // for(i=0;i<count;i++)
  // :outputarray[i]=array[shuffleArray[i+start_index]];
  // :cout << outputarray[i] << endl;
  // endfor
  // endfunction
  return SUCCESS;
}