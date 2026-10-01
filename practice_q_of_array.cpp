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


void maxProfit(int *prices , int n) {
    int bestBuy[100000] ;
    bestBuy[0] = INT32_MAX ;
    for(int i = 1 ; i < n ; i++) {
        bestBuy[i] = min(bestBuy[i-1] , prices[i-1]) ;
    }

    int maxProfit = 0 ;
    for(int i = 0 ; i < n ; i++) {
        int currProfit = prices[i] - bestBuy[i] ;
        maxProfit = max(currProfit , maxProfit) ;
    }

    cout << "The max Profit : " << maxProfit << endl ;
}


void watertrap(int *heights , int n ) {
    int leftmax[20000] , rightmax[20000] ;
    leftmax[0] = heights[0] ;
    rightmax[n-1] = heights[n-1] ;

    for(int i=1 ; i<n ; i++ ) {
        leftmax[i] = max(heights[i-1] , leftmax[i-1]) ;
    }

    for(int i= n-2 ; i>=0 ; i--) {
        rightmax[i] = max(heights[i+1] , rightmax[i+1]) ; 
    }

    int watertrap = 0 ;
    for (int i=0 ; i<n ; i++) {
        int currtrap = min(leftmax[i] , rightmax[i]) - heights[i] ;

        if (currtrap > 0) {
            watertrap += currtrap ;
        }
    }
    cout << "Water Trap : " << watertrap << endl ;
}


bool IsDublicat (int * value , int n ) {
    for (int i=0 ; i < n ; i++) {
        for (int j=0 ; j<n ; j++) {
            if(i==j) {
                continue;
            }

            if(value[i] == value[j]) {
                return true ;
            }
        }
    }
    return false ;
}


int findTar(int *arr , int n , int target) {
    for(int i=0 ; i < n ; i++) {
        if (target == arr[i]) {
            return i ;
        } else if (target == arr[n-i-1]) {
            return n-i-1 ;
        }
    }
    return -1 ; 
}


double ProductSubarray(int *arr , int n) {

    double product = INT32_MIN ;

    for(int start = 0 ; start < n ; start++) {
        
        for(int end=start ; end < n ; end++) {
            
            double currproduct = 1 ;
            for(int i=start ; i<=end ; i++) {
                
                currproduct *= arr[i] ;
                
            }
            product = max(product , currproduct) ;  
        }
    }
    if (product >= 0) {
        return product ;
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

int result = BinarySearch(arr, n, 89) ; // Time complexity : O(log n) and Space complexity : O(1)
cout << result << endl ;

// Buy and Sell stocks

int prices[] = {8, 4, 2, 5, 9, 3, 0 , 2, 6} ;
int n = sizeof(prices) / sizeof(int) ;

maxProfit(prices , n) ; // Time complexity : O(n) and Space complexity : O(n)

// Traping Rainwater

int height[] = {4, 2, 0, 6, 3, 2, 5} ;
int n = sizeof(height) / sizeof(int) ;

watertrap(height , n) ; // Time complexity : O(n) and Space complexity : O(n)

// Given an integer array nums, return true if any value appears at least
// twice in the array, and return false if every element is distinct.
// Examples :
// Input: nums = [1,2,3,4]
// Output: false
// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true

    int num [] = {1, 3, 4, 5} ;
    int n = sizeof(num) / sizeof(int) ;

    cout << IsDublicat(num , n) << endl ; // Time complexity : O(n^2) and Space complexity : O(1)

    
// There is an integer array nums sorted in ascending order (with distinct
// values).
// Prior to being passed to your function, nums is possibly rotated at an unknown pivot
// index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ...,
// nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7]
// might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
// Given the array nums after the possible rotation and an integer target, return the
// index of target if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.
// Examples :
// Input: nums = [4,5,6,7,0,1,2], target = 0Output:
// 4
// Input: nums = [4,5,6,7,0,1,2], target = 3Output: -
// 1

int arr[] = {4, 5, 6, 7, 1, 2, 3} ;  // Time complexity : O(n) and Space complexity : O(1)
int n = sizeof(arr) / sizeof(int) ;

cout << findTar(arr, n , 6) ;


// Given an integer array nums, find a subarray that has the largest
// product, and return the product. The test cases are generated so that the answer will
// fit in a 32-bit integer.
// Note - This Qs might feel difficult as a beginner because it uses DP approach.
// Examples :
// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Input: intervals =nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

int num[] = {2, -3, 5, 6, 7} ;
int n = sizeof(num) / sizeof(int) ;

cout << ProductSubarray(num , n) ; // Time complexity : O(n^3) and Space complexity : O(1)

    return 0;

}