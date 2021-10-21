#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* ptr;
        Node(int data){
            this->data = data;
            ptr = nullptr;
        }
};

class LinkedList{
    Node *head;
    public:
        LinkedList(){
            head = nullptr;
        }
        void insert(int data){
            Node* newNode = new Node(data);
            Node* temp = head;
            newNode->ptr = temp;
            head = newNode;
        }
        void append(int d){
            Node *newNode = new Node(d);
            if(head == nullptr){
                head = newNode;
                return;
            }
            Node *temp = head;
            while(temp->ptr != nullptr){
                temp = temp->ptr;
            }
            temp->ptr = newNode;
        }
        void print(){
            Node *temp = head;
            while(temp != nullptr){
                cout<<temp->data<<" ";
                temp = temp->ptr;
            }
        }
};

int main(){
    LinkedList l1;
    l1.append(10);
    l1.append(20);
    l1.append(30);
    l1.insert(90);
    l1.print();
    return 0;
}
