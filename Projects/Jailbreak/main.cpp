#include <iostream>
#include <ctime>
#include <iomanip>
#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

fstream hscor;

int risk;
int bank(int risk, int ore, int mins);
int jewelry(int risk, int ore,int mins);
int casino(int risk, int ore, int mins);
int gas(int risk, int ore, int mins);
int mansion(int risk, int ore, int mins);
int bank(int risk, int ore, int mins);
int donut(int risk, int ore, int mins);
void showbalance(int balance);
int work(int ore, int mins);
int ore;
int mins;
int highscore;
int highscorev;

int main()
{
    char SalutStiuCaCodulMeuECamGoofyAsaCaCryAboutIt;
    bool exitt = true;
    char rsp;
    int balance = 100;
    char choice;
    bool chill = true;
    bool chill2 = true;
    bool jail = false;
    srand(time(NULL));

do{
  if(ore != 24 && chill2){
    if(ore < 10 && mins < 10) cout << "\n***JAILBREAK***         RISK      TIME      VALUE      22:00-07:00                             Time:0" << ore << ":0" << mins << '\n';
     else if(ore < 10) cout << "\n***JAILBREAK***         RISK      TIME      VALUE      22:00-07:00                             Time:0" << ore << ":" << mins << '\n';
      else if(mins < 10) cout << "\n***JAILBREAK***         RISK      TIME      VALUE      22:00-07:00                             Time:" << ore << ":0" << mins << '\n';
       else cout << "\n***JAILBREAK***         RISK      TIME      VALUE      22:00-07:00                             Time:" << ore << ":" << mins << '\n';
    cout << "Make your choice\n";
    cout << "1.Work                   0%        8h        100$ \n";
    cout << "2.Rob The Donut Store    5%        30m       25$ \n";
    cout << "3.Rob The Gas Station    10%       30m       50$ \n";
    cout << "4.Rob The Jewelry Store  25%       1h        250$      (NIGHT ONLY)\n";
    cout << "5.Rob The Bank           33%       2h        1000$     (NIGHT ONLY)\n";
    cout << "6.Rob The Casino         50%       4h        5000$     (NIGHT ONLY)\n";
    cout << "7.Rob The Mansion        75%       6h        12500$    (NIGHT ONLY)\n";
    cout << "8.Exit\n";
    cout << "9.How to play\n";
    cout << "Please make ur choice\n";
    showbalance(balance);
    cout << '\n' << '\n';

    choice = getch();




    risk = (rand() % 100) + 1;

    switch (choice){
      case '1':  cout << "Are you sure you want to Work? (Y/N)\n";
                cin >> rsp;
                if(rsp == 'y' || rsp == 'Y'){ balance+=work(ore, mins);
                                            if(work(ore, mins) != 0) ore+=8; }
                else balance+=0;
                break;
      case '2':   cout << "Are you sure you want to rob the donut store?(Y/N)\n";
                cin >> rsp;
                if(rsp == 'y' || rsp == 'Y'){ balance+=donut(risk, ore, mins);
                                              if(risk <= 95) mins+=30;
                                                 else chill2 = false, mins+=30;
                                        }
                break;
      case '3':   cout << "Are you sure you want to rob the gas station?(Y/N)\n";
                cin >> rsp;
                if(rsp == 'y' || rsp == 'Y'){ balance+=gas(risk, ore, mins);
                                              if(risk <= 90) mins+=30;
                                                 else chill2 = false, mins+=30;
                                        }
                break;
      case '4': if(((ore < 7) || (ore == 7 && mins == 0)) || ((ore > 22) || (ore == 22 && mins >= 0))){
                    cout << "Are you sure you want to rob the jewelry store?(Y/N)\n";
                    cin >> rsp;
                    if(rsp == 'y' || rsp == 'Y'){ balance+=jewelry(risk, ore, mins);
                                              if(risk <= 75) chill2 = true;
                                                 else chill2 = false, mins+=30;
                                              if(jewelry(risk, ore, mins) != 0) ore++;

                                        }
                    break;
                }
                 else{ cout << "||This is only available during the night!||\n||This is only available during the night!||\n";
                       break;
                   }
      case '5': if(((ore < 7) || (ore == 7 && mins == 0)) || ((ore > 22) || (ore == 22 && mins == 0))){
                    cout << "Are you sure you want to rob the bank?(Y/N)\n";
                    cin >> rsp;
                    if(rsp == 'y' || rsp == 'Y'){ balance+=bank(risk, ore, mins);
                                              if(risk <= 66) chill2 = true;
                                                 else chill2 = false, ore++;
                                              if(bank(risk, ore, mins) != 0) ore+=2;

                                        }
                    break;
                }
                 else{ cout << "||This is only available during the night!||\n||This is only available during the night!||\n";
                       break;
                   }
      case '6': if(((ore < 7) || (ore == 7 && mins == 0)) || ((ore > 22) || (ore == 22 && mins == 0))){
                    cout << "Are you sure you want to rob the casino?(Y/N)\n";
                    cin >> rsp;
                    if(rsp == 'y' || rsp == 'Y'){ balance+=casino(risk, ore, mins);
                                              if(risk <= 50) chill2 = true;
                                                 else chill2 = false, ore+=2;
                                              if(casino(risk, ore, mins) != 0) ore+=4;

                                        }
                    break;
                }
                 else{ cout << "||This is only available during the night!||\n||This is only available during the night!||\n";
                       break;
                   }
      case '7': if(((ore < 7) || (ore == 7 && mins == 0)) || ((ore > 22) || (ore == 22 && mins == 0))){
                    cout << "Are you sure you want to rob the MANSION?(Y/N)\n";
                    cin >> rsp;
                    if(rsp == 'y' || rsp == 'Y'){ balance+=mansion(risk, ore, mins);
                                              if(risk <= 25) chill2 = true;
                                                 else chill2 = false, ore+=3;
                                              if(mansion(risk, ore, mins) != 0) ore+=6;

                                        }
                    break;
                }
                 else{ cout << "||This is only available during the night!||\n||This is only available during the night!||\n";
                       break;
                   }
      case '8': cout << "Are you sure you want to EXIT?(Y/N)\n";
              cin >> rsp;
              if(rsp == 'y' || rsp == 'Y') exitt = false;
              break;
      case '9': cout << "How to play:\n1. Unele locuri pot fi jefuite doar noapte, iar noaptea este intre ora 22:00 si 7:00.\n2. Fiecare loc de jefuit are risk timp si valorare.\n Riskul este procentul care determina care este sansa ta de a fi prins de politie.\n Timpul determina cat timp va dura sa jefuiesti acel loc (Poti vedea cat este ceasul in dreapta sus).\n Valoare determina cati bani vei primi de la acel jaf.\n3. Daca esti prins de politie poti sa dai 1000$ ca sa scapi, daca nu pierzi.\nglhf.\n";
//              cout <<"\nPress Enter To Return";
//              while(SalutStiuCaCodulMeuECamGoofyAsaCaCryAboutIt != ) cin >> SalutStiuCaCodulMeuECamGoofyAsaCaCryAboutIt;
              system("pause");
              system("cls");
              break;
      default: cout << "Connection terminated pls try again.";

    }
    if(chill2 == false){
            cout << "You've been caught by the police\n";
            if(balance >= 1000){do{ cout << "Would you like to buy a get out of jail ticket for 1000$?(Y/N)\n";
                                cin >> rsp;
                                if(rsp == 'y' || rsp == 'Y')balance-=1000, chill2 = true;}while(rsp != 'Y' && rsp != 'y' && rsp != 'N' && rsp != 'n');
                                }
                                else chill = false;
    }
    if(mins == 60) ore++, mins = 0; if(mins > 60) ore++, mins-=60;
  }
   else chill = false;
 }while(chill && exitt);

    if(ore == 24) cout << "The time limit has been reached!\n";

    cout << "Your final score is: " << balance << '$' << '!';
    hscor.open("highscore.txt", ios::in);
    hscor >> highscorev;
    if(highscorev >= balance)
    {
        highscore = highscorev;
        cout << "\n\nHighscore: " << highscore;
        hscor.close();
    }
        else
        {
            highscore = balance;
            cout << "\n\nNEW HIGHSCORE!!!: " << highscore;
            hscor.close();
            hscor.open("highscore.txt", ios::out);
            hscor << highscore;
            hscor.close();

        }
    return 0;
}
void showbalance(int balance){
    cout << "\nYou have: " << balance << '$' << '\n';
}
int work(int ore, int mins){

    if(ore == 16 && mins > 0 || ore > 16){
        cout << "||Not enough time||\n";
        return 0;
        }
            else{
            cout << "||You've succesfully worked for 100$||\n";
            return 100;
            }
  }
