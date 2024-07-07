#include <iostream>

class gates{
public:
int a,b,c,ac,bc,cc;
public:
void getone(){printf("enter the value of A input\n");
scanf("%d",&a);}
void gettwo(){printf("enter the value of A input\n");
scanf("%d",&a);
printf("enter the value of B input\n");
scanf("%d",&b);}

int annd(){
if(a==0 || b==0){return 0;}
else{return 1;}}

int orr(){
if(a==0 && b==0){return 0;}
else{return 1;}}
};




class AND:public gates{
public:
void printdata(){printf("output is %d\n",annd());}};





class OR:public gates{
public:
void printdata(){printf("output is %d\n",orr());}}; 




class NOT:public gates{
public:
void printdata(){
if (a==1){c=0;}
else{c=1;}
printf("output is %d\n",c);}};




class NAND:public gates{
public:
void printdata(){
if (annd()==1){c=0;}
else{c=1;}
printf("output is %d\n",c);}};




class NOR:public gates{
public:
void printdata(){
if (orr()==1){c=0;}
else{c=1;}
printf("output is %d\n",c);}}; 





class XOR:public gates{
public:
void printdata(){    
if(a==0 && b==0)
{c=0;}
else if(a==0 && b==1)
{c=1;}
else if(a==1 && b==0)
{c=1;}
else if (a==1 && b==1);
{c=0;}
printf("output is %d\n",c);}}; 





class XNOR:public gates{
public:
void printdata(){
if(a==0 && b==0){c=1;}
else if(a==0 && b==1){c=0;}
else if(a==1 && b==0){c=0;}
else if(a==1 && b==1);{c=1;}
printf("output is %d\n",c);}}; 








int main(){
int ch;
char choice;
do{printf("\t----------------------MENU-----------------------\n1]Use AND gate\n2]Use OR gate\n3]Use NOT gate\n4]Use NAND gate\n5]Use NOR gate\n6]Use XOR gate\n7]Use XNOR gate\nCHOOSE A GATE\n");
scanf("%d",&ch);
switch(ch){

//And gate
case 1:
do{
AND obj1;
obj1.gettwo();
obj1.annd();
obj1.printdata();
printf("wanna try again\n");
scanf("%s",&choice);
}while(choice=='y'||choice=='Y');
printf("do you want return to main menu\n");
scanf("%s",&choice);
break;

//OR gate
case 2:
do{OR obj;
obj.gettwo();
obj.orr();
obj.printdata();
printf("wanna try again\n");
scanf("%s",&choice);
}while(choice=='y'||choice=='Y');
printf("do you want return to main menu\n");
scanf("%s",&choice);
break;

//not gate
case 3:
do{NOT obj2;
obj2.getone();
obj2.printdata();printf("wanna try again\n");
scanf("%s",&choice);
}while(choice=='y'||choice=='Y');
printf("do you want return to main menu\n");
scanf("%s",&choice);
break;

//nand gate
case 4:
do{NAND obj3;
obj3.gettwo();
obj3.annd();
obj3.printdata();printf("wanna try again\n");
scanf("%s",&choice);
}while(choice=='y'||choice=='Y');
printf("do you want return to main menu\n");
scanf("%s",&choice);
break;

//nor gate 
case 5:
do{NOR obj4;
obj4.gettwo();
obj4.orr();
obj4.printdata();printf("wanna try again\n");
scanf("%s",&choice);
}while(choice=='y'||choice=='Y');
printf("do you want return to main menu\n");
scanf("%s",&choice);
break;

//xor gate
case 6:
do{XOR obj5;
obj5.gettwo();
obj5.printdata();printf("wanna try again\n");
scanf("%s",&choice);
}while(choice=='y'||choice=='Y');
printf("do you want return to main menu\n");
scanf("%s",&choice);
break;

//xnor gate
case 7:
do{XNOR obj6;
obj6.gettwo();
obj6.printdata();printf("wanna try again\n");
scanf("%s",&choice);
}while(choice=='y'||choice=='Y');
printf("do you want return to main menu\n");
scanf("%s",&choice);
break;


case 8:
choice='n';
break;


default:
printf("WRONG CHOICE\n");
printf("do you want return to main menu\n");
scanf("%s",&choice);
break;
}}while(choice=='Y' || choice=='y');
return 0;}


