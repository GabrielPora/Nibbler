/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 14:09:31 by khansman          #+#    #+#             */
/*   Updated: 2017/06/16 14:09:32 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HPP
# define SNAKE_HPP

# include <iostream>
# include <list>

# include "Coord.hpp"
# include "Direction.hpp"
# include "Part.hpp"

# define DEFAULT_SNAKE_LENGTH 4

class Snake {
public:
	Snake(void);
	Snake(Coord head, Direction tail);
	~Snake(void);

	Snake(const Snake &obj);
	Snake operator = (const Snake &obj);

	std::list<Part>		getBody(void) const;
	Direction			getDirection(void) const;
	Coord				getHeadPos(void) const;
	Coord				getTailPos(void) const;

	void				setDirection(Direction dir);
	void				setDirection(char dir);
	
	void				moveSnake(void);
	void				eat(void);

private:
	std::list<Part>		_body;
	Direction			_direction;

};

std::ostream& operator << (std::ostream &o, const Snake &s);

#endif

