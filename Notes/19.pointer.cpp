#include <iostream>
using namespace std;

/*
======================================================================
                            POINTERS 
======================================================================

======================================================================
1. BASIC MEMORY CONCEPTS
======================================================================

When a program runs, variables are stored in the computer's memory.

Example:

int age = 20;

The value 20 is stored somewhere in memory.

We can think of memory like a large collection of storage locations.

Each memory location has:

    1. Address
    2. Value


For example, conceptually:

Address          Value
--------         -----
1000             20
1004             50
1008             100

The actual addresses are decided by the operating system/compiler
and may be different every time the program runs.


IMPORTANT:

Variable:
    Name given to a memory location.

Value:
    Data stored in that memory location.

Address:
    Location of that memory in RAM.


Example:

int age = 20;

age      -> variable/name
20       -> value
&age     -> address of age


======================================================================
2. MEMORY ADDRESS
======================================================================

Every object stored in memory has an address.

We can get the address of a variable using:

    &

This is called the:

    Address-of operator


Example:

int age = 20;

cout << &age;


This prints the memory address of age.

The exact address will be different on different systems/runs.


======================================================================
3. ADDRESS-OF OPERATOR (&)
======================================================================

The & operator can be used to get the address of a variable.

Syntax:

    &variable;


Example:

int x = 10;

cout << &x;


Meaning:

&x

means:

"Give me the memory address of x."


IMPORTANT:

Here & is the ADDRESS-OF operator.

It is different from the reference syntax discussed later.


======================================================================
4. POINTER
======================================================================

A pointer is a variable that stores the address of another variable.

Example:

int age = 20;

int* ptr = &age;


Here:

age
    -> normal integer variable

&age
    -> address of age

ptr
    -> pointer variable storing the address of age


Visual representation:

    age
   +------+
   |  20  |
   +------+
      |
      | address
      v
   ptr
   +------+
   | &age |
   +------+


IMPORTANT:

A pointer stores an ADDRESS, not the actual value directly.


======================================================================
5. POINTER DECLARATION
======================================================================

Syntax:

    dataType* pointerName;


Examples:

int* ptr;

float* ptr;

char* ptr;

double* ptr;


The pointer's type tells C++ what type of object it points to.

Example:

int* ptr;

means:

ptr is a pointer to an int.


Another valid style:

int *ptr;


Both mean the same thing.

Commonly written:

int *ptr;


======================================================================
6. INITIALIZING A POINTER
======================================================================

Example:

int age = 20;

int *ptr = &age;


Now:

age  = 20

ptr  = address of age

*ptr = value stored at that address = 20


======================================================================
7. DEREFERENCE OPERATOR (*)
======================================================================

The * operator is called the:

    Dereference operator

when it is used with a pointer to access the value stored at
the address held by that pointer.


Example:

int age = 20;

int *ptr = &age;

cout << *ptr;


Output:

20


Why?

ptr  -> stores address of age

*ptr -> goes to that address and gets the value


So:

ptr
    = address

*ptr
    = value at that address


======================================================================
8. & AND * ARE OPPOSITES
======================================================================

Consider:

int x = 10;

int* ptr = &x;


&x

means:

    address of x


ptr

contains:

    address of x


*ptr

means:

    value at that address


Therefore:

    &  -> get address

    *  -> get value from address


Think:

    x      -> value
    &x     -> address
    ptr    -> address stored in pointer
    *ptr   -> value at that address


======================================================================
9. MODIFYING A VALUE THROUGH A POINTER
======================================================================

A pointer can be used to modify the original variable.

Example:

int x = 10;

int* ptr = &x;

*ptr = 50;


Now:

x = 50


Why?

*ptr refers to the same memory location as x.


Visual:

        x
     +------+
     |  10  |
     +------+
        ^
        |
       ptr

After:

*ptr = 50;

     +------+
     |  50  |
     +------+


======================================================================
10. NULL POINTER
======================================================================

A null pointer is a pointer that does not point to a valid object.

Modern C++ uses:

    nullptr


Example:

int* ptr = nullptr;


This means:

ptr currently points to no object.


IMPORTANT:

Use:

    nullptr

instead of the old:

    NULL

or:

    0


nullptr was introduced in C++11 and is the preferred way.


======================================================================
11. WHY USE nullptr?
======================================================================

Sometimes we don't have an address to store yet.

Example:

int* ptr = nullptr;


Later:

int x = 100;

ptr = &x;


Now ptr points to x.


We can also check:

if (ptr != nullptr)
{
    cout << *ptr;
}


This prevents dereferencing a null pointer.


======================================================================
12. DEREFERENCING nullptr
======================================================================

This is WRONG:

int* ptr = nullptr;

cout << *ptr;


Why?

ptr does not point to a valid object.

There is no valid object whose value can be accessed.


Dereferencing an invalid pointer can cause undefined behavior.


======================================================================
13. SEGMENTATION FAULT
======================================================================

A segmentation fault occurs when a program tries to access memory
in a way that is not permitted.

For example:

int* ptr = nullptr;

cout << *ptr;


The exact behavior is undefined in C++, and on many systems this
results in a segmentation fault or similar access-violation error.


IMPORTANT:

"Segmentation fault" is a common operating-system-level description.

In C++, the underlying code may have:

    Undefined behavior


Other examples of dangerous memory access include:

- Dereferencing nullptr
- Using an invalid/dangling pointer
- Accessing memory outside an object's valid bounds


======================================================================
                    DANGLING POINTER
======================================================================

A dangling pointer is a pointer that points to a memory location
whose lifetime has ended or which has already been deallocated.

Example:
int *p = new int(10);

delete p;       // Memory is released
p = nullptr;   // Good practice: avoid dangling pointer

If we use *p before setting it to nullptr after delete,
it would be a dangling-pointer situation and dereferencing it
causes undefined behavior.


======================================================================
14. PASSING ARGUMENT BY VALUE
======================================================================

When an argument is passed by value, the function receives a copy
of the argument.

Example:

void change(int x)
{
    x = 100;
}


int a = 10;

change(a);


After calling change():

a is still 10.


Why?

The function received a COPY of a.


Visual:

Original:
    a = 10

Function:
    x = 10

Then:

    x = 100

Original a is still:

    a = 10


======================================================================
15. PASSING BY VALUE EXAMPLE
======================================================================
*/

