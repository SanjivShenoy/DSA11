#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n, freq[10000000];
char str[1000][1000];
int store[10000000], storeval[1000], ptr, z;

void sort()
{
    for(int i=1; i<ptr; i++)
        for(int j=1; j<=ptr-i; j++)
            if(storeval[j] < storeval[j+1])
            {
                int temp = storeval[j];
                storeval[j] = storeval[j+1];
                storeval[j+1] = temp;
                temp = store[j];
                store[j] = store[j+1];
                store[j+1] = temp;
            }
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("\n%[^\n]s",str[i]);
        int sum = 0;
        for(int j=0; str[i][j] != '\0'; j++)
        {
            int x = str[i][j];
            sum += (x*x);
        }
        freq[sum]++;
    }
    scanf("%d",&z);
    for(int i=0; i<10000000; i++)
    {
        if(freq[i] > 0)
        {
            store[++ptr] = i;
            storeval[ptr] = freq[i];
        }
    }
    sort();
    for(int i=1; i<=ptr && z; i++,z--)
    {
        for(int j=1; j<=n; j++)
        {
            int sum = 0;
            for(int k=0; str[j][k] != '\0'; k++)
            {
                int x = str[j][k];
                sum += (x*x);
            }
            if(sum == store[i])
            {
                printf("%s\n",str[j]);
                break;
            }
        }
    }
    return 0;
}
