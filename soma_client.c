#include "soma.h"


// --------------------------- SOMA
float adicao(CLIENT *clnt, float valor1, float valor2) {
	valores numero;
	float *result;

	numero.valor1 = valor1;	
	numero.valor2 = valor2;	

	result = adicao_100(&numero, clnt);

	if(result == NULL) {
		fprintf(stderr, "Problema na chamada do RPC \n");
		exit(0);
	}

	return *result;
}

// Main

float main(int argc, char *argv[]) {
	CLIENT *clnt;
	float valor1, valor2;

	printf("Informe o valor1:");
	scanf("%f", &valor1);

	printf("Informe o valor2:");
	scanf("%f", &valor2);

	clnt = clnt_create (argv[1], SOMA, VERSAO, "udp");
	if (clnt == (CLIENT *) NULL) {
		clnt_pcreateerror (argv[1]);
		exit (1);
	}

	printf("Servidor retornou como resultado: \n");
	printf("%.2f \n", adicao(clnt, valor1, valor2));

	return 0;
}
