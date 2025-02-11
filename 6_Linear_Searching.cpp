#include<iostream>  // Including the input-output stream library
using namespace std; // Using the standard namespace

int main() {
    int length = 5; // Defining the size of the array
    int arr[5] = {1, 2, 3, 4, 5}; // Initializing the array with values

    int element; // Variable to store the element to be searched
    cin >> element; // Taking input from the user

    int found = 0; // Flag to check if the element is found
    int i = 0; // Index variable

    // Linear search: Iterating through the array
    while (i < length) {
        if (arr[i] == element) { // If the element is found
            found++; // Set found flag
            break; // Exit loop as we found the element
        } else {
            i++; // Move to the next element
        }
    }

    // Output the result based on search
    if (found > 0) {
        cout << "\nArray element is present at " << i << " Index!"; // Element found at index i
    } else {
        cout << "\nArray element is not present!"; // Element not found in the array
    }

    return 0; // Return 0 to indicate successful execution
}

/*
📝 Linear Search Algorithm:
- Linear search is a simple searching algorithm that sequentially checks each element in the array.
- If a match is found, it returns the index of the element.
- If the element is not found, it indicates that the element is absent.
- This algorithm works with both sorted and unsorted arrays.
- Time Complexity: O(n) (Worst and Average Case)
- Space Complexity: O(1) (In-place search, no extra space required)

🔹 Key Points:
- Best case: O(1) (if the element is at the first position)
- Worst case: O(n) (if the element is at the last position or not present)
- Used for small datasets or when the array is unsorted.

📌 Use cases:
- Searching an element in small datasets.
- When data is not sorted.
- When the dataset is dynamically changing.
*/
