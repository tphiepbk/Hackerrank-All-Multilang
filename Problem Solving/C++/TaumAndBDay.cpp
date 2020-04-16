#include <iostream>
#include <map>
#include <vector>

using namespace std;

long long int taumBday(int b, int w, int bc, int wc, int z) {
    int bcInit = bc;
    int wcInit = wc;
    if (bc < wc) {
        wc = bc + z;
        if (wc > wcInit) {
            wc = wcInit;
        }
    }
    else if (wc < bc) {
        bc = wc + z;
        if (bc > bcInit) {
            bc = bcInit;
        }
    }
    long long int res = (long long int)b * (long long int)bc + (long long int)w * (long long int)wc;
    return res;
}

int main() {
    int t;
    cin >> t;
    int b,w,wc,bc,z;
    while (t--) {
        cin >> b >> w;
        cin >> bc >> wc >> z;
        long long int temp = taumBday(b,w,bc,wc,z);
        cout << temp << "\n";
    }
}