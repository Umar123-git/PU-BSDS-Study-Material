#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "welcome.h"
#include "sorting.h"
#include "searching.h"

#define COUNT 100

int main()
{
   int m[COUNT];
   printf("main started\n%s\n\n", COPYRIGHT);
   linsearch(m, COUNT, 76);
   selsort(m, COUNT);
   binsearch(m, COUNT, 44);
   printf("main finished\n\n");

}
