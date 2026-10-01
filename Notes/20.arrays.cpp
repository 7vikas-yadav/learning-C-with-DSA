#include <iostream>
#include <iomanip>
#include <algorithm>    // sort(), copy()
#include <array>        // std::array
#include <cstring>      // strlen(), strcpy(), strcmp(), strcat()
#include <string>

using namespace std;


/*
===============================================================================
                              ARRAYS IN C++
===============================================================================

-------------------------------------------------------------------------------
1. WHAT IS AN ARRAY?
-------------------------------------------------------------------------------

An array is a collection of multiple values of the SAME data type
stored under one variable name.

Example:

int marks[5];

This creates an array that can store 5 integers.

Conceptually:

marks
   |
   +---- [0] = 80
   +---- [1] = 75
   +---- [2] = 90
   +---- [3] = 65
   +---- [4] = 88


IMPORTANT:

Array:
    - stores multiple values
    - all elements have the same type
    - elements are stored contiguously
    - indexing starts from 0
    - normal built-in array has fixed size


===============================================================================
2. WHY DO WE NEED ARRAYS?
===============================================================================

Without an array:

int mark1 = 80;
int mark2 = 75;
int mark3 = 90;
int mark4 = 65;
int mark5 = 88;

This becomes difficult when there are hundreds or thousands of values.

Using an array:

int marks[5];

Now all 5 values can be handled using one variable name.

For example:

marks[0]
marks[1]
marks[2]
marks[3]
marks[4]


===============================================================================
3. CHARACTERISTICS OF AN ARRAY
===============================================================================

Important characteristics:

1. Same data type
2. Fixed size for built-in arrays
3. Contiguous memory
4. Zero-based indexing
5. Direct/random access using index
6. Multiple values under one name

Example:

int arr[5];


===============================================================================
4. ARRAY DECLARATION
===============================================================================

Syntax:

    dataType arrayName[size];

Example:

    int marks[5];

Here:

int     -> data type
marks   -> array name
5       -> number of elements


Other examples:

double prices[10];

char letters[26];

float temperature[7];


===============================================================================
5. ARRAY SIZE
===============================================================================

If we write:

int arr[5];

The array contains:

5 elements

Valid indexes are:

0
1
2
3
4

NOT:

5


IMPORTANT:

For an array of size N:

First index = 0
Last index  = N - 1


===============================================================================
6. ARRAY INITIALIZATION
===============================================================================

We can initialize an array while declaring it.

Example:

int arr[5] = {10, 20, 30, 40, 50};


Indexes:

arr[0] = 10
arr[1] = 20
arr[2] = 30
arr[3] = 40
arr[4] = 50


We can also let the compiler determine the size:

int arr[] = {10, 20, 30, 40, 50};

Size = 5


===============================================================================
7. PARTIAL INITIALIZATION
===============================================================================

Example:

int arr[5] = {10, 20};

Remaining elements are initialized to zero.

Conceptually:

arr[0] = 10
arr[1] = 20
arr[2] = 0
arr[3] = 0
arr[4] = 0


Similarly:

int arr[5] = {};

All elements become zero.


===============================================================================
8. ACCESSING ARRAY ELEMENTS
===============================================================================

Syntax:

    arrayName[index]

Example:

int arr[5] = {10, 20, 30, 40, 50};

cout << arr[0];

Output:

10


cout << arr[3];

Output:

40


===============================================================================
9. MODIFYING ARRAY ELEMENTS
===============================================================================

Array elements can be modified using their index.

Example:

int arr[5] = {10, 20, 30, 40, 50};

arr[2] = 100;

Now:

arr = {10, 20, 100, 40, 50}


===============================================================================
10. OUT-OF-BOUNDS ACCESS
===============================================================================

For:

int arr[5];

valid indexes are:

0 1 2 3 4

This is WRONG:

arr[5]

This is also WRONG:

arr[-1]


Accessing outside the valid range causes undefined behavior
for a built-in C++ array.

C++ does NOT automatically perform bounds checking for arr[index].


===============================================================================
11. ARRAY MEMORY
===============================================================================

Array elements are stored in CONTIGUOUS memory.

Example:

int arr[4] = {10, 20, 30, 40};

Conceptually:

Address       Value
-------       -----
1000          10
1004          20
1008          30
1012          40

The exact addresses and spacing depend on the system and data type.

For int:

next element is sizeof(int) bytes away.


===============================================================================
12. ADDRESS OF ARRAY ELEMENTS
===============================================================================

Example:

int arr[3] = {10, 20, 30};

&arr[0]
    -> address of first element

&arr[1]
    -> address of second element

&arr[2]
    -> address of third element


Because array elements are contiguous:

Address of arr[i] is conceptually:

    address of first element + i * sizeof(element)


===============================================================================
13. sizeof() WITH ARRAYS
===============================================================================

Example:

int arr[5];

sizeof(arr)

gives the total number of bytes occupied by the entire array.

If int is 4 bytes:

sizeof(arr) = 20 bytes


Size of one element:

sizeof(arr[0])


Number of elements:

sizeof(arr) / sizeof(arr[0])


Example:

int arr[] = {10, 20, 30, 40, 50};

int n = sizeof(arr) / sizeof(arr[0]);

n = 5


IMPORTANT:

This technique works for an actual built-in array in the same
scope where it exists.

It does NOT generally work after the array has decayed to a pointer
when passed to a normal function parameter.


===============================================================================
14. ARRAY + POINTER RELATIONSHIP
===============================================================================

Example:

int arr[5] = {10, 20, 30, 40, 50};

In most expressions, the array name arr converts to a pointer
to its first element.

So:

arr

behaves like:

&arr[0]


Therefore:

arr == &arr[0]

in an address comparison context.


===============================================================================
15. arr, &arr[0], *arr
===============================================================================

Suppose:

int arr[3] = {10, 20, 30};


arr

    -> address of first element in most expressions


&arr[0]

    -> address of first element


*arr

    -> value of first element


Therefore:

arr      -> address
&arr[0]  -> address
*arr     -> first value


===============================================================================
16. POINTER ARITHMETIC
===============================================================================

Suppose:

int arr[3] = {10, 20, 30};

int* ptr = arr;


ptr
    -> address of arr[0]

ptr + 1
    -> address of arr[1]

ptr + 2
    -> address of arr[2]


And:

*(ptr + 0) -> arr[0]
*(ptr + 1) -> arr[1]
*(ptr + 2) -> arr[2]


IMPORTANT:

Pointer arithmetic automatically accounts for the size of the
pointed-to type.


===============================================================================
17. arr[i] AND *(arr+i)
===============================================================================

These are equivalent for array access:

arr[i]

and:

*(arr + i)


Example:

arr[2]

is equivalent to:

*(arr + 2)


This is an important connection between arrays and pointers.


===============================================================================
18. ARRAY TRAVERSAL
===============================================================================

Traversal means visiting each element of an array one by one.

Example:

for (int i = 0; i < 5; i++)
{
    cout << arr[i];
}


IMPORTANT:

Loop condition should normally be:

i < size

NOT:

i <= size


===============================================================================
19. RANGE-BASED FOR LOOP
===============================================================================

Modern C++ provides:

for (int value : arr)
{
    cout << value;
}

This automatically visits every element.


If we want to modify elements:

for (int& value : arr)
{
    value *= 2;
}

The & means value is a reference to the actual element.


===============================================================================
20. TAKING ARRAY INPUT
===============================================================================

Example:

int arr[5];

for (int i = 0; i < 5; i++)
{
    cin >> arr[i];
}


===============================================================================
21. PRINTING AN ARRAY
===============================================================================

Example:

for (int i = 0; i < 5; i++)
{
    cout << arr[i] << " ";
}


===============================================================================
22. SUM OF ARRAY ELEMENTS
===============================================================================

Algorithm:

1. Create sum = 0
2. Traverse array
3. Add each element to sum


sum += arr[i];


===============================================================================
23. AVERAGE OF ARRAY
===============================================================================

Formula:

average = sum / number of elements


IMPORTANT:

If you want decimal output, use floating-point division.

Example:

double average = (double)sum / n;


===============================================================================
24. MAXIMUM AND MINIMUM
===============================================================================

We can find the maximum and minimum by traversing the array.

Do NOT blindly initialize max/min to 0 if the array may contain
only negative numbers.

Better approach:

int maxValue = arr[0];
int minValue = arr[0];


===============================================================================
25. SEARCHING
===============================================================================

Linear Search:

Check each element one by one.

Example:

arr = {10, 20, 30, 40}

Search 30:

10 -> no
20 -> no
30 -> FOUND


Time complexity:

O(n)


===============================================================================
26. FREQUENCY
===============================================================================

Frequency means:

How many times a value occurs.

Example:

arr = {10, 20, 10, 30, 10}

Frequency of 10 = 3


===============================================================================
27. DUPLICATE ELEMENTS
===============================================================================

A duplicate is a value that appears more than once.

Example:

{10, 20, 30, 20, 40}

20 is duplicated.


===============================================================================
28. REVERSE AN ARRAY
===============================================================================

Example:

Original:

1 2 3 4 5

After reverse:

5 4 3 2 1


Two-pointer approach:

left = 0
right = n - 1

Swap:

arr[left]
arr[right]

Then:

left++
right--


Time complexity:

O(n)


===============================================================================
29. COPYING ARRAYS
===============================================================================

For built-in arrays:

int a[3] = {1, 2, 3};
int b[3];

This is NOT valid:

b = a;


Instead use a loop:

for (int i = 0; i < 3; i++)
{
    b[i] = a[i];
}


You can also use:

std::copy(a, a + 3, b);


===============================================================================
30. COMPARING ARRAYS
===============================================================================

Built-in arrays cannot normally be compared using:

a == b

for element-by-element comparison.

Instead:

1. Check sizes
2. Compare corresponding elements


Example:

a[0] == b[0]
a[1] == b[1]
...


===============================================================================
31. INSERTION IN ARRAY
===============================================================================

Normal built-in arrays have fixed capacity.

Suppose:

10 20 30 40

Insert 25 at index 2.

We first shift elements right:

10 20 30 40
       <- <- <-

Then:

10 20 25 30 40


IMPORTANT:

A built-in array cannot physically grow.

We need enough unused capacity or another container such as
std::vector for dynamically growing collections.


===============================================================================
32. DELETION FROM ARRAY
===============================================================================

Suppose:

10 20 30 40 50

Delete element at index 2:

10 20 40 50


Elements after the deleted position are shifted left.


===============================================================================
33. SORTING
===============================================================================

Sorting means arranging elements in a particular order.

Ascending:

1 2 3 4 5

Descending:

5 4 3 2 1


C++ provides:

sort(arr, arr + n);


Header:

#include <algorithm>


Descending:

sort(arr, arr + n, greater<int>());


===============================================================================
34. BUBBLE SORT
===============================================================================

Bubble Sort repeatedly compares adjacent elements and swaps them
when they are in the wrong order.

Example:

5 2 4 1

After passes, eventually:

1 2 4 5


Typical time complexity:

O(n^2)


===============================================================================
35. SELECTION SORT
===============================================================================

Selection Sort:

1. Find smallest element
2. Put it at current position
3. Repeat


Typical time complexity:

O(n^2)


===============================================================================
36. INSERTION SORT
===============================================================================

Insertion Sort builds the sorted portion one element at a time.

It is useful for understanding sorting algorithms and can perform
well on small or nearly sorted data.

Typical worst-case time complexity:

O(n^2)


===============================================================================
37. SECOND LARGEST
===============================================================================

We can find the largest and second-largest values in one traversal
with appropriate handling for duplicates.

Example:

10 50 20 40

Largest = 50
Second largest = 40


Need to decide whether "second largest" means:

- second distinct largest
OR
- second element in sorted order

These can differ when duplicates exist.

Example:

10 50 50 20

Second DISTINCT largest = 20

But second element after sorting descending = 50.


===============================================================================
38. ARRAY ROTATION
===============================================================================

LEFT ROTATION:

1 2 3 4 5

Rotate left by one:

2 3 4 5 1


RIGHT ROTATION:

1 2 3 4 5

Rotate right by one:

5 1 2 3 4


Rotation by k positions is also possible.


===============================================================================
39. MERGING ARRAYS
===============================================================================

Example:

A = {1, 2, 3}
B = {4, 5, 6}

Merged:

{1, 2, 3, 4, 5, 6}


If arrays are sorted, there are more efficient merge techniques
used in algorithms such as Merge Sort.


===============================================================================
40. UNION AND INTERSECTION
===============================================================================

Union:

Elements present in either set/array.

Intersection:

Elements common to both.

Example:

A = {1, 2, 3}
B = {2, 3, 4}

Intersection:

{2, 3}

Union:

{1, 2, 3, 4}


For arrays with duplicates, you must define whether duplicates
should be preserved or removed.


===============================================================================
41. FINDING A MISSING NUMBER
===============================================================================

Example:

{1, 2, 3, 5}

If expected numbers are:

1 to 5

Missing number = 4


One common mathematical approach:

Expected sum:

n * (n + 1) / 2

Missing:

expected sum - actual sum


This method has limitations if integer overflow is possible for
very large n.


===============================================================================
42. PAIR WITH GIVEN SUM
===============================================================================

Example:

arr = {2, 7, 11, 15}

Target = 9

Pair:

2 + 7 = 9


A simple nested-loop solution:

O(n^2)

More advanced solutions can use sorting or hashing.


===============================================================================
43. MOVE ZEROS
===============================================================================

Example:

0 1 0 3 12

Move zeros to the end:

1 3 12 0 0


This is a common array interview problem.


===============================================================================
44. 2D ARRAY
===============================================================================

A 2D array is an array of arrays.

It is commonly used for matrices/tables.

Syntax:

int matrix[3][4];

Meaning:

3 rows
4 columns

Total elements:

3 * 4 = 12


Access:

matrix[row][column]


Indexes:

Rows:
0 to 2

Columns:
0 to 3


===============================================================================
45. 2D ARRAY INITIALIZATION
===============================================================================

Example:

int matrix[2][3] =
{
    {1, 2, 3},
    {4, 5, 6}
};


Representation:

        column
          0  1  2

row 0 ->  1  2  3
row 1 ->  4  5  6


===============================================================================
46. 2D ARRAY INPUT / OUTPUT
===============================================================================

Use nested loops:

for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < cols; j++)
    {
        cin >> matrix[i][j];
    }
}


Printing:

for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < cols; j++)
    {
        cout << matrix[i][j] << " ";
    }

    cout << endl;
}


===============================================================================
47. MATRIX ADDITION
===============================================================================

Two matrices can be added only when they have the same dimensions.

Example:

A + B

Each element:

C[i][j] = A[i][j] + B[i][j]


===============================================================================
48. MATRIX SUBTRACTION
===============================================================================

Same dimension requirement.

C[i][j] = A[i][j] - B[i][j]


===============================================================================
49. MATRIX MULTIPLICATION
===============================================================================

If:

A = m x n

B = n x p

Then:

C = m x p


Formula:

C[i][j] += A[i][k] * B[k][j]


This requires THREE loops.


===============================================================================
50. TRANSPOSE OF MATRIX
===============================================================================

Transpose changes:

rows -> columns
columns -> rows


Example:

1 2 3
4 5 6

Transpose:

1 4
2 5
3 6


Formula:

transpose[j][i] = matrix[i][j]


===============================================================================
51. MATRIX DIAGONALS
===============================================================================

For a square matrix:

Main diagonal:

matrix[i][i]


Example:

1 2 3
4 5 6
7 8 9

Main diagonal:

1
5
9


Secondary diagonal:

matrix[i][n - 1 - i]


Values:

3
5
7


===============================================================================
52. MULTIDIMENSIONAL ARRAYS
===============================================================================

Arrays can have more than two dimensions.

Example:

int arr[2][3][4];


This is a 3D array.

Total elements:

2 * 3 * 4 = 24


Access:

arr[i][j][k]


===============================================================================
53. PASSING ARRAY TO FUNCTION
===============================================================================

Example:

void printArray(int arr[], int n)


Call:

printArray(arr, n);


IMPORTANT:

When a built-in array is passed to a normal function parameter,
the array does not get copied as a whole.

The parameter effectively receives access to the first element
through pointer-like array-to-pointer conversion.


These forms are commonly equivalent for function parameters:

void func(int arr[], int n)

void func(int arr[10], int n)

void func(int* arr, int n)


The actual array size is NOT carried by the pointer parameter.


===============================================================================
54. WHY PASS SIZE SEPARATELY?
===============================================================================

Example:

void printArray(int arr[], int n)


We need n because inside the function:

sizeof(arr)

does NOT give the size of the original array.

Inside the function parameter, arr behaves as a pointer.


Therefore:

printArray(arr, 5);


===============================================================================
55. MODIFYING ARRAY INSIDE FUNCTION
===============================================================================

Because the function receives access to the original array elements,
we can modify them.

Example:

void change(int arr[], int n)
{
    arr[0] = 100;
}


The original array's first element becomes 100.


===============================================================================
56. const ARRAY PARAMETER
===============================================================================

If a function should only READ the array:

void printArray(const int arr[], int n)


Now:

arr[i]

can be read.

But:

arr[i] = 100;

is not allowed inside the function.


This is useful for preventing accidental modification.


===============================================================================
57. CHARACTER ARRAY
===============================================================================

A character array stores characters.

Example:

char letters[5] = {'A', 'B', 'C', 'D', 'E'};


It is an array whose element type is char.


===============================================================================
58. C-STRING
===============================================================================

A C-string is a sequence of characters terminated by:

'\0'

Example:

char name[] = "Vikas";


Memory conceptually:

V  i  k  a  s  \0


The null character marks the end of the C-string.


IMPORTANT:

"Hello"

contains:

H e l l o \0


Therefore a char array used as a C-string needs space for '\0'.


===============================================================================
59. C-STRING FUNCTIONS
===============================================================================

Header:

#include <cstring>


Common functions:

strlen()
    -> length of C-string excluding '\0'

strcpy()
    -> copy C-string

strcmp()
    -> compare C-strings

strcat()
    -> concatenate C-strings


Modern C++ code often prefers std::string for normal string
handling because it manages memory and provides safer/easier APIs.


===============================================================================
60. ARRAY OF STRINGS
===============================================================================

Using std::string:

string names[3] =
{
    "Vikas",
    "Rahul",
    "Aman"
};


This is an array where each element is a std::string.


We can also have:

char names[3][20];


This is a 2D character array where each row can store a
C-string of limited capacity.


===============================================================================
61. std::array
===============================================================================

C++ provides:

std::array

Header:

#include <array>


Example:

array<int, 5> arr = {10, 20, 30, 40, 50};


Unlike a built-in array, std::array is a standard library container
with useful member functions.


===============================================================================
62. IMPORTANT std::array FUNCTIONS
===============================================================================

arr.size()
    -> number of elements

arr.at(index)
    -> access with bounds checking

arr[index]
    -> access without bounds checking

arr.front()
    -> first element

arr.back()
    -> last element

arr.fill(value)
    -> fills all elements with value

arr.begin()
    -> iterator to beginning

arr.end()
    -> iterator past the last element


===============================================================================
63. BUILT-IN ARRAY VS std::array
===============================================================================

Built-in:

int arr[5];


std::array:

array<int, 5> arr;


std::array provides:

- .size()
- .at()
- .front()
- .back()
- .fill()
- iterators
- better integration with STL algorithms


Both have fixed size.


===============================================================================
64. DYNAMIC ARRAY
===============================================================================

A normal built-in array has a fixed size.

Example:

int arr[5];


If we need dynamic allocation:

int* arr = new int[n];


Here memory for n integers is dynamically allocated.


IMPORTANT:

Memory allocated using:

new[]

must be released using:

delete[]


Example:

delete[] arr;


===============================================================================
65. DYNAMIC ARRAY EXAMPLE
===============================================================================

int n;

cin >> n;

int* arr = new int[n];


Use:

arr[i]


After finishing:

delete[] arr;

arr = nullptr;


IMPORTANT:

For modern C++, std::vector is generally preferred over manually
managed dynamic arrays for a resizable collection.


===============================================================================
66. new[] vs delete[]
===============================================================================

If:

int* arr = new int[10];


Then release with:

delete[] arr;


Do NOT use:

delete arr;

for memory allocated using new[].


Correct pair:

new       -> delete
new[]     -> delete[]


===============================================================================
67. COMMON ARRAY MISTAKES
===============================================================================

1. Forgetting zero-based indexing.

Wrong:

arr[size]


2. Using:

i <= size

instead of:

i < size


3. Accessing a negative index.


4. Accessing beyond array bounds.


5. Forgetting to initialize an array when needed.


6. Assuming a built-in array can grow automatically.


7. Trying:

arr1 = arr2;


for built-in arrays.


8. Forgetting the '\0' when manually creating a C-string.


9. Forgetting delete[] for manually allocated dynamic arrays.


10. Using sizeof(array) after the array has decayed to a pointer
    in a function parameter.


===============================================================================
68. ARRAY TIME COMPLEXITY
===============================================================================

Operation                         Typical Complexity

Access by index                  O(1)

Update by index                  O(1)

Traversal                        O(n)

Linear Search                    O(n)

Reverse                          O(n)

Insert at beginning              O(n)

Delete at beginning              O(n)

Bubble Sort                      O(n^2) worst case

Selection Sort                   O(n^2)

Insertion Sort                   O(n^2) worst case

Binary Search                    O(log n)

IMPORTANT:

Binary search requires sorted data and an appropriate access model.


===============================================================================
69. PRACTICAL COMPLETE EXAMPLES
===============================================================================
*/


