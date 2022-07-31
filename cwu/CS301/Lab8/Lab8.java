// Aidan Hopper
// 12/03/2021
// Lab 8

import java.io.*;
import java.util.*;

public class Lab8
{

    /**
     *  Problem 1: Check if string of parentheces is valid.
     */
    private static boolean problem1(char[] str)
    {
      // creating stack
      Stack<Character> stack = new Stack<>();
      // iterates through string
      for (int i = 0; i < str.length; i++) {
        // if opening push closing counterpart to stack
        if (str[i] == '(') stack.push(')');
        else if (str[i] == '{') stack.push('}');
        else if (str[i] == '[') stack.push(']');
        // if closing pop the stack and check if top of
        // stack is equal to current index
        else {
          char top = stack.pop();
          if (top != str[i]) return false;
        }
      }
      // if loop completes iterations then return true
      return true;
    }

    /**
     *  Problem 2: Check if two "strings" are equivialent after applying backspaces.
     */
    private static boolean problem2(char[] strS, char[] strT)
    {
      // creates stack for strS
      Stack<Character> stackS = new Stack<>();
      char c;
      int hcount = 0;
      // loops through array
      for (int i = 0; i < strS.length; i++) {
        c = strS[i];
        // if not pound then pop stack hcount times
        // and push character to stack
        if (c != '#') {
          for (int k = 0; k < hcount; k++)
            if (!stackS.empty()) stackS.pop();
          stackS.push(c);
          hcount = 0;
        }
        // if pound sign increment hcount
        else if (c == '#') hcount++;
      }
      
      hcount = 0;
      Stack<Character> stackT = new Stack<>();
      for (int i = 0; i < strT.length; i++) {
        c = strT[i];
        if (c != '#') {
          for (int k = 0; k < hcount; k++)
            if (!stackT.empty()) stackT.pop();
          stackT.push(c);
          hcount = 0;
        }
        else if (c == '#') hcount++;
      }

      char t;
      char s;
      if (stackS.size() != stackT.size()) return false;
      // loops through stacks until empty 
      while (!stackS.empty()) {
        // gets top of stack and checks if equal
        t = stackT.pop();
        s = stackS.pop();
        // if not equal return false
        if (s != t) return false;
      }
      // returns true if both stacks are empty without returning false
      return true;
    }

    // ---------------------------------------------------------------------
    // Do not change any of the code below!

    private static final int LabNo = 8;
    private static final String classNum = "CS 301";

    private static final Random rng = new Random(654321);

    public static void main(String args[])
    {
        System.out.println(classNum + " -- Lab " + LabNo);

        testProblems(1);
        testProblems(2);
    }

    private static boolean testProblem1(char[][] testCase)
    {
        char[] str = testCase[0];
        boolean isValid = testCase[1][0] == 't';

        boolean answer = problem1(str);

        return isValid == answer;
    }

    private static boolean testProblem2(char[][] testCase)
    {
        char[] str1 = testCase[0];
        char[] str2 = testCase[1];
        boolean isEqual = testCase[2][0] == 't';

        boolean answer = problem2(str1, str2);

        return isEqual == answer;
    }

