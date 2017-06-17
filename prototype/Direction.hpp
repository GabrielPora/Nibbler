/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Direction.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 14:13:03 by khansman          #+#    #+#             */
/*   Updated: 2017/06/16 14:13:05 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRECTION_HPP
# define DIRECTION_HPP

# include <iostream>

# include "Coord.hpp" 

# define LOST   0
# define NORTH 	1
# define EAST  	2
# define SOUTH 	3
# define WEST  	4

# define LEFT  -1
# define RIGHT  1
# define UP     1
# define DOWN  -1

class Direction {
public:
	Direction(void);
	Direction(char x, char y);
	Direction(char direction);
	~Direction(void);

	Direction(const Direction &obj);
	Direction operator = (const Direction &obj);

	char		getX(void) const;
	char		getY(void) const;
	char		getDirection(void) const;

	void		setX(char x);
	void		setY(char y);
	void		setDirection(char direction);

	Coord		moveCoord(Coord coord) const;
	Direction	opposite(void) const;

private:
	char	_x;
	char	_y;

};

std::ostream& operator << (std::ostream &o, const Direction &Direction);

#endif
