/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:25:00 by msarr             #+#    #+#             */
/*   Updated: 2015/06/16 16:25:04 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"


void ponyOnTheStack()
{

    Pony stackPony;
    stackPony.setColor("blue");
    stackPony.setName("PinkePie");
    stackPony.speak();
    return;
}


void ponyOnTheHeap()
{
    Pony *heapPony;
    heapPony = new Pony();
    heapPony->setColor("red");
    heapPony->setName("rainbowDash");
    heapPony->speak();
    delete heapPony;
    return;
}

int main(void)
{
    ponyOnTheStack();
    ponyOnTheHeap();
    return 0;
}
