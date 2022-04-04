int speakerPin = 8;
int numTones = 6;
int tones[] = {261, 294, 330, 349, 370,  415};
                    // mid C C# D D# E F F# G G# A
void setup()
{
}

void loop()
{
    for (int i = 0; i < numTones; i++)
    {
        tone(speakerPin, tones[i]);
        delay(500);
    }
    noTone(speakerPin);
    delay(1000);
}
