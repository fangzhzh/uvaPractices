#include <string>
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
struct Drink{
    string name;
    int score;
};


void process(vector<Drink> drinks, string); b1, string b2){

}

int main(){

    while (true){
        int count, caseCnt;
        scanf("%d", &count);
        vector<Drink> drinks;
        for (int i = 0; i < count; ++i) {
            Drink tmp;
            tmp.score = i;
            cin >> tmp.name;
            drinks.push_back(tmp);
        }
        while (count-- > 0) {
        }

        scanf("%d", &caseCnt);
        while (caseCnt-- > 0) {
            string b1, b2;
            cin >> b1 >> b2;
            process(drinks, b1, b2);
        }
        string str;
        getline(cin, str);
        if (cin.eof()) {
            break;
        }
        cout << "end" << endl;
    }
}

