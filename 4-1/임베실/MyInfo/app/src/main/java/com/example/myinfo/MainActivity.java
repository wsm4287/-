package com.example.myinfo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }


    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.switch2:
                RadioButton juniorButton = (RadioButton) findViewById(R.id.radio1);
                RadioButton seniorButton = (RadioButton) findViewById(R.id.radio2);

                if (juniorButton.isChecked()) {
                    seniorButton.setChecked(false);
                    juniorButton.setChecked(true);
                } else {
                    seniorButton.setChecked(true);
                    juniorButton.setChecked(false);
                }
                break;
        }
    }
}