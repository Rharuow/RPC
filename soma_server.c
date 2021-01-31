#include "soma.h"

float *
adicao_100_svc(valores *argp, struct svc_req *rqstp)
{
	static float  result;

	printf("Cliente solicita: \n");
	printf("Operação de adição para %.2f e %.2f", argp->valor1, argp->valor2);
	result = argp->valor1 + argp->valor2;
	printf("Resultado da adição: %.2f \n\n", result);

	return &result;
}
