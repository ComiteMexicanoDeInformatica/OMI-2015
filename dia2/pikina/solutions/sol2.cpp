#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
 
int n,k;
long long ma[1000002];
long long pre[1000002];
 
bool calculate(int mid,int p)
{
    long long sum = pre[p] - pre[mid];
    long long total = (p-mid)*ma[p] - sum;
    return (total <= k);
}
 
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&ma[i]);
    }
    sort(ma,ma+n);
     
    pre[0]=0;
    for(int i=0;i<n;i++)
    {
        pre[i+1] = pre[i]+ma[i];
    }
     
    int ra=1;
    int rb=ma[0];
    for(int i=1;i<n;i++)
    {
        int a = 0;
        int b = i;
        int mid;
        while(a+1<b)
        {
            mid = (a+b)/2;
            if(calculate(mid,i))
            {
                b = mid;
            }else
            {
                a = mid;
            }
        }
        if(calculate(b,i))
        {
            if(ra<i-b+1)
            {
                ra = i-b+1;
                rb = ma[i];
            }
        }
        if(calculate(a,i))
        {
            if(ra<i-a+1)
            {
                ra = i-a+1;
                rb = ma[i];
            }
        }
    }
     
    printf("%d %d\n",ra,rb);
}