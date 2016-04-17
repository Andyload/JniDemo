package com.qzi.jnidemo;

public class HelloJni {
	
	public HelloJni(){
		
		nativeConstructor();
	}
	@Override
	protected void finalize() throws Throwable {
		
		nativeDestructor();
	}
	public native void nativeConstructor();
	
	public native void nativeDestructor();
	
	private int mJniObject = 0;
	
	public native String stringFromJNI();
	
	public native int calculate(String calculate,int math,int math2);
}
