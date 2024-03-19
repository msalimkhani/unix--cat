#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
    cat - unix cat
    re-written by Mahdi Salimkhani
    GNU-GPL License
    2024
*/
const int __M_VERSION = 1;
const int __m_VERSION = 0;
int get_majorver()
{
    return __M_VERSION;
}
int get_minorver()
{
    return __m_VERSION;
}
int print_version()
{
    printf("cat - show inside the file.\nVer. %d.%d\n",get_majorver(),get_minorver());
    return 0;
}
int print_help()
{
    printf("NAME\n\t\tcat - concatenate files and print on the standard output\nSYNOPSIS\n\t\tcat [OPTION]... [FILE]...\n\nDESCRIPTION\n\t\tConcatenate FILE(s) to standard output.\n\t\tWith no FILE, or when FILE is -, read standard input.\n");
    printf("\t\t-A, --show-all\t\t\t\tequivalent to -vET\n");
    return 0;
}
int readfile(const char *__buf,int isAll,int isNum)
{
    FILE *ptr;
    char ch;
    int i = 1;
    int counted = 1;
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
        if(ch == '\n' && isAll)
            printf("^M$\n");
        if(!isNum)
        {
            printf("%c",ch);
        } else{
            //printf("%d.%c",i,ch);
            if(counted == 1)
            {
                printf("%d   ",i);
                counted = 0;
            }
            printf("%c",ch);
            if(ch == '\n')
            {
                i++;
                counted = 1;
            }
        }
    } while (ch != EOF);
    fclose(ptr);
    printf("\n");
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
        if(!strcmp(argv[1],"--version") || !strcmp(argv[1],"-v"))
        {
            return print_version();
        }
        else if (!strcmp(argv[1],"--help") || !strcmp(argv[1],"-h"))
        {
            return print_help();
        }
        else
        {
            return readfile(argv[1],0,0);
        }
    }
    else if(argc==3)
    {
        if(!strcmp(argv[1],"-A") || !strcmp(argv[1],"--show-all") || !strcmp("-vET",argv[1]))
        {
            readfile(argv[2],1,0);
        }
        else if(!strcmp(argv[2],"-A") || !strcmp(argv[2],"--show-all") || !strcmp("-vET",argv[2]))
        {
            readfile(argv[1],1,0);
        }
        if(!strcmp(argv[1],"-n") || !strcmp(argv[1],"--number"))
        {
            readfile(argv[2],0,1);
        }
        else if(!strcmp(argv[2],"-n") || !strcmp(argv[2],"--number"))
        {
            readfile(argv[1],0,1);
        }
    }
    else if (argc==4)
    {
        if(!strcmp(argv[1],"-A") || !strcmp(argv[1],"--show-all") || !strcmp("-vET",argv[1]) && (!strcmp(argv[2],"-n") || !strcmp(argv[2],"--number")))
        {
            readfile(argv[2],1,1);
        }
        else if(!strcmp(argv[2],"-A") || !strcmp(argv[2],"--show-all") || !strcmp("-vET",argv[2]) && (!strcmp(argv[3],"-n") || !strcmp(argv[3],"--number")))
        {
            readfile(argv[1],1,1);
        }
        if(!strcmp(argv[1],"-A") || !strcmp(argv[1],"--show-all") || !strcmp("-vET",argv[1]) && (!strcmp(argv[3],"-n") || !strcmp(argv[3],"--number")))
        {
            readfile(argv[2],1,1);
        }
        else if(!strcmp(argv[3],"-A") || !strcmp(argv[3],"--show-all") || !strcmp("-vET",argv[3]) && (!strcmp(argv[1],"-n") || !strcmp(argv[1],"--number")))
        {
            readfile(argv[1],1,1);
        }
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
