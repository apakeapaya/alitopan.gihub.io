package com.skripsi.doorcontrol;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.widget.TextView;

import com.airbnb.lottie.LottieAnimationView;

public class SplashScreen extends AppCompatActivity {
TextView SafeHouse;
LottieAnimationView lottieAnimationView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_splash_screen);

        lottieAnimationView = findViewById(R.id.splash);
        SafeHouse = (TextView) findViewById(R.id.safehome);

        lottieAnimationView.animate().translationY(1600).setDuration(1000).setStartDelay(4000);
        SafeHouse .animate().translationY(1600).setDuration(1000).setStartDelay(4000);

        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                finish();
                login();
            }
        },4000 );
    }

    public void login() {
        Intent intent = new Intent(SplashScreen.this, LoginActivity.class);
        startActivity(intent);
    }
}