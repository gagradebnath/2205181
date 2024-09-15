#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int * array;
    // Add more fields here
    int size;
    int capacity;
    int current_position;
} ArrayList;


void init_arraylist(ArrayList *list, int capacity)
{
    // printf("implement init_arraylist\n");
    // dynamically allocate space for the array
    list->array=(int*)malloc(sizeof(int)*capacity);
    // initialize the size, capacity, and current position
    list->size = 0;
    list->capacity = capacity;
    list->current_position = 0;
    printf("Initialized array with capacity %d\n",list->capacity);
}

void print_list(ArrayList *list)
{
    printf("<");
    if(list->size==0){
        printf("  >\n");
        return;
    }
    for(int i = 0;i<list->size;i++){
        if(list->current_position==i){
            printf(" |%d ",list->array[i]);
        }
        else{
            printf(" %d ",list->array[i]);
        }
    }
    printf(">\n");
}


void clear(ArrayList *list)
{
    // printf("Implement clear\n");
    // clear the list but do not free the array
    for(int i = 0;i<list->size;i++){
        list->array[i]=0;
    }
    // realloc(list->array,1);
    // modify the size, capacity, and current position
    list->size = 0;
    // list->capacity = 0;
    list->current_position=0;
    printf("cleared the list\n");
}

int get_size(ArrayList *list)
{
    // printf("Implement get_size\n");
    printf("size is %d\n",list->size);
    return list->size;
}


void resize(ArrayList *list, int new_capacity)
{
    // printf("Implement resize\n");
    // allocate space for new array with new_capacity
    list = realloc(list->array, new_capacity);
    // print log message
    int temp = list->capacity;
    list->capacity = new_capacity;
   
}


void append(ArrayList *list, int value)
{
    // printf("Implement append\n");
    // call resize if necessary
    if(list->capacity==list->size){
        printf("Resized array from %d to %d\n", list->capacity, list->capacity*2);
        resize(list,list->capacity*2);
    }
    // add value to the end of the list
    list->array[list->size]=value;
    // printf("added :%d at :%d\n",value,list->size);
    list->size++;
}



void insert(ArrayList *list, int value)
{
    // printf("Implement insert\n");
    // call resize if necessary
    if(list->capacity==list->size){
        printf("Resized array from %d to %d\n", list->capacity, list->capacity*2);
        resize(list,list->capacity*2);
    }
    // shift the elements to the right to make space
    
    for(int i = list->size;i>list->current_position;i--){
        list->array[i]=list->array[i-1];
    }

    // add value at the current position
    list->array[list->current_position]=value;
    list->size++;
    printf("inserted %d\n",value, list->current_position);
    // print_list(list);
}


int remove_at_current(ArrayList *list)
{
    if(list->size==0){
        printf("List is empty\n");
        return -1;
    }

    // printf("Implement remove_at_current\n");
    // return -1;
    // save the value of the current element in a variable
    int temp = list->array[list->current_position];
    // shift the elements to the left to fill the gap
    for(int i = list->current_position; i<list->size;i++){
        list->array[i]=list->array[i+1];
    }
    // change the size, and current position as necessary
    list->size--;
    printf("removed %d\n",temp);
    // list->current_position--;
    // call resize if necessary
    // print_list(list);
    if(list->size<=list->capacity/4){
        printf("Resized array from %d to %d\n", list->capacity, list->capacity/2);
        resize(list,list->capacity/2);
    }
    return temp;
}

int find(ArrayList *list, int value)
{
    if(list->size==0){
        printf("List is empty\n");
        return -1;
    }
    // printf("Implement find\n");
    // traverse the list and return the position of the value
    for(int i=0;i<list->size;i++){
        if(list->array[i]==value){
            printf("found %d at %d\n",value, i);
            return i;
        }
    }
    // return -1 if the value is not found
    printf("did not find %d in the list\n",value);
    return -1;
}


void move_to_start(ArrayList *list)
{
    // printf("Implement move_to_start\n");
    // consider the cases when the list is empty
    list->current_position=0;
    printf("moved current position to 0\n");
    // print_list(list);
}


void move_to_end(ArrayList *list)
{
    // printf("Implement move_to_end\n");
    // consider the cases when the list is empty
    list->current_position=list->size-1;
    printf("moved to current position to %d\n",list->size-1);
    // print_list(list);
}


void prev(ArrayList *list)
{
    // printf("Implement prev\n");
    // no change if the current position is at the start
    if(list->current_position>0)
        list->current_position--;
    printf("moved current position from %d to %d\n",list->current_position+1,list->current_position);
    // print_list(list);
}


void next(ArrayList *list)
{
    // printf("Implement next\n");
    // no change if the current position is at the end
    if(list->current_position==list->size-3){
        list->current_position++;
        printf("moved current position from %d to %d\n",list->current_position-1,list->current_position);
    }
    else{
        printf("current position is already at the end\n");
    }
    // print_list(list);
}


void move_to_position(ArrayList *list, int position)
{
    // printf("Implement move_to_position\n");
    printf("moved current position from %d to %d\n",list->current_position,position);
    if(position<list->size&&position>=0){
        list->current_position=position;
    }
    // print_list(list);
}


int get_current_position(ArrayList *list)
{
    // printf("Implement get_current_position\n");
    printf("current position is %d\n",list->current_position);
    // printf("current element is %d\n", list->array[list->current_position]);
    // print_list(list);
    return list->current_position;
}


int get_current_element(ArrayList *list)
{
    // printf("Implement get_current_element\n");
    printf("current element is %d\n", list->array[list->current_position]);
    // print_list(list);
    return list->array[list->current_position];
}

void free_list(ArrayList *list)
{
    // printf("Implement free_list\n");
    // free the array before terminating the program
    free(list->array);
    printf("Freed the list\n");
}


