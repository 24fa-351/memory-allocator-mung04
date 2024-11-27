#include <stdlib.h>

#ifndef MALLOC_H
#define MALLOC_H

char* xmalloc(size_t size);
void xfree(void *ptr);

#endif
