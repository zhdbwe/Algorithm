#include <cstdio>

using namespace std;
//快速选择算法，和快速选择算法的思想类似，时间复杂度为O(n)
int quickSelect(int* A,int left,int right,int k)
{
    if(left == right)
    {
        return A[left];
    }
    //直接选择最后一个元素作为分划元素
    int pivot = A[right];
    int i = left;
    for(int j = left;j < right;++ j)
    {
        if(A[j] < pivot)
        {
        //交换A[i]和A[j]
            int tmp = A[j];
            A[j] = A[i];
            A[i] = tmp;
            i++;
        }
    }
    //交换A[i]和A[right]；即最后一个元素就是第i大的元素
    int tmp = A[i];
    A[i] = A[right];
    A[right] = tmp;
    //如果i==k那么就找到了第k大的数，否则递归向下继续查询
    if(i == k)
    {
        return A[i];
    }
    if(i > k)
        return quickSelect(A, left, i-1 , k);
    else
        return quickSelect(A, i+1, right, k);

    return -1;
};
int main()
{
    int k=0,n=0;
    scanf("%d",&n);
    scanf("%d",&k);
    int *A = new int[n];
    for(int i = 0;i < n;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        A[i] = tmp;
    }
    int k_max = 0;
    k_max = quickSelect(A, 0, n - 1, n - k);
    printf("%d",k_max);
}
