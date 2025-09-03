#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "inimigo.h"
#include "combate.h"
#include "utils.h"
#include "musica.h"


void cena3();
void cena2();
void cena1();
void cena4();

bool enemy_encountered1 = false;
bool enemy_encountered2 = false;
bool enemy_encountered3 = false;
bool boss_encountered = false;


Inimigo BOSS = {"Cavaleiro Maldito", 200, 45};

void introducao(Player *jogador) {
    clearScreen();
    printf("==============================\n");
    printf("         A TORRE              \n");
    printf("==============================\n\n");
    printf("# Introdução\n\n");
    printf("\"Frio. Frio demais. Esses infinitos corredores que continuam a se alastrar nas profundezas estão começando a parecer repetitivos demais...\"\n\n");
    printf("Ele estava lá há semanas, talvez meses, procurando algo, algo que começava a se esquecer...\n");
    printf("As memórias começavam a se afogar nos contornos e entornos das escadas que levam cada vez mais fundo aos calabouços da torre.\n\n");
    printf("A Torre de Valac surgiu no meio do reino de Gilmore, com a maldição de um cavaleiro executado por genocídio.\n");
    printf("O rei então decidiu fazer uso dessa sina que manchou o reino, utilizando-a para a prisão de indivíduos considerados Cruéis para Além da Linha da Morte.\n");
    printf("As maquinações que são utilizadas dentro da torre, e seus habitantes sobrenaturais, sempre serviram como punições viáveis para indivíduos malditos.\n");
    printf("Mas não Elric. Elric veio em sã consciência, procurando o que lhe foi tomado, a herança de sua família, seu filho, arrastado para as profundezas da torre.\n\n");
    printf("Ao menos é o que Elric pensa ser a verdade...\n\n");
    printf("\nPressione ENTER para continuar...\n");
    getchar();
    cena1(jogador);
}

void cena1(Player *jogador) {
    clearScreen();
    int op;
    printf("#cena 1\n\n");
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
        cena2(jogador);
    } else {
        printf("\n“Não vale a pena, há salteadores demais por essas bandas, estaria arriscando minha vida por uma falsa esperança” - Pensa Elric, voltando atrás para o caminho de onde veio.\n");
        printf("No fim, Elric fica perpetuamente preso, deixado na Torre que engoliu tantos outros em sua escuridão.\n");
        exit(0);
    }
}

void cena2(Player *jogador) {
    clearScreen();
    int op;
    printf("#cena 2\n\n");
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

    cena3(jogador);
}

