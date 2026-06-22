#include <unistd.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}   t_list;

int	ft_list_size(t_list *begin_list)
{
    t_list *p;
    int i = 0;

    p = begin_list;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}
   
