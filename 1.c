#include<stdio.h>

int n, m, a[1000];

int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);

    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(a[i] + a[j] == m)
            {
                if(a[i] < a[j])
                    printf("\n%d %d\n\n",a[i],a[j]);
                else
                    printf("\n%d %d\n\n",a[j],a[i]);

                return 0;
            }
        }
    }
    return 0;
}
