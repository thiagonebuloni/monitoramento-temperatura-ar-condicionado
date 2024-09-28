// Pino de leitura do sensor
#define ADCPIN 0

// Variavel para temperatura
float temperatura = 0;

void setup()
{
// Utiiza referencia interna de 1,1V
analogReference(INTERNAL);

// Inicializa serial
Serial.begin(9600);
}

void loop() {
  // Faz leitura do sensor pela função
  temperatura = analogAvg(ADCPIN);
  
  // Faz conversão de Volts para Celcius
  temperatura = temperatura * 1100 / (1024 * 10);
  
  // Imprime temperatura no Serial
  Serial.println(temperatura);

  delay(1000);
}

// Função para leitura em amostragem
  int analogAvg (int sensorPin) {
  int total = 0;
  int amostras = 20;
  for (int n = 0; n < amostras; n++) {
   total+= analogRead (sensorPin);
   delay(10);
  }
  return total / amostras;
}

