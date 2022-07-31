// Aidan Hopper
// 42236214
// I pledge that this submission is solely my work, and that I have neither given, nor received help from anyone.

import java.util.*;
import java.lang.Math.*;

public class Main {


  // gets power of 2 from input n and takes in error string
  public static int powOf2(String eStr, int n){
    // checks if only one bit is flipped by doing a bitwise and operation on n and n - 1
    if ((n & (n - 1)) != 0) {
      System.out.println(eStr);
      System.exit(0);
    }
    
    // counts number of right shifts until number is 1 which corresponds to power number
    int pow = 0;
    while (n != 1) {
      int newN = n >> 1;
      pow++;
      n = newN;
    } 
    return pow;

  }
    
  // converts hex address to binary address
  public static String hexToBin(String addr) {

    // check if address is larger than 2 chars and if it starts with 0x
    if (addr.length() < 3 || !addr.substring(0, 2).equals("0x")) {
      System.out.println("Memory address is not in Base 16. Program terminated");
      System.exit(0);
    }
    
    String bin = "";

    // iterates through the hex string appending corresponding binary values to the bin string
    char c;
    for (int i = 2; i < addr.length(); i++) {
      c = addr.charAt(i);
      switch (c) {
	case '0':
	  bin += "0000";
	  break;
	case '1':
	  bin += "0001";
	  break;
	case '2':
	  bin += "0010";
	  break;
	case '3': 
	  bin += "0011";
	  break;
	case '4': 
	  bin += "0100";
	  break;
	case '5': 
	  bin += "0101";
	  break;
	case '6': 
	  bin += "0110";
	  break;
	case '7':
	  bin += "0111";
	  break;
	case '8':
	  bin += "1000";
	  break;
	case '9': 
	  bin += "1001";
	  break;
	case 'A': 
	  bin += "1010";
	  break;
	case 'B': 
	  bin += "1011";
	  break;
	case 'C': 
	  bin += "1100";
	  break;
	case 'D': 
	  bin += "1101";
	  break;
	case 'E': 
	  bin += "1110";
	  break;
	case 'F':
	  bin += "1111";
	  break;
	default:
	  System.out.println("Memory address is not in Base 16. Program terminated");
	  System.exit(0);
      }
    }
    return bin;

  }

  public static void main (String[] args) {
    Scanner s = new Scanner(System.in);
    System.out.println("Main memory representation is A x 2^E");
    
    // getting main memory
    System.out.print("Value A: ");
    int aVal = s.nextInt();
    System.out.print("Exponent E: ");
    int ePow = s.nextInt();
    long mainMemory = aVal * (int) Math.pow(2, ePow);
    System.out.println("Main memory: " + aVal + " x 2^" + ePow + " = " + mainMemory + " bytes");

    // getting cache memory
    System.out.print("Cache blocks: ");
    int blocks = s.nextInt();
    int blocksPow = powOf2("Cache Blocks is not in Base 2. Program terminated", blocks);
    System.out.print("Bytes in Cache blocks: ");
    int blockSize = s.nextInt();
    int blockSizePow = powOf2("Bytes in Cache blocks is not in Base 2. Program terminated", blockSize);
    System.out.print("k-set associative value: ");
    int kVal = s.nextInt();
    int kPow = powOf2("k-set associative values is not in Base 2. Program terminated", kVal);
    
    // getting memory address
    System.out.print("Memory address in Base 16: ");
    String hexAddr = s.next();
    String binAddr = hexToBin(hexAddr);
    if (binAddr.length() > ePow) {
      System.out.println("Size of address is larger than main memory size. Program terminated");
      System.exit(0);
    }
    int addrLen = binAddr.length();
    System.out.println("Address in binary: " + binAddr);

    // direct cache
    System.out.println("\nDirect Cache mapping of " + hexAddr + " address");
    int wordBits = blockSizePow;
    int lineBits = blocksPow;
    int tagBits = addrLen - (wordBits + lineBits);
    System.out.println("[TAG] " + tagBits + " : [LINE] " + lineBits + " : [WORD] " + wordBits);
    System.out.println("[TAG] " + binAddr.substring(0, tagBits) + 
      " : [LINE] " + binAddr.substring(tagBits, tagBits + lineBits) + 
      " : [WORD] " + binAddr.substring(tagBits + lineBits, tagBits + lineBits + wordBits));

    // associative cache
    System.out.println("\nAssociative Cache mapping of " + hexAddr + " address");
    wordBits = blockSizePow;
    tagBits = ePow - wordBits;
    System.out.println("[TAG] " + tagBits + " : [WORD] " + wordBits);
    System.out.println("[TAG] " + binAddr.substring(0, tagBits) + 
      " : [WORD] " + binAddr.substring(tagBits, tagBits + wordBits));

    // set-associative cache
    System.out.println("\n4-way Cache mapping of " + hexAddr + " address");
    wordBits = blockSizePow;
    int setBits = blocksPow - kPow;
    tagBits = ePow - (wordBits + setBits);
    System.out.println("[TAG] " + tagBits + " : [SET] " + setBits + " : [WORD] " + wordBits);
    System.out.println("[TAG] " + binAddr.substring(0, tagBits) + 
      " : [SET] " + binAddr.substring(tagBits, tagBits + setBits) + 
      " : [WORD] " + binAddr.substring(tagBits + setBits, tagBits + setBits + wordBits));

    s.close();

  }
}
