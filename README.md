# v0.1
Pirmo uždavinio **0.1** versija atlikta dviem būdais:
1) Faile ***"v0.1.cpp"*** programa realizuota naudojant **masyvą**.

   Studentų masyvui priskirta 30 vietos atmintyje. 
   Struktūrą sudaro studento vardas, pavardė, iki 10 namų darbų ivertinimų, egzamino pažymys ir galutinis balas.
   Paleidus programą vartotojas įveda studento vardą ir pavardą, o tada gali pasirikti ar likusius duomenis įvesdinė pats, ar leis kompiuteriui sugeneruoti atsitiktinai.
   Jei duomenis pildo vartotojas, funkcijoje *pildymas* veikia saugikliai, kurie tikrina, jog ivertinimas būtų dešimtbalėje sistemoje. Jei vartotojas iveda netinkamą reikšmę - prašoma patikslinti (įvesti iš naujo). 
   Jei vartotojas pasirenka kompiuterio generavimą - automatiškai įvedami atsitiktiniai skaičiai nuo 1 iki 10.
   Tada suskaičiuojamas galutinis balas naudojant vidurkį ir medianą, o rezultatas išspausdinamas struktūrą turinčioje lentelėje.
   
2) Faile ***"v0.1vec.cpp"*** programa realizuota naudojant **std::vector**  tipo konteinerį.

   Programa analogiška, tačiau vietoje masyvo viski duomenys laikomi vektoriuje.
   Yra atsititktinio vertinimų generavimo funkcijos, tačiau jos nesusietos su main metodu ir neprieinamos vartotojui.
