#include "tstring.h"
#include "operatory.h"
using namespace std;

ostream& MojeOperatory::operator<<( ostream& strumien, const TString& s ) {
return strumien << ( s.ptr ? s.ptr : "pusty" );
}
istream& MojeOperatory::operator>>( istream& strumien, TString& s ) {
string tmp; // pamiętajmy o nagłówku <string>
getline( strumien, tmp ); // wszystko najpierw ląduje do tmp
// teraz trzeba przepisać
delete [] s.ptr;
s.len = tmp.length();
if ( s.len > 0 ) {
s.ptr = new char[ s.len + 1 ];
strcpy( s.ptr, tmp.c_str() ); // metoda c_str() zwraca const char* z obiektu string
} else {
s.ptr = nullptr;
}
return strumien;
}