    private static void testProblems(int prob)
    {
        int noOfLines = 1000000;

        System.out.println("-- -- -- -- --");
        System.out.println(noOfLines + " test cases for problem " + prob + ".");

        boolean passedAll = true;

        for (int i = 1; i <= noOfLines; i++)
        {
            boolean passed = false;
            boolean exce = false;
            char[][] testCase = null;

//             try
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
//             catch (Exception ex)
//             {
//                 passed = false;
//                 exce = true;
//             }

            if (!passed)
            {
                System.out.println("Test " + i + " failed!" + (exce ? " (Exception)" : ""));

                switch (prob)
                {
                    case 1:
                        System.out.println("     infix: " + Arrays.toString(testCase[0]));
                        System.out.println("   postfix: " + Arrays.toString(testCase[1]));
                        break;

                    case 2:
                        System.out.println("    str1: " + Arrays.toString(testCase[0]));
                        System.out.println("    str2: " + Arrays.toString(testCase[1]));
                        System.out.println("   equal: " + Arrays.toString(testCase[2]));
                        break;
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

    static String openParentheses = "({[";
    static String closeParentheses = ")}]";
    static String letters = "abcdefghijklmnopqrstuvwxyz";

    private static char[][] createProblem1(int max)
    {
        int maxSize = max < 50 ? max : 50;
        int size = rng.nextInt(maxSize) + 1;

        boolean broken = (rng.nextInt(10) == 0);

        int[] values = new int[size];
        ArrayList<ArrayList<Integer>> children = new ArrayList<ArrayList<Integer>>(size);

        for (int i = 0; i < size; i++)
        {
            children.add(new ArrayList<Integer>());
        }

        for (int i = 1; i < size; i++)
        {
            int par = rng.nextInt(i);
            children.get(par).add(i);
            values[i] = rng.nextInt(openParentheses.length());
        }

        if (broken)
        {
            int ind = rng.nextInt(size);
            values[ind] -= 3;
        }

        char[] str = new char[2 * size];
        buildString(str, 0, values, children, 0);

        return new char[][] { str, { !broken ? 't' : 'f' } };
    }

    private static int buildString(char[] str, int charInd, int[] values, ArrayList<ArrayList<Integer>> children, int id)
    {
        int val = values[id];
        ArrayList<Integer> child = children.get(id);

        str[charInd] = openParentheses.charAt((val + 3) % 3); // Fix possible negative val.
        charInd++;

        for (int i = 0; i < child.size(); i++)
        {
            charInd = buildString(str, charInd, values, children, child.get(i));
        }

        char closePar;

        if (val < 0)
        {
            int shift = rng.nextInt(2) + 1;
            closePar = closeParentheses.charAt((val + 3 + shift) % 3);
        }
        else
        {
            closePar = closeParentheses.charAt(val);
        }

        str[charInd] = closePar;
        charInd++;

        return charInd;
    }

    private static char[][] createProblem2(int max)
    {
        int maxSize = max < 50 ? max : 50;
        int size = rng.nextInt(maxSize) + 1;

        StringBuilder[] fullStr = { new StringBuilder(), new StringBuilder() };
        StringBuilder[] cleanStr = { new StringBuilder(), new StringBuilder() };

        boolean forceEqual = rng.nextInt(100) < 45;

        for (int i = 0; i < size; i++)
        {
            char rndChar1 = letters.charAt(rng.nextInt(letters.length()));
            char rndChar2 = letters.charAt(rng.nextInt(letters.length()));

            if (forceEqual) rndChar2 = rndChar1;

            cleanStr[0].append(rndChar1);
            cleanStr[1].append(rndChar2);
        }


        for (int ind = 0; ind < fullStr.length; ind++)
        {
            int bsCtr = 0;
            for (int i = 0; i < size;)
            {
                if (rng.nextInt(100) < 25)
                {
                    // Add dummy character
                    fullStr[ind].append(letters.charAt(rng.nextInt(letters.length())));
                    bsCtr++;
                    continue;
                }

                if (bsCtr > 0)
                {
                    fullStr[ind].append('#');
                    bsCtr--;
                    continue;
                }

                // Add real character
                fullStr[ind].append(cleanStr[ind].charAt(i));
                i++;
            }
        }

        // Check if equal.
        boolean isEqual = true;

        for (int i = 0; i < size && !forceEqual && isEqual; i++)
        {
            isEqual = isEqual && (cleanStr[0].charAt(i) == cleanStr[1].charAt(i));
        }

        return new char[][]
            {
                fullStr[0].toString().toCharArray(),
                fullStr[1].toString().toCharArray(),
                { isEqual ? 't' : 'f' }
            };
    }

}
