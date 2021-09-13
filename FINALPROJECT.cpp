#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <cstdlib>
void screenAwal();
void login();
void regis();
void verify();
void home();
void profile();
void cekSaldo();
void isiSaldo();
void transfer();
void daftarTransfer();
void daftarRekeningTransfer();
void rekeningTerdaftar();
void transferSaldo();

struct User {
	char nama[100];
	int umur;
	char noTelp[30];
	char password[30];
	long long int saldo;
};

int main() {
	screenAwal();
	return 0;
}


void screenAwal (){
	int choice;
	do{
		puts("--Selamat Datang di Algo Bank--");
		puts ("1. Login");
		puts ("2. Register");
		puts ("3. Exit");
		scanf("%d", &choice);
		
		switch (choice){
			case 1:{
				choice = 3;
				system("cls");
				login();
				break;
			}
			case 2:{
				choice = 3;
				system("cls");
				regis();
				break;
			}
		}
		
	} while (choice != 3);
}

struct User data;
bool valid;
void login (){
    printf("Phone Number: ", data.noTelp);
	scanf("%s", &data.noTelp[0]);
	printf("Password: ");
	scanf("%s", &data.password[0]);
	verify();
	if(!valid){ //Jika Salah Maka Balik Ke ScreenAwal
		system("cls");
		printf("NoTelp atau Password anda salah, silahkan daftar jika belum memiliki akun\n\n");
		screenAwal();
	}else{
		system("cls");
		home();
	}
}
void regis() {
	FILE *in = fopen("dataUser.txt","a");
	
	struct User temp;
	system("cls");
	printf("\nRegis Akun\n");
	
	printf("Masukkan Nama : ");
	scanf("%s",&temp.nama[0]); fflush(stdin);
	
	printf("Masukkan Umur : ");
	scanf("%d",&temp.umur); fflush(stdin);
	
	printf("Masukkan Nomor Telepon : ");
	scanf("%s",&temp.noTelp[0]); fflush(stdin);
	
	printf("Masukkan Password : ");
	scanf("%s",&temp.password[0]); fflush(stdin);
	
	temp.saldo = 0;
	
	fprintf(in,"%s#%d#%s#%s#%lld\n",temp.nama, temp.umur, temp.noTelp, temp.password, temp.saldo);
	fclose(in);
	
	printf("\nBerhasil Regis, silahkan login\n");
	
	screenAwal();
}


void verify(){
	FILE *in = fopen("dataUser.txt","r");
	
	if(!in){
		valid = false;
	}else{
		struct User temp;
		while(!feof(in)){
			fscanf(in,"%[^#]#",&temp.nama);
			fscanf(in,"%d#",&temp.umur);
			fscanf(in,"%[^#]#",&temp.noTelp);
			fscanf(in,"%[^#]#",&temp.password);
			fscanf(in,"%lld",&temp.saldo);
			fscanf(in,"\n");
						
			if(strcmp(temp.noTelp,data.noTelp)==0){
				if(strcmp(temp.password,data.password) == 0){
					
					valid = true;
					strcpy(data.nama, temp.nama);
					data.umur = temp.umur;
					data.saldo = temp.saldo;
				}else{
					valid = false;
				}
				break;
			}
		}
	}
	
	fclose(in);
}

void home() {
	int choice;
	do {
	puts("\nAlgoBank");
	puts("(1) Tampilkan Profil");
	puts("(2) Cek Saldo");
	puts("(3) Isi Saldo");
	puts("(4) Transfer");
	puts("(5) Daftar Transfer");
	puts("(6) Exit");

	scanf("%d", &choice);
	
	switch(choice) {
		case 1: {
			choice = 7;
			system("cls");
			profile();
			break;
		} case 2: {
			choice = 7;
			system("cls");
			cekSaldo();
			break;
		} case 3: {
			choice = 7;
			system("cls");
			isiSaldo();
			break;
		} case 4: {
			choice = 7;
			system("cls");
			transfer();
			break;
		} case 5: {
			choice = 7;
			system("cls");
			daftarTransfer();
			break;
		} case 6: {
			choice = 7;
			return;
			break;
		}
	}
	
	} while (choice != 7);
	}
void profile() {
	char choice[100];
	system("cls");
	printf("Nama: %s\n", data.nama);
	printf("Umur: %d\n", data.umur);
	printf("NoTelp: %s\n", data.noTelp);
	home();
	return;
}
struct User user;
void cekSaldo(){
	FILE *in = fopen("./dataUser.txt","r");
	
	if(in){
		struct User temp;
		while(!feof(in)){
			fscanf(in,"%[^#]#",&temp.nama);
			fscanf(in,"%d#",&temp.umur);
			fscanf(in,"%[^#]#",&temp.noTelp);
			fscanf(in,"%[^#]#",&temp.password);
			fscanf(in,"%lld",&temp.saldo);
			fscanf(in,"\n");
						
			if(strcmp(temp.noTelp,data.noTelp)==0){
				printf("Saldo Anda Sebesar %lld\n",temp.saldo);
				fclose(in);
				home();
				break;
			}
		}
	}
	
	fclose(in);
}

