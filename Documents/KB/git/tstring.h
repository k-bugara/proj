#ifndef TSTRING_H
#define TSTRING_H
#include <cstring>
class TString {
 public:
 TString(const char* s = nullptr);
TString(const TString& s);
TString& operator= (const TString& s);
~TString();
TString& operator= (TString &&s);

char& operator[]( size_t n );
const char& operator[]( size_t n ) const;
 //interfejs
 private:
    char* ptr = nullptr;
    std::size_t len = 0;
    //implementacja
    //składowe
 protected:
};
#endif 