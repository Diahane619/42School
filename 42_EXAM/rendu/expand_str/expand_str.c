/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:19:00 by francevi          #+#    #+#             */
/*   Updated: 2023/06/05 12:07:58 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    int len = 0;
    int first_word = 1;

    if (argc == 2)
    {
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            ++i;
        while (argv[1][i])
        {
            while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
            {
                ++len;
                ++i;
            }
            if (len > 0 && first_word == 0)
                write(1, "   ", 3);
            first_word = 0;
            write(1, &argv[1][i - len], len);
            len = 0;
            while (argv[1][i] == ' ' || argv[1][i] == '\t')
                ++i;
        }
    }
    write(1, "\n", 1);
}
