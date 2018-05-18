//
//  main.cpp
//  td
//
//  Created by Ibrahim El Mountasser on 18/05/2018.
//  Copyright © 2018 Ibrahim El Mountasser. All rights reserved.
//

#include <iostream>
using namespace std;
class Employee {
protected:
    int matricule;
    string nom;
public:
    Employee(int matricule,string nom):matricule(matricule),nom(nom) {
        
    }
    void affiche() {
        cout<<"je m'appelle: "<<nom<<" Mon matricule est "<<matricule<<endl;
    }
    virtual double salaire() {
        return 0;
    }
};
class Ouvrier: public Employee {
private:
    int anciennete_en_annee;
public:
    Ouvrier(int m, string n, int a):Employee(m,n) {
        anciennete_en_annee = a;
    }
    void affiche() {
        Employee::affiche();
        cout<<"mon anciennete est : "<<anciennete_en_annee<<endl;
    }
    double salaire() {
        return 2500 + (anciennete_en_annee*100);
    }
};




class Cadre: public Employee {
private:
    int indice;
public:
    Cadre(int m, string n, int i):Employee(m,n) {
        indice = i;
    }
    void affiche() {
        Employee::affiche();
        cout<<"mon indice est: "<<indice<<endl;
    }
    double salaire() {
        switch (indice) {
            case 1:
                return 13000;
                break;
            case 2:
                return 15000;
                break;
            case 3:
                return 17000;
                break;
            case 4:
                return 20000;
                break;
                
            default:
                return 0;
                break;
        }
    }
};
void utilise(Employee &m) {
    cout<<"Mon salaire est : "<<m.salaire()<<endl;
}
int main() {
    Ouvrier o(2323,"ahmed",4);
    Cadre c(454,"yassin",2);
//    Employee *m;
//    m=&o;
//    m->affiche();
    o.affiche();
    utilise(o);
    c.affiche();
    utilise(c);
}
























