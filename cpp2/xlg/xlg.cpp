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


int xlg(int x, int y, string arr[], int len){
  // :input-> x, y, array, arraylen;
  // :declare ppg = arraylen/x;
  // :declare rem = arraylen%x;
  // :declare shuffleArray having length arraylen;
  // :call function -> shuffle_array(shuffleArray);
  // for(i=0;i<y;i++)
  // :cout << "Round " << (i+1) << endl;
  // :declare -> j=0;
  // while(j<x-1) is yes then
  //   :cout << "Group " << (j+1) << endl;
  //   :declare subArray of length ppg;
  //   :call function -> sublist(array,subArray,j*ppg,ppg);
  //   :j=j+1;
  // endwhile
  // :call function -> sublist(array,subArray,j*ppg,ppg+rem);
  // endfor
  // stop
  return 0;
}