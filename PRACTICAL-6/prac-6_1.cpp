#include <iostream>
#include <vector>
using namespace std;

// Practical 6 - Problem 1: Cafeteria Fixed-Size Tray Stack using Array
class TrayStack {
private:
    int* arr;
    int topIndex;
    int capacity;

public:
    TrayStack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    ~TrayStack() {
        delete[] arr;
    }

    bool isFull() {
        return topIndex == capacity - 1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    // Place a tray on top
    void placeTray(int trayId) {
        if (isFull()) {
            cout << "Error: Tray counter is FULL! Cannot place tray " << trayId << " (Overflow)." << endl;
            return;
        }
        arr[++topIndex] = trayId;
        cout << "Successfully placed tray ID " << trayId << " on top." << endl;
        displayTop();
    }

    // Take a tray from top
    void takeTray() {
        if (isEmpty()) {
            cout << "Error: Tray counter is EMPTY! No tray to take (Underflow)." << endl;
            return;
        }
        int removed = arr[topIndex--];
        cout << "Customer took tray ID " << removed << " from top." << endl;
        displayTop();
    }

    // Display current top tray
    void displayTop() {
        if (isEmpty()) {
            cout << "Current Status: Counter is empty (No top tray)." << endl;
        } else {
            cout << "Current Top Tray ID: " << arr[topIndex] << endl;
        }
    }

    // Display all trays currently on counter
    void displayAll() {
        if (isEmpty()) {
            cout << "Counter is empty." << endl;
            return;
        }
        cout << "Trays on counter (Top to Bottom): ";
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "===== Practical 6 - Problem 1: Cafeteria Tray Stack =====" << endl;
    cout << "Enter maximum capacity of tray counter (n): ";
    cin >> n;

    TrayStack stack(n);
    int choice, trayId;

    do {
        cout << "\n--- Cafeteria Tray Operations ---" << endl;
        cout << "1. Place Tray (Push)" << endl;
        cout << "2. Take Tray (Pop)" << endl;
        cout << "3. View Current Top Tray (Peek)" << endl;
        cout << "4. Display All Trays" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Tray ID to place: ";
                cin >> trayId;
                stack.placeTray(trayId);
                break;
            case 2:
                stack.takeTray();
                break;
            case 3:
                stack.displayTop();
                break;
            case 4:
                stack.displayAll();
                break;
            case 5:
                cout << "Exiting cafeteria tray management system." << endl;
                break;
            default:
                cout << "Invalid choice! Please select 1-5." << endl;
        }
    } while (choice != 5);

    return 0;
}
