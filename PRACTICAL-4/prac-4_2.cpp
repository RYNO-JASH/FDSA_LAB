#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val)
        {
            data=val;
            next=NULL;
        }
};
class LL{
    Node* head;
    Node* tail;
    public:
        LL(){head=tail=NULL;}
        void push_front(int val)
        {
            Node* newNode=new Node(val);
            if(head==NULL){
                head=tail=newNode;
                return;
            }
            newNode->next=head;  
            head=newNode;          
        }
        void pop_front()
        {
            if(head==NULL)
            {
                cout<<"Empty ";
                return;
            }
            Node* temp=head;
            head=head->next;
            temp->next=NULL;
            delete(temp);

        }
        void pop_back()
        {
            if(head==NULL)
            {
                cout<<"Empty ";
                return;
            }
            if(head==tail)
            {
                delete(head);
                head=tail=NULL;
                return;
            }
            Node* temp=head;
            while(temp->next!=tail)
            {
                temp=temp->next;
            }
            temp->next=NULL;
            delete(tail);
            tail=temp;
        }
        void pop_location(int pos)
        {
            if(head==NULL)
            {
                cout<<"Empty ";
                return;
            }
            if(pos<0)
            {
                cout<<"Invalid Position";
                return;
            }
            if(pos==0)
            {
                pop_front();
                return;
            }
            Node* temp=head;
            for(int i=0;i<pos-1 && temp->next!=NULL;i++)
            {
                temp=temp->next;
            }
            if(temp->next==NULL)
            {
                cout<<"Invalid Position";
                return;
            }
            Node* deleteNode=temp->next;
            temp->next=deleteNode->next;
            if(deleteNode==tail)
            {
                tail=temp;
            }
            delete(deleteNode);
        }
        void printll()
        {
            Node*temp = head;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
                
};

int main()
{
    LL ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.pop_front();
    ll.pop_back();
    ll.pop_location(1);
    
    ll.printll();
    return 0;
}