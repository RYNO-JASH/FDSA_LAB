#include <iostream>
using namespace std;

// Practical 7 - Problem 1: Government Office Token Counter (Circular Queue using Array)
class CircularTokenQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    CircularTokenQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~CircularTokenQueue() {
        delete[] arr;
    }

    bool isFull() {
        return count == capacity;
    }

    bool isEmpty() {
        return count == 0;
    }

    // Join queue (Enqueue)
    void joinToken(int tokenId) {
        if (isFull()) {
            cout << "Error: Token counter is FULL! Cannot issue token " << tokenId << " (Queue Overflow)." << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = tokenId;
        count++;
        cout << "Visitor with Token ID " << tokenId << " joined the queue." << endl;
        displayFront();
    }

    // Serve visitor (Dequeue)
    void serveVisitor() {
        if (isEmpty()) {
            cout << "Error: No visitors waiting! Cannot serve (Queue Underflow)." << endl;
            return;
        }
        int servedToken = arr[front];
        front = (front + 1) % capacity;
        count--;
        cout << "Visitor with Token ID " << servedToken << " has been served." << endl;
        displayFront();
    }

    // Display current front token
    void displayFront() {
        if (isEmpty()) {
            cout << "Current Status: Queue is empty. No visitor at the front." << endl;
        } else {
            cout << "Current Front Token to be served: " << arr[front] << endl;
        }
    }

    // Display all tokens waiting in queue
    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is currently empty." << endl;
            return;
        }
        cout << "Waiting Tokens (Front to Rear): ";
        for (int i = 0; i < count; i++) {
            int idx = (front + i) % capacity;
            cout << arr[idx] << " ";
        }
        cout << " [Total: " << count << "/" << capacity << "]" << endl;
    }
};

int main() {
    int n;
    cout << "===== Practical 7 - Problem 1: Government Office Token System =====" << endl;
    cout << "Enter maximum token counter capacity (n): ";
    cin >> n;

    CircularTokenQueue queue(n);
    int choice, tokenId;

    do {
        cout << "\n--- Token Counter Menu ---" << endl;
        cout << "1. Issue Token / Visitor Join (Enqueue)" << endl;
        cout << "2. Serve Visitor (Dequeue)" << endl;
        cout << "3. View Current Front Token" << endl;
        cout << "4. Display All Waiting Tokens" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Token ID: ";
                cin >> tokenId;
                queue.joinToken(tokenId);
                break;
            case 2:
                queue.serveVisitor();
                break;
            case 3:
                queue.displayFront();
                break;
            case 4:
                queue.displayQueue();
                break;
            case 5:
                cout << "Exiting token counter system." << endl;
                break;
            default:
                cout << "Invalid choice! Please select 1-5." << endl;
        }
    } while (choice != 5);

    return 0;
}
