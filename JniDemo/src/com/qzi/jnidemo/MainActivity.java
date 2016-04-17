package com.qzi.jnidemo;

import java.io.File;

import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {

	private TextView textView,showView;
	private EditText editText,editText2,calText;
	private HelloJni helloJni;
	private FileUtils fileUtils;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		fileUtils = new FileUtils();
		helloJni = new HelloJni();
		textView = (TextView) findViewById(R.id.text);
		editText = (EditText) findViewById(R.id.edit01);
		editText2 = (EditText) findViewById(R.id.edit02);
		calText = (EditText) findViewById(R.id.calculate);
		showView = (TextView) findViewById(R.id.show);
		textView.setText(helloJni.stringFromJNI());
	}
	
	public void myclick(View view){
		try{
			int num = Integer.parseInt(editText.getText().toString());
			int num2 = Integer.parseInt(editText2.getText().toString());
			showView.setText(String.valueOf(helloJni.calculate(calText.getText().toString().trim(),num, num2)));
			String filePath = Environment.getExternalStorageDirectory()+File.separator+"wunding.md";
			String copyPath = Environment.getExternalStorageDirectory()+File.separator+"wunding_qzi";
//			fileUtils.createFile(filePath);
			fileUtils.move(filePath, copyPath);
		}catch(NumberFormatException e){
			Toast.makeText(this, "please input math", Toast.LENGTH_SHORT).show();
			e.printStackTrace();
		}
	}
	
	static{
		System.loadLibrary("hello-jni");
	}
}
