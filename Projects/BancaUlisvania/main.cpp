#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

void ArataBalance(double balanta);
double depozit();
double withdraw(double balanta);

int main()
{
    double balanta = 100;
    int choice = 0;
    do{

        cout << "Banca Ulisvania yey\n";
        cout << "Selecteaza o varianta:\n";
        cout << "1. Arata balanta\n";
        cout << "2. Depoziteaza\n";
        cout << "3. Ia bani\n";
        cout << "4. Iesi (O hel na)\n";
        cout << "Please make ur choice.\n";
        cin >> choice;

        cin.clear();
        fflush(stdin);
        system("cls");

        switch(choice){

         case 1: ArataBalance(balanta);
                 break;
         case 2:balanta += depozit();
                ArataBalance(balanta);
                break;
         case 3:balanta -= withdraw(balanta);
                ArataBalance(balanta);
                break;
         case 4:cout << "Pa sper sa nu iti cada tavanu in cap\n";
                break;
         default: cout << "Connection terminated pls try agian\n";

        }
    }while(choice != 4);
    return 0;
}

void ArataBalance(double balanta){
    cout << "Tu ai: $" << setprecision(2) << fixed << balanta << '\n';
}
double depozit(){
    double bani;

    cout << "Cat vrei sa depozitezi? \n" << '$';
    cin >> bani;

    if(bani < 0)
    cout << "Valoare invalida \n";
     else return bani;

}
double withdraw(double balanta){
    double bani;

    cout << "Cat vrei sa iei?\n" << '$';
    cin >> bani;

    if(bani < 0) cout << "Valoare invalida\n";
     else if(bani > balanta) cout << "Nu ai deajunsi bani\n";
      else return bani;
}
