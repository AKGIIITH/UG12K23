#define MAX_MEMBERS 100 //Defining Macro like a variable

typedef struct Person { //Structure with ID and name and age
    int ID;
    char Name[20];
    int age;
}Biodata;
// typedef struct SocialNet { //Structure with Person and no. of connection
//     Person members[MAX_MEMBERS];
//     int size;
// } SocialNet;


typedef struct Node { //Linked List with Node containig Data in Tail with Biodata and nested struct pointer
    Biodata data;
    Node* next; //Struct Datatype pointer// can be Struct node * too
    //can it be int datatype pointer
    int* mext;
} Node;

typedef Node* LinkedList;

Node third = {
    {01,"Alice", 22},
    NULL,
    NULL
};
Node second = {
    {02,"Bob", 26},
    &third,
    &third
};
Node first = {
    {03,"Charlie", 20},
    &second,
    &second
};

Node* Last = &first;
typedef Last l;

//
int size(Node* Last) {
    int s = 0;
    while (Last != NULL) {
        Last = Last->next;
        s ++;
    }
    return s;
}
void print_list(LinkedList l) {
    while (l != NULL) {
        printf("%s\t\t%d\n",l->data.name, l->data.age);
        l = l->next;   
    }
}

