#include <cstdio>
#include <iostream>

using namespace std;

#define N 100100
int A[N],B[N];


int merge_count(int *A,int s,int m,int e)
///[s,m-1],[m,e-1],����B����
{
    ///cout<<s<<m<<e<<endl;
    int i = 0;
    int j = m;
    int num = 0;
    for(i = s;i < m;++i)
    {
        while(j < e && A[i] > A[j] * 3LL)
        {
            j++;
        }
        num += (j-m);
    }
    i = s;
    j = m;
    int k = 0;
    while(i < m && j < e)
    {
        if(A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
//            if(A[i] > 3 * A[j])
//                num += (m - i + 1);
            //j++;
        }
    }
    if(i < m)///��߼��ϻ�ʣԪ��
    {
        while(i < m)
        {
            B[k++] = A[i++];
//            if(A[i] > 3*A[j - 1])///�ұ����һ��Ԫ�رȽ����˻�����һ��1�������ȥ��
//                num += (m - i + 1);
        }
    }
    else
    {
        while(j < e)///�ұߵļ��ϻ�ʣԪ��
            B[k++] = A[j++];
    }


    for(int i = 0;i < (e - s);++i)
    {
        A[s+i] = B[i];
    }
    ///display(A,s,e);
    ///cout<<"num:"<<num<<endl;
    return num;
}


int inverse_count(int *A,int s,int e)
{
    if(e-s < 2)
        return 0;
    if(e-s == 2)
    {
        if(A[s] > A[s+1] && A[s] > A[s+1] * 3LL)
        {
            swap(A[s],A[s+1]);
            return 1;
        }
        if(A[s] > A[s+1] && A[s] < A[s+1] * 3LL)
        {
            swap(A[s],A[s+1]);
        }
        return 0;
    }
    int mid = (s + e)>>1;
    ///cout<<"mid :" <<mid<<endl;
    int l = inverse_count(A,s,mid);
    int r = inverse_count(A,mid,e);
    int c = merge_count(A,s,mid,e);
    return l + r + c;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;++ i)
    {
        scanf("%d",&A[i]);
    }
    printf("%d\n",inverse_count(A,0,n));
    ///display(A,0,n);
}
