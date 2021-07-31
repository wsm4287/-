package com.vogella.android.service.week14;

import androidx.appcompat.app.AppCompatActivity;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    @Override
    public boolean onTouchEvent(MotionEvent event){
        InputMethodManager imm = (InputMethodManager) getSystemService(Context.INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(getCurrentFocus().getWindowToken(),0);
        return true;
    }
    public void onClickAddDetails(View view){
        ContentValues values = new ContentValues();
        values.put(StudentsProvider.name,((EditText) findViewById(R.id.txtName)).getText().toString());
        getContentResolver().insert(StudentsProvider.CONTENT_URI,values);
        Toast.makeText(getBaseContext(),"New Record Inserted",Toast.LENGTH_LONG).show();
    }
    public void onClickDelDetails(View view){
        String[] values = {((EditText) findViewById(R.id.txtName)).getText().toString()};
        getContentResolver().delete(StudentsProvider.CONTENT_URI,StudentsProvider.name + " LIKE ?", values);
        Toast.makeText(getBaseContext(), "Record Deleted", Toast.LENGTH_LONG).show();
    }
    public void onClickShowDetails(View view){
        TextView resultView = (TextView) findViewById(R.id.res);
        Cursor cursor = getContentResolver().query(Uri.parse("content://com.example.week14.StudentsProvider/users"),null,null,null,null);
        if(cursor.moveToFirst()){
            StringBuilder strBuild = new StringBuilder();
            while(!cursor.isAfterLast()){
                strBuild.append("\n"+cursor.getString(cursor.getColumnIndex("id"))+"-"+cursor.getString(cursor.getColumnIndex("name")));
                cursor.moveToNext();
            }
            resultView.setText(strBuild);
        }
        else{
            resultView.setText("No Records Found");
        }
    }
}