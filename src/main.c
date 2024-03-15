#include <stdio.h>

int readfile(const char *__buf)
{
    FILE *ptr;
    char ch;
    ptr = fopen(__buf,"r");
    if(NULL == ptr)
    {
        printf("cat: Error reading file: \"%s\", No Such file or directory\n",__buf);
        return 127;
    }
    do
    {
        ch = fgetc(ptr);
        if(ch==EOF)
            break;
        printf("%c",ch);
    } while (ch != EOF);
    fclose(ptr);
    return 0;
}
int read_std()
{
    char ch;
    do
    {
        ch = getchar();
        printf("%c", ch);
    } while (ch != EOF);
    
}
int main(int argc, char *argv[])
{
    if(argc==2)
    {
        return readfile(argv[1]);
    }
    else if (argc==1)
    {
        return read_std();
    }
    else
    {
        printf("unknown argument ");
        for (size_t i = 1; i < sizeof(&argv); i++)
        {
            printf("\"%s\" ",argv[i]);
        }
        printf("\n");
        return 1;
    }
}
