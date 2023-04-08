/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:12:00 by iragusa           #+#    #+#             */
/*   Updated: 2023/04/01 16:51:05 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_bitchar(int bit)
{
	static t_info info;
	
	if (info.check == 0)
	{
		info.pid_client = (info.pid_client << 1 | bit);
		info.i++;	
		if (info.i == 32)
		{
			info.check = 1;
			info.i = 0;
		}
	}
	else
	{
		info.c = (info.c << 1 | bit);
		info.i++;
		if (info.i == 8)
		{	
			if (info.c == 0)
			{
				kill(info.pid_client, SIGUSR1);
				info.check = 0;
				info.pid_client = 0;
			}
			write(1, &info.c, 1);
			info.c = 0;
			info.i = 0;
		}
	}
}
/*inserisci il pid nella struttura di sigaction*/
	
void	sighandler(int signum)
{
	if (signum == SIGUSR1)
		ft_bitchar(0);
	else
		ft_bitchar(1);
} 

int main(void)
{
	int	pid;
	struct sigaction	action;
	
	pid = getpid();
	if (pid <= 0)
		return (-1);
	ft_printf("Sono il server con pid %d\n",pid);
	action.sa_handler = sighandler;
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
	}
	return (0);
}
