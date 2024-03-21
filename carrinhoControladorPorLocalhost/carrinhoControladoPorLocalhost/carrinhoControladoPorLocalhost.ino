#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "RCT";
const char *password = "98197313";

int motorEsquerda1 = 13;
int motorEsquerda2 = 12;
int motorDireita1 = 27;
int motorDireita2 = 26;

WebServer server(80);

void setup() {
  pinMode(motorEsquerda1, OUTPUT);
  pinMode(motorEsquerda2, OUTPUT);
  pinMode(motorDireita1, OUTPUT);
  pinMode(motorDireita2, OUTPUT);

  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("");

  Serial.println("Conectado à rede WiFi");

  server.on("/", HTTP_GET, handleRoot);
  server.on("/frente", HTTP_GET, handleFrente);
  server.on("/re", HTTP_GET, handleRe);
  server.on("/direita", HTTP_GET, handleDireita);
  server.on("/esquerda", HTTP_GET, handleEsquerda);
  server.on("/parar", HTTP_GET, handleParar);

  server.begin();
  Serial.println("Servidor iniciado");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  server.send(600, "text/html", "Controle do carrinho Mario <br><br><br><br><a href='/frente'>ir frente</a><br><br><br><br><a href='/re'>ir re</a><br><br><br><br><a href='/direita'>ir direita</a><br><br><br><br><a href='/esquerda'>ir esqurda</a><br><br><br><br><a href='/parar'>parar</a>");
}

void handleFrente() {
  server.send(600, "text/html", "indo frente <br><br><br><br><a href='/frente'>ir frente</a><br><br><br><br><a href='/re'>ir re</a><br><br><br><br><a href='/direita'>ir direita</a><br><br><br><br><a href='/esquerda'>ir esqurda</a><br><br><br><br><a href='/parar'>parar</a>");

  digitalWrite(motorEsquerda1, HIGH);
  digitalWrite(motorEsquerda2, LOW);

  digitalWrite(motorDireita1, LOW);
  digitalWrite(motorDireita2, HIGH);
}

void handleRe() {
  server.send(600, "text/html", "indo ré <br><br><br><br><a href='/frente'>ir frente</a><br><br><br><br><a href='/re'>ir re</a><br><br><br><br><a href='/direita'>ir direita</a><br><br><br><br><a href='/esquerda'>ir esqurda</a><br><br><br><br><a href='/parar'>parar</a>");

  digitalWrite(motorEsquerda1, LOW);
  digitalWrite(motorEsquerda2, HIGH);

  digitalWrite(motorDireita1, HIGH);
  digitalWrite(motorDireita2, LOW);
}

void handleDireita() {
  server.send(600, "text/html", "indo direita <br><br><br><br><a href='/frente'>ir frente</a><br><br><br><br><a href='/re'>ir re</a><br><br><br><br><a href='/direita'>ir direita</a><br><br><br><br><a href='/esquerda'>ir esqurda</a><br><br><br><br><a href='/parar'>parar</a>");
  digitalWrite(motorEsquerda1, LOW);
  digitalWrite(motorEsquerda2, HIGH);

  digitalWrite(motorDireita1, LOW);
  digitalWrite(motorDireita2, HIGH);
}

void handleEsquerda() {
  server.send(600, "text/html", "indo esquerda <br><br><br><br><a href='/frente'>ir frente</a><br><br><br><br><a href='/re'>ir re</a><br><br><br><br><a href='/direita'>ir direita</a><br><br><br><br><a href='/esquerda'>ir esqurda</a><br><br><br><br><a href='/parar'>parar</a>");
  digitalWrite(motorEsquerda1, HIGH);
  digitalWrite(motorEsquerda2, LOW);

  digitalWrite(motorDireita1, HIGH);
  digitalWrite(motorDireita2, LOW);
}

void handleParar() {
  server.send(600, "text/html", "parando <br><br><br><br><a href='/frente'>ir frente</a><br><br><br><br><a href='/re'>ir re</a><br><br><br><br><a href='/direita'>ir direita</a><br><br><br><br><a href='/esquerda'>ir esqurda</a><br><br><br><br><a href='/parar'>parar</a>");
  digitalWrite(motorEsquerda1, LOW);
  digitalWrite(motorEsquerda2, LOW);

  digitalWrite(motorDireita1, LOW);
  digitalWrite(motorDireita2, LOW);
}
