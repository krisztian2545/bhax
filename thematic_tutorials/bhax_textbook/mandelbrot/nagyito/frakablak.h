#ifndef FRAKABLAK_H
#define FRAKABLAK_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include "frakszal.h"

class FrakSzal;

class FrakAblak : public QMainWindow
{
    Q_OBJECT

public:
    FrakAblak(double a = -2.0, double b = .7, double c = -1.35,
              double d = 1.35, int szelesseg = 600,
              int iteraciosHatar = 255, QWidget *parent = 0);
    ~FrakAblak();
    void vissza(int magassag , int * sor, int meret) ;
    void vissza(void) ;
    // A komplex s�k vizsg�lt tartom�nya [a,b]x[c,d].
    double a, b, c, d;
    // A komplex s�k vizsg�lt tartom�ny�ra fesz�tett
    // h�l� sz�less�ge �s magass�ga.
    int szelesseg, magassag;
    // Max. h�ny l�p�sig vizsg�ljuk a z_{n+1} = z_n * z_n + c iter�ci�t?
    // (tk. most a nagy�t�si pontoss�g)
    int iteraciosHatar;

protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void keyPressEvent(QKeyEvent*);

private:
    QImage* fraktal;
    FrakSzal* mandelbrot;
    bool szamitasFut;
    // A nagy�tand� kijel�lt ter�letet bal fels� sarka.
    int x, y;
    // A nagy�tand� kijel�lt ter�let sz�less�ge �s magass�ga.
    int mx, my;
    int savec;
};

#endif // FRAKABLAK_H
