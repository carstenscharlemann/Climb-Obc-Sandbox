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

public:
	Site();
	Site(const char *baseUri);
	virtual ~Site();

	void AddPage(Page* page);
	void AddDefaultPage(Page* page);
	void AddNotFoundPage(Page* page);

	Page* FindPage(std::string uri);

private:
	std::string BaseUri;
	std::list<Page*> Pages;
};


#endif /* SRC_SITE_HH_ */
