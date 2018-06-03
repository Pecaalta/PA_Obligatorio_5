/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InterfazGrafica.cpp
 * Author: mauro
 * 
 * Created on 3 de junio de 2018, 16:17
 */

#include "InterfazGrafica.h"
#include "iostream"
int ancho = 120;
string tab = "    ";
bool Contli = true;
int ContOl = 0;

int CinInt() {
    cout << endl << "\t>";
    string texto;
    fflush(stdin);
    getline(cin, texto);
    int ret = 0, aux = 0, pow = 1;
    for (int i = texto.size() - 1; i >= 0; i--) {
        aux = ((int) texto[i] - 48);
        if (aux <= 9 and aux >= 0) {
            ret += pow * aux;
            pow *= 10;
        } else {
            return -1;
        }
    }
    return ret;
};

int CinInt(string texto) {
    cout << "\t " << texto << ": ";
    fflush(stdin);
    getline(cin, texto);
    int ret = 0, aux = 0, pow = 1;
    for (int i = texto.size() - 1; i >= 0; i--) {
        aux = ((int) texto[i] - 48);
        if (aux <= 9 and aux >= 0) {
            ret += pow * aux;
            pow *= 10;
        } else {
            return -1;
        }
    }
    return ret;
};

string CinString() {
    string texto;
    cout << endl << "\t>";
    fflush(stdin);
    getline(cin, texto);
    return texto;
};

string CinString(string texto) {
    cout << "\t " << texto << ": ";
    fflush(stdin);
    getline(cin, texto);
    return texto;
};

void header(string texto) {
    system("cls");
    char ASCII[] = {(char) 205, (char) 186, (char) 201, (char) 187, (char) 188, (char) 200, (char) 196};
    int anchoImprimible = (ancho - 10);
    int spacio = (anchoImprimible - texto.size()) / 2;
    int var1 = (spacio * 2);
    int var2 = anchoImprimible - texto.size();
    cout << endl;
    cout << tab << ASCII[2];
    for (int i = 0; i < anchoImprimible; i++) {
        cout << ASCII[0];
    }
    cout << ASCII[3] << endl;

    cout << tab << ASCII[1];
    for (int i = 0; i < spacio; i++) {
        cout << " ";
    }
    cout << texto;
    if (var1 != var2) {
        cout << " ";
    }
    for (int i = 0; i < spacio; i++) {
        cout << " ";
    }
    cout << ASCII[1] << endl;

    cout << tab << ASCII[5];
    for (int i = 0; i < anchoImprimible; i++) {
        cout << ASCII[0];
    }
    cout << ASCII[4] << endl;
    cout << endl;
};

void Subheader(string texto) {
    int anchoImprimible = (ancho - 20);
    int spacio = (anchoImprimible - texto.size()) / 2;
    int var1 = (spacio * 2);
    int var2 = anchoImprimible - texto.size();
    cout << tab << tab << "<";
    for (int i = 0; i < spacio; i++) {
        cout << "-";
    }

    cout << " " << texto << " ";

    if (var1 != var2) {
        cout << " ";
    }

    for (int i = 0; i < spacio; i++) {
        cout << "-";
    }
    cout << ">" << endl;
    cout << endl;
};

void li() {
    int anchoImprimible = ancho - (tab.size() * 4) - 2;
    cout << tab << tab;
    if (Contli) {
        cout << (char) 218;
        for (int i = 0; i < anchoImprimible; i++) {
            cout << (char) 196;
        }
        cout << (char) 191;
    } else {

        cout << (char) 192;
        for (int i = 0; i < anchoImprimible; i++) {
            cout << (char) 196;
        }
        cout << (char) 217;
    }
    cout << endl;
    Contli = !Contli;
}

void li(string texto) {
    int anchoImprimible = ancho - (tab.size() * 4) - 3;
    if (texto.compare("-") != 0) {
        cout << tab << tab << (char) 179 << " ";
        if (anchoImprimible > texto.size()) {
            cout << texto;
            anchoImprimible -= texto.size();
            for (int i = 0; i < anchoImprimible; i++) {
                cout << " ";
            }
        } else {
            anchoImprimible -= 4;
            for (int i = 0; i < anchoImprimible; i++) {
                cout << texto[i];
            }
            cout << "... ";
        }
        cout << (char) 179 << endl;
    } else {
        anchoImprimible += 1;
        cout << tab << tab << (char) 195;
        for (int i = 0; i < anchoImprimible; i++) {
            cout << (char) 196;
        }
        cout << (char) 180;
        cout << endl;
    }
}

void ol(string texto) {
    ContOl++;
    int anchoImprimible = ancho - (tab.size() * 4) - 5;
    cout << tab << tab;
    printf("%-3d",ContOl);     
    cout << " - ";
    if (anchoImprimible > texto.size()) {
        cout << texto;
        anchoImprimible -= texto.size();
    } else {
        anchoImprimible -= 4;
        for (int i = 0; i < anchoImprimible; i++) {
            cout << texto[i];
        }
        cout << "... ";
    }
    cout << endl;
}
void ol() {
    ContOl = 0;
}
int olNum() {
    return (ContOl-1);
}
