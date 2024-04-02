#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<conio.h>
struct Song {
	char NameSong[31];
	char Musician[26];
	char Singer[26];
	int Length;
};
struct SNode {
	Song info;
	SNode* Next;
};
struct SList {
	SNode* Head;
	SNode* Tail;
};
void initSList(SList& sl) {
	sl.Head = NULL;
	sl.Tail = NULL;
}
bool isEmpty(SList& sl) {
	if (sl.Head == NULL)
		return true;
	return false;
}
void show_Menu() {
	printf("\n-----------------------------\n");
	printf("\n 0: to end program ");
	printf("\n 1: tao mot bai hat ");
	printf("\n 2: doc file ");
	printf("\n-----------------------------\n");
}
void input_Song(Song& x) {
	printf("\n nhap ten bai hat: ");
	fgets(x.NameSong, sizeof(x.NameSong), stdin);
	printf("\n nhap ten nghe si: ");
	fgets(x.Musician, sizeof(x.Musician), stdin);
	printf("\n nhap ten ca si: ");
	fgets(x.Singer, sizeof(x.Singer), stdin);
	printf("\n nhap do dai cua bai hat: ");
	scanf("%d", &x.Length);
	getchar(); 
}
void show_Song(Song x) {
	printf("%-31s%-26s%-26s%10d\n", x.NameSong, x.Musician, x.Singer, x.Length);
}
void show_SNode(SNode* p) {
	show_Song(p->info);
}
SNode* create_SNode(Song& x) {
	SNode* p = new SNode;
	if (p == NULL) {
		printf("\n khong du bo nho de cap phat ");
		return NULL;
	}
	p->info = x;
	p->Next - NULL;
	return p;
}
void addSNodetoList(SList& sl, SNode* p) {
	if (isEmpty(sl)) {
		sl.Head = sl.Tail = p;
	}
	else {
		sl.Tail->Next = p;
		sl.Tail = p;
	}
}
void readSongFromFile(SList& sl, const char* filename) {
	FILE* fi = NULL;
	fopen_s(&fi, filename, "r");
	if (fi == NULL) {
		printf("\n khong the mo file %s", filename);
		return;
	}
	char buffer[100];
	
	while (fgets(buffer, sizeof(buffer), fi)) {
		Song x;
		if (sscanf_s(buffer, "%[^#]%*c%[^#]%*c%[^#]%*c%d", x.NameSong, (unsigned)_countof(x.NameSong), x.Musician, (unsigned)_countof(x.Musician), x.Singer, (unsigned)_countof(x.Singer), &x.Length) == 4) {
			SNode* p = create_SNode(x);
			addSNodetoList(sl, p);
		}
		else {
			printf("\n falied ");
		}
	}
	fclose(fi);
}
void prinftAllSong(SList sl) {
	SNode* p = sl.Head;
	if (p == NULL) {
		printf("\n danh sach rong: ");
		return;
	}
	while (p) {
		show_SNode(p);
	}
}
void bai1() {
	int choice;
	Song song;
	SList sl;
	initSList(sl);

	do {
		show_Menu();
		printf("\n your choice :");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1: {
			input_Song(song);
			SNode* p = create_SNode(song);
			show_SNode(p);
			break;
		}
		case 2: {
			readSongFromFile(sl, "ListSong,txt");
			prinftAllSong(sl);
			break;
		}
		default:
			break;
		}
	} while (choice != 0);
}
int main() {
	bai1();

	return 0;
}