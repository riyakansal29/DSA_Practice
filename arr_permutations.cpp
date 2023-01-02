//all possible permutations
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void permutation(vector<int> &arr, vector<vector<int>> &ans, int index){
    if(index == arr.size()-1){
      ans.push_back(arr);
      return;
    }
    for(int i=index; i<arr.size(); i++){
      swap(arr[i], arr[index]);
      permutation(arr, ans, index+1);
      swap(arr[i], arr[index]);
    }
}

void display(vector<vector<int>> &ans){
  for(int i=0; i<ans.size(); i++){
    for(int j=0; j<ans[0].size(); j++){
        cout<<ans[i][j];
    }
    cout<<endl;
  }
}

int main() {
// int arr[3] = {1,2,3};
vector<int>arr;
arr.push_back(1);
arr.push_back(2);
arr.push_back(3);
vector<vector<int>>ans;
int index = 0;
permutation(arr,ans, index);
// display(ans);
vector<int>ans1;
int arr1[3] ={1,2,3};
ans1.push_back(next_permutation(arr1, arr1+3));
for(int i=0;i<3;i++){
  cout<<arr1[i];
}
int arr5[2] = {1,2};
swap(arr5[0], arr5[1]);
cout<<arr5[0];

    return 0;
}
