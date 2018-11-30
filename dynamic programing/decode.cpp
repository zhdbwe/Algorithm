#include <cstdio>

#define N 1000100
using namespace std;

//char d[N];
int dp[3];

int main()
{
    char t1 = '0';
    char t2 = '0';
    //int n =0;
    //int single_decode = 0;
    //int double_decode = 0;
    dp[1] = 1;dp[2] = 0;
    t1 = getchar();
    if(t1 == '0') dp[1] = 0;
    while((t2 = getchar()) != '\n')
    {
//        if(t2 == '0') single_decode = 0;
//        else single_decode = dp[1] + dp[2];
//        if(t1 == '1' || (t1 == '2' && t2 < '7')) double_decode = dp[1];
//        else double_decode = 0;
//        dp[2] = double_decode;
//        dp[1] = single_decode;
        dp[0] = dp[1];
        if(t2 == '0') dp[1] = 0;
        else dp[1] = dp[1] + dp[2];
        if(t1 == '1' || (t1 == '2' && t2 < '7')) dp[2] = dp[0];
        else dp[2] = 0;
        t1 = t2;
    }
    printf("%d",dp[1] + dp[2]);
    return 0;
}




