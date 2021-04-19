#include "soma.h"
int *
add_1_svc(numbers *argp, struct svc_req *rqstp)
{
static int result;

printf("Funcao soma(%d, %d) foi chamada\n", argp->a, argp->b);
result = argp->a + argp->b;
return &result;
}
