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
    while (s[i])
    {
        
         if ((f(s[i + 1]) == 1 || s[i + 1] == '\0') && (s[i] >= 'a' && s[i] <= 'z'))
        {
            s[i] -= 32;
            write(1,&s[i],1);
        }
        else if((s[i] >= 'A' && s[i] <= 'Z') && (f(s[i + 1]) == 0 && s[i+1] != '\0'))
        {
            s[i] += 32;
            write(1,&s[i],1);
        }
        else
            write(1,&s[i],1);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac > 1)
    {
        int i = 1;
        while (i < ac)
        {
            display(av[i]);
            write(1,"\n",1);
            i++;
        }
    }
   else
       write(1,"\n",1);

}
