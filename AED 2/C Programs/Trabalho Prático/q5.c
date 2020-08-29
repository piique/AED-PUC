#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// declaracao de funcoes utilizadas
float modulo(float value);
bool ehTriangulo(float x, float y, float z);

int main(void) {
  float X, Y, Z;

  scanf("%f %f %f", &X, &Y, &Z);

  // conjunto de ifs para verificar se valores sao triangulo e de qual tipo
  if (!ehTriangulo(X, Y, Z)) {
    printf("NAO FORMA UM TRIANGULO\n");
  } else {
    if (X == Y && Y == Z) {
      printf("EQUILATERO");
    } else if (X != Y && X != Z && Y != Z) {
      printf("ESCALENO");
    } else {
      printf("ISOSCELES");
    }
  }

  return 0;
}

// verifica condicao  de existencia do triangulo de acordo com a regra comentada dentro da funcao e retorna true caso seja triangulo
bool ehTriangulo(float x, float y, float z) {
  // | y - z | < x < y + z;
  // | x - z | < y < x + z;
  // | x - y | < z < x + y;
  if (modulo(y - z) < x && x < y + z && modulo(x - z) < y && y < x + z && modulo(x - y) < z && z < x + y)
    return true;
  return false;
}

// recebe valor float e retorna seu modulo
float modulo(float value) {
  return value > 0 ? value : value * (-1);
}
