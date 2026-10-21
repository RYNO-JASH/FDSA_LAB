#include <iostream>
#include <vector>
using namespace std;

// Practical 10 - Problem 3: University Storage Slot Allocation using Double Hashing
const int TABLE_SIZE = 10;

class UniversityStorage {
private:
    int slots[TABLE_SIZE];
    bool occupied[TABLE_SIZE];
    int totalAssigned;

public:
    UniversityStorage() {
        totalAssigned = 0;
        for (int i = 0; i < TABLE_SIZE; i++) {
            slots[i] = -1;
            occupied[i] = false;
        }
    }

    // Rule 1 (Primary Hash): determines initial slot
    int hash1(int studentId) {
        return studentId % TABLE_SIZE;
    }

    // Rule 2 (Secondary Hash): determines jump / step size
    // Must yield a non-zero jump to guarantee progress
    int hash2(int studentId) {
        return 7 - (studentId % 7); // Generates jump sizes from 1 to 7
    }

    // Assign slot using Double Hashing: probe(i) = (hash1(id) + i * hash2(id)) % TABLE_SIZE
    bool assignSlot(int studentId) {
        if (totalAssigned == TABLE_SIZE) {
            cout << "Storage slots are COMPLETELY FULL! Cannot assign ID " << studentId << "." << endl;
            return false;
        }

        int h1 = hash1(studentId);
        int step = hash2(studentId);
        int slot = h1;
        int probeCount = 0;

        while (occupied[slot] && probeCount < TABLE_SIZE) {
            cout << "   Collision at Slot " << slot << " for Student ID " << studentId 
                 << " -> Jumping by " << step << " slots." << endl;
            probeCount++;
            slot = (h1 + probeCount * step) % TABLE_SIZE;
        }

        if (probeCount == TABLE_SIZE) {
            cout << "Error: Unable to find an open slot for Student ID " << studentId 
                 << " within " << TABLE_SIZE << " probes." << endl;
            return false;
        }

        slots[slot] = studentId;
        occupied[slot] = true;
        totalAssigned++;

        if (probeCount == 0) {
            cout << "Student ID " << studentId << " directly assigned to Slot " << slot << "." << endl;
        } else {
            cout << "Student ID " << studentId << " assigned to Slot " << slot 
                 << " after " << probeCount << " probe(s)." << endl;
        }
        return true;
    }

    // Display final storage slots
    void displayTable() {
        cout << "\n==============================================" << endl;
        cout << "      FINAL UNIVERSITY STORAGE SLOTS STATE    " << endl;
        cout << "==============================================" << endl;
        cout << "Slot #\tStatus\t\tAssigned Student ID" << endl;
        cout << "----------------------------------------------" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "  " << i << "\t";
            if (occupied[i]) {
                cout << "[Occupied]\t" << slots[i];
            } else {
                cout << "[Empty]\t\t---";
            }
            cout << endl;
        }
        cout << "==============================================" << endl;
        cout << "Total slots occupied: " << totalAssigned << "/" << TABLE_SIZE << endl;
    }
};

int main() {
    UniversityStorage storage;
    int n;

    cout << "===== Practical 10 - Problem 3: University Storage (Double Hashing) =====" << endl;
    cout << "Enter number of student IDs to assign: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int id;
        cout << "Enter Student ID " << (i + 1) << ": ";
        cin >> id;
        storage.assignSlot(id);
    }

    storage.displayTable();
    return 0;
}
