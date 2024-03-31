#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("numere.in");

struct NrMare
{
    int n, c[1000];
};

char s;
string n1, n2;
NrMare nr1, nr2, nr3;

NrMare conversie(string s)
{
    NrMare x;
    memset(&x,0, sizeof(x));
    x.n = s.size();
    for(int i=0; i<x.n; i++)
        x.c[i] = s[x.n-i-1]-'0';
    return x;
}

void afis(NrMare x)
{
    for(int i = x.n-1; i>=0; i--)cout << x.c[i];
    cout << endl;
}
NrMare add(NrMare x, NrMare y)
{
    NrMare z;
    int t = 0;
    memset(&z,0, sizeof(z));
    z.n = max(x.n, y.n);
    for(int i=0; i<z.n; i++)
    {
        z.c[i] = x.c[i] + y.c[i] + t;
        t = z.c[i]/10;
        z.c[i]%=10;
    }
    if(t>0)z.c[z.n++] = t;
    return z;
}

NrMare operator+(NrMare x, NrMare y)
{
    NrMare z;
    int t = 0;
    memset(&z,0, sizeof(z));
    z.n = max(x.n, y.n);
    for(int i=0; i<z.n; i++)
    {
        z.c[i] = x.c[i] + y.c[i] + t;
        t = z.c[i]/10;
        z.c[i]%=10;
    }
    if(t>0)z.c[z.n++] = t;
    return z;
}

NrMare inmul(NrMare &x, NrMare &y)
{
    NrMare z;
    int t = 0;
    memset(&z,0, sizeof(z));
    z.n = x.n + y.n;
    for(int i=0; i<x.n; i++)
        for(int j=0; j<y.n; j++)
            z.c[i+j]+=x.c[i]*y.c[j];
    for(int i=0; i<z.n; i++)
    {
        z.c[i]+=t;
        t = z.c[i]/10;
        z.c[i]%=10;
    }
    while(z.n>1 && z.c[z.n-1]==0)z.n--;
    return z;
}

int pw(int a, int n)
{
    int p=1;
    while(n)
    {
        if(n%2==1)p=p*a;
        a = a*a;
        n/=2;
    }
    return p;
}

/// compar x cu y, x<y ret -1, x==y ret 0, x>y ret 1
int cmp(NrMare x, NrMare y)
{
    int i;
    if(x.n>y.n)return 1;
    if(x.n<y.n)return -1;
    for(i=x.n-1; i>=0 && x.c[i]==y.c[i]; i--);
    if(i==-1)return 0;
    if(x.c[i]>y.c[i]) return 1;
    return -1;
}

int operator<(NrMare x, NrMare y)
{
    int i;
    if(x.n>y.n)return 0;
    if(x.n<y.n)return 1;
    for(i=x.n-1; i>=0 && x.c[i]==y.c[i]; i--);
    if(i==-1)return 0;
    if(x.c[i]>y.c[i]) return 0;
    return 1;
}
int main()
{
    fin >> s >> n1 >> n2;
    nr1 = conversie(n1);
    nr2 = conversie(n2);
    if(s=='+')
    {
        nr3 = nr1 + nr2;
        afis(nr3);
    }
    if(s=='*')
    {
        afis(inmul(nr1, nr2));

    }
    if(s=='-')
    {

    }
    if(s=='<')
    {
        cout << cmp(nr1,nr2);
        if(nr1<nr2)cout << "adev";
        else cout << "fals";

    }


    return 0;
}
