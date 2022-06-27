bool State[3][4] = {{false, false, false, false}, {false, false, false, false}, {true, true, true, true}};
const byte Semaphore[] = {2, 3, 4, 5}, Lights[] = {6, 7, 8}, Red[] = {9, 10, 11, 12}, Seconds[] = {70, 12, 5, 3};
byte c = 0, f = 0, g = 0, k = 0, u = 0;
unsigned long long Millis = 0;

void setup()
{
    for (f = 0; f < 4; f++)
    {
        pinMode(Semaphore[f], OUTPUT);
        digitalWrite(Semaphore[f], State[0][f]);
        pinMode(Red[f], OUTPUT);
        digitalWrite(Red[f], State[2][f]);
        if (f < 3)
        {
            pinMode(Lights[f], OUTPUT);
            digitalWrite(Lights[f], State[1][f]);
        }
    }
}
void loop()
{
    for (f = 0; f < 4; f++)
    {
        State[0][f] = true;
        State[1][f] = false;
        State[2][f] = true;
    }
    State[0][u] = false;
    State[2][u] = false;
    if ((c - k) > 2)
        State[2][u] = true;
    else
    {
        State[1][2] = true;
        if ((c - k) == 0)
            State[1][0] = true;
        else if ((c - k) == 1 || (((c - k) == 2) && (millis() % 1000 > 500)))
            State[1][1] = true;
    }
    for (f = 0; f < 4; f++)
    {
        digitalWrite(Semaphore[f], State[0][f]);
        digitalWrite(Red[f], State[2][f]);
        if (f < 3)
            digitalWrite(Lights[f], State[1][f]);
    }
    if (millis() - Millis > Seconds[g] * 1000)
    {
        g++;
        c++;
        if (g > 3)
            g = 0;
        if (c > 15)
            c = 0;
        if (c % 4 == 0)
        {
            k = c;
            u = k / 4;
        }
        Millis = millis();
    }
}
