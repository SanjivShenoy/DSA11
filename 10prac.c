#include<stdio.h>

int n, stack[1000], tos = -1;
char str[1000][1000];
int a[1000];

void push(int val)
{
    stack[++tos] = val;
}

int pop()
{
    if(tos == -1)
        return -1;
    else
        return stack[tos--];
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("\n%s",str[i]);

    for(int i=1; i<=n; i++)
    {
        for(int m=1; m<=n; m++)
            if(m!=i)
                push(m);
        int flag = 1;
        for(int x=0; flag!=0; x++)
        {
            flag = 0;
            int z = tos;
            for(int i=0; i<=z; i++)
                a[i] = pop();

            for(int j=0; j<=z; j++)
            {
                if(str[a[j]][x] == str[i][x])
                {
                    push(a[j]);
                    flag = 1;
                }
            }
            if(flag == 0)
            {
                printf("\n");
                for(int k=0; k<=x; k++)
                {
                    printf("%c",str[i][k]);
                }
                printf("\n");
            }
        }
    }


    return 0;
}
