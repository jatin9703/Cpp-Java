#include<bits/stdc++.h>
using namespace std;

class object{
    public:
    int id;
    float profit;
    float weight;
    float ratio;
    float status=0;
    object(int id,float weight,float profit,float ratio){
        this->id=id;
        this->weight=weight;
        this->profit=profit;
        this->ratio=ratio;
    }
    
};
class fractional{
    int n;
    float capacity=0;
    float total_profit=0;
    vector<object*>v1;
    public:
    void getdata();
    void display();
    void fractional_knapsack();
    
    
    
    
};


void fractional::getdata(){
    float profit,weight,ratio;
    int id;
    cout<<"enter the number of objects"<<endl;
    cin>>n;
cout<<"enter the capacity of knapsack->";
cin>>capacity;
    for(int i=0;i<n;i++){
        cout<<"Enter the object id ->";
        cin>>id;
        
        cout<<"enter the weight of object->";
        cin>>weight;
        
        cout<<"enter the profit of associative object->";
        cin>>profit;
        
        ratio=profit/weight;
        object* temp=new object(id,weight,profit,ratio);
        v1.push_back(temp);
    }
    
    
    
}

void fractional::display(){
    cout<<"object id"<<setw(15)<<"weight"<<setw(15)<<"Profit"<<setw(15)<<"Ratio"<<setw(15)<<"Added Fraction"<<endl;
    
    for (auto x: v1){
        cout<<x->id<<setw(15)<<x->weight<<setw(15)<<x->profit<<setw(15)<<x->ratio<<setw(15)<<x->status<<endl;
    }
}


void fractional::fractional_knapsack(){
    
    sort(v1.begin(),v1.end(),[](object* l, object* r){return l->ratio>r->ratio;});
    
    this->display();
    
   for(auto x:v1){
       if(x->weight <= capacity){
           x->status=1;
           
           capacity=capacity-(x->weight);
           total_profit=(total_profit)+(x->profit);
           continue;
       }
      
        x->status=capacity/x->weight;
       capacity-=capacity;
       total_profit=total_profit+(x->status)*(x->profit);
   }
    
    cout<<"Total profit is "<<total_profit<<endl;
    
  this->display();
    
}



int main(){
    fractional k1;
    k1.getdata();
    k1.display();
    k1.fractional_knapsack();
    
    return 0;
}






