/*
  Teensy Piano

  A piano set to be used as a USB Keyboard for playing music.

  created 10/22/2019
  by Olin Gallet

*/

int button4 = 0;
int button5 = 0;
int button6 = 0;
int button7 = 0;
int button8 = 0;
int button9 = 0;
int button10 = 0;
int button11 = 0;
int hAxis   = 0;
int vAxis   = 0;
int lButton = 0;
int rButton = 0;

void setup() {
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  Keyboard.begin();
  Mouse.begin();
}
void setOutputPins(int pin12, int pin13, int pin14, int pin15){
  digitalWrite(15, pin15);
  digitalWrite(14, pin14);
  digitalWrite(13, pin13);
  digitalWrite(12, pin12);
}

void readInputPins(){
  button11 = digitalRead(11);
  button10 = digitalRead(10);
  button9  = digitalRead(9);
  button8  = digitalRead(8);
  button7  = digitalRead(7);
  button6  = digitalRead(6);
  button5  = digitalRead(5);
  button4  = digitalRead(4);
}

void loop() {
  setOutputPins(HIGH, HIGH, HIGH, LOW);
  readInputPins();
  if (button11 == LOW){
    Keyboard.press('z');
    Keyboard.releaseAll();
  } else if (button10 == LOW){
    Keyboard.press('b');
    Keyboard.releaseAll();
  } else if (button9 == LOW){
    Keyboard.press('.');
    Keyboard.releaseAll();
  } else if (button8 == LOW){
    Keyboard.press('d');
    Keyboard.releaseAll();
  } else if (button7 == LOW){
    Keyboard.press('k');
    Keyboard.releaseAll();
  } else if (button6 == LOW){
    Keyboard.press('q');
    Keyboard.releaseAll();
  } else if (button5 == LOW){
    Keyboard.press('t');
    Keyboard.releaseAll();
  } else if (button4 == LOW){
    Keyboard.press('o');
    Keyboard.releaseAll();
  }

  setOutputPins(HIGH, HIGH, LOW, HIGH);
  readInputPins();
  if (button11 == LOW){
    Keyboard.press('x');
    Keyboard.releaseAll();
  } else if (button10 == LOW){
    Keyboard.press('n');
    Keyboard.releaseAll();
  } else if (button9 == LOW){
    Keyboard.press('/');
    Keyboard.releaseAll();
  } else if (button8 == LOW){
    Keyboard.press('f');
    Keyboard.releaseAll();
  } else if (button7 == LOW){
    Keyboard.press('l');
    Keyboard.releaseAll();
  } else if (button6 == LOW){
    Keyboard.press('w');
    Keyboard.releaseAll();
  } else if (button5 == LOW){
    Keyboard.press('y');
    Keyboard.releaseAll();
  } else if (button4 == LOW){
    Keyboard.press('p');
    Keyboard.releaseAll();
  }

  setOutputPins(HIGH, LOW, HIGH, HIGH);
  readInputPins();
  if (button11 == LOW){
    Keyboard.press('c');
    Keyboard.releaseAll();
  } else if (button10 == LOW){
    Keyboard.press('m');
    Keyboard.releaseAll();
  } else if (button9 == LOW){
    Keyboard.press('a');
    Keyboard.releaseAll();
  } else if (button8 == LOW){
    Keyboard.press('h');
    Keyboard.releaseAll();
  } else if (button7 == LOW){
    Keyboard.press(';');
    Keyboard.releaseAll();
  } else if (button6 == LOW){
    Keyboard.press('e');
    Keyboard.releaseAll();
  } else if (button5 == LOW){
    Keyboard.press('u');
    Keyboard.releaseAll();
  } else if (button4 == LOW){
    Keyboard.press('[');
    Keyboard.releaseAll();
  }

  setOutputPins(LOW, HIGH, HIGH, HIGH);
  readInputPins();
  if (button11 == LOW){
    Keyboard.press('v');
    Keyboard.releaseAll();
  } else if (button10 == LOW){
    Keyboard.press(',');
    Keyboard.releaseAll();
  } else if (button9 == LOW){
    Keyboard.press('s');
    Keyboard.releaseAll();
  } else if (button8 == LOW){
    Keyboard.press('j');
    Keyboard.releaseAll();
  } else if (button7 == LOW){
    Keyboard.press('\'');
    Keyboard.releaseAll();
  } else if (button6 == LOW){
    Keyboard.press('r');
    Keyboard.releaseAll();
  } else if (button5 == LOW){
    Keyboard.press('i');
    Keyboard.releaseAll();
  } else if (button4 == LOW){
    Keyboard.press(']');
    Keyboard.releaseAll();
  }

  lButton = digitalRead(18);
  rButton = digitalRead(19);
  if (lButton == LOW){
    Mouse.click(MOUSE_LEFT);
  } else if (rButton == LOW){
    Mouse.click(MOUSE_RIGHT);
  }

  hAxis = analogRead(16);
  vAxis = analogRead(17);
  if (hAxis < 350){
    Mouse.move(25, 0, 0);
  } else if (hAxis < 450){
    Mouse.move(5, 0, 0);
  }else if (hAxis > 750){
    Mouse.move(-25, 0, 0);
  } else if (hAxis > 650){
    Mouse.move(-5, 0, 0);
  }

  if (vAxis < 350){
    Mouse.move(0, -25, 0);
  } else if (vAxis < 450){
    Mouse.move(0, -5, 0);
  } else if (vAxis > 750){
    Mouse.move(0, 25, 0);
  } else if (vAxis > 650){
    Mouse.move(0, 5, 0);
  }
  
  delay(100);
}
