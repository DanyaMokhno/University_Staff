#include <stdio.h>
#include <stdlib.h>
#include <time.h>

template <class T>
class Array
{
private:
    T *p;
    int n;
public:
    Array(int num)
    {
        n=num;
        p = new T[n];
        // there must be initialization!
        for(int i=0;i<n;i++) p[i]=rand()/10000000;
    }
    T get_elem(T num) { return *(p+num); }
    // task; add method show() !!
    ~Array() { delete [] p; }
};

void show_array(Array<int> a, int n)
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

    srand(time(NULL));
    printf("How many elements? ");
    fgets(s0,maxlen,stdin);
    k=atoi(s0);

    Array<int> arr(k);
    for(i=0;i<k;i++)
    {
        printf("%3d ",arr.get_elem(i));
    }
    puts("");

    //show_array(arr, k);

    printf("%3d ",arr.get_elem(k-2));

    return 0;
}
