#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define fil 8//tamaño de la matriz
#define col 8//

int matriz[fil][col];
bool matrizV[fil][col];//matrizVisitados

int dx[4]={-1,1,0,0};//izquierda o deracha
int dy[4]={0,0,-1,1};//arriba o abajo

//inicialisar la matriz de visitados
void llenarMatrizV(){
	
	for(int i=0; i<fil ;i++){
		
		for(int j=0; j<col;j++){
			
			matrizV[i][j]=false;
			
			}
		}
	}

int generarNumero(){
	return (rand() % 2);
}

//printf
void mostrarMatriz(){
	for(int i=0; i<fil ;i++){
		
		for(int j=0; j<col;j++){
			
			printf("%d ", matriz[i][j])	;		
			}
			printf("\n");

		}
	}
	
//rellenar la matriz aleatoriamente	
void llenarMatriz(){
	for(int i=0; i<fil ;i++){
		
		for(int j=0; j<col;j++){
			
			matriz[i][j]=generarNumero();
			
			}
		}
	}
//buscar en profundidad hasta el final de una rama
void algoritmoDFS(int x, int y){
	matrizV[x][y]=true;//marcar como visitado
	for(int i=0 ; i<4; i++){
		int fx = x + dx[i];
		int fy = y + dy[i];
		
		if(fx>=0 && fx<fil && fy>=0 && fy<col && matrizV[fx][fy]!=true && matriz[fx][fy]==1){
			algoritmoDFS(fx, fy);
			}
		}

	}
	
	

//contar cuantas islas ecuentra
int buscarIslas(){
	int cont = 0;
	llenarMatrizV();
		for(int i=0; i<fil ;i++){
		
			for(int j=0; j<col;j++){
				
				if(matriz[i][j] == 1 && matrizV[i][j]==false){
					algoritmoDFS(i,j);
					cont++;
					
					} 					
			}
		}
		return cont;
		
	}
	
int main(){
	srand(time(NULL));
	llenarMatriz();
	mostrarMatriz();
	printf("Total de Islas: %d",buscarIslas());
	return 0;
}
