#include <iostream>
#include <string>
using namespace std;

const string username = "Admin";
const int password = 123456;
const int MAX = 200;

struct Kendaraan
{
    string platNomor[MAX];
    string tipeKendaraan[MAX];
    int lamaParkir[MAX];
    int id[MAX];
    int awal = 0, akhir = 0;
} antrean;

void init()
{
    antrean.awal = 0;
    antrean.akhir = 0;
}

bool cekKosong()
{
    return (antrean.akhir == 0);
}

bool parkiranPenuh()
{
    return (antrean.akhir == MAX);
}

void inputData(int jmlKendaraan)
{
    string temp1;
    int temp2, type;

    cout << "Masukkan Jumlah Kendaraan: ";
    cin >> jmlKendaraan;
    for (int i = 0; i < jmlKendaraan && antrean.akhir < MAX; i++)
    {
        cout << "\nAntrean Nomor [" << antrean.akhir + 1 << "]" << endl;
        cout << "-------------------------------" << endl;
        cout << "Tarif Kendaraan" << endl;
        cout << "1. Mobil | Biaya: Rp. 4000 / jam" << endl;
        cout << "2. Motor | Biaya: Rp. 2000 / jam" << endl;
        cout << "-------------------------------" << endl;
        cout << endl;
        cout << "Masukkan tipe kendaraan: ";
        cin >> type;

        if (type == 1)
            antrean.tipeKendaraan[antrean.akhir] = "Mobil";
        else if (type == 2)
            antrean.tipeKendaraan[antrean.akhir] = "Motor";

        cout << "Masukkan plat nomor: ";
        cin >> temp1;
        cout << "Masukkan lama parkir (jam): ";
        cin >> temp2;

        antrean.platNomor[antrean.akhir] = temp1;
        antrean.id[antrean.akhir] = antrean.akhir;
        antrean.lamaParkir[antrean.akhir] = temp2;
        antrean.akhir++;

        cout << "Berhasil menambahkan data." << endl;
        cout << endl;
    }
}

void cekKendaraan()
{
    for (int i = antrean.awal; i < antrean.akhir; i++)
    {
        cout << "Antrean Kendaraan Nomor: " << antrean.id[i] + 1 << endl;
        cout << "Tipe Kendaraan\t: " << antrean.tipeKendaraan[i] << endl;
        cout << "Plat Nomor\t: " << antrean.platNomor[i] << endl;
        cout << "Lama Parkir\t: " << antrean.lamaParkir[i] << " jam | Biaya: Rp. ";
        cout << (antrean.tipeKendaraan[i] == "Mobil" ? antrean.lamaParkir[i] * 4000 : antrean.lamaParkir[i] * 2000) << endl;
        cout << endl;
    }
}

void kendaraanKeluar(const string &user)
{
    if (cekKosong())
    {
        cout << "Silahkan input kendaraan terlebih dahulu!" << endl;
        return;
    }

    string platKendaraan;
    cout << "Masukkan plat kendaraan yang keluar: ";
    cin >> platKendaraan;

    int index;
    for (index = antrean.awal; index < antrean.akhir; index++)
    {
        if (antrean.platNomor[index] == platKendaraan)
            break;
    }

    if (index == antrean.akhir)
    {
        cout << "Kendaraan dengan plat nomor " << platKendaraan << " tidak ditemukan!" << endl;
        return;
    }

    cout << "Kendaraan dengan plat nomor " << platKendaraan << " berhasil keluar." << endl;
    cout << "---------------------------------" << endl;
    cout << "           STRUK PARKIR" << endl;
    cout << "---------------------------------" << endl;
    cout << "|User           : " << user << "\t\t|"<< endl;
    cout << "|Tipe Kendaraan : " << antrean.tipeKendaraan[index] << "\t\t|" << endl;
    cout << "|Plat Nomor     : " << antrean.platNomor[index] << "\t|" << endl;
    cout << "|Lama Parkir    : " << antrean.lamaParkir[index] << " jam" << "\t\t|" << endl;
    cout << "|Biaya Parkir   : Rp. " << (antrean.tipeKendaraan[index] == "Mobil" ? antrean.lamaParkir[index] * 4000 : antrean.lamaParkir[index] * 2000) << "\t|" << endl;
    cout << "---------------------------------";

    // Menggeser data kendaraan setelah kendaraan keluar
    for (int i = index; i < antrean.akhir - 1; i++)
    {
        antrean.platNomor[i] = antrean.platNomor[i + 1];
        antrean.tipeKendaraan[i] = antrean.tipeKendaraan[i + 1];
        antrean.lamaParkir[i] = antrean.lamaParkir[i + 1];
        antrean.id[i] = antrean.id[i + 1];
    }
    antrean.akhir--;
}

int main()
{
    int jmlKendaraan, pil;
    string cari;
    init();

    cout << "=========================================" << endl;
    cout << "\tPROGRAM PARKIR TELYUP" << endl;
    cout << "=========================================" << endl;
    cout << "Silahkan Login" << endl;

    int pass;
    string user;
    int coba = 3;

    while (coba > 0)
    {
        cout << "\nUsername : ";
        cin >> user;
        cout << "Password : ";
        cin >> pass;

        if (username == user && password == pass)
        {
            cout << "\nSelamat Bekerja " << user << "!!!" << endl;
            break;
        }
        else
        {
            cout << "Username dan Password Keliru" << endl;
            coba--;
            cout << "\nSisa Kesempatan Login : " << coba << endl;
            if (coba == 0)
            {
                cout << "Akun Anda Terblokir" << endl;
                return 0;
            }
        }
    }

    do
    {
        cout << "\n------------ PROGRAM PARKIR TELYUP -----------" << endl;
        cout << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "| Menu:\t\t\t\t\t\t\t|" << endl;
        cout << "| 1. Kendaraan Masuk\t\t\t\t\t|" << endl;
        cout << "| 2. Lihat Kendaraan\t\t\t\t\t|" << endl;
        cout << "| 3. Kendaraan Keluar\t\t\t\t\t|" << endl;
        cout << "| 4. Data Berdasarkan Lama Parkir\t\t\t|" << endl;
        cout << "| 5. Cari Kendaraan (Plat Nomor)\t\t\t|" << endl;
        cout << "| 6. Keluar\t\t\t\t\t\t|" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << endl;

        cout << "Masukan pilihan: ";
        cin >> pil;

        switch (pil)
        {
        case 1:
            if (parkiranPenuh())
            {
                cout << "\nParkiran Sudah Penuh!" << endl;
            }
            else
            {
                inputData(jmlKendaraan);
            }
            break;
        case 2:
            if (cekKosong())
            {
                cout << "\nSilahkan input kendaraan terlebih dahulu!" << endl;
            }
            else
            {
                cout << "\n\t~~Daftar Kendaraan~~" << endl;
                cout << endl;
                cekKendaraan();
            }
            break;
        case 3:
            if (cekKosong())
            {
                cout << "\nSilahkan input kendaraan terlebih dahulu!" << endl;
            }
            else
            {
                kendaraanKeluar(username);
            }
            cekKendaraan();
            break;
        }
    } while (pil != 6);

    return 0;
}
