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

	//RECORRER FILA Y COLUMNA
	for(int i = 0 ; i<9 ; i++)
	{
		int marked_f[10] = {0,0,0,0,0,0,0,0,0,0};
		int marked_c[10] = {0,0,0,0,0,0,0,0,0,0};
		
		for(int j = 0 ; j<9 ; j++)
		{
        
            if (n->sudo[i][j] != 0)
            {
                if(marked_f[n->sudo[i][j]] == 0)
                    marked_f[n->sudo[i][j]] = 1;        
                else if (marked_f[n->sudo[i][j]] == 1)
                    return 0;
            }
                
            if (n->sudo[j][i] != 0)
            {
				if(marked_c[n->sudo[j][i]] == 0)
					marked_c[n->sudo[j][i]] = 1;
				else if (marked_c[n->sudo[j][i]] == 1)
					return 0;
                }
			}
	}

	for(int k = 0; k<9 ; k++)
	{
		int marked_sm[10] = {0,0,0,0,0,0,0,0,0,0};
		for(int p=0;p<9;p++)
		{
		    int i=3*(k/3) + (p/3) ;
		    int j=3*(k%3) + (p%3) ;
                
            if(n->sudo[i][j] != 0)
			{
                if(marked_sm[(n->sudo[i][j])]==0)
                    marked_sm[(n->sudo[i][j])] = 1;
                else if (marked_sm[(n->sudo[i][j])] == 1)
                    return 0;
			}
		}		
	}
    return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();

	if (n == NULL) return NULL;
	
	int i, j;
	for(int k = 1 ; k<=9 ; k++)
	{
		int comp = 0;
		Node * cpy_node = copy(n);
		for(i=0 ; i<9 ; i++)
			for(j=0 ; j<9 ; j++)
				if(cpy_node->sudo[i][j] == 0)
				{
					cpy_node->sudo[i][j] = k;
					break;
				}
		if(is_valid(cpy_node)==1)
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