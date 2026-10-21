#include <iostream>
#include <vector>
using namespace std;

// Practical 10 - Problem 1: Parking Lot Allocation using Linear Probing
const int TABLE_SIZE = 10;

class ParkingLot {
private:
    int slots[TABLE_SIZE];
    bool occupied[TABLE_SIZE];
    int totalVehicles;

public:
    ParkingLot() {
        totalVehicles = 0;
        for (int i = 0; i < TABLE_SIZE; i++) {
            slots[i] = -1;
            occupied[i] = false;
        }
    }

    // Hash function: last digit of vehicle registration number
    int hashFunction(int regNo) {
        return regNo % TABLE_SIZE;
    }

    // Insert vehicle using Linear Probing
    bool parkVehicle(int regNo) {
        if (totalVehicles == TABLE_SIZE) {
            cout << "Parking Lot is COMPLETELY FULL! Cannot park vehicle " << regNo << "." << endl;
            return false;
        }

        int initialSlot = hashFunction(regNo);
        int slot = initialSlot;

        // Linear probing: check slot, slot+1, slot+2, ... mod 10
        while (occupied[slot]) {
            slot = (slot + 1) % TABLE_SIZE;
        }

        slots[slot] = regNo;
        occupied[slot] = true;
        totalVehicles++;

        if (slot == initialSlot) {
            cout << "Vehicle " << regNo << " assigned to preferred Slot " << slot << "." << endl;
        } else {
            cout << "Collision at Slot " << initialSlot << "! Vehicle " << regNo << " probed to Slot " << slot << "." << endl;
        }
        return true;
    }

    // Display final parking lot state
    void displayState() {
        cout << "\n==========================================" << endl;
        cout << "       FINAL PARKING LOT STATE (0 - 9)    " << endl;
        cout << "==========================================" << endl;
        cout << "Slot #\tStatus\t\tVehicle Registration" << endl;
        cout << "------------------------------------------" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "  " << i << "\t";
            if (occupied[i]) {
                cout << "[Occupied]\t" << slots[i];
            } else {
                cout << "[Empty]\t\t---";
            }
            cout << endl;
        }
        cout << "==========================================" << endl;
        cout << "Total parked vehicles: " << totalVehicles << "/" << TABLE_SIZE << endl;
    }
};

int main() {
    ParkingLot lot;
    int n;

    cout << "===== Practical 10 - Problem 1: Parking Lot (Linear Probing) =====" << endl;
    cout << "Enter number of vehicles arriving: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int reg;
        cout << "Enter registration number of Vehicle " << (i + 1) << ": ";
        cin >> reg;
        lot.parkVehicle(reg);
    }

    lot.displayState();
    return 0;
}
