#include <criterion/criterion.h>
#include <stdio.h>

Test(main_tests, always_passes) {
    
    cr_assert(1, "Ce test passe toujours.");
}
