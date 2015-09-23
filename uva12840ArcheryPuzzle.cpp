#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#define inff 0x3fffffff
using namespace std;
int dp[301][301];
int bag[301];
void processInput() {
    int count, score;
    int shoot;
    scanf("%d %d", &count, &score);
    int arrows[count];
    for(int i = 0; i < count; ++i) {
        scanf("%d", arrows+i);
    }
    for( int index = 0; index < count; index++) {
        for(int curScore = 1; curScore <= score; ++curScore) {
            dp[index][curScore] = inff;
            for(int lowIndex = index; lowIndex >=0; lowIndex--) {
                if(arrows[index] <= curScore && dp[lowIndex][curScore-arrows[index]]+1 < dp[index][curScore] ){
                    dp[index][curScore] = dp[lowIndex][curScore-arrows[index]]+1;
                }
            }
        }
    }

    
    int answerIndex = -1;
    int smallestShoot = inff;
    for(int curIndex = count-1 ; curIndex >= 0; curIndex--) {
        if(dp[curIndex][score] == inff) {
            continue;
        }
        if( dp[curIndex][score] < smallestShoot) {
            smallestShoot = dp[curIndex][score];
            answerIndex = curIndex;
        }
    }

    if(answerIndex < 0) {
        cout << "impossible" << endl;
        return;
    }
    
    cout << "[" << dp[answerIndex][score] << "] ";
    int curScore =  score;
    while(true) {
        cout << arrows[answerIndex] ;
        curScore -= arrows[answerIndex];
        if(curScore <= 0 ) {
            break;
        }
        for(int curIndex = count-1 ; curIndex >= 0; curIndex--) {
            if(dp[curIndex][curScore] == inff) {
                continue;
            }
            if( dp[curIndex][curScore] < smallestShoot) {
                smallestShoot = dp[curIndex][curScore];
                answerIndex = curIndex;
            }
        }
        cout << " ";
    }
    cout << endl;
        
}

int main() {
    memset(dp, 301,0);
    memset(bag, 301,0);
     int testCase = 1;
     int count;
     scanf("%d",&count);
     while (count--) {
         cout << "Case " << testCase << ": ";
         processInput();
         testCase++;
     }
}
