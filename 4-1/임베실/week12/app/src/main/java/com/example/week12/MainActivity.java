package com.example.week12;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.NotificationCompat;
import androidx.core.app.NotificationManagerCompat;

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.content.Context;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {
    private final static String CHANNEL_ID = "channel_id";
    int channel_num;
    EditText title1;
    EditText content1;
    String title;
    String content;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button b1 = (Button) findViewById(R.id.Notify);
        Button b2 = (Button) findViewById(R.id.Update);
        Button b3 = (Button) findViewById(R.id.RemoveAll);



        channel_num = -1;

        createNoficationChannel();

        b1.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                channel_num  = channel_num + 1;
                title1 = (EditText) findViewById(R.id.title);
                content1 = (EditText) findViewById(R.id.contents);
                title = title1.getText().toString();
                content = content1.getText().toString();
                addNotification();
            }
        });

        b2.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                title1 = (EditText) findViewById(R.id.title);
                content1 = (EditText) findViewById(R.id.contents);
                title = title1.getText().toString();
                content = content1.getText().toString();
                addNotification();
                channel_num  = channel_num + 1;
            }
        });

        b3.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                removeNotification();
            }
        });

    }

    private void addNotification(){

        NotificationCompat.Builder builder = new NotificationCompat.Builder(this, CHANNEL_ID)
                .setSmallIcon(R.drawable.notification_icon_background)
                .setContentTitle(title)
                .setContentText(content)
                .setPriority(NotificationCompat.PRIORITY_DEFAULT);

        NotificationManager manager = (NotificationManager)getSystemService(Context.NOTIFICATION_SERVICE);
        manager.notify(channel_num, builder.build());

    }

    private void removeNotification(){
        NotificationManager manager = (NotificationManager)getSystemService(Context.NOTIFICATION_SERVICE);
        manager.cancelAll();
        channel_num = - 1;
    }

    private void createNoficationChannel(){
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O){
            CharSequence name = title;
            String description = content;
            int importance = NotificationManager.IMPORTANCE_DEFAULT;
            NotificationChannel channel = new NotificationChannel(CHANNEL_ID, name, importance);
            channel.setDescription(description);
            NotificationManager notificationManager = getSystemService(NotificationManager.class);
            notificationManager.createNotificationChannel(channel);

        }
    }


}




