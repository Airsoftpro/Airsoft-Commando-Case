bool activerMuscic = 1;

#include <DFRobot_DF1201S.h>
#include <SoftwareSerial.h>

//SoftwareSerial DF1201SSerial(2, 3);  //RX  TX
#define DF1201SSerial Serial1
DFRobot_DF1201S DF1201S;

#include "Nextion.h"
int introshow;
int boom = 0;
const int fumee = 4;
const int fumee1 = 5;
const int serrure = 6;

byte code[10][9] = {
  { 1, 8, 3, 6, 1, 9, 5, 5, 0 },
  { 1, 2, 1, 6, 5, 4, 9, 7, 1 },
  { 9, 5, 1, 1, 5, 0, 4, 7, 2 },
  { 7, 0, 6, 7, 1, 2, 4, 8, 7 },
  { 8, 1, 8, 5, 3, 6, 0, 5, 3 },
  { 9, 7, 1, 4, 1, 4, 2, 4, 6 },
  { 8, 9, 5, 5, 1, 2, 8, 6, 4 },
  { 8, 7, 8, 9, 8, 3, 2, 5, 4 },
  { 2, 3, 4, 2, 2, 8, 4, 1, 3 },
  { 7, 4, 0, 2, 8, 4, 7, 8, 1 }
};
byte codesaisie[9] = {};
byte Nbsaisie;
NexPage page0 = NexPage(0, 0, "page0");
NexPage page1 = NexPage(1, 0, "page1");
NexPage page2 = NexPage(2, 0, "page2");
NexButton page2b0 = NexButton(2, 2, "b0");
NexButton page2b1 = NexButton(2, 3, "b1");
NexButton page2b2 = NexButton(2, 4, "b2");
NexButton page2b3 = NexButton(2, 5, "b3");
NexButton page2b4 = NexButton(2, 6, "b4");
NexButton page2b5 = NexButton(2, 7, "b5");
NexButton page2b6 = NexButton(2, 8, "b6");
NexButton page2b7 = NexButton(2, 9, "b7");
NexButton page2b8 = NexButton(2, 10, "b8");
NexButton page2b9 = NexButton(2, 11, "b9");
NexButton page2b10 = NexButton(2, 12, "b10");
NexButton page2b11 = NexButton(2, 13, "b11");
NexText t0 = NexText(2, 14, "t0");
NexText t1 = NexText(2, 15, "t1");


char buffer[100] = {};

NexTouch *nex_listen_list[] = {
  &page0,
  &page1,
  &page2,
  &page2b0, &page2b1, &page2b2, &page2b3, &page2b4, &page2b5, &page2b6, &page2b7, &page2b8, &page2b9, &page2b10, &page2b11,
  &t0, &t1,
  NULL
};

unsigned long currentTime = 0;
unsigned long previousTime = 0;


int Tpsanimpage0 = 16000;
int Tpsanimpage1 = 6000;


void setup(void) {
  delay(3000);
  Serial.begin(9600);
  nexInit();
  delay(1000);
  page2b0.attachPop(page2b0PopCallback, &page2b1);
  page2b1.attachPop(page2b1PopCallback, &page2b1);
  page2b2.attachPop(page2b2PopCallback, &page2b2);
  page2b3.attachPop(page2b3PopCallback, &page2b3);
  page2b4.attachPop(page2b4PopCallback, &page2b4);
  page2b5.attachPop(page2b5PopCallback, &page2b5);
  page2b6.attachPop(page2b6PopCallback, &page2b6);
  page2b7.attachPop(page2b7PopCallback, &page2b7);
  page2b8.attachPop(page2b8PopCallback, &page2b8);
  page2b9.attachPop(page2b9PopCallback, &page2b9);
  page2b10.attachPop(page2b10PopCallback, &page2b10);
  page2b11.attachPop(page2b11PopCallback, &page2b11);

  pinMode(fumee, OUTPUT);
  pinMode(fumee1, OUTPUT);
  pinMode(serrure, OUTPUT);
  digitalWrite(fumee, LOW);
  digitalWrite(fumee1, LOW);
  digitalWrite(serrure, LOW);

  if (activerMuscic == 1) {
    DF1201SSerial.begin(115200);
    while (!DF1201S.begin(DF1201SSerial)) {
      Serial.println("Init failed, please check the wire connection!");
      delay(1000);
    }
    DF1201S.setVol(5);
    DF1201S.switchFunction(DF1201S.MUSIC);
    /*Wait for the end of the prompt tone */
    delay(2000);
    /*Set playback mode to "repeat all"*/
    DF1201S.setPlayMode(DF1201S.SINGLE);
  }
}

