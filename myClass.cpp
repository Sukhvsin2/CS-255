#include<iostream>

using namespace std;

class Money{
    private:
    	// decalaring variables
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
        
        friend istream& operator>>(istream &s, Money &obj){
        	char temp;
        	s>>obj.dollar>>temp>>obj.cents;
		}
		
		
        friend ostream& operator<<(ostream &s, Money &obj){
        	s<<obj.dollar<<"."<<obj.cents;
		}

        void operator +(Money &obj){
            if(this->cents + obj.cents == 100){
                this->dollar += obj.dollar + 1;
                this->cents = 0;
             }else{
                this->cents += obj.cents;
                this->dollar += obj.dollar;
            }
        }
        void operator -(Money &obj){
            if(this->dollar > obj.dollar){
				this->dollar -= obj.dollar;
				if(this->cents > obj.cents){
					this->cents -= obj.cents;
				}else{
					this->cents = 100 - (obj.cents - this->cents);
					this->dollar--;
				}
			}else{
				this->dollar = obj.dollar - this->dollar;
				if(this->cents > obj.cents){
					this->cents = 100-(this->cents - obj.cents);
					this->dollar--;
				}else{
					this->cents = 100 - (obj.cents - this->cents);
					this->dollar--;
				}
			}
        }
        bool operator==(Money &obj){
        	if(this->dollar == obj.dollar && this->cents) return true;
        	return false;
		}
		bool operator<(Money &obj){
        	if(this->dollar < obj.dollar) return true;
        	return false;
		}
		bool operator>(Money &obj){
        	if(this->dollar > obj.dollar) return true;
        	return false;
		}
		bool operator<=(Money &obj){
        	if(this->dollar <= obj.dollar) return true;
        	return false;
		}
		bool operator>=(Money &obj){
        	if(this->dollar >= obj.dollar) return true;
        	return false;
		}
		bool operator!=(Money &obj){
        	if(this->dollar != obj.dollar || this->cents != obj.cents) return false;
        	return true;
		}
		Money operator++(int){
			Money temp = *this;
			this->dollar += 1;
			return temp;
		}
		Money operator--(int){
			Money temp = *this;
			this->dollar -= 1;
			return temp;
		}
		Money operator++(){
			this->dollar += 1;
			return *this;
		}
		Money operator--(){
			this->dollar -= 1;
			return *this;
		}
        void printMoney(){
            cout<<"Your Money: "<<this->dollar<<".";
            if (this->cents < 10) cout<<"0"<<this->cents<<endl;
            else cout<<this->cents<<endl;
        }
};

int main(){
    Money m1, m2;
    int d,c;
    
    cin>>m1>>m2;
    m1-m2;
    m1.printMoney();
    
	/**
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
    m1.printMoney();**/
}
