import java.util.Scanner;
import java.lang.Math;

public class Distancia_Euclidiana {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    float x1, y1, x2, y2;
    do {
      x1 = in.nextFloat();
      y1 = in.nextFloat();
      x2 = in.nextFloat();
      y2 = in.nextFloat();
      System.out.printf("%.2f\n", (Math.sqrt(Math.pow((x1 - x2), 2) + Math.pow((y1 - y2), 2))));
    } while (x1 != 0 && y1 != 0 && x2 != 0 && y2 != 0);
    in.close();
  }
}
