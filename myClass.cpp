#include<iostream>

using namespace std;

class Money{
    private:
        int dollar, cents;

    public:
        Money(){
            this->dollar = this->cents = 0;
        }
        void setDollar(int dollar){
            this->dollar = dollar;
        }

        void setCents(int cents){
            this->cents = cents;
        }

        int getDollar(){
            return this->dollar;
        }

        int getCents(){
            return this->cents;
        }

        void operator +(Money obj){
            if(this->cents + obj.cents == 100){
                this->dollar += obj.dollar + 1;
                this->cents = 0;
             }else{
                this->cents += obj.cents;
                this->dollar += obj.dollar;
            }
        }
        void operator -(Money obj){
            if(this->cents + obj.cents == 100){
                this->dollar -= obj.dollar - 1;
                this->cents > obj.cents ? this->cents -= obj.cents: obj.cents -= this->cents;
             }else{
                this->cents -= obj.cents;
                this->dollar -= obj.dollar;
            }
        }
        void printMoney(){
            cout<<"Your Money: "<<this->dollar<<"."<<this->cents<<endl;
        }
};

int main(){
    Money m1, m2;
    int d,c;
    char temp;
    cout<<"Enter your money: ";
    cin>>d>>temp>>c;
    m1.setDollar(d);
    m1.setCents(c);
    m1.printMoney();


    cout<<"Enter your money: ";
    cin>>d>>temp>>c;
    m2.setDollar(d);
    m2.setCents(c);
    m2.printMoney();

    m1 - m2;

    cout<<"Sub addition: ";
    m1.printMoney();
}
