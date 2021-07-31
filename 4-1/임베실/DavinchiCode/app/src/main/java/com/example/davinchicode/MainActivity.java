package com.example.davinchicode;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        start();

        Button imageButton = (Button) findViewById(R.id.start);
        Button imageButton2 = (Button) findViewById(R.id.load);
        Button imageButton3 = (Button) findViewById(R.id.introduction);


        imageButton.setOnClickListener(new View.OnClickListener() {


            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getApplicationContext(), Game.class);
                intent.putExtra(Intent.EXTRA_TEXT, "0");
                startActivity(intent);
            }
        });

        imageButton2.setOnClickListener(new View.OnClickListener() {


            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getApplicationContext(), Game.class);
                intent.putExtra(Intent.EXTRA_TEXT, "1");
                startActivity(intent);
            }
        });

        imageButton3.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getApplicationContext(), Introduction.class);
                startActivity(intent);
            }
        });

    }

    public native void start();

}