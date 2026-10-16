#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void insertBeginning(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, NULL};
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void insertPosition(Node*& head, int value, int position) {
    if (position < 0) {
        cout << "Invalid position\n";
        return;
    }
    if (position == 0) {
        insertBeginning(head, value);
        return;
    }
    Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Invalid position\n";
        return;
    }
    Node* newNode = new Node{value, temp->next};
    temp->next = newNode;
}
int main() {
    Node* head = NULL;
    int n, value, position, choice;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertEnd(head, value);
    }
    cout << "1. Insert at beginning\n2. Insert at end\n3. Insert at position\n";
    cin >> choice;
    cout << "Enter value: ";
    cin >> value;
    if (choice == 1)
        insertBeginning(head, value);
    else if (choice == 2)
        insertEnd(head, value);
    else if (choice == 3) {
        cout << "Enter position (0-based): ";
        cin >> position;
        insertPosition(head, value, position);
    } else
        cout << "Invalid choice\n";
    cout << "Linked List: ";
    display(head);
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
