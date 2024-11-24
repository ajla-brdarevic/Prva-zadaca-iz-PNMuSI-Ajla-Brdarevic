#include <iostream>     
#include <cmath>        
#include <iomanip>      
#include "metoda_proste_iteracije.h" 

// Funkcija g(x) koja definira iterativni postupak za aproksimaciju rješenja
// U ovom primjeru, funkcija vraća kubni korijen izraza (x + 2).
// Funkcija g mora biti tako definisana da metoda proste iteracije konvergira.
double funkcijaGProstaIteracija(double x) {
    return std::cbrt(x + 2);        // Primjer funkcije g(x)
}

// Implementacija metode proste iteracije za traženje približnog rješenja nelinearne jednačine
void metodaProsteIteracije(double pocetnaVrijednost, double tolerancija) {
    // Inicijalizacija varijabli:
    // trenutnaVrijednost - trenutna aproksimacija rješenja
    // maksimalniBrojIteracija - maksimalni broj iteracija za zaustavljanje algoritma
    // greska - apsolutna razlika između trenutne i nove vrijednosti u iteracijama
    double trenutnaVrijednost = pocetnaVrijednost;  // Početna pretpostavka
    int maksimalniBrojIteracija = 150;              // Limit iteracija
    double greska = tolerancija + 1;                // Postavljanje inicijalne greške većom od tolerancije

    // Ispis zaglavlja za tabelu rezultata
    // setw koristi se za formatiranje širine kolona
    std::cout << std::setw(12) << "Iteracija"               // Broj iteracije
        << std::setw(22) << "Trenutna vrijednost"           // Trenutna aproksimacija rješenja
        << std::setw(24) << "g(Trenutna vrijednost)"        // Vrijednost funkcije g u trenutnoj aproksimaciji
        << std::setw(22) << "Greska" << std::endl;          // Razlika između dvije uzastopne aproksimacije

    // Iterativni proces metode proste iteracije
    for (int iteracija = 0; iteracija < maksimalniBrojIteracija && greska > tolerancija; iteracija++) {
        // Korak 1: Računanje nove aproksimacije pomoću funkcije g(x)
        double novaVrijednost = funkcijaGProstaIteracija(trenutnaVrijednost);

        // Korak 2: Izračunavanje greške kao apsolutne razlike između nove i trenutne aproksimacije
        greska = std::abs(novaVrijednost - trenutnaVrijednost);

        // Korak 3: Ispis trenutnih rezultata
        std::cout << std::setw(12) << iteracija + 1               // Iteracija (počinje od 1)
            << std::setw(22) << novaVrijednost                    // Nova aproksimacija
            << std::setw(24) << funkcijaGProstaIteracija(novaVrijednost) // Vrijednost g(x) za novu aproksimaciju
            << std::setw(22) << greska << std::endl;              // Trenutna greška

        // Korak 4: Provjera da li algoritam divergirа
        if (greska > tolerancija) {
            // Ako razlika između trenutne i nove vrijednosti raste, algoritam divergirа
            if (std::abs(novaVrijednost - trenutnaVrijednost) > greska) {
                std::cout << "Greska: Detektovana divergencija algoritma.\n";
                break;      // Prekid iterativnog procesa zbog divergencije
            }
        }

        // Korak 5: Ažuriranje trenutne vrijednosti za narednu iteraciju
        trenutnaVrijednost = novaVrijednost;
    }

    // Nakon završetka iterativnog procesa:
    // Provjera da li je greška unutar zadate tolerancije
    if (greska <= tolerancija) {
        // Ispis približne vrijednosti korijena ako je metoda konvergirala
        std::cout << "\nKorijen je priblizno: " << trenutnaVrijednost << std::endl;
    }
    else {
        // Ispis greške ako algoritam nije konvergirao nakon maksimalnog broja iteracija
        std::cerr << "Greska: Metoda proste iteracije nije konvergirala nakon "
            << maksimalniBrojIteracija << " iteracija." << std::endl;
    }
}
