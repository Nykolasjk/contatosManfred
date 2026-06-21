#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define maxContatos 1024

	// significado typedef: a palavra que avisa o computador que vamos criar um apelido.
	// significado struct: a palavra que agrupa as informações.
	
	typedef struct { // o typedef struct cria um "apelido/atalho" para um tipo de dado personalizado. ela junta várias variáveis diferentes dentro de uma só. 
		
	char nome[60]; // os [] indicam o tamanho máximo do vetor de caracteres, aqui vai ser 59 + \0. esse (\0) é um caractere de finalização.
	char telefone[20];
    char email[50];
    char cidade[30];
    char empresa[50];
    
} Contato;

Contato agenda[maxContatos];
int totalContatos = 0;

void limpar();
void incluirContato();
void listarContatos();
void buscarContato();
void excluirContato();

int main(void){
	
	int n=0;
	
	do{
		
		printf("\n====================================");
        printf("\n      AGENDA DE CONTATOS");
        printf("\n====================================");
		printf("\n[1] - Incluir contato\n");
		printf("[2] - Listar contatos\n");
		printf("[3] - Buscar contato pelo nome\n");
		printf("[4] - Excluir contato\n");
		printf("[5] - Sair\n");
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
			
			buscarContato();
			
		break;
		
		case 4:
			
			excluirContato();
			
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

void limpar (){
	
	system("cls");
	
}

void incluirContato() {
	
	printf("\n=========== ADICIONAR CONTATOS ===========\n");
	
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

    printf("\n=========== CONTATOS ===========\n");
    
     if(totalContatos == 0) {
        printf("\nNenhum contato cadastrado.\n"); //fazer uma funcao pra isso? 
    }

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

void buscarContato(){
    char nome[60];
    int encontrado = 0;

	printf("\n============== BUSCA DE CONTATOS ==============\n");
	
	 if(totalContatos == 0) {
        printf("\nNenhum contato cadastrado.\n");
        return;
    }

    printf("\nDigite aqui o nome que deseja buscar: ");
    scanf(" %[^\n]", nome);

    for(int i = 0; i < totalContatos; i++) // faz o laço pra percorrer todos os contatos disponiveis
    {
        if(strcmp(nome, agenda[i].nome) == 0) // usei o strcmp pra comparar as strings, ele avalia caracter por caracter e ai valida. 
        										//strcmp valida assim: se for 0, quer dizer que é igual ao contato que esta armazenado, se for diferente da erro
        										// ele esta comparando o nome digitado na busca com os nomes na posição "i" da agenda
        {
            printf("\nNome: %s", agenda[i].nome);
            printf("\nTelefone: %s", agenda[i].telefone);
            printf("\nEmail: %s", agenda[i].email);
            printf("\nCidade: %s", agenda[i].cidade);
            printf("\nEmpresa: %s\n", agenda[i].empresa);

            encontrado = 1;
        }
    }

    if(!encontrado)
    {
        printf("\nContato nao encontrado.\n");
    }
}

void excluirContato(){
	char nome[60];
    int encontrado = 0;
    
    printf("\n============== EXCLUSAO DE CONTATOS ==============\n");
    
     if(totalContatos == 0) {
        printf("\nNenhum contato cadastrado.\n");
        return;
    }
	
	 printf("\nDigite aqui o nome do contato que deseja excluir: ");
	 scanf(" %[^\n]", nome);
	
	for(int i = 0; i < totalContatos; i++)
    {
        if(strcmp(nome, agenda[i].nome) == 0) {
           
           for(int j = i; j < totalContatos - 1; j++)
            {
                agenda[j] = agenda[j + 1]; // troca a posição na agenda ao excluir o contato. se o 1ª contato for excluido, o 2ª pega sua posição, como se fosse uma esteira movendo pra esquerda os produtos
            }

            totalContatos--; // muda o total de contatos :p meio obvio mas e melhor pra gravar o que faz
           
           	printf("\nContato deletado com sucesso!\n");
           
            encontrado = 1;
            
        }
    }
    
    
    if(!encontrado)
    {
        printf("\nContato nao encontrado.\n");
    }
}