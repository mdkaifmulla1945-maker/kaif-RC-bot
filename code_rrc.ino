/ Motor Driver Pins (L298N)
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

// RF Receiver Data Pin
#define RF_DATA 8

char command;

void setup() {

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(RF_DATA, INPUT);

  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {
    command = Serial.read();

    // Forward
    if(command == 'F') {
      forward();
    }

    // Backward
    else if(command == 'B') {
      backward();
    }

    // Left
    else if(command == 'L') {
      left();
    }

    // Right
    else if(command == 'R') {
      right();
    }

    // Stop
    else if(command == 'S') {
      stopCar();
    }
  }
}

// Movement Functions

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}