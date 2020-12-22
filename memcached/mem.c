/*
   ================================================================
   =
   =
   =   文件名称：mem.c
   =   创 建 者：Ang Wang  
   =   创建日期：2020年12月21日
   =   描    述：
   =
   ===============================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <libmemcached/memcached.h>

int main(int argc,char *argv[])
{
	memcached_st *memc;
	memcached_return rc;
	memcached_server_st *server;

	time_t expiration=0;
	uint32_t flags=0;

	memc = memcached_create(NULL);
	server = memcached_server_list_append(NULL,(char*)"localhost",11111,&rc);
	rc = memcached_server_push(memc,server);
	memcached_server_list_free(server);

	const char *key = "123456";
	const char *value = "asdfgh";

	size_t keylen = strlen(key);
	size_t valuelen = strlen(value);

	rc = memcached_set(memc,key,keylen,value,valuelen,expiration,flags);

	if(MEMCACHED_SUCCESS == rc){
		printf("Save data:%s successfully\n",value);
	}
	char *result = memcached_get(memc,key,keylen,&valuelen,&flags,&rc);
	if(MEMCACHED_SUCCESS == rc){
		printf("Get value:%s successfully\n",result);
	}
	memcached_free(memc);
	return 0;
}
