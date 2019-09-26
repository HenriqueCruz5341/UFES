#define semVerde 8
#define semAmare 9
#define semVerme 10
#define pedVerde 5
#define pedVerme 6
#define botao 7                                 

int greenTime = 4000, crossTime = 8000;
boolean apertou = false, apertado = false;

void carroPassa(){
  digitalWrite(semVerde, HIGH);
  digitalWrite(semVerme, LOW);
  digitalWrite(semAmare, LOW);
}

void paraCarro(){
  digitalWrite(semVerde, LOW);
  digitalWrite(semAmare, HIGH);
  delay(1500);
  digitalWrite(semAmare, LOW);
  digitalWrite(semVerme, HIGH);
}

void pedestrePassa(){
  digitalWrite(pedVerme, LOW);
  digitalWrite(pedVerde, HIGH);
  delay(5000);
  for(int i = 0; i < 3; i++){
    digitalWrite(pedVerde, LOW);
    delay(500);
    digitalWrite(pedVerde, HIGH);
    delay(500);
  }
}

void paraPedestre(){
  digitalWrite(pedVerde, LOW);
  digitalWrite(pedVerme, HIGH);
}

void setup(){
  pinMode(semVerde, OUTPUT);
  pinMode(semAmare, OUTPUT);
  pinMode(semVerme, OUTPUT);
  pinMode(pedVerde, OUTPUT);
  pinMode(pedVerme, OUTPUT);
  digitalWrite(semVerde, HIGH);
  digitalWrite(semAmare, LOW);
  digitalWrite(semVerme, LOW);
  digitalWrite(pedVerde, LOW);
  digitalWrite(pedVerme, LOW);
}

void loop(){
  if(digitalRead(botao) == true && apertou == false){
    apertou = true;
    apertado = true;
    delay(greenTime);
    if(apertado){
      paraCarro();
      pedestrePassa();
      paraPedestre();
      carroPassa();
    }
    apertado = false;
  }
  apertou = false;
  carroPassa();
  paraPedestre();
}
