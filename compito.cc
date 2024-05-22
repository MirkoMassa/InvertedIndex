#include "liste.h"
#include "parola.h"

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

parola* load(int& dim) {
    ifstream inputFile("inverted"); 

    string line; 
    getline(inputFile, line);
    dim = stoi(line);
    parola *parole = new parola[dim];

    for (int i = 0; i < dim; ++i) {
        // Read the word

        getline(inputFile, line);
        // cout << line << endl;
        strncpy(parole[i].p, line.c_str(), sizeof(parole[i].p) - 1);
        parole[i].p[sizeof(parole[i].p) - 1] = '\0';

        getline(inputFile, line);
        parole[i].n_doc = stoi(line);

        // Read the first document ID and create the head of the list
        getline(inputFile, line);
        int docID = stoi(line);
        parole[i].l = new_elem(docID);

        elem* currElem = parole[i].l;

        // Read the remaining document IDs and append to the list
        for (int j = 0; j < parole[i].n_doc - 1; ++j) {
            getline(inputFile, line);
            docID = stoi(line);
            elem* idElem = new_elem(docID);
            currElem = insert_elem(currElem, idElem);
        }
    }
    
    inputFile.close();

    
  
    return parole; 
}

void stampa(parola* p,int n) {
    cout << "L'inverted index e' composto come segue:" << endl;

    for (size_t i = 0; i < n; i++) {
        parola currParola = p[i];

        cout << "'" << currParola.p << "' in "<< currParola.n_doc << " documenti : " << endl;

        lista docs = currParola.l;
        cout << "doc " << docs->inf << endl;

        for (size_t j = 0; j < p->n_doc-1; j++){
            cout << "doc " << docs->inf << endl;
            docs = docs->pun;
        }
        
    }
    
}