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




void process(vector<Drink>& drinks, string b1, string b2){
    int index1 = -1, index2=-1;
    bool found = false;
    for (int i = 0; i < drinks.size(); i++) {
        if(drinks[i].name.compare(b1) == 0) {
            index1 = i;
            if (found) {
                break;
            } else {
                found = true;
            }
            continue;
        }
        if(drinks[i].name.compare(b2) == 0) {
            index2 = i;
            if (found) {
                break;
            } else {
                found = true;
            }
            continue;
        }
    }
    cout << drinks[index1].name << " < " << drinks[index2].name << endl;
    for (int i = index2; i < drinks.size(); i++) {
        if( drinks[index1].score < drinks[index2].score) {
            continue;
        }
        
        if ( i == index1) {
            continue;
        }
        int dis = max(drinks[index1].score + 1, drinks[index2].score+1);
        drinks[i].score = drinks[i].score + dis;
    }
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
        
        for (int i = 0; i < drinks.size(); i++) {
            cout << drinks[i].name << ":" << drinks[i].score;
        }         
        cout << "end" << endl;
    }
}

