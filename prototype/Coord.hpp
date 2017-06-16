/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Coord.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 09:33:34 by khansman          #+#    #+#             */
/*   Updated: 2017/06/16 09:33:36 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORD_HPP
# define COORD_HPP

#include <iostream>

class Coord {
public:
	Coord(void);
	Coord(int x, int y);
	~Coord(void);

	Coord(const Coord &obj);
	Coord operator = (const Coord &obj);

	Coord operator + (const Coord &obj);
	Coord operator - (const Coord &obj);
	Coord operator * (const Coord &obj);
	Coord operator / (const Coord &obj);

	Coord operator ++ (int);
	Coord operator ++ (void);
	Coord operator -- (int);
	Coord operator -- (void);

	int		getX(void) const;
	int		getY(void) const;

	void	setX(int x);
	void	setY(int y);

	void	incX(void);
	void	incY(void);
	void	decX(void);
	void	decY(void);

private:
	int		_x;
	int		_y;
};

std::ostream& operator << (std::ostream &o, const Coord &coord);

#endif
