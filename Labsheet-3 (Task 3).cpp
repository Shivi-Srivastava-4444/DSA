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
void deleteBeginning(Node*& head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}
void deleteEnd(Node*& head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}
void deletePosition(Node*& head, int position) {
    if (position < 0 || head == NULL) {
        cout << "Invalid position or empty list\n";
        return;
    }
    if (position == 0) {
        deleteBeginning(head);
        return;
    }
    Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position\n";
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}
int main() {
    Node* head = NULL;
    int n, value, position, choice;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        Node* newNode = new Node{value, NULL};
        if (head == NULL)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    cout << "Original list: ";
    display(head);
    cout << "1. Delete beginning\n2. Delete end\n3. Delete at position\n";
    cin >> choice;
    if (choice == 1)
        deleteBeginning(head);
    else if (choice == 2)
        deleteEnd(head);
    else if (choice == 3) {
        cout << "Enter position (0-based): ";
        cin >> position;
        deletePosition(head, position);
    } else
        cout << "Invalid choice\n";
    cout << "Updated list: ";
    display(head);
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
