#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// File operations with class
class File {
private:
    FILE *fd; // descriptor (pointer to file)
public:
    File() { fd=NULL; } // EOF, no file opened
    bool OpenRO(char *name)
    {
        fd=fopen(name,"r");
        return (fd!=NULL);
    }
    void print_str()
    {
        char c;
        if(fd)
        {
            rewind(fd);
            while(((c=fgetc(fd))!='\n')||((c=fgetc(fd))!=EOF)) putchar(c);
        }
    }
    ~File() { if(fd!=NULL) fclose(fd); }; // destructor closes opened file
};

int main()
{
    enum {maxlen=32};
    char *fname;
    int slen;

    fname=(char*)malloc(maxlen*sizeof(char));
    if(fname!=NULL)
    {
        printf("Enter full filename: ");
        fgets(fname,maxlen,stdin);
        slen=strlen(fname);
        fname[slen-1]='\0';
        File Infile;
        Infile.OpenRO(fname);
        Infile.print_str();
    }
    else puts("No memory! Do nothing!!");

    return 0;
}




