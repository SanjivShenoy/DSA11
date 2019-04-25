#include<stdio.h>

int n;
char str[1000][1000];

int stack[1000], tos = -1, arr[1000];

void push(int val)
{
    stack[++tos] = val;
}

int pop()
{
    if(tos == -1)
        return 0;
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
            int flag2 = 0;
            char ch = str[i][x];
            int num = tos;
            for(int z=0; z <= num; z++)
            {
                arr[z] = pop();
            }
            for(int z=0; z<=num; z++)
            {
                int j = arr[z];
                if(j != i)
                {
                    if(str[j][x] == ch)
                    {
                        push(j);
                        flag2 = 1;
                    }
                }
            }
            if(flag2 == 0)
            {
                flag = 0;
                for(int k=0; k<=x; k++)
                    printf("%c",str[i][k]);
                printf("\n");
            }
        }
    }
    return 0;
}
