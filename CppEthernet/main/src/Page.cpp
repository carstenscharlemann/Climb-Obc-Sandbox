/*
 * Page.cpp
 *
 *  Created on: 16 Apr 2018
 *      Author: Robert
 */
#include "Page.hh"

#include <cstring>

Page::Page(const char* name, const char* title,  const char* body) {
	myurl = std::string(name);
	mybody = std::string(body);
	mytitle = std::string(title);
}

Page::~Page() {

}

static struct fs_file fs;
static char buffer[400];

fs_file *Page::GetHttpFile(void) {


	std::string htmlcontent = "<html><head><title>" + mytitle + "</title></head><body>"+ mybody +"</body></html>";

	// TODO: encapsulate somehow in Site.... or give callback as param, or ....
	int hlen = GetHTTP_Header(myurl.c_str(), buffer);
	fs.data = (const char *) buffer;

    memcpy((void *) &(fs.data[hlen]), (void *)htmlcontent.c_str(), htmlcontent.size() - 1);
	fs.len = hlen + htmlcontent.size() - 1;
	fs.index = fs.len;
	fs.http_header_included = 1;
	fs.is_custom_file = true;
	return &fs;
}
