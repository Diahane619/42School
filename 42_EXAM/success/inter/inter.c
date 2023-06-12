/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:14:59 by francevi          #+#    #+#             */
/*   Updated: 2023/06/11 16:26:47 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
 int main(int argc, char *argv[]) 
 {
    int i = 0; 
	int j;
    int printed[256] = {0}; // array di flag per tenere traccia dei caratteri stampati
    if (argc == 3) 
	{
        while (argv[1][i]) 
		{
            j = 0;
            while (argv[2][j] && argv[1][i] != argv[2][j])
                j++;
            if (argv[2][j] && !printed[(unsigned char)argv[1][i]])// stampa solo se il carattere non è già stato stampato 
			{
                write(1, &argv[1][i], 1);
                printed[(unsigned char)argv[1][i]] = 1; // imposta il flag a 1 per indicare che il carattere è stato stampato
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}