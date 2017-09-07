#define POWER 6
#define RED 9
#define GREEN 10
#define BLUE 11
#define DIODA 13
String command = "free";


void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(DIODA, OUTPUT);
  pinMode(POWER, OUTPUT);
  analogWrite(RED, 255);
}

void loop() {
  if(!command.equals("free")){
    if(command.equals("police")){
      police();
    }
    else if(command.equals("warning")){
      warning();
    }
    else if(command.equals("red")){
      analogWrite(RED, 255);
      command="free";
    }
    else if(command.equals("blue")){
      analogWrite(BLUE, 255);
      command="free";
    }
    else if(command.equals("green")){
      analogWrite(GREEN, 255);
      command="free";
    }
    else if(command.equals("yellow")){
      analogWrite(RED, 255);
      analogWrite(GREEN, 255);
      command="free";
    }
    else if(command.equals("orange")){
      analogWrite(RED, 255);
      analogWrite(GREEN, 128);
      command="free";
    }
    else if(command.equals("azure")){
      analogWrite(GREEN, 255);
      analogWrite(BLUE, 255);
      command="free";
    }
    else if(command.equals("pink")){
      analogWrite(RED, 255);
      analogWrite(BLUE, 255);
      command="free";
    }
  }
}

void serialEvent() {
  resetColors();
  digitalWrite(DIODA, HIGH);
  command = Serial.readString();
  digitalWrite(DIODA, LOW);
}

void resetColors(){
  analogWrite(RED, 0);
  analogWrite(BLUE, 0);
  analogWrite(GREEN, 0);
}

  void police(){
    analogWrite(RED, 255);
    delay(50);
    analogWrite(RED, 0);
    delay(50);
    analogWrite(RED, 255);
    delay(50);
    analogWrite(RED, 0);
    delay(300);
    analogWrite(BLUE, 255);
    delay(50);
    analogWrite(BLUE, 0);
    delay(50);
    analogWrite(BLUE, 255);
    delay(50);
    analogWrite(BLUE, 0);
    delay(300);
  }

  void warning(){
    analogWrite(RED, 255);
    analogWrite(GREEN, 255);
    delay(50);
    analogWrite(RED, 0);
    analogWrite(GREEN, 0);
    delay(50);
    analogWrite(RED, 255);
    analogWrite(GREEN, 255);
    delay(50);
    analogWrite(RED, 0);
    analogWrite(GREEN, 0);
    delay(300);
  }

