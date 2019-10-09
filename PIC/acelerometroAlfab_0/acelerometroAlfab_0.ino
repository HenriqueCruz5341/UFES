#include <Wire.h>
#define Register_ID 0
#define Register_2D 0x2D
#define Register_X0 0x32
#define Register_X1 0x33
#define Register_Y0 0x34
#define Register_Y1 0x35
#define Register_Z0 0x36
#define Register_Z1 0x37

bool esquerda=false, direita=false, cima=false, baixo=false, flag = false, mudou = false;
char caractere;
String palavra, carac;
String sequencia;
int ADXAddress = 0x53;  // the default 7-bit slave address
int reading = 0;
int val=0;
int X0,X1,X_out;
int Y0,Y1,Y_out;
int Z1,Z0,Z_out;
int ultPosApag;
double Xg,Yg,Zg;

void setup() {
  Wire.begin();                
  Serial.begin(9600);    
  delay(100);
  // enable to measute g data
  Wire.beginTransmission(ADXAddress);
  Wire.write(Register_2D);
  Wire.write(8);                //measuring enable
  Wire.endTransmission();     // stop transmitting
  palavra = "\0";
  ultPosApag = -1;
}
 
String IdentificarSequencia(String seq){
  if(seq.equals("E")){
    return "A";
  }else if(seq.equals("D")){
    return "B";
  }else if(seq.equals("EC")){
    return "C";
  }else if(seq.equals("EE")){
    return "D";
  }else if(seq.equals("ED")){
    return "E";
  }else if(seq.equals("DD")){
    return "F";
  }else if(seq.equals("DC")){
    return "G";
  }else if(seq.equals("DE")){
    return "H";
  }else if(seq.equals("CC")){
    return "I";
  }else if(seq.equals("CE")){
    return "J";
  }else if(seq.equals("CD")){
    return "K";
  }else if(seq.equals("EED")){
    return "L";
  }else if(seq.equals("EEC")){
    return "M";
  }else if(seq.equals("EDC")){
    return "N";
  }else if(seq.equals("EDE")){
    return "O";
  }else if(seq.equals("ECE")){
    return "P";
  }else if(seq.equals("ECD")){
    return "Q";
  }else if(seq.equals("ECC")){
    return "R";
  }else if(seq.equals("DDE")){
    return "S";
  }else if(seq.equals("DDC")){
    return "T";
  }else if(seq.equals("DCC")){
    return "U";
  }else if(seq.equals("DCE")){
    return "V";
  }else if(seq.equals("DCD")){
    return "W";
  }else if(seq.equals("DEE")){
    return "X";
  }else if(seq.equals("DEC")){
    return "Y";
  }else if(seq.equals("DED")){
    return "Z";
  }else if(seq.equals("EEE")){
    return "!";
  }else if(seq.equals("DDD")){
    return "?";
  }else if(seq.equals("CCC")){
    return ".";
  }else if(seq.equals("EDD")){
    return " ";
  }else if(seq.equals("C")){
    return "BACK";
  }
  return "\0";
}

double leituraEmY(){
  Wire.beginTransmission(ADXAddress); // transmit to device
  Wire.write(Register_Y0);
  Wire.write(Register_Y1);
  Wire.endTransmission();
  Wire.requestFrom(ADXAddress,2); 
  if(Wire.available()<=2)   
  {
    Y0 = Wire.read();
    Y1 = Wire.read(); 
    Y1=Y1<<8;
    Y_out=Y0+Y1;
  }

  return Y_out;
}

double leituraEmX(){
  //--------------X
  Wire.beginTransmission(ADXAddress); // transmit to device
  Wire.write(Register_X0);
  Wire.write(Register_X1);
  Wire.endTransmission();
  Wire.requestFrom(ADXAddress,2);
  if(Wire.available()<=2)
  {
    X0 = Wire.read();
    X1 = Wire.read(); 
    X1=X1<<8;
    X_out=X0+X1;   
  }

  return X_out;
}

