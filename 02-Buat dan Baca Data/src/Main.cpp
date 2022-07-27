
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Agent {

    int index;    
    string nama;
    string kode;
    string unit;
    string rank;

};

int PilihOpsi ();
void CekDatabase (fstream &nama_file);

//Perintah tiap opsi
void Buat (fstream &nama_file);
void Tampil (fstream &nama_file);

int main () {

    fstream myFile;
    CekDatabase (myFile);

    //Buat (orang, myFile);

    int opsi = PilihOpsi ();
    char lanjut;

    enum Pilihan {BUAT = 1, TAMPIL, UBAH, HAPUS, SELESAI};

    while (opsi != SELESAI) {

        switch (opsi) {

            case BUAT :
            Buat (myFile);
            break;

            case TAMPIL :
            Tampil (myFile);
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
    //system ("cls");

    cout << "\n\tDATA AGENT" << endl;
    cout << "=============================\n" << endl;

    cout << "1. Tambah data agent" << endl;
    cout << "2. Tampilkan data agent" << endl;
    cout << "3. Ubah data agent" << endl;
    cout << "4. Hapus data agent" << endl;
    cout << "5. Selesai" << endl;

    cout << "*******************************\n" << endl;

    cout << "Pilih (1-5) : ";
    cin >> input;
    //cin.ignore(numeric_limits<streamsize>::max(),'\n');
    
    return input;

}

void CekDatabase (fstream &nama_file) {
    
    nama_file.open ("data.txt", ios::app | ios::out | ios::in);
    
    //cek data.bin ada atau tidak
    if (nama_file.is_open ()) {
        cout << "Database ada" << endl;
    }
    else { 
        cout << "Database tidak ada, maka dibuatkan database nya" << endl;
        nama_file.close ();
        nama_file.open ("data.txt", ios::app | ios::out | ios::in);
    }

}

// Perintah tiap opsi

void Buat (fstream &nama_file) {

    cout << "\nMenambahkan data agent\n" << endl;

    Agent orang;

    orang.index = 1;

    cout << "Masukan nama agent : ";
    cin >> orang.nama;
    cout << "Masukan kode agent : ";
    cin >> orang.kode;
    cout << "Masukan unit agent : ";
    cin >> orang.unit;
    cout << "Masukan rank agent : ";
    cin >> orang.rank;

    //nama_file.open ("data.txt", ios::out | ios::app);

    nama_file << orang.nama << "\t| ";
    nama_file << orang.kode << "\t| ";
    nama_file << orang.unit << "\t| ";
    nama_file << orang.rank << "\t| \n";

    cout << "\nData agent " << orang.nama << " sudah di masukkan ke dalam database\n"<< endl;

}

void Tampil (fstream &nama_file) {

    cout << "\nMenampilkan data agent\n" << endl;   

    Agent orang;
    string hasil_baca;

    while (!nama_file.eof ()) {
        getline (nama_file, hasil_baca);
        cout << hasil_baca << endl;
    }

    //nama_file.close ();

    cout << endl;

}   