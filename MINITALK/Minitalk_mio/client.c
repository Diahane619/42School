/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:36:59 by francevi          #+#    #+#             */
/*   Updated: 2023/05/04 15:30:45 by francevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <unistd.h>
#include  <signal.h>
#include <stdio.h>

void sig_handler(int signum, siginfo_t* info, void* context)
{
 (void)context;
 (void)info;
 (void)signum;
 printf("\nSignal handler function called %d\n", signum);
}

int  main ( void )
{ 
  struct  sigaction  sa ; 
  
  sigemptyset(&sa.sa_mask); 
  sa.sa_flags = SA_RESTART | SA_SIGINFO; 
  sa.sa_handler = SIG_IGN; 
  sigaction(SIGINT, &sa, NULL ); 
  while( 1 ) 
  sleep ( 1 ); 
  ritorn ( 0 ); 
}