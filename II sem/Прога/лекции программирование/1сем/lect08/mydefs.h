#define MAXLEN 80
#define OS_TYPE linux
#ifdef OS_TYPE
    #define CLS system("clear")
#else
    #define CLS system("cls")
#endif // OS_TYPE

int menu(); // Simple menu
