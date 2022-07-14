#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;


class Gracz
{
private:

   int money=150;
   int licznik_wygrana = 0;

 friend void licz_wygrania(Gracz&);
 friend void wygrana(Gracz&);
 friend void pieniadze_na_start(Gracz&);
 friend void wczytanie_pieniedzy(Gracz&);
 friend void licz_wygrania_suma(Gracz&);
public:
//    virtual void oblicz_ile_kart()=0;
    int suma_kart=0;
    string nazwa;
    int karty_gracz[100];
    int black = 0;
    int saldo_a = 0;
    int stawka_a = 0;
    int stawka_a_i = 0;

Gracz(string n, int s_kart, int m, int s, int s_a, int s_i)
{
    nazwa = n; suma_kart = s_kart; money = m; saldo_a = s; stawka_a = s_a; stawka_a_i = s_i;
}

~Gracz()
{

}

void wczytanie_pieniedzy(int a)
{
    this -> money = a;
}


int ile_wygran()
{
    return this -> licznik_wygrana;
}

void licz_wygrania(int a)
{
    this -> licznik_wygrana = a;
}

void licz_wygrania_suma()
{
    this -> licznik_wygrana = this -> licznik_wygrana + 1;
}


void pieniadze_na_start()
{
    this -> money = 150;
}

int ile_pieniadze()
{
    return this -> money;
}

void domyslne()
{
     this -> money = 150;
     this -> licznik_wygrana = 0;
     this -> saldo_a = 0;
     this -> stawka_a = 0;
     this -> stawka_a_i = 0;
}

 void wygrana(int a)
 {
    this -> money = money + a*2;
 }

  void przegrana(int a)
 {
    this -> money = money - a;
 }

  void remis(int a)
 {
    this -> money = money + a;
 }

 void wyswietl_nazwe()
 {
     cout << this -> nazwa;
 }

 void wyswietl_pieniadze()
 {
     cout << this -> money;
 }

 void dodaj_karte(int a, int b)
 {
     this -> karty_gracz[b] = a;
 }

 void wyswietl_sume_kart()
 {
     cout << this -> suma_kart;
 }

