package Trabalho_Teorico;

public class Retangulo {

  private double altura;
  private double largura;

  Retangulo(double altura, double largura) {
    this.altura = altura;
    this.largura = largura;
  }

  Retangulo() {
    this.altura = 5;
    this.largura = 10;
  }

  public double getArea() {
    return altura * largura;
  }

  public double getPerimetro() {
    return (altura * 2) + (largura * 2);
  }

  public double getDiagonal() {
    return Math.sqrt(Math.pow(base, 2)) + Math.pow(altura, 2);
  }
}
