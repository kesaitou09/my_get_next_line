#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin_list;
	t_list	*new_elem;

	if (!lst || !f || !del)
		return (NULL);
	begin_list = ft_lstnew((f)(lst->content));
	if (!begin_list)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new_elem = ft_lstnew((f)(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&begin_list, del);
			return (NULL);
		}
		ft_lstadd_back(&begin_list, new_elem);
		lst = lst->next;
	}
	return (begin_list);
}
