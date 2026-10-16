#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n, value, key, count = 0, position = 0;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        Node* newNode = new Node{value, NULL};
        if (head == NULL)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    cout << "Enter element to search: ";
    cin >> key;
    Node* temp = head;
    bool found = false;
    while (temp != NULL) {
        count++;
        if (temp->data == key) {
            cout << "Element found at position " << position << endl;
            found = true;
        }
        temp = temp->next;
        position++;
    }
    if (!found)
        cout << "Element not found\n";
    cout << "Total nodes = " << count << endl;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
