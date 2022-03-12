package com.skripsi.doorcontrol;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.widget.Toast;

import java.util.Calendar;

import mehdi.sakout.aboutpage.AboutPage;
import mehdi.sakout.aboutpage.Element;

public class AboutAplication extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_about_aplication);

        mehdi.sakout.aboutpage.Element adsElement = new Element();
        View aboutPage = new AboutPage(this)
                .isRTL(false)
                .setDescription(" Aplikasi ini dibuat untuk menyelesaikan tugas skripsi bila ada pertanyaan lebih lanjut silahkan hubungi kontak dibawah.")
                .addItem(new Element().setTitle("Version 1.0"))
                .addGroup("Kontak")
                .addEmail("alimediaprofesi@gmail.com")
                .addPlayStore("com.skripsi.doorcontrol")   //Replace all this with your package name
                .addInstagram("topan7373")    //Your instagram id
                .addItem(createCopyright())
                .create();
        setContentView(aboutPage);
    }
    private Element createCopyright()
    {
        Element copyright = new Element();
        @SuppressLint("DefaultLocale") final String copyrightString = String.format("Copyright %d by Ali Topan", Calendar.getInstance().get(Calendar.YEAR));
        copyright.setTitle(copyrightString);
        // copyright.setIcon(R.mipmap.ic_launcher);
        copyright.setGravity(Gravity.CENTER);
        copyright.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(AboutAplication.this,copyrightString,Toast.LENGTH_SHORT).show();
            }
        });
        return copyright;
    }
}