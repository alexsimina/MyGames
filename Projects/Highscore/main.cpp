#include <iostream>
#include <fstream>

using namespace std;

fstream myFile;

int highscore;

int main()
{
    myFile.open("highscore.nobitches", ios::in);
    myFile >> highscore;
    cout << highscore << endl;
    myFile.close();

    myFile.open("highscore.nobitches", ios::out);
    cin >> highscore;
    myFile << highscore;
    myFile.close();


    return 0;
}
