#include<WiFi.h>

char server[] = ORG ".messaging.internetofthings.ibmcloud.com";

if (dist < 100) {
  digitalWrite(LED, HIGH);
  Serial.println("no object is near");
  object = "Near";
} else {
  digitalWrite(LED, LOW);
  Serial.println("no object found");
  object = "No";
}

String payload = "{\"distance\":";
payload += dist;
payload += ","
"\"object\":\"";
payload += object;
payload += "\"}";
Serial.print("Sending payload: ");
Serial.println(payload);

if (client.publish(publishtopic, (char * ) payload.c_str())) {
  Serial.println("Publish ok");
} else {
  Serial.println("Publish failed");
}

void mqttconnect() {
  if (!client.connected()) {
    Serial.print("Reconnecting client to ");
    Serial.println(server);
    while (!!!client.connect(clientid, authMethod, token)) {
      Serial.print(".");
      delay(500);
    }
    initManagedDevice();
    Serial.println();
  }
}

void wificonnect()
WiFi.begin("wifi-network", "passing-device", 6); 