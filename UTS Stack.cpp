#include <iostream>

class Stack {
private:
    int top;
    int capacity;
    int* array;
public:
    Stack(int capacity) : top(-1), capacity(capacity) {
        array = new int[capacity];
    }

    ~Stack() {
        delete[] array;
    }

    void push(int value) {
        if (top == capacity - 1) {
            std::cout << "Stack overflow. Cannot push " << value << std::endl;
            return;
        }
        array[++top] = value;
    }

    void pop() {
        if (top == -1) {
            std::cout << "Stack underflow. Cannot pop." << std::endl;
            return;
        }
        --top;
    }

    int peek() {
        if (top == -1) {
            std::cout << "Stack is empty. Cannot peek." << std::endl;
            return -1;
        }
        return array[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void printStack() {
        for (int i = 0; i <= top; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    std::cout << "Elements of the stack are: ";
    stack.printStack();

    std::cout << "Top element is: " << stack.peek() << std::endl;

    stack.pop();

    std::cout << "Elements of the stack are: ";
    stack.printStack();

    return 0;
}
