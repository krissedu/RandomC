#include <iostream>
#include <cstdlib>
#include <ctime>
#define maxpemain 10
using namespace std;

struct pemain
{
	string nickname;
    int scorebatuguntingkertas;
    int scoretebakangka;
    int scoretotal;
};

struct Tumpukan
{
    int atas;
    pemain data[maxpemain];
} T;

void awal()
{
    T.atas= -1;
}

int searching(string nama);
void buatakun();
void masukakun();
void menu2(int cek);
void Mengurutkan();
void hapusplayernoob();
void tampilhighscore();
void batuguntingkertas(int cek);
void tebakangka(int cek);
void keluar();

int main()
{
    awal();
    int pilihan;
    
    while(true)
    {
    	cout <<"======== Welcome to arcade program =========";
    	cout <<"\n =============== Menu Utama =============== \n";
        cout<<"1. buat akun\n";
        cout<<"2. masuk akun\n";
        cout<<"3. Tampil highscore\n";
        cout<<"4. hapus pemain dengan skor terendah\n";
        cout<<"5. Bersihkan data\n";
        cout<<"6. Keluar\n";

        cout<<"Masukan Pilihan Anda : ";
        cin>>pilihan;

        system("cls");

        switch(pilihan) 
        {
            case 1: buatakun();
                break;
            case 2: masukakun();
                break;
            case 3: tampilhighscore();
                break;
            case 4: hapusplayernoob();
                break;
            case 5: awal();
                break;
            case 6: keluar();
                cout << "Keluar dari program" << endl;
                break;
            default:
                cout << "Pilihan tidak tersedia" << endl;
                break;
        }
    }
}

int searching(string nama)
{
    int cek = -1;
	for(int i = 0 ; i <= T.atas+1 ; i++)
	{
		if (T.data[i].nickname == nama)
		{
            cek = i;
		}
	}
    return cek;
}

void buatakun() 
{
    string nama;
    if (T.atas == maxpemain-1) 
    {
        cout << "Sudah mencapai max pemain\n";
        return;
    } else
    {
        cout << "\n====== Masukkan data ======\n ";
        cout << "\nMasukan Nickname = ";
        cin >> nama;

        if (searching(nama) == -1 )
        {
            T.atas++;
            T.data[T.atas].nickname = nama;
            T.data[T.atas].scorebatuguntingkertas = 0;
            T.data[T.atas].scoretebakangka = 0;
            T.data[T.atas].scoretotal = 0;
            cout << "akun " << nama << " berhasil dibuat \n";
        } else
        {
            cout << "\nakun dengan nama itu sudah ada !\n ";
        }
    }
    cout << "\nenter untuk kembali"<<endl;
    cin.sync();
    cin.get();
    system("cls");
}

void masukakun()
{
    string nama;
  
    cout << "\n====== Masukkan data ======\n ";
    cout << "Masukan Nama = ";
    cin >> nama;
    system("cls");

    int lokasi = searching(nama);

    if(lokasi != -1)
    {
        menu2(lokasi);
    }
    else
    {
        cout << "akun tidak ditemukan,enter untuk kembali\n ";
        cin.sync();
        cin.get();
        system("cls");
    }
    return;
}

void menu2(int lokasi)
{
    int pilihan = 0;
    
    while (pilihan != 3)
    {
        cout <<"\n=========== menu 2 ============ \n";
        cout <<"selamat datang " << T.data[lokasi].nickname << endl;
        cout <<"Apa yang ingin kamu mainkan ?" << endl;

        cout<<"1. batu , gunting , kertas\n";
        cout<<"2. tebak angka\n";
        cout<<"3. keluar\n";

        cout<<"Masukan Pilihan Anda : ";
        cin>>pilihan;

        system("cls");

        switch(pilihan)
        {
            case 1 : batuguntingkertas(lokasi);
            break;
            case 2 : tebakangka(lokasi);
            break;
            case 3 :
            break;
            default:
            cout << "Pilihan tidak tersedia" << endl;
            break;
        }
    } 
}

void Mengurutkan()
{
    if (T.atas == -1)
    {
        cout << "Tumpukan kosong\n";
        return;
    } 

	int i,j; 
	pemain tempone;

	for(i=0 ; i<(T.atas+1) ; i++)
	{
        tempone = T.data[i]; 
		
		j = i - 1;
		
		while(T.data[j].scoretotal < T.data[i].scoretotal && j>=0)
		{
			T.data[j+1]=  T.data[j];
			j--;
		}
	
		T.data[j+1]= tempone;
	}
}

