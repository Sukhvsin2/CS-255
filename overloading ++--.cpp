#include<iostream>

using namespace std;

class Test{
    private:
        int year;
    public:
        Test(){
            this->year = 2021;
        }
        int operator++(int){
            return this->year++;
        }
        int operator--(int){
            return this->year--;
        }
        void operator++(){
            ++year;
        }
        void operator--(){
            --year;
        }
        void display(){
            cout<<"Year: "<<this->year<<endl;
        }
};

int main(){
    Test t1;
    t1.display();
    cout<<t1++<<endl;
    t1.display();
}
