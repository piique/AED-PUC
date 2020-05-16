#include <locale.h>  // no prompt: chcp 65001 - para funcionar formatação
#include <math.h>
#include <stdio.h>
#include <stdlib.h>  // limpar console: system("cls");
#include <time.h>

int divisao(int a, int b);
int qtdDigitos(int a);
int multiplica(int a, int b);
int somaDigitos(int a);
float progressaoAritimetica(float razao, float primeiroTermo, int n);
int questao6();
int questao7();
int questao8();
int questao9();
int questao10();
int questao11();
int questao12();
int func(int x);
int questao13();
void preencheVetor(int *vetor, int n);
void ordenaVetor(int *vetor, int n);
void buscaSegundoMenor(int *vetor, int n, int *segundoMenor);
int questao14();

int main() {
    setlocale(LC_ALL, "Portuguese_Brasil");
    int opc = -1;
    int n1, n2;
    float razao = 3, primeiroTermo = 1;
    int n_esimoTermo = 6;

    while (opc != 0) {
        system("cls");
        printf("------------------------------------ MENU ------------------------------------");
        printf("\nEscolha uma das questões:  ");
        printf("\n 1  - Funcao recursiva que divide A por B atraves de subtracao");
        printf("\n 2  - Quantidade de digitos de um inteiro");
        printf("\n 3  - Soma dos digitos de um inteiro");
        printf("\n 4  - Multiplicacao de dois numeros atraves de soma");
        printf("\n 5  - n-esimo termo de uma progressão geometrica");
        printf("\n 6  - Relatorio da observacao do trecho de codigo passado na questao");
        printf("\n 7  - Imprimir os elementos do vetor cujo valor seja igual ao indice da posicao");
        printf("\n 8  - Preencher vetor com numeros inteiros de 0 a 10");
        printf("\n 9  - Gerar temperaturas aleatorias entre 18 e 40 e imprimir alguns valores");
        printf("\n 10 - Preencher vetor com a seguinte regra: se a posição do vetor é múltipla de 2, deve-se armazenar 1");
        printf("\n 11 - Pegar N numeros x (de 0 a 9) e armazenar na posicao x do vetor o numero de vezes em que x aparece");
        printf("\n 12 - Preencher vetor com 100 primeiros numeros da serie Fibonacci");
        printf("\n 13 - Algoritmo que preenche um vetor com o resultado da função f(x) = 3x³ + 2x² +1x -5, onde X eh o indice da posicao do vetor. Apos preencher o vetor, imprima seu conteudo");
        printf("\n 14 - Armazena N inputs e depois retorna o segundo menor valor do vetor");
        printf("\n 0 - Sair");
        printf("\n\nOpc: ");

        scanf("%i", &opc);

        switch (opc) {
            case 1:
                printf("Digite 2 numeros: ");
                scanf("%i %i", &n1, &n2);
                printf("\nResultado da divisao de %i por %i eh: %i", n1, n2, divisao(n1, n2));
                return 0;
                break;

            case 2:
                printf("\nDigite 1 numero inteiro: ");
                scanf("%i", &n1);
                printf("\nQuantidade de digitos: %i\n", qtdDigitos(n1));
                break;

            case 3:
                printf("\nDigite 1 numero inteiro: ");
                scanf("%i", &n1);
                printf("\nSoma dos digitos do inteiro eh: %i", somaDigitos(n1));
                return 0;
                break;

            case 4:
                printf("Digite 2 numeros: ");
                scanf("%i %i", &n1, &n2);
                printf("\nResultado da multiplica de %i por %i eh: %i", n1, n2, multiplica(n1, n2));
                return 0;
                break;

            case 5:
                printf("\nProgressao geometrica\nDigite a razao: ");
                scanf("%f", &razao);
                printf("Digite o primeiro termo: ");
                scanf("%f", &primeiroTermo);
                printf("Digite a posicao do termo a ser descoberto: ");
                scanf("%i", &n_esimoTermo);

                printf("\nResultado: %0.2f", progressaoAritimetica(razao, primeiroTermo, n_esimoTermo));
                return 0;
                break;

            case 6:
                questao6();
                break;
            case 7:
                questao7();
                break;

            case 8:
                questao8();
                break;
            case 9:
                questao9();
                break;

            case 10:
                questao10();
                break;

            case 11:
                questao11();
                break;

            case 12:
                questao12();
                break;

            case 13:
                questao13();
                break;

            case 14:
                questao14();
                break;

            case 0:
                printf("Saindo...");
                return 0;
                break;

            default:
                printf("Escolha invalida! Tecle enter para voltar ao menu.\n");
        }
        printf("\nTecle Enter para continuar...\n");
        getch();
    }

    return 0;
}

