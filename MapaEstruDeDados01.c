
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//As bibliotecas


#define tamanho 5
//Constante tamanho 5


typedef struct t_estudande{
	char ra[18];
	char nome_arquivo[45];
	char ext_arquivo[25]; 
	char matricula_pro[18];	
}t_estudante;
//Estrutura do t_estudante


typedef struct t_fila{
    t_estudante dados[tamanho];
	int inicio;
	int fim;
}t_fila;
// Estrutura da t_fila


struct t_fila fila;
int op;
//Variáveis globais


void fila_adicionar();
void fila_sair();
void fila_exibir();
void menu_exibir();
void fila_finalizar();
void fila_zerar();
//Estrutura de Protipação


int main(){
	setlocale(LC_ALL, "Portuguese");
	SetConsoleOutputCP (1252);
	SetConsoleCP (1252);
	op = 1;
	fila.inicio=0;
	fila.fim=0;
	while(op!=0){
		system("cls");
		fila_exibir();
		menu_exibir();
		scanf("%d", &op); 
		switch(op){
			case 0:
				fila_finalizar();
			break;
			case 1:
				fila_adicionar();
			break;
			case 2:
				fila_sair();
			break;
			case 3:
				fila_zerar();
			break;
			default:
				printf("\n OPÇÃO INEXISTENTE, POR FAVOR, ESCOLHA UMA DAS OPÇÕES DO MENU ENTRE: [ 0, 1, 2, 3 ]!  \n\n");
				system("pause");
			break;
		}
	}
	return(0);
}
//Função principal do programa


void fila_adicionar(){
	int i;
	if(fila.fim == tamanho){
		printf("\n\n Fila cheia! \n\n");
		system("pause");
	}	else{
		printf("\nInsira o RA do aluno: ");
		scanf(" %s", fila.dados[fila.fim].ra);
		fflush(stdin);
		printf("\nInsira o nome do arquivo: ");
		fgets(fila.dados[fila.fim].nome_arquivo,45, stdin);
		fflush(stdin);
		printf("\nInsira a extensão do arquivo: ");
		fgets(fila.dados[fila.fim].ext_arquivo, 18, stdin);
		fflush(stdin);
		printf("\nInsira a matrícula do professor: ");
		fgets(fila.dados[fila.fim].matricula_pro, 18, stdin);
		fflush(stdin);
		fila.fim++;	
	}
	
}
//Função que adiciona elementos na fila


void fila_sair(){
	int i;
	if( fila.inicio == fila.fim){
		printf("\n\n   FILA VAZIA! \n\n");
		system("pause");
	}	else{
		int i;
		printf("\n         RA: %s\n         NOME DO ARQUIVO: %s\n         EXTENSÃO DO ARQUIVO: %s\n         MATRÍCULA DO PROFESSOR: %s\n\n", fila.dados[fila.inicio].ra, fila.dados[fila.inicio].nome_arquivo, fila.dados[fila.inicio].ext_arquivo, fila.dados[fila.inicio].matricula_pro);
 		system("pause");
		for (i = 0; i < tamanho; i++){
			fila.dados[i] = fila.dados[i+1];
		}
		fila.dados[fila.fim];
		fila.fim--;	
	}
}
// Função que remove o primeiro elemento da fila


void fila_zerar(){
	if( fila.inicio == fila.fim){
		printf("\n\n   FILA VAZIA! \n\n");
		system("pause");
	} 	else{
		 	while(fila.inicio != fila.fim){
		 		int i;
		 		for( i = 0; i< tamanho; i++){
		 			fila.dados[i] = fila.dados[i+1];
				}
		 		fila.dados[fila.fim];
				fila.fim--;	 
			}
		}
}
// função que zera toda a fila


void fila_exibir(){ 
	int i;
	do{
				
		for(i = 0; i < fila.fim; i++)
		
		{
			printf("------------------------------------------------------------------------------------------\n\n");
			printf("         RA: %s \n         NOME DO ARQUIVO: %s \n         EXTENSÃO DO ARQUIVO: %s \n         MATRÍCULA DO PROFESSOR: %s \n\n", fila.dados[i].ra, fila.dados[i].nome_arquivo, fila.dados[i].ext_arquivo, fila.dados[i].matricula_pro);	
		} 
		printf("------------------------------------------------------------------------------------------\n\n");
	} while(fila.inicio == tamanho);
}
//Exibi a fila.



void fila_finalizar(){
	printf("\n\n  Finalizando o programa! \n\n");
	system("pause");
	

}
//função que encerra o programa


void menu_exibir(){
	printf("              \n----------------------  MENU: -------------------------\n\n");
	printf("    1 ---> ADICIONAR UM ELEMENTO NA FILA.\n");
	printf("    2 ---> RETIRAR UM ELEMENTO DA FILA.\n");
	printf("    3 ---> LIMPAR TODA A FILA.\n");
	printf("    0 ---> FINALIZAR O PROGRAMA.\n\n");
	printf("\n--------------------------------------------------------\n");
}
// Menu que exibi as escolhas para os usuários
