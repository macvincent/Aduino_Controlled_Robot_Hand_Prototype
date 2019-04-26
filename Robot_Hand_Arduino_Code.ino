/*****************************************
 * Name:  Jacquline Mckithen
          Emmanuel Anim-Addo
          Nwokeocha Ndukwo
          MacVincent Agha-Oko
 * Dr. Karina Liles
 * CSCI225
 * April 26, 2019
 * The aim of this code is to move the hands of a prototype robot hand.
 ****************************************/
 
  //Here we declare and initialise the input pins for the L923D IC which controlls the logic for the direction
  const int motor1a = 2;
  const int motor1b = 3;
  const int motor2a = 4;
  const int motor2b = 5;
  const int motor3a = 6;
  const int motor3b = 7;
  const int motor4a = 8;
  const int motor4b = 9;
  const int motor5a = 11;
  const int motor5b = 12;
  
 //Here we initialise our analog IC enable pin which controlls the speed
  long enable = 10;

  void setup() {
    // setup codes runs only once:
    //We also set our arduino pins as either output or input pins
    pinMode(motor1a, OUTPUT);
    pinMode(motor1b, OUTPUT);
    pinMode(motor2a, OUTPUT);
    pinMode(motor2b, OUTPUT);
    pinMode(motor3a, OUTPUT);
    pinMode(motor3b, OUTPUT);
    pinMode(motor4a, OUTPUT);
    pinMode(motor4b, OUTPUT);
    pinMode(motor5a, OUTPUT);
    pinMode(motor5b, OUTPUT);
    pinMode(enable, OUTPUT);
    Serial.begin(9600);
    //We set the speed of the motors here
    analogWrite(enable, 225);
  }
  
  void moveOnce(int in1, int in2){
    /* This function lets the fingers move just once
     * We receive the logic pins as parameters
     * And control the motor with it
     */
    //The finger moves in one direction
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delay(1500);
    //The finger moves in one direction
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(1500);
  }

  
  
  void move(int arr[5][2]){
    /* This function lets all the fingers move at the same time
     *  We get all the logic pins as an array list
     *  And through them effect our changes
     */
     
    //The fingers moves in one direction
    for(int i = 0; i < 5; i++){
      int in1 = arr[i][0];
      int in2 = arr[i][1];
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);   
    }
    delay(1500);
    
    //The fingerss move in the opposite direction
    for(int i = 0; i < 5; i++){
      int in1 = arr[i][0];
      int in2 = arr[i][1];
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);   
    }
    delay(1500);

    //We stop moving the fingers
    for(int i = 0; i < 5; i++){
      int in1 = arr[i][0];
      int in2 = arr[i][1];
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);   
    }
  
  }
  
  void loop() {
    //Here we call our functions in a loop
    moveOnce(motor1a, motor1b);
    moveOnce(motor2a, motor2b);
    moveOnce(motor3a, motor3b);
    moveOnce(motor4a, motor4b);
    moveOnce(motor5a, motor5b);
    
    int motorIns[5][2] = {{motor1a,motor1b}, {motor2a,motor2b}, {motor3a,motor3b}, {motor4a,motor4b}, {motor5a,motor5b}};
    move(motorIns);
  }
  
  
