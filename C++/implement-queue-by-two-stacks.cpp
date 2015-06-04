// Time:  O(1), amortized
// Space: O(n)

class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        stack1.emplace(element);
    }

    int pop() {
        int element = top();
        stack2.pop();
        return element;
    }

    int top() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.emplace(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }
};

