#pragma config(Motor,  port2,           left,          tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port3,           right,         tmotorVex269_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           army,          tmotorVex393_HBridge, openLoop, encoderPort, None)
#pragma config(Motor,  port5,           clawy,         tmotorVex269_MC29, openLoop)

task main()
{

while (1==1)
{
//This section will add exponential control to the joysticks, giving higher percision at lower channel values
//motor[left] = 5 + (127-5) * ((vexRT[Ch2]/127)*(vexRT[Ch2]/127)*(vexRT[Ch2]/127)*(vexRT[Ch2]/127));
//motor[right] = 5 + (127-5) * ((vexRT[Ch3]/127)*(vexRT[Ch3]/127)*(vexRT[Ch3]/127)*(vexRT[Ch3]/127));

int LogSpeedL;
int RawSpeedL = vexRT[Ch2];
if (RawSpeedL >= 0) {
    LogSpeedL = (RawSpeedL * RawSpeedL) / 127;
} else {
    LogSpeedL = (RawSpeedL * RawSpeedL) / -127;
}
motor[left]=LogSpeedL;

int LogSpeedR;
int RawSpeedR = vexRT[Ch3];
if (RawSpeedR >= 0) {
    LogSpeedR = (RawSpeedR * RawSpeedR) / 127;
} else {
    LogSpeedR = (RawSpeedR * RawSpeedR) / -127;
}
motor[right]=LogSpeedR;




if (vexRT[Btn5U]==1){ //move the arm up
  motor[army] = 90;
}
else if(vexRT[Btn5D]==1){ //move the arm down
	motor[army] = -20;
}
else if(vexRT[Btn5D]==0){ //make sure that the motor speed returns to 0 when the button is depressed.
	motor[army]=10;
}

if (vexRT[Btn6U]==1){ //open the claw
motor[clawy] = 127;
}
else if (vexRT[Btn6D]==1){ //close the claw
  motor[clawy] = -127;
}
else if (vexRT[Btn6D]==0){ //stop the claw motor
  motor[clawy] = 0;
}
}
}
