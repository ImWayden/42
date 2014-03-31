/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 14:02:06 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 14:02:12 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsft.h"

int main(int argc, char  **argv)
{
struct stat    test;
     char *str;
     
     str = ".";
     if (argc == 1)
        ft_ls(str,ft_recupdir(str), &ft_sortlist, &ft_put_list, NULL);
     else
     {
       str = argv[argc - 1];
       if (argv[argc - 1][0] == '-')
       {
        argc++;
        argv[argc - 1] = ".";
       }
       if ((!stat(argv[argc - 1], &test)) || (!lstat(argv[argc - 1], &test)))
            ft_action(argv, argc);
       else
           ft_acceserror(argv[0], argv, argc);
     }
    return 0;
}
