#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //biblioteca para comando setlocale, aceitar caracteres da lingua portuguesa
#include <string.h>//biblioteca para manipular strings

typedef struct filme{ //struct que me diz os atributos dos filmes, o typedef muda o tipo para Tfilme.
	int id;
	int ano;
	char titulo[50];
	char genero[50];
}Tfilme;

typedef struct cliente{ //struct que me diz os atributos dos clientes, o typedef muda o tipo para Tcliente.
    int id;
	char nome[30];
	char cpf[13];
	char email[30];
}Tcliente;

typedef struct estoque{ //struct que diz os atributos do estoque.
    int quantidade;
    int idf;
    char dataentrada[10];
    char titulof[50];
}Testoque;


Tfilme listaf[50]; //a variavel com vetor da lista dos filmes
Tcliente listac[50];//a variavel com vetor da lista dos clientes
Testoque listae[50];// a variavel com o vetor da lista do estoque
char busca[50],c[]={0}; //um variavel criada para localizar os filmes e clientes pelo nome  com o comando strcmp
int z=0,x,y=0,cont=0,conty=0,conte=0;//variaveis de seleção de menu, de comandos de repetição e de contadores de filmes e clientes(cont para filmes e conty para clientes)


void instrucao(){// função de instruções para um bom uso do programa
    printf("\n--------INSTRUCOES--------\n");
    printf("Insira o id dos filmes e dos clientes apartir do número 1.\n");
    printf("Para saber a posicao atual do id liste os filmes ou clientes.\n");
    printf("Use apenas os numeros listados nos menus para escolher o passo a seguir no menu.\n");
    printf("Ao excluir um filme use a funcao do editar atualizar para colocar outro no lugar.\n\n");
    menu();// chama o menu principal quando terminar a função
}

void posicaoestoque(){
        printf("\nInsira o ID do filme: ");
        scanf("%s*%d",&c);//scaneamos a string c mas alocamos seu endereço num tipo inteiro com um ponteiro
        setbuf(stdin,NULL);// todo setbuf desse é pra limpar o buffer
        x= strtol(c,NULL,10); // x recebe o valor inserido no tipo char c e entao usa o strtol para converte-lo em long int.
        if(x==0 || x<0|| x<conte){
           printf("ID inadequado!\n");
           menuestoque();
            }
        x-=1; //aqui ele tira 1 do ID selecionado para por a posição correta no vetor
}

void cadastroestoque(){
	posicaoestoque();
	printf("Insira a quantidade de filmes: ");
	scanf("%d",&listae[x].quantidade);
	setbuf(stdin,NULL);
	printf("Insira a data de entrada do filme: ");
	fgets(listae[x].dataentrada,10,stdin);
	setbuf(stdin,NULL);
	conte++;
	menuestoque();
}

void listarestoque(){ // função que lista os filmes pela ordem do ID cadastrado
    for(x=0;x<cont;x++){//enquanto o x for menor q o contador de filmes ele entende q tem um filme cadastrado e lista
        if(listaf[x].id!=0){//se o ID for 0 quer dizer q ouve um cadastro mais o filme foi excluido
            printf("Id: %d\n",listae[x].idf);
            printf("Titulo: %s",listae[x].titulof);
            printf("Entrada: %s",listae[x].dataentrada);
            setbuf(stdin,NULL);
            printf("Quantidade: %d\n",listae[x].quantidade);
            setbuf(stdin,NULL);
            }else{
                printf("%s\n",listae[x].titulof);//no caso de filme excluido ele solicitara q um novo filme seja inserido pelo atualizar
        }
    }
    menuestoque();
}

void atualizarestoque(){//função para atualizar tem a mesma função do cadastro mas nao aumenta um no contador
if(cont>=0){
	posicaoestoque();
	printf("Insira a quantidade de filmes: ");
	scanf("%d",&listae[x].quantidade);
	setbuf(stdin,NULL);
	printf("Insira a data de entrada do filme: ");
	fgets(listae[x].dataentrada,10,stdin);
	setbuf(stdin,NULL);
    menuestoque();
    }
}

