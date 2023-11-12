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
	char resposta;
	//final de cria��o de variaveis/stings
	
	do{ // abertura do DO/While, "fa�a isso"
	
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf);// %s refere-se a stings
		
	strcpy(arquivo, cpf);// Responsavel por criar os valores das strings
	
    FILE *file;// cria o arquivo
    file = fopen(arquivo, "w");// cria arquivo na pasta e o "W" significa escrever
    fprintf(file, "CPF: ");// fprintf e o printf dentro do arquivo/ Aparecer "CPF: " antes de aparecer o que o usu�rio digitou
    fprintf(file, cpf);//salvo o valor da variavel
    fclose(file);// fechar o arquivo
    
    printf("Digite o nome a ser cadastrado: ");//perguntando para o usu�rio o nome
    scanf("%s",nome);// salvando o que o usu�rio digitou na string
    
    file = fopen(arquivo, "a");// "A"atualizar/abrir o arquivo
    fprintf(file, ".\nNOME: "); // fprintf para salvar dentro desse arquivo/ Aparecer "NOME: " antes de aparecer o que o usu�rio digitou
    fclose(file);// fechar o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    
    printf("Digite o sebrenome a ser cadastrado: "); //perguntar o sobrenome
    scanf("%s", sobrenome);// salvar o que o usu�rio digitou
    
    file = fopen(arquivo, "a");
    fprintf(file, ".\nSOBRENOME: ");// Aparecer "SOBRENOME: " antes de aparecer o que o usu�rio digitou
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);  // Inserir o que o usu�rio digitou no arquivo
    fclose(file);
    
    
    printf("Digite o cargo a ser cadastrado: ");// Perguntar o cargo 
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, ".\nCARGO: ");// Aparecer "CARGO: "antes de aparecer o que o usu�rio digitou
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fprintf(file, ".\n");
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, "\n");
    fclose(file);
    
    printf("\n\n Deseja cadastrar outro CPF? (S/N): "); //perguntando para o usu�rio se ele deseja cadastrar mais CPFs
        scanf(" %c", &resposta);//resposta do usu�rio 
       } while (resposta == 'S' || resposta == 's');// || Igual a OU
       //enquanto a resposta for, sim, continuar cadastrando CPFs
     

    system("pause");// pausar a tela
    return 0;// c�digo de sa�da ao sistema operacional quando ele termina de ser executado
    

    
    
    }
int consulta()
{ 
	setlocale(LC_ALL, "Portuguese");// Definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: \n");// Recebendo qual usu�rio vai ser consultado.
    scanf("%s",cpf);
    printf("\n");
    
    
    FILE *file;
    file = fopen(cpf, "r"); //"r" Somente ler o arquivo
    
    
    if(file == NULL)// Se o valor retornado for null o arquivo n�o foi encontrado 
	{
	        printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n"); //Mensagem impressa quando o arquivo n�o for encontrado.
    }
    
	
    printf("Essas s�o as informa��es do usu�rio: \n\n");
    
    while(fgets(conteudo, 200, file) != NULL)//While/Enquanto estiver escrevendo na vari�vel ou na string conte�do at� 200 valores, que est�o dentro do arquivo, enquanto o valor for diferente de null ele vai continuar procurando
    //fgets Buscar o arquivo
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
    
  if (remove(cpf) == 0) 
  {
  	printf("Usu�rio removido com sucesso.\n");
  	system("pause");
  }
  else {
  	printf("O usu�rio n�o se encontra no sistema!\n");
  	system ("pause");
  	return 1; // // Retorna um c�digo de erro para indicar falha na remo��o
  }

    FILE *file;
    file = fopen(cpf,"r"); // abrir o arquivo cpf e ler
    
    if(file != NULL) {
    // Se o arquivo ainda existir ap�s a remo��o, h� algo errado
    printf("Erro: O arquivo ainda existe ap�s a remo��o!\n");
    fclose(file);
    system("pause");
    return 1;// Retorna um c�digo de erro
}

	fclose(file);//fechar o arquivo
	return 0; // Retorna 0 para indicar sucesso
}
int main()
{
	setlocale(LC_ALL, "Portuguese");
	int opcao=0; // Definindo vari�veis
	int laco=1;// Vari�vel laco/ tem que ser 1 para sempre entrar no for
	char senhadigitada[] = "a";
	int comparacao;
	
	
	
	printf("\t Cart�rio da EBAC\n\n");//Titulo
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	
	if(comparacao == 0)
	{//inicio do if
	
	    system("cls");
	    for(laco=1;laco=1;)// for = repita quantas vezes eu pedir / enquanto laco for 1 ele ira voltar no in�cio do menu at� o usu�rio pedir para sair
	    {// inicio do for
    	    system("cls"); // Para limpar a tela das op��es ateriores 
            setlocale(LC_ALL, "Portuguese");// Definindo a linguagem Para poder usar acentos
	
	        printf("\t Cart�rio da EBAC\n\n");// Inicio do menu
    	    printf("Escolher op��o desejada do menu:\n\n");// \n = espa�amento entre linhas
         	printf("\t1 - Registrar nomes\n");// \t = espa�amento na linha
         	printf("\t2 - Consultar nomes\n");
         	printf("\t3 - Deletar nomes\n");
         	printf("\t4 - Sair do Programa\n\n");// Fim do menu
        	printf("Op��o: ");
         	scanf("%d" , &opcao);// Armazena a op��o do usu�rio 1,2,3 ou 4 
	        // %d � respons�vel por armazenar vari�vel do tipo inteiro
        	system("cls");//Respons�vel por limpar a tela deletando as mensagens anteriores
    
            switch(opcao)// inicio da sele��o do menu switch case
		    {
			
    	    	case 1:
     	    	registro();//chamada da fun��o registro
                break;//para fechar chaves do Switch case
           	
                case 2:
                consulta();//chamada da fun��o consulta
                break;
         	
                case 3:
                deletar();//chamada da fun��o deletar
                break;
        
	            case 4: // Op��o de sair
                printf("Obrigado por utilizar o sistema!\n");//mensagem de sa�da
		        return 0;
		        break;	
        	
                default:
              	printf("Essa op��o n�o est� disponivel!\n");
	         	system("pause");
	        	break;
    	    }// fim da sele��o switch case
   	    }  // fim do for
   }//fim do if
    else
    printf("Senha incorreta!");

}// fim int main


