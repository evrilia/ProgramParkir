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
    string jamMasuk[MAX];
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
    string temp1, temp2; // Variabel sementara untuk menyimpan plat nomor kendaraan
    int type;            // Variabel sementara untuk menyimpan jam masuk dan tipe kendaraan

    cout << "Masukkan Jumlah Kendaraan: ";
    cin >> jmlKendaraan;

    // membersihkan layar terminal
    system("cls");
    for (int i = 0; i < jmlKendaraan && antrean.akhir < MAX; i++)
    {
        cout << "\nAntrean Nomor [" << antrean.akhir + 1 << "]" << endl; // Menampilkan nomor antrean
        cout << "-------------------------------" << endl;
        cout << "Tarif Kendaraan" << endl;
        cout << "1. Mobil | Biaya: Rp. 4000 / jam" << endl;
        cout << "2. Motor | Biaya: Rp. 2000 / jam" << endl;
        cout << "-------------------------------" << endl;
        cout << endl;
        cout << "Masukkan tipe kendaraan: ";
        cin >> type; // Mengambil input tipe kendaraan dari pengguna

        if (type == 1)
            antrean.tipeKendaraan[antrean.akhir] = "Mobil";
        else if (type == 2)
            antrean.tipeKendaraan[antrean.akhir] = "Motor";

        cout << "Plat Nomor: ";
        cin >> temp1; // Mengambil input plat nomor kendaraan dari pengguna
        cout << "Jam: ";
        cin >> temp2; // Mengambil input jam masuk kendaraan dari pengguna

        // Menyimpan plat nomor kendaraan pada indeks tertentu di dalam array
        antrean.platNomor[antrean.akhir] = temp1;
        antrean.id[antrean.akhir] = antrean.akhir;
        antrean.jamMasuk[antrean.akhir] = temp2;
        antrean.akhir++;

        cout << "Berhasil menambahkan data." << endl;
        cout << endl;
        // membersihkan layar terminal
        system("cls");
    }
}

