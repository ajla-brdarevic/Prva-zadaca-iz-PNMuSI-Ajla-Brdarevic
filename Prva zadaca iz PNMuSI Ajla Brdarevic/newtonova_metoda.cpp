#include <iostream>
#include <cmath>
#include <iomanip>

// Funkcija za izraèunavanje vrijednosti f(x)
// Ova funkcija predstavlja matematicku funkciju èiji korijen se traži.
// U ovom sluèaju, funkcija je f(x) = x^2 - 2.
double funkcijaNewton(double x) {
    return x * x - 2; // f(x) = x^2 - 2
}

// Funkcija za izraèunavanje izvoda f'(x)
// Ovdje se raèuna prvi izvod funkcije f(x), koji je potreban za primjenu Newtonove metode.
// Za funkciju f(x) = x^2 - 2, izvod je f'(x) = 2x.
double izvodFunkcijeNewton(double x) {
    return 2 * x; // f'(x) = 2x
}

// Ova funkcija izvodi jednu iteraciju Newtonove metode za nalaženje korijena funkcije.
// Kroz iteraciju, nova vrijednost za x se raèuna kao:
// x_novo = x - f(x) / f'(x)
// Takoðe se raèuna greška izmeðu trenutnog x i novog x.
double iteracijaNewton(double x, double& greska, int iteracija) {
    // Raèuna vrijednost funkcije f(x) i njenog izvoda f'(x) na trenutnoj taèki x
    double vrijednostFunkcije = funkcijaNewton(x);
    double vrijednostIzvoda = izvodFunkcijeNewton(x);

    // Provjera da li je izvod jednak nuli (što bi izazvalo grešku pri dijeljenju)
    if (vrijednostIzvoda == 0) {
        std::cerr << "Greška: Izvod funkcije je nula." << std::endl;
        return x; // Ako je izvod nula, vraæa trenutnu vrijednost x bez promjena
    }

    // Standardna Newtonova formula za novu aproksimaciju x
    double novaVrijednostX = x - (vrijednostFunkcije / vrijednostIzvoda);

    // Raèunanje greške, koja je apsolutna razlika izmeðu nove i stare vrijednosti x
    greska = std::abs(novaVrijednostX - x);

    // Ispisuje rezultate za svaku iteraciju u formi tabele
    std::cout << std::setw(10) << iteracija      // Broj iteracije
        << std::setw(15) << x              // Trenutna vrijednost x
        << std::setw(15) << vrijednostFunkcije // Vrijednost funkcije f(x)
        << std::setw(15) << vrijednostIzvoda   // Vrijednost izvoda f'(x)
        << std::setw(15) << greska            // Greška izmeðu trenutne i nove vrijednosti x
        << std::endl;

    // Vraæa novu vrijednost x za narednu iteraciju
    return novaVrijednostX;
}

// Implementacija Newtonove metode
// Ova funkcija pokreæe cijeli iterativni proces za nalaženje korijena funkcije
void newtonovaMetoda(double pocetnaAproksimacija, double tolerancija) {
    double x = pocetnaAproksimacija;  // Poèetna aproksimacija za x
    int maksimalniBrojIteracija = 100;  // Maksimalni broj iteracija kako bi se sprijeèilo beskonaèno petljanje
    double greska = tolerancija + 1;  // Poèetna greška postavljena na vrijednost veæu od tolerancije

    // Prikazuje zaglavlje tabele sa informacijama o iteracijama
    std::cout << std::fixed << std::setprecision(6);
    std::cout << std::setw(10) << "Iteracija"  // Kolona za broj iteracije
        << std::setw(15) << "x"          // Kolona za trenutnu vrijednost x
        << std::setw(15) << "f(x)"        // Kolona za vrijednost funkcije f(x)
        << std::setw(15) << "f'(x)"       // Kolona za vrijednost izvoda f'(x)
        << std::setw(15) << "Greška"      // Kolona za grešku
        << std::endl;

    // Iterativni proces: petlja se ponavlja dok greška nije manja od tolerancije
    int iteracija = 1;
    for (int i = 0; i < maksimalniBrojIteracija && greska > tolerancija; i++) {
        // Poziva funkciju za jednu iteraciju Newtonove metode
        x = iteracijaNewton(x, greska, iteracija);

        // Poveæava broj iteracije
        iteracija++;

        // Provjerava da li je razlika izmeðu novih i starih vrijednosti x manja od tolerancije
        if (greska <= tolerancija) {
            break;  // Ako greška postane manja od tolerancije, izlaz iz petlje
        }
    }

    // Provjerava da li je metoda konvergirala unutar maksimalnog broja iteracija
    if (greska <= tolerancija) {
        std::cout << "\nKorijen je priblizno: " << x << std::endl;  // Ispis rezultata
    }
    else {
        std::cerr << "Greška: Metoda nije konvergirala nakon "
            << maksimalniBrojIteracija << " iteracija." << std::endl;
    }
}
