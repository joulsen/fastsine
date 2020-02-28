void graph(float f1(float), float f2(float), float f3(float)) {
  float ii;
  for (int i = 0; i < 100; i++) {
    ii = (float) i / 100 * HALF_PI;
    Serial.print(f1(ii), 10);
    Serial.print(',');
    Serial.print(f2(ii), 10);
    Serial.print(',');
    Serial.print(f3(ii), 10);
    Serial.println();
  }
}
