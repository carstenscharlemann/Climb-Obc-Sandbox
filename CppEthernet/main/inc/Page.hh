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
	std::string myurl;
public:
	Page(const char *name);
	virtual ~Page();

	fs_file *GetHttpFile(void);

};


#endif /* SRC_PAGE_H_ */
