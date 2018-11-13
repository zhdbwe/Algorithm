#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

int a[30010];

int main()
{
    memset(a,0,sizeof(a));
    int n,l;
    scanf("%d %d",&n,&l);
    int num = 0;
    int tmp = 0;
    for(int i = 0;i < n;++i)
    {
        scanf("%d",&tmp);
        a[tmp]++;
    }
    num += a[l];
    for(int i = 1;i < l/2;++i)
    {
        num += a[l-i];
        if(a[i] > a[l-i])
        {
            a[i+1] += (a[i] - a[l-i]);
        }
        a[i] = 0;
        a[l-i] = 0;
    }
    if(l%2 == 0)
        num += floor((float)a[l/2]/2);
    else
        num += (a[l/2+1]>a[l/2] ? a[l/2+1]:a[l/2+1] + floor((float)(a[l/2]-a[l/2+1])/2));
    printf("%d",num);
}
