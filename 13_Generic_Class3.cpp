#include <iostream>
using namespace std;

// 💡 TEMPLATE CLASS: We define a class template that works with different data types.
template <class Type>
class Addition {
private:
    Type a, b;  // 🔹 Two variables of generic type (Type) to hold values.

public:
    // 💡 Constructor: Initializes values of a and b.
    Addition(Type x, Type y) {
        a = x;
        b = y;
    }

    // 💡 Function to perform addition and return the result.
    Type add() {
        return a + b;
    }

    // 💡 Function to display the result of addition.
    void show() {
        cout << "The Addition of " << a << " and " << b << " is " << add() << endl;
    }
};

int main() {
    // 🚀 Creating objects of class template with different data types

    // 🔹 Object of Addition<int> (Works with integers)
    Addition<int> obj1(8, 6); 
    // 🔹 Object of Addition<double> (Works with floating-point numbers)
    Addition<double> obj2(8.2, 6.4);

    // 🖨️ Display results for integer addition
    obj1.show();  // Output: The Addition of 8 and 6 is 14

    // 🖨️ Display results for floating-point addition
    obj2.show();  // Output: The Addition of 8.2 and 6.4 is 14.6

    return 0; // ✅ Successful execution
}
