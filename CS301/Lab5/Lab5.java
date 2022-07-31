// Aidan Hopper
// 11/09/2021
// Lab5

import java.io.*;
import java.util.*;

public class Lab5
{

    /**
     *  Problem 1: Determine the number of nodes based on their number of children.
     */
    private static int[] problem1(Node root)
    {
        // checks if root is null
        if (root == null)
          return new int[] {
            0, // nodes with 0 children
            0, // nodes with 1 child
            0  // nodes with 2 children
        };
        
        // if both sides of tree have nodes then gets
        // arrays for each side then combines them
        // then increments index 0 before returning array
        else if (root.right != null && root.left != null){
          int[] arrL = problem1(root.left);
          int[] arrR = problem1(root.right);
          for (int i = 0; i < 3; i++)
            arrL[i] += arrR[i];
          arrL[2]++;
          return arrL;
        }
        
        // if right side is only node then gets number nodes
        // on right then returns then increments index 1 by 1
        else if (root.right != null){
          int[] arr = problem1(root.right);
          arr[1]++;
          return arr;
        }
        
        // if left side is only node then gets number nodes
        // on right then returns then increments index 1 by 1
        else if (root.left != null) {
          int[] arr = problem1(root.left);
          arr[1]++;
          return arr;
        }
        
        // if root is leaf then returns an array with index 0
        // as 1 which is the base case
        return new int[] {
            1, // nodes with 0 children
            0, // nodes with 1 child
            0  // nodes with 2 children
        };
    }

    /**
     *  Problem 2: Determine the maximum distance from the root to a leaf.
     */
    private static int problem2(Node root)
    {
        // returns the max height value of both sides of tree
        if (root.left != null && root.right != null) {
          int leftH = problem2(root.left);
          int rightH = problem2(root.right);
          return Math.max(leftH, rightH) + 1;
        }
        
        // returns right tree height
        else if (root.right != null)
          return problem2(root.right) + 1;
        
        // returns left tree height
        else if (root.left != null)
          return problem2(root.left) + 1;
        
        // base case
        return 0;
    }

    // ---------------------------------------------------------------------
    // Do not change any of the code below!

    static class Node
    {
        public int value;
        public Node left;
        public Node right;
    }

    private static final int LabNo = 5;
    private static final String classNum = "CS 301";

    private static final Random rng = new Random(654321);

    public static void main(String args[])
    {
        System.out.println(classNum + " -- Lab " + LabNo);

        testProblems(1);
        testProblems(2);
    }

    private static boolean testProblem1(int[][] testCase)
    {
        int[] left = testCase[0];
        int[] right = testCase[1];
        int[] solution = testCase[2];
        
        
        Node root = makeTree(left, right);

        int[] answer = problem1(root);

        if (answer == null || answer.length != solution.length) return false;

        for (int i = 0; i < answer.length; i++)
        {
            if (answer[i] != solution[i]) return false;
        }

        return true;
    }

    private static boolean testProblem2(int[][] testCase)
    {
        int[] left = testCase[0];
        int[] right = testCase[1];
        int solution = testCase[2][0];

        Node root = makeTree(left, right);

        int answer = problem2(root);

        return solution == answer;
    }

    private static void testProblems(int prob)
    {
        int noOfLines = 10000;

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
                        testCase = createProblem1(i);
                        passed = testProblem1(testCase);
                        break;

                    case 2:
                        testCase = createProblem2(i);
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

                System.out.println("    left: " + Arrays.toString(testCase[0]));
                System.out.println("   right: " + Arrays.toString(testCase[1]));

                passedAll = false;
                break;
            }
        }

        if (passedAll)
        {
            System.out.println("All test passed.");
        }

    }

    private static Node makeTree(int[] left, int[] right)
    {
        int size = left.length;
        Node[] nodes = new Node[size];

        for (int i = 0; i < size; i++)
        {
            nodes[i] = new Node();
        }

        for (int i = 0; i < size; i++)
        {
            if (left[i] >=0) 
               nodes[i].left = nodes[left[i]];
            if (right[i] >=0)
                nodes[i].right = nodes[right[i]];
        }

        return nodes[0];
    }

    private static int[][] makeRndBinaryTree(int size)
    {
        int[] left = new int[size];
        int[] right = new int[size];
        int[] childCount = new int[size];
        int[] values = new int[size];

        ArrayList<Integer> available = new ArrayList<Integer>();

        available.add(0);
        left[0] = -1;
        right[0] = -1;
        values[0] = rng.nextInt(size * size);

        for (int i = 1; i < size; i++)
        {
            int parInd = rng.nextInt(available.size());
            int par = available.get(parInd);

            if (childCount[par] == 0)
            {
                if (rng.nextInt(2) == 0)
                {
                    left[par] = i;
                }
                else
                {
                    right[par] = i;
                }

                childCount[par]++;
            }
            else // childCount[par] == 0
            {
                if (left[par] < 0)
                {
                    left[par] = i;
                }
                else
                {
                    right[par] = i;
                }
                childCount[par]++;

                available.set(parInd, available.get(available.size() - 1));
                available.remove(available.size() - 1);
            }

            left[i] = -1;
            right[i] = -1;

            available.add(i);
        }

        return new int[][] { left, right, childCount };

    }

    private static int[][] createProblem1(int max)
    {
        int maxSize = max < 250 ? max : 250;
        int size = rng.nextInt(maxSize) + 1;

        int[][] rndTree = makeRndBinaryTree(size);
        int[] answer = { 0, 0, 0 };

        for (int i = 0; i < rndTree[2].length; i++)
        {
            answer[rndTree[2][i]]++;
        }

        return new int[][] { rndTree[0], rndTree[1], answer };
    }

    private static int[][] createProblem2(int max)
    {
        int maxSize = max < 250 ? max : 250;
        int size = rng.nextInt(maxSize) + 1;

        int[][] rndTree = makeRndBinaryTree(size);
        int[] dist = new int[size];
        int maxDis = 0;

        for (int i = 0; i < size; i++)
        {
            int left = rndTree[0][i];
            int right = rndTree[1][i];
            int chCnt = rndTree[2][i];

            if (left >= 0) dist[left] = dist[i] + 1;
            if (right >= 0) dist[right] = dist[i] + 1;

            if (chCnt == 0)
            {
                maxDis = Math.max(maxDis, dist[i]);
            }
        }

        return new int[][] { rndTree[0], rndTree[1], new int[] { maxDis } };
    }

}
