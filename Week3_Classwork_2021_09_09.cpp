#include <iostream>
using namespace std;

//class declaration
class Fraction{
	//data representation
	int num;
	int den;
public:
	//constructor - called when an object is created
	Fraction(); //constructor that will initialize
	Fraction(int n);
	Fraction(int n, int d);
	void Print()const; //method that will output the object
	void Input();
	//add a MultBy method
    void multBy(Fraction &obj){
        int n2 = obj.num, d2 = obj.den;
        this->den *= d2;
        this->num *= n2;
    }

    void addTo(Fraction &obj){
        int d = obj.den, n = obj.num;

        int temp = this->num;
        this->num *= d;
        n *= this->den;
        this->num += n;
        this->den *= d;
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
int main(){

	Fraction f1; //Instantiates the Fraction class
	Fraction f2(5); //Instantiates the Fraction class
	Fraction f3(4, 6);

	f1.Print(); cout << endl;
	f2.Print(); cout << endl;
	f3.Print();

	cout << "\nEnter a Fraction in the form num/den" << endl;
	f3.Input();
	f3.Print();

	//multiplying two fractions
    f1.multBy(f2);
    cout<<"\n\n\n";
    f1.Print();

    cout<<"\n\n\n";
    f1.addTo(f2);
    f1.Print();
    return 0;
}
