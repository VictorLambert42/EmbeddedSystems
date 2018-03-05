// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int ask = 3;
int clk = 13;
int dat = 12;

// the setup routine runs once when you press reset:
void setup() {                
  pinMode(ask, INPUT_PULLUP); 
  pinMode(clk, INPUT_PULLUP);
  pinMode(dat, INPUT_PULLUP);
  Serial.begin(9600);
}

void question(){
  pinMode(ask, OUTPUT); // ASK port en output
  digitalWrite(ask, LOW); // set ASK to 0
  delay(1);
  pinMode(ask, INPUT_PULLUP); // Let go ASK
}

void answer(){
  pinMode(clk, OUTPUT);  // CLK port en output
  Serial.println("Receiving message :");
  unsigned char res = 0;
  for(int i=0; i<8; i++){
    digitalWrite(clk, LOW); //set CLK to 0
    delay(200);
    
    digitalWrite(clk, HIGH); //set CLK to 1
    delay(100);
    
    int datState = digitalRead(dat); // get ASK port state
    // Serial.println(datState); // display ASK port state
    if(datState){
     res += 1 << i; 
    }
    delay(100);
  }
  Serial.println((int)res);
  pinMode(clk, INPUT_PULLUP); // Let go CLK
}

// the loop routine runs over and over again forever:
void loop() {
  delay(2000);
  question();
  int askState = digitalRead(ask); // get ASK port state
  // Serial.println(askState); // display ASK port state
  if(askState == 0){
    answer();
  }
}