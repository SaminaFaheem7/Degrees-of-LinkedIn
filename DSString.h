#ifndef PA01_SENTIMENT_DSSTRING_H
#define PA01_SENTIMENT_DSSTRING_H

#include <iostream>
#include <cstring>
#include <vector>

class DSString{
private:
    char* s;

public:
    DSString(){
        s = new char[1];
        s[0] = '\0';
    }

    // 1 needs a place to live
    DSString(const char* arg){
        s = new char[strlen(arg) + 1 ];
        strcpy(s, arg);
    }
    //copy constructor deep cop
    DSString(const DSString& arg) {
        s =  new char[strlen(arg.s) + 1];
        strcpy(s, arg.s);
    }

    ~DSString(){
        delete []s;
    }

    DSString& operator= (const char* arg);
    DSString& operator= (const DSString& arg);

    DSString operator+ (const DSString& arg);

    DSString& operator+= (const DSString& arg);

    bool operator== (const char* arg) const;
    bool operator== (const DSString& arg) const;

    bool operator>  (const DSString& arg) const;
    bool operator>  (const char* arg) const;

    bool operator<  (const DSString& arg)const;
    bool operator<  (const char* arg)const;

    bool operator<= (const DSString& arg)const;
    bool operator<= (const char* arg)const;

    bool operator>= (const DSString& arg) const;
    bool operator>= (const char* arg) const;

    char& operator[] (const int num);

    int getLength();

    DSString substring(int start, int numChars);

    char* c_str();

    friend std::ostream& operator<< (std::ostream&, const DSString&);

    DSString lower_alphabets();
    bool contains(DSString substring);
};
#endif //PA01_SENTIMENT_DSSTRING_H
