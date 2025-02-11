#include<iostream>
using namespace std;

int main() {
    // Step 1: Define an initial array with 5 elements
    int initial_length = 5;
    int arr[5] = {2, 3, 4, 5, 6};  // Sample array

    // Step 2: Define the position to delete (1-based index)
    int position = 3;  // Deleting the 3rd element (which is '4' in this case)

    // Step 3: Shift elements to the left from the deletion position
    for(int i = position; i < initial_length; i++) {
        arr[i - 1] = arr[i];  // Overwrite the deleted element by shifting left
    }

    // Step 4: Reduce the length of the array after deletion
    initial_length--;

    // Step 5: Display the updated array after deletion
    cout << "Array after deletion of 1 element:\n";
    for(int j = 0; j < initial_length; j++) {  // Loop through updated array
        cout << arr[j] << " ";  // Print each element
    }
    cout << endl;  // Newline for better readability

    return 0;  // End of program
}
