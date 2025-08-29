#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "inimigo.h"
#include "combate.h"
#include "utils.h"
#include "musica.h"


void escolha3();
void escolha2();
void escolha1();

bool enemy_encountered1 = false;
bool enemy_encountered2 = false;
bool enemy_encountered3 = false;
bool boss_encountered = false;


Inimigo BOSS = {"Cavaleiro Maldito", 100, 20};

void introducao(Player *jogador) {
    clearScreen();
    printf("A Torre\n\n");
    printf("#introdução\n\n");
    printf("“Frio. Frio demais. Esses infinitos corredores que continuam a se alastrar nas profundezas estão começando a parecer repetitivos demais…” - Pensou Elric.\n\n");
    printf("Ele estava lá há semanas, talvez meses, procurando algo, algo que começava a se esquecer… As memórias começavam a se afogar nos contornos e entornos das escadas que levam cada vez mais fundo aos calabouços da torre.\n\n");
    printf("A Torre de Valac surgiu no meio do reino de Gilmore, com a maldição de um cavaleiro executado por genocídio. O rei então decidiu fazer uso dessa sina que manchou o reino, utilizando-a para a prisão de indivíduos considerados “Cruéis para Além da Linha da Morte”. As maquinações que são utilizadas dentro da torre, e seus habitantes sobrenaturais, sempre serviram como punições viáveis para indivíduos malditos. Mas não Elric. Elric veio em sã consciência, procurando o que lhe foi tomado, a herança de sua família, seu filho, arrastado para as profundezas da torre.\n\n");
    printf("Ao menos é o que Elric pensa ser a verdade…\n\n");
    printf("\n\n\npressione enter para continuar....");
    getchar();
    escolha1(jogador);
}

void escolha1(Player *jogador) {
    clearScreen();
    int op;
    printf("#escolha 1\n\n");
    printf("“Luz…” - Você afirma - “Estou vendo luz? Nessas profundezas?”\n");
    printf("A luz de uma pequena centelha de fogo é avistada um pouco abaixo de onde o aventureiro se localiza… Talvez um abrigo? Ou os restos de um outro prisioneiro? Você pode descer, ou voltar para a escuridão atrás de ti, arriscando mais um dia dentro desse labirinto.\n\n");

    printf("1 - Descer para a luz\n");
    printf("2 - Subir para as trevas e arriscar outro dia\n");
    printf("Opcao: ");
    scanf("%d", &op);

    if (op == 1) {
        printf("\nVocê desce mais as escadas, direcionando-se para a luz que avistou anteriormente.\n");
        printf("Hesitante, cada passo em sua direção lhe faz temer pelo que está à frente.\n");
        printf("Ao chegar no fundo, você olha ao redor, e não acredita no que está observando. Uma tocha, pregada numa parede, ilumina a sala conectada à outros 4 corredores. No meio, uma mesa com a nota “Coma e beba.” escrito com letras formais e bem caligrafadas. Não há dúvidas, alguém o esperava.\n\n");
        escolha2(jogador);
    } else {
        printf("\n“Não vale a pena, há salteadores demais por essas bandas, estaria arriscando minha vida por uma falsa esperança” - Pensa Elric, voltando atrás para o caminho de onde veio.\n");
        printf("No fim, Elric fica perpetuamente preso, deixado na Torre que engoliu tantos outros em sua escuridão.\n");
        exit(0);
    }
}

void escolha2(Player *jogador) {
    clearScreen();
    int op;
    printf("#escolha 2\n\n");
    printf("Na mesa a sua frente, você avista uma garrafa do que parece ser vinho, um pão cortado, uma faca e queijo, este diferente do que tens, por não estar mofado. Copos e pratos bem postos decoram a mesa, como se esperassem por mais de uma pessoa, e como podes ver, o pão, o queijo e a bebida não estão inteiros, alguém já passou por lá. A sua barriga estremece.\n\n");

    printf("1 - Comer do banquete\n");
    printf("2 - Recusar a comida\n");
    printf("Opcao: ");
    scanf("%d", &op);

    if (op == 1) {
        printf("\nElric decide então provar da comida posta à sua frente, saciando sua fome e guardando parte do banquete como provisões para o resto da jornada.\n");
        printf("Após se saciar, Elric sente suas forças retornarem, mas também um frio estranho subir-lhe pela espinha. “Magia...” — pensa Elric, cerrando os dentes. — “Essa torre não brinca comigo sem motivo.”\n\n");
    } else {
        printf("\nVocê decide não se arriscar, recusando o banquete e aceitando a dor em sua barriga. Mas a escolha não vem sem consequências. A dor começa a ser muito forte, fazendo com que sofras (2) de dano.\n");
        jogador->hp -= 2;
    }

    escolha3(jogador);
}

