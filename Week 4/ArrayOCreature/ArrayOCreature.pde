CreaturePrime guy;
CreatureFans[] fan = new CreatureFans[6];

boolean upPressed;
boolean downPressed;
boolean leftPressed;
boolean rightPressed;

float d;

void setup() {

  size(600, 600);
  smooth();
  guy = new CreaturePrime();
  guy.prime();

  for (int i=0;i<fan.length;i++) {
    fan[i] = new CreatureFans();
    fan[i].prime();
  }
}

void draw() {
  background(255);
  guy.update();

  //Groupie Data
  for (int j=0;j<fan.length;j++) {
    d=dist(guy.xPos, guy.yPos, fan[j].xPos, fan[j].yPos);
    fan[j].update();
  }
}

void keyPressed() {
  if (keyCode == 'W') {
    upPressed=true;
  }

  if (keyCode== 'S') {
    downPressed=true;
  }
  if (keyCode=='A') {
    leftPressed=true;
  }
  if (keyCode=='D') {
    rightPressed=true;
  }
}

void keyReleased() {
  if (keyCode == 'W') {
    upPressed=false;
  }

  if (keyCode== 'S') {
    downPressed=false;
  }
  if (keyCode=='A') {
    leftPressed=false;
  }
  if (keyCode=='D') {
    rightPressed=false;
  }
}

