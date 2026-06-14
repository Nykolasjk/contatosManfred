#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define maxContatos 100

	// significado typedef: a palavra que avisa o computador que vamos criar um apelido.
	// significado struct: a palavra que agrupa as informações.
	
	typedef struct { // o typedef struct cria um "apelido/atalho" para um tipo de dado personalizado. ela junta várias variáveis diferentes dentro de uma só. 
		
	char  nome[60]; // os [] indicam o tamanho máximo do vetor de caracteres, aqui vai ser 59 + \0. esse (\0) é um caractere de finalização.
	char telefone[20];
    char email[50];
    char cidade[30];
    char empresa[50];
    
} Contato;

Contato agenda[maxContatos];
int totalContatos = 0;

void limpar (){
	
	system("cls");
	
}

void incluirContato() {
	
	printf("\nNome: ");
	scanf(" %[^\n]", agenda[totalContatos].nome); // usei o " %[^\n]" pra poder ler tudo que for digitado, até clicar no "Enter". se fosse com o "%c" ele iria pegar apenas a primeira letra ou palavra antes do espaço. ex "oi, tudo bem" sairia apenas "oi,"

	printf("Telefone: ");
	scanf(" %[^\n]", agenda[totalContatos].telefone);

	printf("Email: ");
	scanf(" %[^\n]", agenda[totalContatos].email);

	printf("Cidade: ");
	scanf(" %[^\n]", agenda[totalContatos].cidade);

	printf("Empresa: ");
	scanf(" %[^\n]", agenda[totalContatos].empresa);

	totalContatos++;

    printf("\nContato cadastrado com sucesso!\n");
}

void listarContatos() {

    if(totalContatos == 0) {
        printf("\nNenhum contato cadastrado.\n");
    }

    printf("\n=========== CONTATOS ===========\n");

    for(int i = 0; i < totalContatos; i++) {

        printf("\nContato %d", i + 1);
        printf("\nNome: %s", agenda[i].nome);
        printf("\nTelefone: %s", agenda[i].telefone);
        printf("\nEmail: %s", agenda[i].email);
        printf("\nCidade: %s", agenda[i].cidade);
        printf("\nEmpresa: %s", agenda[i].empresa);
        printf("\n----------------------------");
    }
}



int main(void){
	
	int n=0;
	
	do{
		
		printf("\n====================================");
        printf("\n      AGENDA DE CONTATOS");
        printf("\n====================================");
		printf("\n1 - Incluir contato\n");
		printf("2 - Listar contatos\n");
		printf("3 - Consultar contato pelo nome\n");
		printf("4 - Excluir contato\n");
		printf("5 - Excluir contato\n");
		printf("Digite um numero de 1 a 5: ");
		scanf("%i", &n);
		limpar();
		
		switch(n){
		
		case 1:
			
			incluirContato();
			
		break;
		
		case 2:
		
			listarContatos();
		
		break;
		
		case 3:
			
		break;
		
		case 4:
			
		break;
		
		case 5:
			printf("Obrigado por utilizar nosso programa, volte sempre!\nPrograma criado por Carla Canalle Mundel e Nykolas Jose Kopp.");
		break;
		
		default:
			printf("Valor invalido, tente novamente.");
		break;
			
	}
	
		
	}while(n != 5);
	
	
	
	return 0;
}

