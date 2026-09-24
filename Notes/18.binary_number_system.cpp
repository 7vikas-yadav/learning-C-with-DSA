#include <iostream>
#include <iomanip>
using namespace std;

/*
======================================================================
        BINARY NUMBER SYSTEM + DATA TYPE MODIFIERS IN C++
======================================================================


======================================================================
1. NUMBER SYSTEM
======================================================================

A Number System is a way to represent numbers using a set of digits.

Common Number Systems:

1. Decimal      -> Base 10
2. Binary       -> Base 2
3. Octal        -> Base 8
4. Hexadecimal  -> Base 16


-------------------- DECIMAL --------------------

Base = 10

Digits:
0 1 2 3 4 5 6 7 8 9

Example:
245

= 2*10^2 + 4*10^1 + 5*10^0
= 200 + 40 + 5
= 245


-------------------- BINARY --------------------

Base = 2

Digits:
0 and 1

Example:
1011

From right to left, powers of 2 are:

1   0   1   1
|   |   |   |
2^3 2^2 2^1 2^0

= 1*8 + 0*4 + 1*2 + 1*1
= 8 + 0 + 2 + 1
= 11


So:

Binary 1011 = Decimal 11


-------------------- OCTAL --------------------

Base = 8

Digits:
0 1 2 3 4 5 6 7

C++ octal literal starts with:

0

Example:
int x = 012;

012 (octal) = 10 (decimal)


-------------------- HEXADECIMAL --------------------

Base = 16

Digits:

0 1 2 3 4 5 6 7 8 9 A B C D E F

Here:

A = 10
B = 11
C = 12
D = 13
E = 14
F = 15

C++ hexadecimal literal starts with:

0x or 0X

Example:

int x = 0xFF;

FF = 15*16 + 15
   = 255


======================================================================
2. C++ NUMBER SYSTEM LITERALS
======================================================================

C++ allows us to write integer values in different number systems.

Decimal:
int a = 25;

Binary:
int b = 0b11001;

Octal:
int c = 031;

Hexadecimal:
int d = 0x19;


All four represent the same decimal value:

25


Important:

0b  -> Binary
0   -> Octal
0x  -> Hexadecimal


Example:

0b1010 = 10 decimal

012 = 10 decimal

0xA = 10 decimal


======================================================================
3. BINARY TO DECIMAL CONVERSION
======================================================================

Example:

Binary = 1101

Write powers of 2:

 1   1   0   1
 |   |   |   |
2^3 2^2 2^1 2^0

= 1*8 + 1*4 + 0*2 + 1*1
= 8 + 4 + 0 + 1
= 13

Therefore:

1101(binary) = 13(decimal)


Quick method:

For every binary digit:

digit * 2^position

Position starts from 0 on the RIGHT side.


======================================================================
4. DECIMAL TO BINARY
======================================================================

To convert Decimal -> Binary:

Repeatedly divide the number by 2
and record the remainders.

Example:

13 / 2 = 6 remainder 1
 6 / 2 = 3 remainder 0
 3 / 2 = 1 remainder 1
 1 / 2 = 0 remainder 1

Read remainders from BOTTOM to TOP:

1101

Therefore:

13(decimal) = 1101(binary)


======================================================================
5. WHY BINARY IS IMPORTANT IN COMPUTERS
======================================================================

Computers work with electrical/electronic states.

Conceptually:

0 -> OFF / LOW
1 -> ON  / HIGH

Therefore computers internally represent data using
bits (Binary Digits).


======================================================================
6. BIT
======================================================================

Bit = Binary Digit

A bit can store only:

0 or 1

Example:

10110101

This contains 8 bits.


======================================================================
7. BYTE
======================================================================

1 Byte = 8 bits

Example:

10110101 = 8 bits = 1 byte


Important:

8 bits can represent:

2^8 = 256 different combinations

For unsigned 8-bit value:

0 to 255


======================================================================
8. DATA TYPE MODIFIERS
======================================================================

Data type modifiers change the properties of a data type.

Main modifiers:

1. signed
2. unsigned
3. short
4. long
5. long long


They are mainly used with integer data types.


======================================================================
9. signed
======================================================================

By default, integer types are generally signed.

signed means the variable can store:

Negative values
Zero
Positive values

Example:

signed int x = -100;


For a typical 32-bit int:

Range:

-2,147,483,648
to
 2,147,483,647


IMPORTANT:

Exact size/range of some C++ types is implementation-dependent.

Use sizeof() and <limits> when you need to know the actual
implementation's limits.


======================================================================
10. unsigned
======================================================================

unsigned means the type does NOT represent negative values.

It uses its available bits for:

0 and positive values.


Example:

unsigned int age = 20;


Typical 32-bit unsigned int range:

0
to
4,294,967,295


Because:

2^32 = 4,294,967,296 possible values

So range is:

0 to 2^32 - 1


IMPORTANT:

Do NOT use unsigned simply because a value "looks positive".
Unsigned arithmetic has special rules, especially when mixing
signed and unsigned values.


======================================================================
11. short
======================================================================

short is an integer type that generally uses less storage than
a standard int when the implementation provides that difference.

Example:

short int x = 100;

We can also write:

short x = 100;


Minimum guaranteed range for short:

-32,767 to 32,767


Typical size:

2 bytes


But remember:

sizeof(short) is implementation-dependent.


======================================================================
12. long
======================================================================

long is an integer type that can provide a larger range than int
on implementations where long is larger.

Example:

long population = 1000000L;


Minimum guaranteed range for signed long:

-2,147,483,647 to
 2,147,483,647


IMPORTANT:

The size of long depends on the platform.

For example:

Windows 64-bit:
long is commonly 4 bytes

Many Unix/Linux 64-bit systems:
long is commonly 8 bytes


So NEVER assume long is always 8 bytes.


======================================================================
13. long long
======================================================================

long long provides at least 64 bits of integer storage.

Example:

long long population = 9000000000LL;


Minimum guaranteed range:

-9,223,372,036,854,775,807
to
 9,223,372,036,854,775,807


Typical size:

8 bytes


The suffix:

LL

can be used to explicitly indicate a long long integer literal.


======================================================================
14. DATA TYPE MODIFIER COMBINATIONS
======================================================================

Common combinations:

short
short int

signed int
unsigned int

long
long int

unsigned long

long long
long long int

unsigned long long


Examples:

short a = 10;

unsigned int b = 20;

long c = 100000L;

long long d = 10000000000LL;

unsigned long long e = 10000000000ULL;

======================================================================
15. MODIFIERS WITH char
======================================================================

char is an integer type in C++.

Therefore we can have:

signed char
unsigned char


Example:

signed char a = -100;

unsigned char b = 200;


IMPORTANT:

Plain char is a separate type whose signedness is
implementation-defined.

So:

char

may behave like:

signed char

or:

unsigned char

depending on the implementation.


======================================================================
17. long WITH double
======================================================================

long can also be used with double:

long double

Example:

long double value = 3.141592653589793238L;


long double is a floating-point type.

It may provide more precision/range than double,
but its exact size and precision are implementation-dependent.


======================================================================
18. sizeof() WITH MODIFIED DATA TYPES
======================================================================

sizeof() tells us the size of a type/object in bytes.

Example:

sizeof(int)

sizeof(long)

sizeof(long long)

sizeof(unsigned int)

IMPORTANT:

The size is implementation-dependent.

So instead of memorizing only one machine's sizes,
you should understand the relative purpose and verify with
sizeof() when needed.


======================================================================
20. INTEGER LITERAL SUFFIXES
======================================================================

A literal is a fixed value written directly in the source code.

Examples:

10
3.14
'A'
"Hello"


A Literal Suffix is a letter/combination of letters written after
a literal to tell the compiler what type the literal should have.

Example:

100L

Here:

100  -> value
L    -> suffix

L tells the compiler that 100 is a long integer literal.


======================================================================
1. INTEGER LITERAL SUFFIXES
======================================================================

Common integer suffixes:

U    -> unsigned
L    -> long
LL   -> long long

They can also be combined:

UL   -> unsigned long
ULL  -> unsigned long long


Examples:

100U

100L

100LL

100UL

100ULL

======================================================================
2. WHY DO WE NEED LITERAL SUFFIXES?
======================================================================

The compiler has to determine the type of a literal.

For example:

100

is an integer literal.

But when we write:

100LL

we explicitly indicate:

"Treat this as a long long integer literal."


This becomes especially useful for large integer constants.


======================================================================
3. FLOATING-POINT LITERAL SUFFIXES
======================================================================

Floating-point literals have different suffixes.

f / F  -> float
l / L  -> long double


Examples:

3.14f

3.14F

3.14L


Without a suffix:

3.14

is normally a double literal.


Therefore:

float a = 3.14f;

double b = 3.14;

long double c = 3.14L;


IMPORTANT:

For floating-point literals:

3.14   -> double
3.14f  -> float
3.14L  -> long double


======================================================================
4. CHARACTER LITERALS
======================================================================

Character literals can also have prefixes/special forms, but these
are different from the integer/floating literal suffixes discussed
above.

Example:

'A'

'A' is a character literal.

It is of type char.


======================================================================
5. STRING LITERALS
======================================================================

Example:

"Hello"

This is a string literal.

String literals can have prefixes such as:

L"Hello"
u"Hello"
U"Hello"
u8"Hello"

These indicate different character/string types or encodings.

They are prefixes, not the integer/floating suffixes discussed above.

======================================================================
6. PRACTICAL EXAMPLE
======================================================================
*/

