package com.example.week13

import android.annotation.SuppressLint
import android.app.NotificationChannel
import android.app.NotificationManager
import android.content.Context
import android.os.Build
import android.os.Bundle
import android.view.View
import android.widget.EditText
import android.widget.RadioButton
import android.widget.Toast
import androidx.annotation.RequiresApi
import androidx.appcompat.app.AppCompatActivity
import androidx.core.app.NotificationCompat
import java.lang.String

class MainActivity : AppCompatActivity() {
    var text : EditText? = null
    var CHANNEL_ID = "channel_ID"
    var inputValue : Float? = null
    var outputValue : Float? = null

    @RequiresApi(Build.VERSION_CODES.O)
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        text = findViewById(R.id.inputValue)

        createNoficationChannel()

    }
    fun onClick(view: View) {
        when (view.getId()) {
            R.id.button1 -> {
                val celsiusButton : RadioButton = findViewById(R.id.radio0)
                val fahrenheitButton : RadioButton = findViewById(R.id.radio1)
                if (text!!.text.length == 0) {
                    Toast.makeText(
                        this, "Please enter a valid number",
                        Toast.LENGTH_LONG
                    ).show()
                    return
                }
                inputValue = text!!.text.toString().toFloat()
                if (celsiusButton.isChecked) {
                    outputValue = (inputValue!! -32) * 5 / 9
                    text!!.setText(
                        String
                            .valueOf(outputValue!!)
                    )
                    celsiusButton.isChecked = false
                    fahrenheitButton.isChecked = true
                    addNotification1()
                } else {
                    outputValue = (inputValue!! * 9 ) / 5 + 32
                    text!!.setText(
                        String
                            .valueOf(outputValue!!)
                    )
                    fahrenheitButton.isChecked = false
                    celsiusButton.isChecked = true
                    addNotification2()
                }
            }
        }
    }

    @SuppressLint("PrivateResource")
    private fun addNotification1() {
        var builder =
            NotificationCompat.Builder(this, CHANNEL_ID)
                .setSmallIcon(R.drawable.notification_icon_background)
                .setContentTitle("week13")
                .setContentText("$inputValue fahrenheit is converted to $outputValue celcius")
                .setPriority(NotificationCompat.PRIORITY_DEFAULT)
        var manager =
            getSystemService(Context.NOTIFICATION_SERVICE) as NotificationManager
        manager.notify(0, builder.build())
    }

    @SuppressLint("PrivateResource")
    private fun addNotification2() {
        var builder =
            NotificationCompat.Builder(this, CHANNEL_ID)
                .setSmallIcon(R.drawable.notification_icon_background)
                .setContentTitle("week13")
                .setContentText("$inputValue celcius is converted to $outputValue fahrenheit")
                .setPriority(NotificationCompat.PRIORITY_DEFAULT)
        var manager =
            getSystemService(Context.NOTIFICATION_SERVICE) as NotificationManager
        manager.notify(0, builder.build())
    }


    @SuppressLint("PrivateResource")
    private fun createNoficationChannel() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            val name = "week13"
            val descriptionText = "week13"
            val importance = NotificationManager.IMPORTANCE_DEFAULT
            val channel = NotificationChannel(CHANNEL_ID, name, importance)
            channel.setDescription(descriptionText)
            val notificationManager: NotificationManager =
                getSystemService(Context.NOTIFICATION_SERVICE) as NotificationManager
            notificationManager.createNotificationChannel(channel)
        }
    }


}


