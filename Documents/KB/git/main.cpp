#include "tstring.h"
#include <iostream>

using namespace std;
using namespace MojeOperatory;


TString fun(const char* c){
    return TString(c);
}



int main(){
    TString s1=("zebym nie byl pusty");
    s1.insert(0,"wstawka");
    cout<<s1<<endl;
    s1.insert(s1.size(), "a");
     cout<<s1<<endl;
    //s1.erase(0, (s1.size()/2));
    //TString s2("inicjalizacja slowem");
    //TString s3 (s2);
    //s3=s2;
    //s3="alfa beta";
    //TString s4 = std::move(s2);
    //TString s3 = std::move(s1);
    
  //  TString s4 ("test");
//   TString s5 = fun("konstruktor przenoszacy");
    
  //  TString s6 = s4;
    
  //  cout<<s1[3]<<endl;
    
    
   // for(auto n : s1) {++n;} endl(cout);
  //  for(const auto& n : s1) cout<< n << " - ";cout<<endl;

   // cout << "zawartosc obiektu s5: " << s5 << endl;

};
