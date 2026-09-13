#include <iostream>
using namespace std;

/*
============================================================
                    LOOPS IN C++
============================================================

Definition:
Loop ka use kisi code ko baar-baar execute karne ke
liye kiya jata hai.

Example:

Agar humein "Hello" 5 baar print karna hai,
to baar-baar cout likhne ki zarurat nahi.

Loop automatically code ko repeat kar sakta hai.


------------------------------------------------------------
WHY DO WE USE LOOPS?
------------------------------------------------------------

Without loop:

cout << "Hello" << endl;
cout << "Hello" << endl;
cout << "Hello" << endl;
cout << "Hello" << endl;
cout << "Hello" << endl;

With loop:

for (int i = 1; i <= 5; i++)
{
    cout << "Hello" << endl;
}

Isliye loops code ko:
-> Short
-> Clean
-> Efficient
banate hain.


============================================================
                  TYPES OF LOOPS
============================================================

C++ mein commonly ye loops use hote hain:

1. for loop
2. while loop
3. do-while loop
4. range-based for loop

Inke andar:
-> Nested loops
-> Infinite loops

bhi bana sakte hain.

============================================================
          ITERATE, ITERATION & ITERATOR
============================================================

ITERATE:
-> Kisi collection/data ke elements ko ek-ek karke
   process ya access karna = iterate karna.

Example:
Array ke har element ko loop se access karna
array ko ITERATE karna hai.


ITERATION:
-> Loop ka ek complete cycle/run = one iteration.

Example:

for (int i = 1; i <= 3; i++)
{
    cout << i;
}

Yahan loop 3 times chala:

1st iteration -> i = 1
2nd iteration -> i = 2
3rd iteration -> i = 3


ITERATOR:
-> Iterator ek object/type hota hai jo collection ke
   elements ko traverse (ek-ek karke access) karne ke
   liye use hota hai.

Example:
vector<int>::iterator it;

Iterator ko mainly STL containers jaise
vector, list, set, map etc. ke saath use kiya jata hai.

IMPORTANT:
Iterator aur iteration same nahi hain.

Iteration:
-> Loop ka ek cycle.

Iterator:
-> Collection ke elements ko traverse karne wala
   object/tool.

============================================================
                  1. FOR LOOP
============================================================

Definition:
Jab humein generally pata hota hai ki loop ko
kitni baar chalana hai, tab for loop useful hota hai.

Syntax:

for (initialization; condition; update)
{
    // code
}


Example:

for (int i = 1; i <= 5; i++)
{
    cout << i << endl;
}


Ismein:

initialization:
    int i = 1

    Loop start hone se pehle ek baar execute hota hai.

condition:
    i <= 5

    Jab tak condition TRUE hai,
    loop chalega.

update:
    i++

    Har iteration ke baad execute hota hai.


------------------------------------------------------------
FOR LOOP KA FLOW
------------------------------------------------------------

1. Initialization
       ↓
2. Condition check
       ↓
3. Condition TRUE?
       ↓
4. Loop body execute
       ↓
5. Update
       ↓
6. Condition check again
       ↓
   Repeat


Example:

for (int i = 1; i <= 3; i++)

Iteration 1:
i = 1
1 <= 3 -> TRUE
print 1
i++

Iteration 2:
i = 2
2 <= 3 -> TRUE
print 2
i++

Iteration 3:
i = 3
3 <= 3 -> TRUE
print 3
i++

Iteration 4:
i = 4
4 <= 3 -> FALSE
loop stop


============================================================
                  2. WHILE LOOP
============================================================

Definition:
while loop mein pehle condition check hoti hai.

Jab tak condition TRUE hai,
loop body repeatedly execute hoti hai.

Syntax:

while (condition)
{
    // code
}


Example:

int i = 1;

while (i <= 5)
{
    cout << i << endl;
    i++;
}


IMPORTANT:
while loop mein initialization aur update
hum manually likhte hain.


------------------------------------------------------------
WHILE LOOP FLOW
------------------------------------------------------------

Initialization
      ↓
Condition check
      ↓
TRUE?
  ↓       ↓
 YES      NO
  ↓       ↓
Body     Stop
  ↓
Update
  ↓
Condition again


------------------------------------------------------------
FOR vs WHILE
------------------------------------------------------------

for:

for (int i = 1; i <= 5; i++)
{
    cout << i;
}

while:

int i = 1;

while (i <= 5)
{
    cout << i;
    i++;
}

Dono same type ka kaam kar sakte hain.

Generally:

FOR
-> Jab iterations ka idea/pattern clear ho.

WHILE
-> Jab condition-based repetition ho aur
   iterations pehle se fixed na hon.


============================================================
                  3. DO-WHILE LOOP
============================================================

Definition:
do-while loop mein code PEHLE execute hota hai,
condition BAAD mein check hoti hai.

Syntax:

do
{
    // code
}
while (condition);


Example:

int i = 1;

do
{
    cout << i << endl;
    i++;
}
while (i <= 5);


------------------------------------------------------------
IMPORTANT DIFFERENCE
------------------------------------------------------------

while loop:

while (condition)
{
    // code
}

Pehle condition check
Phir code execute


do-while:

do
{
    // code
}
while (condition);

Pehle code execute
Phir condition check


Isliye do-while loop:
-> Minimum ONE time execute hota hai,
   even if condition initially FALSE ho.


Example:

int i = 10;

do
{
    cout << "Hello";
}
while (i < 5);


Condition:
10 < 5 -> FALSE

Lekin "Hello" ek baar print hoga.

Because do-while mein body pehle execute hoti hai.


============================================================
              4. RANGE-BASED FOR LOOP
============================================================

Range-based for loop ka use kisi collection/array
ke elements ko easily traverse karne ke liye hota hai.

Syntax:

for (data_type variable : collection)
{
    // code
}


Example:

int numbers[] = {10, 20, 30, 40, 50};

for (int number : numbers)
{
    cout << number << endl;
}


Output:

10
20
30
40
50


Yahan:

number
-> Har iteration mein array ka next element
   receive karta hai.


------------------------------------------------------------
NORMAL FOR vs RANGE-BASED FOR
------------------------------------------------------------

Normal for:

for (int i = 0; i < 5; i++)
{
    cout << numbers[i];
}


Range-based for:

for (int number : numbers)
{
    cout << number;
}


Range-based for mein index manually manage
karne ki zarurat nahi hoti.


============================================================
                  5. NESTED LOOP
============================================================

Definition:
Jab ek loop ke andar doosra loop hota hai,
use Nested Loop kehte hain.

Example:

for (int i = 1; i <= 3; i++)
{
    for (int j = 1; j <= 3; j++)
    {
        cout << j << " ";
    }

    cout << endl;
}


Outer loop:
-> Rows control karta hai.

Inner loop:
-> Har row ke andar columns/items control karta hai.


Nested loops ka common use:

-> Patterns
-> Tables
-> 2D arrays
-> Matrix
-> Grid problems


------------------------------------------------------------
NESTED LOOP FLOW
------------------------------------------------------------

Outer loop 1
    ↓
    Inner loop complete
    ↓
Outer loop 2
    ↓
    Inner loop complete
    ↓
Outer loop 3
    ↓
    Inner loop complete


IMPORTANT:
Har baar outer loop ki ek iteration par
inner loop apni COMPLETE execution karta hai.


============================================================
                  6. INFINITE LOOP
============================================================

Definition:
Aisa loop jo kabhi terminate nahi hota,
Infinite Loop kehlata hai.

Example:

while (true)
{
    cout << "Hello";
}


Condition:
true

-> Always TRUE
-> Loop continuously chalega.


Another example:

for (;;)
{
    cout << "Hello";
}


WARNING:
Infinite loop intentionally bhi use ho sakta hai,
lekin agar accidentally ban gaya to program
continuously run kar sakta hai.


============================================================
                  7. BREAK
============================================================

break statement loop ko immediately terminate
kar deta hai.

Example:

for (int i = 1; i <= 10; i++)
{
    if (i == 5)
    {
        break;
    }

    cout << i << endl;
}


Output:

1
2
3
4

Jab i == 5 hua:
-> break execute
-> Loop completely stop


IMPORTANT:

break = LOOP SE BAHAR NIKLO


============================================================
                  8. CONTINUE
============================================================

continue current iteration ko skip karta hai
aur next iteration par chala jata hai.

Example:

for (int i = 1; i <= 5; i++)
{
    if (i == 3)
    {
        continue;
    }

    cout << i << endl;
}


Output:

1
2
4
5


Jab i == 3:

continue execute
-> 3 ka remaining code skip
-> Next iteration


IMPORTANT:

continue = CURRENT ITERATION SKIP KARO


------------------------------------------------------------
BREAK vs CONTINUE
------------------------------------------------------------

break:
-> Pura loop terminate.

continue:
-> Sirf current iteration skip.


Example:

break:

1 2 3 4
STOP


continue:

1 2 4 5
(loop continues)


============================================================
              COMPLETE PRACTICAL PROGRAM
============================================================
*/

