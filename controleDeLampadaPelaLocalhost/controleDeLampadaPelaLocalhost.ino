#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "RCT";
const char *password = "98197313";

WebServer server(80); 

const int relayPin = 2; 

void setup() {
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado ao WiFi");

  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);

  server.on("/", HTTP_GET, handleRoot);
  server.on("/ligar", HTTP_GET, handleLigar);
  server.on("/desligar", HTTP_GET, handleDesligar);

  server.begin();
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  server.send(200, "text/html", "<h1>controle de lâmpada</h1><p><a href='/ligar'>Ligar</a></p><p><a href='/desligar'>Desligar</a></p>");
}

//trocar para em vez de trocar de pág o resultado ser exibido na mesma pág e adicionar mais um controle 
void handleLigar() {
  digitalWrite(relayPin, LOW);
 server.send(200, "text/plain", "Relé ligado");
}

void handleDesligar() {
  digitalWrite(relayPin, HIGH);
  server.send(200, "text/plain", "Relé desligado");
}
