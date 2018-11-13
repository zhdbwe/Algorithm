#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#define N 1000000

using namespace std;

int monkey[N+100],bana[N+100];

int main()
{
    int n = 0;
    char c = '0';
    while((c = getchar()) != '\n')
    {
        if(isdigit(c))
        {
            ungetc(c,stdin);
            scanf("%d",&monkey[n++]);
        }
    }
    for(int i = 0;i < n;++i)
    {
        scanf("%d",&bana[i]);
    }
    sort(monkey,monkey+n);
    sort(bana,bana+n);
    int max_time = 0;
    int tmp = 0;
    for(int i = 0;i < n;++i)
    {
        tmp = abs(bana[i]-monkey[i]);
        if(tmp > max_time)
            max_time = tmp;
    }



    printf("%d",max_time);
}