int main()
{
    /*
    --------------------------------------------------------
    1. FOR LOOP
    --------------------------------------------------------
    */

    cout << "1. FOR LOOP" << endl;

    for (int i = 1; i <= 5; i++)
    {
        cout << i << " ";
    }

    cout << endl << endl;


    /*
    --------------------------------------------------------
    2. WHILE LOOP
    --------------------------------------------------------
    */

    cout << "2. WHILE LOOP" << endl;

    int i = 1;

    while (i <= 5)
    {
        cout << i << " ";
        i++;
    }

    cout << endl << endl;


    /*
    --------------------------------------------------------
    3. DO-WHILE LOOP
    --------------------------------------------------------
    */

    cout << "3. DO-WHILE LOOP" << endl;

    int j = 1;

    do
    {
        cout << j << " ";
        j++;
    }
    while (j <= 5);

    cout << endl << endl;


    /*
    --------------------------------------------------------
    4. RANGE-BASED FOR LOOP
    --------------------------------------------------------
    */

    cout << "4. RANGE-BASED FOR LOOP" << endl;

    int numbers[] = {10, 20, 30, 40, 50};

    for (int number : numbers)
    {
        cout << number << " ";
    }

    cout << endl << endl;


    /*
    --------------------------------------------------------
    5. NESTED LOOP
    --------------------------------------------------------
    */

    cout << "5. NESTED LOOP" << endl;

    for (int row = 1; row <= 3; row++)
    {
        for (int column = 1; column <= 3; column++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    cout << endl;


    /*
    --------------------------------------------------------
    6. BREAK
    --------------------------------------------------------
    */

    cout << "6. BREAK" << endl;

    for (int k = 1; k <= 10; k++)
    {
        if (k == 5)
        {
            break;
        }

        cout << k << " ";
    }

    cout << endl << endl;


    /*
    --------------------------------------------------------
    7. CONTINUE
    --------------------------------------------------------
    */

    cout << "7. CONTINUE" << endl;

    for (int k = 1; k <= 5; k++)
    {
        if (k == 3)
        {
            continue;
        }

        cout << k << " ";
    }

    cout << endl;

    return 0;
}