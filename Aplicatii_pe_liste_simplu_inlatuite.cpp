//REUNIUNEA< INTERSECTIA< SCADEREA SI SCADEREA SIMETRICA A DOUA LISTE DE INTREGI 


//obs adauga sa verifice da nr de elem din lista este pozitiv 
#include<iostream>
using namespace std;

//definirea structurii pt lista simplu inlantuita
struct lista{
    int val;
    lista *urm;
};

//CREARE LISTA
lista* creare_lista_intregi() {
    int n, x;
    lista *prim, *ultim, *p;// noduri
    prim = NULL;//initializam primul nod cu NULL
    
    cout << "Introduceti numarul de elemente: ";
    cin >> n;
    if(n>0){
    for(int i = 1; i <= n; i++) {
        cout << "Elementul " << i << ": ";
        cin >> x;
        
        p = new lista;// alocam memorie pentru un nou nod
        p->val = x;// atribuim valoarea elementului
        p->urm = NULL;// initializam legatura catre urmatorul element cu NULL
        // adaugam nodul la sfarsitul listei
        if(prim == NULL) {
            prim = p;// primul element din lista
            ultim = p;// ultimul element din lista
        }
        // daca lista nu este vida
        else {
            ultim->urm = p;// legatura catre urmatorul element
            ultim = p;// ultimul element din lista
        }
    }
    return prim;}
    else{
        cout<<"lista este nula"<<endl;
        prim=NULL;
        return prim;
    }
}

//PARCURGERE LISTA
void parcurgere_lista(lista *cap) {
    lista *p = cap;// nod curent
    if(p == NULL) {
        cout << "Lista este vida!\n";// lista vida
        return;
    }
    while(p != NULL)// parcurgerea listei
     {
        cout << p->val << " ";
        p = p->urm;// trecem la urmatorul element
    }
    cout << endl;
}


//functia ia doua liste si creeaza o noua lista care contine elementele unice din ambele liste
lista* reuniune(lista *L1, lista *L2)
 {
    lista *rezultat = NULL;//initializam lista rezultat cu NULL
    lista *ultim = NULL;//initializam ultimul element cu NULL ca sa marcam capatul listei
    lista *p1 = L1;// nod curent pentru lista 1
    lista *p2 = L2;// nod curent pentru lista 2
    // parcurgem lista 1 si copiem elementele in lista rezultat
    while(p1 != NULL) {
        lista *nou = new lista;// alocam memorie pentru un nou nod
        nou->val = p1->val;// atribuim valoarea elementului
        nou->urm = NULL;
        
        if(rezultat == NULL)// daca lista rezultat este vida
         {
            rezultat = nou;
            ultim = nou;
        } else // daca lista rezultat nu este vida
        {
            ultim->urm = nou;//adaugam nodul la sfarsitul listei
            ultim = nou;
        }
        p1 = p1->urm;// trecem la urmatorul element
    }
    
    while(p2 != NULL)// parcurgem lista 2 si adaugam elementele care nu au fost deja adaugate in lista rezultat
     {
        bool exista = false;//pt verificarea daca elementul exista deja in lista rezultat
        lista *temp = rezultat;// nodul curent pentru lista rezultat
        while(temp != NULL) {
            //verificam daca elementul exista deja in lista rezultat
            if(temp->val == p2->val)
             {
                exista = true;
                break;
            }
            temp = temp->urm;// trecem la urmatorul element
        }
        
        if(!exista)// daca elementul nu exista deja in lista rezultat il insertam in lista rezultat
         {
            lista *nou = new lista;
            nou->val = p2->val;
            nou->urm = NULL;
            ultim->urm = nou;
            ultim = nou;
        }
        p2 = p2->urm;// trecem la urmatorul element
    }
    
    return rezultat;
}