void escolha3(Player *jogador) {
    clearScreen();
    
    int op;
    printf("#escolha 3\n\n");
    printf("Os quatro corredores diante de si parecem chamá-lo, cada um exalando um som diferente: o tilintar de metal, um choro baixo, uma gargalhada, silêncio absoluto e o eco distante de passos.\n\n");

    printf("1 - Seguir o tilintar de metal\n");
    printf("2 - Seguir o choro baixo\n");
    printf("3 - Seguir a gargalhada\n");
    printf("4 - Seguir o silêncio absoluto\n");
    printf("Opcao: ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            clearScreen();
                if(enemy_encountered1 == false){
                    printf("\nElric segue o corredor, espada em punho. O tilintar se torna ensurdecedor até que ele encontra uma sala circular, onde um guerreiro espectral de armadura partida golpeia o ar, como se ainda lutasse contra inimigos invisíveis. Ao perceber Elric, o espectro berra:\n“Mais um traidor que vem me atormentar!”\n\n\n");
                    parar_musica();
                    tocar_musica_combate();
                    combate(jogador, generateEnemy("Guerreiro Espectral"));
                    printf("O espírito se desfaz em pó negro, mas não antes de murmurar: “Você… foi o culpado… traidor…”\n\n");
                    enemy_encountered1 = true;
                }else{
                    printf("\nElric já enfrentou o Guerreiro Espectral antes. Ele decide seguir em frente, evitando a sala circular.");
                    printf("\n\n PRESSIONE ENTER PARA CONTINUAR");
                    getchar();
                }
            break;
        case 2:
            clearScreen();
            if(enemy_encountered2 == false){
                printf("\nSeguindo o lamento, Elric encontra uma cela aberta. Dentro dela, uma criança espectral chora abraçada a um cadáver acorrentado. Quando Elric se aproxima, a criança ergue a cabeça e mostra olhos vazios.\n“Você… devolva meu pai…”\n\n");
                parar_musica();
                tocar_musica_combate();
                combate(jogador, generateEnemy("Criança Espectral"));
                printf("A criança desaparece em fumaça, gritando: “Assassino!!!”\n\n");
                enemy_encountered2 = true;
                break;
            }else{
                printf("\nElric já enfrentou a Criança Espectral antes. Ele decide seguir em frente, evitando a cela.");
                printf("\n\n PRESSIONE ENTER PARA CONTINUAR");
                getchar();
            }
        case 3:
            clearScreen();
            if(enemy_encountered3 == false){    
                printf("\nO corredor o leva a uma grande sala onde esqueletos dançam em círculo, rindo e gargalhando de sua própria miséria. Assim que percebem Elric, todos sacam espadas enferrujadas, gritando profanidades e chacotas contra o cavaleiro.\n\n");
                parar_musica();
                tocar_musica_combate();
                combate(jogador, generateEnemy("Esqueletos Dançantes"));
                printf("No chão, os esqueletos se reorganizam, formando uma palavra escrita em ossos: “Genocida.”\n\n");
                enemy_encountered3 = true;
                break;
            } else{
                printf("\nElric já enfrentou os Esqueletos Dançantes antes. Ele decide seguir em frente, evitando a sala.");
                printf("\n\n PRESSIONE ENTER PARA CONTINUAR");
                getchar();
            }

        case 4:
            clearScreen();
            if(boss_encountered == false){               
                printf("\nNo caminho mais escuro, Elric sente o ar ficar pesado. Ao final do corredor, há um espelho negro. Quando ele olha para o reflexo, não vê a si mesmo, mas um cavaleiro em armadura negra, coberta de sangue. O reflexo ergue a espada e avança para fora do espelho.\n");
                printf("Ele vê O Cavaleiro Maldito, aquele a quem ele caçava, por ter levado seu filho perdido.\n\n");
                parar_musica();
                tocar_musica_chefe();
                combate(jogador, &BOSS);
                printf("\nAo vencê-lo, Elric descobre a verdade: ele mesmo é o genocida, o Cavaleiro Maldito.\n");
                printf("Fim da jornada.\n");
                exit(0);
                break;
            }
        default:
            printf("Opcao invalida.\n");
            escolha3(jogador);
    }
}

int main() {
    clearScreen();
    inicializar_audio();
    Player *jogador = malloc(sizeof(Player));
    jogador->hp = 100;
    jogador->dano = 20;
    jogador->inDefence1 = false;
    jogador->inDefence2 = false;

    while(true){ 

        tocar_musica_ambientacao();
    
        printf("MENU\n");
        printf("1 - Iniciar Jogo\n");
        printf("2 - Sair\n");
        printf("Opcao: ");
    
        int opcao;
    
        scanf("%d", &opcao);
    
        getchar();  // Limpar o buffer

        if (opcao == 1) {
            introducao(jogador);
        } else {
            printf("Saindo do jogo...\n");
            free(jogador);
            break;
        }
    }
    return 0;
}
