#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)
{
    switch(argc)
    {
        case 0:
        case 1:
        case 2:
            fputs("Expected argument(s): name1 name2 ...\r\n", stderr);
            return EXIT_FAILURE;
        default:
            srand(time(NULL));
            fputs("Enter \"spin\" to spin the bottle or \"end\" to end the game!\r\n\r\n", stdout);
            for(const register int argn = argc - 1;;)
            {
                char buff [6] = "\0\0\0\0\0";
                while(fgets(buff, 5, stdin) == NULL);
                if(!strncmp(buff, "spin", 4) || !strncmp(buff, "SPIN", 4) || !strncmp(buff, "Spin", 4))
                {
                    const register char * const restrict name1 = argv [1 + (rand() % argn)];
                    const register char * restrict name2;
                    while((name2 = argv [1 + (rand() % argn)]) == name1);
                    printf("\t%s and %s\r\n\r\n", name1, name2);
                }
                else if(!strncmp(buff, "end", 3) || !strncmp(buff, "END", 3) || !strncmp(buff, "End", 3))
                {
                    break;
                }
            }
            return EXIT_SUCCESS;
    }
}