double leituraEmZ(){
  //------------------Z
  Wire.beginTransmission(ADXAddress); // transmit to device
  Wire.write(Register_Z0);
  Wire.write(Register_Z1);
  Wire.endTransmission();
  Wire.requestFrom(ADXAddress,2); 
  if(Wire.available()<=2)   
  {
    Z0 = Wire.read();
    Z1 = Wire.read(); 
    Z1=Z1<<8;
    Z_out=Z0+Z1;
  }

  return Z_out;
}


void loop()
{
  int i;
  Xg=leituraEmX()/256.0;
  Yg=leituraEmY()/256.0;
  Zg=leituraEmZ()/256.0;

  if(!baixo){ // vai guardando em sequencia os movimentos lidos enquanto nao eh feito um movimento para baixo
    if(Xg > -0.4 && Xg < 0.4 && Yg > -0.4 && Yg < 0.4 && Zg > -1 && Zg < -0.8 && (cima || baixo || direita || esquerda)){
     cima = false;
     baixo = false;
     direita = false;
     esquerda = false;
    } 
   
   else if(Xg >= 0.5 && !cima){
     Serial.print("CIMA");
     Serial.println(" ");
     cima = true;
     sequencia += "C";
   }
   else if(Xg <= -0.5 && !baixo){
     baixo = true;
   }
   else if(Yg >= 0.5 && !esquerda){
     Serial.print("ESQUERDA");
     Serial.println(" ");
     esquerda = true;
     sequencia += "E";
   }
   else if(Yg <= -0.5 && !direita){
     Serial.print("DIREITA");
     Serial.println(" ");
     direita = true;
     sequencia += "D";
   }
  }else{ //quando um movimento eh feito para baixo a proxima vez q o programa executar, entrara aqui
   mudou = false; //para controlar que a palavra so sera impressa na tela caso tenha sofrido alguma alteracao
   carac = IdentificarSequencia(sequencia); //recebe o caractere correspondente a sequencia de movimentos feitos
   if(palavra.equals("\0") && !carac.equals("BACK") && !sequencia.equals("\0")){ //entrara nesse if somente quando a palavra estiver vazia
     palavra = carac;
     mudou = true;
   }else if(carac.equals("BACK")){ // entrara nesse if caso o comando tenha sido para apagar uma letra digitada, a parte de apagar na verdade vai sobreescrever a letra com um '_', e quando outra letra for digitada no lugar, sera colocada no lugar de '_'
     for(i = 0; palavra.charAt(i) != '\0' && palavra.charAt(i) != '_'; i++); // para achar a ultima posicao com uma letra valida a ser apagada
     ultPosApag = i-1;
     if(i > 0){ // se nao for a ultima ultima letra restante na palavra, a ultima letra da direita para esquerda sera substituida por '_'
       palavra.setCharAt(i-1, '_');
     }
     if(palavra.charAt(0) == '_'){  // se for a ultima letra restante na palavra, palavra ira se tornar uma string vazia
       palavra = "\0";
       ultPosApag = -1; // para mostrar que nao existe uma ultima posicao apagada
     }
     mudou = true; // como houve alteracao na string palavra, ela sera impressa
   }else if(!sequencia.equals("\0")){ //caso palavra ja possua caracteres e a sequencia nao tenha sido vazia
     if(ultPosApag >= 0){ // para ver se teve uma ultima letra apagada
       palavra.setCharAt(ultPosApag, carac.charAt(0)); // a primeira posicao da esquerda para direita que possuir um '_' recebera uma letra no lugar
       if(ultPosApag < palavra.length()-1){ // se a ultima posicao apagada nao for igual a ultima posicao valida da string palavra
         ultPosApag++;  // avanca para a proxima posicao que possui um '_'
       }else{ // se a ultima posicao apagada for igual a ultima posicao valida da string palavra, ultima posicao apagada nao existira mais
         ultPosApag = -1;
       }
     }else{ //caso nao tenha uma ultima letra apagada, carac sera apenas concatenada no final de palavra
       palavra = palavra + carac;
     }
     mudou = true; // como houve alteracao na string palavra, ela sera impressa
   }
   if(mudou){ //caso palavra tenha sofrido alguma alteracao, ela sera impressa
     Serial.println(palavra);
   }
   sequencia = "\0";
   baixo = false; //baixo recebe falso para que sequencia possa novamente comecar a armazenar a sequencia de movimentos feitos
  }
}
