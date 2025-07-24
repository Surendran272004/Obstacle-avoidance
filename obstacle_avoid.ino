const int trigPin = 9;
const int echoPin = 10;

float duration, distance;

void setup() {
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorvalue=analogRead(A0);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
  if(distance<=7){
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    }
   else if(distance>=7){
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
   }
   
   delay(100);
}
