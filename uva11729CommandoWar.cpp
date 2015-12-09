#include<stdio.h>
#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;
struct Task{
    Task(int brief, int duration){
        this->brief = brief;
        this->duration = duration;
    }
    bool operator<(const Task& r) const{
        return duration > r.duration;
    }

    int brief;
    int duration;
};

int main(){
    int count;
    int caseN = 1;
    while(true){
        scanf("%d", &count);
        if(count == 0){
            return 0;
        }
        vector<Task> tasks;
        while(count--){
            int x, y;
            scanf("%d %d", &x, &y);
            Task task(x,y);
            tasks.push_back(task);
        }

        sort(tasks.begin(), tasks.end());
        int sumBrief = 0, sum = 0;
        for(int i = 0; i < tasks.size(); i++)  
        {  
            sumBrief += tasks[i].brief;  
            sum = max(sumBrief+tasks[i].duration, sum);  
        }  

        cout << "Case " << caseN << ": " << sum << endl;
        caseN++;
    }

}
