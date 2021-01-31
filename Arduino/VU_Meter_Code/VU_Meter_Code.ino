//Tech Maker
// Subscribe : https://www.youtube.com/channel/UCX-zqect0_tlU6Qwn6GNKcA

int led[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10,11,12,13};
int input, i;
void setup()
{
  for (i = 0; i < 14; i++)
    pinMode(led[i], OUTPUT);
  //Serial.begin(9600);
}
void loop()
{
  input = analogRead(A0);
  //Serial.println(s);
  input = input / 14;      //By changing the denomintor the sensitivity can be changed
  if (input < 14)
  {
    if (input == 0)
    {
      for (i = 0; i < 14; i++)
      {
        digitalWrite(led[i], LOW);
      }
    }
    else
    {
      for (i = 0; i < input; i++)
      {
        digitalWrite(led[i], HIGH);
        delay(4);
      }
      for (i = i; i < 14; i++)
      {
        digitalWrite(led[i], LOW);
      }
    }
  }
}
