#include <iostream>
#include <string>

using namespace std;

string myString = "Hello World";

int main() {

    cout << myString << '\n' << '\n';

//  length() - determină lungimea unui șir de caractere:
    int len = myString.length(); // len va fi 11
    cout << "Lungime: " << len << '\n';

//  empty() - verifică dacă un șir de caractere este gol:
    bool isEmpty = myString.empty(); // isEmpty va fi false
    cout << "Are elemente? (0 = Da, -1 = Nu): " << isEmpty << '\n';

//  substr(start, length) - obține un subșir de caractere:
    string subString = myString.substr(6, 5); // subString va fi "World"
    cout << "Dupa caracterul 6, cele 5 caractere: " << subString << '\n';


//  find(substring) - caută un subșir într-un șir și returnează poziția primei apariții:
    int position = myString.find("World"); // positia va fi 6
    cout << "Pozitia elementului 'World': " << position << '\n';

//  replace(old, new) - înlocuiește aparițiile unui subșir cu alt subșir:
    myString.replace(6, 5, "Ali Si Dani"); // myString va fi "Hello Ali Si Dani"
    cout << "Se inlocuieste, dupa caracterul 6, cele 5 caractere, 'World', cu 'Ali Si Dani': " << myString << '\n';


//  append(str) - adaugă un alt șir de caractere la sfârșitul șirului curent:
    myString.append(" :)"); // myString va fi "Hello World :)"
    cout << "La final, se adauga ' :)' : " << myString << '\n';

//  compare(str) - compară două șiruri de caractere:
    string str1 = "Hello";
    string str2 = "World";
    int result = str1.compare(str2); // result va fi un număr negativ, deoarece "Hello" este înainte de "World" în ordine lexicografică (alfabetica)
    cout << "Se compara 'Hello' si 'World' alfabetic astfel incat:\nSa se afiseze un nr negativ daca 'Hello' este inainte de 'World' sau un numar pozitiv daca este dupa (daca elementele reprezinta aceleasi caractere se va afisa 0) : " << result << '\n';

    cout << "\nIn final string-ul va arata astfel: " << myString << '\n';
}