void excluirestoque(){
     printf("\nInsira o ID do filme: ");
        scanf("%s*%d",&c);//scaneamos a string c mas alocamos seu endereço num tipo inteiro com um ponteiro
        setbuf(stdin,NULL);// todo setbuf desse é pra limpar o buffer
        x= strtol(c,NULL,10); // x recebe o valor inserido no tipo char c e entao usa o strtol para converte-lo em long int.
        if(x==0 || x<0 || x<cont){
           printf("ID inadequado!\n");
           menu1();
            }
        x-=1;
    listae[x].idf = x+1;
    strcpy(listae[x].titulof, "Vazio - Atualize o filme");
    strcpy(listae[x].dataentrada, "Vazio");
    setbuf(stdin,NULL);
    menuestoque();
}

void editarestoque(){//função de menu editar
    printf("\nEditar\n");
    printf("\t[1] Atualizar\n");
    printf("\t[2] Excluir\n");
    printf("\t[3] Voltar\n");
    printf("Operacao: ");
    scanf ("%d", &z);

    switch(z){//o swtitch permite escolher um caso de acordo com o input do usuario na variavel z neste caso
    case 1:
        atualizarestoque();
        break;//encerra o caso
    case 2:
        excluirestoque();
        break;
    case 3:
        menuestoque();
        break;
    default://caso o input não seja nenhum desses casos ele mostrara essa mensagem
        printf("\nComando invalido, tente novamente!\n\n");
        setbuf(stdin,NULL);
        editar();
        break;
    }
}

void visualizarestoque(){
    printf("\nInsira o ID do filme: ");
        scanf("%s*%d",&c);//scaneamos a string c mas alocamos seu endereço num tipo inteiro com um ponteiro
        setbuf(stdin,NULL);// todo setbuf desse é pra limpar o buffer
        x= strtol(c,NULL,10); // x recebe o valor inserido no tipo char c e entao usa o strtol para converte-lo em long int.
        if(x==0 || x<0){
           printf("ID inadequado ou em uso!\n");
           menuestoque();
            }
            x-=1;
            printf("Id: %d\n",listae[x].idf);
            printf("Titulo: %s",listae[x].titulof);
            printf("Entrada: %s",listae[x].dataentrada);
            setbuf(stdin,NULL);
            printf("Quantidade: %d\n\n",listae[x].quantidade);
            setbuf(stdin,NULL);
    menuestoque();
}

void consultaestoque(){// visualiza as informações do filme cadastrado apartir de seu titulo
    printf("\nInsira o Titulo do filme: ");
    setbuf(stdin,NULL);
    fgets(busca,50,stdin);
    for(x=0;x<=50;x++){
        if(strcmp(busca, listae[x].titulof) == 0){ //compara a variavel busca inserida com os titulos dos filmes ate achar o igual então mostra as informações
            printf("Id: %d\n",listae[x].idf);
            printf("Titulo: %s",listae[x].titulof);
            printf("Entrada: %s",listae[x].dataentrada);
            printf("Quantidade: %d\n",listae[x].quantidade);
        }
    }
    menuestoque();
}

