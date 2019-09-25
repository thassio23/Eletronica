// ESP32 - SISTEMA DE CONTROLE DE MOTORES + ULTRASSOM

// SUBSTITUIR 0 PELO PINO DA ESP32 LIGADO AO MOTOR

// MOTORES DC
const int emb_1 = 0;  // Embaralhador 1
const int emb_2 = 0;  // Embaralhador 2
const int emb_c1 = 0; // Embaralhador Central Sentido Horário
const int emb_c2 = 0; // Embaralhador Central Sentido Anti-Horário
const int dist = 0;   // Distribuidor

// MOTORES DE PASSO
const int elev_1 = 0; // Elevador Pino 1
const int elev_2 = 0; // Elevador Pino 2
const int rot_1 = 0;  // Rotacionador Pino 1
const int rot_2 = 0;  // Rotacionador Pino 2
const int pos_1 = 0;  // Posicionador Pino 1
const int pos_2 = 0;  // Posicionador Pino 2

// ULTRASSOM
const int trig = 0;   // Pino Trigger
const int echo = 0;   // Pino Echo

// FLAGS
int flag = 0;         // Flag de Software (Servidor)
int usom = 0;         // Flag Ultrassom
int players = 0       // Número de Jogadores
int counter = 0       // Contador de Obstáculos (Jogadores)
int pic = 0;          // Envia Mensagem para Raspberry Fotografar a Carta

void setup() {
  
  Serial.begin(9600);

  pinMode(emb_1,  OUTPUT);
  pinMode(emb_2,  OUTPUT);
  pinMode(emb_c1, OUTPUT);
  pinMode(emb_c2, OUTPUT);
  pinMode(dist,   OUTPUT);
  pinMode(elev_1, OUTPUT);
  pinMode(elev_2, OUTPUT);
  pinMode(rot_1,  OUTPUT);
  pinMode(rot_2,  OUTPUT);
  pinMode(pos_1,  OUTPUT);
  pinMode(pos_2,  OUTPUT);

}

void loop() {

  while(flag == 0){} // ESPERAR AUTORIZAÇÃO DO SERVIDOR

  Embaralhador();
  Elevador();

  for(counter = 0; counter < player; counter++){

    Rotacionador();
    Posicionador();
    Distribuidor();    
    
  }

  FRT();
  flag = 0;
  
}

void Embaralhador(){ // 1º ESTÁGIO DE EMBARALHAMENTO

    digitalWrite(emb_1, HIGH);
    digitalWrite(emb_2, HIGH);
    
    delay(3000);

    digitalWrite(emb_1, LOW);
    digitalWrite(emb_2, LOW);

}

void Elevador(){ // CONTROLE DO ELEVADOR E REDISTRIBUIDOR

  /*
    CÓDIGO MOTOR DE PASSOS SUBINDO
  */

  delay(5000);

  digitalWrite(emb_c1, HIGH);
  delay(1500);
  digitalWrite(emb_c1, LOW);

  digitalWrite(emb_c2, HIGH);
  delay(1500);
  digitalWrite(emb_c2, LOW);

  /*
    CÓDIGO MOTOR DE PASSOS DESCENDO
  */  
  
}

void Rotacionador(){

    while(usom == 0){
      /*
      CÓDIGO MOTOR DE PASSOS GIRANDO
      */
    }
  
}

void Posicionador(){  // POSICIONADOR DA CARTA SOBRE A CÂMERA
  
  /*
    CÓDIGO MOTOR DE PASSOS GIRANDO
  */

  delay(500);   // PAUSA PRA FOTO
  pic = 1       // PLACEHOLDER DA FUNÇÃO

  /*
    CÓDIGO MOTOR DE PASSOS GIRANDO
  */
  
}

void Distribuidor(){  // LANÇADOR DE CARTAS

  digitalWrite(dist, HIGH);
  delay(500);
  digitalWrite(dist, LOW);
  
}

void FRT(){ // FLOP, RIVER, TURN

  /* 
    ROTACIONADOR, POSICIONADOR E DISTRIBUIDOR ESPECÍFICOS
  */

}
