class CreatureFans {

  float xPos;
  float yPos;
  float fanSpeed;
  float bigness;

  void prime() {

    xPos = random(bigness*50, width-bigness*50);
    yPos = random(bigness*50, height-bigness*50);
    bigness = 1;    // Change the creature's size
    fanSpeed = 5;
  }

  void update() {

    //The body. Position determined here
    strokeWeight(3);  
    stroke(0);
    fill(75, 56, 32);
    ellipse(xPos, yPos, bigness*50, bigness*50);

    // The eyeball
    fill(255);        
    ellipse(xPos-(bigness*4), yPos-(bigness*2), bigness*25, bigness*10);

    //The pupil
    fill(0);    
    ellipse(xPos-(bigness*5), yPos-(bigness+bigness*.5), bigness*5, bigness*5);

    //The mouth
    line(xPos-(bigness*16), yPos+(bigness*10), xPos+(bigness*11), yPos+(bigness*10));
  

  //MOVEMENT

  if(d>=10) {
    xPos=lerp(xPos, guy.xPos, .01);
    yPos=lerp(yPos, guy.yPos, .01);
  }

  }
    //Wall bounding

    //KOMBAT
  }
