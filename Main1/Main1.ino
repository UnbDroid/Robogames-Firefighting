/*esqueleto de codigo para implementar*/

/*---------------------------------------------------------------------------*/
/* Defines dos valores do busy*/

#define WALK_STAIRS 1                // macro que manda robo andar a distancia da escada bem no começo ou bem no final do codigo

#define FORWARD 2                    // macro que manda o robo seguir adiante na casa

#define TURN_LEFT 3                  // macro que manda o robo girar 90 graus para a esquerda
#define TURN_RIGHT 4                 // macro que manda o robo girar 90 graus para a direita
#define TURN_AROUND 5                // macro que manda o robo girar 180 graus

#define CHECK_ROOM 6                 // macro que manda o robo checar o quarto em que ele está
#define CANDLE 7                     // macro que manda o robo apagar a vela

#define BACK_HOME 8                  // macro que manda o robo voltar pro inicio, de acordo com a posicao dele no mapa

#define WALK_DISTANCE 9              // macro que manda o robo andar a distancia especifica (somente sera chamada em um momento do codigo, antes de entrar no ultimo quarto, portanto se refere a apenas uma distancia especifica)

#define WALK_TO_WALL 10              // macro que manda o robo andar ate chegar perto da parede (necessário após checar a sala, para ficar relativamente no centro do corredor)

int busy = WALK_STAIRS;
/*---------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------*/
/* Includes, defines e variáveis do giroscópio*/

#include <Wire.h>

#define CTRL_REG1 0x20
#define CTRL_REG2 0x21
#define CTRL_REG3 0x22
#define CTRL_REG4 0x23
#define CTRL_REG5 0x24
#define REFERENCE 0X25

int AngSpeedZ, gyroTime, gyroAddress = 105;
unsigned long tGyroNow=0, tGyroAnt;
long int yaw=0;
float gyroFilterB=0, gyroFilterA = 0;
/*-----------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------*/
/* Variáveis de localização*/

int vaosCount=0;                           // número de vãos que o robô encontrou enquanto percorre a arena (depois alguem traduz a variável pro inglês, pq n me lembro agora a tradução kkk)

/*----------------------------------------------------------------------------------------------------*/

/*
  --------------------------------------inicizalizacao---------------------------
  funcao de inicializar os sensores/ponte H/ motores/ encoders
*/
/*______________________________________________FUNCOES DE ALTO NIVEL !!_________________________________________________*/
/*
 funcao que recebe duas coordenadas (X,Y) atuais e retorna o local do robo numa matriz de 9 (qual casa)
 |20|21|22|
 |10|11|12|
 |00|01|02|
 ///////////////////// NOTE QUE AS AREAS NAO VAO SER QUADRADAS !! VOA DEPENDER DO TAMANHO DA ARENA E DOS QUARTOS
 ///////////o schaivini ficou com essa funcao !
*/
/*_______________________________________________________________________________________________________________________*/  
/*
  funcao que seria chamada quando o robo estiver na porta de cada quarto que procura a vela ! -------- se achar, sera chamada a funcao de baixo - apagar a vela 
*/
/*_______________________________________________________________________________________________________________________*/
/*
  se a funcao de cima achar a vela essa funcao sera chamada e ela realizaria o processo de apagar a vela
*/
/*_______________________________________________________________________________________________________________________*/
/*
  sair do quarto e voltar para a orientacao certa para continur a trajetoria do robo caso a funcao de procurar a vela nao achar a vela
*/
/*_______________________________________________________________________________________________________________________*/
/*
  realiza a volta pra base sem depender do local que o robo atualmente esta ! usando a matriz da primeira funcao
*/
/*_______________________________________________________________________________________________________________________*/
/*
  comparacao entre as coordenadas X e Y atuais e a quantiadade de vao passados
*/
/*_______________________________________________________________________________________________________________________*/
/*
 caso a funcao de cima retorna que o valor das coordenadas eh inconveniente com a quantidade de vaos passados
 esta funcao faria o robo ir ao checkpoint para recomecar a parte na qual  ele se perdeu
*/
/*_______________________________________________________________________________________________________________________*/
/*
 ---------------------------------------FUNCAO CORACAO DO CODIGO !--------------------------
 ----DIRECIONARIA O ANDAMENTO DO CODIGO PARA AS OUTRAS FUNCOES USANDO VARIAVEL GLOBAR DO ESTADO ATUAL DO ROBO (o nome dessa variavel provavelmente sera busy)! 
 --------------- RECOMENDO DEIXAR A IMPLEMENTACAO DESSA FUNCAO PARA O ABDU/MINIBAU
*/

void Heart(){
  switch(busy){
      case WALK_STAIRS:
        //chama função para atravessar a escada
        //se a função de voltar pra casa ainda não tiver sido chamada
        break;
        
      case FORWARD:
        //OnFwd(MOTOR_RIGHT, 90);
        //OnFwd(MOTOR_LEFT, 90);
        break;

      case TURN_LEFT:
        //Turn(-90);            //função Turn(int degree) já existe, só falta passar para cá
        break;

      case TURN_RIGHT:
        //Turn(90);
        break;

      case TURN_AROUND:
        //Turn(180);
        break;

      case CHECK_ROOM:
        //Função para checar a sala
        break;

      case CANDLE:
        //Função para ir para perto da vela e apagá-la
        break;

      case BACK_HOME:
        //Função que calcula a rota para voltar para o inicio, e manda o robô pra lá
        break;

      case WALK_DISTANCE:
        //Função para o robô percorrer uma distância específica
        break;

      case WALK_TO_WALL:
        //Função para o robô chegar a uma distância específica da parede na frente
        break;
  }
}

/*______________________________________-----------------------------------______________________________________________*/
/*--------------------------------------___________________________________----------------------------------------------*/

/*______________________________________FUNCOES DE BAIXO NIVEL !!!!!!!!!!!!______________________________________________*/
/*
  leitura de US instantanea + identificacao de vao somando no contador global a quantidade de vao passados para cada (esq/ dir)
*/
/*_______________________________________________________________________________________________________________________*/
/*
  funcao que recebe a distancia como parametro e anda essa distancia pedida. (poderia ser arrompida pela leitura do vao no US)
*/
/*_______________________________________________________________________________________________________________________*/
/*
  funcoes de girar (podem ser varias para cada um angulo e direcao, ou uma que recebe angulo e direcao como parametro e faz para qualquer angulo "funcao inteligente")
  ---para escolher qual o tipo dessa funcao, recomendo o segundo pq poderia ser reutilizado e seria bem mais inteligente 
  MAS*** as vezes esse tipo de funcao eh mais arriscado do que implementar funcao para cada caso! entao se n der muito certo o segundo tipo, pode ser o primeiro
*/
/*_______________________________________________________________________________________________________________________*/
/*
 filtros para os sensores que necessitam
*/

void setup()
{
  /*
      setttar as parada todim
  -----------------------------------------------------------
    chamar a funcao de inicializar os bagul
    ;
    e anda certa distancia ate o vao atravessando a escada     --> Minibau: fiz de um jeito que essa parte fica inclusa no coração do codigo, não precisa ser chamada aqui
    depois de andar, somar o valor da distancia entre o ponto de inicio ate o final da escada (projetado no x ja)
  */
}

void loop()
{
}
