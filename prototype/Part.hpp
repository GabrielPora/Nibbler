/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 09:14:19 by khansman          #+#    #+#             */
/*   Updated: 2017/06/16 09:14:20 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PART_HPP
# define PART_HPP

# include <iostream>
#include "Coord.hpp"

class Part {
public:
	Part(void);
	Part(Coord coord);
	Part(Coord coord, bool eaten);
	Part(int x, int y);
	~Part(void);

	Part(const Part &obj);
	Part operator = (const Part &obj);

	Coord	getPos(void) const;
	bool	getEaten(void) const;

	void	setPos(Coord coord);
	void	setPos(int x, int y);
	void	setEaten(bool eaten);

private:
	Coord	_pos;
	bool	_eaten;

};

std::ostream& operator << (std::ostream &o, const Part &part);

#endif
