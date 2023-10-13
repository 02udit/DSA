#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int n = 7;
    int k = 4;

    deque<int> maxi;  // Deque to store indices of elements in decreasing order (for maximum elements)
    deque<int> mini;  // Deque to store indices of elements in increasing order (for minimum elements)

    // Process the first window of size k
    for(int i = 0; i < k; i++){
        // Remove all previous greater elements (useless for finding maximum)
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        // Remove all previous smaller elements (useless for finding minimum)
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        // Add the current index to the deque for both maximum and minimum
        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;
    // Add the sum of maximum and minimum elements of the first window to ans
    ans += arr[maxi.front()] + arr[mini.front()];

    // Process the rest of the array
    for(int i = k; i < n; i++){
        // Remove indices that are out of the current window
        while(!maxi.empty() && i - maxi.front() >= k){
            maxi.pop_front();
        }
        while(!mini.empty() && i - mini.front() >= k){
            mini.pop_front();
        }

        // Remove all previous greater elements (useless for finding maximum)
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        // Remove all previous smaller elements (useless for finding minimum)
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        // Add the current index to the deque for both maximum and minimum
        maxi.push_back(i);
        mini.push_back(i);

        // Add the sum of maximum and minimum elements of the current window to ans
        ans += arr[maxi.front()] + arr[mini.front()];
    }

    cout << "answer is " << ans << endl;

    return 0;
}
