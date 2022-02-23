#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
char command[10];
float pi = 3.14;

class baza_cerc
{
public:
    int raza, inaltime;

    void citire_cerc(int &raza_c, int &inaltime_c){
        cin>>raza_c;
        cin>>inaltime_c;
    }
    void calcul_gem_frisca(int raza_c, int inaltime_c, float &gem, float &frisca){
        gem = 2 * pi * raza_c * raza_c * inaltime_c;
        frisca = 2 * pi * raza_c * inaltime_c;

        cout<< "Cantitate de gem folosita pentru prajitura aceasta: " << gem<< " g" << endl;
        cout<< "Cantitate de frisca folosita pentru prajitura aceasta: " << frisca << " g" << endl;
    }

};
class baza_dreptunghi
{
public:
    int latime, lungime, inaltime;

    void citire_drept(int &lungime_d, int &latime_d, int &inaltime_d){
        cin>>lungime_d;
        cin>>latime_d;
        cin>>inaltime_d;
    }
    void calcul_gem_frisca(int lungime_d, int latime_d, int inaltime_d, float &gem, float &frisca){
        gem = 2 * lungime_d * latime_d * inaltime_d;
        frisca =  2 * (lungime_d + latime_d) * inaltime_d;

        cout << "Cantitate de gem folosita pentru prajitura aceasta: " << gem<< " g" << endl;
        cout << "Cantitate de frisca folosita pentru prajitura aceasta: " << frisca << " g" << endl;
    }
};
class baza_patrat
{
public:
    int latura, inaltime;

    void citire_patrat(int &latura_p, int &inaltime_p){
        cin>>latura_p>>inaltime_p;
    }
    void caclul_gem_frisca(int latura_p, int inaltime_p, float &gem, float &frisca){
        gem =  2 * latura_p * latura_p * inaltime_p;
        frisca = 4 * latura_p * inaltime_p;

        cout<< "Cantitate de gem folosita pentru prajitura aceasta: " << gem<< " g" << endl;
        cout<< "Cantitate de frisca folosita pentru prajitura aceasta: " << frisca << " g" << endl;
    }
};
class baza_triunghi
{
public:
    int cat_mica, cat_mare, inaltime;

    void citire_tri(int &cat_mica_t, int &cat_mare_t, int &inaltime_t){
        cin>>cat_mica_t>>cat_mare_t>>inaltime_t;
    }
    void calcul_gem_frisca(int cat_mica_t, int cat_mare_t, int inaltime_t, float &gem, float &frisca){
        gem = cat_mare_t * cat_mica_t * inaltime_t;
        float ipot = sqrt(cat_mare_t * cat_mare_t + cat_mica_t * cat_mica_t);
        frisca = (ipot + cat_mare_t + inaltime_t);

        cout<< "Cantitate de gem folosita pentru prajitura aceasta: " << gem<< " g" << endl;
        cout<< "Cantitate de frisca folosita pentru prajitura aceasta: " << frisca << " g" << endl;
    }
};

class prajitura
{
public:
    baza_cerc forma_c;
    baza_dreptunghi forma_d;
    baza_patrat forma_p;
    baza_triunghi forma_t;

    float gem;
    float frisca;
}prajituri[100];

int main() {
    cin.getline(command,10);

    bool stop = strcmp(command, "STOP");
    int i = 0;
    float frisca_total = 0;
    float gem_total = 0;

    while (stop){
        if (!strcmp(command, "ADD")){
            char baza[20];
            cin.getline(baza, 20);
            i++;
            if (baza[0] == 'c'){
                cout << "Introdu raza si inaltimea" << endl;

                prajituri[i].forma_c.citire_cerc(prajituri[i].forma_c.raza, prajituri[i].forma_c.inaltime);
                prajituri[i].forma_c.calcul_gem_frisca(prajituri[i].forma_c.raza, prajituri[i].forma_c.inaltime, prajituri[i].gem, prajituri[i].frisca);

                gem_total += prajituri[i].gem;
                frisca_total += prajituri[i].frisca;
            }
            else if (baza[0] == 'd'){
                cout << "Introdu lungimea, latimea si inaltimea" << endl;

                prajituri[i].forma_d.citire_drept(prajituri[i].forma_d.lungime, prajituri[i].forma_d.latime, prajituri[i].forma_d.inaltime);
                prajituri[i].forma_d.calcul_gem_frisca(prajituri[i].forma_d.lungime, prajituri[i].forma_d.latime, prajituri[i].forma_d.inaltime, prajituri[i].gem, prajituri[i].frisca);

                gem_total += prajituri[i].gem ;
                frisca_total += prajituri[i].frisca;
            }
            else if (baza[0] == 'p'){
                cout << "Introdu latura si inaltimea" << endl;

                prajituri[i].forma_p.citire_patrat(prajituri[i].forma_p.latura,prajituri[i].forma_p.inaltime);
                prajituri[i].forma_p.caclul_gem_frisca(prajituri[i].forma_p.latura, prajituri[i].forma_p.inaltime, prajituri[i].gem, prajituri[i].frisca);

                gem_total += prajituri[i].gem ;
                frisca_total += prajituri[i].frisca;
            }
            else{
                cout << "Introdu cateta mare, cateta mica si inaltimea" << endl;

                prajituri[i].forma_t.citire_tri(prajituri[i].forma_t.cat_mica, prajituri[i].forma_t.cat_mare, prajituri[i].forma_t.inaltime);
                prajituri[i].forma_t.calcul_gem_frisca(prajituri[i].forma_t.cat_mica, prajituri[i].forma_t.cat_mare, prajituri[i].forma_t.inaltime, prajituri[i].gem, prajituri[i].frisca);

                gem_total += prajituri[i].gem ;
                frisca_total += prajituri[i].frisca;
            }
        }

        if (!strcmp(command, "TOTAL")){
            cout<< "Cantitatea de gem totala: " << gem_total << " g" << endl;
            cout<< "Cantitatea de frisca total: " << frisca_total << " g" << endl;

        }

        if (!strcmp(command, "REMOVE")){
            int x; cin>>x;

            gem_total -= prajituri[x].gem;
            frisca_total -= prajituri[x].frisca;

            for (int j = x; j < i; j++) prajituri[j] = prajituri[j+1];
            i--;
        }

        cin.getline(command, 10);
        stop = strcmp(command, "STOP");
    }



    return 0;
}
