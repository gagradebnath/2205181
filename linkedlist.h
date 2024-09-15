#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
       
    // add *next and *prev here

    struct Node *next;
    struct Node *prev;

} Node;


typedef struct
{
    // add Node* head, tail, current_position and other necessary fields here
    Node *head;
    Node *tail;
    Node *current_position;
    int size;
    int current_position_index;
} LinkedList;


void init_linkedlist(LinkedList *list)
{
    // printf("implement init_linkedlist\n");
    // initialize head, tail with null
    list->head=NULL;
    list->tail=NULL;
    list->current_position=NULL;
    list->size=0;
    list->current_position_index=0;
}


void clear(LinkedList *list)
{
    // printf("Implement clear\n");
    Node *temp = list->head;
    // traverse the list and free each node
    while(temp!=NULL){
        Node *temp2 = temp->next;
        free(temp);
        temp=temp2;
    }
    list->head=NULL;
    list->tail=NULL;
    list->current_position=NULL;
    list->size=0;
    list->current_position_index=0;
    // set head and tail to null
}


int get_size(LinkedList *list)
{
    printf("size is %d\n",list->size);
    return list->size;
}


void append(LinkedList *list, int value)
{
    // printf("Implement append\n");
    // create a new node and set its value
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data=value;
    new_node->next=NULL;
    new_node->prev=NULL;   
    // consider the case when the list is empty and when it isnt
    if(list->size==0){
        list->head=new_node;
        list->tail=new_node;
        list->current_position=new_node;
    }
    else{
        list->tail->next=new_node;
        new_node->prev=list->tail;
        list->tail=new_node;
    }
    list->size++;
    // printf("prev :%X curr :%X nxt :%X appended :%d size :%d\n",new_node->prev,new_node,new_node->next,value,list->size);
}


void insert(LinkedList *list, int value)
{
    // printf("Implement insert\n");
    if(list->size==0){
        append(list,value);
        printf("inserted %d\n",value);
        return ;
    }
    // create a new node and set its value
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data=value;
    new_node->next=NULL;
    new_node->prev=NULL;
    // place it at the current position (check order of operations)
    if(list->current_position==list->head){
        new_node->next=list->head;
        list->head->prev=new_node;
        list->head=new_node;
    }
    else{
        new_node->next=list->current_position;
        new_node->prev=list->current_position->prev;
        list->current_position->prev->next=new_node;
        list->current_position->prev=new_node;
    }
    list->current_position=new_node;
    list->size++;
    printf("inserted %d\n",value);
    // consider the case when the list is empty and when it isnt
}


int remove_at_current(LinkedList *list)
{
    // printf("Implement remove_at_current\n");
    if(list->size==0){
        printf("List is empty\n");
        return -1;
    }
    int value = list->current_position->data;
    if(list->size==1){
        free(list->current_position);
        list->head=NULL;
        list->tail=NULL;
        list->current_position=NULL;
    }
    else if(list->current_position==list->head){
        list->current_position->next->prev=NULL;
        list->head=list->current_position->next;
        list->current_position=list->head;
    }
    else{
        list->current_position->prev->next=list->current_position->next;
        list->current_position->next->prev=list->current_position->prev;
        list->current_position=list->current_position->next;
    }
    // consider the case when current code is at the begining or at the end
    list->size--;
    printf("removed %d\n",value);
    return -1;
}


int find(LinkedList *list, int value)
{
    // printf("Implement find\n");
    Node *temp = list->head;
    int i = 0;
    while(temp!=NULL){
        if(temp->data==value){
            printf("found %d at %d\n",value,i);
            return value;
        }
        temp=temp->next;
        i++;
    }
    printf("did not find %d in the list\n",value);
    // traverse the list and return the position of the value
    return -1;
}


void move_to_start(LinkedList *list)
{
    // printf("Implement move_to_start\n");
    list->current_position=list->head;
    list->current_position_index=0;
    printf("moved current position to 0\n");
}


void move_to_end(LinkedList *list)
{
    list->current_position=list->tail;
    list->current_position_index=list->size-1;
    printf("movesd current position to %d\n",list->size-1);
}


void prev(LinkedList *list)
{
    // printf("Implement prev\n");
    if(list->current_position!=list->head){
        list->current_position=list->current_position->prev;
        list->current_position_index--;
        printf("moved current position from %d to %d\n",list->current_position_index+1,list->current_position_index);
        return ;
    }
    printf("current position is at the start\n");
}


void next(LinkedList *list)
{
    if(list->current_position!=list->tail){
        list->current_position=list->current_position->next;
        list->current_position_index++;
        printf("moved current position from %d to %d\n",list->current_position_index-1,list->current_position_index);
        return ;
    }
    printf("current position is at the end\n");
    // printf("Implement next\n");
}


void move_to_position(LinkedList *list, int position)
{
    // printf("Implement move_to_position\n");
    if(position<=0 || position>=list->size){
        printf("Invalid position\n");
        return ;
    }
    Node *temp = list->head;
    for(int i=0;i<position;i++){
        temp=temp->next;
    }
    list->current_position=temp;
    printf("moved current position from %d to %d\n",list->current_position_index,position);
    list->current_position_index=position;
    // traverse the list and stop at the given position
}


int get_current_position(LinkedList *list)
{
    // printf("Implement get_current_position\n");
    // traverse the list and stop when you are at the current position
    Node *temp = list->head;
    int i = 0;
    while(temp!=list->current_position){
        temp=temp->next;
        i++;
    }
    printf("current position is %d\n",i);
    // return the position (integer)
    return i;
}


int get_current_element(LinkedList *list)
{
    // printf("Implement get_current_element\n");
    // return the value at the current position
    printf("current element is %d\n",list->current_position->data);
    return -1;
}


void print_list(LinkedList *list)
{
    // printf("< list elements here >");
    // printf("%d\n",list->size);
    Node *temp = list->head;
    printf("<");
    if(list->size==0){
        printf("  >\n");
        return ;
    }
    while(temp!=NULL){
        if(temp==list->current_position){
            printf(" |%d ",temp->data);
        }
        else
            printf(" %d ",temp->data);
        temp=temp->next;
    }
    printf(">\n");
}


void free_list(LinkedList *list)
{
    // printf("Implement free_list\n");
    Node *temp = list->head;
    while(temp!=NULL){
        Node *temp2 = temp->next;
        free(temp);
        temp=temp2;
    }
    list->head=NULL;
    list->tail=NULL;
    list->current_position=NULL;
    list->size=0;
    list->current_position_index=0;

    // free each node in the list
}
