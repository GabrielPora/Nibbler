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
#include <list>

# include "Coord.hpp"
# include "Direction.hpp"
# include "Part.hpp"

class Snake {
public:
	Snake(void);
	Snake(Coord head, Direction tail);
	~Snake(void);

	Snake(const Snake &obj);
	Snake operator = (const Snake &obj);

	std::list<Part>		getBody(void);
	Direction			getDirection(void);

	void				setDirection(Direction dir);
	void				setDirection(char dir);
	
	bool				moveSnake(void);

private:
	std::list<Part>		body;
	Direction			direction;

};

std::ostream& operator << (std::ostream &o, const Snake &s);

#endif

