/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Direction.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 14:13:09 by khansman          #+#    #+#             */
/*   Updated: 2017/06/16 14:13:10 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Direction.hpp"

/*
** Constructors and Destructors
*/
Direction::Direction(): _x(0), _y(0) {
	//
}

Direction::Direction(char x, char y): _x(x), _y(y) {
	//
}

Direction::Direction(char direction) {
	setDirection(direction);
}

Direction::~Direction(void) {
	//
}

/*
** Copying
*/
Direction::Direction(const Direction &obj) {
	this->_x = obj._x;
	this->_y = obj._y;
}

Direction Direction::operator = (const Direction &obj) {
	this->_x = obj._x;
	this->_y = obj._y;

	return (*this);
}

/*
** Getters
*/
char	Direction::getX() const {
	return (this->_x);
}

char	Direction::getY() const {
	return (this->_y);
}

char	Direction::getDirection() const {
	if (this->_x == 0 && this->_y == 1)
		return (NORTH);
	if (this->_x == 1 && this->_y == 0)
		return (EAST);
	if (this->_x == 0 && this->_y == -1)
		return (SOUTH);
	if (this->_x == -1 && this->_y == 0)
		return (WEST);

	return (LOST);
}

/*
** Setters
*/
void	Direction::setX(char x) {
	if (-1 <= x && x <= 1)
		this->_x = x;
}

void	Direction::setY(char y) {
	if (-1 <= y && y <= 1)
		this->_y = y;
}

void	Direction::setDirection(char direction) {
	switch (direction) {
		case NORTH :
			_x = 0;
			_y = 1;
			break;
		case EAST :
			_x = 1;
			_y = 0;
			break;
		case SOUTH :
			_x = 0;
			_y = -1;
			break;
		case WEST :
			_x = -1;
			_y = 0;
			break;
		default :
			_x = 0;
			_y = 0;
	}
}