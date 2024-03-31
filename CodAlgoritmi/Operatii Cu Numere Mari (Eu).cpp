#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin ("numere.in");

struct NrMare{int n, c[1000];};
char s;
string n1, n2;

NrMare nr1, nr2, nr3;
NrMare conversie(string s)
{
    NrMare x;
    memset(&x, 0, sizeof(x)); //& pentru adresa de memorie
    x.n = s.size(); //lungimea lui s
    for(int i = 0; i < x.n; i++)
        x.c[i] = s[x.n - i - 1] - '0';
        //-1 fiindca e de la zero
        //s[luam caracterul(cifra)]
        //- '0' pt ca transform in int
        return x;
}
void afis(NrMare x)
{
    for(int i = x.n-1; i >= 0; i--)
        cout << x.c[i];
    cout << '\n';
}
NrMare add(NrMare x, NrMare y)
{
    NrMare z;
    int t = 0;
    memset(&z, 0, sizeof(z));
    z.n = max(x.n, y.n);
    for(int i = 0; i < z.n; i++)
    {
        z.c[i] = x.c[i] + y.c[i] + t;
        t = z.c[i] / 10; // t - ce tinem minte practic
        z.c[i] %= 10; //sa fie cifra
    }
    if(t > 0)
        z.c[z.n++] = t;
    return z;
}

NrMare operator+(NrMare x, NrMare y)
{
    NrMare z;
    int t = 0;
    memset(&z, 0, sizeof(z));
    z.n = max(x.n, y.n);
    for(int i = 0; i < z.n; i++)
    {
        z.c[i] = x.c[i] + y.c[i] + t;
        t = z.c[i] / 10;
        z.c[i] %= 10;
    }
    if(t > 0)
        z.c[z.n++] = t;
    return z;
}
NrMare inmul(NrMare x, NrMare y) //daca suntem siguri ca x, y nu se modifica
                                 //putem pune &(referinta) ca sa nu mai copieze
{
    NrMare z;
    int t = 0;
    memset(&z, 0, sizeof(z));
    z.n = x.n + y.n;
    for(int i = 0; i < x.n; i++)
        for(int j = 0; j < y.n; j++)
            z.c[i+j] += x.c[i] * y.c[j];
    for(int i = 0; i < z.n; i++)
    {
        z.c[i] += t;
        t = z.c[i] / 10;
        z.c[i] %= 10;
    }
    while (z.n > 1 && z.c[z.n-1] == 0)
        z.n--;
    return z;

}
// compar x cu y
// x < y => return -1;
// x == y => return 0;
// x > y => return 1;
int cmp(NrMare x, NrMare y)
{
    int i;
    if(x.n > y.n) return 1;
    if(x.n < y.n) return -1;
    for(i = x.n-1; i >= 0 && x.c[i] == y.c[i]; i--);
    if(i == -1) return 0; // sunt egale
    if(x.c[i] > y.c[i]) return 1;
    return -1;

}
NrMare scad(NrMare x, NrMare y)
{
    NrMare z;
    int imprum = 0;
    memset(&z, 0, sizeof(z));
    int rsp = cmp(x, y);
    if(rsp == 1) swap (x, y);
    z.n = max(x.n, y.n);
    for(int i = 0; i < z.n; i++)
    {
        x.c[i] += imprum;
        imprum = 0;
        if(y.c[i] < x.c[i])
        {
            z.c[i] = 10 - x.c[i] + y.c[i] - imprum;
            imprum = 1;
        }
        else z.c[i] = y.c[i] - x.c[i];
    }

    while(z.n > 1 && z.c[z.n-1] == 0)
        z.n--;

    return z;
}

int pw(int a, int n)
{
    int p = 1;
    while(n)
    {
        if(n % 2 == 1) p = p*a;
        a = a*a;
        n/=2;
    }
    return p;
}
int main()
{
    fin >> s >> n1 >> n2;
    nr1 = conversie(n1);
    nr2 = conversie(n2);
    if(s == '+')
    {   //adunare
        nr3 = nr1 + nr2;
        afis(nr3);
    }
    else if(s == '*')
    {   //inmultire
        afis(inmul(nr1, nr2));

    }
    else if(s == '-')
    {   //scadere
        afis(scad(nr1, nr2));
    }
    else if(s == '<')
    {
        //mai mic
        cout << cmp(nr1, nr2);
    }
    return 0;
}
