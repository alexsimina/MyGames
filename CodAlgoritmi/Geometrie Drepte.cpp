#include <iostream>
#include <cmath>
using namespace std;

struct coordonate{int x, y;};

int tip, c1, c2, xx, yy, ecdreapta;
coordonate A, B, C, D;

int main()
{
    cin >> A.x >> A.y >> B.x >> B.y;
    cout << "\n\n1: Lungime dreapta.\n2. Pozitie C\n3. Punct de intersectie a dreptei CD\n4. Distanta punctului C de la dreapta AB";
    cin >> tip;

    if(A.x >= B.x)
        swap(B.x, A.x);

    if(B.y >= A.y)
        swap(B.y, A.y);

    c1 = A.y - B.y;
    c2 = B.x - A.y;

    if(tip == 1)
        cout << sqrt(c1*c1 + c2*c2);

    else if(tip == 2)
    {
        cin >> C.x >> C.y;
        ecdreapta = C.x*(B.y - A.y) + C.y*(A.x - B.x) + A.y * B.x - A.x * B.y;
        if(ecdreapta == 0) cout << "\nPe dreapta";
        else if(ecdreapta < 0) cout << "\Peste dreapta";
        else cout << "\Sub dreapta";
    }
    else if(tip == 3)
    {
        //to do
    }
    else if(tip == 4)
    {
        cin >> C.x >> C.y;
        ecdreapta = abs(C.x*(B.y - A.y) + C.y*(A.x - B.x) + A.y * B.x - A.x * B.y);

        cout << ecdreapta / sqrt((B.y - A.y) * (B.y -A.y) + (A.x - B.x) * (A.x - B.x));
    }
    return 0;
}