// --------------------------------------------------------------------
// Function: printArray
// --------------------------------------------------------------------

void printArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}


// --------------------------------------------------------------------
// Function: sumArray
// --------------------------------------------------------------------

int sumArray(const int arr[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}


// --------------------------------------------------------------------
// Function: findMax
// --------------------------------------------------------------------

int findMax(const int arr[], int n)
{
    int maxValue = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
        }
    }

    return maxValue;
}


// --------------------------------------------------------------------
// Function: findMin
// --------------------------------------------------------------------

int findMin(const int arr[], int n)
{
    int minValue = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < minValue)
        {
            minValue = arr[i];
        }
    }

    return minValue;
}


// --------------------------------------------------------------------
// Function: linearSearch
// Returns index if found, otherwise -1.
// --------------------------------------------------------------------

int linearSearch(const int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}


// --------------------------------------------------------------------
// Function: reverseArray
// --------------------------------------------------------------------

void reverseArray(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        swap(arr[left], arr[right]);

        left++;
        right--;
    }
}


// --------------------------------------------------------------------
// Function: bubbleSort
// --------------------------------------------------------------------

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no swap happened, array is already sorted.
        if (!swapped)
        {
            break;
        }
    }
}


// --------------------------------------------------------------------
// Function: insertAt
// Inserts value at index.
// Returns new logical size.
// Assumes enough capacity exists.
// --------------------------------------------------------------------

