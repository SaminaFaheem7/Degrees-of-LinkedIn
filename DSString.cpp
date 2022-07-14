// Created by mark on 6/2/2021.
// Updated by Samina Faheem on 6/13/2022

using namespace std;
#include "DSString.h"

//assigning the value of one DSString to another
DSString& DSString :: operator= (const char* arg){
    if(s != nullptr)
    {
        delete []s;
    }
    s = new char[strlen(arg) + 1 ];
    strcpy(s, arg);
    return *this;
}

DSString& DSString :: operator= (const DSString& arg){
    if(s != nullptr)
    {
        delete []s;
    }
    s =  new char[strlen(arg.s) + 1];
    strcpy(s, arg.s);
    return *this;
}

//Adding characters of DSStrings
DSString DSString :: operator+ (const DSString& arg) {
    DSString temp;
    temp.s = new char[strlen(s) + strlen(arg.s) + 1];
    strcpy(temp.s, s);
    strcat(temp.s, arg.s);
    return temp;
}

//Adding and assigning the value of DSStrings
DSString& DSString::operator += (const DSString& arg){
    *this = *this+ arg;
    return *this;
}

//Comparing the values of DSStrings
bool DSString :: operator== (const char* arg) const{
    return strcmp(s,arg) == 0;
}

bool DSString :: operator== (const DSString& arg) const{
    strcmp(s,arg.s);
    return strcmp(s,arg.s) == 0;
}

// Checking if the DSString is > the other
bool DSString :: operator> (const DSString& arg) const{
    strcmp(s,arg.s);
    return strcmp(s,arg.s) > 0;
}

bool DSString :: operator> (const char* arg) const{
    return strcmp(s,arg) > 0;
}

// Checking if the DSString is < the other
bool DSString :: operator< (const DSString& arg) const{
    strcmp(s,arg.s);
    return strcmp(s,arg.s) < 0;
}

bool DSString ::  operator< (const char* arg) const {
    return strcmp(s,arg) < 0;
}

// Checking if the DSString is <= the other
bool DSString :: operator<= (const DSString& arg) const{
    return !(*this > arg);
}
bool DSString :: operator<=(const char* arg) const{
    return !(*this > arg);
}

// Checking if the DSString is <= the other
bool DSString :: operator>= (const DSString& arg) const{
    return !(*this < arg);
}

bool DSString :: operator>=(const char* arg) const{
    return !(*this < arg);
}

//subscript of an array
char& DSString :: operator[] (const int num){
    return *(s + num);
}

//Length of the DSString
int DSString :: getLength(){
    return strlen(s);
}

//subsequence of a DSString
DSString DSString ::  substring(int start, int numChars){
    char* temp= new char[numChars+1];
    strncpy(temp, s+ start, numChars);
    DSString temp2;
    temp2= temp;
    return temp2;
}

char* DSString :: c_str(){
    return s;
}

//Output operator (cout)
ostream& operator<< (ostream& out, const DSString& printword){
    out<< printword.s;
    return out;
}

//Lowering all the alphabets.
DSString DSString:: lower_alphabets(){
    for(int i=0; i<strlen(s); i++)
    {
        s[i] = tolower(s[i]);
    }
    return *this;
}

//Does the string contains it or not
bool DSString::contains(DSString word){
    if(word.getLength()>strlen(s))
    {
        return false;
    }
    for(int i=0; i<strlen(s)-word.getLength(); i++)
    {
        DSString temp;
        temp = substring(i ,word.getLength());
        if(temp == word)
        {
            return true;
        }
    }
    return false;
}