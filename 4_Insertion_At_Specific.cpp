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

/*
📝 Dry Run of the Array Insertion:

### Initial Array:
`arr[6] = {1, 4, 5, 6, 7}` (size = 6, but only 5 elements are filled)

### Goal:
- Insert the element `2` at the 3rd position (1-based index).
- The array should look like: `{1, 4, 2, 5, 6, 7}` after insertion.

---

### Step-by-Step Execution:

#### Step 1: Initial Setup
- `arr[6] = {1, 4, 5, 6, 7}` (initial array with 5 elements).
- `position = 3` (we need to insert at the 3rd position, 1-based index).
- `element = 2` (the value to insert).

#### Step 2: Shifting Elements (Shifting to the right)

**Initial array:** `{1, 4, 5, 6, 7}`

- **Iteration 1 (i = 5):**
  - Shift element `arr[4]` to `arr[5]`. Now, `arr = {1, 4, 5, 6, 7, 7}`.
  
- **Iteration 2 (i = 4):**
  - Shift element `arr[3]` to `arr[4]`. Now, `arr = {1, 4, 5, 6, 6, 7}`.
  
- **Iteration 3 (i = 3):**
  - Shift element `arr[2]` to `arr[3]`. Now, `arr = {1, 4, 5, 5, 6, 7}`.
  
- **Iteration 4 (i = 2):**
  - Shift element `arr[1]` to `arr[2]`. Now, `arr = {1, 4, 4, 5, 6, 7}`.

Now, the array looks like `{1, 4, 4, 5, 6, 7}`. The space at index 2 is ready to receive the new element.

#### Step 3: Inserting the New Element
- Insert `element = 2` at `arr[position - 1] = arr[2 - 1] = arr[2]`. Now, `arr = {1, 4, 2, 5, 6, 7}`.

#### Step 4: Final Array
- The final array after insertion is: `{1, 4, 2, 5, 6, 7}`.

### Final Output:

