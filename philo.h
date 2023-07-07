/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:01:57 by tbolkova          #+#    #+#             */
/*   Updated: 2023/07/07 13:47:13 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct 			s_data {
	char				**av;
	int32_t				philo_num;
	int64_t				run_program;
	char				*err_msg;
	pthread_mutex_t		*mutex_forks;
	pthread_mutex_t		mutex_message;
	pthread_mutex_t		mutex_death;
	bool				rip_philo;
}						t_data;

typedef struct 	s_philo {
	int32_t				id;
	int32_t				eaten_meals;
	int32_t				num_philo;
	int64_t				time_routine_start;
	int64_t				time_program_start;
	int64_t				finished_eating;
	int64_t				action_death;
	int64_t				action_eating;
	int64_t				action_sleeping;
	int64_t				times_philo_eats;
	pthread_t			thread;
	pthread_mutex_t		*mutex_left_fork;
	pthread_mutex_t		*mutex_right_fork;
	t_data				*access;
} 				t_philo;

//!-------------SRC---------------

//	main.c
void philo_run(t_philo *philo);

//	utils.c
void 	init_data(t_data *data, int32_t ac, char **av);
void 	err_message(char *msg);
int32_t 	check_valid_arg(char *av);
int 	is_whitespace(char c);
int64_t 	get_time(void);

//	libft_utils.c
int			ft_isdigit(int d);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);

//	mutex.c
void create_mutex(t_data *data);
void destroy_mutex(t_data *data);

//	threads.c
void init_threads(t_philo *philo, t_data *data, char **av, int32_t ac);
void execute_threads(t_philo *philo);
void wait_threads(t_philo *philo);

//	logic.c
void take_forks(t_philo *philo);
bool philo_died(t_philo *philo);
void eating(t_philo *philo);
void sleeping(t_philo *philo);
void thinking(t_philo *philo);

#endif








// typedef struct s_data
// {
// 	char			**av;
// 	int32_t			amount_philos;
// 	int64_t			start_program;
// 	pthread_mutex_t	*mutex_forks;
// 	pthread_mutex_t	mutex_message;
// 	pthread_mutex_t	mutex_death;
// 	bool			philo_died;
// }				t_data;

// typedef struct s_philo
// {	
// 	int32_t			eaten_meals;
// 	int32_t			amount_philos;
// 	int32_t			id;
// 	int64_t			time_routine_start;
// 	int64_t			time_program_starts;
// 	int64_t			finished_eating;
// 	int64_t			tt_die;
// 	int64_t			tt_eat;
// 	int64_t			tt_sleep;
// 	int64_t			times_philo_eats;
// 	pthread_t		thread;
// 	pthread_mutex_t	*mutex_left_fork;
// 	pthread_mutex_t	*mutex_right_fork;
// 	t_data			*access;
// }				t_philo;
