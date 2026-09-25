#include <iostream>

#include <iomanip>

using namespace std;

int scope = 24 ;  // Global scope

void sayHello () {
    cout << "Hello :)\n" ; 
}

void assistant () {
    sayHello () ; // call to funtion sayHello
    cout << "work done \n" ;
}

string MyName() ;  // Function declare

int sum(int a , int b = 1) {  // a , b are parameters
    int sum = a + b ; 
    return sum ;
}

double sum(double a, double b ) {  // Function Overloading with Type of parameters
    return a + b ;
}

int sum (int a , int b , int c) {  // Function Overloading with no. of parameters
    return a + b + c ;
}

void BinToDec (int BinNum) {
    int n = BinNum ;
    int DecNum = 0 ;
    int pow = 1 ;  // 2^0 2^1 2^2 ...

    while (n > 0) {
        int digit = n % 10 ;
        DecNum = DecNum + (digit * pow) ;

        pow *= 2 ;
        n /= 10 ;
    }
    cout << DecNum << endl ;
}

void DecToBin (long long DecNum) {
    long long n = DecNum ;
    long long BinNum = 0 ;
    long long pow = 1 ; // 10^0  10^1  10^2 ...
    while (n > 0) {
        long long digit = n % 2 ;
        BinNum += pow * digit ;
        pow *= 10 ;
        n /= 2 ;
    }
    cout << BinNum << endl ;
}

void changeA(int a) {
    a = 20 ; 
    cout << a << "\n" ;
}

// pass by reference using pointer
void changeB(int *ptr) {
    *ptr = 50 ;
    cout << *ptr << "\n" ;
}

// pass by reference using reference variable
void changeX(int &y) {
    y = 50 ;
    cout << y << "\n" ;
}


