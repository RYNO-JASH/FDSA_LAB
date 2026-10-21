#include <iostream>
#include <vector>
using namespace std;

// Practical 10 - Problem 2: Library Shelving System using Separate Chaining
const int NUM_SHELVES = 10;

class BookNode {
public:
    int bookCode;
    BookNode* next;

    BookNode(int code) {
        bookCode = code;
        next = NULL;
    }
};

class LibraryShelves {
private:
    BookNode* shelves[NUM_SHELVES];
    int totalBooks;

public:
    LibraryShelves() {
        totalBooks = 0;
        for (int i = 0; i < NUM_SHELVES; i++) {
            shelves[i] = NULL;
        }
    }

    ~LibraryShelves() {
        for (int i = 0; i < NUM_SHELVES; i++) {
            BookNode* curr = shelves[i];
            while (curr != NULL) {
                BookNode* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
    }

    // Hash function: book code % 10
    int hashFunction(int bookCode) {
        return bookCode % NUM_SHELVES;
    }

    // Place book on the shelf (Separate Chaining: append / stack)
    void placeBook(int bookCode) {
        int shelfIndex = hashFunction(bookCode);
        BookNode* newBook = new BookNode(bookCode);

        // Prepend to shelf chain (or append)
        newBook->next = shelves[shelfIndex];
        shelves[shelfIndex] = newBook;
        totalBooks++;

        cout << "Book " << bookCode << " placed on Shelf " << shelfIndex;
        if (newBook->next != NULL) {
            cout << " (Chain length at this shelf: stacked with existing books)";
        }
        cout << "." << endl;
    }

    // Display final contents of all shelves
    void displayShelves() {
        cout << "\n==============================================" << endl;
        cout << "        FINAL LIBRARY SHELVES CONTENTS        " << endl;
        cout << "==============================================" << endl;
        for (int i = 0; i < NUM_SHELVES; i++) {
            cout << "Shelf [" << i << "]: ";
            if (shelves[i] == NULL) {
                cout << "[Empty]";
            } else {
                BookNode* curr = shelves[i];
                while (curr != NULL) {
                    cout << curr->bookCode;
                    if (curr->next != NULL) cout << " -> ";
                    curr = curr->next;
                }
            }
            cout << endl;
        }
        cout << "==============================================" << endl;
        cout << "Total books categorized across shelves: " << totalBooks << endl;
    }
};

int main() {
    LibraryShelves library;
    int n;

    cout << "===== Practical 10 - Problem 2: Library Shelves (Separate Chaining) =====" << endl;
    cout << "Enter number of books arriving: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int code;
        cout << "Enter Book Code " << (i + 1) << ": ";
        cin >> code;
        library.placeBook(code);
    }

    library.displayShelves();
    return 0;
}
