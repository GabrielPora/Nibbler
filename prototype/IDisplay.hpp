/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IDisplay.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 10:55:42 by khansman          #+#    #+#             */
/*   Updated: 2017/06/17 10:55:45 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IDISPLAY_HPP
# define IDISPLAY_HPP

# include <map>

# include "Direction.hpp"

# ifndef MAP
#  define MAP std::map<int, std::map<int, char> >
# endif

class IDisplay {
public:
	IDisplay(void) {};
	virtual ~IDisplay(void) {};

	IDisplay(const IDisplay &obj) {};
	virtual IDisplay operator = (const IDisplay &obj);

	virtual void		drawMap(MAP map);
	virtual void		drawScore(int score);
	virtual void		drawPause(void);
	virtual void		drawGameOver(void);

	virtual Direction	getDirection(void);

};

#endif
