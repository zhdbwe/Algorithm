#include <cstdio>

using namespace std;

int quickSelect(int* A,int left,int right,int k)
{
    if(left == right)
    {
        return A[left];
    }
    int pivot = A[right];
    int i = left;
    for(int j = left;j < right;++ j)
    {
        if(A[j] < pivot)
        {
            int tmp = A[j];
            A[j] = A[i];
            A[i] = tmp;
            i++;
        }
    }
    int tmp = A[i];
    A[i] = A[right];
    A[right] = tmp;
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


