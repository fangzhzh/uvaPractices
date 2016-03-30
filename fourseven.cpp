#include <stdio.h>
#include <iostream>
#include <regex>
using namespace std;
int main(){
    return 0;
    int n;
    while(true){
        long long s, m;
        cin >> s;
        if(cin.eof()){
            return 0;
        }
        cin >> m;
        int count = 0;
        for(long i = s; i <= m; ++i){
            string str = to_string(i);
            sort(str.begin(), str.end());
            long found = str.find_first_not_of("47");
            if( found == string::npos) {
                count++;
            }             
        }
        ++n;
        cout << count << endl;
    }
}
