#include <stdio.h>

void    main()
{
    int age;
    int *address = &age;
    
    *address = 37;
    printf("%p\n", *address);
}