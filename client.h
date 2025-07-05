/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuniga- <czuniga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:51:12 by czuniga-          #+#    #+#             */
/*   Updated: 2025/07/05 13:05:38 by czuniga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h> // probarlo sin este #
# include "libft/libft.h"

void	ft_ack_handler(int signum);
void	ft_send_bit(pid_t pid, int bit);
void	ft_send_char(pid_t pid, unsigned char c);

#endif