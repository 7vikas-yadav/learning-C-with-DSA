#include <iostream>

using namespace std;

void multipleBy2(int &a, int &b, int &c) {
a *= 2;
b *= 2;
c *= 2;
}

int main()
{
// What will ptr2 point to in the following code:

int x = 5, y = 10;
int *ptr1 = &x, *ptr2 = &y;
ptr2 = ptr1;  // ptr2 take the memory address of ptr1 so both represnt x

cout << ptr1 << endl ;  
cout << ptr2 << endl ;
cout << &x << endl ;


// What is the type of a & b :
float* x, y; // Here x is a float pointer and y is a normal float variable


// Can we initialize a pointer with value 0 ?

int *nptr = nullptr;
int *ptr = NULL ;
int *vptr = 0 ;

cout << vptr << endl ;


// What will be the output of the following code :

int x; // declare an integer variable x

int *ptr; // declare a pointer variable ptr that can point to an integer

x = 7; // assign the value 7 to x

ptr = &x; // assign the address of x to ptr

cout << *ptr;
// the output will be 7 because ptr is pointing to the address of x and *ptr 
// dereferences that address to get the value of x which is 7.
    

// What will be the output of the following code :

// void multipleBy2(int &a, int &b, int &c) {
// a *= 2;
// b *= 2;
// c *= 2;
// }

int x =1, y =2,  z =3;
multipleBy2(x, y, z);
cout << x << y << z << "\n"; 
// the output will be 246 because the function multipleBy2 takes references 
// to the variables x, y, and z, and multiplies their values by 2. 
// So x becomes 2, y becomes 4, and z becomes 6.


// What will be the output of the following code :

int a = 32;
int *ptr = &a; 
// ptr is a pointer to an integer, and it is initialized to point to the address of the variable a.

char ch = 'A';
char &cho = ch;
// cho is a reference to the variable ch, which means that cho and ch refer to the same memory location.

cho += a; 
// cho is incremented by the value of a, which is 32.
// Since cho is a reference to ch, this operation modifies the value of ch as well.
// The ASCII value of 'A' is 65, so adding 32 to it results in 97, which corresponds to the character 'a'.

*ptr += ch;
// The value pointed to by ptr (which is a) is incremented by the value of ch (which is now 'a', or 97).
// So a becomes 32 + 97 = 129.

cout << a << " , " << ch << endl;
// a is now 129, and ch is 'a'.

    return 0;

}