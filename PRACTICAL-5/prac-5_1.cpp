#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int val)
        {
            data = val;
            next = NULL;
            prev = NULL;
        }
};

class DLL
{
    Node* head;
    Node* tail;

    public:
        DLL()
        {
            head = tail = NULL;
        }

        void push_front(int val)
        {
            Node* newNode = new Node(val);

            if(head == NULL)
            {
                head = tail = newNode;
                return;
            }
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        void push_back(int val)
        {
            Node* newNode = new Node(val);

            if(head == NULL)
            {
                head = tail = newNode;
                return;
            }
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        void insert_after(int song, int val)
        {
            Node* temp = head;

            while(temp != NULL && temp->data != song)
            {
                temp = temp->next;
            }

            if(temp == NULL)
            {
                cout << "Song " << song << " not found." << endl;
                return;
            }

            Node* newNode = new Node(val);

            if(temp == tail)
            {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
                return;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }

        void pop_front()
        {
            if(head == NULL)
            {
                cout << "Playlist is empty." << endl;
                return;
            }

            Node* temp = head;

            if(head == tail)
            {
                head = tail = NULL;
                delete temp;
                return;
            }

            head = head->next;
            head->prev = NULL;

            delete temp;
        }

        int count()
        {
            int cnt = 0;
            Node* temp = head;

            while(temp != NULL)
            {
                cnt++;
                temp = temp->next;
            }
            return cnt;
        }

        void print()
        {
            Node* temp = head;
            cout << "Playlist: ";

            while(temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
            cout << "Number of songs: " << count() << endl;
        }
};

int main()
{
    DLL playlist;

    cout << "Add 10 at beginning:" << endl;
    playlist.push_front(10);
    playlist.print();

    cout << "\nAdd 20 at end:" << endl;
    playlist.push_back(20);
    playlist.print();

    cout << "\nAdd 30 at end:" << endl;
    playlist.push_back(30);
    playlist.print();

    cout << "\nInsert 25 after 20:" << endl;
    playlist.insert_after(20, 25);
    playlist.print();

    cout << "\nInsert 15 after 10:" << endl;
    playlist.insert_after(10, 15);
    playlist.print();

    cout << "\nRemove first song:" << endl;
    playlist.pop_front();
    playlist.print();

    cout << "\nTry inserting after 100:" << endl;
    playlist.insert_after(100, 50);
    playlist.print();

    return 0;
}