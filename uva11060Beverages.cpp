#include <string>
#include <stdio.h>
#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;
struct Drink{
    string name;
    int score;
    vector<Drink*> previous;
    vector<Drink*> nexts;
};
void removeLink(Drink*& drink1, Drink*& drink2) {
    drink1->nexts.erase(
        remove(drink1->nexts.begin(), drink1->nexts.end(), drink2),
        drink1->nexts.end());
        
    drink2->previous.erase(
        remove(drink2->previous.begin(), drink2->previous.end(), drink1),
        drink2->previous.end());
}

void removeDrinkPrevois(Drink* &drink1, Drink* &drink2) {
    // previous
    for (int i = 0; i < drink1->previous.size(); i++) {
        removeLink(drink1->previous[i], drink2);
    }
    
    // next
    for (int i = 0; i < drink1->nexts.size(); ++i) {
        removeLink(drink1->nexts[i], drink2);        
    }
}

void processLink(Drink* &drink1, Drink* &drink2) {
    if(drink1->nexts.empty()) {
        drink1->nexts.push_back(drink2);
        return;
    }
    vector<Drink*>::iterator  i = drink1->nexts.begin();
    for(;
        i != drink1->nexts.end();
        ++i) {
        if((*i)->score > drink2->score ){
            drink1->nexts.insert(i, drink2);
            break;
        }
    }
    if (i == drink1->nexts.end()) {
        drink1->nexts.insert(i, drink2);
    }
    removeDrinkPrevois(drink1, drink2);
}

void process1(vector<Drink*> drinks, string b1, string b2){
    int index1 = -1, index2=-1;
    bool found = false;
    for (int i = 0; i < drinks.size(); i++) {
        if(drinks[i]->name.compare(b1) == 0) {
            index1 = i;
            if (found) {
                break;
            } else {
                found = true;
            }
            continue;
        }
        if(drinks[i]->name.compare(b2) == 0) {
            index2 = i;
            if (found) {
                break;
            } else {
                found = true;
            }
            continue;
        }
    }
    Drink* drink1 = drinks[index1];
    Drink* drink2 = drinks[index2];
    processLink(drink1, drink2);
    drink2->previous.push_back(drink1);
}

Drink* &drinking(std::vector<Drink*>& drinks ){
    vector<Drink*>::iterator  i = drinks.begin();
    for(; i != drinks.end();
        ++i) {
        if((*i)->previous.empty()){
            break;
        }
    }
    Drinks* curDrink = drinks[i];
    drinks.erase(drinks.being() + i);
    return curDrink;
}
void topIterate(vector<Drink*>& drinks){
    std::vector<Drink*> orderedDrink;
    deque<Drink*> drinkDeque;
    drinkDeque.push_back(drinking(drinks));
    cout << (*i)->name;
    
    while(!drinkDeque.empty()){
        Drink* drink = drinkDeque.front();
        cout << drink->name << " ";
        drinkDeque.pop_front();
        for( int k = 0; k < drink->nexts.size(); ++k){
            removeLink(drink, drink->nexts[i]);
        }
        drinking(drinks);
    }
    cout << endl;
    
}

void process(vector<Drink*>& drinks, string b1, string b2){
    int index1 = -1, index2=-1;
    bool found = false;
    for (int i = 0; i < drinks.size(); i++) {
        if(drinks[i]->name.compare(b1) == 0) {
            index1 = i;
            if (found) {
                break;
            } else {
                found = true;
            }
            continue;
        }
        if(drinks[i]->name.compare(b2) == 0) {
            index2 = i;
            if (found) {
                break;
            } else {
                found = true;
            }
            continue;
        }
    }
    cout << drinks[index1]->name << " < " << drinks[index2]->name << endl;
    for (int i = index2; i < drinks.size(); i++) {
        if( drinks[index1]->score < drinks[index2]->score) {
            continue;
        }
        
        if ( i == index1) {
            continue;
        }
        int dis = max(drinks[index1]->score + 1, drinks[index2]->score+1);
        drinks[i]->score = drinks[i]->score + dis;
    }
}

int main(){
    
    while (true){
        int count, caseCnt;
        scanf("%d", &count);
        vector<Drink*> drinks;
        for (int i = 0; i < count; ++i) {
            Drink *tmp = new Drink();
            tmp->score = i;
            cin >> tmp->name;
            drinks.push_back(tmp);
        }
        scanf("%d", &caseCnt);
        while (caseCnt-- > 0) {
            string b1, b2;
            cin >> b1 >> b2;
            process1(drinks, b1, b2);
        }
        string str;
        getline(cin, str);
        if (cin.eof()) {
            break;
        }
        topIterate(drinks);
        for( int k = 0; k < drinks.size(); ++k){
            delete drinks[k];
        }
    }
    
}


