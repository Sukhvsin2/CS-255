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
	void Print()const; //method that will output the object
	void Input();
	int GetNum()const;
	int GetDen()const;
	void SetNum(int n);
	void SetDen(int d);
	Fraction Multiply(const Fraction& right)const;
	//Fraction operator*(const Fraction& right)const;
	friend Fraction operator*(const Fraction& left, const Fraction& right);
    friend ostream& operator<<(ostream &c, const Fraction &obj){
        c<<"Overloading << operator: "<<obj.num<<"/"<<obj.den;
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
void Fraction::Print()const{
	cout << num << "/" << den;
}

void Fraction::Input(){
	char dummy;
	cin >> num;
	cin >> dummy;
	cin >> den;
}

int Fraction::GetNum()const{
	return num;
}
int Fraction::GetDen()const{
	return den;
}
void Fraction::SetNum(int n){
	num = n;
}
void Fraction::SetDen(int d){
	if (d == 0)
		d = 1;
	den = d;
}

Fraction Fraction::Multiply(const Fraction& right)const{
	Fraction temp;
	temp.num = num * right.num;
	temp.den = den * right.den;
	return temp;
}
/*Fraction Fraction::operator*(const Fraction& right)const{
	Fraction temp;
	temp.num = num * right.num;
	temp.den = den * right.den;
	return temp;
}
*/
Fraction operator*(const Fraction& left, const Fraction& right){
	Fraction temp;
	temp.num = left.num * right.num;
	temp.den = left.den * right.den;
	return temp;

}


int main(){

	Fraction f1(3,4); //Instantiates the Fraction class
	Fraction f2(1,3);
	Fraction result;
	//result = f1.Multiply(f2);
	result = f1 * f2;
	result.Print(); cout << endl;

	cout << f1 << endl;

	return 0;
}
