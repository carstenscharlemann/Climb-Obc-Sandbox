/*
 * Page.cpp
 *
 *  Created on: 16 Apr 2018
 *      Author: Robert
 */
#include "Page.hh"

#include <cstring>

Page::Page(const char *name) {
	myurl = std::string(name);
}

Page::~Page() {

}

fs_file *Page::GetHttpFile(void) {
	static struct fs_file fs;
	static char buffer[200];

	if (myurl == "/page1.html") {
		std::string content = "<html><head><title>Title 1</title></head><body><h1>Page 1</h1><a href=""/"">Home</a></body></html>";

		int hlen = GetHTTP_Header(myurl.c_str(), buffer);
		fs.data = (const char *) buffer;

		memcpy((void *) &fs.data[hlen], (void *)content.c_str(), content.size() - 1);

		fs.len = hlen + content.size() - 1;
		fs.index = fs.len;
		fs.http_header_included = 1;

		return &fs;
	} else {
		return 0;
	}

}
