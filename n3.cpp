#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxContatos 100

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
int contatoExiste(char nome[]);
void listarContatos();
void buscarContato();
void alterarContato();
void excluirContato();

int main(void){
	
	int n=0;
	
	do{
		
		printf("\n==================================");
        printf("\n      AGENDA DE CONTATOS");
        printf("\n==================================\n");
		printf("\n[1] - Incluir contato\n");
		printf("[2] - Listar contatos\n");
		printf("[3] - Buscar contato\n");
		printf("[4] - Alterar contato\n");
		printf("[5] - Excluir contato\n");
		printf("[6] - Sair\n");
		printf("\n----------------------------------\n");
		printf("\nDigite um numero de 1 a 6: ");
		
   		if(scanf("%i", &n) != 1){
    		n = 0;
    		fflush(stdin);
		}
		
		limpar();
		
		switch(n){
		
			case 1: incluirContato(); break;
		
			case 2: listarContatos(); break;
		
			case 3: buscarContato(); break;
		
			case 4: alterarContato(); break;
			
			case 5: excluirContato(); break;
			
			case 6: printf("Obrigado por utilizar nosso programa, volte sempre!\nPrograma criado por Carla Canalle Mundel e Nykolas Jose Kopp."); break;
			
			default: printf("\n[VALOR INVALIDO, TENTE NOVAMENTE.]\n"); break;
		}
		
	}while(n != 6);
	
	return 0;
}

void limpar (){
	
	system("cls");
	
}