void cekKendaraan()
{
    for (int i = antrean.awal; i < antrean.akhir; i++)
    {
        // Menampilkan informasi kendaraan dalam antrian
        cout << "Antrean Kendaraan Nomor: " << antrean.id[i] + 1 << endl;
        cout << "Tipe Kendaraan\t: " << antrean.tipeKendaraan[i] << endl;
        cout << "Plat Nomor\t: " << antrean.platNomor[i] << endl;
        cout << "Jam\t\t: " << antrean.jamMasuk[i] << endl;
    }
    // press enter to continue
    cout << "Tekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void kendaraanKeluar(const string &user)
{
    if (cekKosong())
    {
        cout << "Silahkan input kendaraan terlebih dahulu!" << endl;
        cout << "Tekan Enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
        return;
    }

    string platKendaraan;
    cout << "Masukkan plat kendaraan yang keluar: ";
    cin >> platKendaraan;

    system("cls");

    int index;
    bool kendaraanDitemukan = false;
    for (index = antrean.awal; index < antrean.akhir; index++)
    {
        if (antrean.platNomor[index] == platKendaraan)
        {
            kendaraanDitemukan = true;
            break;
        }
    }

    if (!kendaraanDitemukan)
    {
        cout << "Kendaraan dengan plat nomor " << platKendaraan << " tidak ditemukan!" << endl;
        cout << "Tekan Enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
        return;
    }

    int lamaParkirBaru;
    cout << "Masukkan lama parkir kendaraan (jam): ";
    cin >> lamaParkirBaru;

    antrean.lamaParkir[index] = lamaParkirBaru;

    // Menyimpan data lama parkir dan menghitung biaya parkir
    int biayaParkir = (antrean.tipeKendaraan[index] == "Mobil") ? lamaParkirBaru * 4000 : lamaParkirBaru * 2000;

    // Menyimpan data struk parkir sebelum menggeser elemen array
    string platNomor = antrean.platNomor[index];
    string tipeKendaraan = antrean.tipeKendaraan[index];
    string jamMasuk = antrean.jamMasuk[index];

    // Menggeser elemen array setelah kendaraan keluar
    for (int i = index; i < antrean.akhir - 1; i++)
    {
        antrean.tipeKendaraan[i] = antrean.tipeKendaraan[i + 1];
        antrean.platNomor[i] = antrean.platNomor[i + 1];
        antrean.jamMasuk[i] = antrean.jamMasuk[i + 1];
        antrean.lamaParkir[i] = antrean.lamaParkir[i + 1];
    }

    antrean.akhir--; // Mengurangi jumlah kendaraan yang terdaftar

    system("cls");
    cout << "Kendaraan dengan plat nomor " << platKendaraan << " berhasil keluar." << endl;
    cout << "---------------------------------" << endl;
    cout << "           STRUK PARKIR" << endl;
    cout << "---------------------------------" << endl;
    cout << "|User           : " << user << "\t\t|" << endl;
    cout << "|Tipe Kendaraan : " << tipeKendaraan << "\t\t|" << endl;
    cout << "|Plat Nomor     : " << platNomor << "\t|" << endl;
    cout << "|Jam Masuk      : " << jamMasuk << "\t\t|" << endl;
    cout << "|Lama Parkir    : " << lamaParkirBaru << " jam"
         << "\t\t|" << endl;
    cout << "|Biaya Parkir   : Rp. " << biayaParkir << "\t|" << endl;
    cout << "---------------------------------" << endl;
    cout << "Tekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void sortJamMasuk()
{
    string temp;
    string tempPlat;
    string tempTipe;

    for (int i = antrean.awal; i < antrean.akhir - 1; i++)
    {
        for (int j = antrean.awal; j < antrean.akhir - i - 1; j++)
        {
            if (antrean.jamMasuk[j] > antrean.jamMasuk[j + 1])
            {
                // Menukar jamMasuk
                temp = antrean.jamMasuk[j];
                antrean.jamMasuk[j] = antrean.jamMasuk[j + 1];
                antrean.jamMasuk[j + 1] = temp;

                // Menukar platNomor
                tempPlat = antrean.platNomor[j];
                antrean.platNomor[j] = antrean.platNomor[j + 1];
                antrean.platNomor[j + 1] = tempPlat;

                // Menukar tipeKendaraan
                tempTipe = antrean.tipeKendaraan[j];
                antrean.tipeKendaraan[j] = antrean.tipeKendaraan[j + 1];
                antrean.tipeKendaraan[j + 1] = tempTipe;
            }
        }
    }
}

void cariKendaraan(string cari) // sequential search
{
    system("cls"); // Membersihkan layar terminal
    int ind[MAX];
    int j = 0;
    bool ditemukan = false;

    // Mencari kendaraan berdasarkan nomor plat
    for (int i = antrean.awal; i < antrean.akhir; i++)
    {
        if (antrean.platNomor[i] == cari)
        {
            ind[j] = i;
            j++;
            ditemukan = true;
        }
    }

    if (ditemukan)
    {
        // Menampilkan data kendaraan yang ditemukan
        cout << "Plat Nomor Kendaraan " << cari << " Ditemukan" << endl;
        cout << "Data kendaraan yang ditemukan:" << endl;
        for (int k = 0; k < j; k++)
        {
            int index = ind[k];
            cout << "-----------------------------------" << endl;
            cout << "Nomor Plat     : " << antrean.platNomor[index] << endl;
            cout << "Tipe Kendaraan : " << antrean.tipeKendaraan[index] << endl;
            cout << "Jam            : " << antrean.jamMasuk[index] << endl;
            cout << "-----------------------------------" << endl;
        }
        // press enter to continue
        cout << "Tekan Enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
    }
    else
    {
        // Menampilkan pesan jika data tidak ditemukan
        cout << "Data tidak ditemukan!" << endl;
    }
}

int main()
{
    system("cls"); // Membersihkan layar terminal
    int jmlKendaraan, pil;
    string cari;

    init(); // Memanggil fungsi init untuk inisialisasi

    // Tampilan awal program parkir
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

        // Verifikasi username dan password
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

            // Akun terblokir jika percobaan login melebihi 3 kali
            if (coba == 0)
            {
                cout << "Akun Anda Terblokir" << endl;
                return 0;
            }
        }
    }

    // Menu utama program parkir
    do
    {
        system("cls"); // Membersihkan layar terminal
        cout << "\n--------- PROGRAM PARKIR TELYUP ---------" << endl;
        // Menampilkan menu pilihan
        cout << "| Menu:\t\t\t\t\t|" << endl;
        cout << "| 1. Kendaraan Masuk\t\t\t|" << endl;
        cout << "| 2. Lihat Kendaraan\t\t\t|" << endl;
        cout << "| 3. Kendaraan Keluar\t\t\t|" << endl;
        cout << "| 4. Data Berdasarkan Jam Masuk\t\t|" << endl;
        cout << "| 5. Cari Kendaraan (Plat Nomor)\t|" << endl;
        cout << "| 6. Keluar\t\t\t\t|" << endl;
        cout << "-----------------------------------------" << endl;
        cout << endl;

        cout << "Masukan pilihan: ";
        cin >> pil; // Meminta input pilihan menu

        // Melakukan aksi sesuai dengan pilihan menu yang dimasukkan
        switch (pil)
        {
        case 1:
            // Memeriksa apakah parkiran sudah penuh atau belum
            if (parkiranPenuh())
            {
                // membersihkan layar terminal
                system("cls");
                cout << "\nParkiran Sudah Penuh!" << endl;
            }
            else
            {
                // membersihkan layar terminal
                system("cls");
                inputData(jmlKendaraan); // Memasukkan data kendaraan
            }
            break;
        case 2:
            // Memeriksa apakah tidak ada data kendaraan yang dimasukkan
            if (cekKosong())
            {
                // membersihkan layar terminal
                system("cls");
                cout << "\nSilahkan input kendaraan terlebih dahulu!" << endl;
            }
            else
            {
                // membersihkan layar terminal
                system("cls");
                cout << "\n\t~~Daftar Kendaraan~~" << endl;
                cekKendaraan(); // Menampilkan data kendaraan
            }
            break;
        case 3:
            // Memeriksa apakah tidak ada data kendaraan yang dimasukkan
            if (cekKosong())
            {
                // membersihkan layar terminal
                system("cls");
                cout << "\nSilahkan input kendaraan terlebih dahulu!" << endl;
            }
            else
            {
                // membersihkan layar terminal
                system("cls");
                kendaraanKeluar(username); // Memproses kendaraan yang keluar
            }
            // cekKendaraan();
            break;
        case 4:
            // Memeriksa apakah tidak ada data kendaraan yang dimasukkan
            if (cekKosong())
            {
                // membersihkan layar terminal
                system("cls");
                cout << "\nSilahkan input Kendaraan terlebih dahulu!" << endl;
            }
            else
            {
                // membersihkan layar terminal
                system("cls");
                sortJamMasuk(); // Mengurutkan data kendaraan berdasarkan jam masuk
            }
            cekKendaraan();
            break;

        case 5:
            // membersihkan layar terminal
            system("cls");
            // Meminta input plat nomor untuk mencari kendaraan
            cout << "\nMasukan plat kendaraan yang ingin dicari: ";
            cin >> cari;
            cariKendaraan(cari); // Melakukan pencarian kendaraan berdasarkan plat nomor
            break;
        case 6:
            // membersihkan layar terminal
            system("cls");
            cout << "\nKeluar Dari Program..." << endl;
            break;
        default:
            // membersihkan layar terminal
            system("cls");
            cout << "\nMasukkan pilihan sesuai di menu!" << endl;
            break;
        }
    } while (pil != 6); // Program berjalan hingga pilihan menu 6 (Keluar)

    return 0;
}