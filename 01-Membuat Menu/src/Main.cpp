
#include <iostream>
#include <string>

using namespace std;

int PilihOpsi ();

int main () {

    int opsi = PilihOpsi ();
    char lanjut;

    enum Pilihan {BUAT = 1, TAMPIL, UBAH, HAPUS, SELESAI};

    while (opsi != SELESAI) {

        switch (opsi) {

            case BUAT :
            cout << "\nMenambahkan data agent" << endl;
            break;

            case TAMPIL :
            cout << "\nMenampilkan data agent" << endl;
            break;

            case UBAH : 
            cout << "\nMengubah data agent" << endl;
            break;

            case HAPUS :
            cout << "\nMenghapus data agent" << endl;
            break;

            default :
            cout << "\nInput Error !!!" << endl;
            break;

        }

        cout << "\nLanjutkan? (y/n) : ";
        std::cin >> lanjut;

        if (lanjut == 'y' || lanjut == 'Y') {
            opsi = PilihOpsi ();
        }
        else if (lanjut == 'n' || lanjut == 'N') {
            break;
        }
        else {
            cout << "Input Error\n" << endl;
        }

    }

    cout << "\nSelesai\n" << endl;

    return 0;

}

int PilihOpsi () {

    int input;
    system ("cls");

    cout << "\tDATA AGENT" << endl;
    cout << "=============================\n" << endl;

    cout << "1. Tambah data agent" << endl;
    cout << "2. Tampilkan data agent" << endl;
    cout << "3. Ubah data agent" << endl;
    cout << "4. Hapus data agent" << endl;
    cout << "5. Selesai" << endl;

    cout << "*******************************\n" << endl;

    cout << "Pilih (1-5) : ";
    std::cin >> input;
    
    return input;

}