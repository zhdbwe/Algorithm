#include <cstdio>
#include <algorithm>

using namespace std;
#define INF 1000100

int s[100100],dp[100100];

int slove(int *s,int n)
{
    if(n == 0||n == 1)
    {
        return n;
    }
    for(int i = 0;i < n;++i)
    {
        dp[i] = INF;
    }
    for(int i = 0;i < n;++i)
    {
       *lower_bound(dp,dp + n,s[i]) = s[i];
    }
    return lower_bound(dp,dp + n,INF) - dp;
}


int main()
{
    int t,n;
    scanf("%d",&t);
    int ans[t];
    for(int i = 0;i < t;++i)
    {
        scanf("%d",&n);
        for(int j = 0;j < n;++j)
        {
            scanf("%d",&s[j]);
        }
        printf("%d\n",slove(s,n));
    }
}
