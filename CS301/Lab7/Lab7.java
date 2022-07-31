// Aidan Hopper
// 11/22/2021
// Lab 7

import java.io.*;
import java.util.*;

public class Lab7
{

    /**
     *  Problem 1: Determine if two given binary search trees store the same numbers.
     */
    private static boolean problem1(Node t1, Node t2)
    {   
        // getting in order arrays of values
        int[] arr1 = getInOrder(t1);
        int[] arr2 = getInOrder(t2);
        // checks if arrays are same length then 
        // iterates through them checking values
        // and returns true if all values are the
        // same
        if (arr1.length != arr2.length) return false;
        for (int i = 0; i < arr1.length; i++)
          if (arr1[i] != arr2[i]) return false;
        return true;
    }

    /**
     *  Problem 2: Determine the sum of all node's keys between min and max (inclusive).
     */
    private static int problem2(Node root, int min, int max)
    {
        // if at bottom of tree return 0
        // base case
        if (root == null) return 0;
        // recursive step
        int sum = problem2(root.left, min, max) + problem2(root.right, min, max);
        // if sum is within bounds then add to sum
        if (root.key >= min && root.key <= max) 
          sum += root.key;
        // return the sum
        return sum;
    }

    // ---------------------------------------------------------------------
    // Do not change any of the code below!

    private static class Node
    {
        public Node left = null;
        public Node right = null;

        public int key;

        public Node(int key)
        {
            this.key = key;
        }
    }

    private static void insert(Node root, int key)
    {
        if (root == null)
        {
            root = new Node(key);
            return;
        }

        for (Node node = root;;)
        {
            if (key < node.key)
            {
                if (node.left == null)
                {
                    node.left = new Node(key);
                }

                node = node.left;
            }
            else if (key > node.key)
            {
                if (node.right == null)
                {
                    node.right = new Node(key);
                }

                node = node.right;
            }
            else // key = node.key
            {
                // Nothing to do, because no value to update.
                break;
            }
        }
    }

    private static int[] getInOrder(Node root)
    {
        if (root == null) return new int[] { };

        Stack<Node> stack = new Stack<Node>();
        ArrayList<Integer> orderList = new ArrayList<Integer>();

        for (Node node = root;;)
        {
            if (node == null)
            {
                if (stack.empty()) break;

                node = stack.pop();
                orderList.add(node.key);
                node = node.right;
            }
            else
            {
                stack.push(node);
                node = node.left;
            }
        }

        int[] order = new int[orderList.size()];
        for (int i = 0; i < order.length; i++)
        {
            order[i] = orderList.get(i);
        }

        return order;
    }

    private static int[] getPreOrder(Node root)
    {
        if (root == null) return new int[] { };

        Stack<Node> stack = new Stack<Node>();
        ArrayList<Integer> orderList = new ArrayList<Integer>();

        for (Node node = root;;)
        {
            if (node == null)
            {
                if (stack.empty()) break;

                node = stack.pop();
                node = node.right;
            }
            else
            {
                orderList.add(node.key);
                stack.push(node);
                node = node.left;
            }
        }

        int[] order = new int[orderList.size()];
        for (int i = 0; i < order.length; i++)
        {
            order[i] = orderList.get(i);
        }

        return order;
    }

    private static int[] getPostOrder(Node root)
    {
        if (root == null) return new int[] { };

        Stack<Node> stack = new Stack<Node>();
        Stack<Integer> stackCtr = new Stack<Integer>();
        ArrayList<Integer> orderList = new ArrayList<Integer>();

        stack.push(root);
        stackCtr.push(0);

        while (!stack.empty())
        {
            int ctr = stackCtr.pop();
            Node node = stack.peek();

            if (ctr == 0)
            {
                // First visit.
                stackCtr.push(1);

                if (node.left != null)
                {
                    stack.push(node.left);
                    stackCtr.push(0);
                }
            }
            else if (ctr == 1)
            {
                // Second visit.
                // Left subtree done.
                stackCtr.push(2);

                if (node.right != null)
                {
                    stack.push(node.right);
                    stackCtr.push(0);
                }
            }
            else // ctr >= 2
            {
                // Third visit.
                // Right subtree done.
                stack.pop();
                orderList.add(node.key);
            }
        }

        int[] order = new int[orderList.size()];
        for (int i = 0; i < order.length; i++)
        {
            order[i] = orderList.get(i);
        }

        return order;
    }

    // ---------------------------------------------------------------------

    private static final int LabNo = 7;
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
        int[] tree1 = testCase[0];
        int[] tree2 = testCase[1];

        boolean solution = testCase[2][0] == 1;

        Node root1 = new Node(tree1[0]);
        Node root2 = new Node(tree2[0]);

        for (int i = 1; i < tree1.length; i++)
        {
            insert(root1, tree1[i]);
            insert(root2, tree2[i]);
        }

        return solution == problem1(root1, root2);
    }

    private static boolean testProblem2(int[][] testCase)
    {
        int[] tree = testCase[0];
        int[] range = testCase[1];
        int solution = testCase[2][0];

        Node root = new Node(tree[0]);

        for (int i = 1; i < tree.length; i++)
        {
            insert(root, tree[i]);
        }

        int answer = problem2(root, range[0], range[1]);

        return answer == solution;
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

                if (prob == 1)
                {
                    System.out.println("  tree 1: " + Arrays.toString(testCase[0]));
                    System.out.println("  tree 2: " + Arrays.toString(testCase[1]));
                }
                else
                {
                    System.out.println("    tree: " + Arrays.toString(testCase[0]));
                    System.out.println("   range: " + Arrays.toString(testCase[1]));
                }
                passedAll = false;
                break;
            }
        }

        if (passedAll)
        {
            System.out.println("All test passed.");
        }

    }

    private static void shuffle(int[] arr)
    {
        for (int i = 0; i < arr.length; i++)
        {
            int rndInd = rng.nextInt(arr.length - i) + i;

            int tmp = arr[i];
            arr[i] = arr[rndInd];
            arr[rndInd] = tmp;
        }
    }

    private static int[] getRandomNumbers(int size)
    {
        int maxSize = size * 10;

        int[] integers = new int[maxSize];
        for (int i = 0; i < maxSize; i++)
        {
            integers[i] = i;
        }

        shuffle(integers);

        return Arrays.copyOf(integers, size);
    }

    private static int[][] createProblem1(int max)
    {
        int maxSize = max < 250 ? max : 250;
        int size = rng.nextInt(maxSize) + 5;

        int equal = rng.nextInt(2);

        int[] tree1 = getRandomNumbers(size);
        int[] tree2 = tree1.clone();

        if (equal == 0)
        {
            int ind = rng.nextInt(tree1.length);
            tree1[ind]++;
        }

        return new int[][]
        {
            tree1,
            tree2,
            new int[] { equal }
        };
    }

    private static int[][] createProblem2(int max)
    {
        int maxSize = max < 250 ? max : 250;
        int size = rng.nextInt(maxSize) + 5;

        int[] keys = getRandomNumbers(2 * size);

        int minKey = keys[rng.nextInt(2 * size)];
        int maxKey = keys[rng.nextInt(2 * size)];

        shuffle(keys);

        int[] tree = Arrays.copyOf(keys, size);

        int sum = 0;

        for (int i = 0; i < tree.length; i++)
        {
            if (tree[i] >= minKey && tree[i] <= maxKey)
            {
                sum += tree[i];
            }
        }

        return new int[][]
        {
            tree,
            new int[] { minKey, maxKey },
            new int[] { sum }
        };
    }

}
