#include <stdio.h>
#include <math.h>

class Int_Array
{
private:
    int *p;
    int n;
public:
    Int_Array(int num)
    {
        n=num;
        p = new int[n];
        // there must be initialization!
    }
    Int_Array(const Int_Array& ir2)
    {
        p = new int[n];
        for(int i=0;i<n;i++) p[i]=ir2.p[i];
    }
    int get_elem(int num) { return *(p+num); }
    ~Int_Array() { delete [] p; }
};

void show_array(Int_Array& a, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%3d ",a.get_elem(i));
    }
    puts("");
}

int main()
{
    enum {maxlen=32};
    char s0[32];
    int k,i;

    printf("How many elements? ");
    fgets(s0,maxlen,stdin);
    k=atoi(s0);

    Int_Array arr(k);
    for(i=0;i<k;i++)
    {
        printf("%3d ",arr.get_elem(i));
    }
    puts("");

    show_array(arr, k);

    printf("%3d ",arr.get_elem(k-2));

    return 0;
}

