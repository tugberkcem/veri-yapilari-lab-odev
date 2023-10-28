#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Dugum yapisi (node structure) olusturuyoruz
struct Node {
    int data;
    struct Node* next;
};

// Dugum olusturma islemi
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Bagli listeyi siralamak icin kullanilan insertion_sort fonksiyonu
void insertion_sort(struct Node** head) {
    struct Node* sorted = NULL; // Siralanmis liste

    struct Node* current = *head;
    while (current != NULL) {
        struct Node* next = current->next;

        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }

    *head = sorted;
}

// Bagli listeyi ekrana yazdirma islemi
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n = 100;
    struct Node* head = NULL;

    srand(time(0));
    for (int i = 0; i < n; i++) {
        int data = rand() % 1000 + 1;
        struct Node* newNode = createNode(data);
        newNode->next = head;
        head = newNode;
    }

    insertion_sort(&head);

    printf("Siralanmis Liste: ");
    printList(head);

    // Bellegi serbest birakma
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