void cena3(Player *jogador) {
    clearScreen();
    int op;
    printf("#cena 3\n\n");
    printf("Os quatro corredores diante de si parecem chamá-lo, cada um exalando um som diferente: o tilintar de metal, um choro baixo, uma gargalhada, silêncio absoluto e o eco distante de passos.\n\n");

    if(enemy_encountered1 == false) printf("1 - Seguir o tilintar de metal\n");
    if(enemy_encountered2 == false) printf("2 - Seguir o choro baixo\n");
    if(enemy_encountered3 == false) printf("3 - Seguir a gargalhada\n");

    printf("4 - Seguir o silêncio absoluto\n");
    printf("Opcao: ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            clearScreen();
                if(enemy_encountered1 == false){
                    printf("\nElric segue o corredor, espada em punho. O tilintar se torna ensurdecedor até que ele encontra uma sala circular, onde um guerreiro espectral de armadura partida golpeia o ar, como se ainda lutasse contra inimigos invisíveis. Ao perceber Elric, o espectro berra:\n“Mais um traidor que vem me atormentar!”\n\n\n");
                
                    tocar_musica(MUSICA_COMBATE);
                    combate(jogador, generateEnemy("Guerreiro Espectral"));
                    tocar_musica(MUSICA_AMBIENTACAO);
                
                    printf("O espírito se desfaz em pó negro, mas não antes de murmurar: “Você… foi o culpado… traidor…”\n\n");
                    printf("\n\n O espectro deixa para trás uma caixa com frascos de vidro contendo um liquido vermelho cheio de vida e parte de sua armadura cai ao chão.\n 'isso pode me ajudar' - pensa Elric.");
                
                    jogador -> maxHp += 50;
                    jogador -> hp += 50;
                    jogador -> potionReleased = true;
                    jogador -> potionQuantity += 3;
                    
                    
                    printf("\n\n PRESSIONE ENTER PARA CONTINUAR");
                    getchar();

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
                
                tocar_musica(MUSICA_COMBATE);
                combate(jogador, generateEnemy("Criança Espectral"));
                tocar_musica(MUSICA_AMBIENTACAO);
                
                printf("A criança desaparece em fumaça, gritando: “Assassino!!!”\n\nEla deixou para trás uma lâmpada com luz azul cintilante, aparentemente afastando os espíritos desse lugar.");
                
                jogador -> lightReleased = true;
                
                printf("\n\n PRESSIONE ENTER PARA CONTINUAR");
                getchar();

                enemy_encountered2 = true;

            }else{
                printf("\nElric já enfrentou a Criança Espectral antes. Ele decide seguir em frente, evitando a cela.");
                printf("\n\n PRESSIONE ENTER PARA CONTINUAR");
                getchar();
            }
            break;
        case 3:
            clearScreen();
            if(enemy_encountered3 == false){    
                printf("\nO corredor o leva a uma grande sala onde esqueletos dançam em círculo, rindo e gargalhando de sua própria miséria. Assim que percebem Elric, todos sacam espadas enferrujadas, gritando profanidades e chacotas contra o cavaleiro.\n\n");
                
                tocar_musica(MUSICA_COMBATE);
                combate(jogador, generateEnemy("Esqueletos Dançantes"));
                tocar_musica(MUSICA_AMBIENTACAO);
                
                printf("No chão, os esqueletos se reorganizam, formando uma palavra escrita em ossos: “Genocida.”\n\n");
                printf("\n\n A arma desses esqueletos cae ao chão, uma espada grande e poderosa.... Ela pode ser util");
                
                jogador -> chanceOfHit += 15;
                jogador -> dano += 20;
                
                
                printf("\n\n PRESSIONE ENTER PARA CONTINUAR");
                getchar();

                enemy_encountered3 = true;
        
            } else{
                printf("\nElric já enfrentou os Esqueletos Dançantes antes. Ele decide seguir em frente, evitando a sala.");
                printf("\n\n PRESSIONE ENTER PARA CONTINUAR");
                getchar();
            }
            break;

        case 4:
            clearScreen();
            if(boss_encountered == false){               
                printf("\nNo caminho mais escuro, Elric sente o ar ficar pesado. Ao final do corredor, há um espelho negro. Quando ele olha para o reflexo, não vê a si mesmo, mas um cavaleiro em armadura negra, coberta de sangue. O reflexo ergue a espada e avança para fora do espelho.\n");
                printf("Ele vê O Cavaleiro Maldito, aquele a quem ele caçava, por ter levado seu filho perdido.\n\n");
                
                tocar_musica(MUSICA_CHEFE);
                combate(jogador, &BOSS);
                
                printf("\nAo vencê-lo, Elric descobre a verdade: ele mesmo é o genocida, o Cavaleiro Maldito.\n");
                printf("Fim da jornada.\n");
                
                boss_encountered = true;
            }
        default:
            printf("Opcao invalida.\n");
            cena3(jogador);
    }

    if(boss_encountered == false){
        cena4(jogador);
    }
}

void cena4(Player* jogador){
    clearScreen();

    printf("Ao fim do confronto, Elric se vê diante de seu reflexo no espelho negro. Não é por esse caminho ao qual ele deve seguir, então ele se afasta lentamente e retorna a sala anterior.\n");
    printf("Ele percebe que a verdadeira batalha ainda está por vir.\n");
    printf("\n\nPressione enter para continuar ....");
    
    getchar();
    
    cena3(jogador);
}

int main() {
    clearScreen();
    inicializar_audio();
    

    while(boss_encountered == false){ 

        tocar_musica(MUSICA_AMBIENTACAO);
        Player jogador;
        jogador = inicializarJogador();

        printf("==============================\n");
        printf("        A TORRE DE VALAC      \n");
        printf("==============================\n");
        printf("        RPG - C GAME          \n");
        printf("==============================\n\n");
        printf("Bem-vindo, aventureiro!\n");
        printf("Escolha uma opção para começar sua jornada:\n\n");
        printf("1 - Iniciar Nova Jornada\n");
        printf("2 - Sair da Torre\n");
        printf("------------------------------\n");
        printf("Opcao: ");
    
        int opcao;
    
        scanf("%d", &opcao);
    
        getchar();  // Limpar o buffer

        if (opcao == 1) {
            introducao(&jogador);
        } else {
            printf("Saindo do jogo...\n");
            break;
        }
    }
    parar_musica();
    return 0;
}
