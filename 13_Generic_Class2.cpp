#include <iostream>
using namespace std;

// Template class definition
template <class T>  // 'T' is a placeholder for a data type
class MyClass {
private:
    T var;  // Generic variable of type T

public:
    // Constructor to initialize 'var'
    MyClass(T arg) {
        var = arg;
    }

    // Function to display the value of 'var'
    void display() {
        cout << "Value: " << var << endl;
    }
};

int main() {
    // Creating a class template object with int type
    MyClass<int> obj1(42);
    obj1.display();  // Output: Value: 42

    // Creating a class template object with float type
    MyClass<float> obj2(3.14);
    obj2.display();  // Output: Value: 3.14

    // Creating a class template object with string type
    MyClass<string> obj3("Hello, Templates!");
    obj3.display();  // Output: Value: Hello, Templates!

    return 0;
}
