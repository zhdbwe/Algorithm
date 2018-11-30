#include <cstdio>
#include <algorithm>
#include <iostream>
#define N 1000000

using namespace std;

long long a,b,k;

int main()
{
    long long tmp = 0;
    a=b=k=0;
    while(scanf("%d",&tmp) != EOF)
    {

        k = max(a,b + tmp);
        b=a,a=k;
        if(getchar() == '\n')
        break;
    }
    printf("%ld",k);
}
