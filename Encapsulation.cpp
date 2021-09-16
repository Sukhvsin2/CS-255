#include <iostream>
using namespace std;

//class declaration
class Fraction{
	//data representationdf
	int num;
	int den;
public:
	//constructor - called when an object is created
	Fraction(); //constructor that will initialize
	Fraction(int n);
	Fraction(int n, int d);
	void print()const; //method that will output the object
	void Input();

    int getNum(){
        return num;
    }
    int getDen(){
        return den;
    }
    void setNum(int n){
        num = n;
    }
    void setDen(int d){
        den = d == 0 ? 1 : d;
    }
    void setData(int n, int d){
        num = n;
        den = d == 0 ? 1 : d;
    }
/**
    Fraction operator * (Fraction &obj){
        Fraction res;
        res.num = this->num * obj.num;
        res.den = this->den * obj.den;
        return res;
    }**/

    friend Fraction operator * (Fraction &obj1, Fraction &obj2){
        Fraction res;
        res.num = obj1.num * obj2.num;
        res.den = obj1.den * obj2.den;
        return res;
    }

    /**
    Fraction operator + (Fraction &obj1){
        Fraction res;
        res.num = obj1.num * this->den + this->num * obj1.den;
        res.den = this->den + obj.den;
        return res;
    }**/

    friend Fraction operator + (Fraction &obj1, Fraction &obj2){
        Fraction res;
        res.num = obj1.num * obj2.den + obj2.num * obj1.den;
        res.den = obj1.den * obj2.den;
        return res;
    }

    /**
    Fraction operator - (Fraction &obj1){
        Fraction res;
        res.num = obj1.num * this->den - this->num * obj1.den;
        res.den = this->den - obj.den;
        return res;
    }**/

    friend Fraction operator - (Fraction &obj1, Fraction &obj2){
        Fraction res;
        res.num = obj1.num * obj2.den - obj2.num * obj1.den;
        res.den = obj1.den - obj2.den;
        return res;
    }

};

//class Fraction definition

Fraction::Fraction(){
	cout << "Fraction Constructor - no data" << endl;
	num = 0;
	den = 1;
}
Fraction::Fraction(int n){
	cout << "Fraction Constructor - data_1" << endl;
	num = n;
	den = 1;
}
Fraction::Fraction(int n, int d){
	cout << "Fraction Constructor - data_2" << endl;
	num = n;

	if (d == 0)
		den = 1;
	else
		den = d;


}
void Fraction::print()const{
	cout << endl<<num << "/" << den<<endl;
}

void Fraction::Input(){
	char dummy;
	cin >> num;
	cin >> dummy;
	cin >> den;
}
int main(){

	Fraction f1; //Instantiates the Fraction class

    f1.setNum(1);
    f1.setDen(100);
    // calling by getters
    cout<<f1.getNum()<<"/"<<f1.getDen()<<endl;

    f1.setData(1,100);
    cout<<f1.getNum()<<"/"<<f1.getDen()<<endl;

    Fraction f2(2,2);

    // Over loading operator
    Fraction f3 = f1 * f2;
    f3.print();

// Over loading operator
    f3 = f1 + f2;
    f3.print();

// Over loading operator
    f3 = f1 - f2;
    f3.print();
	return 0;
}
