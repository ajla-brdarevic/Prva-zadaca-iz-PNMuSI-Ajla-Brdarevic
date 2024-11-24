#pragma once
#ifndef NEWTONOVA_METODA_H
#define NEWTONOVA_METODA_H

double funkcijaNewton(double x);

double izvodFunkcijeNewton(double x);

double iteracijaNewton(double x, double& greska);

void newtonovaMetoda(double pocetnaAproksimacija, double tolerancija);

#endif // NEWTONOVA_METODA_H
