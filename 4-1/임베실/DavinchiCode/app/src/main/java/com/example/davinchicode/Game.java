
package com.example.davinchicode;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ResourceBundle;
import java.util.Vector;
import android.util.Log;


public class Game extends AppCompatActivity {
    Integer WhiteNum[] = new Integer[13];
    Integer BlackNum[] = new Integer[13];
    Integer WhiteCard[] = new Integer[27];
    Integer BlackCard[] = new Integer[27];
    Integer Player1[] = new Integer[14];
    Integer Player2[] = new Integer[14];
    Integer Player1_color[] =new Integer[13];
    Integer Player2_color[] = new Integer[13];
    Integer Player1_opened[] = new Integer[13];
    Integer Player2_opened[] = new Integer[13];
    Integer ll;

    ImageView Player1_image[] = new ImageView[13];
    ImageButton Player2_image[] = new ImageButton[13];
    Button OK;
    TextView text1;

    Button HINT;

    int hint;

    private static final String TAG = "Game";

    private EditText input;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_game);

        text1 = (TextView) findViewById(R.id.textView);
        input =  (EditText) findViewById(R.id.inputValue);
        OK = (Button) findViewById(R.id.ok);
        HINT = (Button) findViewById(R.id.hint);

        Bundle getdata = getIntent().getExtras();
        ll = Integer.parseInt(getdata.getString(Intent.EXTRA_TEXT));

        hint = 2;
        led(hint);

        for(int i=0; i<13; i++){
            WhiteNum[i] = i;
            BlackNum[i] = i;
            Player1[i] = 99;
            Player2[i] = 99;
            Player1_color[i] = 0;
            Player2_color[i] = 0;
            Player1_opened[i] = 0;
            Player2_opened[i] = 0;
        }
        Player1[13] = 99;
        Player2[13] = 99;

        WhiteCard[0] = R.drawable.white0;
        WhiteCard[1] = R.drawable.white1;
        WhiteCard[2] = R.drawable.white2;
        WhiteCard[3] = R.drawable.white3;
        WhiteCard[4] = R.drawable.white4;
        WhiteCard[5] = R.drawable.white5;
        WhiteCard[6] = R.drawable.white6;
        WhiteCard[7] = R.drawable.white7;
        WhiteCard[8] = R.drawable.white8;
        WhiteCard[9] = R.drawable.white9;
        WhiteCard[10] = R.drawable.white10;
        WhiteCard[11] = R.drawable.white11;
        WhiteCard[12] = R.drawable.whitejoker;
        WhiteCard[13] = R.drawable.whiteempty;

        WhiteCard[14] = R.drawable.white0_rev;
        WhiteCard[15] = R.drawable.white1_rev;
        WhiteCard[16] = R.drawable.white2_rev;
        WhiteCard[17] = R.drawable.white3_rev;
        WhiteCard[18] = R.drawable.white4_rev;
        WhiteCard[19] = R.drawable.white5_rev;
        WhiteCard[20] = R.drawable.white6_rev;
        WhiteCard[21] = R.drawable.white7_rev;
        WhiteCard[22] = R.drawable.white8_rev;
        WhiteCard[23] = R.drawable.white9_rev;
        WhiteCard[24] = R.drawable.white10_rev;
        WhiteCard[25] = R.drawable.white11_rev;
        WhiteCard[26] = R.drawable.whitejoker_rev;


        BlackCard[0] = R.drawable.black0;
        BlackCard[1] = R.drawable.black1;
        BlackCard[2] = R.drawable.black2;
        BlackCard[3] = R.drawable.black3;
        BlackCard[4] = R.drawable.black4;
        BlackCard[5] = R.drawable.black5;
        BlackCard[6] = R.drawable.black6;
        BlackCard[7] = R.drawable.black7;
        BlackCard[8] = R.drawable.black8;
        BlackCard[9] = R.drawable.black9;
        BlackCard[10] = R.drawable.black10;
        BlackCard[11] = R.drawable.black11;
        BlackCard[12] = R.drawable.blackjoker;
        BlackCard[13] = R.drawable.blackempty;

        BlackCard[14] = R.drawable.black0_rev;
        BlackCard[15] = R.drawable.black1_rev;
        BlackCard[16] = R.drawable.black2_rev;
        BlackCard[17] = R.drawable.black3_rev;
        BlackCard[18] = R.drawable.black4_rev;
        BlackCard[19] = R.drawable.black5_rev;
        BlackCard[20] = R.drawable.black6_rev;
        BlackCard[21] = R.drawable.black7_rev;
        BlackCard[22] = R.drawable.black8_rev;
        BlackCard[23] = R.drawable.black9_rev;
        BlackCard[24] = R.drawable.black10_rev;
        BlackCard[25] = R.drawable.black11_rev;
        BlackCard[26] = R.drawable.blackjoker_rev;

        Player1_image[0] = findViewById(R.id.player1_1);
        Player1_image[1] = findViewById(R.id.player1_2);
        Player1_image[2] = findViewById(R.id.player1_3);
        Player1_image[3] = findViewById(R.id.player1_4);
        Player1_image[4] = findViewById(R.id.player1_5);
        Player1_image[5] = findViewById(R.id.player1_6);
        Player1_image[6] = findViewById(R.id.player1_7);
        Player1_image[7] = findViewById(R.id.player1_8);
        Player1_image[8] = findViewById(R.id.player1_9);
        Player1_image[9] = findViewById(R.id.player1_10);
        Player1_image[10] = findViewById(R.id.player1_11);
        Player1_image[11] = findViewById(R.id.player1_12);
        Player1_image[12] = findViewById(R.id.player1_13);

        Player2_image[0] = findViewById(R.id.player2_1);
        Player2_image[1] = findViewById(R.id.player2_2);
        Player2_image[2] = findViewById(R.id.player2_3);
        Player2_image[3] = findViewById(R.id.player2_4);
        Player2_image[4] = findViewById(R.id.player2_5);
        Player2_image[5] = findViewById(R.id.player2_6);
        Player2_image[6] = findViewById(R.id.player2_7);
        Player2_image[7] = findViewById(R.id.player2_8);
        Player2_image[8] = findViewById(R.id.player2_9);
        Player2_image[9] = findViewById(R.id.player2_10);
        Player2_image[10] = findViewById(R.id.player2_11);
        Player2_image[11] = findViewById(R.id.player2_12);
        Player2_image[12] = findViewById(R.id.player2_13);

        if(ll == 1){
            loaddata();
        }


            View.OnClickListener onClickListener = new Button.OnClickListener(){
                @Override
                public void onClick(View v) {
                    switch(v.getId()){
                        case R.id.black:
                            int count;
                            int k = 0;
                            while(Player1[k]!=99) k++;
                            count = k;
                            k = 0;
                            if(count>=4 && count <13){
                                text1.setText("상대 카드를 골라주세요" + count);
                                int open = draw1_black(count);
                                Hint();
                                View.OnClickListener onClickListener = new Button.OnClickListener(){
                                    @Override
                                    public void onClick(View vv) {
                                        switch(vv.getId()){
                                            case R.id.player2_1 :
                                                text1.setText("추측할 숫자를 입력하세요 " + count);
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[0] == y){
                                                            Player2_opened[0] = 1;
                                                            if(Player2_color[0] == 1) Player2_image[0].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[0] == 2) Player2_image[0].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI(count);
                                                        }

                                                    }
                                                });
                                                break;
                                            case R.id.player2_2 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[1] == y){
                                                            if(Player2_color[1] == 1) Player2_image[1].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[1] == 2) Player2_image[1].setBackgroundResource(BlackCard[y]);
                                                            Player2_opened[1] = 1;
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_3 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[2] == y){
                                                            Player2_opened[2] = 1;
                                                            if(Player2_color[2] == 1) Player2_image[2].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[2] == 2) Player2_image[2].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI(count);
                                                        }
                                                    }

                                                });
                                                break;
                                            case R.id.player2_4 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[3] == y){
                                                            Player2_opened[3] = 1;
                                                            if(Player2_color[3] == 1) Player2_image[3].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[3] == 2) Player2_image[3].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_5 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[4] == y){
                                                            Player2_opened[4] = 1;
                                                            if(Player2_color[4] == 1) Player2_image[4].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[4] == 2) Player2_image[4].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI(count);
                                                                    }
                                                                });
                                                            }
                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_6 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[5] == y){
                                                            Player2_opened[5] = 1;
                                                            if(Player2_color[5] == 1) Player2_image[5].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[5] == 2) Player2_image[5].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_7 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[6] == y){
                                                            Player2_opened[6] = 1;
                                                            if(Player2_color[6] == 1) Player2_image[6].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[6] == 2) Player2_image[6].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_8 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[7] == y){
                                                            Player2_opened[7] = 1;
                                                            if(Player2_color[7] == 1) Player2_image[7].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[7] == 2) Player2_image[7].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_9 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[8] == y){
                                                            Player2_opened[8] = 1;
                                                            if(Player2_color[8] == 1) Player2_image[8].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[8] == 2) Player2_image[8].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_10 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[9] == y){
                                                            Player2_opened[9] = 1;
                                                            if(Player2_color[9]== 1) Player2_image[9].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[9] == 2) Player2_image[9].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_11 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[10] == y){
                                                            Player2_opened[10] = 1;
                                                            if(Player2_color[10] == 1) Player2_image[10].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[10] == 2) Player2_image[10].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_12 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[11] == y){
                                                            Player2_opened[11] = 1;
                                                            if(Player2_color[11] == 1) Player2_image[11].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[11] == 2) Player2_image[11].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI(count);
                                                                    }
                                                                });
                                                            }
                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_13 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[12] == y){
                                                            Player2_opened[12] = 1;
                                                            if(Player2_color[12] == 1) Player2_image[12].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[12] == 2) Player2_image[12].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI(count);
                                                                    }
                                                                });
                                                            }
                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI(count);
                                                        }
                                                    }
                                                });
                                                break;

                                        }

                                    }
                                };
                                Player2_image[0].setOnClickListener(onClickListener);
                                Player2_image[1].setOnClickListener(onClickListener);
                                Player2_image[2].setOnClickListener(onClickListener);
                                Player2_image[3].setOnClickListener(onClickListener);
                                Player2_image[4].setOnClickListener(onClickListener);
                                Player2_image[5].setOnClickListener(onClickListener);
                                Player2_image[6].setOnClickListener(onClickListener);
                                Player2_image[7].setOnClickListener(onClickListener);
                                Player2_image[8].setOnClickListener(onClickListener);
                                Player2_image[9].setOnClickListener(onClickListener);
                                Player2_image[10].setOnClickListener(onClickListener);
                                Player2_image[11].setOnClickListener(onClickListener);
                                Player2_image[12].setOnClickListener(onClickListener);
                            }

                            else if(count<4){
                                int ccount = count+1;
                                text1.setText(ccount +" 장의 카드를 골랐습니다.");
                              draw1_black(count);
                              draw2_white(count);
                            }

                            else{
                                text1.setText("모든 카드를 소모하였습니다. 상대 카드를 골라주세요");
                                Hint();
                                View.OnClickListener onClickListener = new Button.OnClickListener(){
                                    @Override
                                    public void onClick(View vv) {
                                        switch(vv.getId()){
                                            case R.id.player2_1 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[0] == y){
                                                            Player2_opened[0] = 1;
                                                            if(Player2_color[0] == 1) Player2_image[0].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[0] == 2) Player2_image[0].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }
                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }

                                                    }
                                                });
                                                break;
                                            case R.id.player2_2 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[1] == y){
                                                            Player2_opened[1] = 1;
                                                            if(Player2_color[1] == 1) Player2_image[1].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[1] == 2) Player2_image[1].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }
                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_3 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[2] == y){
                                                            Player2_opened[2] = 1;
                                                            if(Player2_color[2] == 1) Player2_image[2].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[2] == 2) Player2_image[2].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }
                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }

                                                });
                                                break;
                                            case R.id.player2_4 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[3] == y){
                                                            Player2_opened[3] = 1;
                                                            if(Player2_color[3] == 1) Player2_image[3].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[3] == 2) Player2_image[3].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_5 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[4] == y){
                                                            Player2_opened[4] = 1;
                                                            if(Player2_color[4] == 1) Player2_image[4].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[4] == 2) Player2_image[4].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_6 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[5] == y){
                                                            Player2_opened[5] = 1;
                                                            if(Player2_color[5] == 1) Player2_image[5].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[5] == 2) Player2_image[5].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });

                                                            }
                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_7 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[6] == y){
                                                            Player2_opened[6] = 1;
                                                            if(Player2_color[6] == 1) Player2_image[6].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[6] == 2) Player2_image[6].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });

                                                            }
                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_8 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[7] == y){
                                                            Player2_opened[7] = 1;
                                                            if(Player2_color[7] == 1) Player2_image[7].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[7] == 2) Player2_image[7].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });

                                                            }
                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_9 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[8] == y){
                                                            Player2_opened[8] = 1;
                                                            if(Player2_color[8] == 1) Player2_image[8].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[8] == 2) Player2_image[8].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }
                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_10 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[9] == y){
                                                            Player2_opened[9] = 1;
                                                            if(Player2_color[9]== 1) Player2_image[9].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[9] == 2) Player2_image[9].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }
                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_11 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[10] == y){
                                                            Player2_opened[10] = 1;
                                                            if(Player2_color[10] == 1) Player2_image[10].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[10] == 2) Player2_image[10].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }
                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_12 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[11] == y){
                                                            Player2_opened[11] = 1;
                                                            if(Player2_color[11] == 1) Player2_image[11].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[11] == 2) Player2_image[11].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_13 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[12] == y){
                                                            Player2_opened[12] = 1;
                                                            if(Player2_color[12] == 1) Player2_image[12].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[12] == 2) Player2_image[12].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;

                                        }

                                    }
                                };
                                Player2_image[0].setOnClickListener(onClickListener);
                                Player2_image[1].setOnClickListener(onClickListener);
                                Player2_image[2].setOnClickListener(onClickListener);
                                Player2_image[3].setOnClickListener(onClickListener);
                                Player2_image[4].setOnClickListener(onClickListener);
                                Player2_image[5].setOnClickListener(onClickListener);
                                Player2_image[6].setOnClickListener(onClickListener);
                                Player2_image[7].setOnClickListener(onClickListener);
                                Player2_image[8].setOnClickListener(onClickListener);
                                Player2_image[9].setOnClickListener(onClickListener);
                                Player2_image[10].setOnClickListener(onClickListener);
                                Player2_image[11].setOnClickListener(onClickListener);
                                Player2_image[12].setOnClickListener(onClickListener);

                            }

                            break;

                        case R.id.white:
                            k = 0;
                            while(Player1[k]!=99) k++;
                            count = k;
                            k = 0;
                            if(count>=4 && count <13){
                                int open = draw1_white(count);
                                Hint();
                                text1.setText("상대 카드를 골라주세요");
                                View.OnClickListener onClickListener = new Button.OnClickListener(){
                                    @Override
                                    public void onClick(View vv) {
                                        switch(vv.getId()){
                                            case R.id.player2_1 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[0] == y){
                                                            Player2_opened[0] = 1;
                                                            if(Player2_color[0] == 1) Player2_image[0].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[0] == 2) Player2_image[0].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_2(count);
                                                                    }
                                                                });
                                                            }
                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI_2(count);
                                                        }

                                                    }
                                                });
                                                break;
                                            case R.id.player2_2 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[1] == y){
                                                            Player2_opened[1] = 1;
                                                            if(Player2_color[1] == 1) Player2_image[1].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[1] == 2) Player2_image[1].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_2(count);
                                                                    }
                                                                });
                                                            }
                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI_2(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_3 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[2] == y){
                                                            Player2_opened[2] = 1;
                                                            if(Player2_color[2] == 1) Player2_image[2].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[2] == 2) Player2_image[2].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_2(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI_2(count);
                                                        }
                                                    }

                                                });
                                                break;
                                            case R.id.player2_4 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[3] == y){
                                                            Player2_opened[3] = 1;
                                                            if(Player2_color[3] == 1) Player2_image[3].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[3] == 2) Player2_image[3].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_2(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI_2(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_5 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[4] == y){
                                                            Player2_opened[4] = 1;
                                                            if(Player2_color[4] == 1) Player2_image[4].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[4] == 2) Player2_image[4].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_2(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI_2(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_6 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[5] == y){
                                                            Player2_opened[5] = 1;
                                                            if(Player2_color[5] == 1) Player2_image[5].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[5] == 2) Player2_image[5].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_2(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI_2(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_7 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[6] == y){
                                                            Player2_opened[6] = 1;
                                                            if(Player2_color[6] == 1) Player2_image[6].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[6] == 2) Player2_image[6].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_2(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI_2(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_8 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[7] == y){
                                                            Player2_opened[7] = 1;
                                                            if(Player2_color[7] == 1) Player2_image[7].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[7] == 2) Player2_image[7].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_2(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI_2(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_9 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[8] == y){
                                                            Player2_opened[8] = 1;
                                                            if(Player2_color[8] == 1) Player2_image[8].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[8] == 2) Player2_image[8].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_2(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI_2(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_10 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[9] == y){
                                                            Player2_opened[9] = 1;
                                                            if(Player2_color[9]== 1) Player2_image[9].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[9] == 2) Player2_image[9].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_2(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI_2(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_11 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[10] == y){
                                                            Player2_opened[10] = 1;
                                                            if(Player2_color[10] == 1) Player2_image[10].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[10] == 2) Player2_image[10].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_2(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI_2(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_12 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[11] == y){
                                                            Player2_opened[11] = 1;
                                                            if(Player2_color[11] == 1) Player2_image[11].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[11] == 2) Player2_image[11].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_2(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI_2(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_13 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[12] == y){
                                                            Player2_opened[12] = 1;
                                                            if(Player2_color[12] == 1) Player2_image[12].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[12] == 2) Player2_image[12].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_2(count);
                                                                    }
                                                                });
                                                            }
                                                        }
                                                        else{
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            AI_2(count);
                                                        }
                                                    }
                                                });
                                                break;
                                        }

                                    }
                                };
                                Player2_image[0].setOnClickListener(onClickListener);
                                Player2_image[1].setOnClickListener(onClickListener);
                                Player2_image[2].setOnClickListener(onClickListener);
                                Player2_image[3].setOnClickListener(onClickListener);
                                Player2_image[4].setOnClickListener(onClickListener);
                                Player2_image[5].setOnClickListener(onClickListener);
                                Player2_image[6].setOnClickListener(onClickListener);
                                Player2_image[7].setOnClickListener(onClickListener);
                                Player2_image[8].setOnClickListener(onClickListener);
                                Player2_image[9].setOnClickListener(onClickListener);
                                Player2_image[10].setOnClickListener(onClickListener);
                                Player2_image[11].setOnClickListener(onClickListener);
                                Player2_image[12].setOnClickListener(onClickListener);
                            }

                            else if(count<4){
                                int ccount = count+1;
                                text1.setText(ccount +" 장의 카드를 골랐습니다.");
                                draw1_white(count);
                                draw2_black(count);
                            }
                            else{
                                text1.setText("모든 카드를 소모했습니다. 상대 카드를 골라주세요");
                                Hint();
                                View.OnClickListener onClickListener = new Button.OnClickListener(){
                                    @Override
                                    public void onClick(View vv) {
                                        switch(vv.getId()){
                                            case R.id.player2_1 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[0] == y){
                                                            Player2_opened[0] = 1;
                                                            if(Player2_color[0] == 1) Player2_image[0].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[0] == 2) Player2_image[0].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }

                                                    }
                                                });
                                                break;
                                            case R.id.player2_2 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[1] == y){
                                                            Player2_opened[1] = 1;
                                                            if(Player2_color[1] == 1) Player2_image[1].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[1] == 2) Player2_image[1].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_3 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[2] == y){
                                                            Player2_opened[2] = 1;
                                                            if(Player2_color[2] == 1) Player2_image[2].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[2] == 2) Player2_image[2].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }

                                                });
                                                break;
                                            case R.id.player2_4 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[3] == y){
                                                            Player2_opened[3] = 1;
                                                            if(Player2_color[3] == 1) Player2_image[3].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[3] == 2) Player2_image[3].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_5 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[4] == y){
                                                            Player2_opened[4] = 1;
                                                            if(Player2_color[4] == 1) Player2_image[4].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[4] == 2) Player2_image[4].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_6 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[5] == y){
                                                            Player2_opened[5] = 1;
                                                            if(Player2_color[5] == 1) Player2_image[5].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[5] == 2) Player2_image[5].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_7 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[6] == y){
                                                            Player2_opened[6] = 1;
                                                            if(Player2_color[6] == 1) Player2_image[6].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[6] == 2) Player2_image[6].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_8 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[7] == y){
                                                            Player2_opened[7] = 1;
                                                            if(Player2_color[7] == 1) Player2_image[7].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[7] == 2) Player2_image[7].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_9 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[8] == y){
                                                            Player2_opened[8] = 1;
                                                            if(Player2_color[8] == 1) Player2_image[8].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[8] == 2) Player2_image[8].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_10 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[9] == y){
                                                            Player2_opened[9] = 1;
                                                            if(Player2_color[9]== 1) Player2_image[9].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[9] == 2) Player2_image[9].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_11 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[10] == y){
                                                            Player2_opened[10] = 1;
                                                            if(Player2_color[10] == 1) Player2_image[10].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[10] == 2) Player2_image[10].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_12 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[11] == y){
                                                            Player2_opened[11] = 1;
                                                            if(Player2_color[11] == 1) Player2_image[11].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[11] == 2) Player2_image[11].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                            case R.id.player2_13 :
                                                text1.setText("추측할 숫자를 입력하세요 ");
                                                OK.setOnClickListener(new View.OnClickListener(){
                                                    @Override
                                                    public void onClick(View view){
                                                        int y = Integer.valueOf(input.getText().toString());
                                                        if(Player2[12] == y){
                                                            Player2_opened[12] = 1;
                                                            if(Player2_color[12] == 1) Player2_image[12].setBackgroundResource(WhiteCard[y]);
                                                            if(Player2_color[12] == 2) Player2_image[12].setBackgroundResource(BlackCard[y]);
                                                            if(Player2_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else{
                                                                text1.setText("그만 하시겠습니까? ");
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View v) {
                                                                        AI_1(count);
                                                                    }
                                                                });
                                                            }

                                                        }
                                                        else{
                                                            int open = 0;
                                                            while(Player1_opened[open] == 1 && open<12) open++;
                                                            int z = Player1[open];
                                                            if(Player1_color[open] == 1) Player1_image[open].setBackgroundResource(WhiteCard[z+14]);
                                                            if(Player1_color[open] == 2) Player1_image[open].setBackgroundResource(BlackCard[z+14]);
                                                            Player1_opened[open] = 1;
                                                            if(Player1_End() == 1){
                                                                OK.setOnClickListener(new View.OnClickListener() {
                                                                    @Override
                                                                    public void onClick(View view) {
                                                                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                                                                        startActivity(intent);
                                                                    }
                                                                });
                                                            }
                                                            else AI_1(count);
                                                        }
                                                    }
                                                });
                                                break;
                                        }

                                    }
                                };
                                Player2_image[0].setOnClickListener(onClickListener);
                                Player2_image[1].setOnClickListener(onClickListener);
                                Player2_image[2].setOnClickListener(onClickListener);
                                Player2_image[3].setOnClickListener(onClickListener);
                                Player2_image[4].setOnClickListener(onClickListener);
                                Player2_image[5].setOnClickListener(onClickListener);
                                Player2_image[6].setOnClickListener(onClickListener);
                                Player2_image[7].setOnClickListener(onClickListener);
                                Player2_image[8].setOnClickListener(onClickListener);
                                Player2_image[9].setOnClickListener(onClickListener);
                                Player2_image[10].setOnClickListener(onClickListener);
                                Player2_image[11].setOnClickListener(onClickListener);
                                Player2_image[12].setOnClickListener(onClickListener);
                            }

                            break;


                    }

                }
            };
            Button BlackButton = (Button) findViewById(R.id.black);
            BlackButton.setOnClickListener(onClickListener);
            Button WhiteButton = (Button) findViewById(R.id.white);
            WhiteButton.setOnClickListener(onClickListener);

    }

    public int draw1_black(int count){
        int a;
        if(count<12) a = (int) (Math.random()*(13-count));
        else{
            a = 0;
            text1.setText("마지막입니다/ ");
            if(BlackNum[a] == 12){
                text1.setText("-의 위치를 정해주세요");
                final int[] xx = new int[1];
                OK.setOnClickListener(new View.OnClickListener(){
                    @Override
                    public void onClick(View view){
                        int x = 12;
                        Player1[x] = 12;
                        Player1_image[x].setBackgroundResource(BlackCard[12]);
                        Player1_opened[x] = 0;
                        Player1_color[x] = 2;
                        BlackNum[a] = -999;
                        xx[0] =x;
                    }
                });
                return xx[0];
            }
        }
        int k = 0;
        if(BlackNum[a] == 12){
            text1.setText("-의 위치를 정해주세요");
            final int[] xx = new int[1];
            OK.setOnClickListener(new View.OnClickListener(){
                @Override
                public void onClick(View view){
                    int x = Integer.valueOf(input.getText().toString());
                    if(x>=count) x = count;
                    for(int j=count-1; j>=x; j--){
                        Player1[j+1] = Player1[j];
                        Player1_color[j+1] = Player1[j];
                        Player1_opened[j+1] = Player1_opened[j];
                        Player1_image[j+1].setBackground(Player1_image[j].getBackground());
                    }
                    Player1[x] = 12;
                    Player1_image[x].setBackgroundResource(BlackCard[12]);
                    Player1_opened[x] = 0;
                    Player1_color[x] = 2;
                    BlackNum[a] = -999;
                    xx[0] =x;
                }
            });
            return xx[0];
        }
        else{
            while (Player1[k] < BlackNum[a] || Player1[k] == 12){
                k++;
            }
            int t = 12;
            while(t>k){
                Player1[t] = Player1[t-1];
                Player1_color[t] = Player1_color[t-1];
                Player1_opened[t] = Player1_opened[t-1];
                Player1_image[t].setBackground(Player1_image[t-1].getBackground());
                t--;
            }
            Player1[k] = BlackNum[a];
            Player1_color[k] = 2;
            Player1_opened[k] = 0;
            Player1_image[k].setBackgroundResource(BlackCard[BlackNum[a]]);
            for(int j=a; j<12-count; j++){
                BlackNum[j] = BlackNum[j+1];
            }
            BlackNum[12-count] = -999;
            return k;
        }

    }

    public int draw1_white(int count){
        int a;
        if(count<12) a = (int) (Math.random()*(13-count));
        else{
            a = 0;
            text1.setText("마지막입니다/ ");
            if(BlackNum[a] == 12){
                text1.setText("-의 위치를 정해주세요");
                final int[] xx = new int[1];
                OK.setOnClickListener(new View.OnClickListener(){
                    @Override
                    public void onClick(View view){
                        int x = 12;
                        Player1[x] = 12;
                        Player1_image[x].setBackgroundResource(BlackCard[12]);
                        Player1_opened[x] = 0;
                        Player1_color[x] = 2;
                        BlackNum[a] = -999;
                        xx[0] =x;
                    }
                });
                return xx[0];
            }
        }
        int k = 0;
        if(WhiteNum[a] == 12){
            text1.setText("-의 위치를 정해주세요");
            final int[] xx = {0};
            OK.setOnClickListener(new View.OnClickListener(){
                @Override
                public void onClick(View view){
                    int x = Integer.valueOf(input.getText().toString());
                    if(x>=count) x = count;
                    for(int j=count-1; j>=x; j--){
                        Player1[j+1] = Player1[j];
                        Player1_color[j+1] = Player1_color[j];
                        Player1_opened[j+1] = Player1_opened[j];
                        Player1_image[j+1].setBackground(Player1_image[j].getBackground());
                    }
                    Player1[x] = 12;
                    Player1_color[x] = 1;
                    Player1_opened[x] = 0;
                    Player1_image[x].setBackgroundResource(WhiteCard[12]);
                    WhiteNum[a] = -999;
                    xx[0] = x;
                }
            });
            return xx[0];
        }
        else{
            while (Player1[k] < WhiteNum[a] || Player1[k] == 12){
                k++;
            }
            if(Player1[k].equals(WhiteNum[a])){
                k++;
            }
            int t = 12;
            while(t>k){
                Player1[t] = Player1[t-1];
                Player1_color[t] = Player1_color[t-1];
                Player1_opened[t] = Player1_opened[t-1];
                Player1_image[t].setBackground(Player1_image[t-1].getBackground());
                t--;
            }
            Player1[k] = WhiteNum[a];
            Player1_color[k] = 1;
            Player1_opened[k] = 0;
            Player1_image[k].setBackgroundResource(WhiteCard[WhiteNum[a]]);

            for(int j=a; j<12-count; j++){
                WhiteNum[j] = WhiteNum[j+1];
            }
            WhiteNum[12-count] = -999;
            return k;
        }
    }


    public int draw2_white(int count){
        int b = (int) (Math.random()*(13-count));
        int k = 0;
        int a;
        if(count<12) a = (int) (Math.random()*(13-count));
        else{
            a = 0;
            text1.setText("마지막입니다/ ");
            if(BlackNum[a] == 12){
                text1.setText("-의 위치를 정해주세요");
                final int[] xx = new int[1];
                OK.setOnClickListener(new View.OnClickListener(){
                    @Override
                    public void onClick(View view){
                        int x = 12;
                        Player1[x] = 12;
                        Player1_image[x].setBackgroundResource(BlackCard[12]);
                        Player1_opened[x] = 0;
                        Player1_color[x] = 2;
                        BlackNum[a] = -999;
                        xx[0] =x;
                    }
                });
                return xx[0];
            }
        }
        if(WhiteNum[b] == 12){
            int x = (int) (Math.random()*count);
            for(int j=count-1; j>=x; j--){
                Player2[j+1] = Player2[j];
                Player2_opened[j+1] = Player2_opened[j];
                Player2_image[j+1].setBackground(Player2_image[j].getBackground());
                Player2_color[j+1] = Player2_color[j];
            }
            Player2[x] = 12;
            Player2_image[x].setBackgroundResource(WhiteCard[13]);
            Player2_color[x] = 1;
            Player2_opened[x] = 0;
            WhiteNum[b] = -999;
            return x;
        }
        else{
            while (Player2[k] < WhiteNum[b] || Player2[k] == 12){
                k++;
            }
            if(Player2[k].equals(WhiteNum[b])){
                k++;
            }
            int t = 12;
            while(t>k){
                Player2[t] = Player2[t-1];
                Player2_image[t].setBackground(Player2_image[t-1].getBackground());
                Player2_color[t] = Player2_color[t-1];
                Player2_opened[t] = Player2_opened[t-1];
                t--;
            }
            Player2[k] = WhiteNum[b];
            Player2_image[k].setBackgroundResource(WhiteCard[13]);
            Player2_color[k] = 1;
            Player2_opened[k] = 0;
            for(int j=b; j<12-count; j++){
                WhiteNum[j] = WhiteNum[j+1];
            }
            WhiteNum[12-count] = -999;
            return k;
        }



    }

    public int draw2_black(int count){
        int b = (int) (Math.random()*(13-count));
        int k = 0;
        int a;
        if(count<12) a = (int) (Math.random()*(13-count));
        else{
            a = 0;
            text1.setText("마지막입니다/ ");
            if(BlackNum[a] == 12){
                text1.setText("-의 위치를 정해주세요");
                final int[] xx = new int[1];
                OK.setOnClickListener(new View.OnClickListener(){
                    @Override
                    public void onClick(View view){
                        int x = 12;
                        Player1[x] = 12;
                        Player1_image[x].setBackgroundResource(BlackCard[12]);
                        Player1_opened[x] = 0;
                        Player1_color[x] = 2;
                        BlackNum[a] = -999;
                        xx[0] =x;
                    }
                });
                return xx[0];
            }
        }
        if(BlackNum[b] == 12){
            int x = (int) (Math.random()*count);
            for(int j=count-1; j>=x; j--){
                Player2[j+1] = Player2[j];
                Player2_image[j+1].setBackground(Player2_image[j].getBackground());
                Player2_color[j+1] = Player2_color[j];
                Player2_opened[j+1] = Player2_opened[j];
            }
            Player2[x] = 12;
            Player2_image[x].setBackgroundResource(BlackCard[13]);
            Player2_color[x] = 2;
            Player2_opened[x] = 0;
            WhiteNum[b] = -999;
            return x;
        }
        else{
            while (Player2[k] < BlackNum[b] || Player2[k] == 12){
                k++;
            }
            int t = 12;
            while(t>k){
                Player2[t] = Player2[t-1];
                Player2_image[t].setBackground(Player2_image[t-1].getBackground());
                Player2_color[t] = Player2_color[t-1];
                Player2_opened[t] = Player2_opened[t-1];
                t--;
            }
            Player2[k] = BlackNum[b];
            Player2_image[k].setBackgroundResource(BlackCard[13]);
            Player2_color[k] = 2;
            Player2_opened[k] = 0;

            for(int j=b; j<12-count; j++){
                BlackNum[j] = BlackNum[j+1];
            }
            BlackNum[12-count] = -999;
            return k;
        }


    }

    public void AI(int count){
        int open = draw2_white(count);
        int k = 0;
        while(Player1_opened[k] != 0) k++;
        int c = Player1_color[k];
        int j = 0;
        int list[] = new int[13];

        for(int i=0; i<=12; i++){
            list[i] = 0;
        }

        while(Player2[j] != 99){
            if(Player2_color[j] == c){
                list[Player2[j]] = 1;
            }
            j++;
        }

        j = 0;
        while(Player1[j] != 99){
            if(Player1_opened[j] == 1 && Player1_color[j] == c){
                list[Player1[j]] = 1;
            }
            j++;
        }

        j = 0;
        while(list[j] == 1) j = (int) (Math.random()*13);

        int x = j;

        if(Player1[k] == x){
            text1.setText("상대가 당신의 카드를 맞췄습니다. ");
            if(Player1_color[k] == 1) Player1_image[k].setBackgroundResource(WhiteCard[x+14]);
            if(Player1_color[k] == 2) Player1_image[k].setBackgroundResource(BlackCard[x+14]);
            Player1_opened[k] = 1;
            if(Player1_End() == 1){
                OK.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                        startActivity(intent);
                    }
                });
            }
        }
        else{
            text1.setText("상대가 틀렸습니다.  ");
            if(Player2_color[open] == 1) Player2_image[open].setBackgroundResource(WhiteCard[Player2[open]]);
            if(Player2_color[open] == 2) Player2_image[open].setBackgroundResource(BlackCard[Player2[open]]);
            Player2_opened[open] = 1;
        }
        savedata();
    }


    public void AI_1(int count){
        int k = 0;
        while(Player1_opened[k] != 0) k++;
        int c = Player1_color[k];
        int j = 0;
        int list[] = new int[13];

        for(int i=0; i<=12; i++){
            list[i] = 0;
        }

        while(Player2[j] != 99 && j<13){
            if(Player2_color[j] == c){
                list[Player2[j]] = 1;
            }
            j++;
        }

        j = 0;
        while(Player1[j] != 99 && j<13){
            if(Player1_opened[j] == 1 && Player1_color[j] == c){
                list[Player1[j]] = 1;
            }
            j++;
        }

        j = 0;
        while(list[j] == 1 && j<12) j++;

        int x = j;

        if(Player1[k] == x){
            text1.setText("상대가 당신의 카드를 맞췄습니다. ");
            if(Player1_color[k] == 1) Player1_image[k].setBackgroundResource(WhiteCard[x+14]);
            if(Player1_color[k] == 2) Player1_image[k].setBackgroundResource(BlackCard[x+14]);
            Player1_opened[k] = 1;

            if(Player1_End() == 1){
                OK.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                        startActivity(intent);
                    }
                });
            }
        }
        else{
            int open = 0;
            while(Player2_opened[open] == 1 && open<12) open++;
            text1.setText("상대가 틀렸습니다.  ");
            if(Player2_color[open] == 1) Player2_image[open].setBackgroundResource(WhiteCard[Player2[open]]);
            if(Player2_color[open] == 2) Player2_image[open].setBackgroundResource(BlackCard[Player2[open]]);
            Player2_opened[open] = 1;
        }
        savedata();
    }

    public void AI_2(int count){
        int open = draw2_black(count);
        int k = 0;
        while(Player1_opened[k] != 0) k++;
        int c = Player1_color[k];
        int j = 0;
        int list[] = new int[13];

        for(int i=0; i<=12; i++){
            list[i] = 0;
        }

        while(Player2[j] != 99){
            if(Player2_color[j] == c){
                list[Player2[j]] = 1;
            }
            j++;
        }

        j = 0;
        while(Player1[j] != 99){
            if(Player1_opened[j] == 1 && Player1_color[j] == c){
                list[Player1[j]] = 1;
            }
            j++;
        }

        j = 0;
        while(list[j] == 1) j = (int) (Math.random()*13);

        int x = j;

        if(Player1[k] == x){
            text1.setText("상대가 당신의 카드를 맞췄습니다. ");
            if(Player1_color[k] == 1) Player1_image[k].setBackgroundResource(WhiteCard[x+14]);
            if(Player1_color[k] == 2) Player1_image[k].setBackgroundResource(BlackCard[x+14]);
            Player1_opened[k] = 1;
            if(Player1_End() == 1){
                OK.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                        startActivity(intent);
                    }
                });
            }
        }
        else{
            text1.setText("상대가 틀렸습니다.  ");
            if(Player2_color[open] == 1) Player2_image[open].setBackgroundResource(WhiteCard[Player2[open]]);
            if(Player2_color[open] == 2) Player2_image[open].setBackgroundResource(BlackCard[Player2[open]]);
            Player2_opened[open] = 1;
        }
        savedata();
    }

    public int Player1_End(){
        int k = 0;
        while(k<13 && Player1_opened[k] == 1 ) k++;
        int x = 0;
        while(x<13 && Player1[x] != 99) x++;
        if(x != k) return 0;
        text1.setText("더 배워와 ㅋ. 나가~ ");
        return 1;
    }

    public int Player2_End(){
        int k = 0;
        while(k<13 && Player2_opened[k] == 1) k++;
        int x = 0;
        while(x<13 && Player2[x] != 99) x++;
        if(x != k) return 0;
        text1.setText("겜 좀 하네?? re? ");
        return 1;
    }

    public void Hint(){

        HINT.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(hint <1){
                    text1.setText("모든 hint를 사용하셨습니다. ");
                    return;
                }

                int x=0;
                while(Player2[x] != 99) x++;

                int k = (int) (Math.random()*x);
                while(Player2_opened[k] == 1) k = (int) (Math.random()*x);

                if(k<9) segment((k+1)*100 + Player2[k]);
                else segment((k+1)*100 + Player2[k]);

                hint = hint - 1;
                led(hint);
                return;
            }
        });
        return;
    }

    public void savedata(){

        int buf[] = new int[1024];

        for(int i=0; i<1024; i++) buf[i] = 0;

        for(int i=0; i<13; i++){
            buf[i] = WhiteNum[i];
        }
        for(int i=0; i<13; i++){
            buf[i+13] = BlackNum[i];
        }

        for(int i=0; i<13; i++){
            buf[i+13*2] = Player1[i];
        }
        for(int i=0; i<13; i++){
            buf[i+13*3] = Player2[i];
        }

        for(int i=0; i<13; i++){
            buf[i+13*4] = Player1_color[i];
        }
        for(int i=0; i<13; i++){
            buf[i+13*5] = Player2_color[i];
        }

        for(int i=0; i<13; i++){
            buf[i+13*6] = Player1_opened[i];
        }
        for(int i=0; i<13; i++){
            buf[i+13*7] = Player2_opened[i];
        }


        buf[13*8] = hint;

        write(buf);


        return;

    }

    public void loaddata(){

        int buf[] = new int[1024];
        for(int i=0; i<1024; i++) buf[i] = 0;
        read(buf);

        for(int i=0; i<13; i++){
            WhiteNum[i] = buf[i];
        }
        for(int i=0; i<13; i++){
            BlackNum[i] = buf[i+13];
        }

        for(int i=0; i<13; i++){
            Player1[i] = buf[i+13*2];
        }
        for(int i=0; i<13; i++){
            Player2[i] =  buf[i+13*3];
        }

        for(int i=0; i<13; i++){
            Player1_color[i] = buf[i+13*4];
        }
        for(int i=0; i<13; i++){
            Player2_color[i] = buf[i+13*5];
        }

        for(int i=0; i<13; i++){
            Player1_opened[i] = buf[i+13*6];
        }
        for(int i=0; i<13; i++){
            Player2_opened[i] = buf[i+13*7];
        }

        hint = buf[13*8];
        led(hint);

        for(int i=0; i<13; i++){
            if(Player1[i] != 99){
                if(Player1_color[i] == 1){
                    if (Player1_opened[i] == 0) {
                        Player1_image[i].setBackgroundResource(WhiteCard[Player1[i]]);
                    }
                    else{
                        Player1_image[i].setBackgroundResource(WhiteCard[Player1[i]+14]);
                    }
                }
                else{
                    if (Player1_opened[i] == 0) {
                        Player1_image[i].setBackgroundResource(BlackCard[Player1[i]]);
                    }
                    else{
                        Player1_image[i].setBackgroundResource(BlackCard[Player1[i]+14]);
                    }
                }
            }
            if(Player2[i] != 99){
                if(Player2_color[i] == 1){
                    if (Player2_opened[i] == 0) {
                        Player2_image[i].setBackgroundResource(WhiteCard[13]);
                    }
                    else{
                        Player2_image[i].setBackgroundResource(WhiteCard[Player2[i]]);
                    }
                }
                else{
                    if (Player2_opened[i] == 0) {
                        Player2_image[i].setBackgroundResource(BlackCard[13]);
                    }
                    else{
                        Player2_image[i].setBackgroundResource(BlackCard[Player2[i]]);
                    }
                }
            }
        }

        return;
    }


    public native void led(int a);
    public native void segment(int a);
    public native void read(int[] buf);
    public native void write(int[] buf);

}