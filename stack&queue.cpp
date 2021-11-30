#include<iostream>
#define MAX 5

using namespace std;

class Stack{
    int arr[MAX];
    int top;
    public:
        Stack(){
            top = 0;
        }
        void push(int data){
            if(top == MAX){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            top++;
            arr[MAX-top-1] = data;
        }
        void pop(){
            if(top == 0){
                cout<<"Stack Underflow"<<endl;
                return;
            }
            top--;
        }
        void print(){
            int temp = top;
            while(temp){
                cout<<arr[MAX-temp-1]<<" ";
                temp--;
            }
            cout<<endl;
        }
};

class Queue{
    int arr[MAX];
    int front, rear;
    public:
        Queue(){
            front = rear = -1;
        }
        void enqueue(int data){
            if(rear == MAX-1) return;
            if(front == -1){
                front++;
            }
            rear++;
            arr[rear] = data;
        }
        void dequeue(){
            if(rear != front){}
        }
        void print(){}
};

int main(){
}
