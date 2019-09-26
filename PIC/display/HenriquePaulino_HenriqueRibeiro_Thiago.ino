 /* 
 __________________________________________
| Curso Arduino 5 - Display de 7 Segmentos |
|                 OnDuino           |
|     http://www.onduino.blogspot.com.br   |
|__________________________________________|

Esse código foi baseado no seguinte site:
http://www.instructables.com/id/Seven-Segment-Display-Tutorial/?ALLSTEPS

 As ligações foram feitas para um display de anodo comum
 no caso de um display de catodo comum basta inverter os 
 valores de 1 para 0 e de 0 para 1 

                Pinos do Dislpay:{ A,B,C,D,E,F,G }
                Pinos do Arduino:{ 2,3,4,5,6,7,8 } */
byte display7segmentosNum[10][7] = {{ 1,1,1,1,1,1,0 },  // = 0
                                 { 0,1,1,0,0,0,0 },  // = 1
                                 { 1,1,0,1,1,0,1 },  // = 2
                                 { 1,1,1,1,0,0,1 },  // = 3
                                 { 0,1,1,0,0,1,1 },  // = 4
                                 { 1,0,1,1,0,1,1 },  // = 5
                                 { 1,0,1,1,1,1,1 },  // = 6
                                 { 1,1,1,0,0,0,0 },  // = 7
                                 { 1,1,1,1,1,1,1 },  // = 8
                                 { 1,1,1,0,0,1,1 }   // = 9
                               };

byte display7segmentosAlf[6][7] = {{ 1,1,1,0,1,1,1 },  // = A
                                 { 0,0,1,1,1,1,1 },  // = B
                                 { 1,0,0,1,1,1,0 },  // = C
                                 { 0,1,1,1,1,0,1 },  // = D
                                 { 1,0,0,1,1,1,1 },  // = E
                                 { 1,0,0,0,1,1,1 },  // = F
                               };

int contador = 0;

void setup() {                
  pinMode(2, OUTPUT);   
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
}

void segmentos7(byte digito) {
  byte pino = 2;
  for (byte segmento = 0; segmento < 7; segmento++) {
    digitalWrite(pino, display7segmentosAlf[digito][segmento]);
    pino++;
  }
}

void loop() {
  int estadoAtual;
  int estadoAnterior = 0;
  /*if(estadoAtual){
    estadoAnterior = 0;
  }else{
    estadoAnterior = 1;
  }*/
  /*for (byte num = 0; num < 6; num++) {
   delay(1000);
   segmentos7(num); 
  }
  delay(5000);*/
  estadoAtual= digitalRead(9);
  if(estadoAtual == HIGH && estadoAnterior == LOW){
        estadoAnterior = digitalRead(9);
    if(contador != 5){
      contador++;
    }else{
      contador = 0; 
    }
  }
    estadoAnterior = digitalRead(9);
  
  segmentos7(contador);
}
