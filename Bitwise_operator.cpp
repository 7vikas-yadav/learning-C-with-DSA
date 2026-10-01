#include <iostream>
#include <bitset>

using namespace std;

/*
===============================================================================
                         BITWISE OPERATORS IN C++
===============================================================================

Bitwise operators work directly on the BITS of an integer.

Before understanding bitwise operators, remember:

Binary uses only:

    0 and 1


Example:

Decimal 5

Binary:

00000101

Decimal 3

Binary:

00000011


Bitwise operators compare/manipulate these individual bits.


===============================================================================
1. BITWISE OPERATORS
===============================================================================

C++ provides these main bitwise operators:

    &    Bitwise AND
    |    Bitwise OR
    ^    Bitwise XOR
    ~    Bitwise NOT
    <<   Left Shift
    >>   Right Shift


Quick table:

Operator        Name

&               Bitwise AND
|               Bitwise OR
^               Bitwise XOR
~               Bitwise NOT
<<              Left Shift
>>              Right Shift


IMPORTANT:

These are different from logical operators:

&&    -> Logical AND
||    -> Logical OR
!     -> Logical NOT

Bitwise:

&     -> Bitwise AND
|     -> Bitwise OR
~     -> Bitwise NOT


===============================================================================
2. BINARY REPRESENTATION
===============================================================================

Example:

int a = 5;

Binary representation:

00000101


int b = 3;

Binary:

00000011


We can visualize an integer in binary using:

bitset<8>(a)

For example:

bitset<8>(5)

gives:

00000101


===============================================================================
3. BITWISE AND (&)
===============================================================================

AND works bit-by-bit.

Rules:

    0 & 0 = 0
    0 & 1 = 0
    1 & 0 = 0
    1 & 1 = 1


Truth table:

A   B   A & B

0   0     0
0   1     0
1   0     0
1   1     1


Example:

    5 = 00000101
    3 = 00000011
        --------
    & = 00000001

Therefore:

5 & 3 = 1


IMPORTANT:

AND gives 1 only when BOTH bits are 1.


===============================================================================
4. BITWISE OR (|)
===============================================================================

OR rules:

    0 | 0 = 0
    0 | 1 = 1
    1 | 0 = 1
    1 | 1 = 1


Example:

    5 = 00000101
    3 = 00000011
        --------
    | = 00000111

Therefore:

5 | 3 = 7


IMPORTANT:

OR gives 1 if AT LEAST ONE bit is 1.


===============================================================================
5. BITWISE XOR (^)
===============================================================================

XOR = Exclusive OR

Rules:

    0 ^ 0 = 0
    0 ^ 1 = 1
    1 ^ 0 = 1
    1 ^ 1 = 0


Example:

    5 = 00000101
    3 = 00000011
        --------
    ^ = 00000110

Therefore:

5 ^ 3 = 6


IMPORTANT:

XOR gives 1 when the two bits are DIFFERENT.


Easy memory trick:

Same -> 0
Different -> 1


===============================================================================
6. BITWISE NOT (~)
===============================================================================

NOT flips every bit.

    0 -> 1
    1 -> 0


Example with 8 bits:

5:

00000101

~5:

11111010


IMPORTANT:

For signed integers, the numerical result of ~ depends on the
representation and width of the type. Modern C++ implementations
commonly use two's complement.

For an unsigned N-bit value, ~x flips all N bits and is equivalent
to:

    maximum_value - x

For example, with 8-bit unsigned:

5:

00000101

~5:

11111010

11111010 = 250

So:

~(unsigned char-like 8-bit value 5) -> 250

But be careful with integer promotions in actual C++ expressions.


===============================================================================
7. LEFT SHIFT (<<)
===============================================================================

Left shift moves bits toward the LEFT.

Syntax:

    value << number_of_positions


Example:

5:

00000101

5 << 1:

00001010

Result:

10


So:

5 << 1 = 10


Another example:

5 << 2

00000101
   ↓ shift 2 positions

00010100

Result:

20


For unsigned integers, left shifting by k positions corresponds to
multiplication by 2^k when the shifted value remains representable.


===============================================================================
8. RIGHT SHIFT (>>)
===============================================================================

Right shift moves bits toward the RIGHT.

Example:

20:

00010100

20 >> 1:

00001010

Result:

10


Therefore:

20 >> 1 = 10


For unsigned integers, right shifting by k positions corresponds to
integer division by 2^k, discarding the remainder.


===============================================================================
9. LEFT SHIFT AND MULTIPLICATION
===============================================================================

For suitable unsigned values:

x << 1
    approximately corresponds to:

x * 2


x << 2
    approximately corresponds to:

x * 4


x << 3
    approximately corresponds to:

x * 8


Example:

3 << 2

3 * 4 = 12


IMPORTANT:

Do not blindly use this rule for every signed-integer situation.
Signed shifting has additional rules and possible undefined behavior.


===============================================================================
10. RIGHT SHIFT AND DIVISION
===============================================================================

For unsigned integers:

x >> 1
    corresponds to:

x / 2


x >> 2
    corresponds to:

x / 4


Example:

20 >> 2

20 / 4 = 5


For signed negative values, right-shift behavior is
implementation-defined, so don't rely on unsigned-style reasoning
for negative signed integers.


===============================================================================
11. BITWISE OPERATORS WITH ASSIGNMENT
===============================================================================

Just like:

+=
-=
*=
/=

C++ also provides:

&=
|=
^=
<<=
>>=


Example:

int x = 5;

x &= 3;

means:

x = x & 3;


Example:

int x = 5;

x |= 3;

means:

x = x | 3;


Example:

int x = 5;

x ^= 3;

means:

x = x ^ 3;


===============================================================================
12. BIT MASK
===============================================================================

A bit mask is a value used to select, set, clear, or test particular
bits.

Example:

Suppose:

    x = 10110100

Mask:

    00000100

To check whether a particular bit is set:

    x & mask


This is one of the most important practical uses of bitwise operators.


===============================================================================
13. CHECK WHETHER A NUMBER IS ODD OR EVEN
===============================================================================

The least significant bit (LSB) tells us whether an integer is odd
or even.

Even number:

LSB = 0

Odd number:

LSB = 1


We can check:

    n & 1


If:

    n & 1 == 0

then n is even.


If:

    n & 1 == 1

then n is odd.


Example:

5:

00000101

5 & 1:

00000101
00000001
--------
00000001

Result = 1

Therefore 5 is odd.


Example:

6:

00000110

6 & 1:

00000110
00000001
--------
00000000

Therefore 6 is even.


===============================================================================
14. CHECK A PARTICULAR BIT
===============================================================================

Suppose we want to check the 2nd bit.

Usually we count bits from the RIGHT starting at 0.

Example:

Binary:

10110100

Bit positions:

7 6 5 4 3 2 1 0
1 0 1 1 0 1 0 0


To create a mask for bit position 2:

1 << 2

Binary:

00000100


Then:

n & (1 << 2)


If result is non-zero:

The bit is set (1).


If result is zero:

The bit is clear (0).


===============================================================================
15. SET A BIT
===============================================================================

"Set a bit" means change it to 1.

Formula:

    n = n | (1 << position)


Example:

n:

00000000

Set bit 2:

1 << 2

00000100


OR:

00000000
00000100
--------
00000100


Now bit 2 is 1.


===============================================================================
16. CLEAR A BIT
===============================================================================

"Clear a bit" means change it to 0.

Formula:

    n = n & ~(1 << position)


Example:

n:

00001111

Clear bit 2:

Mask:

00000100

NOT mask:

11111011


AND:

00001111
11111011
--------
00001011


Bit 2 becomes 0.


===============================================================================
17. TOGGLE A BIT
===============================================================================

"Toggle" means:

    0 -> 1
    1 -> 0


Use XOR:

    n = n ^ (1 << position)


Example:

n:

00000100

Toggle bit 2:

00000100
00000100
--------
00000000


Toggle again:

00000000
00000100
--------
00000100


===============================================================================
18. XOR IMPORTANT PROPERTIES
===============================================================================

These properties are very useful.

1.

    x ^ 0 = x


2.

    x ^ x = 0


3.

    x ^ x ^ x = x


4.

XOR is commutative:

    a ^ b = b ^ a


5.

XOR is associative:

    (a ^ b) ^ c
    =
    a ^ (b ^ c)


===============================================================================
19. SWAP TWO NUMBERS USING XOR
===============================================================================

Traditional swap:

int temp = a;
a = b;
b = temp;


There is also an XOR trick:

a = a ^ b;
b = a ^ b;
a = a ^ b;


This can swap integer values without a temporary variable.

However, in normal modern C++ code:

    swap(a, b);

is clearer and preferred.

The XOR technique is mainly useful for understanding bitwise
operations and certain algorithmic problems.


===============================================================================
20. REMOVE THE LOWEST SET BIT
===============================================================================

For an unsigned integer x:

    x = x & (x - 1);


This clears the lowest set bit.

Example:

x:

10110000

x - 1:

10101111

AND:

10110000
10101111
--------
10100000


The lowest 1 has been removed.


This technique is useful in bit manipulation algorithms.


===============================================================================
21. COUNT SET BITS
===============================================================================

A set bit means:

    bit = 1


Example:

101101

Number of set bits = 4


A classic technique:

while (n != 0)
{
    n = n & (n - 1);
    count++;
}


Each iteration removes one set bit.


C++ also provides useful standard-library facilities such as
std::popcount in modern C++.


===============================================================================
22. BITWISE VS LOGICAL OPERATORS
===============================================================================

VERY IMPORTANT DIFFERENCE:


BITWISE:

&

Works on individual bits.


LOGICAL:

&&

Works with logical true/false conditions.


Example:

int a = 5;
int b = 3;


a & b

performs bitwise AND.


a && b

performs logical AND.

Since both 5 and 3 are non-zero:

a && b

produces:

true -> 1


But:

a & b

produces:

1


They happen to produce different/same values in some examples,
but they are completely different operations.


Similarly:

|   -> bitwise OR
||  -> logical OR

~   -> bitwise NOT
!   -> logical NOT


===============================================================================
23. OPERATOR PRECEDENCE
===============================================================================

Bitwise operators have their own precedence levels.

For expressions involving multiple operators, use parentheses
instead of relying on memory.

Example:

if ((x & 1) == 1)
{
    ...
}


This is clearer than:

if (x & 1 == 1)


Always use parentheses when mixing bitwise operators with
comparison/logical operators.


===============================================================================
24. PRACTICAL USES OF BITWISE OPERATORS
===============================================================================

Bitwise operations are commonly used in:

- Low-level programming
- Embedded systems
- Operating systems
- Device drivers
- Networking
- Permission/flag systems
- Compression
- Cryptography-related algorithms
- Competitive programming
- Bit masks
- Hardware control


===============================================================================
25. IMPORTANT LIMITATIONS
===============================================================================

Bitwise operators are intended for integral and enumeration types.

They are NOT used like normal arithmetic operators on:

float
double


For example:

double x = 3.14;

x & 1;       // INVALID


===============================================================================
*/


