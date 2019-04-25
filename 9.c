#include<stdio.h>

int n, arr[1000], a[1000], ptr;

void inorder(int x)
{
    int left = x*2;
    int right = x*2+1;

    if(a[left] == -1 && a[right] == -1)
    {
        a[x] = arr[++ptr];
        return;
    }
    if(a[left] != -1)
        inorder(left);
    a[x] = arr[++ptr];
    if(a[right] != -1)
        inorder(right);
}

void postorder(int x)
{
    int left = 2*x;
    int right = 2*x + 1;
    if(a[left] == -1 && a[right] == -1)
    {
        printf("%d ",a[x]);
        return;
    }
    if(a[left] != -1)
        postorder(left);

    if(a[right] != -1)
        postorder(right);

    printf("%d ",a[x]);

}

int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
        scanf("%d",&arr[i]);

    for(int i=n+1; i<1000; i++)
        a[i] = -1;

    inorder(1);

    printf("\n");
    postorder(1);
    printf("\n\n");

    return 0;
}
