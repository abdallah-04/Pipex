/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amufleh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:28:10 by amufleh           #+#    #+#             */
/*   Updated: 2025/08/23 12:36:15 by amufleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *doit(void *strr)
{
	char *str = (char *)strr;
	char *data = malloc((ft_strlen(str) *sizeof(char)) + 1);
	ft_strlcpy(data ,str ,ft_strlen(str));
	data[0] = data[0] - 32;
   	 return ((char *)data);
}
void print (void *str)
{
	printf("%s\n",(char *)str);
}
int main()
{
       t_list *a = ft_lstnew("abdallah");
        t_list *b = ft_lstnew("42");
        t_list *c = ft_lstnew("amman");
        ft_lstadd_back(&a, b);
        ft_lstadd_back(&a, c);
        t_list *new_lst = ft_lstmap(a, doit, free);
        ft_lstiter(new_lst,print);

}
