#include <iostream>
#include <stdlib.h>
#include "linklist.h"
using namespace std;

List<int> a;
ListItr<int> b;
ListItr<int> c;

int Insert () {
        char choice;
        int number;
        b=a.zeroth();
        system("clear");
        cout << "\tInsert Menu"<<endl;
        cout << "\t1.Insert front"<<endl;
        cout << "\t2.Insert back"<<endl;
        cout << "\t3.Insert position"<<endl;
        cout << "\tEnter Choice:\t";
        cin >> choice;

        switch (choice) {

        case '1':
                cout << "Insert front number :";
                cin >> number;
                b = a.zeroth();
                a.insert(number,b);
                break;

        case '2':
                cout << "Insert back number :";
                cin >> number;
                b = a.findPrevious(NULL);
                a.insert(number,b);
                break;

        case '3':
                int p;
                int countList;
                cout << "Print List\n";
                countList = printList(a);
                if (countList > 0) {
                        do {
                                cout<<"Enter Position (not more "<<countList<<") : ";
                                cin>>p;
                                if(p>countList) {
                                        cout<<"No This Position Plase Try Again "<<endl;
                                }
                        } while(p>countList);
                        for(int i=1; i<p; i++) {
                                b.advance();
                        }
                        cout << "Enter Element:";
                        cin >> number;
                        a.insert(number,b);
                        cout<<endl;
                }
                else {
                        cout << "No element in Linklist.\n";
                        cout << "You can choose choice no 1 or 2 to insert element.";
                        cout << endl;
                        Insert ();
                }

                break;
        }
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
}

int Print () {
        int n;
        cout << "\t===Print List==="<<endl;
        n = printList(a);
        cout<<"\tCount of ListNode : "<<n<<endl;
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
}

int Find () {
        int f=0;
        int element;
        cout<<"Enter Element : ";
        cin>>element;
        b=a.zeroth();
        c=a.find(element);

        if(c.retrieve()!=NULL) {
                while(c.retrieve()!=b.retrieve()) {
                        b.advance();
                        f++;
                }
                cout << "Found! This Element is position "<<f;
        }
        else
                cout << "Find Not Found";
        cout << endl;
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
}

int Remove () {
        int element;
        int n = 0;
        int r;
        cout << "Enter Element : ";
        cin >> element;
        r = a.remove(element);
        cout << endl;
        if(r==1) {
                cout<<"This Element is Removed"<<endl;
                n-=r;
        }
        else{
                cout<<"This Element is Not Remove"<<endl;
        }
        cout<<endl;
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
}

bool Exit (bool check) {
        if(check==true) {
                system("clear");
                cout << endl << endl;
                cout << "\t==== Exit Program... ====";
                return false;
        }
        else {
                return true;
        }

}

int main () {
        int number;
        char choice;
        bool exit = Exit(false);
        do {
                system("clear");
                cout << endl;
                cout << "\t===== Linked List ====="<<endl;
                cout << "\t1.Insert"<<endl;
                cout << "\t2.Print"<<endl;
                cout << "\t3.Find"<<endl;
                cout << "\t4.Remove"<<endl;
                cout << "\t5.Exit"<<endl;
                cout << "\tEnter Choice:\t";
                cin >> choice;
                cout << endl;

                switch (choice) {
                case '1': Insert(); break;
                case '2': Print(); break;
                case '3': Find(); break;
                case '4': Remove(); break;
                case '5': exit = Exit(true); break;

                }
        } while(exit);
        return 0;
}
