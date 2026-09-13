#include <iostream>
#include <cmath>  // to use square root

using namespace std ;

int main()
{
// Print the Square pattern using for loop.
//         ****
//         ****
//         ****
//         ****

    for(int i = 1 ; i <= 4 ; i++) {
        cout << "****" << endl ;

    }


// Print numbers from n to 1 using for loop.

    int n ;
    cout << "Enter the number : " ;
    cin >> n ;

    for (int i = n ; i >= 1 ; i --) {
        cout << i << " " ;
    }

// Print the sum of digits of a number using while loop.

    int n ;
    cout << "Enter the number : " ;
    cin >> n ;

    int sum = 0 ; 
    int i = n ; 
    while (i > 0) {
        int digit = i % 10 ;
        sum += digit ;
        i /= 10 ;
    }
    cout << "the sum of digits of " 
         << n 
         << " is : " 
         << sum 
         << endl ;


// Print the sum of odd digits of a number using while loop.

    int n ;
    cout << "Enter the number : " ;
    cin >> n ;
    int sum = 0 ;
    int i = n ;
    while (i > 0) {
        int digit = i % 10 ;
            if (digit % 2 != 0) {
                sum += digit ;
            }
        i /=10 ;
    }

    cout << "The sum of odd digit of "
         << n 
         << " is : "
         << sum 
         << endl ;

// Print the digits of a given number in reverse using while loop.

    int n ;
    cout << "Enter the number : " ;
    cin >> n ;

    int i = n ; 
    while (i > 0) {
        int lastdigit = i % 10 ;

        cout << lastdigit ;

        i /= 10 ;
    }

// Reverse a given number & print the result.

int n ;
    cout << "Enter the number : " ;
    cin >> n ;
int rev = 0 ;
    int i = n ; 
    while (i > 0) {
        int lastdigit = i % 10 ;
        rev = rev * 10 + lastdigit ;

        i /= 10 ;
    }
    cout << "Reverse No : "
         << rev 
         << endl ;

// WAP where user can keep entering numbers till they enter a multiple of 10.

int n ;
do {
    cout << "Enter the number : " ;
    cin >> n ;
} while (n % 10 != 0) ;


// WAP to show numbers entered by user except multiples of 10.

int n ;
do {
    cout << "Enter the number : " ;
    cin >> n ;
    if (n % 10 == 0){
        continue;
    }
    cout << "Good" << endl; 
} while (true) ;


// Check if a number is prime or not .

int n ;
cout << "Enter the number : " ; 
cin >> n ; 

bool isPrime = true ;

for (int i = 2 ; i < n ; i++) {
    if (n % i == 0) {  // i is a factor of n 
        isPrime = false ;
        break ;
    }
}

if ( isPrime) {  // By default isPrime == true
    cout << "This is a Prime number" << endl ;
} else {
    cout << "This is a Composite number" << endl ;
}

// More optimize way

int n ;
cout << "Enter the number : " ; 
cin >> n ; 

bool isPrime = true ;

for (int i = 2 ; i < sqrt(n) ; i++) {
    if (n % i == 0) {  // i is a factor of n 
        isPrime = false ;
        break ;
    }
}

if ( isPrime) {  // By default isPrime == true
    cout << "This is a Prime number" << endl ;
} else {
    cout << "This is a Composite number" << endl ;
}

// Question 1 : WAP to find the Factorial of a number entered by the user.
// factorial of 0! = 1, 1! = 1, 2! = 2, 3! = 6, 4! = 24 and so on.

int n ; 
cout << "Enter the number : " ;
cin >> n ;
int product = 1 ;
for (int i = 1 ; i <= n ; i++) {
    if (n == 0) {
        product = 1 ;
        break ;
    }
    product = product * i ;
}

cout << "The factorial of "
     << n
     << " is : "
     << product
     << endl ;

// Question 2 : WAP to print the multiplication table of a number, entered by the user.

int n ; 
cout << "Enter the number : " ;
cin >> n ;

int i = 1 ;
while (i <= 10) {
    cout << n << " * " << i << " = " << n*i << endl ;
    i++ ;
}

// Question 3 : WAP to input a number and check whether the number is an Armstrong
// number or not.
// An Armstrong number is a number that is equal to the sum of cubes of its digits.

int armstrong ;
cout << "Enter the number : " ;
cin >> armstrong ;
int i = armstrong ;
int sum = 0 ;
while (i > 0) {
    int digit = i % 10 ; 
    sum = sum + digit * digit * digit ;
    i /= 10 ;
}

if (armstrong == sum) {
    cout << "This is a Armstrong Number" << endl ;
} else {
    cout << "This is a Not Armstrong Number" << endl ;
}

// Question 4 : For a positive N , WAP that prints all the prime numbers from 2 to N.
// (Assume N >= 2)

int n ;
std::cout << "Enter the number : " ;
std::cin >> n ;

for (int i = 2 ; i <= n ; i++) {

    int curr = i ;  // current number for check . just to replicat that number
    bool isPrime = true ;

    for (int j = 2 ; j < i ; j++ ) {
        if (i % j == 0) {
            isPrime = false ;
            break ;  // stop checking
        }
    }
        if (isPrime) {
            std::cout << curr << " " ;
    }
}

// Note: We can all use this  j * j <= i is used in Prime Checking
// for (int j = 2; j * j <= i; j++)
// To check whether i is prime, we only need to check divisors up to √i.
// If i has a factor greater than √i, it must have a corresponding factor smaller than √i.
// Therefore, checking beyond √i is unnecessary.
// j * j <= i is equivalent to j <= √i, but avoids explicitly calculating the square root.

// Example:

// i = 36
// √36 = 6

// So we only check:

// 2, 3, 4, 5, 6

// No need to check 7 to 35.

// Benefit: It makes the prime-checking loop significantly more efficient.


// Question 5 : For a positive N , WAP that prints the first N Fibonacci numbers.
// (Assume N >= 2)
// Fibonacci series : 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ….
// This is a series where each number is a sum of previous 2 numbers in the series.

int n ;
std::cout << "Enter the number : " ;
std::cin >> n ;

int first = 0 ;
int sec = 1 ;

std::cout << "The first " << n << " Fibonacci numbers are : " ;

for (int i = 1 ; i <= n ; i++) {
    if (i == 1) {
        std::cout << first << " " ;
    } else if (i == 2) {
        std::cout << sec << " " ;
    } else {
        int next = first + sec ;
        std::cout << next << " " ;
        first = sec ;
        sec = next ;
    }
}

std::cout << std::endl ;

// Or this is the second way

int n ;
std::cout << "Enter the number : " ;
std::cin >> n ;

int first = 0, sec = 1;
std::cout << first << " " << sec << " ";
for(int i=2; i<n; i++) {
int third = first + sec;
std::cout << third << " ";
first = sec;
sec = third;
}
std::cout << "\n";

return 0;

}