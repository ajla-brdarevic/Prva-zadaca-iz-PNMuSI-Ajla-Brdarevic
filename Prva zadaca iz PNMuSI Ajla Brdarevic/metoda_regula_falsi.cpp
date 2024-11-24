#include <iostream>
#include <cmath>
#include <iomanip>

// Funkcija za raèunanje vrijednosti f(x)
// Ovo je funkcija èiji se korijen traži. U ovom sluèaju, traži korijen kvadratnog broja 2.
double funkcijaRegulaFalsi(double x) {
    return x * x - 2; // Kvadratni korijen od 2 je rješenje jednadžbe x^2 - 2 = 0
}

// Implementacija metode Regula Falsi
// Funkcija prima donju granicu, gornju granicu i toleranciju (maksimalno dopuštena greška).
void metodaRegulaFalsi(double donjaGranicnaVrijednost, double gornjaGranicnaVrijednost, double tolerancija) {
    // Provjera da li je metoda primjenjiva na danom intervalu
    // Metoda zahtijeva da funkcija ima razlièite predznake na krajevima intervala
    if (funkcijaRegulaFalsi(donjaGranicnaVrijednost) * funkcijaRegulaFalsi(gornjaGranicnaVrijednost) >= 0) {
        std::cout << "Greska: Metoda Regula Falsi nije primjenjiva na ovom intervalu.\n";
        return; // Prekid funkcije ako uvjet nije zadovoljen
    }

    // Inicijalizacija varijabli za proces iteracije
    double srednjaVrijednost = gornjaGranicnaVrijednost; // Poèetna aproksimacija
    double prethodnaVrijednost = srednjaVrijednost;      // Èuva prethodnu vrijednost za raèunanje greške
    double greska = tolerancija + 1;                     // Poèetna greška postavljena na vrijednost veæu od tolerancije
    int maksimalniBrojIteracija = 150;                   // Maksimalni broj dozvoljenih iteracija

    // Ispis zaglavlja tabele za prikaz rezultata po iteracijama
    std::cout << std::setw(12) << "Iteracija"
        << std::setw(18) << "Donja granica"
        << std::setw(18) << "Gornja granica"
        << std::setw(22) << "Srednja vrijednost"
        << std::setw(25) << "f(Srednja vrijednost)"
        << std::setw(15) << "Greska" << std::endl;

    // Glavna petlja za iterativni proces metode Regula Falsi
    for (int iteracija = 0; iteracija < maksimalniBrojIteracija && greska > tolerancija; iteracija++) {
        // Izraèunavanje srednje vrijednosti pomoæu formule Regula Falsi
        srednjaVrijednost = gornjaGranicnaVrijednost
            - (funkcijaRegulaFalsi(gornjaGranicnaVrijednost) * (gornjaGranicnaVrijednost - donjaGranicnaVrijednost))
            / (funkcijaRegulaFalsi(gornjaGranicnaVrijednost) - funkcijaRegulaFalsi(donjaGranicnaVrijednost));

        // Raèunanje greške kao razlike trenutne i prethodne srednje vrijednosti
        greska = std::abs(srednjaVrijednost - prethodnaVrijednost);

        // Ispis trenutnih vrijednosti iteracije u tabelarnom obliku
        std::cout << std::setw(12) << iteracija + 1
            << std::setw(18) << donjaGranicnaVrijednost
            << std::setw(18) << gornjaGranicnaVrijednost
            << std::setw(22) << srednjaVrijednost
            << std::setw(25) << funkcijaRegulaFalsi(srednjaVrijednost)
            << std::setw(15) << greska << std::endl;

        // Ažuriranje intervala na osnovu predznaka funkcije u srednjoj vrijednosti
        if (funkcijaRegulaFalsi(srednjaVrijednost) * funkcijaRegulaFalsi(donjaGranicnaVrijednost) < 0) {
            gornjaGranicnaVrijednost = srednjaVrijednost; // Srednja vrijednost postaje nova gornja granica
        }
        else {
            donjaGranicnaVrijednost = srednjaVrijednost; // Srednja vrijednost postaje nova donja granica
        }

        // Spremanje trenutne srednje vrijednosti za usporedbu u sljedeæoj iteraciji
        prethodnaVrijednost = srednjaVrijednost;
    }

    // Provjera je li metoda konvergirala unutar dozvoljene greške i iteracija
    if (greska <= tolerancija) {
        // Ako je greška manja ili jednaka toleranciji, korijen je pronaðen
        std::cout << "\nKorijen je priblizno: " << srednjaVrijednost << std::endl;
    }
    else {
        // Ako metoda nije konvergirala, prikazuje se poruka o grešci
        std::cerr << "Greska: Metoda Regula Falsi nije konvergirala nakon "
            << maksimalniBrojIteracija << " iteracija." << std::endl;
    }
}
