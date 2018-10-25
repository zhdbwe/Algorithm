#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int m,n,k;
    scanf("%d %d",&m,&n);
    scanf("%d",&k);
    int g[m][n];
    for(int i = 0;i < m;++i)
    {
        for(int j = 0;j < n;++j)
        {
            scanf("%d",&g[i][j]);
        }
    }
    int dp[m][n][k];
    dp[m-1][n-1][0] = g[m-1][n-1];
    for(int j = n-2;j>=0;--j)
    {
            dp[m-1][j][0] = dp[m-1][j+1][0] + g[m-1][j];
    }
    for(int j = m-2;j>=0;--j)
        {
            dp[j][n-1][0] = dp[j+1][n-1][0] + g[j][n-1];
        }
    for(int i = 1;i < k;++i)
    {
        dp[m-1][n-1][i] = 0;
        for(int j = n-2;j>=0;--j)
        {
            dp[m-1][j][i] = 0;
        }
        for(int j = m-2;j>=0;--j)
        {
            dp[j][n-1][i] = 0;
        }
    }
    for(int i = m-2;i>=0;--i)
    {
        for(int j = n-2;j>=0;--j)
        {
            int right = 0;
            int down = 0;
            for(int p = 0;p < k && right < k && down < k;++p)
            {
                if(dp[i+1][j][down] > dp[i][j+1][right])
                {
                    dp[i][j][p] = dp[i+1][j][down] + g[i][j];
                    down ++;
                }
                else
                {
                    dp[i][j][p] = dp[i][j+1][right] + g[i][j];
                    right ++;
                }
            }
        }
    }
    for(int i = 0;i<k - 1;++i)
        printf("%d ",dp[0][0][i]);
    printf("%d",dp[0][0][k-1]);
    return 0;
}
