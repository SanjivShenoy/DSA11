#include<stdio.h>
#define INF 100000000

int n,m;
char str[1000][1000], str2[1000][1000];
int freq[INF];

int main()
{
    scanf("%d%d",&n,&m);

    for(int i=0; i<n; i++)
    {
        scanf("\n%s",str[i]);
        int sum = 0;
        for(int j=0; str[i][j]!='\0'; j++)
            sum += str[i][j];
        freq[sum]++;
    }

    for(int i=0; i<m; i++)
    {
        scanf("\n%s",str2[i]);
        int sum = 0;
        for(int j=0; str2[i][j]!='\0'; j++)
            sum += str2[i][j];
        freq[sum]--;
        if(freq[sum] < 0)
        {
            printf("\nNo\n\n");
            return 0;
        }
    }
    printf("\nYes\n\n");

    return 0;
}
