/*
 * Site.cpp
 *
 *  Created on: 18 Apr 2018
 *      Author: Robert
 */

#include "Site.hh"
#include "board_api.h"

Site::Site() {
	BaseUri="";
	AddDefaultPage(new Page("","Home","<h1><a href=""/page1.html"">Page 1</a></h1><h1><a href=""/page2.html"">Page 2</a></h1>"));
	AddNotFoundPage(new Page("","404","<h1>Uuups, nothing here....!</h1>"));
	AddPage(new Page("/page1.html","Seite 1", "<h1><a href=""/"">Home</a></h1><h1><a href=""/page2.html"">to p 2</a></h1>"));
	AddPage(new Page("/page2.html","Seite 2", "<h1><a href=""/"">Home</a></h1><h1><a href=""/page1.html"">to p 1</a></h1>"));
}

Site::Site(const char* baseUri) {
	BaseUri=baseUri;
}

Site::~Site() {

}

void Site::AddPage(Page *page) {
	Pages.push_back(page);
}

void Site::AddDefaultPage(Page *page) {
	page->myurl = std::string("/index.html");
	AddPage(page);
}

void Site::AddNotFoundPage(Page *page) {
	page->myurl = std::string("/404.html");
	AddPage(page);
}



Page* Site::FindPage(std::string uri) {
	Page *p = 0;
	auto r = find_if(Pages.begin(), Pages.end(), [&uri](const Page *arg) {
		return (arg->myurl == uri);
	});
	if (r != Pages.end()) {
		p = *r;
	}
	return p;
}






