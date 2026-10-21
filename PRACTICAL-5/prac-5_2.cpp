#include<iostream>
using namespace std;

class SNode
{
public:
    int data;
    SNode* next;

    SNode(int val)
    {
        data = val;
        next = NULL;
    }
};

class SCLL
{
    SNode* head;
    SNode* tail;

public:
    SCLL()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        SNode* n = new SNode(val);

        if(head == NULL)
        {
            head = tail = n;
            n->next = head;
            return;
        }

        n->next = head;
        head = n;
        tail->next = head;
    }

    void push_back(int val)
    {
        SNode* n = new SNode(val);

        if(head == NULL)
        {
            head = tail = n;
            n->next = head;
            return;
        }

        tail->next = n;
        tail = n;
        tail->next = head;
    }

    void remove(int val)
    {
        if(head == NULL) return;

        SNode* temp = head;
        SNode* prev = tail;

        do
        {
            if(temp->data == val) break;
            prev = temp;
            temp = temp->next;
        } while(temp != head);

        if(temp->data != val) return;

        if(head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            if(temp == head)
                head = head->next;
            else
                prev->next = temp->next;

            if(temp == tail)
                tail = prev;

            tail->next = head;
        }

        delete temp;
    }

    void display()
    {
        if(head == NULL)
        {
            cout << "Empty\n";
            return;
        }

        SNode* temp = head;

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != head);

        cout << endl;
    }
};

class DNode
{
public:
    int data;
    DNode* next;
    DNode* prev;

    DNode(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

class DCLL
{
    DNode* head;
    DNode* tail;

public:
    DCLL()
    {
        head = tail = NULL;
    }

    void push_back(int val)
    {
        DNode* n = new DNode(val);

        if(head == NULL)
        {
            head = tail = n;
            n->next = n;
            n->prev = n;
            return;
        }

        n->prev = tail;
        n->next = head;
        tail->next = n;
        head->prev = n;
        tail = n;
    }

    void remove(int val)
    {
        if(head == NULL) return;

        DNode* temp = head;

        do
        {
            if(temp->data == val) break;
            temp = temp->next;
        } while(temp != head);

        if(temp->data != val) return;

        if(head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            if(temp == head)
                head = temp->next;

            if(temp == tail)
                tail = temp->prev;
        }

        delete temp;
    }

    void display()
    {
        if(head == NULL)
        {
            cout << "Empty\n";
            return;
        }

        DNode* temp = head;

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != head);

        cout << endl;
    }
};

int main()
{
    SCLL s;
    DCLL d;

    s.push_back(1);
    s.push_back(2);
    s.push_front(3);
    s.display();

    s.remove(2);
    s.display();

    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.display();

    d.remove(2);
    d.display();

    return 0;
}