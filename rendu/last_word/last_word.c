#include <unistd.h>
int f(char c)
{
    if (c == ' ' || c == '\t')
        return 1;
    return 0;
}
void display(char *s)
{
    int i = 0;
    int start , end = 0;
    
    while (s[i])
        i++;
    i--;
    while(i >= 0 && f(s[i]) == 1)
        i--;
    end = i + 1;
    while (f(s[i]) == 0)
        i--;
    start = i + 1;

    while (start < end)
    {
        write(1,&s[start],1);
        start++;
    }
    write(1,"\n",1);
}
int main(int ac,char **av)
{
    if (ac  == 2)
        display(av[1]);
    else
        write(1,"\n",1);
}
