#include <iostream>
#include <string>
using namespace std;

// Practical 7 - Problem 2: Hospital Emergency Ward (Unlimited Queue using Linked List)
class PatientNode {
public:
    string patientName;
    int patientId;
    PatientNode* next;

    PatientNode(int id, string name) {
        patientId = id;
        patientName = name;
        next = NULL;
    }
};

class EmergencyWardQueue {
private:
    PatientNode* front;
    PatientNode* rear;
    int totalPatients;

public:
    EmergencyWardQueue() {
        front = rear = NULL;
        totalPatients = 0;
    }

    ~EmergencyWardQueue() {
        while (!isEmpty()) {
            PatientNode* temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return front == NULL;
    }

    // New patient arrives at the back of the queue (Enqueue)
    void arrivePatient(int id, const string& name) {
        PatientNode* newPatient = new PatientNode(id, name);
        if (rear == NULL) {
            front = rear = newPatient;
        } else {
            rear->next = newPatient;
            rear = newPatient;
        }
        totalPatients++;
        cout << "Patient Registered -> ID: " << id << " (" << name << ") joined the emergency line." << endl;
        displayFront();
    }

    // Doctor attends the patient at the front (Dequeue)
    void attendPatient() {
        if (isEmpty()) {
            cout << "Warning: Emergency ward is empty! No patients waiting to be attended." << endl;
            return;
        }
        PatientNode* temp = front;
        cout << "Doctor is now attending: " << temp->patientName << " (ID: " << temp->patientId << ")" << endl;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
        totalPatients--;
        displayFront();
    }

    // Display the next patient in line
    void displayFront() {
        if (isEmpty()) {
            cout << "Current Status: No patient currently at front. Ward is clear." << endl;
        } else {
            cout << "-> Next Patient to be Attended: " << front->patientName << " (ID: " << front->patientId << ")" << endl;
        }
    }

    // Display entire list of waiting patients
    void displayAllWaiting() {
        if (isEmpty()) {
            cout << "Emergency ward has no waiting patients." << endl;
            return;
        }
        cout << "\n--- Currently Waiting Patients in Emergency Ward ---" << endl;
        PatientNode* curr = front;
        int pos = 1;
        while (curr != NULL) {
            cout << pos++ << ". [ID: " << curr->patientId << "] " << curr->patientName;
            if (curr == front) cout << " <- NEXT";
            cout << endl;
            curr = curr->next;
        }
        cout << "Total waiting patients: " << totalPatients << endl;
    }
};

int main() {
    EmergencyWardQueue ward;
    int choice;
    int id;
    string name;

    cout << "===== Practical 7 - Problem 2: Hospital Emergency Ward Queue =====" << endl;

    do {
        cout << "\n--- Emergency Ward Operations ---" << endl;
        cout << "1. Patient Arrival (Enqueue)" << endl;
        cout << "2. Doctor Attends Patient (Dequeue)" << endl;
        cout << "3. View Next Patient at Front" << endl;
        cout << "4. Display All Waiting Patients" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Patient ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Patient Name: ";
                getline(cin, name);
                ward.arrivePatient(id, name);
                break;
            case 2:
                ward.attendPatient();
                break;
            case 3:
                ward.displayFront();
                break;
            case 4:
                ward.displayAllWaiting();
                break;
            case 5:
                cout << "Exiting hospital emergency ward system." << endl;
                break;
            default:
                cout << "Invalid choice! Please select 1-5." << endl;
        }
    } while (choice != 5);

    return 0;
}
