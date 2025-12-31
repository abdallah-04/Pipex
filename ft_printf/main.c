#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    printf("%x",ULONG_MAX);

    //    printf("========stand========\n");
    //    int l333 = printf(" 42Amman \n Abdallah   \t anything %%\n ---------\n");
    //    int l444 = ft_printf(" 42Amman \n Abdallah   \t anything %%\n ---------\n");
    //    printf("len printf %d len ft_print %d\n",l333 , l444);

    // printf("======== %%-1 ========\n");
    // char c = 'A';
    // int l111 = printf(NULL, c);
    // int l222 = ft_printf(NULL, c);
    // printf("len printf %d len ft_print %d\n",l111 , l222);

    // printf("======== %%c ========\n");
    // char c = 'A';
    // int l1 = printf("%c\n", c);
    // int l2 = ft_printf("%c\n", c);
    // //ft_printf("%c\n", c);
    // printf("len printf %d len ft_print %d\n",l1 , l2);

//     printf("\n======== %%s ========\n");
//     char *str = "| | | | | | 42Amman | | | | | |";
//     int l3 = printf("%s\n", str);
//     int l4 =ft_printf("%s\n", str);
//     //ft_printf("%s\n", " ");
//     printf("len printf %d len ft_print %d\n",l3 , l4);

//     printf("\n======== %%s (NULL) ========\n");
//     char *null_str = NULL;
//     int l5 =printf("%s\n", null_str);
//     int l6 =ft_printf("%s\n", null_str);
//     printf("len printf %d len ft_print %d\n",l5 , l6);

    // printf("\n======== %%p ========\n");
    // char *str1 = "42";
    // char *ptr = str1;
    // int l7 = printf("%p\n", ptr);
    // int l8 =ft_printf("%p\n", ptr);
    // printf("len printf %d len ft_print %d\n",l7 , l8);

    // printf("\n======== %%p (NULL) ========\n");
    // char *null_ptr = NULL;
    // int l9 = printf("%p\n", null_ptr);
    // int l10 =ft_printf("%p\n", null_ptr);
    // printf("len printf %d len ft_print %d\n",l9 , l10);

    // printf("\n======== %%d ========\n");
    // int d = -12345;
    // int l11 = printf("%d | %d | %d | %d\n", INT_MIN, INT_MAX , 0, d);
    // int l12 = ft_printf("%d | %d | %d | %d\n", INT_MIN, INT_MAX, 0, d);
    // printf("len printf %d len ft_print %d\n",l11 , l12);

//     printf("\n======== %%i ========\n");
//     int i = 6789;
//     int l13 = printf("%i | %i | %i\n", INT_MIN, INT_MAX, i);
//     int l14 = ft_printf("%i | %i | %i\n", INT_MIN, INT_MAX, i);
//     printf("len printf %d len ft_print %d\n",l13 , l14);

//     printf("\n======== %%u ========\n");
//     unsigned int u = 23232773;
//     unsigned int u_neg = (unsigned int)-1;
//     int l15 = printf("%u | %u | %u | %u\n", 0, UINT_MAX, u_neg,u);
//     int l16 =ft_printf("%u | %u | %u | %u\n", 0, UINT_MAX, u_neg,u);
//     printf("len printf %d len ft_print %d\n",l15 , l16);

//     printf("\n======== %%x ========\n");
//     int hex = 373592855; //16449317
// //  int_min = 80000000
// //  int_max = 7fffffff
//     int l17 = printf("%x | %x | %x | %x\n", 0, INT_MIN, hex,INT_MAX);
//     int l18 =ft_printf("%x | %x | %x | %x\n", 0, INT_MIN, hex, INT_MAX);
//     //ft_printf("%x\n",ULONG_MAX); // error
//     printf("len printf %d len ft_print %d\n",l17 , l18);
// //  ft_printf("%x | %x\n",LONG_MAX,LONG_MAX);
// //  printf("%x | %x\n",LONG_MAX,LONG_MAX);


//     printf("\n======== %%X ========\n");
//     int hex = 373592855; //16449317
// //  int_min = 80000000
// //  int_max = 7FFFFFFF
//     int l19 = printf("%X | %X | %X | %X\n", 0, INT_MIN, hex,INT_MAX);
//     int l20 =ft_printf("%X | %X | %X | %X\n", 0, INT_MIN, hex, INT_MAX);
//     printf("len printf %d len ft_print %d\n",l19 , l20);

//     printf("\n======== %%%% ========\n");
//     int l21 = printf("%%\n");
//     int l22 = ft_printf("%%\n");
//     printf("len printf %d len ft_print %d\n",l21 , l22);

//        printf("========extra========\n");
//        int l333 = printf(NULL);
//        int l444 = ft_printf(NULL);
//        printf("len printf %d len ft_print %d\n",l333 , l444);


    return 0;
}
