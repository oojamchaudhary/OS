
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
    #include <math1.h>
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
//     gcc -c add.c  
//     gcc -c sub.c
//     ar rs libmath1.a add.o sub.o
//     gcc -o opDemo opDemo.o libmath1.a 
//     ./opDemo

//     /* Dynamic Linking */
//     gcc -Wall -fPIC -c add.c
//     gcc -Wall -fPIC -c sub.c
//     gcc -shared -o libmath1.so add.o sub.o
//     gcc -o opDemo opDemo.o libmath1.so 
//     ./opDemo
// */
    