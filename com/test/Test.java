package com.test;

import com.task.Task;

public class Test {
	static {
		System.loadLibrary("ngdump");
	}
	
	public static void main(String args[]) {
		Test t = new Test();
		t.hi();
		Task tsk = t.dummyTask();

		System.out.println(tsk.getDesc());
	}

	private native void hi();
	private native Task dummyTask();
}
