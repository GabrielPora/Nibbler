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
	_size = Coord(DEFAULT_HEIGHT, DEFAULT_WIDTH);
	_snake = Snake();
	resetMap();
	generateFood();
}

GameState::GameState(Coord size) {
	_size = size;
	_snake = Snake();
	resetMap();
	generateFood();
}

GameState::GameState(int width, int height) {
	_size = Coord(width, height);
	_snake = Snake();
	resetMap();
	generateFood();
}

GameState::~GameState(void) {
	_map.clear();
}

/*
** Copying
*/
GameState::GameState(const GameState &obj) {
	this->_snake = obj._snake;
	this->_map = obj._map;
	this->_food = obj._food;
	this->_size = obj._size;
}

GameState GameState::operator = (const GameState &obj) {
	this->_snake = obj._snake;
	this->_map = obj._map;
	this->_food = obj._food;
	this->_size = obj._size;

	return (*this);
}

/*
** Getters
*/

MAP		GameState::getMap(void) const {
	return (this->_map);
}

Snake	GameState::getSnake(void) const {
	return (this->_snake);
}

Coord	GameState::getSize(void) const {
	return (this->_size);
}

int		GameState::getWidth(void) const {
	return (this->_size.getX());
}

int		GameState::getHeight(void) const {
	return (this->_size.getY());
}

Direction	GameState::getSnakeDir(void) const {
	return (this->_snake.getDirection());
}

/*
** Setters
*/
void	GameState::setSize(Coord size) {
	this->_size = size;
}

void	GameState::setWidth(int width) {
	this->_size.setX(width);
}

void	GameState::setHeight(int height) {
	this->_size.setY(height);
}
void	GameState::setSnakeDir(char direction) {
	this->_snake.setDirection(direction);
}

/*
** Functions
*/
void		GameState::resetMap(void) {
	for (int k = 0; k < this->_size.getY(); k++)
		for (int l = 0; l < this->_size.getX(); l++)
			this->_map[l][k] = 0;
}

void		GameState::resetSnake(void) {
	//
}

void		GameState::runIteration(void) {
	//
}

void		GameState::generateFood(void) {
	//
}
