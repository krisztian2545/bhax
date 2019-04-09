#ifndef SEJTABLAK_H
#define SEJTABLAK_H

#include <QMainWindow>
#include <QPainter>
#include "sejtszal.h"

class SejtSzal;

class SejtAblak : public QMainWindow
{
  Q_OBJECT
  
public:
  SejtAblak(int szelesseg = 100, int magassag = 75, QWidget *parent = 0);

  ~SejtAblak();
  // Egy sejt lehet l
  static const bool ELO = true;
  // vagy halott
  static const bool HALOTT = false;
  void vissza(int racsIndex);
  
protected:
  // Kt rcsot hasznlunk majd, az egyik a sejttr llapott
  // a t_n, a msik a t_n+1 idpillanatban jellemzi.
  bool ***racsok;
  // Valamelyik rcsra mutat, technikai jelleg, hogy ne kelljen a
  // [2][][]-bl az els dimenzit hasznlni, mert vagy az egyikre
  // lltjuk, vagy a msikra.
  bool **racs;
  // Megmutatja melyik rcs az aktulis: [rcsIndex][][]
  int racsIndex;
  // Pixelben egy cella adatai.
  int cellaSzelesseg;
  int cellaMagassag;
  // A sejttr nagysga, azaz hnyszor hny cella van?
  int szelesseg;
  int magassag;    
  void paintEvent(QPaintEvent*);
  void siklo(bool **racs, int x, int y);
  void sikloKilovo(bool **racs, int x, int y);
  
private:
  SejtSzal* eletjatek;
  
};

#endif // SEJTABLAK_H
