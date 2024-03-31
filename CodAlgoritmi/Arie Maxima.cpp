#include <bits/stdc++.h>

using namespace std;

const int NM_MAX = 400;  //Limita vectorilor
int NrRanduri, NrColoane;   //Numarul de randuri / coloane
bool Matrice[NM_MAX + 2][NM_MAX + 2];   //Matrice care contine doar 0 si 1
int MatCrescatoare[NM_MAX + 2][NM_MAX + 2]; //Matricea initiala, dar crescatoare daca spatiul este liber (*)
int Histograma[NM_MAX + 2];  //MatCrescatoare transformata intr-o histograma
int MemoratorDeHistoCrescatoare[NM_MAX + 2];     //Memoreaza pozitia histogramelor crescatoare dintr-un sir crescator.
int EsteCrescator;      //Pentru verficare daca sirul inca mai este crescator, macar daca ultima histograma din sir este mai mare ca prima
int Stanga[NM_MAX + 2], Dreapta[NM_MAX + 2];      //Memoreaza limitele dintr-un sir crescator
int i, j, MaxArie;

//MatCrescatoare creste daca pe pozitia dinaintea ei este 0 (liber), altfel devine 0. Cresterea este doar pe coloane.
//Exemplu : 0 -> 1
//          0 -> 2
//          0 -> 3
//          1 -> 0
int main () {

    cin >> NrRanduri >> NrColoane;
    for (i = 1; i <= NrRanduri; i++)
        for (j = 1; j <= NrColoane; j++)
        {
            //Citire
            cin >> Matrice[i][j];
            if (Matrice[i][j] == 1) MatCrescatoare[i][j] = 0;   //Daca spatiul este ocupat (1) MatCrescatoare = 0
            else MatCrescatoare[i][j] = MatCrescatoare[i - 1][j] + 1;   //Daca spatiul este liber(0) MatCrescatoare creste.

        }

    for (i = 1; i <= NrRanduri; i++) {
        for (j = 1; j <= NrColoane; j++)
            Histograma[j] = MatCrescatoare[i][j]; //transformam MatCrescatoare intr-o histograma

        //Gasim limita la stanga
        EsteCrescator = 0;
        MemoratorDeHistoCrescatoare[0] = 0;
        for (j = 1; j <= NrColoane; j++) {

            while (EsteCrescator > 0 && Histograma[MemoratorDeHistoCrescatoare[EsteCrescator]] >= Histograma[j])
                EsteCrescator--; //Daca EsteCrescator e mai mare ca 0 el va scade daca histograma dinainte lui
            //adica Histograma[MemoratorDeHistoCrescatoare[EsteCrescator]] este mai mare. Scazand din EsteCrescator
            //histograma dinainte lui se va schimba cu una, doua sau mai multe poziti in spate in functie de EsteCrescator


            Stanga[j] = MemoratorDeHistoCrescatoare[EsteCrescator] + 1; //Memoreaza indicele histogramei
            EsteCrescator++;                                            //Creste cu 1 in caz de e crescator altfel scade la while
            MemoratorDeHistoCrescatoare[EsteCrescator] = j;             //Memoreaza pozitia histogramei de la care incepe sa fie crescator


        }

        EsteCrescator = 0;
        MemoratorDeHistoCrescatoare[0] = NrColoane + 1;

        //Gasire limita de la dreapta pentru j
        for (j = NrColoane; j >= 1; j--) {

            while (EsteCrescator > 0 && Histograma[MemoratorDeHistoCrescatoare[EsteCrescator]] >= Histograma[j])
                EsteCrescator--;  //Daca EsteCrescator e mai mare ca 0 el va scade daca histograma dinainte lui
            //adica Histograma[MemoratorDeHistoCrescatoare[EsteCrescator]] este mai mare. Scazand din EsteCrescator
            //histograma dinainte lui se va schimba cu una, doua sau mai multe poziti in spate in functie de EsteCrescator


            Dreapta[j] = MemoratorDeHistoCrescatoare[EsteCrescator] - 1; //Memoreaza indicele histogramei
            EsteCrescator++;                                             //Creste cu 1 in caz de e crescator altfel scade la while
            MemoratorDeHistoCrescatoare[EsteCrescator] = j;              //Memoreaza pozitia histogramei de la care incepe sa fie crescator

        }
        //Calculam Aria
        for (j = 1; j <= NrColoane; j++)
            MaxArie = max(MaxArie, Histograma[j] * (Dreapta[j] - Stanga[j] + 1));

    }

    cout << MaxArie;

    return 0;

}
/*
5 5
1 0 0 1 0
0 0 1 0 0
1 0 0 0 1
0 1 0 0 0
1 1 1 1 1
*/