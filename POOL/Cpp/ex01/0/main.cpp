/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 13:59:38 by msarr             #+#    #+#             */
/*   Updated: 2015/06/26 13:59:40 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

int main()
{

	//Warlock bob; //Ne compile pas
	Warlock bob("Bob", "the magnificent"); //Compile
	Warlock jim("Jim", "the nauseating"); //Compile
	bob = jim; //Ne compile pas
	//Warlock jack(jim); //Ne compile pas
// Warlock const richard("Richard", "Mistress of Magma");
// richard.introduce();
// std::cout << richard.getName() << "-" << richard.getTitle() << std::endl;
// Warlock* jack = new Warlock("Jack", "the Long");
// jack->introduce();
// jack->setTitle("the Not-So-Long-After-All");
// jack->introduce();
// delete jack;
return (0);
}
