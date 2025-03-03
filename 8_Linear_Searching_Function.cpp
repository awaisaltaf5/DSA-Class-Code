#include<iostream> // Including the input-output stream library
using namespace std;

/**
 * Linear Search Function:
 * - This function iterates through the array and checks if the given element exists.
 * - If the element is found, it returns the index where it was found.
 * - If the element is not found, it returns -1.
 */
int linear_Searching(int arr[], int element, int length) {
    for (int i = 0; i < length; i++) { // Loop through each element in the array
        if (arr[i] == element) { // Check if the current element matches the searched element
            return i; // Return the index if the element is found
        }
    }
    return -1; // Return -1 if the element is not found in the array
}

int main() {
    int length = 5; // Define the length of the array
    int arr[5] = {1, 2, 3, 4, 5}; // Initialize the array with 5 elements

    int element; // Variable to store the element to be searched
    cout << "Enter the Element: ";
    cin >> element; // Taking user input for the element to search

    // Call the linear search function and store the result
    int result = linear_Searching(arr, element, length);

// Display the result based on whether the element is found or not
    if (result != -1) {
        cout << "Element is Found at " << result << " Index!"; // Print the index if found
    } else {
        cout << "Element is not Present!"; // Print message if element is not found
    }

    return 0; // Return 0 to indicate successful execution
}
// Dry run for linear search
    // Let's say the input element is 4:
    // 1. Start the loop at i = 0:
    //    arr[0] = 1, check if 1 == 4 (no), continue to the next index.
    // 2. Now, i = 1:
    //    arr[1] = 2, check if 2 == 4 (no), continue to the next index.
    // 3. Now, i = 2:
    //    arr[2] = 3, check if 3 == 4 (no), continue to the next index.
    // 4. Now, i = 3:
    //    arr[3] = 4, check if 4 == 4 (yes), return index 3.
    //    Element is found at index 3.

    // Another example: If the element is 6:
    // 1. Start the loop at i = 0:
    //    arr[0] = 1, check if 1 == 6 (no), continue to the next index.
    // 2. Now, i = 1:
    //    arr[1] = 2, check if 2 == 6 (no), continue to the next index.
    // 3. Now, i = 2:
    //    arr[2] = 3, check if 3 == 6 (no), continue to the next index.
    // 4. Now, i = 3:
    //    arr[3] = 4, check if 4 == 6 (no), continue to the next index.
    // 5. Now, i = 4:
    //    arr[4] = 5, check if 5 == 6 (no), exit the loop.
    //    Since we have reached the end of the array and the element was not found, return -1.