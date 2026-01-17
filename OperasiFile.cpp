#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    // membuka file untuk MENULIS
    ofstream fileku("data.txt");

    if (!fileku.is_open()) {
        cout << "File gagal dibuat\n";
        return 1;
    }

    // menulis isi file
    fileku << "prak.pemrog dasar\n";
    fileku << "hujan deras";
    fileku.close();

    // membaca & menampilkan isi file
    string temp;
    ifstream namaBerkas("data.txt");

    cout << "Isi file:\n";
    while (getline(namaBerkas, temp)) {
        cout << temp << endl;
    }

    namaBerkas.close();

    return 0;
}
