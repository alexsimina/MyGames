#include <bits/stdc++.h>

using namespace std;

const int nm=1e7+1;///1*10^7+1, 10000001
int i, j, x;
char a[nm];

/// ciurul se foloseste doar daca avem de testat multe numere daca sunt prime sau nu
int main()
{
    /// ciurul lui eratostene
    a[0] = a[1] = 1; /// numerele 1 si 0 nu sunt prime
    for(i=2; i*i<nm; i++)
        if(a[i]==0) /// daca numarul i este prim
            for(j=i*i; j<nm; j+=i) a[j] = 1; /// multiplii nu sunt numere prime

    /// verificare numar prim
    cin >> x;
    if(a[x]==0) cout << "prim";
    else cout << "nu e prim";

    return 0;
}
