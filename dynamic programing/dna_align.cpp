#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char str_a[1010];
char str_b[1010];

int score[1010];
int new_score[1010];

int val(char a,char b)
{
    if(a == b) return 0;
    else if((a == 'C'&& b == 'G')||(a == 'G' && b =='C')) return 4;
    else return 5;
}

int main()
{
    scanf("%s",str_a);
    scanf("%s",str_b);

    int m = strlen(str_a);
    int n = strlen(str_b);
    for(int i = 0;i <= n;++i)
    {
        score[i] = 3 * i;
    }
    for(int i = 1;i <= m;++i)
    {
        new_score[0] = 3 * i;
        for(int j = 1;j <= n;++j)
        {
            new_score[j] = min(score[j-1] + val(str_a[i-1],str_b[j-1]),min(score[j] + 3,new_score[j-1] + 3));
        }
        for(int j = 0;j <= n;++j)
        {
            score[j] = new_score[j];
        }
    }
    printf("%d",score[n]);

    return 0;

}
