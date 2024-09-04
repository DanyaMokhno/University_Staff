#include <stdio.h>

int main()
{
    enum colors {
                    Red     = 0xff0000,
                    Green   = 0x00ff00,
                    Blue    = 0x0000ff,
                    Yellow  = 0xffff00,
                    Cyan    = 0x00ffff,
                    Magenta = 0xff00ff,
                    Black   = 0x0,
                    White   = 0xffffff
                };
    enum colors oneColor;

    oneColor=Cyan;
    printf("%d\n", oneColor);
    printf("%ld\n", sizeof(enum colors));
    return 0;
}

