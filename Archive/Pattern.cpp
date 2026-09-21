#include <iostream>

using namespace std;

int main()
{
// Pattern

// 1 1 1 1 
// 2 2 2 2
// 3 3 3 3 
// 4 4 4 4

int n ; 
cout << "Enter the number : " ;
cin >> n ;

// Outer loop
for (int i = 1 ; i <= n ; i++) {
    // Inner loop 
    for (int j = 1 ; j <= n ; j++) {
        //work
        cout << i << " " ;
    }
    cout << endl ;
}


// *
// * *
// * * *
// * * * *

// First way

int n ; 
cout << "Enter the number : " ;
cin >> n ;

for (int i = 1 ; i <= n ; i++) {
    for (int j = 1 ; j <= n ; j++) {
        cout << "* " ;
        if (i == j) {
            break ;
        }
    }
    cout << endl ;
}

// Second way

int n ; 
cout << "Enter the number : " ;
cin >> n ;

for (int i = 1 ; i <= n ; i++) {
    for (int j = 1 ; j <= i ; j++) {
        cout << "* " ;
    }
    cout << endl ;
}


// * * * *
// * * * 
// * *
// *

int n ; 
cout << "Enter the number : " ;
cin >> n ;
for (int i = 1 ; i <= n ; i++) {
    for (int j = 1 ; j <= n-i+1 ; j++) {
        cout << "* " ;
    }
    cout << endl ;
}


// 1
// 1 2
// 1 2 3
// 1 2 3 4

int n ; 
cout << "Enter the number : " ;
cin >> n ;
for (int i = 1 ; i <= n ; i++) {
    for (int j = 1 ; j <= i ; j++) {
        cout << j << " ";
    }
    cout << endl ;
}


// A
// B C
// D E F
// G H I J

int n ;
cout << "Enter the number : " ;
cin >> n ;
char chr = 'A' ;

for (int i = 1 ; i <= n ; i++) {
    for (int j = 1 ; j <= i ; j++) {
        cout << chr << " " ;
        chr ++ ; 
    }
    cout << endl ;
}


// * * * * *
// *       *
// *       *
// * * * * *

int n ; 
cout << "Enter the number : " ;
cin >> n ;

for (int i = 1 ; i <= n ; i++) {
    cout << "*" ; // First star
    for (int j = 1 ; j <= n-1 ; j++) {
        if (i == 1 || i == n) {
            cout << "*" ;
        } else {
            cout << " " ;
        }
    }
    cout << "*" << endl ; // Last star
}


//       *
//     * *
//   * * *
// * * * *

int n ; 
cout << "Enter the number : " ;
cin >> n ;

for (int i = 1 ; i <= n ; i++){
    //Space
    for(int j = 1 ; j <= n-i ; j++) {
        cout << " " ; 
    }
    //Star
    for (int j = 1 ; j <= i ; j++) {
        cout << "*" ;
    }
    cout << endl ;
}


// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 1112131415

int n ; 
cout << "Enter the number : " ;
cin >> n ;
int num = 1 ; 

for (int i = 1 ; i <= n ; i++) {
    for(int j = 1 ; j <= i ; j++) {
        cout << num << " "  ;
        num ++ ;
    }
    cout << endl ;
}


//    *
//   ***
//  *****
// *******

int n ; 
cout << "Enter the number : " ;
cin >> n ;

for (int i = 1 ; i <= n ; i++) {
    // Space
    for (int j = 1 ; j <= n-i ; j++) {
        cout << " " ; 
    }
    // Star
    for (int j = 1 ; j <= 2*i-1 ; j++) {
        cout << "*" ; 
    }
    cout << endl ; 
}


// *******
//  *****
//   ***
//    *
   
int n ; 
cout << "Enter the number : " ;
cin >> n ;

for (int i = n ; i >= 1 ; i--) {
    // Space
    for (int j = 1 ; j <= n-i ; j++) {
        cout << " " ;
    }
    // Star
    for (int j = 1 ; j <= 2*i-1 ; j++) {
         cout << "*" ;
    }
    cout << endl ;
}       


//    *
//   ***
//  *****
// *******
// *******
//  *****
//   ***
//    *

int n ; 
cout << "Enter the number : " ;
cin >> n ;

for (int i = 1 ; i <= n ; i++) {
    // Space
    for (int j = 1 ; j <= n-i ; j++) {
        cout << " " ; 
    }
    // Star
    for (int j = 1 ; j <= 2*i-1 ; j++) {
        cout << "*" ; 
        
    }
    cout << endl ; 
}

for (int i = n ; i >= 1 ; i--) {
    // Space
    for (int j = 1 ; j <= n-i ; j++) {
        cout << " " ;
    }
    // Star
    for (int j = 1 ; j <= 2*i-1 ; j++) {
         cout << "*" ;
    }
    cout << endl ;
}   


// *      *
// **    **
// ***  ***
// ********
// ********
// ***  ***
// **    **
// *      *

int n ; 
cout << "Enter the number : " ;
cin >> n ;

// Upper Half
for (int i = 1 ; i <= n ; i++) { // Outer loop
    // Star
    for (int j = 1 ; j <= i ; j++) {
        cout << "*" ; 
    }
    // Space
    for (int j = 1 ; j <= 2*(n-i) ; j++) {
        cout << " " ; 
    }
    // Star
    for (int j = 1 ; j <= i ; j++) {
        cout << "*" ;
    }
    cout << endl ;
}

// Lower Half
for (int i = n ; i >= 1 ; i--) { // Outer loop
    // Star
    for(int j = i ; j >= 1 ; j--) {
        cout << "*" ;
    }
    // Space
    for (int j = 1 ; j <= 2 * (n-i) ; j++) {
        cout << " " ;
    }
    // Star
    for (int j = i ; j >= 1 ; j--) {
        cout << "*" ;
    }
    cout << endl ;
}


// Q. Print the 0-1 Triangle Pattern. 
// 1
// 01
// 010
// 1010
// 10101

int n ; 
cout << "Enter the number : " ;
cin >> n ;

bool val = true ;

for (int i = 1 ; i <= n ; i++) {
    for (int j = 1 ; j <= i ; j++) {
        cout << val << " " ; 
        val = !val ;
    }
    cout << endl ;
}


// Print the 0-1 Triangle Pattern. 
// 1
// 01
// 101
// 0101
// 10101

int n ; 
cout << "Enter the number : " ;
cin >> n ;

for (int i = 1 ; i <= n ; i++) {
    for(int j = 1 ; j <= i ; j++) {
        if((i + j) % 2 == 0) {
            cout << true << " ";
        } else {
            cout << false << " ";
        }
    }
    cout << endl ;
}


// Q. Print the Rhombus Pattern. 
//     *****
//    *****
//   *****
//  *****
// *****

int n ; 
cout << "Enter the number : " ;
cin >> n ;

for (int i = 1 ; i <= n ; i++) {
    // Space
    for (int j = 1 ; j <= n-i ; j++) {
        cout << " " ;
    }
    cout << "*****" << endl ;
}


// Q. Print the Palindromic Pattern with Numbers.
//     1
//    212
//   32123
//  4321234
// 543212345

int n ;
cout << "Enter the number : " ;
cin >> n ;

for (int i = 1 ; i <= n ; i++) {
    
    // Space
    for (int j = 1 ; j <= n - i ; j++) {
        cout << " " ;
    }
    // backword number
    for (int k = i ; k >= 1 ; k--) {
        cout << k ;
    }
    // forward number
    for (int l = 2 ; l <= i ; l++) {
        cout << l ;
    }
    cout << endl ;
}

    return 0;

}