void incluirContato(){
	
	char nome[60];
	
	if(totalContatos >= maxContatos){
        printf("\nAgenda cheia! Limite de %i contatos atingido.\n", maxContatos);
    	return;
	}
	
	printf("\n=========== ADICIONAR CONTATOS ===========\n");
	
	printf("\nNome: ");
	scanf(" %[^\n]", nome); // usei o " %[^\n]" pra poder ler tudo que for digitado, até clicar no "Enter". se fosse com o "%c" ele iria pegar apenas a primeira letra ou palavra antes do espaço. ex "oi, tudo bem" sairia apenas "oi,"

	if(contatoExiste(nome)){
        printf("\nJa existe um contato com esse nome!\n");
    	return;
	}

	strcpy(agenda[totalContatos].nome, nome);

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

int contatoExiste(char nome[]){
	
	for(int i = 0; i < totalContatos; i++){
		if(strcmp(nome, agenda[i].nome) == 0){
			return 1;
		}
	}
	return 0;	
}

void listarContatos(){
	
	printf("\n=========== CONTATOS ===========\n");
	
    if(totalContatos == 0){
    	printf("\nNenhum contato cadastrado.\n");
    }

    // cópia temporária para não bagunçar a ordem original
    Contato temp[maxContatos];
    for(int i = 0; i < totalContatos; i++){
        temp[i] = agenda[i];
    }
    
    // bubble sort
    for(int i = 0; i < totalContatos - 1; i++){
        for(int j = 0; j < totalContatos - 1; j++){
            if(strcmp(temp[j].nome, temp[j+1].nome) > 0){
                Contato aux = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = aux;
            }
        }
    }
    
    for(int i = 0; i < totalContatos; i++){
        printf("\nContato %i", i + 1);
        printf("\nNome: %s", temp[i].nome);
        printf("\nTelefone: %s", temp[i].telefone);
        printf("\nEmail: %s", temp[i].email);
        printf("\nCidade: %s", temp[i].cidade);
        printf("\nEmpresa: %s", temp[i].empresa);
        printf("\n----------------------------");
    }
    printf("\n");
}

void buscarContato(){
    char nome[60];
    int encontrado = 0;

	printf("\n============== BUSCA DE CONTATOS ==============\n");
	
	if(totalContatos == 0){
    	printf("\nNenhum contato cadastrado para busca.\n");
        return;
    }

	//listarContatos();
	printf("\nPara acessar um contato, digite o nome que deseja buscar: ");
    scanf(" %[^\n]", nome);                            

    for(int i = 0; i < totalContatos; i++){ // faz o laço pra percorrer todos os contatos disponiveis
    	if(strstr(agenda[i].nome, nome) != NULL){ /* usei o strstr pra comparar as strings, ele avalia caracter por caracter e ai valida. strcmp valida assim: se for 0, quer dizer que é igual ao contato que esta armazenado, se for diferente da erro ele esta comparando o nome digitado na busca com os nomes na posição "i" da agenda.*/
         	printf("\n============== CONTATO ENCONTRADO ==============\n");
			printf("\nNome: %s", agenda[i].nome);
            printf("\nTelefone: %s", agenda[i].telefone);
            printf("\nEmail: %s", agenda[i].email);
            printf("\nCidade: %s", agenda[i].cidade);
            printf("\nEmpresa: %s\n", agenda[i].empresa);

            encontrado = 1;
        }
    }

    if(!encontrado){
        printf("\nContato nao encontrado.\n");
    }
}

void alterarContato(){
	char nome[60];
    int encontrado = 0;

    printf("\n============== ALTERAR CONTATO ==============\n");

    if(totalContatos == 0){
        printf("\nNenhum contato cadastrado para alteracao.\n");
        return;
    }

    listarContatos();

    printf("\nDigite o nome do contato que deseja alterar: ");
    scanf(" %[^\n]", nome);

    for(int i = 0; i < totalContatos; i++){

        if(strcmp(nome, agenda[i].nome) == 0){

            printf("\n---- Digite os novos dados ----\n");

            char novoNome[60];
            printf("Nome: ");
            scanf(" %[^\n]", novoNome);

            if(strcmp(novoNome, agenda[i].nome) != 0 && contatoExiste(novoNome)){ // a primeira condicao verifica se é o mesmo nome atual, se for, ta de boa, pode ser. a segunda olha se ja tem outro contato com esse novo nome. o && obriga que as duas sejam verdadeiras.
                printf("\nJa existe um contato com esse nome!\n");
                return;
            }

            strcpy(agenda[i].nome, novoNome);

            printf("Telefone: ");
            scanf(" %[^\n]", agenda[i].telefone);

            printf("Email: ");
            scanf(" %[^\n]", agenda[i].email);

            printf("Cidade: ");
            scanf(" %[^\n]", agenda[i].cidade);

            printf("Empresa: ");
            scanf(" %[^\n]", agenda[i].empresa);

            printf("\nContato alterado com sucesso!\n");

            encontrado = 1;
            break;
        }
    }

    if(!encontrado){
        printf("\nContato nao encontrado.\n");
    }
}

void excluirContato(){
	char nome[60];
    int encontrado = 0;
    
    printf("\n============== EXCLUSAO DE CONTATOS ==============\n");
    
     if(totalContatos == 0){
        printf("\nNenhum contato cadastrado para exclusao.\n");
        return;    
    }
	
	 listarContatos();
	
	 printf("\nDigite aqui o nome do contato que deseja excluir: ");
	 scanf(" %[^\n]", nome);                                        
	
	for(int i = 0; i < totalContatos; i++){
        if(strcmp(nome, agenda[i].nome) == 0){
           
           for(int j = i; j < totalContatos - 1; j++){ 
                agenda[j] = agenda[j + 1]; // troca a posição na agenda ao excluir o contato. se o 1ª contato for excluido, o 2ª pega sua posição, como se fosse uma esteira movendo pra esquerda os produtos
            }

            totalContatos--; // muda o total de contatos :p meio obvio mas e melhor pra gravar o que faz
           
           	printf("\nContato deletado com sucesso!\n");
           
            encontrado = 1;
            
        }
    }
    
    
    if(!encontrado){
        printf("\nContato nao encontrado.\n");
    }
}