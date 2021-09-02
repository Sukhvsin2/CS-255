#include<iostream>

using namespace std;

int main(){
    int s;
    cout<<"How many integers: ";
    cin>>s;

    int *arr = new int[s];

    for(int i=0;i<s;i++){
        arr[i] = i + 1;
    }
    for(int i=0;i<s;i++){
        cout<<arr[i]<<" ";
    }

    delete[] arr;

    return 0;
}
