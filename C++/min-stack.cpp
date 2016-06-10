// Time:  O(n)
// Space: O(1)

class MinStack {
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        if (elements_.empty()) {
            elements_.emplace(0);
            stack_min_ = number;
        } else {
            elements_.emplace(static_cast<int64_t>(number) - stack_min_);
            if (number < stack_min_) {
                stack_min_ = number; // Update min.
            }
        }
    }

    int pop() {
        auto diff = elements_.top();
        elements_.pop();
        if (diff < 0) {
            stack_min_ -= diff; // Restore previous min.
        }
        return stack_min_ + diff;
    }

    int min() {
        return stack_min_;
    }

private:
    stack<int64_t> elements_;
    int stack_min_;
};

// Time:  O(n)
// Space: O(n)
class MinStack2 {
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        if (cached_min_with_count_.empty() || cached_min_with_count_.top().first > number) {
            cached_min_with_count_.emplace(number, 1);
        } else if (cached_min_with_count_.top().first == number) {
            ++cached_min_with_count_.top().second;
        }
        elements_.emplace(number);
    }

    int pop() {
        if (cached_min_with_count_.top().first == elements_.top()) {
            if (--cached_min_with_count_.top().second == 0) {
                cached_min_with_count_.pop();
            }
        }
        auto number = elements_.top();
        elements_.pop();
        return number;
    }

    int min() {
        return cached_min_with_count_.top().first;
    }
private:
    stack<int> elements_;
    stack<pair<int, int>> cached_min_with_count_;
};


// Time:  O(n)
// Space: O(n)
class MinStack3 {
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        if (cached_min_.empty() || cached_min_.top() >= number) {
            cached_min_.emplace(number);
        }
        elements_.emplace(number);
    }

    int pop() {
        if (cached_min_.top() == elements_.top()) {
            cached_min_.pop();
        }
        auto number = elements_.top();
        elements_.pop();
        return number;
    }

    int min() {
        return cached_min_.top();
    }
private:
    stack<int> elements_;
    stack<int> cached_min_;
};