void isiSaldo() {
	long long int s;
	bool sukses = false;
	
	system("cls"); //Clear screen
	
	printf("Masukkan Saldo yang ingin diisi : ");
	scanf("%lld",&s); //Input dan disimpan ke dalam variabel s
	
	FILE *in = fopen("./dataUser.txt","r");
	FILE *baru = fopen("./userData2.txt","a");
	
	if(in){
		struct User temp;
		while(!feof(in)){
			fscanf(in,"%[^#]#",&temp.nama);
			fscanf(in,"%d#",&temp.umur);
			fscanf(in,"%[^#]#",&temp.noTelp);
			fscanf(in,"%[^#]#",&temp.password);
			fscanf(in,"%lld",&temp.saldo);
			fscanf(in,"\n");
						
			if(strcmp(temp.noTelp,data.noTelp)==0){
				fprintf(baru, "%s#%d#%s#%s#%lld\n", temp.nama, temp.umur, temp.noTelp, temp.password, temp.saldo+s);
				sukses = true;
			}else{
				fprintf(baru, "%s#%d#%s#%s#%lld\n", temp.nama, temp.umur, temp.noTelp, temp.password, temp.saldo);
			}
		}
	}
	
	fclose(in);
	fclose(baru);
	
	remove("./dataUser.txt");

	rename("./userData2.txt","./dataUser.txt");
	
	if(sukses){
		printf("\nSaldo berhasil ditambahkan");
	}else{
		printf("\nSaldo gagal ditambahkan");
	}
	
		home();
}			


char tempNoTelp[30];
struct User currentUser;
void transfer() {
	FILE *in = fopen("./dataUser.txt", "r");
	struct User temp;
	currentUser = data;
	printf("Masukkan no rekening (no telp) yang ingin di transfer: ");
	scanf("%s", &tempNoTelp);
	if(in){
		
		while(!feof(in)){
			fscanf(in,"%[^#]#",&temp.nama);
			fscanf(in,"%d#",&temp.umur);
			fscanf(in,"%[^#]#",&temp.noTelp);
			fscanf(in,"%[^#]#",&temp.password);
			fscanf(in,"%lld",&temp.saldo);
			fscanf(in,"\n");
						
			if(strcmp(temp.noTelp,tempNoTelp)==0){
				fclose(in);
				transferSaldo();
				break;
			} 
			
		}
	}
	
	fclose(in);
	return;
}
void transferSaldo() {
	long long int s;
	bool sukses1 = false;
	bool sukses2 = false;
	bool sukses3 = false;

	
	system("cls"); //Clear screen
	
	printf("Masukkan Saldo yang ingin ditransfer : ");
	scanf("%lld",&s); //Input dan disimpan ke dalam variabel s
	
	FILE *in = fopen("./dataUser.txt","r");
	FILE *baru = fopen("./userData2.txt","a");
	
	if(in){
		struct User temp;
		while(!feof(in)){
			fscanf(in,"%[^#]#",&temp.nama);
			fscanf(in,"%d#",&temp.umur);
			fscanf(in,"%[^#]#",&temp.noTelp);
			fscanf(in,"%[^#]#",&temp.password);
			fscanf(in,"%lld",&temp.saldo);
			fscanf(in,"\n");
						
			if(strcmp(temp.noTelp,currentUser.noTelp)==0){
				fprintf(baru, "%s#%d#%s#%s#%lld\n", temp.nama, temp.umur, temp.noTelp, temp.password, temp.saldo-s);
				sukses1 = true;
			}
			if(strcmp(temp.noTelp,tempNoTelp)==0){
				fprintf(baru, "%s#%d#%s#%s#%lld\n", temp.nama, temp.umur, temp.noTelp, temp.password, temp.saldo+s);
				sukses2 = true;
			}
		}
	
	if (sukses1 == true && sukses2 == true) {
		sukses3 = true;
	}
	fclose(in);
	fclose(baru);
	
	remove("./dataUser.txt");

	rename("./userData2.txt","./dataUser.txt");
	
	
	if(sukses3){
		printf("\nSaldo berhasil ditransfer");
	}else{
		printf("\nSaldo gagal ditransfer");
	}
	
		home();
}
}

void daftarTransfer() {
	int choice;
	do {
		system("cls");
		puts("(1) Daftarkan Rekening Transfer");
		puts("(2) Lihat Rekening Terdaftar");
		puts("(3) Kembali ke home screen");
		scanf("%d", &choice);
	
		switch (choice) {
			case 1: {
				choice = 4;
				daftarRekeningTransfer();
				break;
			} case 2: {
				choice = 4;
				rekeningTerdaftar();
				break;
			} case 3: {
				choice = 4;
				home();
				break;
			}
		}
	} while (choice != 4);

}
void daftarRekeningTransfer() {
	FILE *fp = fopen("./daftarRekening.txt", "a");
	char noTelpLain[30];
	puts("Masukkan nomor rekening (NoTelp) lain: ");
	scanf("%s", &noTelpLain);
	
	
	
	fclose(fp);
}	
void rekeningTerdaftar() {
	return;
}
