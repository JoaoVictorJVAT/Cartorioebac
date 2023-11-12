#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h>// biblioteca de alocação de espaço de memória
#include <locale.h>// biblioteca de alocação de texto por região
#include <string.h>//biblioteca responsável por cuidar das strings


int registro()//Função responsavel por cadastrar os usuarios no sistema
    {   
    
    setlocale(LC_ALL, "Portuguese");// Definindo a linguagem
    //inicio de criação de variaveis/stings
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char resposta;
	//final de criação de variaveis/stings
	
	do{ // abertura do DO/While, "faça isso"
	
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf);// %s refere-se a stings
		
	strcpy(arquivo, cpf);// Responsavel por criar os valores das strings
	
    FILE *file;// cria o arquivo
    file = fopen(arquivo, "w");// cria arquivo na pasta e o "W" significa escrever
    fprintf(file, "CPF: ");// fprintf e o printf dentro do arquivo/ Aparecer "CPF: " antes de aparecer o que o usuário digitou
    fprintf(file, cpf);//salvo o valor da variavel
    fclose(file);// fechar o arquivo
    
    printf("Digite o nome a ser cadastrado: ");//perguntando para o usuário o nome
    scanf("%s",nome);// salvando o que o usuário digitou na string
    
    file = fopen(arquivo, "a");// "A"atualizar/abrir o arquivo
    fprintf(file, ".\nNOME: "); // fprintf para salvar dentro desse arquivo/ Aparecer "NOME: " antes de aparecer o que o usuário digitou
    fclose(file);// fechar o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    
    printf("Digite o sebrenome a ser cadastrado: "); //perguntar o sobrenome
    scanf("%s", sobrenome);// salvar o que o usuário digitou
    
    file = fopen(arquivo, "a");
    fprintf(file, ".\nSOBRENOME: ");// Aparecer "SOBRENOME: " antes de aparecer o que o usuário digitou
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);  // Inserir o que o usuário digitou no arquivo
    fclose(file);
    
    
    printf("Digite o cargo a ser cadastrado: ");// Perguntar o cargo 
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, ".\nCARGO: ");// Aparecer "CARGO: "antes de aparecer o que o usuário digitou
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fprintf(file, ".\n");
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, "\n");
    fclose(file);
    
    printf("\n\n Deseja cadastrar outro CPF? (S/N): "); //perguntando para o usuário se ele deseja cadastrar mais CPFs
        scanf(" %c", &resposta);//resposta do usuário 
       } while (resposta == 'S' || resposta == 's');// || Igual a OU
       //enquanto a resposta for, sim, continuar cadastrando CPFs
     

    system("pause");// pausar a tela
    return 0;// código de saída ao sistema operacional quando ele termina de ser executado
    

    
    
    }
int consulta()
{ 
	setlocale(LC_ALL, "Portuguese");// Definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: \n");// Recebendo qual usuário vai ser consultado.
    scanf("%s",cpf);
    printf("\n");
    
    
    FILE *file;
    file = fopen(cpf, "r"); //"r" Somente ler o arquivo
    
    
    if(file == NULL)// Se o valor retornado for null o arquivo não foi encontrado 
	{
	        printf("Não foi possivel abrir o arquivo, não localizado!. \n"); //Mensagem impressa quando o arquivo não for encontrado.
    }
    
	
    printf("Essas são as informações do usuário: \n\n");
    
    while(fgets(conteudo, 200, file) != NULL)//While/Enquanto estiver escrevendo na variável ou na string conteúdo até 200 valores, que estão dentro do arquivo, enquanto o valor for diferente de null ele vai continuar procurando
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
    
    printf("Digite o CPF do usuário a ser deletado:");
    scanf("%s", cpf);
    
  if (remove(cpf) == 0) 
  {
  	printf("Usuário removido com sucesso.\n");
  	system("pause");
  }
  else {
  	printf("O usuário não se encontra no sistema!\n");
  	system ("pause");
  	return 1; // // Retorna um código de erro para indicar falha na remoção
  }

    FILE *file;
    file = fopen(cpf,"r"); // abrir o arquivo cpf e ler
    
    if(file != NULL) {
    // Se o arquivo ainda existir após a remoção, há algo errado
    printf("Erro: O arquivo ainda existe após a remoção!\n");
    fclose(file);
    system("pause");
    return 1;// Retorna um código de erro
}

	fclose(file);//fechar o arquivo
	return 0; // Retorna 0 para indicar sucesso
}
int main()
{
	setlocale(LC_ALL, "Portuguese");
	int opcao=0; // Definindo variáveis
	int laco=1;// Variável laco/ tem que ser 1 para sempre entrar no for
	char senhadigitada[] = "a";
	int comparacao;
	
	
	
	printf("\t Cartório da EBAC\n\n");//Titulo
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	
	if(comparacao == 0)
	{//inicio do if
	
	    system("cls");
	    for(laco=1;laco=1;)// for = repita quantas vezes eu pedir / enquanto laco for 1 ele ira voltar no início do menu até o usuário pedir para sair
	    {// inicio do for
    	    system("cls"); // Para limpar a tela das opções ateriores 
            setlocale(LC_ALL, "Portuguese");// Definindo a linguagem Para poder usar acentos
	
	        printf("\t Cartório da EBAC\n\n");// Inicio do menu
    	    printf("Escolher opção desejada do menu:\n\n");// \n = espaçamento entre linhas
         	printf("\t1 - Registrar nomes\n");// \t = espaçamento na linha
         	printf("\t2 - Consultar nomes\n");
         	printf("\t3 - Deletar nomes\n");
         	printf("\t4 - Sair do Programa\n\n");// Fim do menu
        	printf("Opção: ");
         	scanf("%d" , &opcao);// Armazena a opção do usuário 1,2,3 ou 4 
	        // %d É responsável por armazenar variável do tipo inteiro
        	system("cls");//Responsável por limpar a tela deletando as mensagens anteriores
    
            switch(opcao)// inicio da seleção do menu switch case
		    {
			
    	    	case 1:
     	    	registro();//chamada da função registro
                break;//para fechar chaves do Switch case
           	
                case 2:
                consulta();//chamada da função consulta
                break;
         	
                case 3:
                deletar();//chamada da função deletar
                break;
        
	            case 4: // Opção de sair
                printf("Obrigado por utilizar o sistema!\n");//mensagem de saída
		        return 0;
		        break;	
        	
                default:
              	printf("Essa opção não está disponivel!\n");
	         	system("pause");
	        	break;
    	    }// fim da seleção switch case
   	    }  // fim do for
   }//fim do if
    else
    printf("Senha incorreta!");

}// fim int main


