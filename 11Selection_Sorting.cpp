#include <iostream>
using namespace std;

int main()
{
    int length = 5;
    int arr[5] = {2, 3, 1, 4, 5};

    // Selection Sort Algorithm (Sorting in Ascending Order)
    // Selection Sort is a simple sorting algorithm that works by repeatedly selecting
    // the smallest (or largest) element from the unsorted part and moving it to the correct position.
    // It has a time complexity of O(n^2) in all cases, which makes it inefficient for large datasets.

    // Outer loop runs from 0 to length-2 (as the last element gets sorted automatically)
    for (int i = 0; i < length - 1; i++)
    {
        // Inner loop to find the minimum element in the unsorted part
        for (int j = i + 1; j < length; j++)
        {
            // If the current element is greater than the next element, swap them
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }

    // Printing the sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
    Explanation of Selection Sort:

    - Selection Sort is an in-place sorting algorithm, meaning it does not require extra memory.
    - It works by dividing the array into two parts: sorted and unsorted.
    - In each iteration, it finds the smallest element from the unsorted part and places it in the sorted part.
    - The process continues until all elements are sorted.

    Why do we use Selection Sort?
    - It is simple and easy to implement.
    - It is useful when working with small datasets.
    - It performs well when the cost of swapping elements is low.
    - Unlike Bubble Sort, it minimizes the number of swaps.

    Dry Run of Selection Sort:

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

    Time Complexity:
    - Best Case: O(n^2) (Even if the array is already sorted)
    - Worst Case: O(n^2) (When elements are in reverse order)
    - Average Case: O(n^2)

    Space Complexity: O(1) (Since sorting is done in place)
*/
