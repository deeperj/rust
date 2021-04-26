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
  // :input -> output_array, arraylen;
  // :declare -> arraylen as length of ouput_array;
  // :set output_array values to zero;
  // :declare -> i=0;
  // :declare -> j=random_between_1_and_arraylen;
  // while(i<arraylen) is yes then
  //   while(output_array[j]>0) is yes then
  //   :j=random_between_1_and_arraylen;
  //   endwhile is no
  //   :output_array[j]=i;
  //   :i=i+1;
  // endwhile is no
  // endfunction
  return 0;
}