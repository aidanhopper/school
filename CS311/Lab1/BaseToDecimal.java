// Aidan Hopper
// 42236214
// I pledge that this submission is solely my work, and that I have neither given, nor received help from anyone.

import java.util.Scanner;

public class BaseToDecimal {

    public static int baseToDecimal() {
	Scanner scan = new Scanner(System.in);
	int base = 0;
	// asks for base until base is valid
	do {
	    System.out.print("Please enter a base : ");
	    String strBase = scan.next();
	    base = Integer.parseInt(strBase);
	} while (base < 2 || base > 9);
	System.out.print("Please Enter a base " + base + " number : ");
	String num = scan.next();
	// algorithm for converting base X to base 10
	int result = 0;
	int length = num.length();
	for (int i = 0; i < length; i++) {
	    int d = Character.getNumericValue(num.charAt(i));
	    result = (result * base) + d;
	}
	// returning result
	return result;
    }
    
    public static void main(String[] args) {
	int decimal = baseToDecimal();
	System.out.println(decimal);
    }
    
}
