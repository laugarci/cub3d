/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:18:37 by laugarci          #+#    #+#             */
/*   Updated: 2022/10/18 15:20:06 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*itera la lista 'lst' y aplica la funcion 'f' al contenido de cada nodo.
 * Crea una lista resultante de la aplicacion correcta y sucesiva de la
 * funcion 'f' sobre cada nodo. La funcion 'del' se utilitza para eliminar
 * el contenido de un nodo, si hace falta. */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;
	void	*tmp;

	if (!lst)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		newnode = ft_lstnew(tmp);
		if (!newnode)
		{
			ft_lstclear(&newlist, del);
			free(tmp);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
