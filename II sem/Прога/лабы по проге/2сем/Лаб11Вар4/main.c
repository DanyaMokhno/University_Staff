#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define ORG_LEN 50
#define MIN(a, b) (a < b) ? a : b

typedef union MAC
{
    /* собственно mac адрес */
    uint8_t address[6];

    /* октеты для упарвления отвечающие за идентификатор производителя */
    struct
    {
        int oct1: 8;
        int oct2: 8;
        int oct3: 8;
    };
} MAC;

int get_ip(MAC *mac)
{
    int i;
    int address[6];
    int complete;
    printf("input ip address\n");
    scanf("%x:%x:%x:%x:%x:%x", &(address[0]), &(address[1]), &(address[2]), &(address[3]), &(address[4]),
          &(address[5]));
    complete = 1;
    for (i = 0; i < 6; i++)
        if (address[i] < 256)
            mac->address[i] = (uint8_t) address[i];
        else complete = 0;
    return complete;
}

void print_address(MAC *mac)
{
    int i;
    for (i = 0; i < 6; i++)
    {
        printf("%02x", mac->address[i]);//02
        putchar(':');
    }
    putchar(8);
    putchar('\n');
}

void print_list_of_codes(FILE *f)
{
    char str[ORG_LEN];
    printf("select one of the list:\n");
    for (; fgets(str, ORG_LEN, f) != NULL;) printf("%s", str);
    rewind(f);
}

int change_code(MAC *mac)
{
    FILE *file = NULL;
    char organization[ORG_LEN];        // строка с консоли
    char str[ORG_LEN];                 // строка из файла
    size_t org_len, org_from_file_len;    // длины

    int code[3];
    char org_from_file[ORG_LEN];

    int flag;

    file = fopen("CID.csv", "r");
    print_list_of_codes(file);

    fgets(organization, ORG_LEN, stdin);
    org_len = strlen(organization);
    organization[org_len - 1] = '\0';


    for (flag = 0; fgets(str, ORG_LEN, file) != NULL;)
    {
        sscanf(str, "%x.%x.%x, %[^,]", &(code[0]), &(code[1]), &(code[2]), org_from_file);
        org_from_file_len = strlen(org_from_file);
        org_from_file[org_from_file_len - 1] = '\0';
        if (!strncmp(organization, org_from_file, (MIN(org_len, org_from_file_len)) - 1))
        {
            flag = 1;
            mac->oct1 = code[0];
            mac->oct2 = code[1];
            mac->oct3 = code[2];
        }
    }
    return flag;
}

int main(void)
{
    MAC address;
    MAC *ptr_addr;
    int received;
    int flag;

    ptr_addr = &address;
    received = get_ip(ptr_addr);
    if (received)
    {
        print_address(ptr_addr);
        fflush(stdin);
        flag = change_code(ptr_addr);
        if (!flag) printf("NOT FOUND!!!");
        else print_address(ptr_addr);
    } else
        printf("ip address incorrect");
    return 0;
}
// fa:36:2a:c6:f8:4f
// ZigBee
// ZigBee Alliance