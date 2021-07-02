#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
char **argv_unico(char **argv_copy, int len)
{
    char **argv2;
    int i;
    int j;
    int k;
    int m;
    char tmp;

    argv2 = malloc(sizeof(char*) * (len + 1));
    *argv2 = malloc(sizeof(char) * (len + 1));
    bzero(argv2, len);
    i = 0;
    j = 0;
    k = 0;
    m = 0;
    while (argv_copy[i++])
    {
        j = 0;
        while (argv_copy[j])
        {
            if (argv_copy[i][j] != ' ')
            {    
                tmp = argv_copy[i][j];
                argv2[k][m] = tmp;
            }
            else
            {
                k++;
                m = -1;
            }
            j++;
            m++;
        }
    }
    return (argv2);
}

int main(int argc, char **argv)
{
    int i = 0;
    argv = argv_unico(&argv[i], 4);
    while (i < 4)
        printf("%s", argv[i++]);
    return (0);
}

/*


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char **arg;
    
    arg = calloc(sizeof(char*),4+1);
    *arg = calloc(sizeof(char),4+1);
    int a = 0;
    int b = 0;
    arg[a][b] = '1';
    printf("%c",arg[a][b]);
    return 0;
}



*/