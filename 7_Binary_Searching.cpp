#include<iostream>  // Including the input-output stream library
using namespace std; // Using the standard namespace

int main() {
    int found = 0;  // Flag to check if element is found
    int mid;  // Variable to store the middle index
    int n = 5;  // Defining the size of the array
    int arr[5] = {1, 2, 3, 4, 5};  // Sorted array (Binary search requires sorted data)
    int start = 0;  // Starting index
    int end = n - 1;  // Ending index
    int element;  // Variable to store the element to be searched

    cout << "Enter element to search: ";
    cin >> element;  // Taking input from the user

    // Binary Search Algorithm: Works only on sorted arrays
    while (start <= end) {
        mid = (start + end) / 2;  // Finding the middle index
        
        if (arr[mid] == element) {  // If the middle element matches the search element
            found++;  // Set found flag
            break;  // Exit loop as we found the element
        }
        else if (arr[mid] < element) {  // If element is greater, search in the right half
            start = mid + 1;
        }
        else if (arr[mid] > element) {  // If element is smaller, search in the left half
            end = mid - 1;
        }
    }

    // Output the result based on search
    if (found > 0) {
        cout << "\nArray element is present at " << mid << " Index!";  // Element found at mid index
    } else {
        cout << "\nArray element is not present!";  // Element not found in the array
    }

    return 0;  // Return 0 to indicate successful execution
}

/*
📝 Binary Search Algorithm:
- Binary search is an efficient searching algorithm that works on sorted arrays.
- It divides the search space into two halves and eliminates half of the elements in each step.
- If the element is found at the middle index, return it.
- Otherwise, decide whether to search in the left or right half based on comparison.

🔹 Key Concepts:
- Works only on **sorted arrays**.
- It uses **divide and conquer** strategy.
- Reduces the search space **by half** in each iteration.

🔹 Time Complexity:
- **Best Case:** O(1) (If the middle element is the target)
- **Average & Worst Case:** O(log n) (Since search space is divided by 2 each time)

🔹 Space Complexity:
- **O(1)** (Iterative approach, no extra space used)

📌 Use Cases:
- When the dataset is large and sorted.
- Faster than linear search, especially for large datasets.
- Used in searching algorithms for databases, dictionaries, and libraries.

✅ Comparison with Linear Search:
- **Linear Search:** O(n), checks elements one by one.
- **Binary Search:** O(log n), eliminates half of the search space each time.

---

### 📝 Dry Run of the Binary Search:

Let’s walk through a dry run of the binary search with the array `{1, 2, 3, 4, 5}` and search for element `4`.

#### 1st Iteration:
- `start = 0`, `end = 4`
- `mid = (0 + 4) / 2 = 2`
- `arr[mid] = arr[2] = 3`
- Since `arr[mid] < element`, the search continues in the right half.
- Update: `start = mid + 1 = 3`

#### 2nd Iteration:
- `start = 3`, `end = 4`
- `mid = (3 + 4) / 2 = 3`
- `arr[mid] = arr[3] = 4`
- `arr[mid] == element`, element found at index `3`.

**Result**: The element `4` is found at index `3`.

---

Let’s walk through a dry run with the element `6` (which is not present in the array).

#### 1st Iteration:
- `start = 0`, `end = 4`
- `mid = (0 + 4) / 2 = 2`
- `arr[mid] = arr[2] = 3`
- Since `arr[mid] < element`, the search continues in the right half.
- Update: `start = mid + 1 = 3`

#### 2nd Iteration:
- `start = 3`, `end = 4`
- `mid = (3 + 4) / 2 = 3`
- `arr[mid] = arr[3] = 4`
- Since `arr[mid] < element`, the search continues in the right half.
- Update: `start = mid + 1 = 4`

#### 3rd Iteration:
- `start = 4`, `end = 4`
- `mid = (4 + 4) / 2 = 4`
- `arr[mid] = arr[4] = 5`
- Since `arr[mid] < element`, the search continues in the right half.
- Update: `start = mid + 1 = 5`

At this point, `start = 5` and `end = 4`, so the loop ends and the element `6` is not found.

**Result**: The element `6` is not present in the array.
*/