/*
Descrição: recebe 2 numeros inteiros e retorna a divisao entre eles
Entradas: 2 inteiros
Saída: 1 inteiro
*/
int divisao(int a, int b) {
    if (a - b < 0) {
        return 0;
    }
    return divisao(a - b, b) + 1;
}
/*
Descrição: recebe 1 inteiro e retorna a quantidade de digitos
Entradas: 1 inteiro
Saída: 1 inteiro
*/
int qtdDigitos(int a) {
    int count = 1;
    if (a < 10) {
        return 1;
    } else {
        count += qtdDigitos(a / 10);
        return count;
    }
}

/*
Descrição: recebe 2 inteiros e retorna a multiplicacao deles
Entradas:  inteiro
Saída: 1 inteiro
*/
int multiplica(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    } else if (a > 0 && b > 1) {
        return a + multiplica(a, --b);
    }
}

/*
Descrição: recebe um inteiro e retorna a soma de digitos
Entradas: 1 inteiro
Saída: 1 inteiro
*/
int somaDigitos(int a) {
    int soma = 0;
    if (a < 10) {
        return a;
    } else {
        soma += somaDigitos(a / 10) + a % 10;
        return soma;
    }
}

/*
Descrição: recebe a razao(float), o primeiro termo (float) e o n-esimo termo (int)
Entradas: 2 float e 1 int
Saída: retorna o valor do termo na posição n em float
*/
float progressaoAritimetica(float razao, float primeiroTermo, int n) {
    if (n <= 1) {
        return primeiroTermo;
    }
    return razao * progressaoAritimetica(razao, primeiroTermo, --n);
}

int questao6() {
    // preenche o vetor
    // vetor = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    int vetor[10];
    printf("Digite 10 valores para serem colocados no vetor: ");
    for (int i = 0; i <= 9; i++) {
        scanf("%d", &vetor[i]);
    }

    // imprime o vetor na ordem contraria
    for (int i = 9; i >= 0; i--) {
        printf("%i ", vetor[i]);
    }
    return 0;
}

int questao7() {
    // int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int vetor[10];
    printf("Digite 10 numeros: ");

    for (int i = 0; i <= 9; i++) {
        scanf("%i", &vetor[i]);
    }

    for (int i = 0; i <= 9; i++) {
        if (i == vetor[i]) {
            printf("\nVetor[%i]: %i", i, vetor[i]);
        }
    }
}

int questao8() {
    srand(time(NULL));
    int vetor[15];
    for (int i = 0; i <= 15; i++) {
        vetor[i] = rand() % 11;  // numeros aleatorios entre 0 e 10
    }

    for (int i = 0; i <= 9; i++) {
        printf("\nVetor[%i]: %i", i, vetor[i]);
    }
    return 0;
}

