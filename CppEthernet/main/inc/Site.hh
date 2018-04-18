/*
 * Site.hh
 *
 *  Created on: 18 Apr 2018
 *      Author: Robert
 */

#ifndef SRC_SITE_HH_
#define SRC_SITE_HH_

#include <string>
#include <algorithm>
#include <iostream>
#include <list>

#include "page.hh"


class Site {
	std::string BaseUri;
	std::list<Page> Pages;

public:
	Site();
	Site(const char *baseUri);
	virtual ~Site();

	void AddPage(Page page);
	Page FindPage(std::string uri);
};


#endif /* SRC_SITE_HH_ */
