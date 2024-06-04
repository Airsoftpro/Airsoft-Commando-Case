void intro() {
  currentTime = millis();
  if (introshow == 0) {
    page0.show();
    introshow = 1;
    previousTime = currentTime;
    if (activerMuscic == 1) {
      DF1201S.playFileNum(1);
      DF1201S.start();
    }
  }
  if (((currentTime - previousTime) > Tpsanimpage0) && introshow == 1) {
    page1.show();
    introshow = 2;
    previousTime = currentTime;
    if (activerMuscic == 1) {
      DF1201S.pause();
      DF1201S.playFileNum(2);
      DF1201S.start();
    }
  }
  if (((currentTime - previousTime) > Tpsanimpage1) && introshow == 2) {
    if (activerMuscic == 1) {
      DF1201S.pause();
    }
    page2.show();
    introshow = 3;
    affcode();
  }
}