int insertAt(int arr[], int n, int capacity, int index, int value)
{
    if (n >= capacity)
    {
        return n;
    }

    if (index < 0 || index > n)
    {
        return n;
    }

    for (int i = n; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;

    return n + 1;
}


// --------------------------------------------------------------------
// Function: deleteAt
// Deletes element at index.
// Returns new logical size.
// --------------------------------------------------------------------

int deleteAt(int arr[], int n, int index)
{
    if (index < 0 || index >= n)
    {
        return n;
    }

    for (int i = index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    return n - 1;
}


// --------------------------------------------------------------------
// Function: leftRotateOne
// --------------------------------------------------------------------

void leftRotateOne(int arr[], int n)
{
    if (n <= 1)
    {
        return;
    }

    int first = arr[0];

    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[n - 1] = first;
}


// --------------------------------------------------------------------
// Function: rightRotateOne
// --------------------------------------------------------------------

void rightRotateOne(int arr[], int n)
{
    if (n <= 1)
    {
        return;
    }

    int last = arr[n - 1];

    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = last;
}


// --------------------------------------------------------------------
// Function: countOccurrences
// --------------------------------------------------------------------

int countOccurrences(const int arr[], int n, int target)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            count++;
        }
    }

    return count;
}


/*
===============================================================================
                                MAIN
===============================================================================
*/

