# Prva zadaca iz PNMuSI - Rješsavanje nelinearnih jednačcina

1. Napisati program (u programskom jeziku po želji) za rješavanje nelinearnih jednačina koristeći metodu regula falsi. Program treba da ima minimalno sljedeće karakteristike:
a) unos granica intervala i tačnosti;  
b) provjeru ispunjenosti uslova za korištenje metode;  
c) maksimalan broj iteracija – postaviti na 150;  
d) iterativni postupak zaustaviti kad je zadovoljen jedan od dva kriterija: tačnost   (kao mjeru uzeti apsolutnu grešku uzastopnih aproksimacija) ili maksimalan broj iteracija;  
e) ispis treba da sadrži redni broj iteracije, granice segmenta s novom aproksimacijom,   vrijednost funkcije za trenutnu iteraciju, trenutnu grešku.

2. Napisati program (u programskom jeziku po želji) za rješavanje nelinearnih jednačina koristeći Newtonovu metodu i njenu modifikaciju. Program treba da ima minimalno sljedeće karakteristike:  
a) izbor metode (Newtonova ili modificirana Newtonova);  
b) unos početne aproksimacije i tačnosti;  
c) maksimalan broj iteracija – postaviti na 100;  
d) iterativni postupak zaustaviti kad je zadovoljen jedan od dva kriterija: tačnost   (kao mjeru uzeti apsolutnu grešku) ili maksimalan broj iteracija;  
e) ispis treba da sadrži redni broj iteracije, trenutnu aproksimaciju, vrijednost funkcije za trenutnu aproksimaciju, vrijednost prvog izvoda za trenutnu aproksimaciju, trenutnu grešku.

3. Napisati program (u programskom jeziku po želji) za rješavanje nelinearnih jednačina koristeći metodu proste iteracije. Program treba da ima minimalno sljedeće karakteristike:
a) unos početne aproksimacije i tačnosti;  
b) maksimalan broj iteracija – postaviti na 150;  
c) iterativni postupak zaustaviti kad je zadovoljen jedan od dva kriterija: tačnost   (kao mjeru uzeti apsolutnu grešku) ili maksimalan broj iteracija ili kada proces počnu da divergira (greška naredne iteracije je veća od prethodne);  
d) ispis treba da sadrži redni broj iteracije, trenutnu aproksimaciju, vrijednost   funkcije g(x) za trenutnu aproksimaciju, trenutnu grešku.  

4. Napisane programe testirati na nekim problemima za koja se znaju rješenja (s predavanja,   vježbi i sl.). Navesti jednačinu, ulazne podatke i rješenje s brojem iteracija.

5. Napisane programe iskoristiti za rješavanje sljedećeg inženjerskog problema:   Van der Waalsova jednačina stanja za fluide može se predstaviti u obliku  
pv³ − pbv² + av − ab = RT v²  
gdje je, p pritisak, v molarna zapremina, a i b su empirijske konstante vodika, T je   apsolutna temperatura i R je gasna konstanta. Odredi v. Iterativni proces zaustaviti kada je razlika dvije uzastopne iteracije manja od 10⁻⁶.
Podaci: R = 0.082054 [L at/(mol K)], a = 0.2476, b = 0.02661, p = 20 [at], T = 500 [K], v₀ = 10.
