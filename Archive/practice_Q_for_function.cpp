#include <iostream>

using namespace std;

int product(int a , int b = 1) {
    return a * b ;
}

string IsEven(int a ) {
    if (a % 2 == 0) {
        return "Even" ;
    }

    return "Odd" ;
}

int factorial(int a ) {

int fact = 1 ;

    for (int i = 2 ; i <= a ; i++) {
        fact *= i ;
    }
    // cout << "factorial(" << a << ") = " << fact << endl ;
    return fact ;
}

string IsPrime (int a) {
    // for (int i = 2 ; i < a ; i++) {
    // OR
    for (int i = 2 ; i*i < a ; i++) {
        if (a % i == 0) {
            return "Non Prime" ;
        }
    }
    return "Prime" ; 
}

void allprime (int n) {
    for (int i = 2 ; i < n ; i++) {
        if (IsPrime(i) == "Prime") {
            cout << i << " " ;
        }
    }
    cout << endl ;
}

float Binomial (int n , int r) {
    int val1 = factorial(n) ;
    int val2 = factorial(r) ;
    int val3 = factorial(n-r) ; 

    float result = val1 / (val2 * val3) ;

    return result ;
}

string Ispalindrome (int n) {
    int val = 0 ;
    int original = n ;
    while (n > 0) {
        int digit = n % 10 ;
        val = val * 10 + digit ;
        n /= 10 ; 
    }
    if (val == original) {
        return "Palindrome" ;
    }
    return "Not a Palindrome" ;
}

int sumdigit(int a) {
    int value = 0 ;
    while (a > 0) {
        int digit = a % 10 ;
        value += digit ;
        a /= 10 ;
    }
    return value ;
}

int SumSquare (int a , int b) {
    return (a*a) + (b*b) + (2*a*b) ;
}

int largerNum(int a , int b , int c) {
    if ( a > b && a > c) {
        return a ;
    } else if (b > c) {
        return b ;
    }
    return c ;
}

char NextChar (char a) {
    if (a == 'z') {
        return 'a' ;
    } else if (a == 'Z') {
        return 'A' ;
    }

    a += 1 ;
    return a ;
}

int main()
{

// WAP to find the product of 2 number - a & b.

cout << product(2,10) << endl ;


// WAP to print if a number is odd or even .

cout << IsEven(2) << endl ;


// WAP to print the factorial of a number n.

cout << factorial(5) << endl ;


// WAP to print if a number is prime or not .

cout << IsPrime (33) << endl ; 


// WAP to find the binomial coefficient for given n & r.

cout << Binomial (10 , 4) << endl ;


// Print all primes in a Range from 2 to n.

allprime (100) ;


// Write a function to check if a number is a palindrome. 
// A number is called a palindrome if the number is equal to the reverse of a number.

cout << Ispalindrome(22121212) << endl ;


// Write a function to calculate the sum of digits of a number.

cout << sumdigit(93332) << endl ;


// Write a function which takes 2 numbers as parameters (a & b) and 
// outputs : a^2 + b^2 + 2*ab.

cout << SumSquare(2,6) << endl ;


// Write a function that prints the largest of 3 numbers.

cout << largerNum(200 , 200 , 6) << endl ; 


// Write a function that accepts a character (ch) as parameters & returns 
// the character that occurs after ch in the English alphabet.
// Eg : input = ‘c’, return value = ‘d’
// Note : for ch = ‘z’, return ‘a’.

cout << NextChar ('Z') << endl ;


}