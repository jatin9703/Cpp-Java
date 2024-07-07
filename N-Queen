#include<bits/stdc++.h>
using namespace std;

class nqueen{
  int n;
  int**arr;
  
  public:
  
  nqueen(int n){
      this->n=n;
      arr=new int* [n];
      for(int i=0;i<n;i++){
          arr[i]=new int[n];
      }
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              arr[i][j]=0;
          }
      }
  
      cout<<"Chess board created "<<endl;
  }
  
  bool issafe(int row,int col);
  bool place_queen(int row);
  void display(){
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              cout<<arr[i][j]<<" ";
          }
          cout<<endl;
      }
  }
  
  
  
};



bool nqueen::issafe(int row ,int col){
    for (int r=row;r>=0;r--){
        if (arr[r][col]==1){
            return false;
        }
    }
    int r=row;
    int c=col;
    while(r>=0 && c>=0){
        if (arr[r][c]==1){
            return false;
        }
        r--;
        c--;
    }
    
     r=row;
     c=col;
    while(r>=0 && c<n){
        if (arr[r][c]==1){
            return false;
        }
        r--;
        c++;
    }
    
   return true; 
}

bool nqueen::place_queen(int row){
    if(row>=n){
        return true;
    }
    for (int col=0;col<n;col++){
    if(this->issafe(row,col)){
        arr[row][col]=1;
        if(this->place_queen(row+1)){
      cout<<row<<" "<<col<<endl;;
            return true;
        }
        
        arr[row][col]=0;
    }
        
    }
    return false;
    
}


int main(){
    int n;
    cout<<"Enter the chess board size->";
    cin>>n;
    nqueen queen(n);
    if (queen.place_queen(0)){
        queen.display();
       cout<<"done";
    }
    return 0;
}