#include <bits/stdc++.h>
using namespace std;

bool binarysearch(vector<int>& arr, int elem){
    int left=0;
    sort(arr.begin(), arr.end()); //since binary search works only in sorted array
    int right= arr.size()-1;
    while(left<=right){
        int pivot= left + (right-1)/2; //finding out the center element
        if(arr[pivot]==elem)   
            return true;
        if(arr[pivot]>elem)  //if center element is greater than the element to search, the element must be in first half, so right changes to pivot-1
            right=pivot-1;
        else
            left= pivot+1;
    }
    return false;
}

int main(){
    vector<int> arr;
    int n;
    cin>>n; //size of array
    int x=0;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    int elem=0;
    cin>>elem; //the element to search
    bool ispresent= binarysearch(arr, elem);
    if(ispresent)
        cout<<"Element Found";
    else
        cout<<"Element not in array";
}
