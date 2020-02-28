void setup() {
  Serial.begin(115200);
  graph(fastsine1, fastsine2, fastsine3);
  delay(1000);
  Serial.println();
  sweepTest(fastsine1, fastsine2, fastsine3, 0);
}

void loop() {
}
