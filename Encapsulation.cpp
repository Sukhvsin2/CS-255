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
	f1.print();

    f1.setNum(1);
    f1.setDen(-100);
    // calling by getters
    cout<<f1.getNum()<<"/"<<f1.getDen();
	return 0;
}
