package com.test;

public class Test {
	static {
		System.loadLibrary("ngdump");
	}
	
	public static void main(String args[]) {
		Test t = new Test();
		t.hi();
	}

	private native void hi();
}
