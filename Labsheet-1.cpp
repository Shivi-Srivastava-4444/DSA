#include <iostream>
using namespace std;

/* Q1(a). Display Welcome Message */

int main() {
    cout << "Welcome to Data Structures Lab" << endl;
    cout << "Course Code : BTCS209P" << endl;
    return 0;
}

/* Q1(b). Arithmetic Operations */

int main1() {
    int a, b;
    cin >> a >> b;
    cout << "Sum = " << a + b << endl;
    cout << "Difference = " << a - b << endl;
    cout << "Product = " << a * b << endl;
    if (b != 0) {
        cout << "Quotient = " << a / b << endl;
        cout << "Remainder = " << a % b << endl;
    }
    return 0;
}

/* Q2(a). Even or Odd */

int main2() {
    int n;
    cin >> n;
    if (n % 2 == 0)
        cout << "Even";
    else
        cout << "Odd";
    return 0;
}

/* Q2(b). Largest Among Three Numbers */

int main3() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a >= b && a >= c)
        cout << "Largest = " << a;
    else if (b >= a && b >= c)
        cout << "Largest = " << b;
    else
        cout << "Largest = " << c;
    return 0;
}

/* Q2(c). Leap Year */

int main4() {
    int year;
    cin >> year;
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        cout << "Leap Year";
    else
        cout << "Not a Leap Year";
    return 0;
}

/* Q3(a). Print Numbers from 1 to 100 */

int main5() {
    for (int i = 1; i <= 100; i++)
        cout << i << " ";
    return 0;
}

/* Q3(b). Multiplication Table */

int main6() {
    int n;
    cin >> n;
    for (int i = 1; i <= 10; i++)
        cout << n << " x " << i << " = " << n * i << endl;
    return 0;
}

/* Q3(c). Factorial Using While Loop */

int main7() {
    int n, i = 1;
    unsigned long long fact = 1;
    cin >> n;
    if (n < 0) {
        cout << "Factorial is not defined";
        return 0;
    }
    while (i <= n) {
        fact *= i;
        i++;
    }
    cout << "Factorial = " << fact;
    return 0;
}

/* Q3(d). Fibonacci Series */

int main8() {
    int n, a = 0, b = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << a << " ";
        int c = a + b;
        a = b;
        b = c;
    }
    return 0;
}

/* Q4(a). Square Using Function */

int square(int n) {
    return n * n;
}

int main9() {
    int n;
    cin >> n;
    cout << "Square = " << square(n);
    return 0;
}

/* Q4(b). Maximum Using Function */

int maximum(int a, int b) {
    return (a > b) ? a : b;
}

int main10() {
    int a, b;
    cin >> a >> b;
    cout << "Maximum = " << maximum(a, b);
    return 0;
}

/* Q4(c). Prime Number Using Function */

bool isPrime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main11() {
    int n;
    cin >> n;
    if (isPrime(n))
        cout << "Prime Number";
    else
        cout << "Not a Prime Number";
    return 0;
}

/* Q5(a). Read and Display Array */

int main12() {
    int arr[10];
    for (int i = 0; i < 10; i++)
        cin >> arr[i];
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    return 0;
}

/* Q5(b). Largest and Smallest in Array */

int main13() {
    int arr[10];
    for (int i = 0; i < 10; i++)
        cin >> arr[i];
    int largest = arr[0], smallest = arr[0];
    for (int i = 1; i < 10; i++) {
        if (arr[i] > largest)
            largest = arr[i];
        if (arr[i] < smallest)
            smallest = arr[i];
    }
    cout << "Largest = " << largest << endl;
    cout << "Smallest = " << smallest;
    return 0;
}

/* Q5(c). Sum and Average of Array */

int main14() {
    int arr[10], sum = 0;
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << "Sum = " << sum << endl;
    cout << "Average = " << sum / 10.0;
    return 0;
}

/* Q5(d). Linear Search */

int main15() {
    int arr[10], key, position = -1;
    for (int i = 0; i < 10; i++)
        cin >> arr[i];
    cin >> key;
    for (int i = 0; i < 10; i++) {
        if (arr[i] == key) {
            position = i;
            break;
        }
    }
    if (position != -1)
        cout << "Element found at position " << position + 1;
    else
        cout << "Element not found";
    return 0;
}
