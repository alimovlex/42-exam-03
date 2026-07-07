/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   hidenp.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: alalimov <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/10 18:17:50 by alalimov       #+#    #+#                */
/*   Updated: 2026/05/10 18:17:52 by alalimov       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_hidenp(char *s1, char *s2)
{
        while(*s2)
        {
                if (*s1 && *s2 == *s1)
                        s1++;
                s2++;
        }
        if (!*s1)
                write(1, "1\n", 2);
        else
                write(1, "0\n", 2);
}

int main(int argc, char **argv)
{
        if (argc != 3)
                write(1, "\n", 1);
        else
        {
                char *s1 = *++argv;
                char *s2 = *++argv;
                ft_hidenp(s1, s2);
        }

        return 0;
}