// INTERSECTIA A DOUA LISTE
lista* intersectie(lista *L1, lista *L2) {
    lista *rezultat = NULL; // Initializam lista rezultat cu NULL (lista va contine elementele comune din cele doua liste)
    lista *ultim = NULL;    // Ultimul nod din lista rezultat, folosit pentru a adauga elemente noi la final
    lista *p1 = L1;         // Nodul curent pentru parcurgerea listei L1
    
    while (p1 != NULL) {    // Parcurgem lista L1
        lista *p2 = L2;     // Initializam un pointer pentru a parcurge lista L2
        while (p2 != NULL) { // Parcurgem lista L2 pentru fiecare element din L1
            if (p1->val == p2->val) { // Verificam daca valoarea curenta din L1 exista in L2
                bool exista = false; // Variabila pentru a verifica daca valoarea exista deja in lista rezultat
                lista *temp = rezultat; // Initializam un pointer pentru a parcurge lista rezultat
                
                // Verificam daca valoarea este deja prezenta in lista rezultat
                while (temp != NULL) {
                    if (temp->val == p1->val) { // Daca valoarea exista deja, setam exista pe true
                        exista = true;
                        break; // Iesim din while
                    }
                    temp = temp->urm; // Trecem la urmatorul nod
                }
                
                // Daca valoarea nu exista deja in lista rezultat, o adaugam
                if (!exista) {
                    lista *nou = new lista; // Cream un nou nod
                    nou->val = p1->val;     // Setam valoarea noului nod
                    nou->urm = NULL;        // Urmatorul nod este NULL (deoarece il adaugam la final)
                    
                    if (rezultat == NULL) { // Daca lista rezultat este goala
                        rezultat = nou;    // Noul nod devine primul nod din lista rezultat
                        ultim = nou;       // Ultimul nod din lista devine noul nod
                    } else {               // Daca lista rezultat nu este goala
                        ultim->urm = nou;  // Legam noul nod la finalul listei
                        ultim = nou;       // Actualizam ultimul nod ca fiind noul nod
                    }
                }
                break; // Iesim din while-ul pentru L2, deoarece valoarea a fost gasita
            }
            p2 = p2->urm; // Trecem la urmatorul nod din lista L2
        }
        p1 = p1->urm; // Trecem la urmatorul nod din lista L1
    }
    
    return rezultat; // Returnam lista rezultat care contine intersectia celor doua liste
}


// FUNCTIE PENTRU SCADEREA A DOUA LISTE
lista* scadere(lista *L1, lista *L2) {
    lista *rezultat = NULL; // Initializam lista rezultat cu NULL
    lista *ultim = NULL;    // Ultimul nod din lista rezultat
    lista *p1 = L1;         // Nodul curent pentru parcurgerea listei L1
    
    while (p1 != NULL) {    // Parcurgem lista L1
        bool exista = false; // Variabila pentru a verifica daca valoarea curenta din L1 exista in L2
        lista *p2 = L2;      // Nodul curent pentru parcurgerea listei L2
        
        // Verificam daca valoarea curenta din L1 exista in L2
        while (p2 != NULL) {
            if (p1->val == p2->val) { // Daca valoarea exista in L2, setam exista pe true
                exista = true;
                break; // Iesim din while
            }
            p2 = p2->urm; // Trecem la urmatorul nod din L2
        }
        
        // Daca valoarea nu exista in L2, o adaugam in lista rezultat
        if (!exista) {
            lista *nou = new lista; // Cream un nou nod
            nou->val = p1->val;     // Setam valoarea nodului
            nou->urm = NULL;        // Urmatorul nod este NULL
            
            if (rezultat == NULL) { // Daca lista rezultat este goala
                rezultat = nou;    // Noul nod devine primul nod din lista rezultat
                ultim = nou;       // Ultimul nod devine noul nod
            } else {               // Daca lista rezultat nu este goala
                ultim->urm = nou;  // Adaugam noul nod la final
                ultim = nou;       // Actualizam ultimul nod
            }
        }
        p1 = p1->urm; // Trecem la urmatorul nod din L1
    }
    
    return rezultat; // Returnam lista rezultat
}

// FUNCTIE PENTRU SCADEREA SIMETRICA A DOUA LISTE
lista* scadere_simetrica(lista *L1, lista *L2) {
    // Calculam diferenta dintre L1 si L2 si invers
    lista *diferenta1 = scadere(L1, L2);
    lista *diferenta2 = scadere(L2, L1);
    
    lista *rezultat = NULL; // Initializam lista rezultat cu NULL
    lista *ultim = NULL;    // Ultimul nod din lista rezultat
    
    // Adaugam elementele din prima diferenta in lista rezultat
    lista *p = diferenta1;
    while (p != NULL) {
        lista *nou = new lista; // Cream un nou nod
        nou->val = p->val;      // Setam valoarea nodului
        nou->urm = NULL;        // Urmatorul nod este NULL
        
        if (rezultat == NULL) { // Daca lista rezultat este goala
            rezultat = nou;    // Noul nod devine primul nod din lista rezultat
            ultim = nou;       // Ultimul nod devine noul nod
        } else {               // Daca lista rezultat nu este goala
            ultim->urm = nou;  // Adaugam noul nod la final
            ultim = nou;       // Actualizam ultimul nod
        }
        p = p->urm; // Trecem la urmatorul nod
    }
    
    // Adaugam elementele din a doua diferenta in lista rezultat
    p = diferenta2;
    while (p != NULL) {
        lista *nou = new lista; // Cream un nou nod
        nou->val = p->val;      // Setam valoarea nodului
        nou->urm = NULL;        // Urmatorul nod este NULL
        
        if (rezultat == NULL) { // Daca lista rezultat este goala (teoretic inutil aici)
            rezultat = nou;    // Noul nod devine primul nod din lista rezultat
            ultim = nou;       // Ultimul nod devine noul nod
        } else {               // Daca lista rezultat nu este goala
            ultim->urm = nou;  // Adaugam noul nod la final
            ultim = nou;       // Actualizam ultimul nod
        }
        p = p->urm; // Trecem la urmatorul nod
    }
    
    return rezultat; // Returnam lista rezultat
}

