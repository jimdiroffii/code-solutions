import java.util.*;
import java.io.*;
import java.math.*;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.

 * Write an answer using System.out.println()
 * To debug: System.err.println("Debug messages...");
 **/
class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        String MESSAGE = in.nextLine();
        // System.err.println("DEBUG: " + MESSAGE);

        String binaryMsg = convertStringToBinary(MESSAGE);
        // System.err.println("DEBUG: " + binaryMsg);

        String unaryMsg = convertBinaryToUnary(binaryMsg);
        // System.err.println("DEBUG: " + unaryMsg);

        System.out.println(unaryMsg);
        in.close();
    }

    public static String convertStringToBinary(String str) {
        StringBuilder result = new StringBuilder();
        char[] chars = str.toCharArray();
        for (char c : chars) {
            result.append(String.format("%7s", Integer.toBinaryString(c)).replaceAll(" ", "0"));
        }

        return result.toString();
    }

    public static String convertBinaryToUnary(String str) {
        StringBuilder result = new StringBuilder();
        char[] chars = str.toCharArray();

        for (int i = 0; i < chars.length;) {
            if (chars[i] == '0') {
                result.append("00 ");
                while (i < chars.length && chars[i] == '0') {
                    // System.err.println("DEBUG: '0' loop: char=" + chars[i] + " i=" + i);
                    result.append("0");
                    i++;
                }
            }
            else {
                result.append("0 ");
                while (i < chars.length && chars[i] == '1') {
                    // System.err.println("DEBUG: '1' loop: char=" + chars[i] + " i=" + i);
                    result.append("0");
                    i++;
                }
            }
            if (i < chars.length) {
                result.append(" ");
            }
            // System.err.println("DEBUG: Looping: i=" + i + " result=" + result.toString());
        }

        return result.toString();
    }
}