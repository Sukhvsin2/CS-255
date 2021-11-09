#include <iostream>
using namespace std;
//****************************
// LinkedList.h class headers
//****************************

class Node{
	int data;
	Node* next;
	Node();
	Node(int d);
	Node(int d, Node* n);
	friend class LinkedList;
};


class LinkedList{
	Node * head;
public:
	LinkedList();
	LinkedList(const LinkedList& l);
	LinkedList& operator=(const LinkedList l);
	~LinkedList();
    bool Insert(int e);
	bool Remove(int e);
	void Print()const;


};

//************************************
// LinkedList.cpp class implementation
//************************************
Node::Node(){
	next = nullptr;
}
Node::Node(int d){
	data = d;
	next = nullptr;
}
Node::Node(int d, Node* n){
	data = d;
	next = n;
}
LinkedList::LinkedList(){
	head = nullptr;
}

void LinkedList::Print()const{
	Node* curr = head;
	while (curr != nullptr){
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout<<"\n\n";
}

LinkedList::LinkedList(const LinkedList& l){
	//build a new list for the calling object based upon the contents of the parameter
	Node* temp = l.head;
	while(temp != nullptr){
	    this->Insert(temp->data);
	    temp = temp->next;
	}
	
}
LinkedList& LinkedList::operator=(const LinkedList l){
	//make sure calling object and parameter are not the same list then
	//deallocate calling operator then 
	//rebuild a new list for the calling object based upon the contents of the parameter
	
	
}
LinkedList::~LinkedList(){
	//deallocate each item in the list and reset head to nullptr
	Node * temp = nullptr;
	while(head != nullptr){
	    temp = head;
	    head = head->next;
	    delete temp;
	}
	delete head;
	cout<<"Deconstructor Called\n";
}
    
	

bool LinkedList::Insert(int e){
    bool result = true;
    if (head == nullptr || e < head->data)
        head = new Node(e, head);
    else{ 
        Node* curr = head, *prev = head;
        while (curr != nullptr && e >= curr->data){
            prev = curr;
            curr = curr->next;        
        }
        if ( e != prev->data)
            prev->next = new Node(e, prev->next);
        else{
            cout << "no duplicates" << endl;
            result = false;
        }
    }
    return result;
}

bool LinkedList::Remove(int e){
	bool success = false;
	//put Remove code here... assume an ordered list
	Node* temp = head, *prev = head;
	    if(head->data == e){
	        head = head->next;
	        delete temp;
	        success = true;
	        return success;
	    }
	while(temp != nullptr){
	    if(temp->data == e){
	        prev->next = temp->next;
	        delete temp;
	        success = true;
	        return success;
	    }
	    prev = temp;
        temp = temp->next;
	    
	}
	return success;
}


//************************************
// Driver
//************************************


int main() {
	{
	    LinkedList l1;
    	l1.Insert(0);
    	l1.Insert(2);
    	l1.Insert(58);
    	l1.Insert(-1);
    	cout<<"Before L1: ";
    	l1.Print();
    	
    	LinkedList l2(l1);
    	
    	
    	cout<<"L2: "; l2.Print();
    	l1.Remove(2);
    	cout<<"After Removing 2 from L1: ";
    	l1.Print();
    	
    	
	}
	
	return 0;
}

