#ifndef TSTRING_H

#define TSTRING_H

#include <cstring>

#include "operatory.h"

class TString{
    public:

	TString(const char* s = nullptr);
	TString(const TString& s);
	TString& operator= (const TString& s);
	TString& operator= (TString&& s);
   
    char& operator[](size_t n);
	const char& operator[](size_t n)const;
	  
	char* begin() {return ptr;}
	char* end() {return ptr+len;}
	size_t length() const {return len;}
	void clear() {delete [] ptr; ptr = nullptr; len = 0;}
	bool empty() const {return len ? false : true;}
	char& front() {return *ptr;}
	const char& front() const {return *ptr;}
	char& back() {return*(ptr+len-1); }
	const char& back() const {return *(ptr+len-1);}
    
	size_t size () const{return len; }
	
	
    char* insert(size_t pos, const char* c);
	char* insert(size_t pos, char* c);
	char* erase(size_t bpos = 0, size_t leng = 0);
	friend std::ostream& MojeOperatory::operator<< (std::ostream& strumien, const TString& s);
    friend std::istream& MojeOperatory::operator>> (std::istream& strumien, TString& s );

  
    ~TString();
    private:
    char* ptr=nullptr;
    std::size_t len =0;

    
};
#endif
