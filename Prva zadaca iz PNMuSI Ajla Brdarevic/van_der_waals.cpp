#include "van_der_waals.h"

// Funkcija koja predstavlja Van der Waalsovu jedna�inu f(v)
// Parametri:
// - zapremina: zapremina (v) u jedna�ini
// - pritisak: pritisak (p)
// - temperatura: temperatura (T)
// Povratna vrijednost:
// - Vrijednost funkcije f(v) prema Van der Waalsovoj jedna�ini

double vanDerWaalsFunkcija(double zapremina, double pritisak, double temperatura) {
    // Izra�unavanje vrijednosti funkcije prema Van der Waalsovoj jedna�ini
    return pritisak * std::pow(zapremina, 3) - pritisak * b * std::pow(zapremina, 2)
        + a * zapremina - a * b - (R * temperatura) / std::pow(zapremina, 2);
}

// Funkcija koja ra�una izvod f'(v) prema Van der Waalsovoj jedna�ini
// Parametri:
// - zapremina: zapremina (v) u jedna�ini
// - pritisak: pritisak (p)
// - temperatura: temperatura (T)
// Povratna vrijednost:
// - Vrijednost izvoda funkcije f'(v)

double vanDerWaalsIzvod(double zapremina, double pritisak, double temperatura) {
    // Izra�unavanje izvoda funkcije prema Van der Waalsovoj jedna�ini
    return 3 * pritisak * std::pow(zapremina, 2) - 2 * pritisak * b * zapremina
        + a + (2 * R * temperatura) / std::pow(zapremina, 3);
}

// Metoda regula falsi za rje�enje Van der Waalsove jedna�ine
// Parametri:
// - a_parametar: po�etna donja granica intervala
// - b_parametar: po�etna gornja granica intervala
// - pritisak: pritisak (p)
// - temperatura: temperatura (T)
void rijesiVanDerWaalsRegulaFalsi(double a_parametar, double b_parametar, double pritisak, double temperatura) {
    double tolerancija = 1e-6;  // Tolerancija za prihvatljivo rje�enje
    double funkcija_a = vanDerWaalsFunkcija(a_parametar, pritisak, temperatura);
    double funkcija_b = vanDerWaalsFunkcija(b_parametar, pritisak, temperatura);

    // Provjera da li se korijen nalazi u intervalu [a, b]
    if (funkcija_a * funkcija_b > 0) {
        std::cout << "Interval nema korijen!\n";
        return;  // Ako nema korijena, izlazi iz funkcije
    }

    double c, funkcija_c;  // Ta�ka presjeka i njena funkcijska vrijednost
    int broj_iteracija = 0;
    std::cout << "Iteracija\tc\n";

    // Iteracija dok se ne postigne preciznost ili dok se ne dostigne maksimalni broj iteracija
    do {
        // Izra�unavanje nove ta�ke c koriste�i metoda regula falsi
        c = (a_parametar * funkcija_b - b_parametar * funkcija_a) / (funkcija_b - funkcija_a);
        funkcija_c = vanDerWaalsFunkcija(c, pritisak, temperatura);

        // Ispis trenutne iteracije
        std::cout << broj_iteracija << "\t\t" << c << "\n";

        // Provjera konvergencije
        if (std::fabs(funkcija_c) < tolerancija)
            break;  // Prekid ako je rje�enje dovoljno precizno

        // A�uriranje intervala na osnovu znaka funkcije
        if (funkcija_a * funkcija_c < 0) {
            b_parametar = c;
            funkcija_b = funkcija_c;
        }
        else {
            a_parametar = c;
            funkcija_a = funkcija_c;
        }

        broj_iteracija++;  // Pove�anje broja iteracija
    } while (broj_iteracija < 1000);  // Maksimalni broj iteracija

    // Ispis kona�nog rje�enja
    std::cout << "Rje�enje: zapremina v = " << c << "\n";
    std::cout << "Broj iteracija: " << broj_iteracija << "\n";
}

// Metoda Newton za rje�enje Van der Waalsove jedna�ine
// Parametri:
// - pocetnaAproksimacija: po�etna vrijednost zapremine
// - pritisak: pritisak (p)
// - temperatura: temperatura (T)

void rijesiVanDerWaalsNewton(double pocetnaAproksimacija, double pritisak, double temperatura) {
    double zapremina = pocetnaAproksimacija;  // Po�etna aproksimacija za rje�enje
    double tolerancija = 1e-6;  // Tolerancija za prihvatljivo rje�enje
    int broj_iteracija = 0;

    std::cout << "Iteracija\tv\n";

    // Iteracija dok se ne postigne preciznost ili dok se ne dostigne maksimalni broj iteracija
    while (broj_iteracija < 1000) {
        double funkcija_zapremina = vanDerWaalsFunkcija(zapremina, pritisak, temperatura);
        double izvod_zapremina = vanDerWaalsIzvod(zapremina, pritisak, temperatura);

        // Provjera da li je izvod previ�e blizu nuli
        if (std::fabs(izvod_zapremina) < 1e-12) {
            std::cout << "Izvod funkcije je previ�e blizu nuli!\n";
            return;  // Prekid ako je izvod nula
        }

        // Izra�unavanje nove vrijednosti zapremine
        double nova_zapremina = zapremina - funkcija_zapremina / izvod_zapremina;
        std::cout << broj_iteracija << "\t\t" << zapremina << "\n";

        // Provjera konvergencije
        if (std::fabs(nova_zapremina - zapremina) < tolerancija) {
            zapremina = nova_zapremina;
            break;  // Prekid ako je razlika ispod tolerancije
        }

        zapremina = nova_zapremina;  // A�uriranje zapremine za narednu iteraciju
        broj_iteracija++;
    }

    // Ispis kona�nog rje�enja
    std::cout << "Rje�enje: zapremina v = " << zapremina << "\n";
    std::cout << "Broj iteracija: " << broj_iteracija << "\n";
}