int main() 
{
// // Draw Pattern

//     cout << "*****\n";
//     cout << "****\n";
//     cout << "***\n";
//     cout << "**\n";
//     cout << "*\n";


// // Variables

// int a = 10;
// int b = 20;

//     cout << "a is " << a <<endl;
//     cout << "b is " << b <<endl;

// int a;

//     cout << "a is " << a <<endl;  // a = Grabeg Value

// a = 30;

//     cout << "a is " << a <<endl;

// // Data types

// int age = 49;
// int marks = 48;

// cout <<"Size of int = "<< sizeof(int) <<endl;

// char grad = 'A';

// bool isAdult = true;

// float cgpa = 8.9;

// cout << age <<" " << grad << " " << isAdult << " " << cgpa << " " << endl;

// float PI = 3.14159265359;
// double PI2 = 3.14159265359;

// cout << "PI = " << PI << endl;
// cout << "PI2 = " << PI2 << endl;

// cout <<setprecision(13) << "PI = " << PI << endl;
// cout << setprecision(13) << "PI2 = " << PI2 << endl;


// // input

// int age; // grabege value
// cout << "Enter your age : ";
// cin >> age ;
// cout << "yout age is " <<age << endl;

// //Sum of two number
// int a,b;
// cin >>a;
// cin >> b;

// int sum = a+b;

// cout << sum << endl;

// // Constant

// const int g = 9.8 ;

// //Type Casting

// // Implicit conversion

//     cout << ( 10 / 3 ) << endl ; // 3  int
//     cout << ( 10.0 / 3 ) << endl ; // 3.33333  double
//     cout << ( 'a' + 1 ) << endl ;  // 98  int

// // Explicit Conversion

//     cout << (int)'A' << endl ;    // 65  int
//     cout << (int)1.99 << endl ;   // 1
//     cout << (float)10/3 << endl ; // 3.33333
//     cout << (float)(10/3) << endl ;// 3
//     cout << (char)('a' + 1) << endl ; // b
//     cout << (bool) 3  << endl ;  // 1
//     cout << (bool) 3 + 2 << endl ;  // 1 + 2 = 3
//     cout << (23.5 + 2 + 'A') << endl ; // 23.5 + 2 + 65 = 90.5

// // Arithmetic opreators
// // Binary
// int a = 5 ;
// int b = 10 ;

//     cout << "+ --> " << (a + b) << endl ;   // 15 (Addition)
//     cout << "- --> " << (a - b) << endl ;   // -5 (subtration)
//     cout << "* --> " << (a * b) << endl ;   // 50 (Multiply)
//     cout << "/ --> " << (a / b) << endl ;   // 0 (Division)
//     cout << "% --> " << (a % b) << endl ;   // 5 (Modulo)

// // Unary

// int a = 3 ;

// // Increment Operatiors
// a ++ ; // 4 
// cout << "a = " << a << endl ;

// // (post Incremant)
// int b = ++a ; // 5 (post Incremant)
// cout << "b = " << b << endl ;

// // (per Incremant)
// int c = a++ ; // 5 (per Incremant)
// cout << "c = " << c << endl ;

// // (Decrement)
// a -- ; // 5 
// cout << "a = " << a << endl ;

// // (post Decrement)
// int d = a-- ; // 5 (post Decrement)
// cout << "d = " << d << endl ;

// // (pre Decrement)
// int e = --a ; // 3 (per Decrement)
// cout << "e = " << e << endl ;

// // Assignment Operator
// int a = 10 ;

// a += 5 ; // a = a + 5 -> 15
// cout << a << endl;

// a -= 5 ; // a = a - 5 -> 10
// cout << a << endl ;

// a *= 5 ; // a = a * 5 -> 50
// cout << a << endl ; 

// a /= 5 ; // a = a / 5 -> 10
// cout << a << endl ;

// // Relational Operators 

// int a = 4 ;
// int b = 4 ;

// cout << (a > b) << endl ; // false -> 0
// cout << (a >= b) << endl ; // True -> 1
// cout << (a < b) << endl ; // false -> 0
// cout << (a <= b) << endl ; // True -> 1
// cout << (a == b) << endl ; // True -> 1
// cout << (a != b) << endl ; // false -> 0


// // Logical Operators

// cout << ((3 < 5 ) && (4 > 5)) << endl ;

// // Conditional Statement

// // If - else

// // Voting age

// int age ;
// cout << "Enter your age : " ;
// cin >> age ;

// if (age >= 35) {
//     cout << "Contest for election" << endl ;
// }
// if (age >= 18) {
//     cout << "Can Vote" << endl ;
// }

// // Marks And Grade System

// int marks ;

// cout << "Enter your marks : " ;
// cin >> marks ;

// if (marks <= 100 && marks >= 90) {
//     cout << "Pass"
//          << "\nGrade : A+"
//          << endl ;
// }
// else if (marks < 90 && marks >= 80) {
//     cout << "Pass"
//          << "\nGrade : A"
//          << endl ;
// }
// else if (marks < 80 && marks >= 70) {
//     cout << "Pass"
//          << "\nGrade : B+"
//          << endl ;
// }
// else if (marks < 70 && marks >= 60) {
//     cout << "Pass"
//          << "\nGrade : B"
//          << endl ;
// }
// else if (marks < 60 && marks >= 50) {
//     cout << "Pass"
//          << "\nGrade : C"
//          << endl ;
// }
// else if (marks < 50 && marks >= 33) {
//     cout << "Pass"
//          << "\nGrade : D"
//          << endl ;
// } else {
//     cout << "Fail" << endl ;
// }

// // Switch Statement

// int day ;

// cout << "Enter the day(number) : " ;
// cin >> day ;

// switch (day) {

//     case 1 : cout << "Monday" << endl ;
//             break ;
//     case 2 : cout << "Tuesday" << endl ;
//             break ;
//     case 3 : cout << "Wednesday" << endl ;
//             break ;
//     case 4 : cout << "Thursday" << endl ;
//             break ;
//     case 5 : cout << "Friday" << endl ;
//             break ;
//     case 6 : cout << "Saturday" << endl ;
//             break ;
//     case 7 : cout << "Sunday" << endl ;
//             break ;
    
//     default : cout << "Invalid Day" << endl ;

// }

// // Loops

// // For Loops

// // Print number from 1 to n
// int n ,i ; 
// cout << "Enter the number : " ;
// cin >> n ;

// for ( i = 1 ; i <= n ; i++ ) {
//     cout << i << " " ;
// }

//     cout << endl; 
//     cout << "The last value of num = " << i << endl ;


// // Print your name 5 times
    
// string name ;
// cout << "What is your Name : " ; 
// cin >> name ;

// for (int i = 0 ; i <= 4 ; i++) {
//     cout << name << endl ;
// }

// // Print sum of first a natural number

// int a , sum ; 

// cout << "Enter the number : " ;
// cin >> a ; 

// sum = 0 ; 
// for (int i = 0 ; i <= a ; i ++) {
//     sum += i ;
// }
// cout << "the sum of " 
//      << a 
//      << " natural number is : " 
//      << sum 
//      << endl ;

// // While loop

// int i = 1 ;  // intialization
// while (i <= 5) {  // condition check
//     cout << i << " " ;
//     i++ ;   // increment
// }
// cout << endl ;

// // Do-while loop

// int n = 1 ;

// do {
//     cout << n << " ";
//     n ++ ;
// } while (n <= 5) ;

// // Break in loop

// int i = 1 ;

// while(i <= 10) {
   
//     cout << i << endl ;
    
//     i++ ;
//      if (i == 5){
//         break;
//     }
// }
// cout << "out of loop now " << endl ;

// // Continue Statement

// for (int i = 1 ; i <= 10 ; i++) {
//     if(i == 4) {
//         continue;
//     }
//     cout << i << endl; 
// }

// Nested loop

// Pattern

// 1 1 1 1 
// 2 2 2 2
// 3 3 3 3 
// 4 4 4 4

// int n ; 
// cout << "Enter the number : " ;
// cin >> n ;

// // Outer loop
// for (int i = 1 ; i <= n ; i++) {
//     // Inner loop 
//     for (int j = 1 ; j <= n ; j++) {
//         //work
//         cout << i << " " ;
//     }
//     cout << endl ;
// }

// // Function

// sayHello () ; // Function call

// assistant () ;

// // Forward Declaration

// cout << MyName() << endl ;

// // Parameters

// cout << sum(2,4) << endl ;  // 2,4 are argument

// // Function Overloading
// cout << sum (4 , 5) << endl ;
// cout << sum (4.5 , 5.7) << endl ;
// cout << sum (4 , 5 , 9) << endl ;

// // Binary number system

// // Binary to Decimal conversion
// BinToDec (1111) ;

// // Decimal to Binary conversion
// DecToBin (155555LL) ;

// // Pointer

// // Address Of (&) operator

// int t = 32 ;
// int *ptr = &t ;
// cout << &t << " = " << ptr << endl ;

// float a = 3.3214 ;
// float *ptr2 = &a ;
// cout << &a << " = " << ptr2 << endl ;

// cout << sizeof(ptr) << endl ;
// cout << sizeof(ptr2) << endl ;
// cout << &ptr << "\n" << &ptr2 << endl ;

// int **pptr = &ptr ;
// cout << &ptr << " = " << pptr << endl ;

// int ***ppptr = &pptr ;
// cout << &pptr << " = " << ppptr << endl ;

// // Dereference operater

// cout << &t << " = " << *(&t) << "\n" 
//      << &ptr << " = " << *(&ptr) << "\n"
//      << &pptr << " = " << *(&pptr) << endl ;

// cout << ***ppptr << endl ;  // ***pptr = 32  it reach to the file destination

// *ptr = 23 ;
// cout << t << endl ; 

// **pptr = 89 ;
// cout << t << endl ; 

// // Null pointer

// int *eptr ;
// cout << eptr << "\n" ;  // it will give a garbage value

// int *nptr = nullptr ; // it will give a null pointer value
// int *nptr2 = 0 ; // it will give a null pointer value
// int *nptr3 = NULL ; // it will give a null pointer value
// cout << nptr << "\n" ; // 0x0
// cout << nptr2 << "\n" ; // 0x0
// cout << nptr3 << "\n" ; // 0x0

// cout << *nptr << endl ; // Segmentation fault

// // Passing Arguments

// int a = 10 ; 
// changeA(a) ; // Pass by value
// cout << a << endl ;

// // pass by reference

// int b = 30 ;
// changeB(&b) ;
// cout << b << endl ;

// // Reference variable

// int x = 32 ;
// int &y = x ; // y and x are the same mean y and x repersent same memory location
// y = 222 ;
// x = 43 ;
// cout << x << "\n"
//      << y << endl ;

// changeX(x) ;

// cout << x << endl ;




    return 0;
    
}































































































































































































































































































































// string MyName() {
//     return "Vikas Yadav" ;

// }