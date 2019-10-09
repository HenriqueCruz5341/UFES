#include <Wire.h>
#define Register_ID 0
#define Register_2D 0x2D
#define Register_X0 0x32
#define Register_X1 0x33
#define Register_Y0 0x34
#define Register_Y1 0x35
#define Register_Z0 0x36
#define Register_Z1 0x37

const int ledPin = 13;
int piscando = 0; 
bool esquerda=false, direita=false, cima=false, 
baixo=false, flag = false, mudou = false;
char caractere;
long tempoInicial = 4000;
String palavra, carac;
String sequencia;
int ADXAddress = 0x53;  // the default 7-bit slave address
int reading = 0;
int val=0;
int X0,X1,X_out;
int Y0,Y1,Y_out;
int Z1,Z0,Z_out;
int e=0, d=0, c=0, b=0;
double Xg,Yg,Zg, YgAnt, XgAnt, ZgAnt;

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
}
 
String IdentificarSequencia(String seq){
  if(seq.equals("E")){
    return "A";
  }else if(seq.equals("D")){
    return "B";
  }else if(seq.equals("CC")){
    return "C";
  }else if(seq.equals("B")){
    return "D";
  }else if(seq.equals("ED")){
    return "E";
  }else if(seq.equals("EC")){
    return "F";
  }else if(seq.equals("ERBR")){
    return "G";
  }else if(seq.equals("ERER")){
    return "H";
  }else if(seq.equals("DRDR")){
    return "I";
  }else if(seq.equals("DRCR")){
    return "J";
  }else if(seq.equals("DRBR")){
    return "K";
  }else if(seq.equals("CRBR")){
    return "L";
  }else if(seq.equals("ERERER")){
    return "M";
  }else if(seq.equals("ERERDR")){
    return "N";
  }else if(seq.equals("ERERCR")){
    return "O";
  }else if(seq.equals("ERERBR")){
    return "P";
  }else if(seq.equals("ERDRCR")){
    return "Q";
  }else if(seq.equals("ERDRBR")){
    return "R";
  }else if(seq.equals("ERDRDR")){
    return "S";
  }else if(seq.equals("ERBRBR")){
    return "T";
  }else if(seq.equals("ERCRCR")){
    return "U";
  }else if(seq.equals("ERCRBR")){
    return "V";
  }else if(seq.equals("DRDRDR")){
    return "W";
  }else if(seq.equals("DRDRBR")){
    return "X";
  }else if(seq.equals("DRDRCR")){
    return "Y";
  }else if(seq.equals("CRCRCR")){
    return "Z";
  }else if(seq.equals("BRBRBR")){
    return "!";
  }else if(seq.equals("CRCRBR")){
    return "?";
  }else if(seq.equals("CRCR")){
    return ".";
  }else if(seq.equals("BRBR")){
    return " ";
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


if(!baixo){
  if(Xg > -0.4 && Xg < 0.4 && Yg > -0.4 && Yg < 0.4 && Zg > -1 && Zg < -0.8 && (cima || baixo || direita || esquerda)){
    cima = false;
    baixo = false;
    direita = false;
    esquerda = false;
    //sequencia += "R";
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
}else{
  mudou = false;
  carac = IdentificarSequencia(sequencia);
  if(flag == false){
    palavra = carac;
    flag = true;
    mudou = true;
  }else if(!sequencia.equals("\0")){
    palavra = palavra + carac;
    mudou = true;
  }
  if(mudou){
    Serial.println(palavra);
  }
  sequencia = "\0";
  baixo = false;
}

  /*Serial.print("X= ");
  Serial.print(Xg);
  Serial.print("       ");
  Serial.print("Y= ");
  Serial.print(Yg);
  Serial.print("       ");
  Serial.print("Z= ");
  Serial.print(Zg);
  Serial.println("  ");*/
}
