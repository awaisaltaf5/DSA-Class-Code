#include<iostream>
using namespace std;

int main() {
    int length = 5; 
    int arr[5] = {2, 3, 1, 4, 5};

    // Selection Sort Algorithm (Sorting in Ascending Order)
    // Outer loop runs from 0 to length-2 (as last element gets sorted automatically)
    for (int i = 0; i < length - 1; i++) {
        // Inner loop to find the minimum element in the unsorted part
        for (int j = i + 1; j < length; j++) {
            // If the current element is greater than the next element, swap them
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }

    // Printing the sorted array
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

/* 
    Dry Run of the Selection Sort Algorithm:
    
    Initial array: {2, 3, 1, 4, 5}
    
    Step 1: i = 0
    Compare arr[0] with arr[1] → 2 < 3 (No swap)
    Compare arr[0] with arr[2] → 2 > 1 (Swap 2 and 1)
    Compare arr[0] with arr[3] → 1 < 4 (No swap)
    Compare arr[0] with arr[4] → 1 < 5 (No swap)
    Array after step 1: {1, 3, 2, 4, 5}

    Step 2: i = 1
    Compare arr[1] with arr[2] → 3 > 2 (Swap 3 and 2)
    Compare arr[1] with arr[3] → 2 < 4 (No swap)
    Compare arr[1] with arr[4] → 2 < 5 (No swap)
    Array after step 2: {1, 2, 3, 4, 5}

    Step 3: i = 2
    Compare arr[2] with arr[3] → 3 < 4 (No swap)
    Compare arr[2] with arr[4] → 3 < 5 (No swap)
    Array after step 3: {1, 2, 3, 4, 5}

    Step 4: i = 3
    Compare arr[3] with arr[4] → 4 < 5 (No swap)
    Array after step 4: {1, 2, 3, 4, 5}

    Final sorted array: {1, 2, 3, 4, 5}
*/
