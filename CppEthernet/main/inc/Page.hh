/*
 * Page.h
 *
 *  Created on: 16 Apr 2018
 *      Author: Robert
 */

#ifndef SRC_PAGE_H_
#define SRC_PAGE_H_

#include <cstddef>
#include <iostream>
#include <string>

extern "C" {
	#include "lwip_fs.h"
}

class Page {

public:
	Page(const char *name, const char* title, const char* body);
	virtual ~Page();

	std::string myurl;
	fs_file *GetHttpFile(void);

private:
	std::string mytitle;
	std::string mybody;
};


#endif /* SRC_PAGE_H_ */
