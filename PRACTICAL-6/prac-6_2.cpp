#include <iostream>
#include <string>
using namespace std;

// Practical 6 - Problem 2: Unlimited Web Browser Page History using Linked List Stack
class PageNode {
public:
    string url;
    PageNode* next;

    PageNode(string pageUrl) {
        url = pageUrl;
        next = NULL;
    }
};

class BrowserHistory {
private:
    PageNode* top;
    int historyCount;

public:
    BrowserHistory() {
        top = NULL;
        historyCount = 0;
    }

    ~BrowserHistory() {
        while (!isEmpty()) {
            PageNode* temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return top == NULL;
    }

    // Visit a new web page (Push operation)
    void visitPage(const string& url) {
        PageNode* newNode = new PageNode(url);
        newNode->next = top;
        top = newNode;
        historyCount++;
        cout << "Visited: " << url << endl;
        displayCurrentPage();
    }

    // Press Back button (Pop operation)
    void pressBack() {
        if (isEmpty()) {
            cout << "Notice: No history available to go back to!" << endl;
            return;
        }

        // If only 1 page is in history, user is on the very first page
        if (top->next == NULL) {
            cout << "Already on the initial/first page (" << top->url << "). Cannot go back further!" << endl;
            return;
        }

        PageNode* temp = top;
        cout << "Navigating back from: " << temp->url << endl;
        top = top->next;
        delete temp;
        historyCount--;
        displayCurrentPage();
    }

    // View current active page
    void displayCurrentPage() {
        if (isEmpty()) {
            cout << "Browser is currently on blank start page." << endl;
        } else {
            cout << "-> Current Page: " << top->url << endl;
        }
    }

    // Display full browsing history (Top to Bottom)
    void displayFullHistory() {
        if (isEmpty()) {
            cout << "History is empty." << endl;
            return;
        }
        cout << "\n--- Full Browsing History (Most Recent First) ---" << endl;
        PageNode* curr = top;
        int step = 1;
        while (curr != NULL) {
            cout << step++ << ". " << curr->url;
            if (curr == top) cout << " (Current)";
            cout << endl;
            curr = curr->next;
        }
        cout << "Total pages in history: " << historyCount << endl;
    }
};

int main() {
    BrowserHistory browser;
    int choice;
    string url;

    cout << "===== Practical 6 - Problem 2: Web Browser History Management =====" << endl;

    do {
        cout << "\n--- Browser Operations ---" << endl;
        cout << "1. Visit New Page" << endl;
        cout << "2. Press Back Button" << endl;
        cout << "3. View Current Page" << endl;
        cout << "4. View Full Browsing History" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter website URL (e.g., google.com): ";
                cin >> url;
                browser.visitPage(url);
                break;
            case 2:
                browser.pressBack();
                break;
            case 3:
                browser.displayCurrentPage();
                break;
            case 4:
                browser.displayFullHistory();
                break;
            case 5:
                cout << "Closing browser session." << endl;
                break;
            default:
                cout << "Invalid choice! Please select 1-5." << endl;
        }
    } while (choice != 5);

    return 0;
}
