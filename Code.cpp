#include <iostream>

#include <iomanip>

using namespace std;

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


    return 0;
    
}