// FUNCTIE PENTRU SORTAREA UNEI LISTE
lista* sortare_lista(lista* cap) {
    if (cap == NULL || cap->urm == NULL) { // Daca lista este goala sau are un singur element, este deja sortata
        return cap;
    }
    
    lista *i, *j;
    int temp; // Variabila temporara pentru interschimbarea valorilor
    
    // Sortam lista folosind metoda Bubble Sort
    for (i = cap; i->urm != NULL; i = i->urm) { // Parcurgem lista cu i
        for (j = i->urm; j != NULL; j = j->urm) { // Parcurgem lista cu j, care porneste de la i->urm
            if (i->val > j->val) { // Daca valorile sunt in ordine gresita, le interschimbam
                temp = i->val;
                i->val = j->val;
                j->val = temp;
            }
        }
    }
    
    return cap; // Returnam lista sortata
}




int main() {
    lista *L1, *L2;
    int optiune;
    
    cout << "Crearea primei liste:\n";
    L1 = creare_lista_intregi();
    
    cout << "\nCrearea celei de-a doua liste:\n";
    L2 = creare_lista_intregi();
    
    do {
        cout << "\nMeniu operatii:\n";
        cout << "1. Reuniune\n";
        cout << "2. Intersectie\n";
        cout << "3. Scadere L1 - L2\n";
        cout << "4. Scadere simetrica\n";
        cout << "0. Iesire\n";
        cout << "Alegeti optiunea: ";
        cin >> optiune;
        
        switch(optiune) {
            case 1: {
    lista *rez = reuniune(L1, L2);
    cout << "Reuniunea listelor: ";
    parcurgere_lista(rez);
    
    cout << "\nDoriti sa sortati rezultatul? (1-Da/0-Nu): ";
    int optSortare;
    cin >> optSortare;
    switch(optSortare) {
        case 1:
            rez = sortare_lista(rez);
            cout << "Rezultatul sortat: ";
            parcurgere_lista(rez);
            break;
        case 0:
            break;
    }
    break;
}

case 2: {
    lista *rez = intersectie(L1, L2);
    cout << "Intersectia listelor: ";
    parcurgere_lista(rez);
    
    cout << "\nDoriti sa sortati rezultatul? (1-Da/0-Nu): ";
    int optSortare;
    cin >> optSortare;
    switch(optSortare) {
        case 1:
            rez = sortare_lista(rez);
            cout << "Rezultatul sortat: ";
            parcurgere_lista(rez);
            break;
        case 0:
            break;
    }
    break;
}

case 3: {
    lista *rez = scadere(L1, L2);
    cout << "Scaderea L1 - L2: ";
    parcurgere_lista(rez);
    
    cout << "\nDoriti sa sortati rezultatul? (1-Da/0-Nu): ";
    int optSortare;
    cin >> optSortare;
    switch(optSortare) {
        case 1:
            rez = sortare_lista(rez);
            cout << "Rezultatul sortat: ";
            parcurgere_lista(rez);
            break;
        case 0:
            break;
    }
    break;
}

case 4: {
    lista *rez = scadere_simetrica(L1, L2);
    cout << "Scaderea simetrica: ";
    parcurgere_lista(rez);
    
    cout << "\nDoriti sa sortati rezultatul? (1-Da/0-Nu): ";
    int optSortare;
    cin >> optSortare;
    switch(optSortare) {
        case 1:
            rez = sortare_lista(rez);
            cout << "Rezultatul sortat: ";
            parcurgere_lista(rez);
            break;
        case 0:
            break;
    }
    break;
}

          

            case 0:
                cout << "Program incheiat!\n";
                break;
            default:
                cout << "Optiune invalida!\n";
        }
    } while(optiune != 0);
    
    return 0;
}


