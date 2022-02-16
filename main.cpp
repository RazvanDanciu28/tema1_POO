#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
char command[10];
float pi = 3.14;

struct baza_cerc
{
    int raza, inaltime;
};
struct baza_dreptunghi
{
    int latime, lungime, inaltime;
};
struct baza_patrat
{
    int latura, inaltime;
};
struct baza_triunghi
{
    int cat_mica, cat_mare, inaltime;
};

struct prajitura
{
    bool cerc = false;
    bool dreptunghi  = false;
    bool patrat = false;
    bool triunghi = false;

    baza_cerc forma_c;
    baza_dreptunghi forma_d;
    baza_patrat forma_p;
    baza_triunghi forma_t;
}prajituri[100];

int main() {
    std::cin >> a >>  b;
    std::cout << a + b;

                gem_total += gem;
                frisca_total += frisca;

                cout<< "Cantitate de gem folosita pentru prajitura aceasta: " << gem << " g" << endl;
                cout<< "Cantitate de frisca folosita pentru prajitura aceasta: " << frisca << " g" << endl;


            }
            else if (baza[0] == 'd'){
                cout << "Introdu lungimea, latimea si inaltimea" << endl;

                prajituri[i].dreptunghi = true;
                cin>>prajituri[i].forma_d.lungime;
                cin>>prajituri[i].forma_d.latime;
                cin>>prajituri[i].forma_d.inaltime;

                int gem = 2 * prajituri[i].forma_d.lungime * prajituri[i].forma_d.latime * prajituri[i].forma_d.inaltime;
                int frisca = 2 * (prajituri[i].forma_d.lungime + prajituri[i].forma_d.latime) * prajituri[i].forma_d.inaltime;

                gem_total += gem;
                frisca_total += frisca;

                cout<< "Cantitate de gem folosita pentru prajitura aceasta: " << gem << " g" << endl;
                cout<< "Cantitate de frisca folosita pentru prajitura aceasta: " << frisca << " g" << endl;
            }
            else if (baza[0] == 'p'){
                cout << "Introdu latura si inaltimea" << endl;

                prajituri[i].patrat = true;
                cin>>prajituri[i].forma_p.latura;
                cin>>prajituri[i].forma_p.inaltime;

                int gem = 2 * prajituri[i].forma_p.latura * prajituri[i].forma_p.latura * prajituri[i].forma_p.inaltime;
                int frisca = 4 * prajituri[i].forma_p.latura * prajituri[i].forma_p.inaltime;

                gem_total += gem;
                frisca_total += frisca;

                cout<< "Cantitate de gem folosita pentru prajitura aceasta: " << gem << " g" << endl;
                cout<< "Cantitate de frisca folosita pentru prajitura aceasta: " << frisca << " g" << endl;
            }
            else{
                cout << "Introdu cateta mare, cateta mica si inaltimea" << endl;

                prajituri[i].triunghi = true;
                cin>>prajituri[i].forma_t.cat_mare;
                cin>>prajituri[i].forma_t.cat_mica;
                cin>>prajituri[i].forma_t.inaltime;

                int gem = prajituri[i].forma_t.cat_mare * prajituri[i].forma_t.cat_mica * prajituri[i].forma_t.inaltime;
                float ipot = sqrt(prajituri[i].forma_t.cat_mare * prajituri[i].forma_t.cat_mare + prajituri[i].forma_t.cat_mica * prajituri[i].forma_t.cat_mica);
                float frisca = (ipot + prajituri[i].forma_t.cat_mare + prajituri[i].forma_t.inaltime);

                gem_total += gem;
                frisca_total += frisca;

                cout<< "Cantitate de gem folosita pentru prajitura aceasta: " << gem << " g" << endl;
                cout<< "Cantitate de frisca folosita pentru prajitura aceasta: " << frisca << " g" << endl;


            }
        }

        if (!strcmp(command, "TOTAL")){
            cout<< "Cantitatea de gem totala: " << gem_total << " g" << endl;
            cout<< "Cantitatea de frisca total: " << frisca_total << " g" << endl;

        }

        if (!strcmp(command, "REMOVE")){
            int x; cin>>x;
            for (int j = x; j < i; j++) prajituri[j] = prajituri[j+1];
            i--;
        }

        cin.getline(command, 10);
        stop = strcmp(command, "STOP");
    }



    return 0;
}
