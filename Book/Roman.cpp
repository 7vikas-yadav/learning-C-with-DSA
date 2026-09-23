// Roman1 : From decimal to Roman.

#include <iostream>
#include <stdlib.h>

// using namespace std ;
class Roman {
    private :
        enum {L = 100} ;
    public :
        Roman (unsigned n) ;
        char a [L] ;
} ;

Roman::Roman(unsigned n) 
{
     int v[] = {1000 , 900 , 500 , 400 , 100 , 90 , 50 , 40 , 10 , 9 , 5 , 4 , 1} ,
     len = sizeof(v)/sizeof(*v) ;
     char *r[] = {"M" , "CM" , "D" , "CD" , "C" , "XC" , "L" , "XL" , "X" , "IX" , "V" , "IV" , "I"} ;
     int pos = 0 ;
     for (int i = 0 ; i < len ; i++) {
        while (v[i] <= n) {
            if (pos + 3 > L) {
                std::cout << "Number too large.\n" ; exit(1) ;
            }
            a[pos++] = r[i][0] ;
            if (r[i][1]) a[pos++] = r[i][1] ;
            n -= v[i] ;
        }
     }
     a[pos] = '\0' ;
}

int main() {
    unsigned n ;
    std::cout << "Enter a decimal number :" ;
    std::cin >> n ;
    std::cout << "Roman :" << Roman(n).a << std::endl ;
    return 0 ;
}