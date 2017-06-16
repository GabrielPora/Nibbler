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
	//
}

Snake	GameState::getSnake(void) const {
	//
}

Coord	GameState::getSize(void) const {
	//
}

int		GameState::getWidth(void) const {
	//
}

int		GameState::getHeight(void) const {
	//
}

char	GameState::getSnakeDir(void) const {
	//
}

/*
** Setters
*/

/*
** Functions
*/
