#include<iostream>

#include<vector>

using namespace std;

//class process  
class process {
  public: int at,bt,bt1,ct,position,firsttime,flag;
  string name;

  process() {
    at = bt = bt1=-1;
    ct = 0;
    position = -1;
    firsttime = -1;
    flag = 0;
    name = "null";
  }
};

//class round robin
class rr {

  public: int s,
  rear = 0,
  i = 0;
  process * arr;
  vector < process > v1;

  int Time = 0;
  rr(int s) {
    arr = new process[s];
  }

  void getdata();
  void display();
  void display2();
  void sort();
  void filler();
  void operation();
};

void rr::getdata() {

  cout << "----------------------------------------------------------\n";
  this -> display();
  cout << "----------------------------------------------------------\n\n";
  cout << "ENTRIES:-\n----------------------------------------------------------\n";

  for (int i = 0; i < s; i++) {
    cout << "Enter process name\t";
    cin >> arr[i].name;
    cout << "Enter arrival time\t";
    cin >> arr[i].at;
    cout << "Enter burst time \t";
    cin >> arr[i].bt;
    arr[i].bt1=arr[i].bt;
    arr[i].position = i;
  }

  cout << "\n----------------------------------------------------------\n";

  cout << "\n\n\nINPUT:-\n----------------------------------------------------------\n";
  this -> display();
  cout << "----------------------------------------------------------\n";

  this -> operation();
  cout << "\n\nOUTPUT:-\n----------------------------------------------------------\n";
  this -> display2();
  cout << "----------------------------------------------------------\n";
}

void rr::filler() {

  while (arr[i].at <= Time && i < s) {

    v1.push_back(arr[i]);
    i++;
  }
}

void rr::operation() {
  int flag, flag2;
  int quantum;
  this -> sort();
  cout << "enter your quantum" << endl;
  cin >> quantum;
  this -> filler();

  do {
    flag = 0;

    /*if (v1[rear+1].at>v1[rear].bt && v1.size()>=2){
    	cout<<"\ntime increased by --"<<(v1[rear].at>v1[rear].bt)<<endl;
    	Time=Time+(v1[rear].at>v1[rear].bt);
    	
    }*/

    this -> filler();

    if (rear < v1.size()) {

      if (v1[rear].bt <= quantum) {

        if (v1[rear].flag == 0) {
          arr[v1[rear].position].firsttime = Time;
          arr[v1[rear].position].flag = 1;
        }
        Time = Time + v1[rear].bt;
        flag = 1;
        arr[v1[rear].position].bt = 0;
        arr[v1[rear].position].ct = Time;
        this -> filler();
      } else {
        if (v1[rear].flag == 0) {
          arr[v1[rear].position].firsttime = Time;
          arr[v1[rear].position].flag = 1;
        }
        arr[v1[rear].position].bt = arr[v1[rear].position].bt - quantum;

        Time = Time + quantum;
        flag = 1;
        this -> filler();
        v1.push_back(arr[v1[rear].position]);
      }
      rear++;
    }

    if (flag != 1) {
      Time++;
    }

    for (int i = 0; i < s; i++) {

      if (arr[i].bt != 0) {
        flag2 = 1;
        break;
      } else {
        flag2 = 0;
      }
    }

  } while (flag2 != 0);
  cout << endl;
  for (int i = 0; i < v1.size(); i++) {
    cout << v1[i].name << " | ";

  }

}

void rr::display2() {
  float avgres = 0, avgwt = 0, avgct = 0;
  cout << "Processes|Arrival time |Burst time |Compeletion time|TATime|wait time|Response time\n";
  for (int i = 0; i < s; i++) {
    cout << arr[i].name << "\t" << arr[i].at << "\t" << arr[i].bt1 << "\t" << arr[i].ct << "\t" << arr[i].ct - arr[i].at << "\t" << (arr[i].ct - arr[i].at) - arr[i].bt1 << "\t" << arr[i].firsttime - arr[i].at << endl;
    avgres = avgres + arr[i].firsttime - arr[i].at;
    avgwt = avgwt + (arr[i].ct - arr[i].at) - arr[i].bt1;
    avgct = avgct + arr[i].ct;
  }
  cout << "\n#Average waiting time- " << avgwt / s << endl;
  cout << "\n#Average completion time- " << avgct / s << endl;
  cout << "\n#Average response time- " << avgres / s << endl;
}

//sorting processes in ascending order of arrival timr
void rr::sort() {
  int temp, temp2;
  string temp1;

  for (int i = 0; i < s; i++) {
    for (int j = i + 1; j < s; j++) {
      if (arr[i].at > arr[j].at) {
        temp = arr[i].at;
        temp1 = arr[i].name;
        temp2 = arr[i].bt;
        arr[i].at = arr[j].at;
        arr[i].name = arr[j].name;
        arr[i].bt = arr[j].bt;
        arr[i].bt1 = arr[j].bt1;
        arr[j].at = temp;
        arr[j].name = temp1;
        arr[j].bt = temp2;
         arr[j].bt1= temp2;
        arr[j].position = j;
        arr[i].position = i;
      }
    }
  }

}

//Display 

void rr::display() {
  cout << "Processes|Arrival time |Burst time | \n";
  for (int i = 0; i < s; i++) {

    cout << arr[i].name << "\t\t\t" << arr[i].at << "\t\t\t\t" << arr[i].bt1 << endl;

  }

}

int main() {
  int size;
  cout << "Enter the number of processes\n";
  cin >> size;
  rr obj(size);

  obj.s = size;

  obj.getdata();

  return 0;
}
