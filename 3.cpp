#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 100010
#define INF 0x3f3f3f3f
struct points
{
    double x,y;
    int idx;
}p[N],py[N],pytmp[N];

int pyidx[N];

double min(double a, double b) { return a > b ? b : a; }

bool cmpx(const points &a, const points &b) { return a.x != b.x ? a.x < b.x : a.y < b.y; }

bool cmpy(const points &a, const points &b) { return a.y != b.y ? a.y < b.y : a.x < b.x; }

inline double distance( const points & a, const points & b )
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void merge_y(points* dst,points* src,int l, int r)
{
    int m = (l + r + 1) >> 1;
    int p_l = l;
    int p_r = m;
    int p = l;
    while(p_l < m && p_r <r)
    {
        if(cmpy(src[p_l], src[p_r]))
           dst[p++] = src[p_l++];
        else
            dst[p++] = src[p_r++];
    }
    while(p_l < m) dst[p++] = src[p_l++];
    while(p_r < r) dst[p++] = src[p_r++];
}

double closepair(points* X,points* Y,points* TMP,int left, int right)
{
    if(right - left == 2) return distance(p[left], p[right]);
    if(right - left == 3) return min(distance(p[left],p[left + 1]), min(distance(p[left], p[right - 1]), distance(p[left + 1], p[right - 1])));
    ///有三个点的时候计算三个点的距离取最小值
    int pivot = (right + left + 1) >> 1; /// 取中点
    int p_l = left;
    int p_r = pivot;
    for(int i = left;i < right;++ i)
    {
        if(Y[i].idx < X[pivot].idx) TMP[p_l ++] = Y[i];
        else TMP[p_r ++] = Y[i];
    }
    double mindis = min(closepair(X,TMP,Y,left, pivot), closepair(X,TMP,Y,pivot, right));
    merge_y(Y,TMP,left,right);
    int cnt = 0;
    for(int i = left;i < right;++ i)
    {
        if(X[pivot].x - mindis <= Y[i].x && Y[i].x <= X[pivot].x + mindis)
        {
            pyidx[cnt ++] = i;
        }
    }
    for(int i = 0;i < cnt;++ i)
    {
        for(int j = i + 1;j < min(i+8,cnt);++ j)
        {
            mindis = min(mindis, distance(Y[pyidx[i]],Y[pyidx[j]]));
        }
    }
    return mindis;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;++ i)
    {
        scanf("%lf %lf",&p[i].x,&p[i].y);
    }
    sort(p,p + n,cmpx);
    for(int i = 0;i < n;++i) p[i].idx = i;
    memcpy(py, p, sizeof(py));
    sort(py,py + n,cmpy);
    printf("%.2f", closepair(p, py, pytmp, 0, n));

}


