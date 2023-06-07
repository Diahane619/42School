/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:51:19 by iragusa           #+#    #+#             */
/*   Updated: 2023/05/15 15:46:28 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*azione da fare quando ricevo il segnale dal server*/
void	ft_action(int signum)
{
	(void)signum;
	ft_printf("il server ha inviato un SIGUSR1\n");
	exit(0);
}

/*trasforma ogni char in binario ed invia i segnali al server*/
void	ft_send_pid(int pid, int pid_server, int i)
{	
	while (i--)
	{
		if (pid_server >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(50);
	}
}

void	ft_send_msg(int pid, char *msg)
{
	char	c;
	int		i;

	while (*msg)
	{
		i = 8;
		c = *msg;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep (50);
		}
		msg++;
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(10);
	}	
	return ;
}

int	main(int ac, char **av)
{
	struct sigaction	action;
	int					pid_client;

	pid_client = getpid();
	action.sa_handler = ft_action;
	if (ac != 3 || !ft_strlen(av[2]))
		return (1);
	sigaction(SIGUSR1, &action, NULL);
	ft_printf("inviato: %d\n", ft_strlen(av[2]));
	ft_send_pid(ft_atoi(av[1]), pid_client, 32);
	ft_send_msg(ft_atoi(av[1]), av[2]);
	pause();
	return (0);
}
