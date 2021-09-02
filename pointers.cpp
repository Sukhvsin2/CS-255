#include<iostream>

using namespace std;

int main(){
    int arr[10] = {1,2,3,4,5}, size = 5;
    cout<<&arr<<endl;
    for(int i=0;i<size;i++){
        cout<<*(arr + i)<<" ";
    }

    return 0;
}
