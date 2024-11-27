#include <stdlib.h>
#include <stdio.h>

#include "malloc.h"

struct memo_chunk {
    int size;
    char* pointer_to_start;
};

// void* get_me_blocks(size_t how_much) {
//     void* ptr = sbrk(0);
//     sbrk(how_much);
//     return ptr;
// }

static char memo_arr[1024];
static size_t free_idx = 0;

char* xmalloc(size_t size) {
    if (free_idx + size <= sizeof(memo_arr)) {
        char* memo_ptr = memo_arr + free_idx;
        free_idx += size;

        if (memo_ptr == NULL) {
            fprintf(stderr, __FILE__ ":%d malloc failed\n", __LINE__);
            exit(1);
        }

        fprintf(stderr, __FILE__ ":%d malloc(%lu) = %p\n", __LINE__, size, memo_ptr);

        return memo_ptr;
    }

    // char *ptr = malloc(size);

    // if (ptr == NULL) {
    //     fprintf(stderr, __FILE__ ":%d malloc failed\n", __LINE__);
    //     exit(1);
    // }
    // fprintf(stderr, __FILE__ ":%d malloc(%lu) = %p\n", __LINE__, size, ptr);
    // return ptr;
}

void xfree(void *ptr) {
    free_idx = 0;

    // fprintf(stderr, __FILE__ ": free(%p)\n", ptr);
    // free(ptr);
}