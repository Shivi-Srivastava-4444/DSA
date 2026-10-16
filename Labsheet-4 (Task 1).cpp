#include <iostream>
using namespace std;
#define MAX 100
int stackArr[MAX], top = -1;
void push(int value) {
    if (top == MAX - 1)
        cout << "Stack Overflow\n";
    else {
        stackArr[++top] = value;
        cout << "Element pushed successfully\n";
    }
}
void pop() {
    if (top == -1)
        cout << "Stack Underflow\n";
    else
        cout << "Popped element: " << stackArr[top--] << endl;
}
void peek() {
    if (top == -1)
        cout << "Stack is empty\n";
    else
        cout << "Top element: " << stackArr[top] << endl;
}
void display() {
    if (top == -1) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--)
        cout << stackArr[i] << " ";
    cout << endl;
}
int main() {
    int choice, value;
    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Check Empty\n6. Check Full\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << (top == -1 ? "Stack is empty\n" : "Stack is not empty\n");
                break;
            case 6:
                cout << (top == MAX - 1 ? "Stack is full\n" : "Stack is not full\n");
                break;
            case 7:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 7);
    return 0;
}
