#include <stdio.h>
#include <stdlib.h>
// bir linked list düðümü
struct Node{
    int data;
    struct Node* next;
};

// bu fonksiyon, verilen düðümden baþlayarak linked list'in içeriðini yazdýrýr
void printList(struct Node* n){
    while(n != NULL){
        printf(" %d",n->data);
        n = n->next;
    }
}
// baþa eleman ekleme
void push(struct Node** head_ref,int new_data){
    // yeni düðümü allocade etmek
    struct Node* new_node = (struct Node*) malloc(sizeof (struct Node));
    // yeni deðeri al
    new_node->data = new_data;
    // yeni düðümü head yapmak
    new_node->next = (*head_ref);
    // yeni düðüme point etmek için head;
    (*head_ref) = new_node;
}

// bir düðmden sonra düðüm ekleme
void insertAfter(struct Node* prev_node, int new_data){
    // verilen düðüm kontrol edilir
    if(prev_node == NULL){
        printf("Verilen node NULL olamaz");
        return;
    }
    // yeni düðüm allocate edilir
    struct Node* new_node = (struct Node*) malloc(sizeof (struct Node));
    // yeni deðer alýnýr
    new_node->data=new_data;
    // yeni düðümün next'i, önceki düðümün next'i yapýlýr
    new_node->next = prev_node->next;
    // önceli düðümün next'i, yeni düðüm yapýlýr
    prev_node->next= new_node;
}
// sona düðüm eklemek
void append(struct Node** head_ref, int new_data){
    // yeni düðüm allocate edilir
    struct Node* new_node = (struct Node*) malloc(sizeof (struct Node));
    struct Node *last = *head_ref;

    // yeni deðer alýnýr
    new_node->data = new_data;
    // bu düðüm son düðüm olduðu için, next'i NULL yapýlýr
    new_node->next = NULL;
    // Eðer linked list boþ ise yeni düðüm head yapýlýr
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    // Linked list boþ deðilse son düðüme geçiþ yapýlýr
    while (last->next != NULL){
        last = last->next;
    }
    // son düðümün next'i yeni düðüm yapýlýr
    last->next = new_node;
    return;
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // yýðýnda 3 düðüm ayýrmak
    head = (struct Node*) malloc(sizeof (struct Node));
    second = (struct Node*) malloc(sizeof (struct Node));
    third =(struct Node*) malloc(sizeof (struct Node));

    head->data = 1; // ilk düðüme deðer atandý
    head->next =second; // ilk düðümü, ikinci düðüme baðladýk

    second->data = 2; // ikinci düðüme deðer atandý
    second->next = third; // ikinci düðümü, üçüncü düðüme baðladýk

    third->data =3; // üçüncü düðüme deðer atandý
    third->next = NULL;

    // fonksiyonu çaðýralým
    //push(&head,0);
    //insertAfter(head->next,5);
    append(&head,4);
    printList(head);

    return 0;
}
