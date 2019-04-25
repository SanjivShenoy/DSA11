#include<stdio.h>

int n;
int a[1000][1000];
char ch;
int queuex[1000];
int queuey[1000];
int mark[1000][1000];
int dist[1000][1000];

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            scanf("%c",&ch);
            while(ch == '\n' || ch == ' ')
                scanf("%c",&ch);
            if(ch == 'S')
                a[i][j] = 19;
            else if(ch == 'B')
                a[i][j] = 2;
            else if(ch == 'H')
                a[i][j] = 8;
            else if(ch == 'P')
                a[i][j] = 16;
        }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    int qs = 0, qd = 0;

    queuex[0] = 0;
    queuey[0] = 0;
    while(qd>=qs)
    {
        int x = queuex[qs];
        int y = queuey[qs++];

        if(a[x][y+1] == 16 || a[x][y-1] == 16 || a[x+1][y] == 16 || a[x-1][y] == 16)
        {
            queuex[++qd] = x+1;
            queuex[qd] = y+1;
        }
    }



    return 0;
}
