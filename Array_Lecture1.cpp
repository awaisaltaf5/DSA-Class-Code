#include<iostream>
using namespace std;

int main() {
    // Step 1: Define an array with initial values
    int arr[] = {2, 3, 4, 5};  

    // Step 2: Calculate the length of the array dynamically
    int length = sizeof(arr) / sizeof(arr[0]); // Total size of array / size of one element

    // Step 3: Print the calculated length of the array
    cout << "Length: " << length << endl;

    // Step 4: Loop through the array and print each index and its corresponding element
    for(int i = 0; i < length; i++) {  
        cout << "Array index is " << i << " and Array element is " << arr[i] << endl;
    }

    return 0;  // End of the program
}
