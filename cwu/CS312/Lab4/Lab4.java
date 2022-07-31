// Aidan Hopper 
// 42236214
// I pledge that this submission is soley my work, and that I have neither given, nor received help from anyone.

import java.io.*;
import java.util.*;
import java.lang.Math;

public class Lab4 {

  // reads file from path + name and converts into integer array
  public static int[] readFile(String name, int print) {
    
    // creating file from path + name
    String path = "./bin/";
    File file = new File(path + name);
    
    // catches file not found exception
    try {

      // opening scanner and reading line in file
      Scanner sc = new Scanner(file);
      String data = sc.nextLine();
      sc.close();
      if (print == 1) {
	System.out.println("\nTransmitted file content: " + data);
	System.out.println("Total number of bytes read: " + data.length() + " bytes");
	System.out.println();
      }
      
      // creates integer array from string
      int[] arr = new int[data.length()];
      int k = 0;
      for (int i = arr.length - 1; i >= 0; i--) 
      //for (int i = 0; i < arr.length - 1; i++) 
	arr[i] = Integer.parseInt(String.valueOf(data.charAt(k++)));

      return arr;

    } catch (Exception e){}

    return null;
  }

  // gets the number of k bits needed for bits array
  public static int getKBits(int[] bits) {
    int totalBits = bits.length;

    int m = totalBits - 1;
    int k = 1;

    // finds the first k that makes 2^k >= m + k
    while (Math.pow(2, k) - 1 < m + k) {
      k++;
      m--;
    }     
  
    System.out.println("M data bits is: " + m + "\nK check bits is: " + k);
    System.out.println();
    
    return k;

  }

  // gets the check bits locations and returns them in an array
  public static int[] getCheckLoc(int k) {
    int[] arr = new int[k];

    // populates arr with locations of check bits
    for (int i = 0; i < k; i++) 
      arr[i] = (int) Math.pow(2, i) - 1;
    
    System.out.print("Location of the k check bits are: ");
    for (int x : arr)
      System.out.print(x + " ");
    System.out.println();

    return arr;
  }

  // gets the values of the check bit locations and returns them in an array
  public static int[] getCheckValues(int[] bits, int[] checkLocs) {
    int[] checkValues = new int[checkLocs.length];
    int index = checkLocs.length - 1;
    // gets value of check bits and records value to checkValues array
    for (int i : checkLocs)
      checkValues[index--] = bits[i];

    System.out.print("The k check bit values are: ");
    for (int x : checkValues) 
      System.out.print(x + " ");
    System.out.println();
    System.out.println();
    
    return checkValues;
  }

  // gets the syndrome word of the check values and calculates where the error is
  public static void getSynBit(int[] cvT, int[] cvR) {
    int[] arr = new int[cvR.length];
    int numHits = 0;
    // compares check values with xor operator and records number of 1s that occur
    for (int i = 0; i < cvR.length; i++) {
      arr[i] = cvT[i] ^ cvR[i];
      if (arr[i] == 1) numHits++;
    }

    
    // displays syndrome word
    System.out.print("The syndrome word is: ");
    for (int x : arr) 
      System.out.print(x + " ");
    System.out.println();
    
    // depending on numbder of 1s in syndrome word different outputs are shown
    if (numHits == 0) 
      System.out.println("No error in received file.");

    else if (numHits == 1) 
      System.out.println("Only one syndrome bit is set to 1. The error bit is one of the check bits. No correction needed.");
    
    else { 
      int sum = 0;
      for (int i = arr.length - 1; i >= 0; i--)
	sum += (Math.pow(2, arr.length - i - 1) * arr[i]);
      System.out.println("The location of the error bit in the received data is: " + sum);
    }
  }

  // prints data from transmission file
  public static void printT() {
    int[] bitsT = readFile("transmitfile.bin", 1);
    int kT = getKBits(bitsT);
    int[] checkLocsT = getCheckLoc(kT);
    int[] checkValuesT = getCheckValues(bitsT, checkLocsT);
  }

  // tests transmission file compared to received file
  public static void testFile(String name) {
    // getting transmission file data
    int[] bitsT = readFile("transmitfile.bin", 0);
    int kT = getKBits(bitsT);
    int[] checkLocsT = getCheckLoc(kT);
    int[] checkValuesT = getCheckValues(bitsT, checkLocsT);

    // getting specified receive file data
    int[] bitsR = readFile(name, 1);
    // checks if transmission file and received file are same size 
    if (bitsR.length != bitsT.length) {
      System.out.println("Files are not the same size!");
      return;
    }
    int kR = getKBits(bitsR);
    int[] checkLocsR = getCheckLoc(kR);
    int[] checkValuesR = getCheckValues(bitsR, checkLocsR);

    // comparing the two and getting syndrome bits
    getSynBit(checkValuesT, checkValuesR);

  }

  public static void main(String[] args) {
    printT();
    testFile("receivefile1.bin");
    testFile("receivefile2.bin");
    testFile("receivefile3.bin");
    testFile("receivefile4.bin");
  }
}
