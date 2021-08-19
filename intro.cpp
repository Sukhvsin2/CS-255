#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void alpha(){
    for(int i='a'; i<='z'; i++){
        cout<<(char)i<<" ";
    }
    cout<<endl;
}

void inp(){
    int i=0, temp, min=0;
    while(i<10){
        cin>>temp;
        if(min>temp) min = temp;
        i++;
    }
    cout<<"min?: "<<min;
    cout<<endl;
}

void ran(){
    int arr[5], i=0;
    srand(time(0));
    int r = rand() % 40 + 20;
    do{
        arr[i] = r;
        i++;
    }while(i<4);
    cout<<endl;
}

int main(){

    alpha();
    inp();
    ran();
    return 0;
}