int main()
{
    // Integer literals

    int a = 100;

    unsigned int b = 100U;

    long c = 1000000L;

    long long d = 9000000000LL;

    unsigned long e = 100000UL;

    unsigned long long f = 10000000000ULL;


    // Floating-point literals

    float x = 3.14f;

    double y = 3.14;

    long double z = 3.14L;


    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;


/*
======================================================================
21. INTEGER OVERFLOW
======================================================================

When a value goes outside the range of a signed integer type,
the result is not something you should rely on; signed integer
overflow is undefined behavior in C++.

Example:

int x = 2147483647;

x = x + 1;

This exceeds the typical signed 32-bit int range.

Therefore, always choose an appropriate type and range.


IMPORTANT:

Unsigned integer arithmetic wraps modulo 2^N for an N-bit type.

Example for an 8-bit unsigned value:

255 + 1 -> 0


======================================================================
22. BINARY REPRESENTATION AND BITS
======================================================================

For an N-bit unsigned integer:

Number of possible values = 2^N

For 8 bits:

2^8 = 256 values

Range:

0 to 255


For 16 bits:

2^16 = 65,536 values

Range:

0 to 65,535


For 32 bits:

2^32 = 4,294,967,296 values

Range:

0 to 4,294,967,295


For 64 bits:

2^64 possible values


======================================================================
23. SIGNED INTEGER AND TWO'S COMPLEMENT
======================================================================

Modern C++ implementations commonly use two's complement
representation for signed integers.

For an N-bit two's-complement signed integer:

Minimum = -2^(N-1)
Maximum =  2^(N-1) - 1

For 8 bits:

Minimum = -128
Maximum = 127


Example:

8-bit:

00000001 = +1

11111111 represents -1 in two's complement.


NOTE:

This is useful for understanding binary representation,
but do not confuse the mathematical representation with
the C++ rules governing signed overflow.


======================================================================
24. PRACTICAL EXAMPLES
======================================================================
*/

    // ==========================================================
    // BINARY NUMBER SYSTEM
    // ==========================================================

    int decimal = 13;

    // 0b means binary
    int binary = 0b1101;

    // 0 means octal
    int octal = 015;

    // 0x means hexadecimal
    int hexadecimal = 0xD;

    cout << "Decimal      : " << decimal << endl;
    cout << "Binary value : " << binary << endl;
    cout << "Octal value  : " << octal << endl;
    cout << "Hex value    : " << hexadecimal << endl;


    // ==========================================================
    // DATA TYPE MODIFIERS
    // ==========================================================

    short shortNumber = 100;

    unsigned int positiveNumber = 4000000000U;

    long long bigNumber = 9000000000LL;

    unsigned long long veryBigPositiveNumber =
        18000000000ULL;

    signed char signedCharacter = -50;

    unsigned char unsignedCharacter = 200;

    long double preciseValue = 3.141592653589793238L;


    cout << "\n--- DATA TYPE MODIFIERS ---\n";

    cout << "short                 : " << shortNumber << endl;
    cout << "unsigned int          : " << positiveNumber << endl;
    cout << "long long             : " << bigNumber << endl;
    cout << "unsigned long long    : "
         << veryBigPositiveNumber << endl;

    cout << "signed char           : "
         << static_cast<int>(signedCharacter) << endl;

    cout << "unsigned char         : "
         << static_cast<int>(unsignedCharacter) << endl;

    cout << "long double           : "
         << setprecision(20) << preciseValue << endl;


    // ==========================================================
    // sizeof()
    // ==========================================================

    cout << "\n--- SIZE OF DATA TYPES ---\n";

    cout << "sizeof(short)              : "
         << sizeof(short) << " bytes" << endl;

    cout << "sizeof(int)                : "
         << sizeof(int) << " bytes" << endl;

    cout << "sizeof(unsigned int)       : "
         << sizeof(unsigned int) << " bytes" << endl;

    cout << "sizeof(long)               : "
         << sizeof(long) << " bytes" << endl;

    cout << "sizeof(long long)          : "
         << sizeof(long long) << " bytes" << endl;

    cout << "sizeof(unsigned long long) : "
         << sizeof(unsigned long long) << " bytes" << endl;

    cout << "sizeof(float)              : "
         << sizeof(float) << " bytes" << endl;

    cout << "sizeof(double)             : "
         << sizeof(double) << " bytes" << endl;

    cout << "sizeof(long double)        : "
         << sizeof(long double) << " bytes" << endl;


    // ==========================================================
    // INTEGER LITERAL SUFFIXES
    // ==========================================================

    unsigned int a = 100U;
    long b = 100000L;
    long long c = 10000000000LL;
    unsigned long long d = 10000000000ULL;

    cout << "\n--- INTEGER LITERAL SUFFIXES ---\n";

    cout << "Unsigned : " << a << endl;
    cout << "Long     : " << b << endl;
    cout << "Long long: " << c << endl;
    cout << "ULL      : " << d << endl;


    // ==========================================================
    // BINARY CALCULATION EXAMPLE
    // ==========================================================

    /*
        10110(binary)

        = 1*2^4 + 0*2^3 + 1*2^2 + 1*2^1 + 0*2^0

        = 16 + 0 + 4 + 2 + 0

        = 22
    */

    int binaryExample = 0b10110;

    cout << "\nBinary 10110 in decimal = "
         << binaryExample << endl;
    
    return 0;
}