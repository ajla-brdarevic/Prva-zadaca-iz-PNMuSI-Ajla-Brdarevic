#include <iostream>
#include <cmath>
#include <iomanip>

// Funkcija za izra�unavanje vrijednosti f(x)
// Ova funkcija predstavlja matematicku funkciju �iji korijen se tra�i.
// U ovom slu�aju, funkcija je f(x) = x^2 - 2.
double funkcijaNewton(double x) {
    return x * x - 2; // f(x) = x^2 - 2
}

// Funkcija za izra�unavanje izvoda f'(x)
// Ovdje se ra�una prvi izvod funkcije f(x), koji je potreban za primjenu Newtonove metode.
// Za funkciju f(x) = x^2 - 2, izvod je f'(x) = 2x.
double izvodFunkcijeNewton(double x) {
    return 2 * x; // f'(x) = 2x
}

// Ova funkcija izvodi jednu iteraciju Newtonove metode za nala�enje korijena funkcije.
// Kroz iteraciju, nova vrijednost za x se ra�una kao:
// x_novo = x - f(x) / f'(x)
// Tako�e se ra�una gre�ka izme�u trenutnog x i novog x.
double iteracijaNewton(double x, double& greska, int iteracija) {
    // Ra�una vrijednost funkcije f(x) i njenog izvoda f'(x) na trenutnoj ta�ki x
    double vrijednostFunkcije = funkcijaNewton(x);
    double vrijednostIzvoda = izvodFunkcijeNewton(x);

    // Provjera da li je izvod jednak nuli (�to bi izazvalo gre�ku pri dijeljenju)
    if (vrijednostIzvoda == 0) {
        std::cerr << "Gre�ka: Izvod funkcije je nula." << std::endl;
        return x; // Ako je izvod nula, vra�a trenutnu vrijednost x bez promjena
    }

    // Standardna Newtonova formula za novu aproksimaciju x
    double novaVrijednostX = x - (vrijednostFunkcije / vrijednostIzvoda);

    // Ra�unanje gre�ke, koja je apsolutna razlika izme�u nove i stare vrijednosti x
    greska = std::abs(novaVrijednostX - x);

    // Ispisuje rezultate za svaku iteraciju u formi tabele
    std::cout << std::setw(10) << iteracija      // Broj iteracije
        << std::setw(15) << x              // Trenutna vrijednost x
        << std::setw(15) << vrijednostFunkcije // Vrijednost funkcije f(x)
        << std::setw(15) << vrijednostIzvoda   // Vrijednost izvoda f'(x)
        << std::setw(15) << greska            // Gre�ka izme�u trenutne i nove vrijednosti x
        << std::endl;

    // Vra�a novu vrijednost x za narednu iteraciju
    return novaVrijednostX;
}

// Implementacija Newtonove metode
// Ova funkcija pokre�e cijeli iterativni proces za nala�enje korijena funkcije
void newtonovaMetoda(double pocetnaAproksimacija, double tolerancija) {
    double x = pocetnaAproksimacija;  // Po�etna aproksimacija za x
    int maksimalniBrojIteracija = 100;  // Maksimalni broj iteracija kako bi se sprije�ilo beskona�no petljanje
    double greska = tolerancija + 1;  // Po�etna gre�ka postavljena na vrijednost ve�u od tolerancije

    // Prikazuje zaglavlje tabele sa informacijama o iteracijama
    std::cout << std::fixed << std::setprecision(6);
    std::cout << std::setw(10) << "Iteracija"  // Kolona za broj iteracije
        << std::setw(15) << "x"          // Kolona za trenutnu vrijednost x
        << std::setw(15) << "f(x)"        // Kolona za vrijednost funkcije f(x)
        << std::setw(15) << "f'(x)"       // Kolona za vrijednost izvoda f'(x)
        << std::setw(15) << "Gre�ka"      // Kolona za gre�ku
        << std::endl;

    // Iterativni proces: petlja se ponavlja dok gre�ka nije manja od tolerancije
    int iteracija = 1;
    for (int i = 0; i < maksimalniBrojIteracija && greska > tolerancija; i++) {
        // Poziva funkciju za jednu iteraciju Newtonove metode
        x = iteracijaNewton(x, greska, iteracija);

        // Pove�ava broj iteracije
        iteracija++;

        // Provjerava da li je razlika izme�u novih i starih vrijednosti x manja od tolerancije
        if (greska <= tolerancija) {
            break;  // Ako gre�ka postane manja od tolerancije, izlaz iz petlje
        }
    }

    // Provjerava da li je metoda konvergirala unutar maksimalnog broja iteracija
    if (greska <= tolerancija) {
        std::cout << "\nKorijen je priblizno: " << x << std::endl;  // Ispis rezultata
    }
    else {
        std::cerr << "Gre�ka: Metoda nije konvergirala nakon "
            << maksimalniBrojIteracija << " iteracija." << std::endl;
    }
}
