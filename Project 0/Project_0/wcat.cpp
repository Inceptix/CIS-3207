#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char myString [100];
    //int i = 0;

    for (int i=1; i <argc; i++)
    {
        fp = fopen(argv[i], "r");

        if (fp == NULL)
        {
            printf("cannot open file\n");
            exit(1);
        }

        while (1)
        {
            if (fgets(myString,100, fp) == NULL) break;
            //i++;
            //printf("%3d: %s", i, myString);
            printf("%s", myString);
        }

        fclose(fp);
    }

    exit(0);
}
