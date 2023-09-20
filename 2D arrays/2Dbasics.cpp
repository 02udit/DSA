#include<bits/stdc++.h>
using namespace std;


// searching the element in array
bool searchElement(int arr[][4],int target){
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j]==target) return 1;
        }
    }
    return 0;
}

// row wise sum
void rowWiseSum(int arr[][4],int row,int col){
    cout<<"Row wise sum are= ";
    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<col;j++){
            sum+=arr[i][j];
        }
        cout<<sum<<" ";
    }
}

// col wise sum
void colWiseSum(int arr[][4],int row,int col){
    cout<<"Column wise sum are= ";
    for(int i=0;i<col;i++){
        int sum=0;
        for(int j=0;j<row;j++){
            sum+=arr[j][i];
        }
        cout<<sum<<" ";
    }
}


// largest row wise sum
int largestRowWiseSum(int arr[][4],int row,int col){
    int maxi=INT_MIN;
    int rowIndex=-1;
    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<col;j++){
            sum+=arr[i][j];
        }
        if(sum>maxi){
            maxi=sum;
            rowIndex=i;
        }
    }
    cout<<"Maximum sum is= "<<maxi<<endl;
    return rowIndex;
}

int main(){
    int arr[3][4];

    // row wise input
    cout<<"Enter the elements: "<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }

    //column wise input
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<3;j++){
    //         cin>>arr[j][i];
    //     }
    // }


    // printing the array
    cout<<"Array:- "<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Enter the target value= ";
    int x;
    cin>>x;
    if(searchElement(arr,x)) cout<<"Element found";
    else cout<<"Element Not fount";

    cout<<endl<<endl;

    rowWiseSum(arr,3,4);
    cout<<endl<<endl;
    colWiseSum(arr,3,4);
    cout<<endl<<endl;
    int largestSum=largestRowWiseSum(arr,3,4);
    cout<<"Largest sum is in row "<<largestSum<<endl;
    return 0;
}