void loop(void) {
  currentTime = millis();
  if (introshow < 3) {
    intro();
  }
  nexLoop(nex_listen_list);
}

void page2b1PopCallback(void *ptr) {
  if (Nbsaisie < 9) {
    codesaisie[Nbsaisie] = 0;
    Nbsaisie++;
    affcode();
  }
}

void page2b3PopCallback(void *ptr) {
  if (Nbsaisie < 9) {
    codesaisie[Nbsaisie] = 1;
    Nbsaisie++;
    affcode();
  }
}
void page2b4PopCallback(void *ptr) {
  if (Nbsaisie < 9) {
    codesaisie[Nbsaisie] = 2;
    Nbsaisie++;
    affcode();
  }
}
void page2b5PopCallback(void *ptr) {
  if (Nbsaisie < 9) {
    codesaisie[Nbsaisie] = 3;
    Nbsaisie++;
    affcode();
  }
}
void page2b6PopCallback(void *ptr) {
  if (Nbsaisie < 9) {
    codesaisie[Nbsaisie] = 4;
    Nbsaisie++;
    affcode();
  }
}
void page2b7PopCallback(void *ptr) {
  if (Nbsaisie < 9) {
    codesaisie[Nbsaisie] = 5;
    Nbsaisie++;
    affcode();
  }
}
void page2b8PopCallback(void *ptr) {
  if (Nbsaisie < 9) {
    codesaisie[Nbsaisie] = 6;
    Nbsaisie++;
    affcode();
  }
}
void page2b9PopCallback(void *ptr) {
  if (Nbsaisie < 9) {
    codesaisie[Nbsaisie] = 7;
    Nbsaisie++;
    affcode();
  }
}
void page2b10PopCallback(void *ptr) {
  if (Nbsaisie < 9) {
    codesaisie[Nbsaisie] = 8;
    Nbsaisie++;
    affcode();
  }
}
void page2b11PopCallback(void *ptr) {
  if (Nbsaisie < 9) {
    codesaisie[Nbsaisie] = 9;
    Nbsaisie++;
    affcode();
  }
}

void page2b2PopCallback(void *ptr) {
  for (int i = 0; i <= 8; i++) {
    codesaisie[i] = 0;
  }
  Nbsaisie = 0;
  affcode();
}

void page2b0PopCallback(void *ptr) {
  //code[10][9]
  if (Nbsaisie == 9) {
    for (int i = 0; i <= 9; i++) {
      for (int b = 0; b <= 8; b++) {
        if (code[i][b] != codesaisie[b]) {
          boom = 2;
          break;
        } else {
          boom = 1;
        }
      }
      if (boom == 1) {
        break;
      }
    }
    if (boom == 2) {
      t1.Set_background_color_bco(63488);
      digitalWrite(fumee, HIGH);
      digitalWrite(fumee1, HIGH);
      digitalWrite(serrure, LOW);
      if (activerMuscic == 1) {
        DF1201S.playFileNum(4);
        DF1201S.start();
      }
      delay(7000);
    }
    if (boom == 1) {
      if (activerMuscic == 1) {
        DF1201S.playFileNum(3);
        DF1201S.start();
      }
      t1.Set_background_color_bco(2016);
      digitalWrite(fumee, LOW);
      digitalWrite(fumee1, LOW);
      digitalWrite(serrure, HIGH);
      delay(6000);
    }
    DF1201S.pause();
  }
}
