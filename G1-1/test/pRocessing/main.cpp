import processing.opengl.*;
import processing.serial.*;
import processing.sound.*;
int Fir=1;
int sat=0;
int alarm_time=5;//sec
int text_x=200;
int text_y=-110;
int alarm_on=0;
float threshold_deg=1.5;
float threshold_acc=0.4;
String aaa;
Serial mudtest;
int counter=0;
float []avg_data=new float[9];
int [] dataread=new int[16];
float [] data_accel=new float [9];
Pulse right_beep=new Pulse(this);
Pulse left_beep=new Pulse(this);
/*
float [] current_x=new float [9];
float [] new_x=new float [9];
float [] buffer_x=new float [9];
float [] current_v=new float [9];
float [] new_v=new float [9];
float [] buffer_v=new float [9];
*/
float t=0.3;
float [] roll=new float[3];
float [] pitch=new float[3];
float [] roll_avg=new float[3];
float [] pitch_avg=new float[3];


void setup()
{

    size(1600,1000,OPENGL);

    mudtest=new Serial(this,"COM6",9600); //com5
    //fullScreen();
    counter=0;
    for(int i=0; i<=15; i++)
    {
        dataread[i]=0;
    }
    for(int i=0; i<=8; i++)
    {
        data_accel[i]=0;
        /*
        current_x[i]=0;
        new_x[i]=0;
        current_v[i]=0;
        new_v[i]=0;

        */
    }
    for(int i=0; i<=2; i++)
    {
        roll[i]=0;
        pitch[i]=0;
        roll_avg[i]=0;
        pitch_avg[i]=0;
    }
    right_beep.set(500,0.5,0.5,0,1);
    left_beep.set(300,0.5,0.5,0,-1);
}

int SerialEvent_transfer (Serial mudtest)
{
    sat=0;
    //println("hello");
    if(mudtest.available()>0)
    {


        aaa =mudtest.readStringUntil('d');
        //println(aaa);

        /*
        for(int i=0;i<9;i++){

          dataread[i]=mudtest.read();
          println(dataread[i]);


        }
        */
        //println("end");
        sat=1;
    }

    return sat;
}


