//计算平面上两个点的最近距离时间复杂度为O(n(logn)^2)，在数据量小的情况下可能还会运行得较快。
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 100010

struct node {
    double x, y;
} p[N], tmp[N];

double min(double a, double b) { return a < b ? a : b; }

bool cmpx(const node &a, const node &b) { return a.x < b.x; }

bool cmpy(const node &a, const node &b) { return a.y < b.y; }

double dis(node a, node b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }

double close_pair(int l, int r) {
    if(r - l == 1) return dis(p[r], p[l]);
    if(r - l == 2) return min(dis(p[l], p[r]), min(dis(p[r], p[r-1]), dis(p[r-1], p[l])));
    int mid = (l + r) >> 1, cnt = 0;
    double ans = min(close_pair(l, mid), close_pair(mid + 1, r));
    for(int i = l; i <= r; i++)
        if(p[i].x - ans <= p[mid].x && p[i].x + ans >= p[mid].x)
            tmp[++cnt] = p[i];
    //对条带中的Y集合排序，在之后的查找就是线性操作。
    sort(tmp + 1, tmp + 1 + cnt, cmpy);
    for(int i = 1; i <= cnt; i++)
        for(int j = i + 1; j <= cnt; j++)
            if(tmp[j].y - tmp[i].y >= ans) break;//如果距离大于ans，直接跳出循环，在7次之后一定跳出循环
            else ans = min(ans, dis(tmp[i], tmp[j]));
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
    sort(p + 1, p + 1 + n, cmpx);
    printf("%.2f\n", close_pair(1, n));
    return 0;
}







