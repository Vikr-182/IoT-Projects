int a = 2;/*RED LIGHT SENSOR*/
int b = 3;/*YELLOW LIGHT SENSOR*/
int c = 4;/*GREEN LIGHT SENSOR*/
int bump = 7;/*BUMP SENSOR*/
int motorleftwheel = 5;
int motorrightwheel = 6;
int spd = 0;

void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
	pinMode(a,INPUT);
	pinMode(b,INPUT);
	pinMode(c,INPUT);
	pinMode(bump,INPUT);
	pinMode(motorleftwheel,OUTPUT);
	analogWrite(motorleftwheel,255);
	analogWrite(motorrightwheel,255);
}

void loop() {

	int w ;
	if(digitalRead(a)==HIGH)
	{
		w = 1;  
	}
	if(digitalRead(b)==HIGH)
	{
		w = 2;  
	}
	if(digitalWrite(c)==HIGH)
	{
		w = 3;  
	}
	if(digitalWrite(bump)==HIGH)
	{
		w = 4;  
	}	
	if(w==1)
	{
		STOP();
	}
	if(w==2)
	{
		FULL();
	}
	if(w==3)
	{
		BRAKE();
	}
	if(w==4)
	{
		BUMP();  
	}
}

void FULL()
{
	/*ACCELERATE TO 100% SPEED */
	while(spd!=255)
	{
		analogWrite(motorrightwheel,spd);
		analogWrite(motorleftwheel,spd);  
		spd++;
		delay(50);//SMOOTH TRANSITION.
	}
}

void STOP()
{
	/*STOP AT RED LIGHT*/
	while(spd!=0)
	{
		analogWrite(motorrightwheel,spd);
		analogWrite(motorleftwheel,spd);
		spd--;  
	}
}
void BRAKE()
{
	/*MAINTAIN CONSTANT 20% SPEED AT YELLOW LIGHT*/
	if(spd>50)
	{
		while(spd!=50)
		{
			analogWrite(motorrightwheel,spd);
			analogWrite(motorleftwheel,spd);
			spd--;  
			delay(40);
		}
	}
	else 
	{
		while(spd!=50)
		{
			analogWrite(motorrightwheel,spd);
			analogWrite(motorleftwheel,spd);
			spd++;
			delay(40);
		}  
	}
}

void BUMP(){
	int c = spd ;
	int flag =0;

	/*CROSSING THE BUMPER AT SPECIFIED 5% SPEED*/
	//DECELERATION
	if(spd>10)
	{
		while(spd!=10)
		{
			analogWrite(motorrightwheel,spd);
			analogWrite(motorleftwheel,spd);
			spd--;  
			delay(40);
			flag = 1;
		}
	}
	else
	{
		while(spd!=10)
		{
			analogWrite(motorrightwheel,spd);
			analogWrite(motorleftwheel,spd);
			spd++;
			flag = 0;
			delay(40);
		}  
	}

	//ACCELERATION
	if(flag==1)
	{
		while(spd!=c)
		{
			analogWrite(motorrightwheel,spd);
			analogWrite(motorleftwheel,spd);
			spd++; 
			delay(40); 
		}
	}
	else
	{
		while(spd!=c)
		{
			analogWrite(motorrightwheel,spd);
			analogWrite(motorleftwheel,spd);
			spd--;
			delay(40);
		}  
	}
}
