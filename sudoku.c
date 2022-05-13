#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){

    return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();
	/*
	cambiar valor de la primera casillla vacia 
	:::: for i in k, for o in k, sea k la dimension del sudoku (3*3)
	if casilla vacia, llenar con numero (uno al nueve)
	CASILLA VACIA :::: 0

	Ciclo para la creacion de nodos.... 
	como existen 9 casos posibles, nueve numeros. un ciclo que vaya del 0 al 9
	copiar nodo, buscar casilla vacia, insertar numero, agregar a lista el nuevo nodo.

	alternativa,emte, lo PRIMERO QUE SE HACE es buscar lña casilla vacia para insertar el valor.
con el ciclo se copian los nodos para agregarlños a la lista ista. :3
	*/
	if (n == NULL) return NULL;
	
	int i, j;
	for(i=0 ; i<3 ; i++)
		for(j=0 ; j<3 ; j++)
			if(n->sudo[i][j] == 0)
				break;

	for(int k = 1 ; k<=9 ; k++)
	{
		Node * cpy_node = copy(n);
		cpy_node->sudo[i][j] = k;
		pushBack(list, cpy_node);
	}
	
    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/