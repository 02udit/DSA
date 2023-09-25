#include<bits/stdc++.h>
using namespace std;

// factorial using recursion
int fact(int n){
    // base case
    if(n==0) return 1;

    //recursive relation
    return n*fact(n-1);
}

// power using recursion
int po(int n){
    // base case
    if(n==0) return 1;

    //recursive relation
    return 2*po(n-1); 
}

// counting using head recursion
void count2(int n){
    // base case
    if(n==0) return;

    //recursive relation
    count2(n-1); 

    // processing
    cout<<n<<" ";
}

// reverse counting using tail recursion
void count1(int n){
    // base case
    if(n==0) return;

    // processing
    cout<<n<<" ";

    //recursive relation
    count1(n-1); 
}

int main(){
    int n=5;
    int factorial=fact(n);
    cout<<"factorial of "<<n<<" is "<<factorial<<endl;
    int power=po(n);
    cout<<"2 to the power "<<n<<" is "<<power<<endl;
    
    cout<<"reverse counting to "<<n<<" is: ";
    count1(n);
    cout<<endl; 
    
    cout<<"counting from "<<n<<" is: ";
    count2(n);
    cout<<endl;  
    return 0;
}