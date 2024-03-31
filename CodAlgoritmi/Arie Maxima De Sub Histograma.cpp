#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 1000000;  //Numarul maxim de histograme
int NrHisto;    //Numar histograme
int Histograma[N_MAX + 2];     //Inaltimea histogramei
int MemoratorDeHistoCrescatoare[N_MAX + 2];     //Memoreaza pozitia histogramelor crescatoare dintr-un sir crescator.
int EsteCrescator;      //Pentru verficare daca sirul inca mai este crescator, macar daca ultima histograma din sir este mai mare ca prima
int Stanga[N_MAX + 2], Dreapta[N_MAX + 2];      //Memoreaza limitele dintr-un sir crescator
long long int MaxArie; //Aria maxima
int i;

int main () {

    //Citire
    cin >> NrHisto;

    for (int i = 1; i <= NrHisto; i++) {

        cin >> Histograma[i];

    }
    EsteCrescator = 0;
    MemoratorDeHistoCrescatoare[0] = 0;

    //Gasire limita de la stanga pentru i
    for (i = 1; i <= NrHisto; i++) {

        while (EsteCrescator > 0 && Histograma[MemoratorDeHistoCrescatoare[EsteCrescator]] >= Histograma[i])
            EsteCrescator--; //Daca EsteCrescator e mai mare ca 0 el va scade daca histograma dinainte lui
                             //adica Histograma[MemoratorDeHistoCrescatoare[EsteCrescator]] este mai mare. Scazand din EsteCrescator
                             //histograma dinainte lui se va schimba cu una, doua sau mai multe poziti in spate in functie de EsteCrescator

        cout << EsteCrescator << " ";
        cout << MemoratorDeHistoCrescatoare[EsteCrescator] << "  ";

        Stanga[i] = MemoratorDeHistoCrescatoare[EsteCrescator] + 1; //Memoreaza indicele histogramei
        EsteCrescator++;                                            //Creste cu 1 in caz de e crescator altfel scade la while
        MemoratorDeHistoCrescatoare[EsteCrescator] = i;             //Memoreaza pozitia histogramei de la care incepe sa fie crescator


    }
    cout << '\n';

    EsteCrescator = 0;
    MemoratorDeHistoCrescatoare[0] = NrHisto + 1;

    //Gasire limita de la dreapta pentru i
    for (i = NrHisto; i >= 1; i--) {

        while (EsteCrescator > 0 && Histograma[MemoratorDeHistoCrescatoare[EsteCrescator]] >= Histograma[i])
            EsteCrescator--;  //Daca EsteCrescator e mai mare ca 0 el va scade daca histograma dinainte lui
                              //adica Histograma[MemoratorDeHistoCrescatoare[EsteCrescator]] este mai mare. Scazand din EsteCrescator
                              //histograma dinainte lui se va schimba cu una, doua sau mai multe poziti in spate in functie de EsteCrescator


        Dreapta[i] = MemoratorDeHistoCrescatoare[EsteCrescator] - 1; //Memoreaza indicele histogramei
        EsteCrescator++;                                             //Creste cu 1 in caz de e crescator altfel scade la while
        MemoratorDeHistoCrescatoare[EsteCrescator] = i;              //Memoreaza pozitia histogramei de la care incepe sa fie crescator

    }

    // Histograma[i] este cea mai mica parte, iar Dreapta[i] Stanga[i] limitele
    for (i = 1; i <= NrHisto; i++)
        MaxArie = max(MaxArie, (long long) Histograma[i] * (Dreapta[i] - Stanga[i] + 1)); //Histograma[i] fiind cea mai mica
                                                                                          //se face aria ei folosind limitele


    cout << MaxArie << "\n";
    for(i = 1; i <= NrHisto; i++)
        cout << Stanga[i] << " " << Dreapta[i] << '\n';
    cout << MaxArie;

    return 0;

}

//9
//2 1 2 4 3 4 1 4 4