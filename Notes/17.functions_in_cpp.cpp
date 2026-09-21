#include <iostream>
using namespace std;

/*
============================================================
                    FUNCTIONS IN C++
============================================================

Definition:
Function ek named block of code hota hai jo ek specific
task perform karta hai.

Function ka main purpose:
-> Code ko reusable banana
-> Large program ko small parts mein divide karna
-> Code ko clean aur organized rakhna


------------------------------------------------------------
BASIC SYNTAX
------------------------------------------------------------

return_type function_name(parameters)
{
    // function body
    return value;
}


Example:

int add(int a, int b)
{
    return a + b;
}


Yahan:

int
-> Return type

add
-> Function name

int a, int b
-> Parameters

return a + b
-> Returned value


============================================================
              FUNCTION DECLARATION
============================================================

Function Declaration ko Function Prototype bhi kehte hain.

Declaration compiler ko pehle hi bata deti hai ki
function exist karta hai.

Syntax:

return_type function_name(parameters);

Example:

int add(int a, int b);


Yahan function ka body nahi hai.

Sirf compiler ko information di gayi hai:
-> Function ka naam kya hai
-> Return type kya hai
-> Kitne parameters hain
-> Parameters ke types kya hain


============================================================
              FORWARD DECLARATION
============================================================

Jab function ko uski definition se PEHLE declare kiya
jata hai, use Forward Declaration kehte hain.

Example:

int add(int a, int b);   // Forward declaration

int main()
{
    cout << add(10, 20);
}

int add(int a, int b)
{
    return a + b;
}


Why needed?

C++ normally code ko top-to-bottom process karta hai.

Agar main() mein function ko call kar diya aur compiler
ne abhi tak us function ko dekha hi nahi hai, to problem
ho sakti hai.

Forward declaration compiler ko pehle hi function ke
baare mein bata deti hai.


------------------------------------------------------------
IMPORTANT
------------------------------------------------------------

Declaration:

int add(int, int);

Definition:

int add(int a, int b)
{
    return a + b;
}

Call:

add(10, 20);


Declaration
-> Function ke baare mein information.

Definition
-> Function ka actual implementation/body.

Call
-> Function ko execute karna.


============================================================
                  PARAMETERS
============================================================

Parameter wo variable hota hai jo function definition
mein receive karta hai.

Example:

int add(int a, int b)
{
    return a + b;
}

Yahan:

a and b = PARAMETERS


Parameters ko formal parameters bhi kaha jata hai.


============================================================
                  ARGUMENTS
============================================================

Function ko call karte waqt jo actual values pass
karte hain, unhe ARGUMENTS kehte hain.

Example:

add(10, 20);

Yahan:

10 and 20 = ARGUMENTS


------------------------------------------------------------
PARAMETER vs ARGUMENT
------------------------------------------------------------

Function definition:

int add(int a, int b)

a, b
-> Parameters


Function call:

add(10, 20)

10, 20
-> Arguments


Easy memory:

PARAMETER
= Function ke andar receive hone wala variable.

ARGUMENT
= Function call ke time pass ki gayi actual value.


============================================================
              WHAT HAPPENS IN MEMORY?
============================================================

Function call hone par memory mein function ke liye
ek temporary memory area create hota hai.

Is area ko generally STACK FRAME / ACTIVATION RECORD
kehte hain.

Example:

int add(int a, int b)
{
    int sum = a + b;
    return sum;
}

When:

add(10, 20);

Function call hone par:

Stack Frame for add
-------------------
a   = 10
b   = 20
sum = 30
-------------------

Function complete hone ke baad ye stack frame
normally destroy/remove ho jata hai.


------------------------------------------------------------
IMPORTANT MEMORY CONCEPT
------------------------------------------------------------

Local variables aur parameters generally function ke
stack frame se associated hote hain.

Example:

int add(int a, int b)
{
    int sum = a + b;
    return sum;
}

Memory concept:

main()
   |
   |---- add(10, 20)
             |
             |---- a = 10
             |---- b = 20
             |---- sum = 30
             |
             |---- return 30
   |
   |---- add ka stack frame remove


IMPORTANT:
Actual memory implementation compiler/ABI par depend
kar sakti hai, but beginner level par function calls ko
stack frames ke through samajhna useful hai.


============================================================
                    SCOPE
============================================================

Scope ka matlab hai:

"Kisi variable ko program ke kis part mein access
kiya ja sakta hai."


Mainly do important scopes:

1. Local Scope
2. Global Scope


============================================================
                  LOCAL SCOPE
============================================================

Jo variable kisi function/block ke andar declare hota hai,
uska scope usi function/block tak hota hai.

Example:

void test()
{
    int x = 10;

    cout << x;   // Valid
}

// cout << x;    // ERROR


x sirf test() ke andar accessible hai.


------------------------------------------------------------
BLOCK SCOPE
------------------------------------------------------------

if, for, while etc. ke braces ke andar declared
variable bhi us block tak limited hota hai.

Example:

if (true)
{
    int x = 10;
    cout << x;   // Valid
}

// cout << x;    // ERROR


============================================================
                  GLOBAL SCOPE
============================================================

Jo variable functions ke bahar declare hota hai,
wo global variable hota hai.

Example:

int value = 100;   // Global variable

void test()
{
    cout << value; // Accessible
}

int main()
{
    cout << value; // Accessible
}


Global variable ka scope generally us declaration ke baad
poore translation unit mein hota hai, subject to linkage
and other language rules.


------------------------------------------------------------
LOCAL vs GLOBAL
------------------------------------------------------------

LOCAL:

void test()
{
    int x = 10;
}

-> Limited scope
-> Function/block ke andar use


GLOBAL:

int x = 10;

int main()
{
    cout << x;
}

-> Functions ke bahar declared
-> Wider scope


============================================================
              FUNCTION OVERLOADING
============================================================

Definition:
Same function name ko different parameter lists ke saath
define karna = Function Overloading.

Example:

int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
}


Dono ka naam:
add

Lekin parameter types different hain:

add(int, int)
add(double, double)


Compiler arguments ke according appropriate function
select karta hai.


------------------------------------------------------------
ANOTHER EXAMPLE
------------------------------------------------------------

int area(int side)
{
    return side * side;
}

int area(int length, int width)
{
    return length * width;
}


area(5)
-> First function

area(5, 10)
-> Second function


------------------------------------------------------------
IMPORTANT RULE
------------------------------------------------------------

Function overloading mein function ka naam same hona
chahiye, lekin parameter list different honi chahiye.

Parameter list different ho sakti hai by:

-> Number of parameters
-> Type of parameters
-> Order of parameter types


Example:

add(int, int)
add(int, int, int)

Different number.


add(int, double)
add(double, int)

Different order/type.


------------------------------------------------------------
RETURN TYPE ONLY SE OVERLOADING NAHI HOTI
------------------------------------------------------------

INVALID:

int add(int a, int b)
{
    return a + b;
}

double add(int a, int b)
{
    return a + b;
}


Ye valid overloading nahi hai because parameter list
same hai.

Sirf return type different hone se function overload
nahi hota.


============================================================
                  COMPLETE PROGRAM
============================================================
*/

