#include<iostream>
#include<vector>
using namespace std;
struct Result
{
  int max;
  int min;
};

Result max_min(vector<int> &arr, int left,int right){
  Result res;
  if(left == right){
    res.max = arr[left];
    res.min = arr[right];
    return res;
  }
  if(left+1 == right){
    if(arr[left] > arr[right]){
      res.max = arr[left];
      res.min = arr[right];
    }
    else{
      res.min = arr[left];
      res.max = arr[right];
    }
    return res;
  }
  int mid = (left+right)/2;
  Result low = max_min(arr,left,mid);
  Result high = max_min(arr,mid+1,right);
  if(low.max > high.max){
    res.max = low.max;
  }
  else{
    res.max = high.max;
  }
  if(low.min < high.min){
    res.min = low.min;
  }
  else{
    res.min = high.min;
  }
  return res;
}


int main(){
  vector<int> vec = {5,6,4,7,2,1,9};
  Result ans = max_min(vec,0,vec.size()-1);
  cout<<ans.max<<"   "<<ans.min;

  return 0;
}