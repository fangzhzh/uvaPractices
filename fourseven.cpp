#include <stdio.h>
#include <iostream>
#include <regex>
using namespace std;
int main(){
    regex reg1("[47]+");
    while(true){
        int s, m;
        cin >> s;
        if(cin.eof()){
            return 0;
        }
        cin >> m;
        int count = 0;
        for(int i = s; i < m; ++i){
            string str = to_string(i);
            if( regex_match(str, reg1)){
                ++count;
            }
            cout << count << endl;
        }

    }
}