int main()
{
    // ========================================================================
    // 1. BASIC ARRAY
    // ========================================================================

    int marks[5] = {80, 75, 90, 65, 88};

    cout << "Original Array: ";

    for (int i = 0; i < 5; i++)
    {
        cout << marks[i] << " ";
    }

    cout << endl;


    // ========================================================================
    // 2. ACCESSING ELEMENTS
    // ========================================================================

    cout << "\nFirst element : " << marks[0] << endl;
    cout << "Last element  : " << marks[4] << endl;


    // ========================================================================
    // 3. MODIFYING ELEMENT
    // ========================================================================

    marks[2] = 95;

    cout << "After modifying index 2: ";

    printArray(marks, 5);


    // ========================================================================
    // 4. sizeof() AND ARRAY SIZE
    // ========================================================================

    int arr[] = {10, 20, 30, 40, 50};

    int numberOfElements =
        sizeof(arr) / sizeof(arr[0]);

    cout << "\nNumber of elements = "
         << numberOfElements << endl;

    cout << "Total bytes = "
         << sizeof(arr) << endl;

    cout << "One element bytes = "
         << sizeof(arr[0]) << endl;


    // ========================================================================
    // 5. ARRAY + POINTER
    // ========================================================================

    cout << "\n--- ARRAY + POINTER ---\n";

    cout << "arr       : " << arr << endl;
    cout << "&arr[0]   : " << &arr[0] << endl;

    cout << "*arr      : " << *arr << endl;

    cout << "arr[2]    : " << arr[2] << endl;
    cout << "*(arr+2)  : " << *(arr + 2) << endl;


    // ========================================================================
    // 6. RANGE-BASED FOR LOOP
    // ========================================================================

    cout << "\nRange-based loop: ";

    for (int value : arr)
    {
        cout << value << " ";
    }

    cout << endl;


    // ========================================================================
    // 7. RANGE-BASED LOOP WITH REFERENCE
    // ========================================================================

    int numbers[] = {1, 2, 3, 4, 5};

    for (int& value : numbers)
    {
        value *= 2;
    }

    cout << "After multiplying by 2: ";

    for (int value : numbers)
    {
        cout << value << " ";
    }

    cout << endl;


    // ========================================================================
    // 8. SUM AND AVERAGE
    // ========================================================================

    int sum = sumArray(arr, numberOfElements);

    double average =
        static_cast<double>(sum) / numberOfElements;

    cout << "\nSum     = " << sum << endl;
    cout << "Average = " << average << endl;


    // ========================================================================
    // 9. MAXIMUM AND MINIMUM
    // ========================================================================

    cout << "\nMaximum = "
         << findMax(arr, numberOfElements) << endl;

    cout << "Minimum = "
         << findMin(arr, numberOfElements) << endl;


    // ========================================================================
    // 10. SEARCH
    // ========================================================================

    int target = 30;

    int index =
        linearSearch(arr, numberOfElements, target);

    if (index != -1)
    {
        cout << "\n" << target
             << " found at index "
             << index << endl;
    }
    else
    {
        cout << "\nElement not found." << endl;
    }


    // ========================================================================
    // 11. COUNT OCCURRENCE
    // ========================================================================

    int duplicateExample[] =
    {
        10, 20, 10, 30, 10, 40
    };

    int frequency =
        countOccurrences(duplicateExample, 6, 10);

    cout << "\nFrequency of 10 = "
         << frequency << endl;


    // ========================================================================
    // 12. REVERSE
    // ========================================================================

    int reverseExample[] =
    {
        1, 2, 3, 4, 5
    };

    reverseArray(reverseExample, 5);

    cout << "\nReversed array: ";

    printArray(reverseExample, 5);


    // ========================================================================
    // 13. COPY ARRAY
    // ========================================================================

    int source[] = {10, 20, 30, 40};
    int destination[4];

    copy(source, source + 4, destination);

    cout << "\nCopied array: ";

    printArray(destination, 4);


    // ========================================================================
    // 14. INSERTION
    // ========================================================================

    int insertArray[10] =
    {
        10, 20, 30, 40
    };

    int insertSize = 4;

    insertSize =
        insertAt(
            insertArray,
            insertSize,
            10,
            2,
            25
        );

    cout << "\nAfter inserting 25 at index 2: ";

    printArray(insertArray, insertSize);


    // ========================================================================
    // 15. DELETION
    // ========================================================================

    insertSize =
        deleteAt(insertArray, insertSize, 3);

    cout << "After deleting index 3: ";

    printArray(insertArray, insertSize);


    // ========================================================================
    // 16. BUBBLE SORT
    // ========================================================================

    int sortExample[] =
    {
        5, 1, 4, 2, 8
    };

    bubbleSort(sortExample, 5);

    cout << "\nBubble sorted array: ";

    printArray(sortExample, 5);


    // ========================================================================
    // 17. std::sort()
    // ========================================================================

    int standardSort[] =
    {
        40, 10, 50, 20, 30
    };

    sort(
        standardSort,
        standardSort + 5
    );

    cout << "\nstd::sort ascending: ";

    printArray(standardSort, 5);

    sort(
        standardSort,
        standardSort + 5,
        greater<int>()
    );

    cout << "std::sort descending: ";

    printArray(standardSort, 5);


    // ========================================================================
    // 18. LEFT ROTATION
    // ========================================================================

    int leftRotation[] =
    {
        1, 2, 3, 4, 5
    };

    leftRotateOne(leftRotation, 5);

    cout << "\nLeft rotation: ";

    printArray(leftRotation, 5);


    // ========================================================================
    // 19. RIGHT ROTATION
    // ========================================================================

    int rightRotation[] =
    {
        1, 2, 3, 4, 5
    };

    rightRotateOne(rightRotation, 5);

    cout << "Right rotation: ";

    printArray(rightRotation, 5);


    // ========================================================================
    // 20. 2D ARRAY
    // ========================================================================

    int matrix[2][3] =
    {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "\n--- 2D ARRAY ---\n";

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }


    // ========================================================================
    // 21. MAIN DIAGONAL
    // ========================================================================

    int squareMatrix[3][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "\nMain diagonal: ";

    for (int i = 0; i < 3; i++)
    {
        cout << squareMatrix[i][i] << " ";
    }

    cout << endl;


    // ========================================================================
    // 22. SECONDARY DIAGONAL
    // ========================================================================

    cout << "Secondary diagonal: ";

    for (int i = 0; i < 3; i++)
    {
        cout << squareMatrix[i][2 - i] << " ";
    }

    cout << endl;


    // ========================================================================
    // 23. MATRIX ADDITION
    // ========================================================================

    int A[2][2] =
    {
        {1, 2},
        {3, 4}
    };

    int B[2][2] =
    {
        {5, 6},
        {7, 8}
    };

    int C[2][2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nMatrix A + B:\n";

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << C[i][j] << " ";
        }

        cout << endl;
    }


    // ========================================================================
    // 24. MATRIX TRANSPOSE
    // ========================================================================

    int original[2][3] =
    {
        {1, 2, 3},
        {4, 5, 6}
    };

    int transpose[3][2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            transpose[j][i] = original[i][j];
        }
    }

    cout << "\nTranspose:\n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << transpose[i][j] << " ";
        }

        cout << endl;
    }


    // ========================================================================
    // 25. CHARACTER ARRAY
    // ========================================================================

    char letters[5] =
    {
        'A', 'B', 'C', 'D', 'E'
    };

    cout << "\nCharacter array: ";

    for (char ch : letters)
    {
        cout << ch << " ";
    }

    cout << endl;


    // ========================================================================
    // 26. C-STRING
    // ========================================================================

    char name[] = "Vikas";

    cout << "\nC-string: "
         << name << endl;

    cout << "Length: "
         << strlen(name) << endl;


    // ========================================================================
    // 27. ARRAY OF STRINGS
    // ========================================================================

    string names[3] =
    {
        "Vikas",
        "Rahul",
        "Aman"
    };

    cout << "\nArray of strings:\n";

    for (string person : names)
    {
        cout << person << endl;
    }


    // ========================================================================
    // 28. std::array
    // ========================================================================

    array<int, 5> standardArray =
    {
        10, 20, 30, 40, 50
    };

    cout << "\n--- std::array ---\n";

    cout << "Size  : "
         << standardArray.size() << endl;

    cout << "First : "
         << standardArray.front() << endl;

    cout << "Last  : "
         << standardArray.back() << endl;

    cout << "at(2): "
         << standardArray.at(2) << endl;


    // fill()
    standardArray.fill(100);

    cout << "After fill(100): ";

    for (int value : standardArray)
    {
        cout << value << " ";
    }

    cout << endl;


    // ========================================================================
    // 29. DYNAMIC ARRAY
    // ========================================================================

    int n = 5;

    int* dynamicArray =
        new int[n];

    for (int i = 0; i < n; i++)
    {
        dynamicArray[i] = (i + 1) * 10;
    }

    cout << "\nDynamic array: ";

    for (int i = 0; i < n; i++)
    {
        cout << dynamicArray[i] << " ";
    }

    cout << endl;

    // Memory allocated using new[] must be released using delete[].

    delete[] dynamicArray;

    dynamicArray = nullptr;


    // ========================================================================
    // 30. POINTER TRAVERSAL
    // ========================================================================

    int pointerArray[] =
    {
        10, 20, 30, 40
    };

    int* ptr = pointerArray;

    cout << "\nPointer traversal: ";

    for (int i = 0; i < 4; i++)
    {
        cout << *(ptr + i) << " ";
    }

    cout << endl;

    return 0;
}