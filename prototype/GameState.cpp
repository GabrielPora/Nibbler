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
	_mode = MODE_PLAY;

	resetMap();
	generateFood();
}

GameState::GameState(Coord size) {
	_size = size;
	_snake = Snake();
	_mode = MODE_PLAY;

	resetMap();
	generateFood();
}

GameState::GameState(int width, int height) {
	_size = Coord(width, height);
	_snake = Snake();
	_mode = MODE_PLAY;

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
	this->_mode = obj._mode;
}

GameState GameState::operator = (const GameState &obj) {
	this->_snake = obj._snake;
	this->_map = obj._map;
	this->_food = obj._food;
	this->_size = obj._size;
	this->_mode = obj._mode;

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

char		GameState::getMode(void) const {
	return (this->_mode);
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

void	GameState::setMode(char mode) {
	if (this->_mode == MODE_END && (mode == MODE_PLAY || mode == MODE_PAUSE)) {
		resetGame();
		this->_mode = mode;
	}
	else if (mode == MODE_PLAY || mode == MODE_PAUSE || mode == MODE_END)
		this->_mode = mode;
}

/*
** Functions
*/

bool		GameState::runIteration(void) {
	if (this->_mode != MODE_PLAY)
		return (false);
	
	moveSnake();

	return ((this->_mode == MODE_PLAY) ? true : false);
}

void		GameState::resetGame(void) {
	_map.clear();

	*this = GameState();
}

/*
** Private Functions
*/
void		GameState::resetMap(void) {
	for (int k = 0; k < this->_size.getY(); k++)
		for (int l = 0; l < this->_size.getX(); l++)
			this->_map[l][k] = MAP_EMPTY;
}

void		GameState::resetSnake(void) {
	this->_snake.resetSnake();
}

/* Requires other assets to be loaded into the map first */
void		GameState::generateFood(void) {
	bool	found = false;
	Coord	pos;

	srand(clock());
	do {
		pos = Coord(rand() % this->_size.getX(), rand() % this->_size.getY());

		if (this->_map[pos.getX()][pos.getY()] == MAP_EMPTY) {
			found = true;
			this->_food = pos;
		}
	} while (!found);

	loadFood();
}

void		GameState::loadSnake(void) {
	std::list<Part>	body = this->_snake.getBody();
	Coord			pos;

	for (std::list<Part>::iterator k = body.begin(); k != body.end(); k++) {
		pos = k->getPos();
		this->_map[pos.getX()][pos.getY()] = MAP_BODY;
	}
	pos = this->_snake.getHeadPos();
	this->_map[pos.getX()][pos.getY()] = MAP_HEAD;
}

void		GameState::loadFood(void) {
	char	c = this->_map[this->_food.getX()][this->_food.getY()];

	if (c == MAP_EMPTY)
		this->_map[this->_food.getX()][this->_food.getY()] = MAP_FOOD;
	else if (c != MAP_FOOD)
		throw std::runtime_error("Food has been incorrectly generated");
}

void		GameState::moveSnake(void) {
	Coord		pos;

	pos = this->_snake.getTailPos();
	this->_map[pos.getX()][pos.getY()] = MAP_EMPTY;
	pos = this->_snake.getHeadPos();
	this->_map[pos.getX()][pos.getY()] = MAP_BODY;

	this->_snake.moveSnake();
	pos = this->_snake.getHeadPos();
	if (pos.getX() < 0 || this->_size.getX() >= pos.getX())
		this->_mode = MODE_END;
	else if (pos.getY() < 0 || this->_size.getY() >= pos.getY())
		this->_mode = MODE_END;
	else if (this->_map[pos.getX()][pos.getY()] == MAP_EMPTY)
		this->_map[pos.getX()][pos.getY()] = MAP_HEAD;
	else if (this->_map[pos.getX()][pos.getY()] == MAP_FOOD) {
		this->_map[pos.getX()][pos.getY()] = MAP_HEAD;
		this->_snake.eat();
		generateFood();
	}
	else
		this->_mode = MODE_END;
}
