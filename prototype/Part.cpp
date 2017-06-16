/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 09:14:23 by khansman          #+#    #+#             */
/*   Updated: 2017/06/16 09:14:24 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Part.hpp"

/*
** Constructors and Destructors
*/
Part::Part(void): _pos(), _eaten(false) {
	//
}

Part::Part(Coord coord): _pos(coord), _eaten(false) {
	//
}

Part::Part(Coord coord, bool eaten): _pos(coord), _eaten(eaten) {
	//
}

Part::Part(int x, int y): _pos(x, y), _eaten(false) {
	//
}

Part::~Part(void) {
	//
}

/*
** Copying
*/
Part::Part(const Part &obj) {
	this->_pos = obj._pos;
	this->_eaten = obj._eaten;
}

Part Part::operator = (const Part &obj) {
	this->_pos = obj._pos;
	this->_eaten = obj._eaten;

	return (*this);
}

/*
** Getters
*/
Coord	Part::getPos(void) const {
	return (this->_pos);
}

bool	Part::getEaten(void) const {
	return (this->_eaten);
}
/*
** Setters
*/
void	Part::setPos(Coord coord) {
	this->_pos = coord;
}

void	Part::setPos(int x, int y) {
	this->_pos = Coord(x, y);
}

void	Part::setEaten(bool eaten) {
	this->_eaten = eaten;
}

/*
** Display
*/
std::ostream& operator << (std::ostream &o, const Part &part) {
	o << "{PART: [eaten: " << part.getEaten()  << "; Pos: " << part.getPos() << "]}";

	return (o);
}
