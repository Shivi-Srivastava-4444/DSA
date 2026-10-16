#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
int main() {
    Node *head = NULL, *temp = NULL;
    int n, value, count = 0;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        Node* newNode = new Node{value, NULL};
        if (head == NULL)
            head = temp = newNode;
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    cout << "Linked List: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        count++;
        temp = temp->next;
    }
    cout << "\nTotal nodes = " << count;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
