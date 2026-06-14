#include <stdio.h>
#include <stdlib.h>



int main(void){
	
	int n=0;
	char nome[10], tel[10];
	
	/*void limpa(void);{
		system("cls");
	}*/
	
	do{
		
		system("cls");
		printf("1 - Incluir contato\n");
		printf("2 - Listar contatos\n");
		printf("3 - Consultar contato pelo nome\n");
		printf("4 - Excluir contato\n");
		printf("5 - Excluir contato\n");
		printf("Digite um numero de 1 a 5: ");
		scanf("%i", &n);
		
		switch(n){
		
		case 1:
			
			system("cls");
			printf("Liste aqui as informações de contato:\n");
			printf("Digite o nome do contato: ");
			scanf("%c", &nome);
			printf("\n");
			// descobrir como diferenciar nome de numeros com if
			printf("Digite o telefone do contato: ");
			scanf("%c", &tel);
			
		break;
		
		case 2:
		
		break;
		
		case 3:
			
		break;
		
		case 4:
			
		break;
		
		case 5:
			printf("Obrigado por utilizar nosso programa, volte sempre!");
		break;
		
		default:
			printf("Valor inválido, tente novamente.");
		break;
			
	}
	
		
	}while(n != 5);
	
	/*switch(n){
		
		case 1:
			printf("Liste aqui as informações de contato:\n");
		break;
		
		case 2:
		
		break;
		
		case 3:
			
		break;
		
		case 4:
			
		break;
		
		case 5:
			printf("Obrigado por utilizar nosso programa, volte sempre!");
		break;
		
		default:
			printf("Valor inválido, tente novamente.");
		break;
			
	}*/
	
	
	return 0;
}