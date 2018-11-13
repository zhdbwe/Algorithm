#include <cstdio>
#include <algorithm>
//#include <limits>
#include <iostream>

#define MAX_PRICE 801000

using namespace std;

struct Food
{
    int xi,yi,pi;
} food[1010];

int dp[1010][25][81];

int main()
{
    int x,y;
    int n;
    scanf("%d %d",&x,&y);
    scanf("%d",&n);
    for(int i = 1;i <= n;++i)
    {
        scanf("%d %d %d",&food[i].xi,&food[i].yi,&food[i].pi);
    }
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= x;++j)
        {
            for(int k = 1;k <= y;++k)
            {
                if(j <= food[i].xi && k <= food[i].yi)
                    dp[i][j][k] = food[i].pi;
                else
                    dp[i][j][k] = MAX_PRICE;
            }
        }
    }

    for(int i = 1;i < n;++i)
    {
        for(int j = 1;j <= x;++j)
        {
            for(int k = 1;k <=y;++k)
            {
                int idx = min(x, j + food[i+1].xi);
                int idy = min(y, k + food[i+1].yi);
                dp[i+1][j][k] = min(dp[i][j][k],dp[i+1][j][k]);
                dp[i+1][idx][idy] = min(dp[i][j][k]+food[i+1].pi,dp[i+1][idx][idy]);
            }
        }
    }
    printf("%d",dp[n][x][y]);

}
