package com.operators;

public class Assignment_Operator {

	public static void main(String[] args)
	{
		int a = 6;
		int b= 3;
		
		//operations//
		//a=b;  // now  a = b
		System.out.println(a); // assign the value from right hand side to left hand sie
		System.out.println("(a+=b) = "+(a += b)); // a = a+b=>6+3=9
		System.out.println("(a-=b) = "+(a -= b)); // a = a-b=>9-3=6
		System.out.println("(a*=b) = "+(a*= b)); // a = a*b=> 6*3=18
		System.out.println("(a/=b) = "+(a /= b)); // a = a/b=>18/3=6
		System.out.println("(a%=b) = "+(a %= b)); // a = a%b=>6%3=0
		System.out.println("(a&=b) = "+(a &= b));  // a= 
		System.out.println("(a^=b) = "+(a ^= b)); // a = a^b=>0^3=3
		System.out.println("(a<<=b) = "+(a <<= b)); // a = a << b=> 24
		System.out.println("(a>>=b) = "+(a >>= b)); // a = a>>b=>6-3

		
	}
}