int donut(int risk, int ore, int mins){

    if(risk <= 95){
        cout << "||You've succesfully robbed the donut store for 25$||\n||You've succesfully robbed the donut store for 25$||\n";
        return 25;
    }
    else{
        return 0;
    }
}
int gas(int risk, int ore, int mins){

    if(risk <= 90){
        cout << "||You've succesfully robbed the gas station for 50$||\n||You've succesfully robbed the gas station for 50$||\n";
        return 50;
    }
    else{
        return 0;
    }
}
int jewelry(int risk, int ore, int mins){
    if(ore == 23 && mins > 0){
                    cout << "||Not enough time||\n";
                    return 0;
                    }
        else {
            if(risk <= 75) {
                cout << "||You've succesfully robbed the jewelry store for 250$||\n";
                return 250;
            }
            else return 0;
        }

}
int bank(int risk, int ore, int mins){
    if((ore == 22 && mins > 0) || ore > 22){
                    cout << "||Not enough time||\n";
                    return 0;
                    }
        else {
            if(risk <= 66) {
                cout << "||You've succesfully robbed the bank for 1000$||\n";
                return 1000;
            }
            else return 0;
        }

}
int casino(int risk, int ore, int mins){
    if((ore == 20 && mins > 0) || ore > 20){
                    cout << "||Not enough time||\n";
                    return 0;
                    }
        else {
            if(risk <= 50) {
                cout << "||You've succesfully robbed the casino for 5000$||\n";
                return 5000;
            }
            else return 0;
        }

}
int mansion(int risk, int ore, int mins){
    if((ore == 18 && mins > 0) || ore > 18){
                    cout << "||Not enough time||\n";
                    return 0;
                    }
        else {
            if(risk <= 25) {
                cout << "||You've succesfully robbed the MANSION for 12500$!!!||\n";
                return 12500;
            }
            else return 0;
        }

}
