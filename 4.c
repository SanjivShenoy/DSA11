#include<stdio.h>

int t, n, m, l, r, c, p, q, s, freq[1000][1000];

void calc()
{
    int z = l;
    l = (l*p + r)%n + 1;
    r = (r*q + z)%n + 1;
    if(l > r)
    {
        int temp = l;
        l = r;
        r = temp;
    }
    c = (c*s)%1000000 + 1;
    printf("\n\n%d %d %d\n\n",l,r,c);
}

int main()
{
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        scanf("%d%d",&n,&m);
        scanf("%d%d%d%d%d%d",&l,&r,&c,&p,&q,&s);
        for(int j=l; j<=r; j++)
            freq[i][j]+=c;

        for(int k=1; k<m; k++)
        {
            calc();
            for(int j=l; j<=r; j++)
                freq[i][j]+=c;
        }
        int max = -99, id = -99;
        for(int k=1; k<=n; k++)
        {
            if(freq[i][k] > max)
            {
                max = freq[i][k];
                id = k;
            }
        }
        printf("\n%d %d\n\n",id,max);
    }
    return 0;
}
