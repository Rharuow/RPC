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
// --------------------------- Subtraçao
float subtracao(CLIENT *clnt, float valor1, float valor2) {
	valores numero;
	float *result;

	numero.valor1 = valor1;	
	numero.valor2 = valor2;	

	result = subtracao_100(&numero, clnt);

	if(result == NULL) {
		fprintf(stderr, "Problema na chamada do RPC \n");
		exit(0);
	}

	return *result;
}
// --------------------------- MULTIPLICACAO
float multiplicacao(CLIENT *clnt, float valor1, float valor2) {
	valores numero;
	float *result;

	numero.valor1 = valor1;	
	numero.valor2 = valor2;	

	result = multiplicacao_100(&numero, clnt);

	if(result == NULL) {
		fprintf(stderr, "Problema na chamada do RPC \n");
		exit(0);
	}

	return *result;
}
// --------------------------- Divisão
float divisao(CLIENT *clnt, float valor1, float valor2) {
	valores numero;
	float *result;

	numero.valor1 = valor1;	
	numero.valor2 = valor2;	

	result = divisao_100(&numero, clnt);

	if(result == NULL) {
		fprintf(stderr, "Problema na chamada do RPC \n");
		exit(0);
	}

	return *result;
}


float main(int argc, char *argv[]) {
	CLIENT *clnt;
	float valor1, valor2;
	int operacao;

	printf("Escolha operação:");
	printf("(1)- Soma\n");
	printf("(2)- Subtração\n");
	printf("(3)- Divisão\n");
	printf("(4)- Multiplicação\n");
	scanf("%d", &operacao);

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

	switch(operacao) {
		case 1:
			printf("Servidor processou o seguinte resultado: \n");
			printf("%.2f + %.2f = %.2f\n", valor1, valor2, adicao(clnt, valor1, valor2));
		break;
		case 2:
			printf("Servidor processou o seguinte resultado: \n");
			printf("%.2f - %.2f = %.2f\n", valor1, valor2, subtracao(clnt, valor1, valor2));
		break;
		case 3:
		if(valor2!=0) {
			printf("Servidor processou o seguinte resultado: \n");
			printf("%.2f / %.2f = %.2f\n", valor1, valor2, divisao(clnt, valor1, valor2));
		} else {
			printf("Não existe divisão por 0!\n");
		}
		break;
		case 4:
			printf("Servidor processou o seguinte resultado: \n");
			printf("%.2f * %.2f = %.2f\n", valor1, valor2, multiplicacao(clnt, valor1, valor2));
		break;
		default:
			printf("Operador inválido! \n");
			printf("Escolha um tipo de operação: \n1 para [+]\n 2 para [-]\n 3 para [/]\n 4 para [*]; \n");
			break;
	};

	return 0;
}