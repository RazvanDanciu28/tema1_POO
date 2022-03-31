#include <iostream>
#include <cstring>
using namespace std;

class film{
    char *denumire_film, *gen, *regizor;
    double rating;
public:
    //constructor
    film(){
        denumire_film = new char[50];

        gen = new char[25];
        regizor = new char[50];
    };
    //destructor
    ~film(){
        delete[] denumire_film;
        delete[] gen;
        delete[] regizor;
    }

    //constructor de copiere
    film(film &film_nou){
        delete film_nou.denumire_film;
        int size = strlen(denumire_film);
        film_nou.denumire_film = new char[size];
        strcpy(film_nou.denumire_film, denumire_film);

        delete film_nou.gen;
        size = strlen(gen);
        film_nou.gen = new char[size];
        strcpy(film_nou.gen, gen);

        delete film_nou.regizor;
        size = strlen(regizor);
        film_nou.regizor = new char[size];
        strcpy(film_nou.regizor, regizor);

        film_nou.rating = rating;
    }

    film(const char nume[], const char gen_[], const char reg[], double rating_) {
        denumire_film = new char[50];
        strcpy(denumire_film, nume);

        gen = new char[25];
        strcpy(gen, gen_);

        regizor = new char[50];
        strcpy(regizor, reg);

        rating = rating_;
    }


    //supraincarcare pe operatorul de atribuire
    void operator=(film &film_nou){
        delete film_nou.denumire_film;
        int size = strlen(denumire_film);
        film_nou.denumire_film = new char[size];
        strcpy(film_nou.denumire_film, denumire_film);

        delete film_nou.gen;
        size = strlen(gen);
        film_nou.gen = new char[size];
        strcpy(film_nou.gen, gen);

        delete film_nou.regizor;
        size = strlen(regizor);
        film_nou.regizor = new char[size];
        strcpy(film_nou.regizor, regizor);

        film_nou.rating = rating;
    }

    //supraincarcare pe operatorii specifici de comparare
    bool operator==(film &film_nou){
        if (rating == film_nou.rating) return true;
        else return false;
    }
    bool operator<(film &film_nou){
        if (rating < film_nou.rating) return true;
        else return false;
    }
    bool operator<=(film &film_nou){
        if (rating <= film_nou.rating) return true;
        else return false;
    }
    bool operator>(film &film_nou){
        if (rating > film_nou.rating) return true;
        else return false;
    }
    bool operator>=(film &film_nou){
        if (rating >= film_nou.rating) return true;
        else return false;
    }

    //functii de modificare a informatiilor unui film
    void setName(char *denumire){
        delete[] denumire_film;
        int size = strlen(denumire);
        denumire_film = new char[size];
        strcpy(denumire_film, denumire);
    }
    void setGen(char *gen_){
        delete[] gen;
        int size = strlen(gen_);
        gen = new char[size];
        strcpy(gen, gen_);
    }
    void setRegizor(char *regizor_){
        delete[] regizor;
        int size = strlen(regizor_);
        regizor = new char[size];
        strcpy(regizor, regizor_);
    }
    void setRating(double rating_){
        rating = rating_;
    }
    void setAll(char *denumire, char *gen_, char *regizor_, double rating_){
        int size = strlen(denumire);
        denumire_film = new char[size];
        strcpy(denumire_film, denumire);

        size = strlen(gen_);
        gen = new char[size];
        strcpy(gen, gen_);

        size = strlen(regizor_);
        regizor = new char[size];
        strcpy(regizor, regizor_);
        rating = rating_;
    }

    char *getDenumireFilm() const;

    char *getGen() const;


    //supraincarcarea pe operatorii de citire si afisare
    friend istream &operator>>(istream &fin, film &film_);
    friend ostream &operator<<(ostream &fout, const film &film_);

};

istream &operator>>(istream &fin, film &film_){
    cout<<"Introdu denumirea filmului: "<<endl; fin.getline(film_.denumire_film, 20);
    cout<<"Introdu genul filmului: "<<endl; fin.getline(film_.gen, 20);
    cout<<"Introdu numele regizorului: "<<endl; fin.getline(film_.regizor, 20);
    cout<<"Introdu rating-ul filmului: "<<endl; fin>>film_.rating; cin.get();
    return fin;
}
ostream &operator<<(ostream &fout,  const film &film_){
    cout<<endl<<endl;
    cout<<"denumirea filmului este: "; fout<<film_.denumire_film<<" "; cout<<endl;
    cout<<"genul filmului este: "; fout<<film_.gen<<" "; cout<<endl;
    cout<<"numele regizorului este: "; fout<<film_.regizor<<" "; cout<<endl;
    cout<<"rating-ul filmului este: "; fout<<film_.rating<<" "; cout<<endl;
    return fout;
}

char *film::getDenumireFilm() const {
    return denumire_film;
}

char *film::getGen() const {
    return gen;
}

