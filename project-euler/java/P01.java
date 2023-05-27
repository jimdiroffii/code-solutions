package project_euler.java;

import java.util.Scanner;

/**
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we
 *  get 3, 5, 6 and 9. The sum of these multiples is 23.
 * 
 * Find the sum of all the multiples of 3 or 5 below 1000.
 * 
 * Answer: 233168
 */

public class P01 {
  int numberOfMultiples;
  int[] multiples;
  int maxValue;

  public P01() {
    this.setNumberOfMultiples(2);
    this.setMaxValue(1000);
    this.multiples = new int[numberOfMultiples];
    setMultiples();
  }

  public P01 (int numberOfMultiples, int maxValue) {
    this.setNumberOfMultiples(numberOfMultiples);
    this.setMaxValue(maxValue);
  }

  public void setNumberOfMultiples(int n) {
    this.numberOfMultiples = n;
  }

  public void setMaxValue(int n) {
    this.maxValue = n;
  }

  public void setMultiples() {
    Scanner kbinput = new Scanner(System.in);
    int i = 0;
    for (int multiple : multiples) {
      System.out.println("Enter multiple: ");
      int n = kbinput.nextInt();
      this.multiples[i] = n;
      i++;
      kbinput.nextLine();
    }
  }
  
  public static void main(String [] args) {
    P01 solver = new P01();
    int sum = 0;
    for (int i = 0; i < solver.maxValue; i++) {
      for (int multiple : solver.multiples) {
        if (i % multiple == 0) {
          sum += i;
          break;
        }
      }
    }
    System.out.println("Sum of multiples below max value: " + sum);
  }
}
