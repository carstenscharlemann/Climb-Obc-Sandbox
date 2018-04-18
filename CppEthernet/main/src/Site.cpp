/*
 * Site.cpp
 *
 *  Created on: 18 Apr 2018
 *      Author: Robert
 */

#include "Site.hh"

Site::Site() {
	BaseUri="";
}

Site::Site(const char* baseUri) {
	BaseUri=baseUri;
}

Site::~Site() {

}

void Site::AddPage(Page page) {

	Site::Pages.push_back(page);
}

Page Site::FindPage(std::string uri) {
	auto r = find_if(Site::Pages.begin(), Site::Pages.end(), [&uri](const Page &arg) { return (arg.myurl == uri); });
	Page p = *r;
	return p;
}






