#include "van_der_waals.h"

// Funkcija koja predstavlja Van der Waalsovu jednaèinu f(v)
// Parametri:
// - zapremina: zapremina (v) u jednaèini
// - pritisak: pritisak (p)
// - temperatura: temperatura (T)
// Povratna vrijednost:
// - Vrijednost funkcije f(v) prema Van der Waalsovoj jednaèini

double vanDerWaalsFunkcija(double zapremina, double pritisak, double temperatura) {
    // Izraèunavanje vrijednosti funkcije prema Van der Waalsovoj jednaèini
    return pritisak * std::pow(zapremina, 3) - pritisak * b * std::pow(zapremina, 2)
        + a * zapremina - a * b - (R * temperatura) / std::pow(zapremina, 2);
}

// Funkcija koja raèuna izvod f'(v) prema Van der Waalsovoj jednaèini
// Parametri:
// - zapremina: zapremina (v) u jednaèini
// - pritisak: pritisak (p)
// - temperatura: temperatura (T)
// Povratna vrijednost:
// - Vrijednost izvoda funkcije f'(v)

double vanDerWaalsIzvod(double zapremina, double pritisak, double temperatura) {
    // Izraèunavanje izvoda funkcije prema Van der Waalsovoj jednaèini
    return 3 * pritisak * std::pow(zapremina, 2) - 2 * pritisak * b * zapremina
        + a + (2 * R * temperatura) / std::pow(zapremina, 3);
}

// Metoda regula falsi za rješenje Van der Waalsove jednaèine
// Parametri:
// - a_parametar: poèetna donja granica intervala
// - b_parametar: poèetna gornja granica intervala
// - pritisak: pritisak (p)
// - temperatura: temperatura (T)
void rijesiVanDerWaalsRegulaFalsi(double a_parametar, double b_parametar, double pritisak, double temperatura) {
    double tolerancija = 1e-6;  // Tolerancija za prihvatljivo rješenje
    double funkcija_a = vanDerWaalsFunkcija(a_parametar, pritisak, temperatura);
    double funkcija_b = vanDerWaalsFunkcija(b_parametar, pritisak, temperatura);

    // Provjera da li se korijen nalazi u intervalu [a, b]
    if (funkcija_a * funkcija_b > 0) {
        std::cout << "Interval nema korijen!\n";
        return;  // Ako nema korijena, izlazi iz funkcije
    }

    double c, funkcija_c;  // Taèka presjeka i njena funkcijska vrijednost
    int broj_iteracija = 0;
    std::cout << "Iteracija\tc\n";

    // Iteracija dok se ne postigne preciznost ili dok se ne dostigne maksimalni broj iteracija
    do {
        // Izraèunavanje nove taèke c koristeæi metoda regula falsi
        c = (a_parametar * funkcija_b - b_parametar * funkcija_a) / (funkcija_b - funkcija_a);
        funkcija_c = vanDerWaalsFunkcija(c, pritisak, temperatura);

        // Ispis trenutne iteracije
        std::cout << broj_iteracija << "\t\t" << c << "\n";

        // Provjera konvergencije
        if (std::fabs(funkcija_c) < tolerancija)
            break;  // Prekid ako je rješenje dovoljno precizno

        // Auriranje intervala na osnovu znaka funkcije
        if (funkcija_a * funkcija_c < 0) {
            b_parametar = c;
            funkcija_b = funkcija_c;
        }
        else {
            a_parametar = c;
            funkcija_a = funkcija_c;
        }

        broj_iteracija++;  // Poveæanje broja iteracija
    } while (broj_iteracija < 1000);  // Maksimalni broj iteracija

    // Ispis konaènog rješenja
    std::cout << "Rješenje: zapremina v = " << c << "\n";
    std::cout << "Broj iteracija: " << broj_iteracija << "\n";
}

// Metoda Newton za rješenje Van der Waalsove jednaèine
// Parametri:
// - pocetnaAproksimacija: poèetna vrijednost zapremine
// - pritisak: pritisak (p)
// - temperatura: temperatura (T)

void rijesiVanDerWaalsNewton(double pocetnaAproksimacija, double pritisak, double temperatura) {
    double zapremina = pocetnaAproksimacija;  // Poèetna aproksimacija za rješenje
    double tolerancija = 1e-6;  // Tolerancija za prihvatljivo rješenje
    int broj_iteracija = 0;

    std::cout << "Iteracija\tv\n";

    // Iteracija dok se ne postigne preciznost ili dok se ne dostigne maksimalni broj iteracija
    while (broj_iteracija < 1000) {
        double funkcija_zapremina = vanDerWaalsFunkcija(zapremina, pritisak, temperatura);
        double izvod_zapremina = vanDerWaalsIzvod(zapremina, pritisak, temperatura);

        // Provjera da li je izvod previše blizu nuli
        if (std::fabs(izvod_zapremina) < 1e-12) {
            std::cout << "Izvod funkcije je previše blizu nuli!\n";
            return;  // Prekid ako je izvod nula
        }

        // Izraèunavanje nove vrijednosti zapremine
        double nova_zapremina = zapremina - funkcija_zapremina / izvod_zapremina;
        std::cout << broj_iteracija << "\t\t" << zapremina << "\n";

        // Provjera konvergencije
        if (std::fabs(nova_zapremina - zapremina) < tolerancija) {
            zapremina = nova_zapremina;
            break;  // Prekid ako je razlika ispod tolerancije
        }

        zapremina = nova_zapremina;  // Auriranje zapremine za narednu iteraciju
        broj_iteracija++;
    }

    // Ispis konaènog rješenja
    std::cout << "Rješenje: zapremina v = " << zapremina << "\n";
    std::cout << "Broj iteracija: " << broj_iteracija << "\n";
}
