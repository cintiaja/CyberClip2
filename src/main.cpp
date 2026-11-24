#include <Arduino.h>   // En PlatformIO siempre va esta línea
#include <TFT_eSPI.h>  // Librería de la pantalla

TFT_eSPI tft = TFT_eSPI();  // Creamos el objeto "pantalla"
TFT_eSprite linea = TFT_eSprite(&tft);//la parte o hojita en donde dibujamos la frase
String frase = "SAQUENME DE AQUI POR FAVOR, YA NO AGUANTO :3";

int x = 240;//desde donde empieza la frase
int anchoText = 0;


void setup() {
 Serial.begin(115200);  // Para ver mensajes en el Monitor Serial

  pinMode(4, OUTPUT);     // El pin 4 es la luz de fondo
  digitalWrite(4, HIGH);  // HIGH = luz encendida

  tft.init();                 // Prepara la pantalla
  tft.setRotation(1);         // Pantalla acostada
  tft.fillScreen(TFT_BLACK);  // Fondo negro
  delay(1000);//ESPERA UN 1 SEGUNDO
  tft.fillScreen(TFT_BLACK);

  //linea.createSprite(100, 0);//ancho y largo de la hojita
  //linea.setTextSize(1);//tamaño de la letra
  //linea.setTextColor(TFT_BLUE, TFT_BLACK);//lrtras azules y fondo negro

  //tft.setTextColor(TFT_GREEN, TFT_BLACK);  // Letras verdes
 // tft.setTextSize(2);
 // tft.setCursor(10, 50);
  //tft.println("Proyecto nuevo!");
  if (linea.createSprite(240, 40) == NULL){
    Serial.println("Error: no se puede crear");
  }

  linea.setTextSize(2);

  tft.setTextSize(4);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  anchoText = linea.textWidth(frase);//se mide que tan larga es la frase

}

void loop() {
  linea.fillSprite(TFT_BLACK);//BORRA LO HOJITA
  linea.setCursor(x, 10);//pone el cursor en la pocison x
  linea.print(frase);//imprime la frase recuerda que esta parte es para las animaciones
  linea.pushSprite(0, 47);//sube o pega la hojita la pnatalla 47 = mas o menos al centro

  x = x-2;//mueve la frase 2 pasos a la izquierda


  if (x < -anchoText){
    x = 240;//si se acaba vuuelve a obtener el valor inicial
    //en otras palabras vuelve a iniciar
  }

  delay(20);//espera un poco (mas numero = mas lento)


}