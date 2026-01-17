#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

struct Siswa {
    int nomor;
    string nama;
    int nilai;
};

int main() {
    ifstream file("bacaAku.txt");
    vector<Siswa> data;

    if (!file.is_open()) {
        cout << "File tidak bisa dibuka\n";
        return 1;
    }

    string baris;
    while (getline(file, baris)) {
        if (baris.empty()) continue;

        Siswa s;
        char pemisah;

        stringstream ss(baris);

        // format: nomor; nama; nilai;
        ss >> s.nomor >> pemisah;   // baca nomor dan ;
        ss >> ws;                  // buang spasi
        getline(ss, s.nama, ';');  // baca nama
        ss >> s.nilai;             // baca nilai

        data.push_back(s);
    }

    file.close();

    // OUTPUT
    cout << left
        << setw(6) << "No"
        << setw(10) << "Nama"
        << setw(6) << "Nilai" << endl;
    cout << "--------------------\n";

    for (const auto& s : data) {
        cout << left
            << setw(6) << s.nomor
            << setw(10) << s.nama
            << setw(6) << s.nilai << endl;
    }

    return 0;
}
