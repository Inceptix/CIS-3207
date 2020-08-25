#include <stdio.h>
#include <stdlib.h>




int main(int argc, char *argv[])
{
    FILE *fp;
    char* lineBuf = NULL;
    size_t lineBufSize = 0;
    ssize_t lineSize;

    //int i = 0;

    //terminate program if no arguments
    if (argc <= 1)
    {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    char* search = argv[1];


    for (int i=2; i < argc; i++)
    {
        fp = fopen(argv[i], "r");

        if (fp == NULL)
        {
            printf("cannot open file\n");
            exit(1);
        }

        lineSize = getline(&lineBuf, &lineBufSize, fp);

        while (lineSize >= 0)
        {
            size_t found = lineBuf.find(search);
            if (found != string::npos)
            {
                printf("%s", lineBuf);
            }

            lineSize = getline(&lineBuf, &lineBufSize, fp);
        }

        free(lineBuf);
        lineBuf = NULL;

        fclose(fp);

    }

    exit(0);
}
