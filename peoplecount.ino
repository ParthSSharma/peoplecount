int count = 0;

int ledin = 13;
int led1 = 12;
int led2 = 11;
int led3 = 10;
int mpin1 = 9;
int mpin2 = 8;

int read1 = 0;
int read2 = 0;

int flag1 = 0;
int flag2 = 0;

int th1 = 400;
int th2 = 400;

int timed = 500;

void setup(){
  Serial.begin(9600);
  pinMode(ledin, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(mpin1, OUTPUT);
  pinMode(mpin2, OUTPUT);
}

void loop(){
  read1 = analogRead(A0);
  read2 = analogRead(A1);
  if((flag2 == 0) && (flag1 == 0)){
    if(read1 < th1){
      flag1 = 1;
    }
    if(read2 < th2){
      flag2 = 1;
    }
  }
  if((flag2 == 0) && (flag1 == 1)){
    if(read2 < th2){
      if(flag1 == 1){
        count = count + 1;
      }
      flag1 = 2;
    }
  }
  if((flag2 == 1) && (flag1 == 0)){
    if(read1 < th1){
      if(flag2 == 1){
        count = count - 1;
      }
    flag2 = 2;
    }
  }
  if((flag2 == 2) || (flag1 == 2)){
    delay(timed);
    flag1 = 0;
    flag2 = 0;
  }
  Serial.println(read1);
  Serial.println(read2);
  if(count == 0){
    digitalWrite(ledin, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(mpin1, LOW);
    digitalWrite(mpin2, LOW);
  }
  if(count > 0){
    digitalWrite(ledin, HIGH);
    digitalWrite(mpin1, HIGH);
    digitalWrite(mpin2, LOW);
    if((count > 0) && (count <= 3)){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    }
    else if((count > 3) && (count <= 6)){
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
    }
    else if((count > 6) && (count < 10)){
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
    }
    else if(count == 10){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
    }
  }
}
