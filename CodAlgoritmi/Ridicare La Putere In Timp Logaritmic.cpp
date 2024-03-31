///Ridicare La Putere In Timp Logaritmic
#include <iostream>

using namespace std;

int pw(int x, int n) /// ridica pe x la puterea n
{
    int p=1;
    while(n)
    {
        if(n%2==1)p*=x;
        x=x*x;
        n/=2;
    }
    return p;
}


int pwmod(int x, int n, int mo) /// ridica pe x la puterea n, modul mo
{
    int p=1;
    while(n)
    {
        if(n%2==1)p=p*x%mo;
        x=x*x%mo;
        n/=2;
    }
    return p;
}

int putere, baza, mo;

int main()
{
    cout << "baza + putere + modulo\n";
    cin >> baza >> putere >> mo;
    cout << "\nNormal: " << pw(baza, putere);
    cout << "\nModulo: " << pwmod(baza, putere, mo);
    cout << '\n';
    return 0;
}
