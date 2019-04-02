#ifndef FRAKSZAL_H
#define FRAKSZAL_H

#include <QThread>
#include <cmath>
#include <complex>
#include "frakablak.h"

class FrakAblak;

class FrakSzal : public QThread
{
    Q_OBJECT

public:
    FrakSzal(double a, double b, double c, double d,
             int szelesseg, int magassag, int iteraciosHatar, FrakAblak *frakAblak);
    ~FrakSzal();
    void run();

protected:
    // A komplex s�k vizsg�lt tartom�nya [a,b]x[c,d].
    double a, b, c, d;
    // A komplex s�k vizsg�lt tartom�ny�ra fesz�tett
    // h�l� sz�less�ge �s magass�ga.
    int szelesseg, magassag;
    // Max. h�ny l�p�sig vizsg�ljuk a z_{n+1} = z_n * z_n + c iter�ci�t?
    // (tk. most a nagy�t�si pontoss�g)
    int iteraciosHatar;
    // Kinek sz�molok?
    FrakAblak* frakAblak;
    // Soronk�nt k�ld�m is neki vissza a kisz�moltakat.
    int* egySor;

};

#endif // FRAKSZAL_H
