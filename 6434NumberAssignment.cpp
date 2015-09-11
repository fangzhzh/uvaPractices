#include<stdio.h>
#include<iostream>
#include<algorithm>
#define inff 0x3fffffff
using namespace std;
int n,m;
int table[110][110];
int numbers[110];
int main()
{
    int count,index,index_level2;
    int cas=1;
    scanf("%d",&count);
    while(count--)
    {
        scanf("%d%d",&n,&m);
        for(index=1;index<=n;index++)
        {
            scanf("%d",&numbers[index]);
        }
        sort(numbers+1,numbers+n+1);
        for(index=0;index<=n;index++)
        {
            for(index_level2=0;index_level2<=m;index_level2++)
                table[index][index_level2]=inff;
        }
        int index_level3;
        for(index=1;index<=n;index++)
        {
            table[index][1]=numbers[index]-numbers[1];
            for(index_level2=2;index_level2<=m;index_level2++)
            {
                for(index_level3=1;index_level3<index;index_level3++)
                {
                    table[index][index_level2]=min(table[index][index_level2],table[index_level3][index_level2-1]+numbers[index]-numbers[index_level3+1]);
                }
            }
        }
        printf("Case #%d: %d\n",cas++,table[n][m]);
    }
    return 0;
}
