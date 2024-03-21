#include <iostream>
using namespace std;

int main()
{
	cout<<"============================================"<<endl;
	cout<<"selamat datang di program pengembalian buku."<<endl;
	cout<<"saat ini ada 10 data buku pada sistem."<<endl;
	cout<<"Batas pengembalian buku adalah 1 minggu"<<endl;
	cout<<"============================================"<<endl;
	cout<<"tekan enter untuk melanjutkan. \n";

	//untuk membersihkan terminal jika menekan enter
	cin.sync();
	cin.get();
	system("cls");
	
	int kobu,lajam,datdenda,totdenda,jumdenda = 0,x = 0,z = 0;
	char syarat = 'y';
	string datbuku;
	string rakbuku[10];
	int rakdenda[10];
	
	while (syarat == 'y')
	{
		totdenda = 0;
		datdenda = 0;

		cout<<"============================="<<endl;
		cout<<"masukkan kode buku (1-10)= ";
		cin>>kobu;
		cout<<"masukkan lama peminjaman = ";
		cin>>lajam;
		cout<<"============================="<<endl;
		
		switch(kobu)
		{
			case 1:
			datbuku = "suhairi potter";
			datdenda = 3000;
			break;
			case 2:
			datbuku = "maling kandang";
			datdenda = 5000;
			break;
			case 3:
			datbuku = "ensiklopedia anu";
			datdenda = 10000;
			break;
			case 4:
			datbuku = "cara sixpack dalam 15 menit";
			datdenda = 1000;
			break;
			case 5:
			datbuku = "buku sihir samsudin";
			datdenda = 1500;
			break;
			case 6:
			datbuku = "apa hukumnya menikahi wanita 2d ?";
			datdenda = 2000;
			break;
			case 7:
			datbuku = "aku,kamu,dan asep";
			datdenda = 5000;
			break;
			case 8:
			datbuku = "pendapat para ahli mengenai arti terserah";
			datdenda = 4000;
			break;
			case 9:
			datbuku = "5 dosa besar user twitter";
			datdenda = 7000;
			break;
			case 10:
			datbuku = "cara mudah mengedipkan mata";
			datdenda = 1000;
			break;
			default:
			datbuku = "(kode buku tidak valid)";
			datdenda = 0;
			break;
		}
		
		if (lajam > 7 && datdenda != 0) //buku telat dan kodenya valid
		{
			totdenda = (lajam-7)*datdenda; //lama pinjam dikali denda
			cout<<"anda mengembalikan "<<datbuku<<endl;
			cout<<"pengembalian melebihi batas waktu,total denda = "<<datdenda<<"*"<<lajam - 7<<" = "<<totdenda<<endl;
		}
		else //bukunya tidak telat dan kodenya valid || bukunya telat tapi kode tidak valid
		{
			if(datdenda != 0)
			{
				cout<<"anda mengembalikan "<<datbuku<<endl;
				cout<<"tidak terlambat,tidak ada denda"<<endl;
				datdenda = 0;
			}
			else
			{
				cout<<datbuku<<endl;
			}
		}
		
		if(datbuku != "(kode buku tidak valid)") //bukunya valid
		{
			x++; //untuk array dan jumlah buku
			rakbuku[x] = datbuku;
			if(lajam > 7)
			{
				rakdenda[x] = totdenda;
			}
			else
			{
				rakdenda[x] = 0;
			}
		}

		jumdenda += totdenda; //total semua denda buku
		
		cout<<"\nada lagi (y/t) = ";
		cin>>syarat;

	}

	system("cls");
	
	cout<<"================================="<<endl;
	cout<<"anda mengembalikan  "<<x<<" buku."<<endl;
	for(int y = 0;y<x;y++) //total buku menurun
	{
		z++; // cuma untuk di fungsi for ini aja
		cout<<z<<")."<<rakbuku[y+1]<<", dengan total denda = "<<rakdenda[y+1]<<endl;
	}
	if(jumdenda > 0)
	{
		cout<<"total denda "<<jumdenda<<"rupiah"<<endl;
	}
	else
	{
		cout<<"tidak ada denda yang harus dibayar."<<endl;
	}
	return 0;
}