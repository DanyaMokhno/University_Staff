#include <stdio.h>
#include <stdlib.h>

typedef union IPv4
{
    u_int8_t address[4];
    struct
    {
        int : 6;
        int class: 2;
    };
} IPv4;

int get_ip(IPv4 *ip)
{
    int i;
    int address[4];
    int complete;
    printf("input ip address\n");
    scanf("%d.%d.%d.%d", &(address[0]), &(address[1]), &(address[2]), &(address[3]));
    complete = 1;
    for (i = 0; i < 4; i++)
        if (address[i] < 256)
            ip->address[i] = address[i];
        else complete = 0;
    return complete;
}

void show_bin(u_int8_t address)
{
    int i;
    for (i = 7; i >= 0; i--) printf("%d", (address >> i) & (0x1));
}

void change_class_of_ip(IPv4 *ip)
{
    ip->class = ip->class ^ 0b10;
    if (ip->class & 0b10) ip->class = ip->class & 0b10;
}

void show_ip(IPv4 *ip)
{
    int i;
    printf("%hhu.%hhu.%hhu.%hhu\n", ip->address[0], ip->address[1], ip->address[2], ip->address[3]);
    for (i = 0; i < 4; i++)
    {
        show_bin(ip->address[i]);
        putchar('.');
    }
    putchar(8);
    putchar('\n');
}

int main()
{
    IPv4 *ip;
    int complete;

    ip = malloc(sizeof(IPv4));
    complete = get_ip(ip);
    if (!complete) printf("ip address incorrect");
    else
    {
        puts("original ip:");
        show_ip(ip);
        change_class_of_ip(ip);
        puts("converted ip:");
        show_ip(ip);
    }
    free(ip);
    return 0;
}
/*
Class A:

10.0.0.1
10.20.30.40
10.100.100.100
123.45.67.89

Class B:

172.16.0.1
172.17.20.50
172.31.255.254
*/