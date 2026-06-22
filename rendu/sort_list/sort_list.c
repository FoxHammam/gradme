#include <unistd.h>

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};
void ft_swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *h = lst;
    t_list *p = lst;

    while (lst)
    {
        p = lst->next;
        while (p)
        {
            if (!(*cmp)(lst->data,p->data))
            {
                ft_swap(&lst->data,&p->data);
            }
            p = p->next;
        }
        lst= lst->next;
    }
    return h;
}
        
