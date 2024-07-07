#include <bits/stdc++.h>
using namespace std;

//STATE
class state
{
        public:
                vector<state*> ptr;
        char nature;	//i or f
        char name;
        state(char s1, int n)
        {
                name = s1;
                for (int i = 0; i < n; i++)
                {
                        ptr.push_back(nullptr);
                }
        }
};

//FINITE AUTOMATA 
class automata
{
        private:
                string name;
        char c;
        vector<char> symbol;
        int n;
        map<char, state*> map1;
        public:
                automata()
                {
                        cout << "enter the number of symbols = ";
                        cin >> n;
                        for (int i = 0; i < n; i++)
                        {
                                cout << "put " << i + 1 << " symbol =";

                                cin >> c;
                                symbol.push_back(c);
                        }
                }

        state* get_state();
        void link_state();
        void show_states();
        bool get_language();

};

//function to get string from user
bool automata::get_language()
{
        int flag = 0;
        cout << endl << "Enter the string --> ";
        cin >> name;
        state * temp;
        for (auto x: map1)	//selecting inital state
        {
                if (x.second->nature == 'i' || x.second->nature == 'b')
                {
                        temp = x.second;
                }
        }

        for (int i = 0; i < name.size(); i++)
        {
                flag = 0;
                for (int j = 0; j < symbol.size(); j++)
                {
                        if (name[i] == symbol[j])
                        {
                                temp = temp->ptr[j];

                                flag = 1;
                        }
                }

                if (!flag)
                {
                        cout << "INVALID STRING" << endl;
                        return false;
                }
        }

        if (temp->nature == 'f' || temp->nature == 'b')
        {
                return true;
        }

        return false;

}

//function to show state transition table
void automata::show_states()
{
        string s1, s2;
        cout << "-----------------------------------------------------------" << endl;
        cout << "state        next states" << endl;
        cout << "\t\t\t\t";
        for (int i = 0; i < symbol.size(); i++)
        {
                cout << symbol[i] << "\t";
        }

        cout << endl;
        for (auto x: map1)
        {
                cout << x.first << "\t\t\t\t";
                for (int k = 0; k < symbol.size(); k++)
                {
                        for (auto y: map1)
                        {
                                if (y.second == x.second->ptr[k])
                                {
                                        cout << y.first << "\t";
                                }
                        }
                }
        
        cout<<endl;    
        }

        for (auto x: map1)
        {
                if (x.second->nature == 'i' || x.second->nature == 'b')
                {
                        cout << endl << "Initial state is =" << x.first << endl;
                }

                if (x.second->nature == 'f' || x.second->nature == 'b')
                {
                        cout << "final state is =" << x.first << endl;
                }
        }

        cout << "-----------------------------------------------------------" << endl;
}

//function to form DFA
void automata::link_state()
{
        int choice;
        state * main;

        do {
                main = get_state();
                for (int i = 0; i < symbol.size(); i++)
                {
                        cout << "is their a transition for {" << symbol[i] << "} (1/0) = ";
                        cin >> choice;
                        if (choice)
                        {
                                cout << "DOING STATE TRANSITION ON ->" << symbol[i] << endl;

                                main->ptr[i] = get_state();
                        }
                        else
                        {
                                main->ptr[i] = main;
                        }
                }

                cout << "DO YOU WANT TO ANOTHER STATE? ";
                cin >> choice;
        } while (choice == 1);

}

//function to get state from user
state *automata::get_state()
{
        cout << "ENTER THE NAME OF THE STATE =  ";
        cin >> c;

        if (map1.find(c) == map1.end())
        {
                state * temp;
                temp = new state(c, this->n);

                cout << "NATURE OF STATE\ni for initial\nf for final state\nn for normal state \nb for both initial and final " << endl;
                cin >> temp->nature;
                map1[c] = temp;
                return temp;
        }
        else
        {
                return map1[c];
        }
}

//main function
int main()
{
        automata s1;
        int choice;
        s1.link_state();
        s1.show_states();
        do {
                if (s1.get_language())
                {
                        cout << endl << "Hooray!!!STRING ACCEPTED" << endl;
                }
                else
                {
                        cout << endl << "Ooops!!! STRING REJECTED " << endl;
                }

                cout << endl << "choice to try another string(1/0)" << endl;
                cin >> choice;
        } while (choice == 1);
        cout << endl << "THANKYOU" << endl;
        return 0;
}
