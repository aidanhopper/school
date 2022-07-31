// Aidan Hopper
// 02/21/2022
// Lab 4

import java.io.*;
import java.util.*;

public class Lab4
{
    /**
     *  Problem: Sort multi-digit integers (with n total digits) in O(n) time.
     *  (Technically, it is O(n * b) time. However, since our base b = 128 is constant, it is O(n).)
     */
    private static void problem(byte[][] arr)
    { 

      int base = 128;

      // create array of lengths
      int[] lengths = new int[base];
      int index;
      for (int row = 0; row < arr.length; row++) {
	index = arr[row].length;
	lengths[index]++;
      }
      
      // create 3d array to store arrays at length indicies 
      byte[][][] lenSortedArrs = new byte[base][base][];
      byte[] indicies = new byte[base];
      for (int i = 0; i < arr.length; i++) {
	int len = arr[i].length;
	lenSortedArrs[len][indicies[len]++] = arr[i];
      }

      // next step is to use counting sort to sort each length matrix in lenSortedArrs
      // by the most significant digit
      byte[][][][] lenSortedArrSortInfo = new byte[base][base][base][];
      for (int len = 0; len < base; len++) {
	for (int i = 0; i < base; i++) {
	  byte[] array = lenSortedArrs[len][i];
	  if (array == null) break;
	  for (int n = 0; n < base; n++) {
	    lenSortedArrSortInfo[len][array[array.length - 1]][n] = array;
	    break;
	  }
	}
      }

      // do count sort on lenSortedArrSortInfo again
      int r = 0;
      for (int len = 0; len < base; len++) {
	for (int num = 0; num < base; num++) {
	  byte[] array = lenSortedArrSortInfo[len][num][0];
	  if (array != null) {
	    arr[r++] = array;
	  }
	}
      }

      // at length 47 of test 51 the number 73 repeats twice for the last index causing algo to break
      // solution is to implement some type of collision handling
    }

    // ---------------------------------------------------------------------
    // Do not change any of the code below!

    private static final int LabNo = 4;
    private static final Random rng = new Random(654321);

    private static boolean testProblem(byte[][] testCase)
    {
        byte[][] numbersCopy = new byte[testCase.length][];

        // Create copy.
        for (int i = 0; i < testCase.length; i++)
        {
            numbersCopy[i] = testCase[i].clone();
        }

        // Sort
        problem(testCase);
        Arrays.sort(numbersCopy, new numberComparator());

        // Compare if both equal
        if (testCase.length != numbersCopy.length)
        {
            return false;
        }

        for (int i = 0; i < testCase.length; i++)
        {
            if (testCase[i].length != numbersCopy[i].length)
            {
                return false;
            }

            for (int j = 0; j < testCase[i].length; j++)
            {
                if (testCase[i][j] != numbersCopy[i][j])
                {
                    return false;
                }
            }
        }

        return true;
    }

    // Very bad way of sorting.
    private static class numberComparator implements Comparator<byte[]>
    {
        @Override
        public int compare(byte[] n1, byte[] n2)
        {
            // Ensure equal length
            if (n1.length < n2.length)
            {
                byte[] tmp = new byte[n2.length];
                for (int i = 0; i < n1.length; i++)
                {
                    tmp[i] = n1[i];
                }
                n1 = tmp;
            }

            if (n1.length > n2.length)
            {
                byte[] tmp = new byte[n1.length];
                for (int i = 0; i < n2.length; i++)
                {
                    tmp[i] = n2[i];
                }
                n2 = tmp;
            }

            // Compare digit by digit.
            for (int i = n1.length - 1; i >=0; i--)
            {
                if (n1[i] < n2[i]) return -1;
                if (n1[i] > n2[i]) return 1;
            }

            return 0;
        }
    }

    public static void main(String args[])
    {
        System.out.println("CS 302 -- Lab " + LabNo);
        testProblems();
    }

    private static void testProblems()
    {
        int noOfLines = 10000;

        System.out.println("-- -- -- -- --");
        System.out.println(noOfLines + " test cases.");

        boolean passedAll = true;

        for (int i = 1; i <= noOfLines; i++)
        {
            byte[][] testCase =  createTestCase(i);

            boolean passed = false;
            boolean exce = false;

            try
            {
                passed = testProblem(testCase);
            }
            catch (Exception ex)
            {
		System.out.println(ex);
                passed = false;
                exce = true;
            }

            if (!passed)
            {
                System.out.println("Test " + i + " failed!" + (exce ? " (Exception)" : ""));
                passedAll = false;

                break;
            }
        }

        if (passedAll)
        {
            System.out.println("All test passed.");
        }

    }

    private static byte[][] createTestCase(int testNo)
    {
        int maxSize = Math.min(100, testNo) + 5;
        int size = rng.nextInt(maxSize) + 5;

        byte[][] numbers = new byte[size][];

        for (int i = 0; i < size; i++)
        {
            int digits = rng.nextInt(maxSize) + 1;
            numbers[i] = new byte[digits];

            for (int j = 0; j < digits - 1; j++)
            {
                numbers[i][j] = (byte)rng.nextInt(128);
            }

            // Ensures that the most significant digit is not 0.
            numbers[i][digits - 1] = (byte)(rng.nextInt(127) + 1);
        }

        return numbers;
    }

}
