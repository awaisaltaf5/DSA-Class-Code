#include<iostream> // Including input-output stream library
using namespace std;

/**
 * Binary Search Function:
 * - Works on **sorted arrays**.
 * - Uses the **divide and conquer** approach to search for an element.
 * - The search space is repeatedly divided in half until the element is found or the range becomes empty.
 * - If found, it returns the **index** of the element.
 * - If not found, it returns **-1**.
 */
int Binary_Searching(int arr[], int element, int n, int start, int end) {
    while (start <= end) { // Continue searching while search range is valid
        int mid = (start + end) / 2; // Find the middle index
        
        if (arr[mid] == element) { // If element is found at mid, return index
            return mid;
        }
        else if (arr[mid] < element) { // If element is greater, search the right half
            start = mid + 1;
        }
        else { // If element is smaller, search the left half
            end = mid - 1;
        }
    }
    return -1; // Return -1 if element is not found
}

int main() {
    int n = 5; // Define the length of the sorted array
    int arr[5] = {1, 2, 3, 4, 5}; // Sorted array for binary search
    int start = 0; // Start index of the search space
    int end = n - 1; // End index of the search space
    int element; // Variable to store the element to be searched

    cout << "Enter the Element: ";
    cin >> element; // Taking user input for the element to search

    // Call the binary search function and store the result
    int result = Binary_Searching(arr, element, n, start, end);

    // Display the result based on whether the element is found or not
    if (result != -1) {
        cout << "Element is Found at " << result << " Index!"; // Print the index if found
    }
    else {
        cout << "Element is not Present!"; // Print message if element is not found
    }

    return 0; // Return 0 to indicate successful execution
}

/**
 * ================= DRY RUN OF BINARY SEARCH =================
 * Given: arr[] = {1, 2, 3, 4, 5}, element = 4
 * 
 * Step 1:
 * - start = 0, end = 4
 * - mid = (0+4)/2 = 2
 * - arr[mid] = arr[2] = 3
 * - Since 3 < 4, we search in the right half (start = mid+1)
 * 
 * Step 2:
 * - start = 3, end = 4
 * - mid = (3+4)/2 = 3
 * - arr[mid] = arr[3] = 4
 * - Element found at index 3, return 3
 * 
 * ================= DRY RUN OUTPUT =================
 * Enter the Element: 4
 * Element is Found at 3 Index!
 * 
 * ================= DRY RUN FOR ELEMENT NOT PRESENT =================
 * If searching for 6:
 * - start = 0, end = 4
 * - mid = (0+4)/2 = 2 → arr[mid] = 3
 * - 3 < 6, move to right half (start = 3)
 * - mid = (3+4)/2 = 3 → arr[mid] = 4
 * - 4 < 6, move to right half (start = 4)
 * - mid = (4+4)/2 = 4 → arr[mid] = 5
 * - 5 < 6, move to right half (start = 5)
 * - start > end → element not found, return -1
 * 
 * Output:
 * Enter the Element: 6
 * Element is not Present!
 */
