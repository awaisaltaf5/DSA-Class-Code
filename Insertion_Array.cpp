#include <iostream> // Including the iostream library for input-output operations
using namespace std;

int main()
{
    // Step 1: Define the array with a fixed size
    int initial_length = 6; 

    // Step 2: Declare an array with 6 elements but initialize only 5
    int arr[initial_length] = {2, 3, 4, 5, 6}; 

    // Step 3: Display the existing elements before insertion
    cout << "Elements without Insertion:\n";
    for (int i = 0; i < initial_length - 1; i++)  // Loop through first 5 elements
    {
        cout << arr[i] << endl; // Print each element
    }

    // Step 4: Inserting a new element at the last position
    cout << "Array Elements after Insertion of 1 Element:\n";
    int element = 71; // New element to be inserted

    arr[initial_length - 1] = element; // Inserting element at index 5 (last index)

    // Step 5: Display the array after insertion
    for (int j = 0; j < initial_length; j++) // Loop through all 6 elements
    {
        cout << arr[j] << endl; // Print each element (including the inserted one)
    }

    return 0; // End of the program
}
