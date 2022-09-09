#include <stdio.h>
#include <stdlib.h>
// bir linked list d���m�
struct Node{
    int data;
    struct Node* next;
};

// bu fonksiyon, verilen d���mden ba�layarak linked list'in i�eri�ini yazd�r�r
void printList(struct Node* n){
    while(n != NULL){
        printf(" %d",n->data);
        n = n->next;
    }
}
// ba�a eleman ekleme
void push(struct Node** head_ref,int new_data){
    // yeni d���m� allocade etmek
    struct Node* new_node = (struct Node*) malloc(sizeof (struct Node));
    // yeni de�eri al
    new_node->data = new_data;
    // yeni d���m� head yapmak
    new_node->next = (*head_ref);
    // yeni d���me point etmek i�in head;
    (*head_ref) = new_node;
}

// bir d��mden sonra d���m ekleme
void insertAfter(struct Node* prev_node, int new_data){
    // verilen d���m kontrol edilir
    if(prev_node == NULL){
        printf("Verilen node NULL olamaz");
        return;
    }
    // yeni d���m allocate edilir
    struct Node* new_node = (struct Node*) malloc(sizeof (struct Node));
    // yeni de�er al�n�r
    new_node->data=new_data;
    // yeni d���m�n next'i, �nceki d���m�n next'i yap�l�r
    new_node->next = prev_node->next;
    // �nceli d���m�n next'i, yeni d���m yap�l�r
    prev_node->next= new_node;
}
// sona d���m eklemek
void append(struct Node** head_ref, int new_data){
    // yeni d���m allocate edilir
    struct Node* new_node = (struct Node*) malloc(sizeof (struct Node));
    struct Node *last = *head_ref;

    // yeni de�er al�n�r
    new_node->data = new_data;
    // bu d���m son d���m oldu�u i�in, next'i NULL yap�l�r
    new_node->next = NULL;
    // E�er linked list bo� ise yeni d���m head yap�l�r
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    // Linked list bo� de�ilse son d���me ge�i� yap�l�r
    while (last->next != NULL){
        last = last->next;
    }
    // son d���m�n next'i yeni d���m yap�l�r
    last->next = new_node;
    return;
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // y���nda 3 d���m ay�rmak
    head = (struct Node*) malloc(sizeof (struct Node));
    second = (struct Node*) malloc(sizeof (struct Node));
    third =(struct Node*) malloc(sizeof (struct Node));

    head->data = 1; // ilk d���me de�er atand�
    head->next =second; // ilk d���m�, ikinci d���me ba�lad�k

    second->data = 2; // ikinci d���me de�er atand�
    second->next = third; // ikinci d���m�, ���nc� d���me ba�lad�k

    third->data =3; // ���nc� d���me de�er atand�
    third->next = NULL;

    // fonksiyonu �a��ral�m
    //push(&head,0);
    //insertAfter(head->next,5);
    append(&head,4);
    printList(head);

    return 0;
}
