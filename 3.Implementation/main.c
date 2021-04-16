#include<stdio.h>
#include<math.h>
#define PI 3.14
int main(){
    float V,I,N,R;
    printf("Enter the voltage of the motor:");
    scanf("%f",&V);
    printf("Enter the current of the motor:");
    scanf("%f",&I);
    printf("Enter the speed of the motor:");
    scanf("%f",&N);
    printf("Enter the Resistance of the motor:");
    scanf("%f",&R);
    int p,Z,A1;
    float fl,E;
    lable2:
    printf("Enter the number of poles of the motor:");
    scanf("%d",&p);
    if(p%2==0){
    char A;
    lable1:
    printf("Enter the type of winding(l or w):");
    scanf(" %c",&A);
    char k=A;
    switch(k){
        case 'l':
             printf("The number of parallel paths:%d\n",p);
             A1=p;
             break;
        case 'w':
              A1=2;
              printf("The number of parallel paths:%d\n",A1);
              break;
        default:
         printf("Enter Only l or w\n");
         goto lable1;
    }
    printf("Enter the flux/pole:");
    scanf("%f",&fl);
    printf("Enter number of conductors in the armature of the motor:");
    scanf("%d",&Z);
    //To find Back Emf of the motor
    E=(N*p*fl*Z)/(60*A1);
    printf("Back Emf of the motor:%f\n",E);
    }
    else{
        printf("Number of the poles should be even\n");
        goto lable2;
    }
    //To find Input Power of the motor
    float P;
    //Input power = Voltage * Current
    P=V*I;        
    printf("Input power of the motor:%f\n",P);
    //To find Losses of the motor
    float W1,W2,l,B,h,v,t,ca;
    lable3:
    printf("Enter hysteresis coefficient:");
    scanf("%f",&h);
    printf("Enter the area of cross section:");
    scanf("%f",&ca);
    B=fl/ca;
    printf("The maximum flux density of the motor:%f\n",B);
    float f=(p*N)/120;
    printf("Enter the volume of the core:");
    scanf("%f",&v);
    printf("Enter the thickness of lamination in meters:");
    scanf("%f",&t);
    //Hysteresis Losses
    float r=pow(B,1.6);
    W1=h*r*f*v;
    printf("Hysteresis Losses:%f\n",W1);
    //Eddy Current Losses
    W2=B*B*f*f*t*t*v;
    printf("Eddy Current Losses:%f\n",W2);
    //Copper Losses
    float Cu=I*I*R;
    printf("Copper Losses:%f\n",Cu);
    //Total Losses
    float T=W1+W2+Cu;
    //To find Output power
    float O=P-T; //Output Power = Input Power - Total Losses
    printf("Output Power of the motor:%f\n",O);
    //Efficiency
    float Ef=(O/P)*100;
    printf("Efficiency of the Motor(in percentage):%f\n",Ef);
    if(Ef<50){
        printf("Change the Input Parameters\n");
        goto lable3;
    }
    float W=(2*PI*N)/60;
    float Mp=E*I;
    float Tor;
    //To find Torque
    Tor=Mp/W;
    printf("Torque of the motor:%f\n",Tor);
    //Voltage Regulation
    float VR;
    VR=(V-E)/E;
    printf("Voltage Regulation:%f\n",VR);
      return 0;
   }
