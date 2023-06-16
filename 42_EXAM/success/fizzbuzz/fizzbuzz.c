#include <unistd.h>

int putnumbr(int n)
{
    char number[10] = "0123456789";

    if(n > 9)
        putnumbr(n / 10);
    write(1, &number[n % 10], 1);
}

int main()
{
    int n = 1;

    while(n <= 100)
    {
        if(n % 15 == 0)
            write(1, "fizzbuzz", 8);
        else if(n % 3 == 0)
            write(1, "fizz", 4);
        else if(n % 5 == 0)
            write(1, "buzz", 4);
        else
            putnumbr(n);
            write(1, "\n", 1);
        n++;
    }
}