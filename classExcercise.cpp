#include<iostream>
#include<cstring>

using namespace std;

int MAX = 80;
int ROW = 5;

void buildTable(char **&strTbl, int r){
    strTbl = new char*[r];
    char temp[MAX+1] = "";
    for(int i=0;i<r;i++){
        cout<<"Enter string/no WS will be captured/max :80 chars \n";
        if(i > 0 && i != ROW-1) cout<<"next: ";
        else if(i == ROW-1) cout<<"last: ";
        else cout<<": ";
        cin>>temp;

        strTbl[i] = new char[strlen(temp)+1];
        strcpy(strTbl[i], temp);
    }
}
void printTable(char **strTbl, int row){
    for(int i=0;i<row;i++){
        cout<<strTbl[i]<<" ";
    }
}
void releaseTable(char**& strTbl, int r){
    for(int i=0;i<r;i++){
        delete [] strTbl[i];
    }
    delete [] strTbl;
    strTbl = nullptr;
}


int main(){

    int row = ROW;
    char **stringTable = nullptr;
    cout<<"**** Building Table ****"<<endl;
    buildTable(stringTable, row);
    cout<<endl<<"**** Printing Table ****"<<endl;
    printTable(stringTable, row);

    cout<<endl<<"**** Deallocating Table ****"<<endl;
    releaseTable(stringTable, row);

    return 0;
}