int questao9() {
    int vetor[15], soma = 0, max = 18, min = 40;  // valores entre 18 e 40
    float media;
    srand(time(NULL));

    for (int i = 0; i <= 15; i++) {
        vetor[i] = rand() % 23 + 18;  // valores aleatorios entre 18 e 40
        printf("\nVetor[%i]: %i", i, vetor[i]);

        // soma dos valores para calculo da media
        soma += vetor[i];

        // pegar valor maximo
        if (vetor[i] > max)
            max = vetor[i];

        // pegar valor minimo
        if (vetor[i] < min)
            min = vetor[i];
    }
    media = soma / 15.0;
    printf("\nValor da media: %0.2f", media);
    printf("\nValor maximo: %i", max);
    printf("\nValor minimo: %i", min);

    soma = 0;  // utilizada como contador
    // for para validar quantas vezes a temperatura foi abaixo da media
    for (int i = 0; i <= 15; i++) {
        if (vetor[i] < media) {
            soma++;
        }
    }

    printf("\nQuantidade de vezes abaixo da media: %i", soma);
    return 0;
}

int questao10() {
    int vetor[10], i;
    for (i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            vetor[i] = 1;
            printf("\nVetor[%i]: %i", i, vetor[i]);
        } else {
            vetor[i] = 0;
            printf("\nVetor[%i]: %i", i, vetor[i]);
        }
    }

    return 0;
}

int questao11() {
    int vetor[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, n = 0;
    while (n != -1) {
        printf("Digite numeros entre 0 e 9 (digite -1 para sair): ");
        scanf("%i", &n);

        if (n >= 0 && n <= 9)
            vetor[n]++;
        else if (n != -1)
            printf("Apenas numeros entre 0 e 9!\n");
    }

    // printa o vetor
    for (int i = 0; i < 10; i++)
        printf("\nVetor[%i]: %i", i, vetor[i]);

    return 0;
}

int questao12() {
    // declara variaveis
    double vetor[100];
    int i;

    // preenche as duas primeiras posicoes da sequencia de fibonacci
    vetor[0] = 1;
    vetor[1] = 1;

    // preenche o vetor com a seguencia de fibonacci
    for (i = 2; i <= 100; i++) {
        vetor[i] = vetor[i - 1] + vetor[i - 2];
    }

    // printa o vetor
    for (int i = 0; i < 100; i++)
        printf("\nVetor[%i]: %0.0f", i, vetor[i]);

    return 0;
}

/*
Descrição: recebe um inteiro e retorna o resultado da função
Entradas: 1 int
Saída: 1 int
*/
int func(int x) {
    return (3 * pow(x, 3) + 2 * pow(x, 2) + x - 5);
}

int questao13() {
    int vetor[10];
    // preenche o vetor
    for (int i = 0; i < 10; i++)
        vetor[i] = func(i);

    // printa o vetor
    for (int i = 0; i < 10; i++)
        printf("\nVetor[%i]: %i", i, vetor[i]);

    return 0;
}

void preencheVetor(int *vetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite um numero: ");
        scanf("%i", &vetor[i]);
    }
}

// ordena vetor atraves do metodo bolha
void ordenaVetor(int *vetor, int n) {
    int aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void buscaSegundoMenor(int *vetor, int n, int *segundoMenor) {
    *segundoMenor = vetor[n - 1];  // coloca o maior valor na variavel segundoMenor
    for (int i = 1; i < n; i++) {
        if (vetor[i] < *segundoMenor && vetor[i] != vetor[0]) {
            *segundoMenor = vetor[i];
        }
    }
}

int questao14() {
    // declara variaveis
    int tamanhoVetor, segundoMenor;

    printf("Digite a quantidade de numeros: ");
    scanf("%i", &tamanhoVetor);
    if (tamanhoVetor <= 0) {
        printf("\nValor invalido!");
        return 0;
    }

    // declara o vetor
    int vetor[tamanhoVetor];

    // preenche o vetor
    preencheVetor(vetor, tamanhoVetor);

    // ordena o vetor de forma crescente
    ordenaVetor(vetor, tamanhoVetor);

    // busca o valor do segundo menor e armazena na variavel segundoMenor
    buscaSegundoMenor(vetor, tamanhoVetor, &segundoMenor);

    // printa o vetor
    for (int i = 0; i < tamanhoVetor; i++)
        printf("\nVetor[%i]: %i", i, vetor[i]);

    printf("\nMenor: %i", vetor[0]);
    printf("\nSegundo menor: %i", segundoMenor);

    return 0;
}
