// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(5, INPUT_PULLUP);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  int prox = digitalRead(5);

  if (prox == 0){
    digitalWrite(6, 1);
    digitalWrite(7, 0);
  }
  else {
    digitalWrite(7, 1);
    digitalWrite(6, 0);
  }
}
