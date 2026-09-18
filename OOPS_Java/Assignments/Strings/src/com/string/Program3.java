//3. Write a Java program to check whether a given string ends with
//   the contents of another string.


package com.string;

public class Program3  {
    public static void main(String[] args) {

        String s1 = "Python Exercises";
        String s2 = "se";

        System.out.println("\"" + s1 + "\" ends with \"" + s2 + "\"?" + s1.endsWith(s2));

        s1 = "Python Exercise";

        System.out.println("\"" + s1 + "\" ends with \"" + s2 + "\"? "+ s1.endsWith(s2));
    }
}
