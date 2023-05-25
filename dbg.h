#ifndef DBG_H
#define DBG_H

#include <errno.h>
#include <string.h>

#define debug(M, ...) fprintf(stderr, "L%d: " M "\n", __LINE__, ##__VA_ARGS__)
#define log_err(M, ...) fprintf(stderr, "L%d: " M "\n", __LINE__, ##__VA_ARGS__)
#define check(A,M, ...) if(!A) {log_err(M,##__VA_ARGS__); goto error;}
#define check_debug(A, M, ...) if(!A) {debug(M, ##__VA_ARGS__); goto error;}
#define check_mem(A) check((A), "Out of memory.");

#endif
