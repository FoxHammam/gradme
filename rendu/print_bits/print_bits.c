#include <unistd.h>

void	print_bits(unsigned char octet)
{
    int i = 8;
    while (i--)
        write(1,(octet >> i & 1) ? "1" : "0", 1);
}
