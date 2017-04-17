#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

void towHanoi(int disks,string start,string mid,string last);

int main(){
    int number;
    cout<<"Enter Number of disks:";
    cin>>number;
    towHanoi(number,"A","B","C");
    return 0;
}

void towHanoi(int disks,string start,string mid,string last){
    if(disks == 1){
        cout<<start+"-->"+last<<endl;
    }
    else{
        towHanoi(disks-1,start,last,mid);
        towHanoi(1,start,mid,last);
        towHanoi(disks-1,mid,start,last);
    }
}
