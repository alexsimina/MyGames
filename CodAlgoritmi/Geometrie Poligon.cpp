#include <iostream>

using namespace std;

struct coordonata{int x, y;};

int n, arie, maxX;
coordonata pcte[1000];
int i;

int main()
{
    cout << "Cate puncte?\n";
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> pcte[i].x >> pcte[i].y;
    cout << "\n\n1. Arie Poligon\n2. se afla punctul C in interiorul poligonului?\n"
    for(i = 1; i <= n; i++)
        arie += pcte[i].x * pcte[i+1].y - pcte[i+1].x * pcte[i].y;

    cout << '\n' << arie/2;
    return 0;
}
