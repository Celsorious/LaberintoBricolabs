/////////////// MODIFICAR //////////////////
/* Cambiar los pines en base al esp32*/
/// MOTOR IZQUIERDA ///
const int pinPWMA = 20;
const int pinAIN1= 6;
const int pinAIN2 = 7;
const int pinMotorIzq[3] = {pinPWMA, pinAIN1, pinAIN2};

/// MOTOR DERECHA ///
const int pinPWMB = 21;
const int pinBIN1 = 8;
const int pinBIN2 = 9;
const int pinMotorDer[3] = {pinPWMB, pinBIN1, pinBIN2};

/// VELOCIDAD ///
const int velocidad = 50;

////***********************************///


void haciaDelante(const int pinMotor[3], int velocidad)
{
  analogWrite(pinMotor[0], velocidad);
  digitalWrite(pinMotor[1], HIGH);
  digitalWrite(pinMotor[2], LOW);
}

void haciaAtras(const int pinMotor[3], int velocidad)
{
  analogWrite(pinMotor[0], velocidad);
  digitalWrite(pinMotor[1], LOW);
  digitalWrite(pinMotor[2], HIGH);


}
enum dirGiro{
  horario,
  antihorario
};

void girar(int direccion, int velocidad){
  if (direccion == horario){
    haciaDelante(pinMotorIzq, velocidad);
    haciaAtras(pinMotorDer, velocidad);
  }
  else{
    haciaDelante(pinMotorDer, velocidad);
    haciaAtras(pinMotorIzq, velocidad);
  }
}

enum dirAvance{
  adelante,
  atras
};

void avance(int direccion, int velocidad){
  if (direccion == adelante){
    haciaDelante(pinMotorIzq, velocidad);
    haciaDelante(pinMotorDer, velocidad);
  }
  else{
    haciaAtras(pinMotorDer, velocidad);
    haciaAtras(pinMotorIzq, velocidad);
  }
}


void setup() {
  Serial.begin(115200);
  /// MOTOR IZQUIERDA ///
  pinMode(pinAIN1, OUTPUT);
  pinMode(pinAIN2, OUTPUT);
  pinMode(pinPWMA, OUTPUT);

  /// MOTOR DERECHA ///
  pinMode(pinBIN1, OUTPUT);
  pinMode(pinBIN2, OUTPUT);
  pinMode(pinPWMB, OUTPUT);
}

void loop() {

/////////// TEST MOTOR //////////
  // haciaDelante(pinMotorDer, velocidad)
  //delay(1000);
  haciaDelante(pinMotorIzq, velocidad);
  delay(1000);


/////////// LECTURA SENSORES //////////
/* Descomentar y poner pin al que este conectado el sensor*/
// int valor_sensor = analogRead(pinSensor)
// Serial.prinln(valor_sensor)
// delay(100);

}

