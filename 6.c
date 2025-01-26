
    /* add.c */
    int add(int quant1, int quant2)
    {
      return(quant1 + quant2);
    }

    /* sub.c */
    int sub(int quant1, int quant2)
    {
      return(quant1 - quant2);
    }

    /* math1.h -library file that contains function declarations */
    int add(int, int);
    int sub(int, int);
    
    /* opDemo.c */
    #include "math1.h"
    #include <stdio.h>
 
    int main()
    {
     int x,y;
     printf("Enter values for x and y: ");
     scanf("%d %d",&x,&y);
     printf("%d + %d = %d \n", x, y, add(x, y));
     printf("%d - %d = %d \n", x, y, sub(x, y));
     return 0;
    }
    
// /*
//     /* Static Linking */
//     cc -c add.c sub.c
//     ar -cvq libtest.a add.o sub.o
//     cc opDemo.c libtest.a 
//     ./a.out

//     /* Dynamic Linking */
//     cc -c add.c sub.c -fPIC
//     cc -shared -o libctest.so add.o sub.o
//     cc -L . opDemo.c -l ctest -o dynamic
//     ./dynamic

//     downloading dynamic linking 
//     export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
// */
    