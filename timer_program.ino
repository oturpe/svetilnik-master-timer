// Not working (?)
//    d8
#define WATER_LIGHTS 12
#define PARFANJE 2
#define DRESS 4
#define FOG 7
#define FOG_LIGHT 0

#define SEQUENCE_LENGTH 20
// { seconds, pin, state }
int sequence[SEQUENCE_LENGTH][3] = {
    {  0 * 60 +  0, FOG_LIGHT,    HIGH },
    {  3 * 60 + 44, WATER_LIGHTS, HIGH },
    {  4 * 60 + 57, DRESS,        HIGH },
    {  6 * 60 + 45, WATER_LIGHTS, LOW  },
    {  6 * 60 + 51, DRESS,        LOW  },
    { 12 * 60 + 46, PARFANJE,     HIGH },
    { 13 * 60 + 58, PARFANJE,     LOW  },
    { 15 * 60 + 30, WATER_LIGHTS, HIGH },
    { 16 * 60 +  4, PARFANJE,     HIGH },
    { 17 * 60 + 48, WATER_LIGHTS, LOW  },
    { 17 * 60 + 48, PARFANJE,     LOW  },
    { 27 * 60 + 42, FOG,          HIGH },
    { 31 * 60 + 35, FOG,          LOW  },
    { 31 * 60 + 35, FOG_LIGHT,    LOW  },
    { 31 * 60 + 46, DRESS,        HIGH },
    { 33 * 60 + 05, PARFANJE,     HIGH },
    { 33 * 60 + 34, WATER_LIGHTS, HIGH },
    { 34 * 60 + 53, WATER_LIGHTS, LOW  },
    { 34 * 60 + 53, PARFANJE,     LOW  },
    { 36 * 60 + 30, DRESS,        LOW  }
};

void setup(){
    pinMode(WATER_LIGHTS, OUTPUT);
    pinMode(PARFANJE, OUTPUT);
    pinMode(DRESS, OUTPUT);
    pinMode(FOG, OUTPUT);
    pinMode(FOG_LIGHT, OUTPUT);
    
    digitalWrite(WATER_LIGHTS, LOW);
    digitalWrite(PARFANJE, LOW);
    digitalWrite(DRESS, LOW);
    digitalWrite(FOG, LOW);
    digitalWrite(FOG_LIGHT, LOW);
}

////////////////////////////////////////////////////////////////////////


int counter = 0;
int seconds = 0;
void loop(){
    int * step = sequence[counter];
    
    while(seconds < step[0]) {
        delay(1000);
        seconds++;
    }

    digitalWrite(step[1],step[2]);
    counter++;
}

