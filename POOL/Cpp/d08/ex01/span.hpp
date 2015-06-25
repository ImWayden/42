/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/25 17:04:41 by msarr             #+#    #+#             */
/*   Updated: 2015/06/25 17:04:41 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <algorithm>
#include <list>
#include <numeric>

class Span {

public:
    Span(const unsigned int n);

    ~Span();

    Span(const Span &src);

    int shortestSpan();

    int longestSpan();

    void addNumber(int n);

    Span &operator=(Span const &rhs);

    std::list<int> getContent() const;

    int getSize() const;

private:

    std::list<int> content;
    unsigned int size;

    Span();

};

#endif