#include <bits/stdc++.h>
using namespace std;
struct node {
    char data;
    struct node *next;
};

void insertFirst(struct node **head, char data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void initalize(struct node **head) {
    *head = NULL;
}
void printList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    char c;
    int n,m;
    cin>>n>>m;
    struct node *head[n];
    for(int i=0;i<n;i++){
        head[i]=NULL;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c;
            insertFirst(&head[i],c);
        }
    }
    for(int i=0;i<n;i++){
        printList(head[i]);
    }
    return 0;
}