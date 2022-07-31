// Aidan Hopper
// 42236214
// I pledge that this submission is solely my work, and that I have neither given, nor received help from anyone.

import java.util.Scanner;

public class BaseToDecimal {

    public static String convertBase(int quotient, int base){
	// Converts base 10 to base passed through as argument
	String retstr = "";
	String remainders = "";
	while(quotient != 0) {
	    int remainder = quotient % base;
	    quotient = quotient / base;
	    // if base 16 and remainder is > 9 then
	    // replace 2 digit number with letter
	    if (base > 10 && remainder > 9) {
	        switch (remainder) {
		case 10:
		    remainders += "A";
		    break;
		case 11:
		    remainders += "B";
		    break;
		case 12:
		    remainders += "C";
		    break;
		case 13:
		    remainders += "D";
		    break;
		case 14:
		    remainders += "E";
		    break;
		case 15:
		    remainders += "F";
		    break;
		}
	    }
	    else {
		remainders += String.valueOf(remainder);
	    }
	}
	// reverses order of remainders string to return proper number
	for (int i = remainders.length()-1; i > -1; i--) {
		retstr += remainders.substring(i, i + 1);
	}
	return retstr;
    }
    
    public static void baseToDecimal(){
	// converts the number entered in terminal into three bases
	// of the same number
	Scanner scan = new Scanner(System.in);
	System.out.print("Please enter a base 10 number : ");
	String str = scan.next();
	int intnum = Integer.parseInt(str);
	String rtwo = convertBase(intnum, 2);
	String reight = convertBase(intnum, 8);
	String rsixteen = convertBase(intnum, 16);
	System.out.println("Base 2 : " + rtwo);
	System.out.println("Base 8 : " + reight);
	System.out.println("Base 16: " + rsixteen);
    }
    
    public static void main(String args[]){
	baseToDecimal();
    }
    
}
