///Rezolvare problema EasyQuery
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("easyquery.in");
ofstream fout("easyquery.out");

const int nm=100003;
int i,x,y,p,t,n,k;
long long int a[nm], b[nm]; /// b-vectorul pentru diferente

int main()
{
    fin>>n;
    for(i=1; i<=n; i++)
        fin>>a[i];

    fin>>t;
    for(i=1; i<=t; i++)
    {
        fin>>k>>x>>y>>p;
        if(k==1)
        {
            b[x]+=p;    /// daca k=1 se cresc valorile din intervalul x y cu val p
            b[y+1]-=p;
        }
        else
        {
            b[x]-=p;    /// se scad valorile de pe pozitiile de la x la y cu val p
            b[y+1]+=p;
        }
    }

    for(i=1; i<=n; i++)
    {
        b[i]+=b[i-1];
        fout<<a[i]+b[i]<<" ";
    }
    return 0;
}
