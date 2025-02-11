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