void changeByValue(int x)
{
    x = 100;
}


/*
======================================================================
16. REFERENCE VARIABLE
======================================================================

A reference is another name (alias) for an existing variable.

Syntax:

    dataType& referenceName = variable;


Example:

int x = 10;

int &ref = x;


Now:

x
and
ref

refer to the SAME object.


If we do:

ref = 50;


then:

x = 50


IMPORTANT:

A reference is NOT a separate copy of x.

It is another name for the same object.


Visual:

        +------+
x  ---->|  10  |
ref---->|      |
        +------+


Both x and ref refer to the same object.


======================================================================
17. PASSING BY REFERENCE
======================================================================

A function can receive a reference to the original variable.

Syntax:

void function(int &x)
{
    ...
}


Example:

void changeByReference(int &x)
{
    x = 100;
}


int a = 10;

changeByReference(a);


After function call:

a = 100


Why?

x is a reference to a.

So modifying x modifies the original variable.


======================================================================
18. PASSING BY POINTER
======================================================================

A function can also receive an address using a pointer.

Example:

void changeByPointer(int *x) // x is a pointer to an int
{
    *x = 100;  // Dereference pointer to modify original variable
}


Calling:

int a = 10;

changeByPointer(&a); // Pass the address of a


After the call:

a = 100


Here:

&a
    -> address of a

x
    -> receives that address

*x
    -> accesses a


======================================================================
19. VALUE vs REFERENCE vs POINTER
======================================================================

Suppose:

int a = 10;


------------------ PASS BY VALUE ------------------

void func(int x)

func(a);

x is a COPY.

Changing x does NOT change a.


------------------ PASS BY REFERENCE ------------------

void func(int &x)

func(a);

x is another name for a.

Changing x DOES change a.


------------------ PASS BY POINTER ------------------

void func(int *x)

func(&a);

x stores the address of a.

*x accesses/modifies a.



======================================================================
20. POINTER vs REFERENCE
======================================================================

POINTER:

int* ptr = &x;


- Stores an address
- Can be nullptr
- Can be changed to point to another object
- Use * to dereference
- Can use pointer arithmetic in appropriate contexts


REFERENCE:

int& ref = x;


- Alias for an existing object
- Must be initialized when declared
- Normally cannot be made to refer to a different object later
- Does not use * to access the referred object
- Cannot be a null reference in normal valid C++ code


======================================================================
22. COMPLETE PRACTICAL EXAMPLE
======================================================================
*/

void changeUsingValue(int x)
{
    x = 100;
}


void changeUsingReference(int& x)
{
    x = 200;
}


void changeUsingPointer(int* x)
{
    if (x != nullptr)
    {
        *x = 300;
    }
}


int main()
{
    // ==========================================================
    // BASIC MEMORY + ADDRESS
    // ==========================================================

    int age = 20;

    cout << "Value of age   : " << age << endl;

    cout << "Address of age : " << &age << endl;


    // ==========================================================
    // POINTER
    // ==========================================================

    int* ptr = &age;

    cout << "\nPointer example:\n";

    cout << "Value of ptr   : " << ptr << endl;

    cout << "Value of *ptr  : " << *ptr << endl;


    // ==========================================================
    // MODIFYING THROUGH POINTER
    // ==========================================================

    *ptr = 50;

    cout << "\nAfter *ptr = 50:\n";

    cout << "age = " << age << endl;


    // ==========================================================
    // NULL POINTER
    // ==========================================================

    int* nullPtr = nullptr;

    cout << "\nNull pointer example:\n";

    if (nullPtr == nullptr)
    {
        cout << "nullPtr is not pointing to an object." << endl;
    }


    // ==========================================================
    // PASS BY VALUE
    // ==========================================================

    int a = 10;

    changeUsingValue(a);

    cout << "\nAfter pass by value:\n";
    cout << "a = " << a << endl;
    // a remains 10


    // ==========================================================
    // PASS BY REFERENCE
    // ==========================================================

    changeUsingReference(a);

    cout << "\nAfter pass by reference:\n";
    cout << "a = " << a << endl;
    // a becomes 200


    // ==========================================================
    // PASS BY POINTER
    // ==========================================================

    changeUsingPointer(&a);

    cout << "\nAfter pass by pointer:\n";
    cout << "a = " << a << endl;
    // a becomes 300


    // ==========================================================
    // REFERENCE VARIABLE
    // ==========================================================

    int number = 500;

    int& reference = number;

    reference = 700;

    cout << "\nReference variable example:\n";

    cout << "number    = " << number << endl;
    cout << "reference = " << reference << endl;
    

    return 0;
    
}