#include<iostream>

using namespace std;

class MyClass{
    private:
        char name[25];
        int num, den;
    public:
        void setName(){
            cout<<"NAME: ";
            cin>>name;
        }
        void getName(){
            cout<<name<<endl;
        }

        MyClass(){
            num = 1;
            den = 1;
        }

        MyClass(int num,int den){
            cout<<"Fraction done with constructer"<<endl;
            if(den != 0) {
                this->num = num;
                this->den = den;
            }else cout<<"ERROR: Can't set den 0"<<endl;
        }

        void setFraction(){
            cout<<"NUM/DEN: ";
            cin>>num;
            char s;
            cin>>s;
            cin>>den;
        }

        void getFraction(){
            cout<<"Fraction: "<<num<<"/"<<den<<endl;
        }

};

int main(){
    MyClass c1, c2(3,5);
    c1.setName();
    c1.getName();

    c1.setFraction();
    c1.getFraction();

    c2.getFraction();

    return 0;
}
