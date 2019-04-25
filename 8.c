#include<stdio.h>
#include<stdlib.h>

int n,k,t, a[1000];

int main()
{
    scanf("%d%d%d",&n,&k,&t);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);

    for(int i=1; i<n; i++)
        for(int j=i+1; j<=n; j++)
            if(abs(a[i]-a[j]) <= t && abs(i-j) <= k)
            {
                printf("\nHogwarts wins!\n\n");
                return 0;
            }
    printf("\nVoldemort wins!\n\n");
    return 0;
}
