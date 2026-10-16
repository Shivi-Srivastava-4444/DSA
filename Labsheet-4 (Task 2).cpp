#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* top = NULL;
void push(int value) {
    Node* newNode = new Node{value, top};
    top = newNode;
    cout << "Element pushed successfully\n";
}
void pop() {
    if (top == NULL) {
        cout << "Stack Underflow\n";
        return;
    }
    Node* temp = top;
    cout << "Popped element: " << temp->data << endl;
    top = top->next;
    delete temp;
}
void peek() {
    if (top == NULL)
        cout << "Stack is empty\n";
    else
        cout << "Top element: " << top->data << endl;
}
void display() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    int choice, value;
    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Check Empty\n6. Exit\n";
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
                cout << (top == NULL ? "Stack is empty\n" : "Stack is not empty\n");
                break;
            case 6:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 6);
    while (top != NULL) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    return 0;
}
