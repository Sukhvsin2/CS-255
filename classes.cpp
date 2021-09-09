#include<iostream>

using namespace std;

class MyClass{
    private:
        char name[25];
        int num, den;
    public:
        void setName(){
            cin>>name;
        }
        void getName(){
            cout<<name<<endl;
        }

        MyClass(){
            num = 1;
            den = 1;
        }

        void setFraction(){
            cout<<"NUM: ";
            cin>>num;
            cout<<"DEN: ";
            cin>>den;
        }

        void getFraction(){
            cout<<"Fraction: "<<num<<"/"<<den<<endl;
        }

};

int main(){
    MyClass c1;
    c1.setName();
    c1.getName();

    c1.setFraction();
    c1.getFraction();
    return 0;
}