void posicao(){ // função que tanto diz a posição do vetor quanto seleciona o ID do filme, lembrando que tem q começar por 1 q ele bota o vetor para 0
        printf("\nInsira o ID do filme: ");
        scanf("%s*%d",&c);//scaneamos a string c mas alocamos seu endereço num tipo inteiro com um ponteiro
        setbuf(stdin,NULL);// todo setbuf desse é pra limpar o buffer
        x= strtol(c,NULL,10); // x recebe o valor inserido no tipo char c e entao usa o strtol para converte-lo em long int.
        if(x==0 || x<0 || x<=cont){
           printf("ID inadequado ou em uso!\n");
           menu1();
            }
        x-=1; //aqui ele tira 1 do ID selecionado para por a posição correta no vetor
}
void cadastro(){
	posicao();//chama a função posição
	 // caso o x seja menor q o contador no momento ele vai entender que essa ID esta em uso e nao vai permitir o cadastro
	listaf[x].id = x+1; //devolve o 1 tirado para determinar a posição no vetor para o ID
	listae[x].idf = listaf[x].id;
	printf("Insira o ano do filme: ");
	scanf("%d",&listaf[x].ano);
	setbuf(stdin,NULL);
	printf("Insira o nome do filme: ");
	fgets(listaf[x].titulo,50,stdin);
	strcpy(listae[x].titulof,listaf[x].titulo);
	setbuf(stdin,NULL);
	printf("Insira o genero do filme: ");
	fgets(listaf[x].genero,50,stdin);
	setbuf(stdin,NULL);
	cont++;// coloca mais um no contador de filmes
    menu1();// chama a função menu dos filmes
}
void listar(){ // função que lista os filmes pela ordem do ID cadastrado
    for(x=0;x<cont;x++){//enquanto o x for menor q o contador de filmes ele entende q tem um filme cadastrado e lista
        if(listaf[x].id!=0){//se o ID for 0 quer dizer q ouve um cadastro mais o filme foi excluido
            printf("Id: %d\n",listaf[x].id);
            printf("Ano: %d\n",listaf[x].ano);
            printf("Titulo: %s",listaf[x].titulo);
            printf("Genero: %s\n",listaf[x].genero);//x+1 para mostrar a posição do ID q sempre vai ser 1 a mais q a posição no vetor
            }else{
                printf("%s\n",listaf[x].titulo);//no caso de filme excluido ele solicitara q um novo filme seja inserido pelo atualizar
        }
    }
    menu1();
}

void atualizar(){//função para atualizar tem a mesma função do cadastro mas nao aumenta um no contador
if(cont>=0){
	 printf("\nInsira o ID do filme: ");
        scanf("%s*%d",&c);//scaneamos a string c mas alocamos seu endereço num tipo inteiro com um ponteiro
        setbuf(stdin,NULL);// todo setbuf desse é pra limpar o buffer
        x= strtol(c,NULL,10); // x recebe o valor inserido no tipo char c e entao usa o strtol para converte-lo em long int.
        if(x==0 || x<0 || x<cont){
           printf("ID inadequado ou em uso!\n");
           menu1();
            }
        x-=1;
	listaf[x].id = x+1;
	listae[x].idf = listaf[x].id;
	printf("Insira o ano do filme: ");
	scanf("%d",&listaf[x].ano);
	setbuf(stdin,NULL);
	printf("Insira o nome do filme: ");
	fgets(listaf[x].titulo,50,stdin);
	strcpy(listae[x].titulof,listaf[x].titulo);
	printf("Insira o genero do filme: ");
	fgets(listaf[x].genero,50,stdin);
    menu1();
    }
}

void excluir(){//função exclui um filme da lista
     printf("\nInsira o ID do filme: ");
        scanf("%s*%d",&c);//scaneamos a string c mas alocamos seu endereço num tipo inteiro com um ponteiro
        setbuf(stdin,NULL);// todo setbuf desse é pra limpar o buffer
        x= strtol(c,NULL,10); // x recebe o valor inserido no tipo char c e entao usa o strtol para converte-lo em long int.
        if(x==0 || x<0 || x<cont){
           printf("ID inadequado!\n");
           menu1();
            }
        x-=1;
    listaf[x].id = x+1;
    listaf[x].ano = 0;
    strcpy(listaf[x].titulo, "Vazio - Atualize o filme");
    strcpy(listae[x].titulof,listaf[x].titulo);
    strcpy(listaf[x].genero, "Vazio");
    setbuf(stdin,NULL);
    menu1();
}

