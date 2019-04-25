#include<stdio.h>
#include<string.h>
#include<ctype.h>

int n, q;
char str[1000][1000],str2[1000][1000],str3[1000][1000], s[1000];

int isvowel(char ch)
{
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return 1;
    else
        return 0;
}

int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%s",str[i]);
        for(int j=0; str[i][j] != '\0'; j++)
            str2[i][j] = tolower(str[i][j]);
        for(int j=0; str[i][j] != '\0'; j++)
            str3[i][j] = (isvowel(str2[i][j])) ? '*' : str2[i][j];
    }

    scanf("%d",&q);

    while(q--)
    {
        int flag = 0;
        scanf("\n%s",s);
        for(int i=1; i<=n; i++)
        {
            if(strcmp(s, str[i]) == 0)
            {
                printf("%s\n",s);
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            continue;
        for(int i=0; s[i]!='\0'; i++)
            s[i] = tolower(s[i]);

        for(int i=1; i<=n; i++)
        {
            if(strcmp(s, str2[i]) == 0)
            {
                printf("%s\n",str[i]);
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            continue;

        for(int i=0; s[i]!='\0'; i++)
            s[i] = (isvowel(s[i]) ? '*' : s[i]);

        for(int i=1; i<=n; i++)
        {
            if(strcmp(s, str3[i]) == 0)
            {
                printf("%s\n",str[i]);
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            continue;

        printf("......\n");

    }

    return 0;
}
