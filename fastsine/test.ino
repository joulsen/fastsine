void sweepTest(float* f1(float), float* f2(float), float* f3(float), float delta) {
  volatile float x;

  unsigned int timer1 = micros();
  for (int i = 0; i < 100; i++) {
    x = *f1((float) i/100 * HALF_PI + delta);
  }
  timer1 = micros() - timer1;

  unsigned int timer2 = micros();
  for (int i = 0; i < 100; i++) {
    x = *f2((float) i/100 * HALF_PI + delta);
  }
  timer2 = micros() - timer2;

  unsigned int timer3 = micros();
  for (int i = 0; i < 100; i++) {
    x = *f3((float) i/100 * HALF_PI + delta);
  }
  timer3 = micros() - timer3;

  Serial.println(timer1);
  Serial.println(timer2);
  Serial.println(timer3);
}
