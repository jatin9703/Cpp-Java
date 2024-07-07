#include<iostream>
using namespace std;
 int main(){
 int a=0,b=1,c,n;
 cout << "Enter the number of fibonacci numbrs you want - ";
  cin >> n;
  cout<<"0 1 ";
  n=n-2;
  while(n){
  c=a+b;
  a=b;
  b=c;
  cout<<c<<" ";
  n--;
  }
  return 0;}
