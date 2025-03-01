#include <iostream>
using namespace std;

int main() {
    // Declaring an integer variable
    int num = 10;
    
    // Declaring a pointer that will store the address of 'num'
    int* ptr;
    
    // Storing the address of 'num' in pointer 'ptr'
    ptr = &num;
    
    // Printing the value of 'num' using normal variable
    cout << "Value of num: " << num << endl;
    
    // Printing the value of 'num' using pointer (dereferencing)
    cout << "Value of num using pointer: " << *ptr << endl;
    
    // Printing the address of 'num' using '&' operator
    cout << "Address of num: " << &num << endl;
    
    // Printing the address stored in pointer 'ptr'
    cout << "Address stored in pointer ptr: " << ptr << endl;
    
    // Changing the value of 'num' using pointer
    *ptr = 20;
    cout << "New value of num after changing using pointer: " << num << endl;
    
    return 0;
}