void editar(){//função de menu editar
    printf("\nEditar\n");
    printf("\t[1] Atualizar\n");
    printf("\t[2] Excluir\n");
    printf("\t[3] Voltar\n");
    printf("Operacao: ");
    scanf ("%d", &z);

    switch(z){//o swtitch permite escolher um caso de acordo com o input do usuario na variavel z neste caso
    case 1:
        atualizar();
        break;//encerra o caso
    case 2:
        excluir();
        break;
    case 3:
        menu1();
        break;
    default://caso o input não seja nenhum desses casos ele mostrara essa mensagem
        printf("\nComando invalido, tente novamente!\n\n");
        setbuf(stdin,NULL);
        editar();
        break;
    }
}

void visualizar(){// visualiza as informações do filme cadastrado apartir de sua posição de ID
    printf("\nInsira o ID do filme: ");
        scanf("%s*%d",&c);//scaneamos a string c mas alocamos seu endereço num tipo inteiro com um ponteiro
        setbuf(stdin,NULL);// todo setbuf desse é pra limpar o buffer
        x= strtol(c,NULL,10); // x recebe o valor inserido no tipo char c e entao usa o strtol para converte-lo em long int.
        if(x==0 || x<0){
           printf("ID inadequado ou em uso!\n");
           menu1();
            }
        x-=1;
    printf("Id: %d\n",listaf[x].id);
    printf("Ano: %d\n",listaf[x].ano);
    printf("Titulo: %s",listaf[x].titulo);
    printf("Genero: %s",listaf[x].genero);
    menu1();
}

void consulta(){// visualiza as informações do filme cadastrado apartir de seu titulo
    printf("\nInsira o Titulo do filme: ");
    setbuf(stdin,NULL);
    fgets(busca,50,stdin);
    for(x=0;x<=50;x++){
        if(strcmp(busca, listaf[x].titulo) == 0){ //compara a variavel busca inserida com os titulos dos filmes ate achar o igual então mostra as informações
    printf("Id: %d\n",listaf[x].id);
    printf("Ano: %d\n",listaf[x].ano);
    printf("Titulo: %s",listaf[x].titulo);
    printf("Genero: %s",listaf[x].genero);
        }
    }
    menu1();
}

/*
    apartir daqui todas as funções ou boa parte se repetem ,mas ,
    teremos os clientes como foco e nao mais os filmes.
*/
void posicao1(){
    printf("\nInsira o id do Cliente: ");
    scanf("%s*%d",&c);
        setbuf(stdin,NULL);// todo setbuf desse é pra limpar o buffer
        y= strtol(c,NULL,10);
        if(y==0 || y<0 || y<=conty){
           printf("ID inadequado ou em uso!\n");
           posicao1();
            }
    y-=1;
}
void cadastro1(){
	posicao1();
	listac[y].id = y+1;
	printf("Insira o nome do cliente: ");
	fgets(listac[y].nome,50,stdin);
	setbuf(stdin,NULL);
	printf("Insira o CPF do cliente: ");
	fgets(listac[y].cpf,50,stdin);
	setbuf(stdin,NULL);
	printf("Insira o E-mail do cliente: ");
	fgets(listac[y].email,50,stdin);
	setbuf(stdin,NULL);
	conty++;
    menu2();
}
void listar1(){
    for(y=0;y<conty;y++){
        if(listac[y].id!=0){
            printf("ID: %d\n",listac[y].id);
            printf("Nome: %s",listac[y].nome);
            printf("CPF: %s",listac[y].cpf);
            fflush(stdout);
            printf("E-mail: %s\n",listac[y].email);
            fflush(stdout);
            }else{
                printf("%s\n",listac[y].nome);
        }
    }
    menu2();
}