 void wyswietl_karty(int b)
 {
     for(int i=0; i<b; i++)
     {
           if(this -> karty_gracz[i] == 11)
        cout << "W ";
        else if(this -> karty_gracz[i] == 12)
        cout << "D ";
        else if(this -> karty_gracz[i] == 13)
        cout << "K ";
        else if(this -> karty_gracz[i] == 14)
        cout << "AS ";
        else cout << this -> karty_gracz[i] << " ";
     }
 }

void sumuj_karty(int b)
{
         if(this -> karty_gracz[b] == 11)
            this -> suma_kart = this -> suma_kart + 10;
         else if(this -> karty_gracz[b] == 12)
            this -> suma_kart = this -> suma_kart + 10;
         else if(this -> karty_gracz[b] == 13)
            this -> suma_kart = this -> suma_kart + 10;
         else if(this -> karty_gracz[b] == 14)
            this -> suma_kart = this -> suma_kart + 11;
         else this -> suma_kart = this -> suma_kart + this -> karty_gracz[b];
}

void wyswietl_wszystko_gracz(int b, int c)
{
            system( "cls" );
          cout << "                            BLACKJACK" << endl;
          cout << endl;
          cout << "Gracz 1: ";
          this -> wyswietl_nazwe();
          cout << endl;
          cout << "Saldo: ";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
          this ->wyswietl_pieniadze();
          cout << "$";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
          cout << endl;
          cout << "Stawka: ";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
          cout << c;
          cout << "$";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
          cout << endl;
          cout << "Karty: ";
          this -> wyswietl_karty(b);
          cout << endl;
          cout << "Suma kart: ";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
          this -> wyswietl_sume_kart();
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

void wyswietl_wszystko_krupier(int krupier_licznik)
{
          cout << "                                                     KRUPIER" << endl;
          cout << "                                                        Karty: ";
          this -> wyswietl_karty(krupier_licznik);
          cout << endl;
          cout << "                                                        Suma kart: ";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
          this -> wyswietl_sume_kart();
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
          cout << endl;
          cout << endl;
}

void wyswietl_zaklady_gracz(int b)
{
              cout << "                            BLACKJACK";
          cout <<"                                         UKONCZ ABY WYGRAC: " << endl;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
          cout << endl;
          cout << "Gracz: ";
          this -> wyswietl_nazwe();
          cout << "                                                                ";
           if(this -> ile_wygran() == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                cout << "1.Wygraj raz: 0/1";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            }else if(this ->ile_wygran() >= 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
                cout << "1.Wygraj raz: 1/1";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            }
          cout << endl;
          cout << "Saldo: ";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
          wyswietl_pieniadze();
          cout << "$";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

          if(this -> ile_wygran() <10)
            {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            cout << "                                                                2.Wygraj 10 razy: ";
            cout << this -> ile_wygran();
            cout <<"/10";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            }else if(this -> ile_wygran() == 10)
            {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            cout << "                                                                2.Wygraj 10 razy: ";
            cout << this -> ile_wygran();
            cout <<"/10";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            }

          cout << endl;
          cout << "Karty: ";
          this ->wyswietl_karty(b);

          if(this -> saldo_a == 0 )
            {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            cout << "                                                         3.Uzyskaj saldo rowne 10000$ lub wiecej: ";
            cout << money;
            cout <<"/10000";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            }
          else if(this -> saldo_a >= 1)
            {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            cout << "                                                          3.Uzyskaj saldo rowne 10000$ lub wiecej";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            this -> saldo_a++;
            }


          cout << endl;
          cout << "                                                     KRUPIER   ";
          if(this -> stawka_a < 7500)
            {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            cout << "        4.Wygraj lacznie 7500$: ";
            cout << stawka_a;
            cout <<"/7500";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            }
          else if(this -> stawka_a_i >= 1)
            {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            cout << "        4.Wygraj lacznie 7500$ ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            }
            cout << endl;

}

void wyswietl_zaklady_krupier_dobra(int krupier_licznik)
{
          cout << "                                               Karty: ";
          this -> wyswietl_karty(krupier_licznik);
          cout << endl;
          cout << endl;
          cout << "Ile chcesz obstawic? /wpisz save aby zapisac progres";
          cout << endl;
          cout << ": ";
}

void wyswietl_zaklady_krupier_dobra_1(int krupier_licznik)
{
          cout << "                                               Karty: ";
          this -> wyswietl_karty(krupier_licznik);
          cout << endl;
          cout << endl;
          cout << "Ile chcesz obstawic?";
          cout << endl;
          cout << ": ";
}


void wyswietl_zaklady_krupier_zla(int krupier_licznik)
{
          cout << "                                               Karty: ";
          this -> wyswietl_karty(krupier_licznik);
          cout << endl;
          cout << endl;
          cout << "Ile chcesz obstawic? Kwota poczatkowa to 150$";
          cout << endl;
          cout << ": BLEDNE DANE";
}

void wyswietl_wszystko_gracze_2(int b, int c)
{
          cout << endl;
          cout << "Gracz 2: ";
          this -> wyswietl_nazwe();
          cout << endl;
          cout << "Saldo: ";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
          this -> wyswietl_pieniadze();
          cout << "$";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
          cout << endl;
          cout << "Stawka: ";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
          cout << c;
          cout << "$";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
          cout << endl;
          cout << "Karty: ";
          this -> wyswietl_karty(b);
          cout << endl;
          cout << "Suma kart: ";
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
          this -> wyswietl_sume_kart();
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}


};

int main()
{
    HANDLE hOut;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    srand(time(NULL));
    string n;
    int v=0;

    do{
    do{

    cout << "                                    WITAJ W GRZE BLACKJACK, MILEJ ZABAWY!" << endl;
    cout << endl;
    cout << "ZEBY POZNAC ZASADY GRY WPISZ 1: " << endl;
    cout << endl;
    cout << "ZEBY WYBRAC ILOSC GRACZY WPISZ 2: " << endl;
    cout << endl;
    cout << "Zalecane granie w konsoli o rozmiarze okna 120|30 i rozmiarze buforu 120|9001 w okienku!";
    cout << endl;

    cout <<": ";
    cin >> n;
     if(n=="1")
     {                                      // ZASADY
        system( "cls" );
        cout << "                                   GRA W BLACKJACK - zasady" << endl;
        cout << endl;
        cout << "1. Zadaniem gracza jest uzyskac jak najblizej (ale nie wiecej niz) 21 punktow.\nNajwyzszym ukladem kart jest tzw. Blackjack, czyli as i 10 lub figura, za ktory gracz dostaje 150% zakladu";
        cout << endl<< endl;
        cout << "                                   PUNKTACJA KART" << endl;
        cout << endl;
        cout << "1. Karty od dwojki do dziesiatki maja wartosc rowna numerowi karty. ";
        cout << endl;
        cout << " Walet - W, \n Dama - D \n Krol - K \n Maja wartosc rowna 10 punktow \n As ma wartosc rowna 11.";
        cout << endl<< endl;
        cout << "2. W Blackjacka gra sie przeciwko krupierowi. Gracz stawia zaklad na specjalnym stole uzywajac zetonow.\nNastepnie gracz i krupier dostaja po dwie karty. Obydwie karty gracza sa odkryte,\nnatomiast tylko jedna karta krupiera jest pokazana graczowi. Gracz teraz mo¿e podjac decyzje o swoim nastepnym ruchu.\nGracz ma nastepujace mozliwosci:";
        cout << endl<< endl;
        cout << " HIT -> dobranie karty, aby uzyskac wynik zblizony do 21 \n STAND -> brak ruchu, jesli karty osiagaja wynik zblizony do 21\n DOUBLE DOWN -> podwojenie stawki(mozliwe przy dwoch kartach)";
        cout << endl<< endl;
        cout << "                                   ZASADY DLA KRUPIERA" << endl;
        cout << endl;
        cout << "Jesli krupier ma 16 punktow lub mniej, dobiera kolejna karte. \nJesli krupier ma 17 punktow lub wiecej, wykonuje stand.";
        cout << endl<< endl;
        cout << "Wpisz 1 aby wrocic do menu glownego: ";
        cin >> n;
        system( "cls" );
     }
     else if(n!="1" && n!="2"){
        system( "cls" );
        cout << "                                    WITAJ W GRZE BLACKJACK, MILEJ ZABAWY!" << endl;
        cout << endl;
        cout << "ZEBY POZNAC ZASADY GRY WPISZ 1: " << endl;
        cout << endl;
        cout << "ZEBY WYBRAC ILOSC GRACZY WPISZ 2: " << endl;
        cout << endl;
        cout << "Zalecane granie w konsoli o rozmiarze okna 120|30 i rozmiarze buforu 120|9001 w okienku!";
        cout << endl;

        cout <<": NIEPOPRAWNE DANE ";
        sleep(2);
        system( "cls" );
      }
      else if(n=="2")
      break;

    }while(n=="1" || (n!="1" && n!="2"));
      int m;






     while(m=2137)
     {                      // WYBOR ILU GRACZY
            system( "cls" );
            cout << "                                       WYBIERZ ILU GRACZY" << endl;
            cout << endl;
            cout << "np. 1,2 max 2";
            cout << endl;
            cout << ": ";
            cin >> m;
            if(m==1||m==2)
            {
                break;
            }
            else
            {
            system( "cls" );
            cout << "                                       WYBIERZ ILU GRACZY" << endl;
            cout << endl;
            cout << "np. 1,2 max 2";
            cout << endl;
            cout << ": NIEPOPRAWNE DANE ";
            sleep(2);
            }
     }

     int licznik_dobran=0;
     string n,p;
     string k = "Krupier";
     string wczyt;

        Gracz krupier(k,0,0,0,0,0);

               string linia, nazwa1,op;
                int nr_linii = 1;
                int pieniadze1;
                int saldo_aa, stawka_aa, stawka_ai, wygrane1;
                int czy;


        if(m==1){
            fstream plik;
            cout << "Podaj nazwe " << 1 << " gracza: ";
            cin >>n;
            system( "cls" );

            cout << "           CZY CHCESZ WCZYTAJ SWOJA ROZGRYWKE? t/n";
            cout << endl;
            cout << ": ";
            cin >> wczyt;
            if(wczyt == "t")
            {
                plik.open("blacjack_save.txt", ios::in);
                if(plik.good() == false)
                {
            system( "cls" );
            cout << "           CZY CHCESZ WCZYTAJ SWOJA OSTATNIA ROZGRYWKE? t/n";
            cout << endl;
            cout << ": NIE POSIADASZ SAVE'a";
            sleep(2);
            system( "cls" );
                }else{
                    czy = 1;
              while(getline(plik, linia))
              {
                  switch(nr_linii)
                  {
                      case 1: nazwa1 = linia; break;
                      case 2: pieniadze1 = atoi(linia.c_str()); break;
                      case 3: wygrane1 = atoi(linia.c_str()); break;
                      case 4: wygrane1 = atoi(linia.c_str()); break;
                      case 5: saldo_aa = atoi(linia.c_str()); break;
                      case 6: stawka_ai = atoi(linia.c_str()); break;
                      case 7: stawka_aa = atoi(linia.c_str()); break;
                  }
                  nr_linii++;
              }
              }
            }
            plik.close();
        }
        if(m==2)
        {
            cout << "Podaj nazwe " << 1 << " gracza: ";
            cin >> n;
            Gracz g1(n,0,150,0,0,0);
            cout << endl;
            cout << "Podaj nazwe " << 2 << " gracza: ";
            cin >> p;
            Gracz g2(p,0,150,0,0,0);
        }

        system( "cls" );
        int l;
        Gracz g1(n,0,150,0,0,0);
        Gracz g2(p,0,150,0,0,0);

        Gracz g(n,0,150,0,0,0);

        if(czy == 1)
        {
            g.nazwa = nazwa1;
            g.wczytanie_pieniedzy(pieniadze1);
            g.licz_wygrania(wygrane1);
            g.saldo_a = saldo_aa;
            g.stawka_a = stawka_aa;
            g.stawka_a_i = stawka_ai;
        }
        do{

         int b,c,d = 0;
          int krupier_licznik = 0;
          int suma_krupier=0;
          int suma_kart_gracz = 0;
            int stawka, wybor, wybor_1, wybor_2;
        if(m == 1)
        {
            system( "cls" );
            g.suma_kart = 0;
            krupier.suma_kart = 0;

            if(g.ile_pieniadze() <=0)
            {
            int t;
            cout << "                              BANKRUT!" << endl << endl;

            cout << "WPISZ 0 ABY ZACZAC NOWA ROZGRYWKE" << endl;
            cout <<"WPISZ 1 ABY WROCIC DO MENU GLOWNEGO\nWPISZ 2 ABY WCZYTAJ GRE: ";
            cin >> t;
            if(t==0)
            {
             g.pieniadze_na_start();
             g.licz_wygrania(0);
             g.saldo_a = 0;
             g.stawka_a = 0;
             g.stawka_a_i = 0;
             continue;
            }
            if(t==1)
            {
             g.licz_wygrania(0);
             g.saldo_a = 0;
             g.stawka_a = 0;
             g.stawka_a_i = 0;
            system( "cls" );
                break;
            }
            if(t==2)
            {
                fstream plik;
                plik.open("blacjack_save.txt", ios::in);
                if(plik.good() == false)
                {
            system( "cls" );
            cout << "           CZY CHCESZ WCZYTAJ SWOJA OSTATNIA ROZGRYWKE? t/n";
            cout << endl;
            cout << ": NIE POSIADASZ SAVE'a";
            sleep(2);
            system( "cls" );
                break;
                }else{
                    nr_linii = 1;
              while(getline(plik, linia))
              {
                  switch(nr_linii)
                  {
                      case 1: nazwa1 = linia; break;
                      case 2: pieniadze1 = atoi(linia.c_str()); break;
                      case 3: wygrane1 = atoi(linia.c_str()); break;
                      case 4: wygrane1 = atoi(linia.c_str()); break;
                      case 5: saldo_aa = atoi(linia.c_str()); break;
                      case 6: stawka_ai = atoi(linia.c_str()); break;
                      case 7: stawka_aa = atoi(linia.c_str()); break;
                  }
                  nr_linii++;
              }
              }

            g.nazwa = nazwa1;
            g.wczytanie_pieniedzy(pieniadze1);
            g.licz_wygrania(wygrane1);
            g.saldo_a = saldo_aa;
            g.stawka_a = stawka_aa;
            g.stawka_a_i = stawka_ai;
            plik.close();
                continue;
            }
            else
            {
            system( "cls" );
            cout << "                              BANKRUT!" << endl << endl;

            cout << "WPISZ 1 ABY ZACZAC NOWA ROZGRYWKE" << endl;
            cout <<"WPISZ 0 ABY WROCIC DO MENU GLOWNEGO\nWPISZ 2 ABY WCZYTAJ GRE\n: BLEDNE DANE";
                sleep(2);
            continue;
            }
            }

            if(g.ile_wygran() >=10 && g.saldo_a>=1 && g.stawka_a_i >=1)
            {
                system( "cls" );
                cout <<"                          WYGRALES!! GRATULACJE!!";
                sleep(2);
                system( "cls" );
                cout <<"                          WYGRALES!  GRATULACJE!";
                sleep(2);
                system( "cls" );
                cout <<"                          WYGRALES!! GRATULACJE!!";
                sleep(2);
                system( "cls" );
                 break;
            }


            do{

            if(g.ile_pieniadze() >= 10000)
            {
                g.saldo_a++;
            }

            if(g.stawka_a >= 7500)
            {
                g.stawka_a_i++;
            }
           b=0;
          string sta;                               // WYSWIETLA ZAKLADY
            system( "cls" );
          g.wyswietl_zaklady_gracz(b);
          krupier.wyswietl_zaklady_krupier_dobra(krupier_licznik);
          cin >> sta;

        if(sta == "save")
        {
          fstream plik;
          plik.open("blacjack_save.txt", ios::out);
          plik << g.nazwa << endl;
          plik << g.ile_pieniadze() << endl;
          plik << g.ile_wygran() << endl;
          plik << g.ile_wygran() << endl;
          plik << g.saldo_a << endl;
          plik << g.stawka_a_i << endl;
          plik << g.stawka_a << endl;
          plik.close();
        }

      stawka = atoi(sta.c_str());

      if(stawka<=g.ile_pieniadze() && stawka > 0)
      {
        g.przegrana(stawka);
        break;
      }
      else if(sta == "save")
      {
          system( "cls" );
          g.wyswietl_zaklady_gracz(b);
          krupier.wyswietl_zaklady_krupier_dobra(krupier_licznik);
          cout << "ZAPISANO POSTEP";
          sleep(1);
      }
        else
       {

        system( "cls" );
            g.wyswietl_zaklady_gracz(b);
            krupier.wyswietl_zaklady_krupier_zla(krupier_licznik);
          sleep(2);
      continue;
      }
            }while(stawka=-2137);

         g.black = 0;
  for(int i=0; i<2;i++)
  {

        int k = rand()%13+2;
        g.dodaj_karte(k,b);
        b++;
        g.sumuj_karty(b-1);

        if(k==14)
        {
            g.black = g.black + 1;
        }

  }


          int o = rand()%13+2;
          krupier.dodaj_karte(o,krupier_licznik);
          krupier_licznik++;
          krupier.sumuj_karty(krupier_licznik-1);


          int x=0;
          int z=0;
          int y=0;
          int q=0;

       do{
              g.wyswietl_wszystko_gracz(b,stawka);
              krupier.wyswietl_wszystko_krupier(krupier_licznik);

            if(g.black == 1 && g.suma_kart == 21)
            {                       // WYGRANA
                sleep(1);
                cout << "                       WYGRANA!!!" << endl;
                g.wygrana(stawka);
                sleep(3);
                system( "cls" );
                g.licz_wygrania_suma();
                g.black=0;
                g.stawka_a = g.stawka_a + stawka;
                g.black =0;
                 break;
            }


            if(g.black == 2)
            {
                g.suma_kart = 12;
            }

            if(((krupier.suma_kart >= 17 && krupier.suma_kart <= 21) && ((g.suma_kart > krupier.suma_kart) && g.suma_kart <= 21)) || krupier.suma_kart > 21)
            {
                sleep(1);
                cout << "                       WYGRANA!!!" << endl;
                g.wygrana(stawka);
                sleep(3);
                system( "cls" );
                g.licz_wygrania_suma();
                g.stawka_a = g.stawka_a + stawka;
                 break;
            }

                                    // REMIS
            if((krupier.suma_kart == 21 && g.suma_kart == 21) || (krupier.suma_kart == 17 && g.suma_kart == 17) || (krupier.suma_kart == 18 && g.suma_kart == 18) ||
               (krupier.suma_kart == 19 && g.suma_kart == 19) || (krupier.suma_kart == 20 && g.suma_kart == 20))
              {
                  sleep(1);
                 cout << "                      REMIS!";
                 g.remis(stawka);
                 sleep(3);
                 system( "cls" );
                 break;
              }

                                    // PRZEGRANA
            if(((y!=0) && (krupier.suma_kart > g.suma_kart) && krupier.suma_kart<=21) || (g.suma_kart > 21))
              {
                 if(g.suma_kart < krupier.suma_kart && q!=1){
                    cout << "kupka";
                 }else{
                 sleep(1);
                 cout << "                      PRZEGRANA :(";
                 sleep(3);
                 system( "cls" );
                 break;
                 }

              }

          cout << "Aby dobrac karte wpisz 1: " << endl;
          cout << "Aby wstrzymac sie wpisz 2: " << endl;
          cout << "Aby podwoic swoj zaklad wpisz 3 \(mozliwe przy dwoch kartach): " << endl;
          cout << ": ";
          cin >> wybor;
            if(wybor == 1 && x>=0)
            {
            int k = rand()%13+2;
            g.dodaj_karte(k,b);
            b++;
            g.sumuj_karty(b-1);
            z++;
            y++;

            }
            if(wybor == 2)
            {
                y++;
                q++;
              do{
              if(((krupier.suma_kart >= 17 && krupier.suma_kart <= 21) && ((g.suma_kart > krupier.suma_kart) && g.suma_kart <= 21)) || krupier.suma_kart > 21)
            {
                system( "cls" );
                 break;
                 x=10;
            }if(x==10) break;

            if((krupier.suma_kart == 21 && g.suma_kart == 21) || (krupier.suma_kart == 17 && g.suma_kart == 17) || (krupier.suma_kart == 18 && g.suma_kart == 18) ||
               (krupier.suma_kart == 19 && g.suma_kart == 19) || (krupier.suma_kart == 20 && g.suma_kart == 20))
              {
                 system( "cls" );
                 x=10;
                 break;
              }
              if(krupier.suma_kart <=16)
              {
              system( "cls" );
              g.wyswietl_wszystko_gracz(b,stawka);
              krupier.wyswietl_wszystko_krupier(krupier_licznik);

                int o = rand()%13+2;
                krupier.dodaj_karte(o,krupier_licznik);
                krupier_licznik++;
                krupier.sumuj_karty(krupier_licznik-1);

               sleep(1);

              }
              if(( krupier.suma_kart > g.suma_kart) || (g.suma_kart > 21))
              {
                 system( "cls" );
                 x=10;
                 break;
              }if(x==10) break;


              }while(x=99);
            }
            int f=0;
            if(wybor ==3 && x>=0 && z==0 )
            {
                system( "cls" );
                if(g.ile_pieniadze() >= stawka){
                g.przegrana(stawka);
                stawka = stawka + stawka;

                  int k = rand()%13+2;
                  g.dodaj_karte(k,b);
                  b++;
                  g.sumuj_karty(b-1);

                while(krupier.suma_kart <= 17)
                 {
                        int o = rand()%13+2;
                        krupier.dodaj_karte(o,krupier_licznik);
                        krupier_licznik++;
                        krupier.sumuj_karty(krupier_licznik-1);

                    g.wyswietl_wszystko_gracz(b,stawka);
                    krupier.wyswietl_wszystko_krupier(krupier_licznik);

                    sleep(1);

                    if(((krupier.suma_kart > g.suma_kart) && krupier.suma_kart<=21) || (g.suma_kart > 21)){
                            sleep(1);
                       cout << "                      PRZEGRANA :(";
                        sleep(3);
                        system( "cls" );
                        z=0;
                        f++;
                        break;
                    }if(f==1) break;
                    if(((krupier.suma_kart >= 17 && krupier.suma_kart <= 21) && ((g.suma_kart > krupier.suma_kart) && g.suma_kart <= 21)) || krupier.suma_kart > 21){
                        sleep(1);
                       cout << "                      WYGRANA!!!";
                        g.wygrana(stawka);
                        sleep(3);
                        system( "cls" );
                        z=0;
                        f++;
                        g.licz_wygrania_suma();
                        g.stawka_a = g.stawka_a + stawka;
                        break;
                    }if(f==1) break;
                    if(krupier.suma_kart == g.suma_kart){
                        sleep(1);
                        cout << "                      REMIS!!!";
                        g.remis(stawka);
                        sleep(3);
                        system( "cls" );
                        z=0;
                        f++;
                        break;
                   }if(f==1) break;
                 }
                }
             if(f==1) break;
            }
          }while(v=-1);
        }

        int stawka_1, stawka_2; stawka;
     if(m == 2)       //-----------------------------------------------------------  2 GRACZY ---------------------------------------------------------------
     {
         system( "cls" );

            krupier.suma_kart = 0;

                // GRACZ 2 WYGRYWA

            if(g1.ile_pieniadze() <=0)
            {
            int t;
            cout << "                              BANKRUT!" << endl;
            cout << "                             WYGRYWA GRACZ 2!" << endl << endl;

            cout << "Wpisz 1 aby zaczac nowa rozgrywke lub 0 aby wrocic do menu glownego\n: ";
            cin >> t;

            if(t==1)
            {
                g1.domyslne();
                g2.domyslne();

                continue;
            }
            else if(t==0)
            {
                g1.domyslne();
                g2.domyslne();

                system( "cls" );
                break;
            }else
            {
            system( "cls" );
            cout << "                              BANKRUT!" << endl;
            cout << "                             WYGRYWA GRACZ 2!" << endl << endl;

            cout << "Wpisz 1 aby zaczac nowa rozgrywke lub 0 aby wrocic do menu glownego\n: BLEDNE DANE ";
                sleep(2);
            continue;
            }
            }

            if(g2.ile_wygran() >=10 && g2.saldo_a>=1 && g2.stawka_a_i >=1)
            {
                system( "cls" );
                cout <<"                          WYGRAL GRACZ 2!! GRATULACJE!!";
            }




            // GRACZ 1 WYGRYWA

            if(g2.ile_pieniadze() <=0)
            {
            int t;
            cout << "                              BANKRUT!" << endl;
            cout << "                             WYGRYWA GRACZ 1!" << endl << endl;

            cout << "Wpisz 1 aby zaczac nowa rozgrywke lub 0 aby wrocic do menu glownego\n: ";
            cin >> t;

            if(t==1)
            {
                g1.domyslne();
                g2.domyslne();


                continue;
            }
            else if(t==0)
            {

                g1.domyslne();
                g2.domyslne();

                system( "cls" );
                break;
            }else
            {
            system( "cls" );
            cout << "                              BANKRUT!" << endl;
            cout << "                             WYGRYWA GRACZ 1!" << endl << endl;

            cout << "Wpisz 1 aby zaczac nowa rozgrywke lub 0 aby wrocic do menu glownego\n: BLEDNE DANE ";
                sleep(2);
            continue;
            }
            }

            if(g1.ile_wygran() >=10 && g1.saldo_a>=1 && g1.stawka_a_i >=1)
            {
                system( "cls" );
                cout <<"                          WYGRAL GRACZ 1!! GRATULACJE!!";
            }

            d=0;
            c=0;
        do{

            if(g1.ile_pieniadze() >= 10000)
            {
                g1.saldo_a++;
            }

            if(g1.stawka_a >= 7500)
            {
                g1.stawka_a_i++;
            }
                                            // WYSWIETLA ZAKLADY
          system( "cls" );
          g1.wyswietl_zaklady_gracz(d);
          krupier.wyswietl_zaklady_krupier_dobra_1(krupier_licznik);
          cin >> stawka_1;

      if(stawka_1<=g1.ile_pieniadze() && stawka_1 > 0)
      {
        g1.przegrana(stawka_1);
            break;


      }else
       {
        system( "cls" );
       g1.wyswietl_zaklady_gracz(d);
        krupier.wyswietl_zaklady_krupier_zla(krupier_licznik);
        sleep(2);
        continue;
       }
            }while(stawka_1 =-2137);


            do{

            if(g2.ile_pieniadze() >= 10000)
            {
                g2.saldo_a++;
            }

            if(g2.stawka_a >= 7500)
            {
                g2.stawka_a_i++;
            }

                                            // WYSWIETLA ZAKLADY
          system( "cls" );
          g2.wyswietl_zaklady_gracz(c);
          krupier.wyswietl_zaklady_krupier_dobra_1(krupier_licznik);
          cin >> stawka_2;

      if(stawka_2<=g2.ile_pieniadze() && stawka_2 > 0)
      {
        g2.przegrana(stawka_2);
            break;


      }else
       {
        system( "cls" );
        g2.wyswietl_zaklady_gracz(c);
        krupier.wyswietl_zaklady_krupier_zla(krupier_licznik);
        sleep(2);
        continue;
       }
            }while(stawka_1 =-2137);


        g1.black = 0;
        g2.black = 0;

        g1.suma_kart = 0;
        g2.suma_kart = 0;

    for(int i=0; i<2;i++)
    {
        int k = rand()%13+2;
        g1.dodaj_karte(k,d);
        d++;
        g1.sumuj_karty(d-1);

         if(k==14)
         {
            g1.black = g1.black + 1;
         }
    }

    for(int i=0; i<2;i++)
    {
        int k = rand()%13+2;
        g2.dodaj_karte(k,c);
        c++;
        g2.sumuj_karty(c-1);

         if(k==14)
         {
            g2.black = g2.black + 1;
         }
    }



          int o = rand()%13+2;
          krupier.dodaj_karte(o,krupier_licznik);
          krupier_licznik++;
          krupier.sumuj_karty(krupier_licznik-1);

          int x=0;
          int z=0;
          int y=0;
          int q=0;
          int f=0;
          int wygra_1=0;
          int wygra_2=0;
          int remis_1=0;
          int remis_2=0;
          int przegrana_1 =0;
          int przegrana_2=0;
       do{

         if(f>=1)
         {
            if((g1.black == 1 && g1.suma_kart == 21) || (g2.black == 1 && g2.suma_kart == 21))
            {                       // WYGRANA

                if(g1.black == 1 && g1.suma_kart == 21)
                {
                g1.wygrana(stawka_1);
                system( "cls" );
                g1.licz_wygrania_suma();
                g1.black=0;
                g1.stawka_a = g1.stawka_a + stawka_1;
                g1.black =0;
                wygra_1++;
                }

                if(g2.black == 1 && g2.suma_kart == 21)
                {
                g2.wygrana(stawka_2);
                g2.licz_wygrania_suma();
                g2.black=0;
                g2.stawka_a = g2.stawka_a + stawka_2;
                g2.black =0;
                wygra_2++;
                }
            }


            if(g1.black == 2)
            {
                g1.suma_kart = 12;
            }

            if(g2.black == 2)
            {
                g2.suma_kart = 12;
            }

            if(((krupier.suma_kart >= 17 && krupier.suma_kart <= 21) && ((g1.suma_kart > krupier.suma_kart) && g1.suma_kart <= 21)) || krupier.suma_kart > 21 && g1.suma_kart<=21)
                {
                    g1.wygrana(stawka_1);
                g1.licz_wygrania_suma();
                    g1.stawka_a = g1.stawka_a + stawka_1;
                    wygra_1++;
                }

                if(((krupier.suma_kart >= 17 && krupier.suma_kart <= 21) && ((g2.suma_kart > krupier.suma_kart) && g2.suma_kart <= 21)) || krupier.suma_kart > 21 && g2.suma_kart<=21 )
                {
                    g2.wygrana(stawka_2);
                g2.licz_wygrania_suma();
                    g2.stawka_a = g2.stawka_a + stawka_2;
                    wygra_2++;
                }

                                    // REMIS
            if((krupier.suma_kart == 21 && g1.suma_kart == 21) || (krupier.suma_kart == 17 && g1.suma_kart == 17) || (krupier.suma_kart == 18 && g1.suma_kart == 18) ||
               (krupier.suma_kart == 19 && g1.suma_kart == 19) || (krupier.suma_kart == 20 && g1.suma_kart == 20))
              {
                 g1.remis(stawka_1);
                 remis_1++;
              }

              if((krupier.suma_kart == 21 && g2.suma_kart == 21) || (krupier.suma_kart == 17 && g2.suma_kart == 17) || (krupier.suma_kart == 18 && g2.suma_kart == 18) ||
               (krupier.suma_kart == 19 && g2.suma_kart == 19) || (krupier.suma_kart == 20 && g2.suma_kart == 20))
              {
                 g2.remis(stawka_2);
                 remis_2++;
              }

                                    // PRZEGRANA
            if(((y!=0) && (krupier.suma_kart > g1.suma_kart) && krupier.suma_kart<=21) || (g1.suma_kart > 21))
              {
                 if(g1.suma_kart < krupier.suma_kart && q!=1){
                      cout << " ";
                 }else{
                 przegrana_1++;
                 }

              }

            if(((y!=0) && (krupier.suma_kart > g2.suma_kart) && krupier.suma_kart<=21) || (g2.suma_kart > 21))
              {
                 if(g2.suma_kart < krupier.suma_kart && q!=1){
                    cout << " ";
                 }else{
                 przegrana_2++;
                 }

              }

            if(wygra_1 >= 1)
            {
              g1.wyswietl_wszystko_gracz(d,stawka_1);
              krupier.wyswietl_wszystko_krupier(krupier_licznik);
              g2.wyswietl_wszystko_gracze_2(c, stawka_2);
              cout << endl << endl;
              cout << "                             GRACZ 1 WYGRYWA!!";
              sleep(3);
              q++;
            }

            if(wygra_2 >= 1)
            {
              g1.wyswietl_wszystko_gracz(d,stawka_1);
              krupier.wyswietl_wszystko_krupier(krupier_licznik);
              g2.wyswietl_wszystko_gracze_2(c, stawka_2);
              cout << endl << endl;
              cout << "                             GRACZ 2 WYGRYWA!!";
              sleep(3);
              q++;
            }

              if(przegrana_1 >= 1)
            {
              g1.wyswietl_wszystko_gracz(d,stawka_1);
              krupier.wyswietl_wszystko_krupier(krupier_licznik);
              g2.wyswietl_wszystko_gracze_2(c, stawka_2);
              cout << endl << endl;
              cout << "                             GRACZ 1 PRZEGRYWA!!";
              sleep(3);
              q++;
            }

            if(przegrana_2 >= 1)
            {
              g1.wyswietl_wszystko_gracz(d,stawka_1);
              krupier.wyswietl_wszystko_krupier(krupier_licznik);
              g2.wyswietl_wszystko_gracze_2(c, stawka_2);
              cout << endl << endl;
              cout << "                             GRACZ 2 PRZEGRYWA!!";
              sleep(3);
              q++;
            }

            if(remis_1 >= 1)
            {
              g1.wyswietl_wszystko_gracz(d,stawka_1);
              krupier.wyswietl_wszystko_krupier(krupier_licznik);
              g2.wyswietl_wszystko_gracze_2(c, stawka_2);
              cout << endl << endl;
              cout << "                             GRACZ 1 REMIS!!";
              sleep(3);
              q++;
            }

             if(remis_2 >= 1)
            {
              g1.wyswietl_wszystko_gracz(d,stawka_1);
              krupier.wyswietl_wszystko_krupier(krupier_licznik);
              g2.wyswietl_wszystko_gracze_2(c, stawka_2);
              cout << endl << endl;
              cout << "                             GRACZ 2 REMIS!!";
              sleep(3);
              q++;
            }

            if(q>=2)
            {
                break;
            }
       }
            f++;
            y=0;
            z=0;
         while(y==0)
         {
            g1.wyswietl_wszystko_gracz(d,stawka_1);
            krupier.wyswietl_wszystko_krupier(krupier_licznik);
            g2.wyswietl_wszystko_gracze_2(c, stawka_2);

          cout << endl << endl;
          cout << "Gracz 1:" << endl;
          cout << "Aby dobrac karte wpisz 1: " << endl;
          cout << "Aby wstrzymac sie wpisz 2: " << endl;
          cout << "Aby podwoic swoj zaklad wpisz 3 \(mozliwe przy dwoch kartach): " << endl;
          cout << ": ";
          cin >> wybor_1;

          if(wybor_1 == 1 && y==0)
            {
                int k = rand()%13+2;
                g1.dodaj_karte(k,d);
                d++;
                g1.sumuj_karty(d-1);
                z++;
            }

            if(wybor_1 == 2)
            {
                y++;
            }

            if(wybor_1 == 3 && z==0)
            {
                  y++;
                  int k = rand()%13+2;
                  g1.dodaj_karte(k,d);
                  d++;
                  g1.sumuj_karty(d-1);

                 if(g1.ile_pieniadze() >= stawka_1){
                g1.przegrana(stawka_1);
                stawka_1 = stawka_1 + stawka_1;
            }
       }
         if(y>=1)
            {
        while(y!=2)
          {
            z=0;
             system( "cls" );
             g1.wyswietl_wszystko_gracz(d,stawka_1);
             krupier.wyswietl_wszystko_krupier(krupier_licznik);
             g2.wyswietl_wszystko_gracze_2(c, stawka_2);

          cout << endl << endl;
          cout << "Gracz 2:" << endl;
          cout << "Aby dobrac karte wpisz 1: " << endl;
          cout << "Aby wstrzymac sie wpisz 2: " << endl;
          cout << "Aby podwoic swoj zaklad wpisz 3 \(mozliwe przy dwoch kartach): " << endl;
          cout << ": ";
          cin >> wybor_2;

           if(wybor_2 == 1)
            {
                int k = rand()%13+2;
                g2.dodaj_karte(k,c);
                c++;
                g2.sumuj_karty(c-1);
                z++;
            }

         if(wybor_2 == 2 && y>=0)
            {
                y++;
            }

         if(wybor_2 == 3 && y>=0)
            {
                y++;
            }

            }


         if(wybor_2 == 2 && y==2 || g2.suma_kart>21)
            {
                y++;
                q++;
              do{
              if((((krupier.suma_kart >= 17 && krupier.suma_kart <= 21) && ((g1.suma_kart > krupier.suma_kart) && g1.suma_kart <= 21)) || krupier.suma_kart > 21) &&
                (((krupier.suma_kart >= 17 && krupier.suma_kart <= 21) && ((g2.suma_kart > krupier.suma_kart) && g2.suma_kart <= 21)) || krupier.suma_kart > 21))
            {
                break;
            }

             if(((krupier.suma_kart >= 17 && krupier.suma_kart <= 21) && ((g2.suma_kart > krupier.suma_kart) && g2.suma_kart <= 21)) || krupier.suma_kart > 21)
            {
                break;
            }

            if(((krupier.suma_kart == 21 && g1.suma_kart == 21) || (krupier.suma_kart == 17 && g1.suma_kart == 17) || (krupier.suma_kart == 18 && g1.suma_kart == 18) ||
               (krupier.suma_kart == 19 && g1.suma_kart == 19) || (krupier.suma_kart == 20 && g1.suma_kart == 20)) &&
               ((krupier.suma_kart == 21 && g2.suma_kart == 21) || (krupier.suma_kart == 17 && g2.suma_kart == 17) || (krupier.suma_kart == 18 && g2.suma_kart == 18) ||
               (krupier.suma_kart == 19 && g2.suma_kart == 19) || (krupier.suma_kart == 20 && g2.suma_kart == 20)))
              {
                break;
              }

            if((krupier.suma_kart == 21 && g2.suma_kart == 21) || (krupier.suma_kart == 17 && g2.suma_kart == 17) || (krupier.suma_kart == 18 && g2.suma_kart == 18) ||
               (krupier.suma_kart == 19 && g2.suma_kart == 19) || (krupier.suma_kart == 20 && g2.suma_kart == 20))
              {
                break;
              }

            if(g1.suma_kart > 21 && g2.suma_kart > 21)
            {
                break;
            }


              if((krupier.suma_kart <=16 && (krupier.suma_kart< g1.suma_kart || krupier.suma_kart< g2.suma_kart)) && (g1.suma_kart <=21 || g2.suma_kart <=21))
              {
              system( "cls" );
              g1.wyswietl_wszystko_gracz(d,stawka_1);
              krupier.wyswietl_wszystko_krupier(krupier_licznik);
              g2.wyswietl_wszystko_gracze_2(c, stawka_2);

                int o = rand()%13+2;
                krupier.dodaj_karte(o,krupier_licznik);
                krupier_licznik++;
                krupier.sumuj_karty(krupier_licznik-1);

               sleep(1);
              }else break;
              if(krupier.suma_kart > g1.suma_kart && krupier.suma_kart<=21)
              {
                przegrana_1++;
                q++;
              }

              if(krupier.suma_kart > g2.suma_kart && krupier.suma_kart<=21)
              {
                przegrana_2++;
                q++;
              }
              if(q>=2)
              {
                  q=0;
                  break;
              }

              }while(x=99);
            }

            if(wybor_2 ==3 && g2.ile_pieniadze() >= stawka_2)
            {
                system( "cls" );

                g2.przegrana(stawka_2);
                stawka_2 = stawka_2 + stawka_2;

                int k = rand()%13+2;
                  g2.dodaj_karte(k,c);
                  c++;
                  g2.sumuj_karty(c-1);


              do{
              if((((krupier.suma_kart >= 17 && krupier.suma_kart <= 21) && ((g1.suma_kart > krupier.suma_kart) && g1.suma_kart <= 21)) || krupier.suma_kart > 21) &&
                (((krupier.suma_kart >= 17 && krupier.suma_kart <= 21) && ((g2.suma_kart > krupier.suma_kart) && g2.suma_kart <= 21)) || krupier.suma_kart > 21))
            {
                break;
            }

             if(((krupier.suma_kart >= 17 && krupier.suma_kart <= 21) && ((g2.suma_kart > krupier.suma_kart) && g2.suma_kart <= 21)) || krupier.suma_kart > 21)
            {
                break;
            }

            if(((krupier.suma_kart == 21 && g1.suma_kart == 21) || (krupier.suma_kart == 17 && g1.suma_kart == 17) || (krupier.suma_kart == 18 && g1.suma_kart == 18) ||
               (krupier.suma_kart == 19 && g1.suma_kart == 19) || (krupier.suma_kart == 20 && g1.suma_kart == 20)) &&
               ((krupier.suma_kart == 21 && g2.suma_kart == 21) || (krupier.suma_kart == 17 && g2.suma_kart == 17) || (krupier.suma_kart == 18 && g2.suma_kart == 18) ||
               (krupier.suma_kart == 19 && g2.suma_kart == 19) || (krupier.suma_kart == 20 && g2.suma_kart == 20)))
              {
                break;
              }

            if((krupier.suma_kart == 21 && g2.suma_kart == 21) || (krupier.suma_kart == 17 && g2.suma_kart == 17) || (krupier.suma_kart == 18 && g2.suma_kart == 18) ||
               (krupier.suma_kart == 19 && g2.suma_kart == 19) || (krupier.suma_kart == 20 && g2.suma_kart == 20))
              {
                break;
              }

            if(g1.suma_kart > 21 && g2.suma_kart > 21)
            {
                break;
            }


              if((krupier.suma_kart <=16 && (krupier.suma_kart< g1.suma_kart || krupier.suma_kart< g2.suma_kart)) && (g1.suma_kart <=21 || g2.suma_kart <=21))
              {
              system( "cls" );
              g1.wyswietl_wszystko_gracz(d,stawka_1);
              krupier.wyswietl_wszystko_krupier(krupier_licznik);
              g2.wyswietl_wszystko_gracze_2(c, stawka_2);

                int o = rand()%13+2;
                krupier.dodaj_karte(o,krupier_licznik);
                krupier_licznik++;
                krupier.sumuj_karty(krupier_licznik-1);

               sleep(1);
              }else break;
              if(krupier.suma_kart > g1.suma_kart && krupier.suma_kart<=21)
              {
                przegrana_1++;
                q++;
              }

              if(krupier.suma_kart > g2.suma_kart && krupier.suma_kart<=21)
              {
                przegrana_2++;
                q++;
              }
              if(q>=2)
              {
                  q=0;
                  break;
              }

              }while(x=99);
            }
             if(f==1) break;
            }
           }
          }while(v=-1);
      }

      }while(l= 1);

        }while(v=80);




    return 0;
}
