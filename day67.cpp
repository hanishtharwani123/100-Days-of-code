// 67. Min Stack
#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** Initialize your data structure here. */
    MinStack() {

    }

    /** Push element x onto the stack. */
    void push(int val) {
        // Push the element onto the main stack
        mainStack.push(val);

        // Check if the minStack is empty or if the new element is smaller than the current minimum
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    /** Removes the element on the top of the stack. */
    void pop() {
        // If the top element of the main stack is the same as the top element of the minStack (minimum),
        // pop the top element from the minStack as well.
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }

        // Pop the top element from the main stack.
        mainStack.pop();
    }

    /** Get the top element of the stack. */
    int top() {
        return mainStack.top();
    }

    /** Retrieve the minimum element in the stack. */
    int getMin() {
        return minStack.top();
    }

private:
    stack<int> mainStack;
    stack<int> minStack;
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << "Minimum element: " << minStack.getMin() << endl; // Output: -3

    minStack.pop();

    cout << "Top element: " << minStack.top() << endl;    // Output: 0

    cout << "Minimum element: " << minStack.getMin() << endl; // Output: -2

    return 0;
}
