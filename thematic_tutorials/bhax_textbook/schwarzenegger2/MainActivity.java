package com.example.krisz.rettsgiquiz;

import android.content.DialogInterface;
import android.graphics.Color;
import android.os.Environment;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Random;

public class MainActivity extends AppCompatActivity {

    ArrayList<String> al = new ArrayList<String>();
    TextView tv;
    boolean wait;
    Button b, b2, b3, b4;
    String helyes = "";
    boolean eltalalta = false;
    byte probalkozas = 0;
    int max = 290; // kérdések száma
    int pos;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        tv = (TextView)findViewById(R.id.textView);

        b = (Button)findViewById(R.id.a);
        b2 = (Button)findViewById(R.id.b);
        b3 = (Button)findViewById(R.id.c);
        b4 = (Button)findViewById(R.id.d);
        //b4.setOnClickListener(this);

        b.setBackgroundColor(Color.LTGRAY);
        b2.setBackgroundColor(Color.LTGRAY);
        b3.setBackgroundColor(Color.LTGRAY);
        b4.setBackgroundColor(Color.LTGRAY);

        beolvas();
        program();

    }

    public void kovetkezo(View view){

        if((max == 1) && eltalalta) {
            myAlert();
        } else if(eltalalta) {
            for(int i = 0; i < 5; i++) al.remove((pos * 5));
            max--;
        }

        probalkozas = 0;
        eltalalta = false;

        b.setBackgroundColor(Color.LTGRAY);
        //b.setBackgroundResource(R.);
        b2.setBackgroundColor(Color.LTGRAY);
        b3.setBackgroundColor(Color.LTGRAY);
        b4.setBackgroundColor(Color.LTGRAY);

        program();

    }

    void beolvas(){

        try {

            InputStream is = getAssets().open("fajl.txt");
            BufferedReader br = new BufferedReader(new InputStreamReader(is));

            String s;
            while((s = br.readLine()) != null){
                al.add(s);
            }
            tv.setText(al.toString());

        } catch (java.io.IOException e) {
            e.printStackTrace();
            String path = Environment.getExternalStorageDirectory().getAbsolutePath();
            AlertDialog.Builder dlgAlert  = new AlertDialog.Builder(this);
            dlgAlert.setMessage(e.getMessage().toString() + "  asd  " + path);
            dlgAlert.setTitle("App Title");
            dlgAlert.setCancelable(true);
            dlgAlert.create().show();
        }


    }

    void program(){

        Random r = new Random();
        String kerdes;
        ArrayList<String> valasz = new ArrayList<String>();

        //while(true){

            pos = r.nextInt(max);

            kerdes = al.get(pos*5);
            helyes = al.get((pos * 5)+1);
            valasz.add(helyes);
            valasz.add(al.get((pos * 5)+2));
            valasz.add(al.get((pos * 5)+3));
            valasz.add(al.get((pos * 5)+4));

            valasz = shuffle(valasz);

            tv.setText(kerdes);

            b.setText(valasz.get(0));
            b2.setText(valasz.get(1));
            b3.setText(valasz.get(2));
            b4.setText(valasz.get(3));

            wait = true;
            //while(wait){}

        //}

    }

    ArrayList<String> shuffle(ArrayList<String> b){

        ArrayList<String> a = new ArrayList<String>();
        Random r = new Random();

        for(int i = 4; i > 0; i--){

            try {
                Thread.sleep(200);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            a.add(b.get(r.nextInt(i)));
            b.remove(a.get(4-i));
        }

        return a;

    }


    public void begy(View view) {

        if(helyes.equals(b.getText())){
            ok(b);
        } else {
            nemOk(b);
        }

    }

    public void bketto(View view) {

        if(helyes.equals(b2.getText())){
            ok(b2);
        } else {
            nemOk(b2);
        }

    }

    public void bharom(View view) {

        if(helyes.equals(b3.getText())){
            ok(b3);
        } else {
            nemOk(b3);
        }

    }

    public void bnegy(View view) {

        if(helyes.equals(b4.getText())){
            ok(b4);
        } else {
            nemOk(b4);
        }

    }

    public void ok(Button bu){

        bu.setBackgroundColor(Color.GREEN);
        probalkozas++;
        if(probalkozas == 1) eltalalta = true;

    }

    public void nemOk(Button bu){

        bu.setBackgroundColor(Color.RED);
        probalkozas++;

    }

    public void myAlert(){
        AlertDialog alertDialog = new AlertDialog.Builder(MainActivity.this).create();
        alertDialog.setTitle("Vége a tesztnek.");
        alertDialog.setMessage("Elfogytak a kérdések szóval a program most hibaüzenettel leáll. Köszönjük hogy minket választott.");

        alertDialog.setButton(AlertDialog.BUTTON_NEUTRAL, "OK",
                new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int which) {
                        dialog.dismiss();
                        for(int i = 0; i < 6; i++) al.remove((pos * 5));// ez fontos!!!
                    }
                });
        alertDialog.show();
    }

}
