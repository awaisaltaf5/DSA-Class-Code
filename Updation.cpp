#include<iostream>
using namespace std;

int main(){
    // Initializing an array with elements
    int arr[]={2,3,6,7};

    // Calculating the length of the array
    int length = sizeof(arr) / sizeof(arr[0]);

    // Defining the position (1-based index) where the new element should be placed
    int position = 4; // 4th position in the array (1-based indexing)

    // New element to be placed at the specified position
    int element = 8;

    // Updating the element at the given position (convert 1-based index to 0-based)
    arr[position - 1] = element;

    // Displaying the updated array
    cout << "Array after updation:\n";
    for(int i = 0; i < length; i++){
        cout << arr[i] << endl;
    }

    return 0;
}
