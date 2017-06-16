/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 14:09:40 by khansman          #+#    #+#             */
/*   Updated: 2017/06/16 14:09:41 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"

/*
** Constructors and Destructors
*/
Snake::Snake(void) {
	_direction = Direction(EAST);
	Part part = Part(0, 0);

	for (int k = 0; k < DEFAULT_SNAKE_LENGTH; k++) {
		_body.push_front(part);
		part = _direction.moveCoord(part.getPos());
	}
}

Snake::Snake(Coord head, Direction tail) {
	for (int k = 0; k < DEFAULT_SNAKE_LENGTH; k++) {
		_body.push_back(head);
		head = tail.moveCoord(head);
	}
}

Snake::~Snake(void) {
	_body.clear();
}

/*
** Copying
*/
Snake::Snake(const Snake &obj) {
	for (std::list<Part>::iterator it = _body.begin(); it != _body.end(); ++it)
		this->_body.push_back(*it);
	this->_direction = _direction;
}

Snake Snake::operator = (const Snake &obj) {
	for (std::list<Part>::iterator it = _body.begin(); it != _body.end(); ++it)
		this->_body.push_back(*it);
	this->_direction = _direction;

	return (*this);
}

/*
** Getters
*/
std::list<Part>		Snake::getBody(void) const {
	return (this->_body);
}

Direction			Snake::getDirection(void) const {
	return (this->_direction);
}

/*
** Setters
*/
void				Snake::setDirection(Direction dir) {
	this->_direction = dir;
}

void				Snake::setDirection(char dir) {
	this->_direction = Direction(dir);
}

/*
** Display
*/
std::ostream& operator << (std::ostream &o, const Snake &s) {
	o << "<Snake>";

	return (o);
}

/*
** Functions
*/
void				Snake::moveSnake(void) {
	Part	head = this->_direction.moveCoord(this->_body.front().getPos());

	this->_body.push_front(head);
	if (!this->_body.back().getEaten())
		this->_body.pop_back();
	else
		this->_body.back().setEaten(false);
}

void				Snake::eat(void) {
	this->_body.front().setEaten(true);
}
