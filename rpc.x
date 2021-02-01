struct valores {
  float valor1;
  float valor2;
};

program SOMA{
  version VERSAO {
    float ADICAO(valores)=1;
    float SUBTRACAO(valores)=2;
    float DIVISAO(valores)=3;
    float MULTIPLICACAO(valores)=4;
  }=100;
} = 200;