/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Coord.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 09:33:40 by khansman          #+#    #+#             */
/*   Updated: 2017/06/16 09:33:42 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Coord.hpp"

/*
** Constructors and Destructors
*/
Coord::Coord(): _x(0), _y(0) {
	//
}

Coord::Coord(int x, int y): _x(x), _y(y) {
	//
}

Coord::~Coord(void) {
	//
}

/*
** Copying
*/
Coord::Coord(const Coord &obj) {
	this->_x = obj._x;
	this->_y = obj._y;
}

Coord Coord::operator = (const Coord &obj) {
	this->_x = obj._x;
	this->_y = obj._y;

	return (*this);
}

/*
** Maths Operators
*/
Coord Coord::operator + (const Coord &obj) {
	this->_x += obj._x;
	this->_y += obj._y;

	return (*this);
}

Coord Coord::operator - (const Coord &obj) {
	this->_x -= obj._x;
	this->_y -= obj._y;

	return (*this);
}

Coord Coord::operator * (const Coord &obj) {
	this->_x *= obj._x;
	this->_y *= obj._y;

	return (*this);
}

Coord Coord::operator / (const Coord &obj) {
	this->_x /= obj._x;
	this->_y /= obj._y;

	return (*this);
}

/*
** Post and Pre Increment and Decrement
*/
Coord Coord::operator ++ (int) {
	Coord	tmp(*this);
	operator++();

	return (tmp);
}

Coord Coord::operator ++ () {
	this->_x += 1;
	this->_y += 1;

	return (*this);
}

Coord Coord::operator -- (int) {
	Coord	tmp(*this);
	operator--();

	return (tmp);
}

Coord Coord::operator -- () {
	this->_x -= 1;
	this->_y -= 1;

	return (*this);
}

/*
** Getters
*/
int		Coord::getX(void) const {
	return (this->_x);
}

int		Coord::getY(void) const {
	return (this->_y);
}

/*
** Setters
*/
void	Coord::setX(int x) {
	this->_x = x;
}

void	Coord::setY(int y) {
	this->_y = y;
}

/*
** Basic Increment and Decrement
*/
void	Coord::incX(void) {
	this->_x++;
}

void	Coord::incY(void) {
	this->_y++;
}

void	Coord::decX(void) {
	this->_x--;
}

void	Coord::decY(void) {
	this->_y--;
}

std::ostream& operator << (std::ostream &o, const Coord &coord) {
	o << "( " << coord.getX() << "; " << coord.getY() << ")";

	return (o);
}
