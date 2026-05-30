int sensorDigital = 7;
int sensorAnalogico = A2;

int valorDigital = 0;
int valorAnalogico = 0;

void setup() {
  pinMode(sensorDigital, INPUT);
  Serial.begin(9600);
}

void loop() {
  // faz a leitura do valor digital do sensor
  valorDigital = digitalRead(sensorDigital);
  // imprime o valor digital obtido pelo sensor
  Serial.print("Valor digital: ");
  Serial.println(valorDigital);

  // imprime uma mensagem com base no valor digital obtido (HIGH ou LOW)
  if (valorDigital == HIGH) {
    Serial.println("Presença de gases detectada!");
  } else {
    Serial.println("Nenhuma presença de gases detectada.");
  }

  // faz a leitura do valor analógico do sensor
  valorAnalogico = analogRead(sensorAnalogico);

  // imprime o valor analógido obtido pelo sensor
  Serial.print("Valor analógico: ");
  Serial.println(valorAnalogico);
  if (valorAnalogico < 100) {
    Serial.println("Ar muito limpo");
  } else if (valorAnalogico < 300) {
    Serial.println("Ar limpo/normal");
  } else if (valorAnalogico < 600) {
    Serial.println("Ar moderado, existe aumento de CO₂ ou álcool/fumaça leve");
  } else if (valorAnalogico < 800) {
    Serial.println("Ar poluído, presença de gases nocivos perceptíveis como fumaça ou solventes");
  } else { // 800-1023
    Serial.println("Muito poluído / saturado, alta concentração de CO₂");
  }

  Serial.println("");
  delay(3000);
}