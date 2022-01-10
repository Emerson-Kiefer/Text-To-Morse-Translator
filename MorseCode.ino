int timeUnit = 60;
int frequency = 800;
int audioOutputPin = 12;
int lightOutputPin = 10;
int lightOutputPin2 = 11;
String input = "Hello World";

void setup() {
  // put your setup code here, to run once:
  pinMode(audioOutputPin, OUTPUT);
  pinMode(lightOutputPin, OUTPUT);
  pinMode(lightOutputPin2, OUTPUT);
}
//

void dit(){ //1 unit
  tone(audioOutputPin, frequency, timeUnit);
  digitalWrite(lightOutputPin, HIGH);
  delay(timeUnit);
  digitalWrite(lightOutputPin, LOW);
  delay(timeUnit);
}


void dah(){
  tone(audioOutputPin, frequency, timeUnit*3);
  digitalWrite(lightOutputPin, HIGH);
  delay(timeUnit*3);
  digitalWrite(lightOutputPin, LOW);
  delay(timeUnit*1);
}

void convertLetter(char character){
  String charString = String(character);
  charString.toLowerCase();
  character = charString.charAt(0);
  switch(character){
    case 'a': 
      dit();
      dah();
      break;
    case 'b':
      dah();
      dit();
      dit();
      dit();
      break;
    case 'c':
      dah();
      dit();
      dah();
      dit();
      break;
    case 'd':
      dah();
      dit();
      dit();
      break;
    case 'e':
      dit();
      break;
    case 'f':
      dit();
      dit();
      dah();
      dit();
      break;
    case 'g':
      dah();
      dah();
      dit();
      break;
    case 'h':
      dit();
      dit();
      dit();
      dit();
      break;
    case 'i':
      dit();
      dit();
      break;
    case 'j':
      dit();
      dah();
      dah();
      dah();
      break;
    case 'k':
      dah();
      dit();
      dah();
      break;
    case 'l':
      dit();
      dah();
      dit();
      dit();
      break;
    case 'm':
      dah();
      dah();
      break;
    case 'n':
      dah();
      dit();
      break;
    case 'o':
      dah();
      dah();
      dah();
      break;
    case 'p':
      dit();
      dah();
      dah();
      dit();
      break;
    case 'q':
      dah();
      dah();
      dit();
      dah();
      break;
    case 'r':
      dit();
      dah();
      dit();
      break;
    case 's':
      dit();
      dit();
      dit();
      break;
    case 't':
      dah();
      break;
    case 'u':
      dit();
      dit();
      dah();
      break;
    case 'v':
      dit();
      dit();
      dit();
      dah();
      break;
    case 'w':
      dit();
      dah();
      dah();
      break;
    case 'x':
      dah();
      dit();
      dit();
      dah();
      break;
    case 'y':
      dah();
      dit();
      dah();
      dah();
      break;
    case 'z':
      dah();
      dah();
      dit();
      dit();
      break;
  }
  delay(timeUnit*2);
}

void convertInput(String myInput){
  for(int i = 0; i < myInput.length(); i++){
    if(myInput.charAt(i) == ' '){
      delay(timeUnit*4);
    } else {
      convertLetter(myInput.charAt(i));
    }
  }
  delay(timeUnit*4);
}

void startTransmission(){ //CT prosign
  dah();
  dit();
  dah();
  dit();
  dah();
  delay(timeUnit*7);
}

void ditLight(){
  digitalWrite(lightOutputPin, HIGH);
  digitalWrite(lightOutputPin2, HIGH);
  delay(timeUnit*2);
  digitalWrite(lightOutputPin, LOW);
  digitalWrite(lightOutputPin2, LOW);
  delay(timeUnit*2);
}

void dahLight(){
  digitalWrite(lightOutputPin, HIGH);
  digitalWrite(lightOutputPin2, HIGH);
  delay(timeUnit*6);
  digitalWrite(lightOutputPin, LOW);
  digitalWrite(lightOutputPin2, LOW);
  delay(timeUnit*2);
}

void endTransmission(){
  delay(timeUnit*14);
  ditLight();
  dahLight();
  ditLight();
  dahLight();
  ditLight();
}

void loop() {
  startTransmission(); //start of message
  convertInput(input);
  endTransmission();
  exit(0);
}