/*
void trans()
{
  if(dataread[11]/10==7)
  {dataread[0]=dataread[0]*(-1);
  dataread[1]=dataread[1]*(-1);
  dataread[2]=dataread[2]*(-1);
  }
  if(dataread[11]/10==6)
  {dataread[0]=dataread[0]*(-1);
  dataread[1]=dataread[1]*(-1);
  dataread[2]=dataread[2]*(1);
  }
  if(dataread[11]/10==5)
  {dataread[0]=dataread[0]*(-1);
  dataread[1]=dataread[1]*(1);
  dataread[2]=dataread[2]*(-1);
  }
  if(dataread[11]/10==4)
  {dataread[0]=dataread[0]*(-1);
  dataread[1]=dataread[1]*(1);
  dataread[2]=dataread[2]*(1);
  }
  if(dataread[11]/10==3)
  {dataread[0]=dataread[0]*(1);
  dataread[1]=dataread[1]*(-1);
  dataread[2]=dataread[2]*(-1);
  }
  if(dataread[11]/10==2)
  {dataread[0]=dataread[0]*(1);
  dataread[1]=dataread[1]*(-1);
  dataread[2]=dataread[2]*(1);
  }
  if(dataread[11]/10==1)
  {dataread[0]=dataread[0]*(1);
  dataread[1]=dataread[1]*(1);
  dataread[2]=dataread[2]*(-1);
  }
  if(dataread[11]/10==0)
  {dataread[0]=dataread[0]*(1);
  dataread[1]=dataread[1]*(1);
  dataread[2]=dataread[2]*(1);
  }
  if(dataread[11]%10==7)
  {dataread[3]=dataread[3]*(-1);
  dataread[4]=dataread[4]*(-1);
  dataread[5]=dataread[5]*(-1);
  }
  if(dataread[11]%10==6)
  {dataread[3]=dataread[3]*(-1);
  dataread[4]=dataread[4]*(-1);
  dataread[5]=dataread[5]*(1);
  }
  if(dataread[11]%10==5)
  {dataread[3]=dataread[3]*(-1);
  dataread[4]=dataread[4]*(1);
  dataread[5]=dataread[5]*(-1);
  }
  if(dataread[11]%10==4)
  {dataread[3]=dataread[3]*(-1);
  dataread[4]=dataread[4]*(1);
  dataread[5]=dataread[5]*(1);
  }
  if(dataread[11]%10==3)
  {dataread[3]=dataread[3]*(1);
  dataread[4]=dataread[4]*(-1);
  dataread[5]=dataread[5]*(-1);
  }
  if(dataread[11]%10==2)
  {dataread[3]=dataread[3]*(1);
  dataread[4]=dataread[4]*(-1);
  dataread[5]=dataread[5]*(1);
  }
  if(dataread[11]%10==1)
  {dataread[3]=dataread[3]*(1);
  dataread[4]=dataread[4]*(1);
  dataread[5]=dataread[5]*(1);
  }
  if(dataread[11]%10==0)
  {dataread[3]=dataread[3]*(1);
  dataread[4]=dataread[4]*(1);
  dataread[5]=dataread[5]*(1);
  }
  if(dataread[10]/10==7)
  {dataread[6]=dataread[6]*(-1);
  dataread[7]=dataread[7]*(-1);
  dataread[8]=dataread[8]*(-1);
  }
  if(dataread[10]/10==6)
  {dataread[6]=dataread[6]*(-1);
  dataread[7]=dataread[7]*(-1);
  dataread[8]=dataread[8]*(1);
  }
  if(dataread[10]/10==5)
  {dataread[6]=dataread[6]*(-1);
  dataread[7]=dataread[7]*(1);
  dataread[8]=dataread[8]*(-1);
  }
  if(dataread[10]/10==4)
  {dataread[6]=dataread[6]*(-1);
  dataread[7]=dataread[7]*(1);
  dataread[8]=dataread[8]*(1);
  }
  if(dataread[10]/10==3)
  {dataread[6]=dataread[6]*(1);
  dataread[7]=dataread[7]*(-1);
  dataread[8]=dataread[8]*(-1);
  }
  if(dataread[10]/10==2)
  {dataread[6]=dataread[6]*(1);
  dataread[7]=dataread[7]*(-1);
  dataread[8]=dataread[8]*(1);
  }
  if(dataread[10]/10==1)
  {dataread[6]=dataread[6]*(1);
  dataread[7]=dataread[7]*(1);
  dataread[8]=dataread[8]*(-1);
  }
  if(dataread[10]/10==0)
  {dataread[6]=dataread[6]*(1);
  dataread[7]=dataread[7]*(1);
  dataread[8]=dataread[8]*(1);
  }
  for(int i=0;i<=8;i++){
  data_accel[i]=dataread[i]*20*0.01;
  }
}
void x_buffering(){
  for(int i=0;i<=8;i++){
  buffer_x[i]=new_x[i];
  }
}

void current_x_transfer(){
  for(int i=0;i<=8;i++){
  current_x[i]=buffer_x[i];
  }

}

*/
/*
void new_x_transfer()
{
  for(int i=0;i<=8;i++){
  new_x[i]=((data_accel[i]*pow(t,2)/2+current_v[i]*t));
  }


}

void v_buffering(){
  for(int i=0;i<=8;i++){
  buffer_v[i]=new_v[i];
  }
}

void new_v_transfer()
{
  for(int i=0;i<=8;i++){
  new_x[i]=current_v[i]+data_accel[i]*t;
  }


}
void current_v_transfer(){
  for(int i=0;i<=8;i++){
  current_v[i]=buffer_v[i];
  }


}

*/
void roll_cac()
{
    for(int i=0; i<=2; i++)
    {
        roll[i]=atan2(data_accel[i*3+1],data_accel[i*3+2])*180/PI;
    }
}
void pitch_cac()
{
    for(int i=0; i<=2; i++)
    {
        pitch[i]=atan2(-data_accel[i*3],
                       sqrt((data_accel[i*3+1]*data_accel[i*3+1])+(data_accel[i*3+2]*data_accel[i*3+2])))*180/PI;
    }

}