int main()
{
    // ========================================================================
    // BASIC VALUES
    // ========================================================================

    int a = 5;      // 00000101
    int b = 3;      // 00000011


    cout << "a = " << a << endl;
    cout << "b = " << b << endl;


    // ========================================================================
    // SHOW BINARY REPRESENTATION
    // ========================================================================

    cout << "\n--- BINARY REPRESENTATION ---\n";

    cout << "5 in binary = "
         << bitset<8>(5) << endl;

    cout << "3 in binary = "
         << bitset<8>(3) << endl;


    // ========================================================================
    // BITWISE AND
    // ========================================================================

    cout << "\n--- BITWISE AND ---\n";

    cout << "5 & 3 = "
         << (a & b) << endl;


    // ========================================================================
    // BITWISE OR
    // ========================================================================

    cout << "\n--- BITWISE OR ---\n";

    cout << "5 | 3 = "
         << (a | b) << endl;


    // ========================================================================
    // BITWISE XOR
    // ========================================================================

    cout << "\n--- BITWISE XOR ---\n";

    cout << "5 ^ 3 = "
         << (a ^ b) << endl;


    // ========================================================================
    // BITWISE NOT
    // ========================================================================

    cout << "\n--- BITWISE NOT ---\n";

    cout << "~5 = "
         << (~a) << endl;

    cout << "5 as 8-bit binary = "
         << bitset<8>(5) << endl;

    cout << "~5 as 8-bit binary = "
         << bitset<8>(static_cast<unsigned char>(~a))
         << endl;


    // ========================================================================
    // LEFT SHIFT
    // ========================================================================

    cout << "\n--- LEFT SHIFT ---\n";

    cout << "5 << 1 = "
         << (5 << 1) << endl;

    cout << "5 << 2 = "
         << (5 << 2) << endl;


    // ========================================================================
    // RIGHT SHIFT
    // ========================================================================

    cout << "\n--- RIGHT SHIFT ---\n";

    cout << "20 >> 1 = "
         << (20 >> 1) << endl;

    cout << "20 >> 2 = "
         << (20 >> 2) << endl;


    // ========================================================================
    // ODD / EVEN USING BITWISE AND
    // ========================================================================

    cout << "\n--- ODD / EVEN ---\n";

    int number = 17;

    if ((number & 1) == 1)
    {
        cout << number << " is ODD" << endl;
    }
    else
    {
        cout << number << " is EVEN" << endl;
    }


    // ========================================================================
    // SET A BIT
    // ========================================================================

    cout << "\n--- SET BIT ---\n";

    int value = 0;

    // Set bit position 2.

    value = value | (1 << 2);

    cout << "After setting bit 2: "
         << bitset<8>(value) << endl;


    // ========================================================================
    // CLEAR A BIT
    // ========================================================================

    cout << "\n--- CLEAR BIT ---\n";

    value = 15;     // 00001111

    value = value & ~(1 << 2);

    cout << "After clearing bit 2: "
         << bitset<8>(value) << endl;


    // ========================================================================
    // TOGGLE A BIT
    // ========================================================================

    cout << "\n--- TOGGLE BIT ---\n";

    value = 4;      // 00000100

    value = value ^ (1 << 2);

    cout << "After toggle: "
         << bitset<8>(value) << endl;


    // ========================================================================
    // BITWISE ASSIGNMENT OPERATORS
    // ========================================================================

    cout << "\n--- BITWISE ASSIGNMENT ---\n";

    int x = 5;

    x &= 3;

    cout << "After &= : "
         << x << endl;


    x = 5;

    x |= 3;

    cout << "After |= : "
         << x << endl;


    x = 5;

    x ^= 3;

    cout << "After ^= : "
         << x << endl;


    x = 5;

    x <<= 1;

    cout << "After <<= : "
         << x << endl;


    x = 20;

    x >>= 1;

    cout << "After >>= : "
         << x << endl;


    // ========================================================================
    // XOR PROPERTIES
    // ========================================================================

    cout << "\n--- XOR PROPERTIES ---\n";

    cout << "5 ^ 0 = "
         << (5 ^ 0) << endl;

    cout << "5 ^ 5 = "
         << (5 ^ 5) << endl;


    // ========================================================================
    // REMOVE LOWEST SET BIT
    // ========================================================================

    cout << "\n--- REMOVE LOWEST SET BIT ---\n";

    unsigned int bits = 12;    // 1100

    cout << "Before: "
         << bitset<8>(bits) << endl;

    bits = bits & (bits - 1);

    cout << "After : "
         << bitset<8>(bits) << endl;


    // ========================================================================
    // COUNT SET BITS
    // ========================================================================

    cout << "\n--- COUNT SET BITS ---\n";

    unsigned int n = 29;       // 00011101

    int count = 0;

    unsigned int temp = n;

    while (temp != 0)
    {
        temp = temp & (temp - 1);

        count++;
    }

    cout << "Number of set bits in "
         << n
         << " = "
         << count
         << endl;


    /*
    ===========================================================================
                           QUICK REVISION
    ===========================================================================

    BITWISE OPERATORS
    ---------------------------------------------------------------------------

    &       Bitwise AND
    |       Bitwise OR
    ^       Bitwise XOR
    ~       Bitwise NOT
    <<      Left Shift
    >>      Right Shift


    AND
    ---------------------------------------------------------------------------

    1 & 1 = 1
    Otherwise = 0

    Memory trick:

    BOTH must be 1.


    OR
    ---------------------------------------------------------------------------

    0 | 0 = 0
    Otherwise = 1

    Memory trick:

    AT LEAST ONE must be 1.


    XOR
    ---------------------------------------------------------------------------

    Same       -> 0
    Different  -> 1


    NOT
    ---------------------------------------------------------------------------

    0 -> 1
    1 -> 0


    LEFT SHIFT
    ---------------------------------------------------------------------------

    x << 1

    For suitable unsigned values:

    x * 2


    x << 2

    x * 4


    RIGHT SHIFT
    ---------------------------------------------------------------------------

    For unsigned values:

    x >> 1

    x / 2


    x >> 2

    x / 4


    ODD / EVEN
    ---------------------------------------------------------------------------

    n & 1

    Result 1 -> ODD
    Result 0 -> EVEN


    SET BIT
    ---------------------------------------------------------------------------

    n | (1 << position)


    CLEAR BIT
    ---------------------------------------------------------------------------

    n & ~(1 << position)


    TOGGLE BIT
    ---------------------------------------------------------------------------

    n ^ (1 << position)


    CHECK BIT
    ---------------------------------------------------------------------------

    n & (1 << position)


    REMOVE LOWEST SET BIT
    ---------------------------------------------------------------------------

    n & (n - 1)


    XOR IMPORTANT
    ---------------------------------------------------------------------------

    n ^ 0 = n

    n ^ n = 0


    BITWISE vs LOGICAL
    ---------------------------------------------------------------------------

    Bitwise:

    &   |   ^   ~

    Logical:

    &&  ||  !


    EXAMPLE
    ---------------------------------------------------------------------------

    5 = 00000101
    3 = 00000011


    5 & 3 = 00000001 = 1

    5 | 3 = 00000111 = 7

    5 ^ 3 = 00000110 = 6


    ===========================================================================
                            MEMORY TRICK
    ===========================================================================

    &  -> BOTH
    |  -> ANY
    ^  -> DIFFERENT
    ~  -> FLIP
    << -> LEFT
    >> -> RIGHT


    ===========================================================================
    */
    
    return 0;
}