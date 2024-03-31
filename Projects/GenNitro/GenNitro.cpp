#include <iostream>
#include <cstring>
#include <fstream>
#include <random>

using namespace std;

ofstream fout("1000links.txt");
int i, j;
char charactere[62] ={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a',
                      'b', 'c','d', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                      'l', 'm','n', 'o', 'p', 'q', 'r', 's', 't', 'u',
                      'v', 'w','x', 'y', 'z', 'A', 'B', 'C', 'D', 'E',
                      'F', 'G','H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
                      'P', 'Q','R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
                      'Z'};
int character;

int main() {
    for(i = 1; i <= 1000; i++)
    {
        fout << "discord.gift/";
        for(j = 1; j <= 16; j++) {
            character = rand() % 62;
            fout << charactere[character];
        }

        fout << '\n';
    }
    return 0;
}
