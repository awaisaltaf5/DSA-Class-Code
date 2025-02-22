#include <iostream>
using namespace std;

// Function to perform Insertion Sort on the given array
int insertion_Sort(int arr[], int length)
{
    // Loop to traverse each element starting from the second element (index 1)
    for (int i = 1; i < length; i++)
    {
        // Store the current element (key) to compare and insert it in the correct position
        int key = arr[i];
        // Variable to hold the index of the previous element for comparison
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than the key, one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // Shift the element to the right
            j = j - 1; // Move the comparison index backwards
        }

        // Place the key (current element) at the correct position
        arr[j + 1] = key;
    }
}

// Main function to drive the program
int main()
{
    int length = 5; // Length of the array
    int arr[5] = {2, 3, 4, 1, 5}; // Initial unsorted array

    cout << "Unsorted Array:\n";
    // Print the unsorted array
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }

    // Call the insertion sort function to sort the array
    insertion_Sort(arr, length);

    cout << "\nSorted Array:\n";
    // Print the sorted array
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
Dry Run:

Initial Array: {2, 3, 4, 1, 5}

1. First iteration (i = 1, key = 3):
   - Compare arr[0] (2) with key (3).
   - Since 2 < 3, no shift happens.
   - Array after iteration 1: {2, 3, 4, 1, 5}

2. Second iteration (i = 2, key = 4):
   - Compare arr[1] (3) with key (4).
   - Since 3 < 4, no shift happens.
   - Array after iteration 2: {2, 3, 4, 1, 5}

3. Third iteration (i = 3, key = 1):
   - Compare arr[2] (4) with key (1). Since 4 > 1, shift 4 to the right.
   - Compare arr[1] (3) with key (1). Since 3 > 1, shift 3 to the right.
   - Compare arr[0] (2) with key (1). Since 2 > 1, shift 2 to the right.
   - Insert key (1) at position arr[0].
   - Array after iteration 3: {1, 2, 3, 4, 5}

4. Fourth iteration (i = 4, key = 5):
   - Compare arr[3] (4) with key (5).
   - Since 4 < 5, no shift happens.
   - Array after iteration 4: {1, 2, 3, 4, 5}

Final Sorted Array: {1, 2, 3, 4, 5}
*/
