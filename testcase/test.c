#include <criterion/criterion.h>

Test(execise, 1) {
    cr_assert(sum(1, 2) == 3);
}

Test(execise, 2) {
    cr_assert(square(3) == 9);
}
