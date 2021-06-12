#include "Base.h"

string Base::convert(int num)
{
    int rem;
    string s;
    if (num<=1)
    {
        return num==1?"1":"0";
    }
    rem = num % 2;
    s=convert(num /2);
    s+=rem==1?"1":"0";
    return s;
}
string Base::lookup(string num)
{
    string rv;
    if(num.length()==3){
        if(num.compare("000")==0) rv="0"; 
        if(num.compare("001")==0) rv="1"; 
        if(num.compare("010")==0) rv="2"; 
        if(num.compare("011")==0) rv="3"; 
        if(num.compare("100")==0) rv="4"; 
        if(num.compare("101")==0) rv="5"; 
        if(num.compare("110")==0) rv="6"; 
        if(num.compare("111")==0) rv="7"; 
    }else{
        if(num.compare("0000")==0) rv="0"; 
        if(num.compare("0001")==0) rv="1"; 
        if(num.compare("0010")==0) rv="2"; 
        if(num.compare("0011")==0) rv="3"; 
        if(num.compare("0100")==0) rv="4"; 
        if(num.compare("0101")==0) rv="5"; 
        if(num.compare("0110")==0) rv="6"; 
        if(num.compare("0111")==0) rv="7"; 
        if(num.compare("1000")==0) rv="8"; 
        if(num.compare("1001")==0) rv="9"; 
        if(num.compare("1010")==0) rv="A"; 
        if(num.compare("1011")==0) rv="B"; 
        if(num.compare("1100")==0) rv="C"; 
        if(num.compare("1101")==0) rv="D"; 
        if(num.compare("1110")==0) rv="E"; 
        if(num.compare("1111")==0) rv="F"; 
    }
    return rv;
}

string Hex::convert(int cval)
{
    // call the base class function
    string st=Base::convert(cval);

    // first let's group the  result of the binary function into threes

    // first get the remainder
    int rem=st.length()%4;

    // pad if remainder doesn't equal 0
    if(rem!=0){
        if(rem==1)
            st="000"+st;
        else if(rem==2)
            st="00"+st;
        else
            st="0"+st;
    }
    // split the string into groups of fours
    int stl=st.length()/4;

    //use a for loop, substring and lookup to convert to radix
    string h;
    for(int i=0;i<stl;i++)
        h+=lookup(st.substr(i*4,4));
    return h;
}

string Octal::convert(int cval)
{
    // call the base class function
    string st=Base::convert(cval);

    // first let's group the  result of the binary function into threes

    // first get the remainder
    int rem=st.length()%3;

    // pad if remainder doesn't equal 0
    if(rem!=0)st=rem==1?"00"+st:"0"+st;

    // split the string into groups of threes
    int stl=st.length()/3;

    //use a for loop, supstring and lookup to convert to radix
    string oct;
    for(int i=0;i<stl;i++)
        oct+=lookup(st.substr(i*3,3));
    return oct;

}