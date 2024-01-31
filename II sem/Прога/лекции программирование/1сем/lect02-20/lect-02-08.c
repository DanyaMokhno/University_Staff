#include <stdio.h>
#include <stdlib.h>
#define OS_TYPE linux
#ifdef OS_TYPE
    #define CLS system("clear")
#else
    #define CLS system("cls")
#endif /* OS_TYPE */
int main()
{
    int value;

    do
    {

        puts("There are some options:");
        puts("1 - for HELP");
        puts("2 - for RUN program");
        puts("3 - for SAVE results");
        puts("0 - for EXIT program");
        printf("\nEnter option: ");
        scanf("%d", &value);
        switch(value)
        {
        case 1:
            {
                puts("Your selection is HELP");
                getchar();
            }
            break;
        case 2:
            {
                puts("Your selection is RUN");
                getchar();
            }
            break;
        case 3:
            {
                puts("Your selection is SAVE");
                getchar();
            }
            break;
        case 0:
            {
                puts("Your selection is EXIT");
                getchar();
            }
            break;
        default:
            {
                puts("Incorrect key!");
                getchar();
            }
        }
    puts("Press ENTER to continue");
    getchar();
    CLS;
    } while(value!=0);
    return 0;
}

