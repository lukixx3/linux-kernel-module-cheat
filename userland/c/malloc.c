/* https://cirosantilli.com/linux-kernel-module-cheat#malloc */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *is;
    size_t nbytes = 2 * sizeof(*is);

    /* Allocate 2 ints. Note that unlike traditional stack arrays (non-VLA)
     * this value does not have to be determined at compile time! */
    is = malloc(nbytes);

    /* This can happen for example if we ask for too much memory. */
    if (is == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    /* Write to and read from the allocated memory. */
    is[0] = 1;
    is[1] = 2;
    assert(is[0] == 1);
    assert(is[1] == 2);

    /* Free the allocated memory. */
    free(is);

    return EXIT_SUCCESS;
}
