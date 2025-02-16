#include<iostream>
using namespace std;

int main(){
    // Define the array length
    int length = 5;
    
    // Initialize the array with unsorted elements
    int arr[5] = {2, 3, 1, 4, 5};
    
    // Bubble Sort Algorithm
    // Bubble Sort is a simple sorting algorithm that repeatedly compares adjacent elements 
    // and swaps them if they are in the wrong order.
    // This process continues until the array is sorted.

    // Outer loop to control the number of passes (n-1 passes required)
    for(int i = 0; i < length - 1; i++){
        
        // Inner loop to compare adjacent elements and swap if needed
        for(int j = 0; j < length - i - 1; j++){
            
            // If the current element is greater than the next element, swap them
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    
    // Print the sorted array
    cout << "Sorted Array: ";
    for(int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}

/*
    Explanation of Bubble Sort:

    - Bubble Sort is an in-place sorting algorithm, meaning it sorts the array without using extra memory.
    - It works by repeatedly swapping adjacent elements if they are in the wrong order.
    - After each complete pass, the largest element moves to its correct position.
    - This process continues until all elements are sorted.

    Why do we use Bubble Sort?
    - It is simple and easy to implement.
    - It is useful for small datasets.
    - It is a stable sorting algorithm (does not change the relative order of equal elements).
    - It can be optimized to stop early if the array is already sorted.

    Dry Run of Bubble Sort Algorithm:

    Initial array: [2, 3, 1, 4, 5]

    Pass 1:
    [2, 3, 1, 4, 5] -> [2, 1, 3, 4, 5] (swap 3 and 1)
    [2, 1, 3, 4, 5] -> [2, 1, 3, 4, 5] (no swap needed)
    [2, 1, 3, 4, 5] -> [2, 1, 3, 4, 5] (no swap needed)
    [2, 1, 3, 4, 5] -> [2, 1, 3, 4, 5] (no swap needed)

    Pass 2:
    [2, 1, 3, 4, 5] -> [1, 2, 3, 4, 5] (swap 2 and 1)
    [1, 2, 3, 4, 5] -> [1, 2, 3, 4, 5] (no swap needed)
    [1, 2, 3, 4, 5] -> [1, 2, 3, 4, 5] (no swap needed)

    Pass 3:
    [1, 2, 3, 4, 5] -> [1, 2, 3, 4, 5] (no swap needed)
    [1, 2, 3, 4, 5] -> [1, 2, 3, 4, 5] (no swap needed)

    Pass 4:
    [1, 2, 3, 4, 5] -> [1, 2, 3, 4, 5] (no swap needed)

    Final sorted array: [1, 2, 3, 4, 5]

    Time Complexity:
    - Best Case: O(n) (if the array is already sorted and optimized Bubble Sort is used)
    - Worst Case: O(n^2) (when elements are in reverse order)
    - Average Case: O(n^2)

    Space Complexity: O(1) (since sorting is done in place)
*/