void atualizar1(){
    if(conty>=0){
	printf("\nInsira o ID do cliente: ");
        scanf("%s*%d",&c);//scaneamos a string c mas alocamos seu endereço num tipo inteiro com um ponteiro
        setbuf(stdin,NULL);// todo setbuf desse é pra limpar o buffer
        y= strtol(c,NULL,10); // x recebe o valor inserido no tipo char c e entao usa o strtol para converte-lo em long int.
        if(y==0 || y<0 || conty<y){
           printf("ID inadequado ou nao cadastrado!\n");
           menu2();
            }
        y-=1;
	listac[y].id = y+1;
	printf("Insira o nome do cliente: ");
	fgets(listac[y].nome,50,stdin);
	setbuf(stdin,NULL);
	printf("Insira o CPF do cliente: ");
	fgets(listac[y].cpf,50,stdin);
	setbuf(stdin,NULL);
	printf("Insira o E-mail do cliente: ");
	fgets(listac[y].email,50,stdin);
	setbuf(stdin,NULL);
	menu2();
    }
}

void excluir1(){
    printf("\nInsira o ID do cliente: ");
        scanf("%s*%d",&c);//scaneamos a string c mas alocamos seu endereço num tipo inteiro com um ponteiro
        setbuf(stdin,NULL);// todo setbuf desse é pra limpar o buffer
        y= strtol(c,NULL,10); // x recebe o valor inserido no tipo char c e entao usa o strtol para converte-lo em long int.
        if(y==0 || y<0 || y<conty){
           printf("ID inadequado ou em uso!\n");
           menu2();
            }
        y-=1;
    listac[y].id = y+1;
    strcpy(listac[y].nome, "Insira um novo Cliente");
    strcpy(listac[y].email, "Vazio");
    strcpy(listac[y].cpf, "Vazio");
    setbuf(stdin,NULL);
    menu2();
}

void editar1(){
    printf("\nEditar\n");
    printf("\t[1] Atualizar\n");
    printf("\t[2] Excluir\n");
    printf("\t[3] Voltar\n");
    printf("Operacao: ");
    scanf ("%d", &z);

    switch(z){
    case 1:
        atualizar1();
        break;
    case 2:
        excluir1();
        break;
    case 3:
        menu2();
        break;
    default:
        printf("\nComando invalido, tente novamente!\n\n");
        editar1();
        break;
    }
}

void visualizar1(){
    printf("\nInsira o ID do cliente: ");
        scanf("%s*%d",&c);//scaneamos a string c mas alocamos seu endereço num tipo inteiro com um ponteiro
        setbuf(stdin,NULL);// todo setbuf desse é pra limpar o buffer
        y= strtol(c,NULL,10); // x recebe o valor inserido no tipo char c e entao usa o strtol para converte-lo em long int.
        if(y==0 || y<0){
           printf("ID inadequado ou em uso!\n");
           menu2();
            }
        y-=1;
    printf("ID: %d\n",listac[y].id);
    printf("Nome: %s",listac[y].nome);
    printf("CPF: %s",listac[y].cpf);
    fflush(stdout);
    printf("E-mail: %s",listac[y].email);
    fflush(stdout);
    menu2();
}

void consulta1(){
    printf("\nInsira o nome do cliente: ");
    fflush(stdout);
    setbuf(stdin,NULL);
    fgets(busca,50,stdin);
    for(y=0;y<=50;y++){
        if(strcmp(busca, listac[y].nome) == 0){
    printf("ID: %d\n",listac[y].id);
    printf("Nome: %s",listac[y].nome);
    printf("CPF: %s",listac[y].cpf);
    printf("E-mail: %s",listac[y].email);
        }
    }
    menu2();
}

