/*
Nama Program		: exercise-01
Nama				: Muhammad Iqbal Alif Fadilla
NPM					: 140810180020
Tanggal Pembuatan	: 20 03 19
Deskripsi			: Single Linked List
*/

#include<iostream>
#include<iomanip>
using namespace std;

struct Pegawai {
	char nama[100];
	char div[100];
	float gaji;
	Pegawai* next;
};

typedef Pegawai* pointer;
typedef pointer List;

void createList(List& First) {
	First = NULL;
}

void createElmt(pointer& pBaru) {
	pBaru = new Pegawai;

	cout << "Nama : "; cin.ignore(); cin.getline(pBaru->nama, 100);
	cout << "Bidang/Divisi : "; cin.getline(pBaru->div, 100);
	cout << "Gaji : "; cin >> pBaru->gaji;

	pBaru->next = NULL;
}

void insertFirst(List& First, pointer pBaru) {
	if (First == NULL)
		First = pBaru;
	else {
		pBaru->next = First;
		First = pBaru;
	}
}

void traversal(List First) {
	pointer pBantu;
	if (First == NULL) {
		cout << "List Kosong\n";
	}
	else {
		pBantu = First;
		int i = 1;
		cout << setw(4) << "No" << setw(30) << "Nama" << setw(25) << "Bidang" << setw(8) << "Gaji" << endl;
		do {
			cout << setw(4) << i << setw(30) << pBantu->nama << setw(25) << pBantu->div << setw(8) <<"Rp."<< pBantu->gaji << endl;
			pBantu = pBantu->next;
			i++;
		} while (pBantu != NULL); {
		}
	}
}

void deleteFirst(List& First, pointer& pHapus) {
	if (First == NULL) { // kosong
		pHapus = NULL;
		cout << "List kosong, tidak ada yang dihapus" << endl;
	}
	else if (First->next == NULL) { //isi 1 elemen
		pHapus = First;
		First = NULL;
		cout << "First Deleted" << endl;
	}
	else {
		pHapus = First; // 1
		First = First->next; // 2
		pHapus->next = NULL; // 3
		cout << "First Deleted" << endl;
	}
}

void insertLast(List& First, pointer pBaru) {
	pointer last; //last utk mencatat elemen terakhir
	cout << "Insert Last" << endl;
	if (First == NULL) { //kosong
		First = pBaru;
	}
	else { // ada isi
		last = First; // menemukan elemen terakhir
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = pBaru; // sambungkan
	}
}

void deleteLast(List& First, pointer& pHapus) {
	pointer last, precLast;
	cout << "Delete Last" << endl;
	if (First == NULL) { // kosong
		pHapus = NULL;
		cout << "List kosong, tidak ada yang dihapus" << endl;
	}
	else if (First->next == NULL) { //isi 1 elemen
		pHapus = First;
		First = NULL; // list jadi kosong
	}
	else { // isi > 1 elemen
		last = First; // menemukan elemen terakhir
		precLast = NULL;
		while (last->next != NULL) {
			precLast = last; // preclast mencatat yg akan ditinggalkan Last
			last = last->next; // last berpindah
		}
		pHapus = last;
		precLast->next = NULL;
	}
}

void menu(int& n) {
	cout << "Program Pegawai" << endl;
	cout << "1. Insert First" << endl;
	cout << "2. Insert Last" << endl;
	cout << "3. Delete First" << endl;
	cout << "4. Delete Last" << endl;
	cout << "5. Tampilkan List Pegawai" << endl;
	cout << "0. Exit" << endl;
	cout << "\nInput : "; cin >> n;
	cout << "\n";	
}

int main() {
	pointer p;
	List pgw;
	int n;

	createList(pgw);
	menu(n);
	while (n != 0) {
		switch (n)
		{
		case 1:
			createElmt(p);
			insertFirst(pgw, p);
			menu(n);
			break;
		case 2:
			createElmt(p);
			insertLast(pgw, p);
			menu(n);
			break;
		case 3:
			deleteFirst(pgw, p);
			menu(n);
			break;
		case 4:
			deleteLast(pgw, p);
			menu(n);
			break;
		case 5:
			traversal(pgw);
			menu(n);
			break;
		case 0:
			return 0;
		}
	}
	
	return 0;
}