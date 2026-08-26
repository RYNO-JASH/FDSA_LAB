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
        void push_back(int val)
        {
            Node* newNode=new Node(val);
            if(head==NULL){
                head=tail=newNode;
                return;
            }
            tail->next=newNode;
            tail=newNode;
        }
        void push_position(int val,int pos)
        {
            Node* temp=head;
            if(pos<0)
            {
                cout<<"Invalid Position";
                return;
            }
            if(pos==0)
            {
                push_back(val);
            }
            for(int i=0;i<pos-1;i++)
            {
                temp=temp->next;
            }
            Node* newNode=new Node(val);
            newNode->next=temp->next;
            temp->next=newNode;
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
    LL l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_position(5,2);
    l1.push_position(6,3);

    l1.printll();
    return 0;
}