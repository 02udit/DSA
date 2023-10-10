#include<bits/stdc++.h>
using namespace std;

int main(){
    // Initialize a string variable
    string str = "hello";

    // Display the original string
    cout << str << endl;

    // Create a stack of characters
    stack<char> s;

    // Push each character of the string onto the stack
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];
        s.push(ch);
    }

    // Initialize an empty string to store the reversed string
    string ans = "";

    // Pop each character from the stack and append it to the reversed string
    while(!s.empty()){
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }

    // Display the reversed string
    cout << ans << endl;

    // Return 0 to indicate successful program execution
    return 0;
}
