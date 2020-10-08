#ifndef _COMMON_H_
#define _COMMON_H_

struct pack
{
	uint32_t type;
	uint32_t len;
	uint32_t ver;
	char data[0];
};

#endif
