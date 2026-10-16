#include <iostream>
using namespace std;

/* Task 1: Array Traversal */
void traversal(int arr[], int n) {
    int sum = 0;
    cout << "Array elements and indices:\n";
    for (int i = 0; i < n; i++) {
        cout << "Index " << i << ": " << arr[i] << endl;
        sum += arr[i];
    }
    cout << "Sum = " << sum << endl;
    cout << "Average = " << (double)sum / n << endl;
}

/* Task 2: Array Insertion */
void insertElement(int arr[], int &n, int position, int value) {
    if (position < 0 || position > n || n >= 100) {
        cout << "Invalid index or array is full\n";
        return;
    }
    for (int i = n; i > position; i--)
        arr[i] = arr[i - 1];
    arr[position] = value;
    n++;
    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/* Task 3: Array Deletion */
void deleteElement(int arr[], int &n, int position) {
    if (n == 0 || position < 0 || position >= n) {
        cout << "Invalid index or array is empty\n";
        return;
    }
    for (int i = position; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
    cout << "Array after deletion: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/* Task 4: Searching */
void linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i << endl;
            return;
        }
    }
    cout << "Element not found\n";
}

/* Task 4: Bubble Sort */
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/* Task 5: Menu-Driven Array Operations */
int main() {
    int arr[100], n, choice, position, value, key;
    cout << "Enter number of elements (1-100): ";
    cin >> n;
    if (n < 1 || n > 100) {
        cout << "Invalid array size\n";
        return 0;
    }
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    do {
        cout << "\n1. Display Array\n2. Insert at Beginning\n3. Insert at End\n4. Insert at Index\n";
        cout << "5. Delete from Beginning\n6. Delete from End\n7. Delete at Index\n";
        cout << "8. Linear Search\n9. Bubble Sort\n10. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                traversal(arr, n);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertElement(arr, n, 0, value);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                insertElement(arr, n, n, value);
                break;
            case 4:
                cout << "Enter index and value: ";
                cin >> position >> value;
                insertElement(arr, n, position, value);
                break;
            case 5:
                deleteElement(arr, n, 0);
                break;
            case 6:
                deleteElement(arr, n, n - 1);
                break;
            case 7:
                cout << "Enter index: ";
                cin >> position;
                deleteElement(arr, n, position);
                break;
            case 8:
                cout << "Enter element to search: ";
                cin >> key;
                linearSearch(arr, n, key);
                break;
            case 9:
                bubbleSort(arr, n);
                break;
            case 10:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 10);
    return 0;
}
