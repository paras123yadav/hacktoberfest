#include <bits/stdc++.h>
using namespace std;

bool binarysearch(vector<int>& arr, int elem){
    int left=0;
    sort(arr.begin(), arr.end());
    int right= arr.size()-1;
    while(left<=right){
        int pivot= left + (right-1)/2;
        if(arr[pivot]==elem)
            return true;
        if(arr[pivot]>elem)
            right=pivot-1;
        else
            left= pivot+1;
    }
    return false;
}

int main(){
    vector<int> arr;
    int n;
    cin>>n;
    int x=0;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    int elem=0;
    cin>>elem;
    bool ispresent= binarysearch(arr, elem);
    if(ispresent)
        cout<<"Element Found";
    else
        cout<<"Element not in array";
}