void hapusplayernoob()
{
    Mengurutkan();

    if (T.atas == -1) 
    {
        cout << "Tumpukan kosong\n";
        cout << "\nenter untuk kembali"<<endl;
        cin.sync();
        cin.get();
        system("cls");
        return;
    } 
    T.atas--;
    cout << "\nakun sudah dihapus"<<endl;
    cout << "\nenter untuk kembali"<<endl;
    cin.sync();
    cin.get();
    system("cls");
}

void tampilhighscore()
{
    if (T.atas == -1)
    {
        cout << "Tumpukan kosong\n";
        cout << "\nenter untuk kembali" << endl;
        cin.sync();
        cin.get();
        system("cls");
        return;
    }

    for (int i = 0; i <= T.atas; i++)
    {
        T.data[i].scoretotal = T.data[i].scorebatuguntingkertas +
                              T.data[i].scoretebakangka;
    }

    Mengurutkan();

    cout << "=======================================================\n";
    cout << "No | Nickname | score suit | score tebak angka | total \n";
    cout << "=======================================================\n";


    for (int i = 0; i <= T.atas; i++)
    {
        cout << i + 1 << "."
             << " | " << T.data[i].nickname << "   |   "
             << T.data[i].scorebatuguntingkertas << "   |   "
             << T.data[i].scoretebakangka << "   |   "
             << T.data[i].scoretotal << "   |   " << endl;
    }

    cout << "=======================================================\n";
    cout << "enter untuk kembali" << endl;
    cin.sync();
    cin.get();
    system("cls");
}

void batuguntingkertas(int lokasi)
{
    srand(static_cast<unsigned int>(time(0)));
    string suit[] = {"batu", "kertas", "gunting"};
    int pilihankomputer = rand() % 3;
    string pilihanpemain;

    cout << "ayo main batu, kertas, gunting!\n";
    cout << "ketik pilihanmu (batu, kertas, or gunting): ";
    cin >> pilihanpemain;

    system("cls"); 

    cout << "komputer memilih: " << suit[pilihankomputer] << endl; 
    cout << "kamu memilih: " << pilihanpemain << endl;

    if (pilihanpemain == suit[pilihankomputer]) {
        cout << "seri!\n";
    } else if ( 
        (pilihanpemain == "batu" && suit[pilihankomputer] == "gunting") ||
        (pilihanpemain == "kertas" && suit[pilihankomputer] == "batu") ||
        (pilihanpemain == "gunting" && suit[pilihankomputer] == "kertas")
    ) {
        cout << "kamu menang!\n";
        T.data[lokasi].scorebatuguntingkertas++; 
    } else {
        cout << "komputer menang!\n";
    }

    cout << "\ntekan enter\n";
    cin.sync();
    cin.get(); 
    system("cls");

    return;
}

void tebakangka(int lokasi)
{
    srand(static_cast<unsigned int>(time(0)));
    int angkaTebakan = rand() % 100 + 1;
    int tebakan;
    int jumlahTebakan = 0;
    bool kondisi = false;

   cout << "Selamat datang di Permainan Tebak Angka!" <<endl;

    while (!kondisi) {
       cout << "Masukkan tebakan Anda (1-100): ";
       cin >> tebakan;
        jumlahTebakan++;

        if (jumlahTebakan == 7)
        {
            kondisi = true;
            cout << "ups batas tebakan habis"<<endl;
            cout << "enter untuk kembali"<<endl;
            cin.sync();
            cin.get();
            system("cls");
            
            return;
        }

        if (tebakan == angkaTebakan) {
            kondisi = true;
            T.data[lokasi].scoretebakangka++; 
            cout << "Selamat! Anda berhasil menebak angka " << angkaTebakan << " dengan " << jumlahTebakan << " tebakan." <<endl;
            cout << "enter untuk kembali"<<endl;
            cin.sync();
            cin.get();
            system("cls");
        } else if (tebakan < angkaTebakan) {
           cout << "Tebakan Anda terlalu rendah !" <<endl;
        } else {
           cout << "Tebakan Anda terlalu tinggi !" <<endl;
        } 
    }
    return;
}

void keluar()
{
    exit(0);
}