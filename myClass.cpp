#include<iostream>

using namespace std;

class Money{
    private:
    	// decalaring variables
        int dollar, cents;

    public:
    	Money();
    	void setDollar(int dollar);
    	void setCents(int cents);
    	int getDollar();
    	int getCents();
    	friend istream& operator>>(istream &s, Money &obj);
    	friend ostream& operator<<(ostream &s, Money &obj);
    	void operator +(Money &obj);
    	void operator -(Money &obj);
    	bool operator <(Money &obj);
    	bool operator >(Money &obj);
    	bool operator ==(Money &obj);
    	bool operator <=(Money &obj);
    	bool operator >=(Money &obj);
    	bool operator !=(Money &obj);
    	Money operator ++(int);
    	Money operator --(int);
    	Money operator ++();
    	Money operator --();
    	void printMoney();
    	
};


    	
        Money::Money(){
            this->dollar = this->cents = 0;
        }
        void Money::setDollar(int dollar){
            this->dollar = dollar;
        }

        void Money::setCents(int cents){
            this->cents = cents;
        }

        int Money::getDollar(){
            return this->dollar;
        }

        int Money::getCents(){
            return this->cents;
        }
        
        istream& operator>>(istream &s, Money &obj){
        	char temp;
        	s>>obj.dollar>>temp>>obj.cents;
		}
		
		
        ostream& operator<<(ostream &s, Money &obj){
        	s<<obj.dollar<<"."<<obj.cents;
		}

        void Money::operator +(Money &obj){
            if(this->cents + obj.cents == 100){
                this->dollar += obj.dollar + 1;
                this->cents = 0;
             }else{
                this->cents += obj.cents;
                this->dollar += obj.dollar;
            }
        }
        void Money::operator -(Money &obj){
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
        bool Money::operator==(Money &obj){
        	if(this->dollar == obj.dollar && this->cents) return true;
        	return false;
		}
		bool Money::operator<(Money &obj){
        	if(this->dollar < obj.dollar) return true;
        	return false;
		}
		bool Money::operator>(Money &obj){
        	if(this->dollar > obj.dollar) return true;
        	return false;
		}
		bool Money::operator<=(Money &obj){
        	if(this->dollar <= obj.dollar) return true;
        	return false;
		}
		bool Money::operator>=(Money &obj){
        	if(this->dollar >= obj.dollar) return true;
        	return false;
		}
		bool Money::operator!=(Money &obj){
        	if(this->dollar != obj.dollar || this->cents != obj.cents) return false;
        	return true;
		}
		Money Money::operator++(int){
			Money temp = *this;
			this->dollar += 1;
			return temp;
		}
		Money Money::operator--(int){
			Money temp = *this;
			this->dollar -= 1;
			return temp;
		}
		Money Money::operator++(){
			this->dollar += 1;
			return *this;
		}
		Money Money::operator--(){
			this->dollar -= 1;
			return *this;
		}
        void Money::printMoney(){
            cout<<"Your Money: "<<this->dollar<<".";
            if (this->cents < 10) cout<<"0"<<this->cents<<endl;
            else cout<<this->cents<<endl;
        }

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
