#include "divis.h"
int *
divis_1_svc(numbers *argp, struct svc_req *rqstp)
{
static int result;
	if(argp->b == 0){
		printf(“Denomindador nao pode ser 0”);
	}
else{
printf("Funcao divis(%d, %d) foi chamada\n", argp->a, argp->b);
result = argp->a / argp->b;
}
return &result;
}
