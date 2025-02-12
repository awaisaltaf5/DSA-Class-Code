#include<iostream>
using namespace std;

int main(){
    // Define the array length
    int length = 5;
    
    // Initialize the array with unsorted elements
    int arr[5] = {2, 3, 1, 4, 5};
    
    // Bubble Sort Algorithm
    // Outer loop to control the number of passes
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
    for(int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}

/*
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
*/