film *filme[20];
int main() {

    const film test("nume", "gen", "reg", 5.02);
    cout<<test;
    return 0;

    //citire filme de la tastatura
    cout<<"Introdu numarul de filme: "; int n; cin>>n; cin.get(); cout<<endl;
    for (int i = 1; i <= n; i++){
        cout<<"Filmul "<<i<<endl;
        filme[i] = new film;
        cin>>*filme[i]; cout<<endl;
    }
    //citire comenzi
    char comanda[15];
    int final = 1;
    cout<<"comenzi disponibile: modificare, stergere, sortare, comparare, afisare, stop"<<endl;
    while (final){
        cout<<"Introdu comanda:"; cin.getline(comanda,15);
        //comanda de modificare
        if (comanda[0] == 'm'){
            cout<<"Alege filmul pe care doresti sa-l modifici:"<<endl; int *nr_film = new int; cin>>*nr_film; cin.get(); cout<<endl;
            cout<<"Alege ce vrei sa modifici la filmul "<<*nr_film<<"(nume, gen, regizor, rating, tot): "; char *modif = new char[10]; cin.getline(modif,10); cout<<endl;
            if (modif[0] == 'n'){ //modificarea numelui
                cout<<"Introdu numele nou:"; char nume[50]; cin.getline(nume,50); cout<<endl;
                filme[*nr_film]->setName(nume);
            }
            else if (modif[0] == 'g'){ //modificarea genului
                cout<<"Introdu genul nou:"; char gen[30]; cin.getline(gen,30); cout<<endl;
                filme[*nr_film]->setGen(gen);
            }
            else if (modif[0] == 'r' and modif[1] == 'e'){ //modificarea regizorului
                cout<<"Introdu numele regizorului nou:"; char regizor[50]; cin.getline(regizor,50); cout<<endl;
                filme[*nr_film]->setRegizor(regizor);
            }
            else if (modif[0] == 'r' and modif[1] == 'a'){ //modificarea rating-ului
                cout<<"Introdu rating-ul nou:"; double rating; cin>>rating; cin.get(); cout<<endl;
                filme[*nr_film]->setRating(rating);
            }
            else{
                char nume[50], gen[30], regizor[50]; double rating; //modificarea intregului film
                cout<<"Introdu denumirea noua a filmului: "<<endl; cin.getline(nume, 50);
                cout<<"Introdu genul nou al filmului: "<<endl; cin.getline(gen, 30);
                cout<<"Introdu numele nou al regizorului: "<<endl; cin.getline(regizor, 50);
                cout<<"Introdu rating-ul nou al filmului: "<<endl; cin>>rating; cin.get();
                filme[*nr_film]->setAll(nume, gen, regizor, rating);
                cout<<endl;
            }
            delete nr_film;
            delete[] modif;
        }
            //comanda de stergere
        else if (comanda[0] == 's' and comanda[1] == 't' and comanda[2] == 'e'){
            cout<<"Introdu filmul pe care vrei sa-l stergi: "; int nr_film; cin>>nr_film; cin.get(); cout<<endl;
            for (int i = nr_film; i < n; i++) filme[i] = filme[i+1];
            //delete filme[n];
            n--;

        }
            //comanda de sortare
        else if (comanda[0] == 's' and comanda[1] == 'o' and comanda[2] == 'r'){
            cout<<"Alege tipul de sortare(crescator sau descrescator):"; char sort[10]; cin.getline(sort,10); cout<<endl;
            if (sort[0] == 'c'){ //sortare crescatoare
                for (int i = 1; i <= n; i++){
                    for (int j = i+1; j <= n; j++){
                        if (*filme[i] > *filme[j]){
                            film *aux; aux = new film;
                            aux = filme[i]; filme[i] = filme[j]; filme[j] = aux;
                        }
                    }
                }
            }
            else{ //soratre descrescatoare
                for (int i = 1; i <= n; i++){
                    for (int j = i+1; j <= n; j++){
                        if (*filme[i] < *filme[j]){
                            film *aux; aux = new film;
                            aux = filme[i]; filme[i] = filme[j]; filme[j] = aux;
                        }
                    }
                }
            }
        }
            //comanda de comparare
        else if (comanda[0] == 'c'){
            cout<<"Alege filmele pe care sa le compari: "; int film1, film2; cin>>film1>>film2; cin.get(); cout<<endl;
            if (*filme[film1] > *filme[film2]) cout<<"Filmul "<<film1<<" are rating mai mare pe imdb"<<endl;
            else if (*filme[film1] < *filme[film2]) cout<<"Filmul "<<film2<<" are rating mai mare pe imdb"<<endl;
            else cout<<"Filmele au rating egal pe imdb";
        }
            //comanda de afisare
        else if (comanda[0] == 'a'){
            cout<<"Alege daca vrei sa afisezi toate filmele sau doar unul singur: "; char aleg[10]; cin.getline(aleg,10); cout<<endl;
            if (aleg[0] == 't'){ //afisare a tuturor filmelor
                for (int i = 1; i <= n; i++) cout<<*filme[i]<<endl;
            }
            else{ //afisare a unui singur film
                cout<<"Alege filmul pe care sa-l afisezi: "; int nr; cin>>nr; cin.get(); cout<<endl;
                cout<<*filme[nr]<<endl;
            }
        }
        final = strcmp(comanda, "stop");
        cout<<endl<<"comenzi disponibile: modificare, stergere, sortare, comparare, afisare, stop"<<endl;
    }


    for (int i = 1; i <= n; i++){
        delete filme[i];
    }
    return 0;
}
