// Aidan Hopper
// 10/6/2021
// CS301 Lab2

import java.io.*;
import java.util.*;

public class Lab2
{

    /**
     *  Problem 1: Determines if there are two consequtive equal elements in a specific range of the given array.
     */
    private static boolean problem1(int[] arr, int i, int j)
    {
      if (i == j) return false;
      if (arr[i] == arr[i + 1]) return true;
      if (i+1 >= j) return false;
      return problem1(arr, i+1, j);
    }

    /**
     *  Problem 2: Determines if a specific range in a given array is a plindrome.
     */
    private static boolean problem2(int[] arr, int i, int j)
    {
        if (i >= j) return true;
        if (arr[i] == arr[j]) return problem2(arr, i+1, j-1);
        return false;
    }

    // ---------------------------------------------------------------------
    // Do not change any of the code below!

    private static final int LabNo = 2;

    private static final Random rng = new Random(123456);

    public static void main(String args[])
    {
        System.out.println("CS 301 -- Lab " + LabNo);

        testProblems(1);
        testProblems(2);
    }

    private static boolean testProblem1(int[][] testCase)
    {
        int[] arr = testCase[0];
        int i = testCase[1][0];
        int j = testCase[1][1];

        boolean solution = false;

        for (int ind = i; ind < j; ind++)
        {
            if (arr[ind] == arr[ind + 1])
            {
                solution = true;
                break;
            }
        }

        boolean result = problem1(arr, i, j);

        return result == solution;
    }

    private static boolean testProblem2(int[][] testCase)
    {
        int[] arr = testCase[0].clone();
        int i = testCase[1][0];
        int j = testCase[1][1];

        boolean solution = true;

        for (int ind = 0; ind <= (j - i) / 2; ind++)
        {
            if (arr[i + ind] != arr[j - ind])
            {
                solution = false;
                break;
            }
        }

        boolean result = problem2(arr, i, j);

        return result == solution;
    }

    private static void testProblems(int prob)
    {
        int noOfLines = 100000;

        System.out.println("-- -- -- -- --");
        System.out.println(noOfLines + " test cases for problem " + prob + ".");

        boolean passedAll = true;

        for (int i = 1; i <= noOfLines; i++)
        {
            boolean passed = false;
            boolean exce = false;
            int[][] testCase = null;

            try
            {
                switch (prob)
                {
                    case 1:
                        testCase = createProblem1(5 * i);
                        passed = testProblem1(testCase);
                        break;

                    case 2:
                        testCase = createProblem2(5 * i);
                        passed = testProblem2(testCase);
                        break;
                }
            }
            catch (Exception ex)
            {
                passed = false;
                exce = true;
            }

            if (!passed)
            {
                System.out.println("Test " + i + " failed!" + (exce ? " (Exception)" : ""));
                System.out.println("    arr: " + Arrays.toString(testCase[0]));
                System.out.println("    i = " + testCase[1][0] + "  |  j = " + testCase[1][1]);
                passedAll = false;
                break;
            }
        }

        if (passedAll)
        {
            System.out.println("All test passed.");
        }

    }

    private static int[][] createProblem1(int max)
    {
        int maxSize = max < 500 ? max : 500;

        int size = rng.nextInt(maxSize) + 1;
        int[] numbers = getRandomNumbers(size);

        int j = rng.nextInt(size);
        int i = rng.nextInt(j + 1);

        // Force double somewhere
        if (rng.nextInt(2) == 0 && size > 1)
        {
            int ind = rng.nextInt(size - 1);
            numbers[ind + 1] = numbers[ind];
        }

        return new int[][] { numbers, new int[] { i, j } };
    }

    private static int[][] createProblem2(int max)
    {
        int maxSize = max < 500 ? max : 500;

        int size = rng.nextInt(maxSize) + 1;
        int[] numbers = getRandomNumbers(size);

        int j = rng.nextInt(size);
        int i = rng.nextInt(j + 1);

        // Force palindrome
        if (rng.nextInt(2) == 0 && j > i)
        {
            for (int ind = 0; ind <= (j - i) / 2; ind++)
            {
                numbers[i + ind] = numbers[j - ind];
            }
        }

        return new int[][] { numbers, new int[] { i, j } };
    }

    private static int[] getRandomNumbers(int size)
    {
        int maxSize = size * 10;

        int[] integers = new int[maxSize];
        for (int i = 0; i < maxSize; i++)
        {
            integers[i] = rng.nextInt(maxSize);
        }

//         // Shuffle
//         for (int i = 0; i < maxSize; i++)
//         {
//             int rndInd = rng.nextInt(maxSize - i) + i;
// 
//             int tmp = integers[i];
//             integers[i] = integers[rndInd];
//             integers[rndInd] = tmp;
//         }

        return Arrays.copyOf(integers, size);
    }
}
