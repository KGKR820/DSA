#include <iostream>
// Set => 1 and Unset => 0
using namespace std;

// 101 | 010 => 111

void set(int &num,int pos){
    num = num | (1 << pos);
}

// 101 & 011 => 001

void unset(int &num,int pos){
    num = num & (~(1 << pos));
}

// 101 ^ 010 => 111

void toggle(int &num,int pos){
    num = num ^ (1 << pos);
}

// 101 & 010 => 000

bool find(int &num,int pos){
    return num & (1 << pos);
}

// 101 => 1  010{-(8-2)} => -6

void One_Compliment(int &num){
    num = ~(num);
}

// 101 => 1 011{-(8-3)} => -5

void Two_Compliment(int &num){
    num = ~(num)+1;
}
int main(){
    int num = 5;
    set(num,1);
    cout << num << "\n";
    num = 5;
    unset(num,2);
    cout << num << "\n";
    num = 5;
    toggle(num,1);
    cout << num << "\n";
    num = 5;
    cout << find(num,1) << "\n";
    num = 5;
     One_Compliment(num) ;
    cout <<  num<< "\n";
    num = 5;
     Two_Compliment(num) ;
    cout <<num << "\n";
    return 0;
}
