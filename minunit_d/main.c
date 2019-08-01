#include <stdio.h>
#include <stdlib.h>
#include "../juego_damas/funciones.h"
#include "minunit.h"

#define T 8


MU_TEST(test_funcion_mover)
{
    mu_check(moverPieza(5, 1, 2)== 1);
}


MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_funcion_mover);

}

int main()
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}
