#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void search_stdin(const string& search_term);


int main(int argc, char *argv[])
{
    FILE *fp;
    char* lineBuf = NULL;
    size_t lineBufSize = 0;
    ssize_t lineSize;

    //int i = 0;

    //terminate program if no arguments
    if (argc == 1)
    {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    char* search = argv[1];

    if (argc == 2)
    {
        search_stdin(argv[1]);
    }

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

            if (strstr(lineBuf, search))
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

void search_stdin(const string& search_term)
{

    vector<string> input;
    string line;

    while (getline(cin, line))
        input.push_back(line);

    for (auto & t : input)
        if (t.find(search_term) != string::npos)
            cout << t << std::endl;
}
