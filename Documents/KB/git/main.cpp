#include "tstring.h"
#include <iostream>
using namespace std;
auto fun(const char* c)
{
return TString(c);
}




int main ()
{
    TString s1;
    TString s2("inicjalizacja slowem");
   TString s3 = s2;
   // TString s3 (s2);
    // albo TString s3 {s2};
   // TString s3 = "alfa beta";
     s3 = s2;
    s3=std::move(s1);
     TString s5=fun("konstruktor przenoszacy");
     TString s6=s2;
     s1 = "zebym nie byl pusty";
     cout << "ta wartosc     "<< s1[3] << endl;
}