package com.string;

public class Replace_Substring  {
    public static void main(String[] args) {

        String str = "The quick brown fox jumps over the lazy dog.";
        System.out.println("Original string: " + str);
        
        String newString = str.replaceAll("fox", "cat");
        System.out.println("New String: " + newString);
    }
}