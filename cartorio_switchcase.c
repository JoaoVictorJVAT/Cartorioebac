#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h>// biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h>// biblioteca de aloca��o de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuidar das strings


int registro()//Fun��o responsavel por cadastrar os usuarios no sistema
    {   
    setlocale(LC_ALL, "Portuguese");// Definindo a linguagem
    //inicio de cria��o de variaveis/stings
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de cria��o de variaveis/stings
	printf("Digite o CPF a ser cadastrado: "); //coletando infotma��o do usu�rio
	scanf("%s", cpf);// %s refere-se a stings
		
	strcpy(arquivo, cpf);// Responsavel por criar os valores das strings
    FILE *file;// cria o arquivo
    
    file = fopen(arquivo, "w");// cria arquivo na pasta e o "W" significa escrever
    fprintf(file, "CPF: ");
    fprintf(file, cpf);//salvo o valor da variavel
    fclose(file);// salvo o arquivo
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");// "A"atualizar arquivo
    fprintf(file, ".\nNOME: ");
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    
    printf("Digite o sebrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, ".\nSOBRENOME: ");
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, ".\nCARGO: ");
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fprintf(file, ".\n");
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, "\n");
    fclose(file);
    
    
    system("pause");
    
    
    }
int consulta()
{ 
	setlocale(LC_ALL, "Portuguese");// Definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: \n");
    scanf("%s",cpf);
    printf("\n");
    
    
    FILE *file;
    file = fopen(cpf, "r"); //"r" ler o arquivo
    
    
    if(file == NULL)
	{
	        printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");
    }
    
	
    printf("Essas s�o as informa��es do usu�rio: \n\n");
    
    while(fgets(conteudo, 200, file) != NULL)
	{
          	printf("%s", conteudo);
	}
	fclose(file);
	system("pause");
	
	
	
	
	
} 
int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado:");
    scanf("%s", cpf);
    
    remove(cpf);
   
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL);
	{	
	    printf("O usu�rio n�o se encontra no sistema! .\n");
	    system("pause");
	}
	
	fclose(file);
}
int main()
{
	int opcao=0; // Definindo vari�veis
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{
    	system("cls");
        setlocale(LC_ALL, "Portuguese");// Definindo a linguagem
	
	    printf("\t Cart�rio da EBAC\n\n");// Inicio do menu
    	printf("Escolher op��o desejada do menu:\n\n");// \n = espa�amento entre linhas
    	printf("\t1 - Registrar nomes\n");// \t = espa�amento 
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n");
    	printf("\t4 - Sair do Programa\n\n");// Fim do menu
    	printf("Op��o: ");
    	scanf("%d" , &opcao);// Armazenamento da op��o do usu�rio
	
    	system("cls");//responsavel por limpar a tela
    
    switch(opcao)// inicio da sele��o do menu /switch case
		{
			
		case 1:
			registro();//chamada de fun�oes
            break;
           	
        case 2:
            consulta();
        	break;
         	
        case 3:
        	deletar();
        	break;
        
		case 4:
            printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;	
        	
        default:
        	printf("Essa op��o n�o est� disponivel!\n");
	       	system("pause");
	       	break;
    	}
   	}  // fim da sele��o switch case
}