// ---------------------------------------------------------
// FORWARD DECLARATIONS
// ---------------------------------------------------------

int add(int a, int b);

int multiply(int a, int b);

void showScope();

int area(int side);
int area(int length, int width);


// ---------------------------------------------------------
// GLOBAL VARIABLE
// ---------------------------------------------------------

int globalValue = 100;


// ---------------------------------------------------------
// FUNCTION DEFINITIONS
// ---------------------------------------------------------

int add(int a, int b)
{
    // a and b are PARAMETERS.
    // Their values are received from function ARGUMENTS.

    int sum = a + b;

    return sum;
}


int multiply(int a, int b)
{
    return a * b;
}


// Function for demonstrating local scope
void showScope()
{
    int localValue = 50;

    cout << "Local value  = " << localValue << endl;

    // Global variable can also be accessed here.
    cout << "Global value = " << globalValue << endl;
}


// ---------------------------------------------------------
// FUNCTION OVERLOADING
// ---------------------------------------------------------

// Version 1: One parameter
int area(int side)
{
    return side * side;
}


// Version 2: Two parameters
int area(int length, int width)
{
    return length * width;
}


// =========================================================
// MAIN FUNCTION
// =========================================================

int main()
{
    /*
    --------------------------------------------------------
    FUNCTION CALL
    --------------------------------------------------------
    */

    int result = add(10, 20);

    cout << "Addition = " << result << endl;


    /*
    --------------------------------------------------------
    PARAMETERS AND ARGUMENTS
    --------------------------------------------------------

    add(10, 20);

    10, 20 -> Arguments

    Function:

    int add(int a, int b)

    a, b -> Parameters
    */

    cout << "Multiplication = "
         << multiply(5, 4)
         << endl;


    /*
    --------------------------------------------------------
    LOCAL AND GLOBAL SCOPE
    --------------------------------------------------------
    */

    showScope();

    // globalValue is accessible inside main()
    // because it is a global variable.

    cout << "Global value in main = "
         << globalValue
         << endl;


    /*
    --------------------------------------------------------
    FUNCTION OVERLOADING
    --------------------------------------------------------
    */

    cout << "Square = "
         << area(5)
         << endl;

    cout << "Rectangle area = "
         << area(5, 10)
         << endl;

    return 0;
}