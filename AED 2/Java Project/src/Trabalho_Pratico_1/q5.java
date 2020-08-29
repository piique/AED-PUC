package Trabalho_Pratico_1;

import java.util.Scanner;

public class q5 {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    float X, Y, Z;

    X = in.nextFloat();
    Y = in.nextFloat();
    Z = in.nextFloat();

    in.close();

    // conjunto de ifs para verificar se valores sao triangulo e de qual tipo
    if (!ehTriangulo(X, Y, Z)) {
      System.out.printf("NAO FORMA UM TRIANGULO\n");
    } else {
      if (X == Y && Y == Z) {
        System.out.printf("EQUILATERO");
      } else if (X != Y && X != Z && Y != Z) {
        System.out.printf("ESCALENO");
      } else {
        System.out.printf("ISOSCELES");
      }
    }
  }

  // verifica condicao de existencia do triangulo de acordo com a regra comentada
  // dentro da funcao e retorna true caso seja triangulo
  public static boolean ehTriangulo(float x, float y, float z) {
    // | y - z | < x < y + z;
    // | x - z | < y < x + z;
    // | x - y | < z < x + y;
    if (modulo(y - z) < x && x < y + z && modulo(x - z) < y && y < x + z && modulo(x - y) < z && z < x + y)
      return true;
    return false;
  }

  // recebe valor float e retorna seu modulo
  public static float modulo(float value) {
    return value > 0 ? value : value * (-1);
  }

}
