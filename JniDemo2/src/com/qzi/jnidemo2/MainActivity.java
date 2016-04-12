package com.qzi.jnidemo2;

import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends ActionBarActivity {

	private TextView textView,showView;
    private EditText editText_a,editText_b;
    private Utils utils;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = (TextView) findViewById(R.id.text);
        editText_a = (EditText) findViewById(R.id.edit_a);
        editText_b = (EditText) findViewById(R.id.edit_b);
        showView = (TextView) findViewById(R.id.show);
        utils = new Utils();
        textView.setText(utils.GetText()+utils.add(10,20));
    }

    public void myclick(View view){
        try{
            int num_a = Integer.parseInt(editText_a.getText().toString().trim());
            int num_b = Integer.parseInt(editText_b.getText().toString().trim());
            showView.setText("和为： "+utils.add(num_a,num_b));
        }catch (NumberFormatException e){
            e.printStackTrace();
            Toast.makeText(this,"请输入数字",Toast.LENGTH_SHORT).show();
        }
    }
	static{
		System.loadLibrary("Utils");
		System.loadLibrary("hello-jni");
	}
}
