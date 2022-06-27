bool State[] = {false, false, false};
const byte Lights[] = {6, 7, 8}, Seconds[] = {70, 12, 5, 3};
byte c = 0, i = 0;
unsigned long long Millis = 0;

void setup()
{
    for (i = 0; i < 3; i++)
        pinMode(Lights[i], OUTPUT);
}

void loop()
{
    for (i = 0; i < 3; i++)
        State[i] = false;
    if (c < 2)
        State[c] = true;
    else if (c == 3)
        State[2] = true;
    else if (millis() % 1000 > 500)
        State[1] = true;
    for (i = 0; i < 3; i++)
        digitalWrite(Lights[i], State[i]);
    if (millis() - Millis > Seconds[c] * 1000)
    {
        c++;
        if (c > 3)
            c = 0;
        Millis = millis();
    }
}