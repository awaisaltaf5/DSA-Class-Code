#include <iostream> // Including iostream for input-output operations
using namespace std;

int main() {
    // Step 1: Define the initial length of the array (before insertion)
    int initial_length = 5;

    // Step 2: Declare an array with a size of 6 (extra space for insertion)
    int arr[6] = {1, 4, 5, 6, 7}; // Last position is empty for new insertion

    // Step 3: Define the position where the new element will be inserted
    int position = 3;  // Inserting at the 3rd position (1-based index)

    // Step 4: Define the new element to be inserted
    int element = 2;

    // Step 5: Shift elements to the right starting from the last filled index
    for (int i = initial_length; i >= position; i--) {
        arr[i] = arr[i - 1];  // Move each element one step right
    }

    // Step 6: Insert the new element at the desired position
    arr[position - 1] = element; // Adjusted for 0-based indexing

    // Step 7: Display the updated array
    cout << "Array After Insertion at Specific Position:\n";
    for (int i = 0; i <= initial_length; i++) { // Loop to print all elements
        cout << arr[i] << endl;
    }

    return 0; // End of the program
}
