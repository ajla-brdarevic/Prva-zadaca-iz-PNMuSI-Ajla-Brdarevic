#include <iostream>
#include "metoda_regula_falsi.h"
#include "newtonova_metoda.h"
#include "metoda_proste_iteracije.h"
#include "van_der_waals.h"

int main() {
    int izbor;      // Izbor za meni

    // Ispis opcija za izbor metode
    std::cout << "Metode:\n"
        << "1. Metoda Regula Falsi\n"
        << "2. Newtonova metoda\n"
        << "3. Metoda proste iteracije\n"
        << "4. Testiranje na poznatim problemima\n"
        << "5. Van der Waalsova jednacina\n";
    std::cin >> izbor;

    // Obrada izbora korisnika
    do {
        switch (izbor) {
        case 1: {
            double a, b, tolerancija;       // Varijable za granice intervala (a i b) i za toleranciju
            std::cout << "Metoda Regula Falsi";

            // Unos granica intervala i tolerancije za metodu Regula Falsi
            std::cout << "\nUnijeti granice intervala (u formatu: 'a b'): ";
            std::cin >> a >> b;    
            std::cout << "Unijeti toleranciju: ";
            std::cin >> tolerancija;

            // Poziv funkcije za Regula Falsi
            metodaRegulaFalsi(a, b, tolerancija);
            break;
        }
        case 2: {
            double pocetnaAproksimacija, tolerancija;       // Varijable za poèetnu aproksimaciju i toleranciju za Newton metodu
            std::cout << "Klasicna Newton metoda";

            // Unos parametara za Newtonovu metodu
            std::cout << "\nUnijeti pocetnu aproksimaciju: ";
            std::cin >> pocetnaAproksimacija;
            std::cout << "Unijeti toleranciju: ";
            std::cin >> tolerancija;

            // Poziv funkcije za Newtonovu metodu 
            newtonovaMetoda(pocetnaAproksimacija, tolerancija);
            break;
        }
        case 3: {
            double pocetnaAproksimacija, tolerancija;       // Varijable za poèetnu aproksimaciju i toleranciju za metodu proste iteracije
            std::cout << "Metoda proste iteracije";

            // Unos parametara za metodu proste iteracije
            std::cout << "\nUnijeti pocetnu aproksimaciju: ";
            std::cin >> pocetnaAproksimacija;
            std::cout << "Unijeti toleranciju: ";
            std::cin >> tolerancija;

            // Poziv funkcije za metodu proste iteracije
            metodaProsteIteracije(pocetnaAproksimacija, tolerancija);
            break;
        }
        case 4: {
            std::cout << "Rjesavanje f(x) = x^2 - 2 sa unaprijed zadanim podacima:\n";

            // Regula Falsi
            std::cout << "\nMetoda Regula Falsi:\n";
            double a = 1, b = 2, tolerancija = 0.0001;        // Interval [1, 2] i tolerancija
            metodaRegulaFalsi(a, b, tolerancija);

            // Newtonova metoda
            std::cout << "\nNewtonova metoda:\n";
            double pocetnaAproksimacijaNewton = 3;      // Poèetna aproksimacija
            newtonovaMetoda(pocetnaAproksimacijaNewton, tolerancija);

            // Metoda proste iteracije
            std::cout << "\nMetoda proste iteracije:\n";
            double pocetnaAproksimacijaIteracija = 3;       // Poèetna aproksimacija
            metodaProsteIteracije(pocetnaAproksimacijaIteracija, tolerancija);

            break;
        }
        case 5: {
            int metoda;
            std::cout << "Van der Waals\n";
            std::cout << "Odabrati metodu za rjesavanje Van der Waalsove jednaèine:\n"
                << "1. Regula Falsi\n"
                << "2. Newtonova metoda\n";
            std::cin >> metoda;

            double p, T;        // Varijable za pritisak (p) i temperaturu (T)

            // Unos parametara za Van der Waals
            std::cout << "Unijeti pritisak (p u atm): ";
            std::cin >> p;
            std::cout << "Unijeti temperaturu (T u K): ";
            std::cin >> T;

            // Metoda 1 - rješavanje Van der Waals metodom Regula Falsi
            if (metoda == 1) {
                double a, b;
                std::cout << "Unijeti granice intervala (u formatu: 'a b'): ";
                std::cin >> a >> b;
                rijesiVanDerWaalsRegulaFalsi(a, b, p, T);
            }

            // Metoda 2 - rješavanje Van der Waals Newton klasiènom metodom
            else if (metoda == 2) {
                double pocetnaAproksimacija;
                std::cout << "Unijeti pocetnu aproksimaciju: ";
                std::cin >> pocetnaAproksimacija;
                rijesiVanDerWaalsNewton(pocetnaAproksimacija, p, T);
            }
            else {
                std::cout << "Nepoznata opcija!\n";
            }
            break;
        }

        default:
            // Obrada nevažeæe opcije
            std::cout << "Nepoznata opcija!\n";
            break;
        }

        // Ponovno ispisivanje opcija za izbor metode
        std::cout << "\nMetode:\n"
            << "1. Metoda Regula Falsi\n"
            << "2. Newtonova metoda\n"
            << "3. Metoda proste iteracije\n"
            << "4. Testiranje na poznatim problemima\n"
            << "5. Van der Waalsova jednacina\n"
            << "Izlaz (0 za izlaz): ";
        std::cin >> izbor;

    } while (izbor != 0); // Izlaz iz petlje 

    return 0;
}
