import java.io.*;
import java.util.*;

public class Lab1
{

    /**
     *  Problem 1: Finds the largest number in a specific range of the given array.
     */
    private static int problem1(int[] arr, int i, int j)
    {
	// base case
	if (i >= j) return arr[i];
	// returns range starting on whichever number is largest 
	if (arr[i] >= arr[j]) return problem1(arr, i, j - 1);
	return problem1(arr, i + 1, j);
    }

    /**
     *  Problem 2: Reverse a specific range in a given array.
     */
    private static void problem2(int[] arr, int i, int j)
    {
	// base case
	if (i >= j) return;
	// swaps specified incicies then moves range inwards
	swap(arr, i, j);
	problem2(arr, i + 1, j - 1);
    }

    /**
     *  Swap the items at index i and j of the given array.
     */
    private static void swap(int[] arr, int i, int j)
    {
	int temp = arr[j];
	arr[j] = arr[i];
	arr[i] = temp;
    }

    // ---------------------------------------------------------------------
    // Do not change any of the code below!

    private static final int LabNo = 1;

    private static final Random rng = new Random(30118);

    public static void main(String args[])
    {
        System.out.println("CS 301 -- Lab " + LabNo);

        testProblems(1);
        testProblems(2);
    }

    private static boolean testProblem1(int[][] testCase)
    {
        int[] arr = testCase[0].clone();
        int i = testCase[1][0];
        int j = testCase[1][1];

        int[] arr2 = arr.clone();
        Arrays.sort(arr2, i, j + 1);

        int solution = arr2[j];
        int result = problem1(arr, i, j);

        return result == solution;
    }

    private static boolean testProblem2(int[][] testCase)
    {
        int[] arr = testCase[0].clone();
        int i = testCase[1][0];
        int j = testCase[1][1];

        int[] arr2 = arr.clone();

        problem2(arr, i, j);

        for (int ind = 0; ind <= j - i; ind++)
        {
            if (arr[i + ind] != arr2[j - ind]) return false;
        }

        return true;
    }

    private static void testProblems(int prob)
    {
        int noOfLines = 1000;

        System.out.println("-- -- -- -- --");
        System.out.println(noOfLines + " test cases for problem " + prob + ".");

        boolean passedAll = true;

        for (int i = 1; i <= noOfLines; i++)
        {
            boolean passed = false;
            boolean exce = false;
            int[][] testCase = createProblem(5 * i);

            try
            {
                switch (prob)
                {
                    case 1:
                        passed = testProblem1(testCase);
                        break;

                    case 2:
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

    private static int[][] createProblem(int max)
    {
        int maxSize = max < 500 ? max : 500;

        int size = rng.nextInt(maxSize) + 1;
        int[] numbers = getRandomNumbers(size);

        int j = rng.nextInt(size);
        int i = rng.nextInt(j + 1);

        return new int[][] { numbers, new int[] { i, j } };
    }

    private static int[] getRandomNumbers(int size)
    {
        int maxSize = size * 10;

        int[] integers = new int[maxSize];
        for (int i = 0; i < maxSize; i++)
        {
            integers[i] = i;
        }

        // Shuffle
        for (int i = 0; i < maxSize; i++)
        {
            int rndInd = rng.nextInt(maxSize - i) + i;

            int tmp = integers[i];
            integers[i] = integers[rndInd];
            integers[rndInd] = tmp;
        }

        return Arrays.copyOf(integers, size);
    }
}
