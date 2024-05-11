
#include<stdio.h>

int main()
{
    char a[25][25];
    int b, c, i, j, d;

    scanf("%d %d", &b, &c);

    for (i = 0; i < c; i++) {
        scanf("%s", a[i]);
    }

    for (i = 0 ; i < c; i++)
    {
        for (j = 0; j < b; j++)
        {
            if (a[i][j] == '.')
            {
                if (a[i + 1][j] != '*' && a[i - 1][j] != '*' && a[i][j + 1] != '*' && a[i][j - 1] != '*')
                {
                    d++;
                }
            }
        }
    }

    printf("%d\n", d);

    return 0;
}
