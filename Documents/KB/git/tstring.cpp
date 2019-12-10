#include "tstring.h"
#include <iostream>
#include <stdexcept>

using namespace std;

TString::TString(const char* s):ptr(nullptr), len(0){ 
    if(s>0){
        len =strlen(s);
        ptr = new char [len +1];
        strcpy(ptr,s);
    }
#ifdef DEBUG
	cout<<"TString c-tor"<<len<<" - "<<(ptr ? ptr : "pusty")<<endl;
#endif
}

	TString::~TString(){
#ifdef DEBUG
	cout<<"TString d-tor"<< len <<" - "<<(ptr ? ptr : "pusty")<<endl;
#endif
	delete [] ptr;

}
TString::TString(const TString& s) : ptr(nullptr), len(s.len) {
    if (len>0){
        ptr = new char [len + 1];
        strcpy(ptr, s.ptr);
    }

 #ifdef DEBUG
	cout<<"TString cc-tor"<< len <<" - "<<(ptr ? ptr : "pusty")<<endl;
#endif
}

TString& TString::operator= (const TString& s){
    if (this != &s) {//if (*this !=s 
	}
    delete [] ptr;  
	ptr = nullptr; 
	len=s.len;
    if(len>0)
    {
    ptr = new char [len + 1];
    strcpy(ptr, s.ptr);
    }

    #ifdef DEBUG
	cout<<"TString copy operator= "<< len <<" - "<<(ptr ? ptr : "pusty")<<endl;
#endif
	return *this;


}


    TString& TString::operator=(TString&& s){
        if(this != &s){
            delete [] ptr;
            len = s.len;
            ptr = s.ptr;
            s.len = 0;
            s.ptr = nullptr;
        }
        #ifdef DEBUG
		cout<<"TString move operatro= "<< len <<" - "<<(ptr ? ptr: "pusty")<<endl;
        #endif
        return *this;
    }
   
   
   
 	char& TString::operator[](size_t n){
	if (!ptr) throw invalid_argument("pusty obiket");
	if (n >= 0 && n <= len ) return ptr[n];
	throw out_of_range("In TString::operator[] argument out of scope");

}

 	const char& TString::operator[](size_t n) const {

    if (!ptr) throw invalid_argument("pusty obiket");
	if (n >= 0 && n <= len ) return ptr[n];
	throw out_of_range("In TString::operator[] argument out of scope");
}
    
    
    
	char* TString::insert( size_t pos, const char* c ) {
	if (pos >=0 && pos <= len) {
	size_t oldlen = len;
	len = len+strlen(c);
	char* tmp = new char[ len+1 ];
	strcpy( tmp, ptr );
	for (size_t i=pos; i<pos+strlen(c); ++i) {
	tmp[i] = c[i-pos];
	}
	for (size_t i=pos; i<oldlen; ++i) {
	tmp[i+strlen(c)] = ptr[i];
	}
	delete [] ptr;
	ptr = tmp;
	return ptr;
	} 
else {
	throw out_of_range("zly argument ziomus");
}
	return ptr;

}

	char* TString:: insert(size_t pos, char* c)	{
	if (pos >=0 && pos <= len) {
	size_t oldlen = len;
	len = len+strlen(c);
	char* tmp = new char[ len+1 ];
	strcpy( tmp, ptr );
	for (size_t i=pos; i<pos+strlen(c); ++i) {
	tmp[i] = c[i-pos];
}
	for (size_t i=pos; i<oldlen; ++i) {
	tmp[i+strlen(c)] = ptr[i];
}
	delete [] ptr;
	ptr = tmp;
	return ptr;
} else {
	throw out_of_range("zly argument ziomus");
}
	return ptr;
	cout<<*ptr;

}

char* TString:: erase(size_t bpos, size_t leng)

{if (bpos==0 && leng==0)
    {delete [] ptr;}
if (bpos<leng && (bpos>=0 && leng<=len))
{
char* tmp = new char [len - (leng-bpos+1)];
for (size_t i=0; i<=( len - (leng-bpos+1)); i++)
{tmp[i] = ptr [(leng+1)+i];}
ptr = tmp;
return ptr;
}
else {throw out_of_range("zle argumenty");}


    
}
