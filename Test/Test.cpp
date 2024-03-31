#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>

struct Song {
    char NameSong[31];
    char Musician[26];
    char Singer[26];
    int Length;
};

struct SNode {
    struct Song info;
    struct SNode* next;
};

struct SList {
    struct SNode* Head;
    struct SNode* Tail;
};

void initSList(struct SList* sl) {
    sl->Head = NULL;
    sl->Tail = NULL;
}

struct SNode* create_SNode(struct Song* x) {
    struct SNode* p = (struct SNode*)malloc(sizeof(struct SNode));
    if (p == NULL) {
        printf("\n khong du bo nho de cap phap ");
        return NULL;
    }
    p->info = *x;
    p->next = NULL;
    return p;
}

void show_Menu1() {
    printf("\n-----------------------------\n");
    printf("\n 0: to end program ");
    printf("\n 1: tao mot bai hat ");
    printf("\n 2: doc file ");
    printf("\n-----------------------------\n");
}

void input_Song(struct Song* x) {
    printf("\n Nhap ten bai hat: ");
    getchar();
    fgets(x->NameSong, sizeof(x->NameSong), stdin);
    printf("\n nhap ten nghe si: ");
    fgets(x->Musician, sizeof(x->Musician), stdin);
    printf("\n nhap ten ca si: ");
    fgets(x->Singer, sizeof(x->Singer), stdin);
    printf("\n nhap do dai cua bai hat: ");
    scanf_s("%d", &x->Length);
}

void show_Song(struct Song x) {
    printf("%-31s%-26s%-26s%10d\n", x.NameSong, x.Musician, x.Singer, x.Length);
}

void show_SNode(struct SNode* p) {
    show_Song(p->info);
}

void bai1() {
    int choice;
    struct Song song;
    struct SList sl;
    initSList(&sl);

    do {
        show_Menu1();
        printf("\n your choice :");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: {
            input_Song(&song);
            struct SNode* p = create_SNode(&song);
            show_SNode(p);
            break;
        }
              //case 2: {
              //    FILE* fi = fopen_s("NhacCuaTao.txt", "rt");
              //    if (fi == NULL) {
              //        printf("\n loi khong mo duoc file: ");
              //        break;
              //    }
              //    // Add reading from file logic here
              //    fclose(fi);
              //    break;
              //}
        }
    } while (choice != 0);
}

int main() {
	bai1();
	return 0;
}
