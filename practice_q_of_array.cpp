#include <iostream>

using namespace std;

void printArr(int *arr , int n ) {
    for (int i = 0 ; i < n ; i++) {
        cout << arr[i] << " " ;
    }
    cout << endl ; 
}


int linearSearch(int * arr , int n , int key ) {
    for (int i = 0 ; i < n ; i++) {
        if (arr[i] == key) {
            return i ;
        } 
    }
    return -1 ;
}


int BinarySearch (int *arr , int n , int key) {
    int start = 0 ; 
    int end = n-1 ;
     while (start <= end) {
        int mid = (start + end) / 2 ;
        
        if (arr[mid] == key) {
            return mid ; // Key found
        } else if (arr[mid] < key) { // 2nd half
            start = mid + 1 ;
        } else { // 1st half
            end = mid - 1 ;
        }
     }
     return -1 ;
}


int main()
{
// Large and small array

int arr[] = { 1, 43, 415, 32, 98, 1003} ;
int len = sizeof(arr)/sizeof(arr[0]) ;
int max = arr[0] ; 
int min = arr[0] ;

for (int i = 0 ; i < len ; i++) {
    if (arr[i] > max) {
        max = arr[i] ;
    }

    if (arr[i] < min) {
        min = arr[i] ;
    }
}

cout << "Largest : " << max << endl ;
cout << "Smallest : " << min << endl ;


// Linear Search

int arr[] = {43, 34, 9, 4, 90, 39, 2} ;
int n = sizeof(arr)/sizeof(arr[0]) ; 

int x = linearSearch(arr , n , 309) ;

cout << x << endl ;


// Reverse an array
//(With extra space)

int arr[] = {5, 4, 3, 2, 1} ;
int n = sizeof(arr) / sizeof(arr[0]) ;

int copyArr[n] ;
for (int i = 0 ; i < n ; i++) {
    int j = n-i-1 ;
    copyArr[i] = arr[j] ;
}

for (int i = 0 ; i < n ; i++) {
    arr[i] = copyArr[i] ;
}

printArr(arr , n) ;

// (Without extra space)
// Two pointer Approach

int arr[] = {5, 3, 64, 3, 0} ;
int n = sizeof(arr) / sizeof (arr[0]) ;

int start = 0 , end = n-1; 

while (start < end) {
    // swap
    int temp = arr[start] ;
    arr[start] = arr[end] ;
    arr[end] = temp ;

    // there is a inbuilt function in c++ to swap elements in an array
    swap(arr[start] , arr[end]) ;

    start++ ;
    end-- ;
}

printArr(arr , n) ;


// Binary Search 

int arr[] = {21, 22, 43, 45, 57, 67, 78, 89, 90} ;
int n = sizeof(arr) / sizeof(arr[0]) ;

int result = BinarySearch(arr, n, 89) ;
cout << result << endl ;


    return 0;

}