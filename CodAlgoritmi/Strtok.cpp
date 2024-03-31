#include <bits/stdc++.h>

using namespace std;

char s[] = "Ana, are mere.ceva!", *p;

int main() {
    p = strtok(s, " .,!");
    while(p) {
        cout << p << "\n";
        p = strtok(NULL, " .,!");
    }
    
    return 0;
}
