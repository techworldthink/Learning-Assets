

int level=1;
void setup() {
  Serial.begin(9600);
  Serial2.begin(115200);
  Serial2.println("AT+RST\r\n");
  delay(500);
  Serial2.println("AT+CWMODE=3\r\n");
  delay(500);
  Serial2.println("AT+CWJAP=\"dustbin\",\"2020dustbin\"\r\n");
  delay(500);
  Serial2.println("AT+CIPMUX=1\r\n");
  delay(500);

}

void loop() {
 sendMessage();
}



void sendMessage(){
  Serial2.print("AT+CIPSTART=\"TCP\",\"192.168.43.27\",80\r\n");
  delay(100);
  if (Serial2.find("Error")) {
    Serial.print("j-error");
    return;
  }
  Serial2.println("AT+CIPSEND=171\r\n");
  delay(100);
  if (Serial2.find(">"))
  {
    
    Serial2.print("GET http://192.168.43.27/smartbin/dustbin.php?m_id=tvm123&b_id=1&b_uid=TR4567&level=");
    Serial2.print(level);
    Serial2.print("&st=");
    Serial2.print(level);
    delay(1000);
  }
  else
  {
    Serial.println("ERROR1");
   Serial2.println("AT+CIPCLOSE");
  }
  Serial2.println("AT+CIPCLOSE");
  delay(100);

}
