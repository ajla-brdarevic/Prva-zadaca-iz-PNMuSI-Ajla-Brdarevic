#ifndef VAN_DER_WAALS_H
#define VAN_DER_WAALS_H

#include <iostream>
#include <cmath>
#include <iomanip>

// Konstante za Van der Waalsovu jednaèinu
const double R = 0.0821; // Gasna konstanta
const double a = 0.244;  // Empirijska konstanta (primjer za vodik)
const double b = 0.0266; // Empirijska konstanta (primjer za vodik)

// Prototipi funkcija za rješavanje Van der Waalsove jednaèine
double vanDerWaalsFunkcija(double v, double p, double T); // Funkcija f(v)
double vanDerWaalsIzvod(double v, double p, double T); // Derivacija f(v)
void rijesiVanDerWaalsRegulaFalsi(double a, double b, double p, double T); // Regula falsi metoda
void rijesiVanDerWaalsNewton(double pocetnaAproksimacija, double p, double T); // Newtonova metoda

#endif // VAN_DER_WAALS_H
