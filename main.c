#include <stdio.h>
#include <math.h>
#include <stdlib.h>


// -----------------------

int heap[50], minHeap[50];
int totalElementos=0;

int indiceFilhoEsq(int x){
    int indice=(2*x)+1;
    if(x>=totalElementos||indice>=totalElementos)
      return-1;
    else
      return indice;
}

int indiceFilhoDir(int x){
    int indice=(2*x)+2;
    if(x>=totalElementos||indice>=totalElementos)
      return-1;
    else
      return indice;
}

int indicePai(int x){
    int indice=(int) floor((x-1)/2);
    if(x<=0||x>=totalElementos)
      return-1;
    else
      return indice;
}

// ------------------------------------

void AjustarSubindo(int *heap, int pos){
  if(pos!=-1){
    int pai = indicePai(pos);
    if(pai!=-1){
      if(heap[pos]>heap[pai]){
        int aux=heap[pos];
        heap[pos]=heap[pai];
        heap[pai]=aux;
        AjustarSubindo(heap, pai);
      }
    }
  }
}

void Inserir (int *heap, int x){
  heap[totalElementos]=x;
  totalElementos++;
  AjustarSubindo(heap, totalElementos-1);
}

void AjustarSubindoMin(int *heap, int pos){
  if(pos!=-1){
    int pai = indicePai(pos);
    if(pai!=-1){
      if(heap[pos]<heap[pai]){
        int aux=heap[pos];
        heap[pos]=heap[pai];
        heap[pai]=aux;
        AjustarSubindoMin(heap, pai);
      }
    }
  }
}

void InserirMin (int *heap, int x){
  heap[totalElementos]=x;
  totalElementos++;
  AjustarSubindoMin(heap, totalElementos-1);
}

// -----------------------------------------

void AjustarDescendo(int *heap, int pos){
  if(pos!=-1 && indiceFilhoEsq(pos)!=-1){
    int indiceMaiorFilho=indiceFilhoEsq(pos);
    if(indiceFilhoDir(pos)!=-1 && heap[indiceFilhoDir(pos)]>heap[indiceMaiorFilho])
      indiceMaiorFilho=indiceFilhoDir(pos);

    if(heap[indiceMaiorFilho]>heap[pos]){
      int aux = heap[pos];
      heap[pos] = heap[indiceMaiorFilho];
      heap[indiceMaiorFilho]=aux;
      AjustarDescendo(heap, pos);
      
    }
  }
}

int Remover(int *heap){
  if(totalElementos==0)
    return-1;
  else{
    int retorno=heap[0];
    heap[0]=heap[totalElementos-1];
    totalElementos--;
    AjustarDescendo(heap, 0);
    return retorno;
  }
}


void AjustarDescendoMin(int *heap, int pos){
  if(pos!=-1 && indiceFilhoEsq(pos)!=-1){
    int indiceMaiorFilho=indiceFilhoEsq(pos);
    if(indiceFilhoDir(pos)!=-1 && heap[indiceFilhoDir(pos)]<heap[indiceMaiorFilho])
      indiceMaiorFilho=indiceFilhoDir(pos);

    if(heap[indiceMaiorFilho]<heap[pos]){
      int aux = heap[pos];
      heap[pos] = heap[indiceMaiorFilho];
      heap[indiceMaiorFilho]=aux;
      AjustarDescendoMin(heap, pos);
      
    }
  }
}

int RemoverMin(int *heap){
  if(totalElementos==0)
    return-1;
  else{
    int retorno=heap[0];
    heap[0]=heap[totalElementos-1];
    totalElementos--;
    AjustarDescendoMin(heap, 0);
    return retorno;
  }
}

// --------------------------------

void printHeap(int *heap, int tam){
  for(int i=0; i<tam; i++){
    printf("\n%d", heap[i]);
  }
}

// --------------------------------

int main(void) {

  int escolha=1;
  while(escolha!=4){
    
    printf("\n\n---MENU DE OPÇÔES---\nDigite 1 para inserir um elemento x\nDigite 2 para remover um elemento\nDigite 3 para imprimir a heap\nDigite 4 para sair\n\nEscolha: ");
    scanf("%d", &escolha);
    if(escolha==1){
      printf("Digite o valor de x: ");
      int x;
      scanf("%d", &x);
      InserirMin(minHeap, x);
    }
    if(escolha==2)
      RemoverMin(minHeap);
    if(escolha==3)
      printHeap(minHeap, totalElementos);
  }
  printf("\n\nFim");
  return 0;
}