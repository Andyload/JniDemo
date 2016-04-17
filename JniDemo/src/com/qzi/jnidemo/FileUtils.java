package com.qzi.jnidemo;

public class FileUtils {
	
	public FileUtils(){
		
		nativeConstructor();
	}
	@Override
	protected void finalize() throws Throwable {
		
		nativeDestructor();
	}
	
	public native void nativeConstructor();
	
	public native void nativeDestructor();
	
	private int mJniObject = 0;
	
	public native boolean copy(String firstPath,String copyPath);
	
	public native boolean move(String firstPath,String movePath);
	
	public native boolean createFile(String fileName);
	
}