void menu1(){ // menu de filmes
printf("\nLocadora de Filmes strcpy(Nota,Dez)\n");
printf("Menu de Filmes\n");
    printf("\t[1] Cadastrar\n");
    printf("\t[2] Editar\n");
    printf("\t[3] Listar\n");
    printf("\t[4] Visualizar\n");
    printf("\t[5] Consulta por Titulo\n");
    printf("\t[6] Voltar\n");
    printf("Operacao: ");
    scanf ("%d", &z);
    setbuf(stdin,NULL);
    switch(z){
    case 1:
    	setbuf(stdin,NULL);
        cadastro();
        break;
    case 2:
    	setbuf(stdin,NULL);
        editar();
        break;
    case 3:
    	setbuf(stdin,NULL);
        listar();
        break;
    case 4:
    	setbuf(stdin,NULL);
        visualizar();
        break;
    case 5:
    	setbuf(stdin,NULL);
        consulta();
        break;
    case 6:
    	setbuf(stdin,NULL);
        menu();
        break;
    default:
        printf("\nComando invalido, tente novamente!\n\n");
        setbuf(stdin,NULL);;
        menu1();
        break;
    }
}

void menu2(){
printf("\nLocadora de Filmes strcpy(Nota,Dez)\n");
printf("Menu de Clientes\n");
    printf("\t[1] Cadastrar\n");
    printf("\t[2] Editar\n");
    printf("\t[3] Listar\n");
    printf("\t[4] Visualizar\n");
    printf("\t[5] Consulta por nome\n");
    printf("\t[6] Voltar\n");
    printf("Operacao: ");
    scanf ("%d", &z);
    switch(z){
    case 1:
        cadastro1();
        break;
    case 2:
        editar1();
        break;
    case 3:
        listar1();
        break;
    case 4:
        visualizar1();
        break;
    case 5:
        consulta1();
        break;
    case 6:
        menu();
        break;
    default:
        printf("\nComando invalido, tente novamente!\n\n");
        setbuf(stdin,NULL);
        menu2();
        break;
    }
}

void menuestoque(){ // menu de estoque
printf("\nLocadora de Filmes strcpy(Nota,Dez)\n");
printf("Menu de Estoque\n");
    printf("\t[1] Cadastrar\n");
    printf("\t[2] Editar\n");
    printf("\t[3] Listar\n");
    printf("\t[4] Visualizar\n");
    printf("\t[5] Consulta por Titulo\n");
    printf("\t[6] Voltar\n");
    printf("Operacao: ");
    scanf ("%d", &z);
    setbuf(stdin,NULL);
    switch(z){
    case 1:
    	setbuf(stdin,NULL);
        cadastroestoque();
        break;
    case 2:
    	setbuf(stdin,NULL);
        editarestoque();
        break;
    case 3:
    	setbuf(stdin,NULL);
        listarestoque();
        break;
    case 4:
    	setbuf(stdin,NULL);
        visualizarestoque();
        break;
    case 5:
    	setbuf(stdin,NULL);
        consultaestoque();
        break;
    case 6:
    	setbuf(stdin,NULL);
        menu();
        break;
    default:
        printf("\nComando invalido, tente novamente!\n\n");
        setbuf(stdin,NULL);;
        menu1();
        break;
    }
}

void menu(){// menu principal que chama os submenus de filmes e clientes
    printf("Locadora de Filmes strcpy(Nota,Dez)\n");
    printf("\t[1] Filmes\n");
    printf("\t[2] Clientes\n");
    printf("\t[3] Estoque\n");
    printf("\t[4] Instrucoes\n");
    printf("\t[5] Sair\n");
    printf("Operacao: ");
    scanf ("%d", &z);
    switch(z){
    case 1:
        menu1();
        break;
    case 2:
        menu2();
        break;
    case 3:
        menuestoque();
        break;
    case 4:
        instrucao();
        break;
    case 5:
        system("exit");
        printf("\nFinalizando...\n\n");
        break;
    default:
        printf("\nComando invalido, tente novamente!\n\n");
        setbuf(stdin,NULL);
        menu();
        break;
    }
}


int main(){//função principal
  setlocale(LC_ALL, "Portuguese");//comando q coloca os caracteres do idioma portugues no programa
	menu();
	return 0;
}
