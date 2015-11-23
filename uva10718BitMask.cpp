#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    while(true){
        unsigned int N,L,U;
        cin >> N;
        if(cin.eof()){
            return 0;
        }
        cin >> L >> U;
        if(L == U){
            cout << L << endl;
            continue;
        }
		unsigned int M=~N;
		for (int i=31;i>=0;--i) {
			unsigned int MM = M>>i;
			unsigned int LL = L>>i;
			unsigned int UU = U>>i;
			unsigned int mask = 1<<i;
			if (MM<LL) {
				M |= mask;
			} else if (MM>UU) {
				M &= ~mask;
			}
		}
		cout << M << endl;
    }
}
