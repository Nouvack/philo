/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:54:11 by nsantand          #+#    #+#             */
/*   Updated: 2026/02/26 15:33:32 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"





int main(int argc, char **argv)
{

    if(argc < 5 || argc > 6)
    {
        printf("hola");
        return(1);
    }
    if(!parse_arguments(argv))
		{
      printf("ERROR");
      return(1);
    }
    

    return(0);
}
