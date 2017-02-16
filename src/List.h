//@author Zach Sabin
//@author Kyle Zeller
//create the structure and define all the functions

typedef struct Node {
	//max filename length
    char value[256];
	//pointer to the next node in the list
    struct Node *next;
} Node;

typedef struct List {
	//pointer to the head node in the list
    struct Node *head;
} List;

void print_list(List *list);
void pushToEnd(List *list, char *value);
void pushToFront(List *list, char *value);
void removeFirst(List *list);
void removeLast(List *list);
void removeNode(List *list, int n);
void addElement(List *list, char *value);
List *create_list();