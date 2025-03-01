#include <iostream>
using namespace std;

// Template class definition
template <class T>  // Declaring a template with a placeholder type 'T'
class MyClass {
private:
    T var;  // Variable of generic type 'T'

public:
    // Constructor to initialize the variable
    MyClass(T arg) {
        var = arg;
    }

    // Function to return the stored value
    T getVar() {
        return var;
    }

    // Function to display the value
    void display() {
        cout << "Value: " << var << endl;
    }
};

int main() {
    // Creating an object of MyClass with 'int' type
    MyClass<int> obj1(10);  // T will be replaced by 'int'
    obj1.display();  // Output: Value: 10

    // Creating an object of MyClass with 'double' type
    MyClass<double> obj2(15.5);  // T will be replaced by 'double'
    obj2.display();  // Output: Value: 15.5

    // Creating an object of MyClass with 'string' type
    MyClass<string> obj3("Hello, Templates!");  // T will be replaced by 'string'
    obj3.display();  // Output: Value: Hello, Templates!

    return 0;
}
