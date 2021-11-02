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
		Node* find(int key){
			Node* temp = head;
			int counter = 0;
			while(temp != nullptr){
				counter++;
				if(temp->data == key){
					cout<<"\n"<<key<<" Found at: "<<counter;
					return temp;
				}
				temp = temp->ptr;
			}
			cout<<"\nError: No data in the linkedList!"<<endl;
		}

		void deletebeg(){
			Node* temp = head;
			head = head->ptr;
			delete temp;
		}

         void deleteEnd(){
            Node *temp = head, *prev;
            if(head==nullptr || head->ptr==nullptr){
                cout<<"List is Empty";
                delete head;
                head = nullptr;
                return;
            }
            while(temp->ptr!=nullptr){
                prev=temp;
                temp=temp->ptr;
            }
            prev->ptr = nullptr;
            delete temp;
        }

        void insertOrder(int pos, int item){
            Node *temp = head, *prev = head;
            int i=0;
            if(temp == nullptr){
                cout<<"Head is Null";
                return;
            }else{
                while(temp != nullptr && i < pos-1){
                    i++;
                    prev = temp;
                    temp = temp->ptr;
                }
                Node *newNode = new Node(item);
                prev->ptr = newNode;
                newNode->ptr = temp;

            }

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
    l1.insertOrder(2, 50);
	l1.print();
	//Node* res = l1.find(20);
	//cout<<"\nCheck: "<<res->data;
    return 0;
}
