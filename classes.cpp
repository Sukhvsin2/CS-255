#include<iostream>

using namespace std;

class MyClass{
    private:
        char name[25];
    public:
        void setName(){
            cin>>name;
        }
        void getName(){
            cout<<name;
        }

};

int main(){
    MyClass c1;
    c1.setName();
    c1.getName();
    return 0;
}
