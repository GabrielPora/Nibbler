/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameState.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:29:43 by khansman          #+#    #+#             */
/*   Updated: 2017/06/16 17:29:47 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameState.hpp"

/*
** Constructors and Destructors
*/
GameState::GameState(void) {
	_height = DEFAULT_HEIGHT;
	_width = DEFAULT_WIDTH;
	resetMap();
}