void roll_cac_avg()
{
    for(int i=0; i<=2; i++)
    {
        roll_avg[i]=atan2(avg_data[i*3+1],avg_data[i*3+2])*180/PI;
    }
}
void pitch_cac_avg()
{
    for(int i=0; i<=2; i++)
    {
        pitch_avg[i]=atan2(-avg_data[i*3],
                           sqrt((avg_data[i*3+1]*avg_data[i*3+1])+(avg_data[i*3+2]*avg_data[i*3+2])))*180/PI;
    }

}

void timerWithalarm_danger()
{
    int delay=200;
    for(int i=0; i<alarm_time*1000/delay/2; i++)
    {
        right_beep.stop();
        left_beep.play();
        delay(delay);
        right_beep.play();
        left_beep.stop();
        delay(delay);
    }
    right_beep.stop();
    left_beep.stop();
    alarm_on=0;

}
void timerWithalarm_attention()
{
    int delay=400;
    for(int i=0; i<alarm_time*1000/delay/2; i++)
    {
        right_beep.stop();
        left_beep.play();
        delay(delay);
        right_beep.play();
        left_beep.stop();
        delay(delay);
    }
    right_beep.stop();
    left_beep.stop();
    alarm_on=0;

}
int roll_check(int seta)
{
    float diff=abs(roll_avg[seta]-roll[seta]);
    if(diff<threshold_deg)
    {
        return 0;
    }
    else if(diff<threshold_deg*2)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
int pitch_check(int seta)
{
    float diff=abs(pitch_avg[seta]-pitch[seta]);
    if(diff<threshold_deg)
    {
        return 0;
    }
    else if(diff<threshold_deg*2)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
float total_accel_cac(float x,float y,float z)
{
    float total_accel;
    total_accel=sqrt(x*x+y*y+z*z);
    return total_accel;
}
int accel_check(int seta)
{
    float diff=abs(total_accel_cac(avg_data[seta*3],avg_data[seta*3+1],avg_data[seta*3+2])-total_accel_cac(data_accel[seta*3],data_accel[seta*3+1],data_accel[seta*3+2]));
    if(diff<threshold_acc)
    {
        return 0;
    }
    else if(diff<threshold_acc*2)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
float diff_roll(int seta){
    return roll_avg[seta]-roll[seta];
}
float diff_pitch(int seta){
    return pitch_avg[seta]-pitch[seta];
}
float diff_accel(int seta){
    return total_accel_cac(avg_data[seta*3],avg_data[seta*3+1],avg_data[seta*3+2])-total_accel_cac(data_accel[seta*3],data_accel[seta*3+1],data_accel[seta*3+2]);
}


void draw()
{
    SerialEvent_transfer(mudtest);
    if(aaa!=null)
    {
        //print("trur\n");
        println(aaa);
        float []data_accel_x=float(split(aaa,','));
        String [] kkk=split(aaa,',');
        int position =0;
        if(kkk.length==10)
        {
            while(kkk[position].equals("end")==false)
            {
                position++;
            }
            if(position==9)
            {

                for(int pp=0; pp<9; pp++)
                {
                    data_accel[pp]=data_accel_x[pp]/100;
                    print(pp);
                    print("\t");
                    print(data_accel[pp]);
                    print("\t");
                    println(avg_data[pp]);
                }
                roll_cac();
                pitch_cac();
                /*

                */
                if(counter==100)
                {
                    counter=99;
                    if(Fir==1)
                    {
                        roll_cac_avg();
                        pitch_cac_avg();
                        Fir=0;
                    }
                    for(int pia=0; pia<3; pia++)
                    {
                        print(roll[pia]);
                        print("\t");
                        print(pitch[pia]);
                        print("\t\t\t");
                        print(roll_avg[pia]);
                        print("\t");
                        println(pitch_avg[pia]);
                    }
                    background(0);
                    strokeWeight(5);
                    stroke(255);
                    rotateZ(-HALF_PI);
                    fill(51,204,255);
                    text("Initiated Pipe Situation",-800,50);
                    rotateZ(HALF_PI);
                    stroke(0);
                    stroke(255);
                    line(350,0,0,350,1000,0);
                    line(700,0,0,700,1000,0);
                    stroke(0);
                    fill(128,128,128);
                    lights();
                    translate(200,200);
                    rotateX(radians(roll_avg[0]));
                    rotateZ(radians(-pitch_avg[0]));
                    box(120,250,120);
                    rotateZ(radians(pitch_avg[0]));
                    rotateX(radians(-roll_avg[0]));

                    translate(0,320);
                    rotateX(radians(roll_avg[1]));
                    rotateZ(radians(-pitch_avg[1]));
                    box(120,250,120);
                    rotateZ(radians(pitch_avg[1]));
                    rotateX(radians(-roll_avg[1]));

                    translate(0,320);
                    rotateX(radians(roll_avg[2]));
                    rotateZ(radians(-pitch_avg[2]));
                    box(120,250,120);
                    rotateZ(radians(pitch_avg[2]));
                    rotateX(radians(-roll_avg[2]));
                    /*******************************************/
                    translate(350,-640);//!!!
                    rotateZ(-HALF_PI);
                    fill(51,204,255);
                    text("Current Pipe Situation",-600,-130);
                    rotateZ(HALF_PI);
                    switch(roll_check(0))
                    {
                    case 0:
                        fill(128,128,128);
                        text("roll ok",text_x,text_y);
                        break;
                    case 1:
                        fill(255,255,0);
                        text("roll attention",text_x,text_y);
                        break;
                    case 2:
                        fill(255,0,0);
                        text("roll danger",text_x,text_y);
                        break;
                    }
                    text(diff_roll(0),text_x+500,text_y);
                    switch(pitch_check(0))
                    {
                    case 0:
                        fill(128,128,128);
                        text("pitch ok",text_x,text_y+100);
                        break;
                    case 1:
                        fill(255,255,0);
                        text("pitch attention",text_x,text_y+100);
                        break;
                    case 2:
                        fill(255,0,0);
                        text("pitch danger",text_x,text_y+100);
                        break;
                    }
                    text(diff_pitch(0),text_x+500,text_y+100);
                    switch(accel_check(0))
                    {
                    case 0:
                        fill(128,128,128);
                        text("acceleration ok",text_x,text_y+200);
                        break;
                    case 1:
                        fill(255,255,0);
                        text("acceleration attention",text_x,text_y+200);
                        break;
                    case 2:
                        fill(255,0,0);
                        text("acceleration danger",text_x,text_y+200);
                        break;
                    }
                    text(diff_accel(0),text_x+500,text_y+200);
                    int status_1=roll_check(0)|pitch_check(0)|accel_check(0);
                    switch(status_1)
                    {
                    case 0:
                        fill(128,128,128);
                        break;
                    case 1:
                        fill(255,255,0);
                        if(alarm_on==0)
                        {
                            thread("timerWithalarm_attention");
                            alarm_on=1;
                        }
                        break;
                    case 2:
                    case 3:
                        fill(255,0,0);
                        if(alarm_on==0)
                        {
                            thread("timerWithalarm_danger");
                            alarm_on=1;
                        }
                        break;
                    }

                    rotateX(radians(roll[0]));
                    rotateZ(radians(-pitch[0]));
                    box(120,250,120);
                    rotateZ(radians(pitch[0]));
                    rotateX(radians(-roll[0]));


                    /*******************************************/
                    translate(0,320);//!!!
                    switch(roll_check(1))
                    {
                    case 0:
                        fill(128,128,128);
                        text("roll ok",text_x,text_y);
                        break;
                    case 1:
                        fill(255,255,0);
                        text("roll attention",text_x,text_y);
                        break;
                    case 2:
                        fill(255,0,0);
                        text("roll danger",text_x,text_y);
                        break;
                    }
                    text(diff_roll(1),text_x+500,text_y);
                    switch(pitch_check(1))
                    {
                    case 0:
                        fill(128,128,128);
                        text("pitch ok",text_x,text_y+100);
                        break;
                    case 1:
                        fill(255,255,0);
                        text("pitch attention",text_x,text_y+100);
                        break;
                    case 2:
                        fill(255,0,0);
                        text("pitch danger",text_x,text_y+100);
                        break;
                    }
                    text(diff_pitch(1),text_x+500,text_y+100);
                    switch(accel_check(1))
                    {
                    case 0:
                        fill(128,128,128);
                        text("acceleration ok",text_x,text_y+200);
                        break;
                    case 1:
                        fill(255,255,0);
                        text("acceleration attention",text_x,text_y+200);
                        break;
                    case 2:
                        fill(255,0,0);
                        text("acceleration danger",text_x,text_y+200);
                        break;
                    }
                    text(diff_accel(1),text_x+500,text_y+200);
                    int status_2=roll_check(1)|pitch_check(1)|accel_check(1);
                    switch(status_2)
                    {
                    case 0:
                        fill(128,128,128);
                        break;
                    case 1:
                        fill(255,255,0);
                        if(alarm_on==0)
                        {
                            thread("timerWithalarm_attention");
                            alarm_on=1;
                        }
                        break;
                    case 2:
                    case 3:
                        fill(255,0,0);
                        if(alarm_on==0)
                        {
                            thread("timerWithalarm_danger");
                            alarm_on=1;
                        }
                        break;
                    }
                    rotateX(radians(roll[1]));
                    rotateZ(radians(-pitch[1]));
                    box(120,250,120);
                    rotateZ(radians(pitch[1]));
                    rotateX(radians(-roll[1]));
                    /*******************************************/
                    translate(0,320);//!!!
                    switch(roll_check(2))
                    {
                    case 0:
                        fill(128,128,128);
                        text("roll ok",text_x,text_y);
                        break;
                    case 1:
                        fill(255,255,0);
                        text("roll attention",text_x,text_y);
                        break;
                    case 2:
                        fill(255,0,0);
                        text("roll danger",text_x,text_y);
                        break;
                    }
                    text(diff_roll(2),text_x+500,text_y);
                    switch(pitch_check(2))
                    {
                    case 0:
                        fill(128,128,128);
                        text("pitch ok",text_x,text_y+100);
                        break;
                    case 1:
                        fill(255,255,0);
                        text("pitch attention",text_x,text_y+100);
                        break;
                    case 2:
                        fill(255,0,0);
                        text("pitch danger",text_x,text_y+100);
                        break;
                    }
                    text(diff_pitch(2),text_x+500,text_y+100);
                    switch(accel_check(2))
                    {
                    case 0:
                        fill(128,128,128);
                        text("acceleration ok",text_x,text_y+200);
                        break;
                    case 1:
                        fill(255,255,0);
                        text("acceleration attention",text_x,text_y+200);
                        break;
                    case 2:
                        fill(255,0,0);
                        text("acceleration danger",text_x,text_y+200);
                        break;
                    }
                    text(diff_accel(2),text_x+500,text_y+200);
                    int status_3=roll_check(2)|pitch_check(2)|accel_check(2);
                    switch(status_3)
                    {
                    case 0:
                        fill(128,128,128);
                        break;
                    case 1:
                        fill(255,255,0);
                        if(alarm_on==0)
                        {
                            thread("timerWithalarm_attention");
                            alarm_on=1;
                        }
                        break;
                    case 2:
                    case 3:
                        fill(255,0,0);
                        if(alarm_on==0)
                        {
                            thread("timerWithalarm_danger");
                            alarm_on=1;
                        }
                        break;
                    }
                    rotateX(radians(roll[2]));
                    rotateZ(radians(-pitch[2]));
                    box(120,250,120);
                    rotateZ(radians(pitch[2]));
                    rotateX(radians(-roll[2]));


                    println(status_1);
                    println(status_2);
                    println(status_3);

                }
                else
                {
                    //translate(500,500);
                    background(0);
                    textSize(50);
                    text("initiating",500,500);
                    text(counter,800,500);
                    text("%",900,500);


                    for(int pp=0; pp<9; pp++)
                    {
                        avg_data[pp]+=data_accel[pp]/100;

                    }

                    for(int pia=0; pia<3; pia++)
                    {
                        print(roll[pia]);
                        print("\t");
                        println(pitch[pia]);
                    }
                }

                counter++;
            }
        }
    }




}
