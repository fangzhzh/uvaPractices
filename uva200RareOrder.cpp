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
void processLink(Drink* &drink1, Drink* &drink2) {
    if(drink1->nexts.empty()) {
        drink1->nexts.push_back(drink2);
    } else{
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
    }
}

void process1(vector<Drink*>& drinks, string b1, string b2){
    string char1="";
    string char2="";
    int index1 = -1, index2=-1;
    for (int i = 0; i < b1.size(); ++i) {
        if (b1[i] != b2[i]) {
            char1 = b1[i];
            char2 = b2[i];
            break;
        }
    }
    if (char1.compare("") == 0 || char2.compare("") == 0) {
        return;
    }
    
    bool found = false;
    for (int i = 0; i < drinks.size(); i++) {
        if(drinks[i]->name.compare(char1) == 0) {
            index1 = i;
            if (found) {
                break;
            } else {
                found = true;
            }
            continue;
        }
        if(drinks[i]->name.compare(char2) == 0) {
            index2 = i;
            if (found) {
                break;
            } else {
                found = true;
            }
            continue;
        }
    }
    
    Drink* drink1 = NULL;
    Drink* drink2 = NULL;
    if(index1 == -1){
        drink1 = new Drink();
        drink1->name = char1;
        drinks.push_back(drink1);
    } else {
        drink1 = drinks[index1];
    }
    
    if (index2 == -1) {
        drink2 = new Drink();
        drink2->name = char2;
        drinks.push_back(drink2);
    } else {
        drink2= drinks[index2];
        
    }
    processLink(drink1, drink2);
    drink2->previous.push_back(drink1);
}

Drink* drinking(std::vector<Drink*>& drinks ){
    vector<Drink*>::iterator  i = drinks.begin();
    for(; i != drinks.end();
        ++i) {
        if((*i)->previous.empty()){
            break;
        }
    }
    if (i != drinks.end()) {
        Drink *curDink = *i;
        drinks.erase(i);
        return curDink;
    }
    return NULL;
    
}
void topIterate(vector<Drink*>& drinks){
    std::vector<Drink*> orderedDrink;
    deque<Drink*> drinkDeque;
    drinkDeque.push_back(drinking(drinks));
    
    while(!drinkDeque.empty()){
        Drink* drink = drinkDeque.front();
        cout << drink->name;
        drinkDeque.pop_front();
        vector<Drink*> nexts = drink->nexts;
        for( int k = 0; k < nexts.size(); ++k){
            removeLink(drink, nexts[k]);
        }
        Drink* curDink = drinking(drinks);
        if (curDink == NULL) {
            break;
        }
        drinkDeque.push_back(curDink);
    }
}

void process(vector<string>& keywords) {
    vector<Drink*> drinks;
    for (int j = 0; j < keywords.size() - 1; ++j) {
        process1(drinks, keywords[j], keywords[j+1]);
    }
    topIterate(drinks);
    cout << endl;

}

int main(){
    vector<string> keywords;
    while (true){
        string name;
        cin >> name;
        if (name.compare("#") == 0) {
            break;
        }
        keywords.push_back(name);
    }
    
    process(keywords);

//    while (true) {
//        vector<string> keywords;
//        while (true){
//            string name;
//            cin >> name;
//            if (name.compare("#") == 0) {
//                break;
//            }
//            keywords.push_back(name);
//        }
//        
//        process(keywords);
//        if (cin.eof()) {
//            return 0;
//        }
//        
//    }

}


