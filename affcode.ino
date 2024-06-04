void affcode() {
  if (Nbsaisie == 0) {
    sprintf(buffer, "----------\r\n");
    t0.setText(buffer);
  }
  if (Nbsaisie == 1) {
    sprintf(buffer, "%x--------\r\n", codesaisie[0]);
    t0.setText(buffer);
  }
  if (Nbsaisie == 2) {
    sprintf(buffer, "%x%x-------\r\n", codesaisie[0], codesaisie[1]);
    t0.setText(buffer);
  }
  if (Nbsaisie == 3) {
    sprintf(buffer, "%x%x%x------\r\n", codesaisie[0], codesaisie[1], codesaisie[2]);
    t0.setText(buffer);
  }
  if (Nbsaisie == 4) {
    sprintf(buffer, "%x%x%x%x-----\r\n", codesaisie[0], codesaisie[1], codesaisie[2], codesaisie[3]);
    t0.setText(buffer);
  }
  if (Nbsaisie == 5) {
    sprintf(buffer, "%x%x%x%x%x----\r\n", codesaisie[0], codesaisie[1], codesaisie[2], codesaisie[3], codesaisie[4]);
    t0.setText(buffer);
  }
  if (Nbsaisie == 6) {
    sprintf(buffer, "%x%x%x%x%x%x---\r\n", codesaisie[0], codesaisie[1], codesaisie[2], codesaisie[3], codesaisie[4], codesaisie[5]);
    t0.setText(buffer);
  }
  if (Nbsaisie == 7) {
    sprintf(buffer, "%x%x%x%x%x%x%x--\r\n", codesaisie[0], codesaisie[1], codesaisie[2], codesaisie[3], codesaisie[4], codesaisie[5], codesaisie[6]);
    t0.setText(buffer);
  }
  if (Nbsaisie == 8) {
    sprintf(buffer, "%x%x%x%x%x%x%x%x-\r\n", codesaisie[0], codesaisie[1], codesaisie[2], codesaisie[3], codesaisie[4], codesaisie[5], codesaisie[6], codesaisie[7]);
    t0.setText(buffer);
  }
  if (Nbsaisie == 9) {
    sprintf(buffer, "%x%x%x%x%x%x%x%x%x\r\n", codesaisie[0], codesaisie[1], codesaisie[2], codesaisie[3], codesaisie[4], codesaisie[5], codesaisie[6], codesaisie[7], codesaisie[8]);
    t0.setText(buffer);
  }
}