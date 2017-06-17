/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameState.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:29:39 by khansman          #+#    #+#             */
/*   Updated: 2017/06/16 17:29:40 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMESTATE_HPP
# define GAMESTATE_HPP

# include <iostream>
# include <map>

# include "Coord.hpp"
# include "Snake.hpp"

# define DEFAULT_HEIGHT	20
# define DEFAULT_WIDTH	20

# define MAP_EMPTY		0
# define MAP_OBSTICLE	1
# define MAP_HEAD		2
# define MAP_BODY		3
# define MAP_FOOD		4

# define MAP std::map<int, std::map<int, int> >

class GameState {
public:
	GameState(void);
	GameState(Coord size);
	GameState(int width, int height);
	~GameState(void);

	GameState(const GameState &obj);
	GameState operator = (const GameState &obj);

	MAP			getMap(void) const;
	Snake		getSnake(void) const;
	Coord		getSize(void) const;
	int			getWidth(void) const;
	int			getHeight(void) const;
	Direction	getSnakeDir(void) const;

	void		setSize(Coord size);
	void		setWidth(int width);
	void		setHeight(int height);
	void		setSnakeDir(char direction);

	void		resetMap(void);
	void		resetSnake(void);
	void		runIteration(void);
	void		generateFood(void);

private:
	Snake		_snake;
	MAP			_map;
	Coord		_food;

	Coord		_size;

};

#endif
