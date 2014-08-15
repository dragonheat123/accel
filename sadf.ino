unsigned int counter=0;
float xavg = 0;
float yavg = 0;
float accx;
float accy;
float oldacc;
float acc;
float oldspee;
float spee;
unsigned long timer;
unsigned long accstart;
unsigned int countx=0;


void setup() {
// put your setup code here, to run once:

while(counter<1000){
  xavg = xavg + analogRead(A0);
  yavg = yavg + analogRead(A1);
  counter = counter +1;
}
  xavg = xavg/1000;
  yavg = yavg/1000;


Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

if(timer == 0){  
getxy();
oldacc = acc;
accstart = millis();
timer = 1;
oldspee = spee;
}

if(timer<100){
timer = millis() - accstart +1;
}

if(timer >=100){
 getxy();
 if (accx<0){
 spee = spee -  (acc+oldacc)/2 * 1; 
 }
  if (accx>=0){
 spee = spee + (acc+oldacc)/2 * 1; 
 }
if (countx>25){
 spee = 0; 
}
 
 Serial.print("speed=");
 Serial.println(spee);
 timer = 0;
}



}


void getxy(){

accx = analogRead(A0)-xavg;
accy = analogRead(A1)-yavg;



if( (accx <=3.0 && accx>0.0) || (accx>=-3.0 && accx<0.0) || accx > 1024.0){
  accx = 0;
}

if( (accy <=3.0 && accy>0.0) || (accy>=-3.0 && accy<0.0) || accy > 1024.0){
  accy = 0;
}


accx = accx/164;


accy = accy/164;

acc = sqrt(accx*accx + accy*accy);


Serial.println(acc);

if((acc>0.1) ){
  countx= countx + 1;
  
}
else{
  countx=0;
  Serial.println("fsdfds");
}






}
