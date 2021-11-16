#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
        Node(){
            left = right = nullptr;
        }
};

class BinaryTree{
    Node *root;
    bool insertNode(int data, Node *&root){
        if(root == nullptr){
            Node *newNode = new Node();
            newNode->data = data;
            root = newNode;
            return true;
        }else{
            if(data < root->data)   insertNode(data, root->left);
            else insertNode(data, root->right);
        }
    }
    void inorderNode(Node *root){
        if(root == nullptr) return;
        inorderNode(root->left);
        cout<<root->data<<" ";
        inorderNode(root->right);
    };
    void prefixNode(Node *root){
        if(root == nullptr) return;
        cout<<root->data<<" ";
        inorderNode(root->left);
        inorderNode(root->right);
    };
    void postfixNode(Node *root){
        if(root == nullptr) return;
        inorderNode(root->left);
        inorderNode(root->right);
        cout<<root->data<<" ";
    };
    Node* searchNode(int data, Node *root){
        if(root == nullptr) return nullptr;
        if(root->data == data){
            return root;
        }else{
            if(data < root->data)   searchNode(data, root->left);
            else searchNode(data, root->right);
        }

    }
    public:
        BinaryTree(){
            root = nullptr;
        }
        bool insert(int data){
            return insertNode(data, root);
        }
        void inorder(){
            inorderNode(root);
        }
        void prefix(){
            prefixNode(root);
        }
        void postfix(){
            postfixNode(root);
        }
        void search(int data){
            Node *temp = searchNode(data, root);
            if(temp) cout<<"Found it: "<<temp<<endl;
            else cout<<"Nope!";
        }
        /**void insert(int data){
            Node *temp = root;
            Node* newNode = new Node();
            newNode->data = data;
            newNode->left = newNode->right = nullptr;
            if(root == nullptr){
                root = newNode;
            }else{
                while(temp != nullptr){
                    if(temp->data > data) temp->left;
                    else temp->right;
                }
                temp = newNode;
            }
        }
        void postfix(Node *r){
            if(r == nullptr) return;
            postfix(r->left);
            postfix(r->right);
            cout<<r->data<<" ";
        }**/
};

int main(){
    BinaryTree B;
    B.insert(50);
    B.insert(25);
    B.insert(100);
    B.insert(45);
    B.insert(75);
    B.inorder();
    cout<<endl;
    B.prefix();
    cout<<endl;
    B.postfix();
    cout<<endl;
    B.search(1000);
    return 0;
}
