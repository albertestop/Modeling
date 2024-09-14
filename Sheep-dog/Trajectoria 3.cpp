#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

using namespace std;

//PARÀMETRES NORMALITZACIÓ
	double Oatr=0.04, Natr=15, Ofr=1.5, Opar=50, Npar=0.1, Ogos=1.3, Ngos=3.5;
	double radi_cercle=6, dist_separacio=1;
	double y_centre=radi_cercle, x_centre=radi_cercle, ax=9, by=12, lon=1.2, v_perro=3, descanso=3;
	double radi=ax, amplada;
	double temps_final=162.08;
	
	
	
double dist(double punt1x, double punt1y, double punt2x, double punt2y){   //distancia entre dos punts
	return sqrt((punt1x-punt2x)*(punt1x-punt2x)+(punt1y-punt2y)*(punt1y-punt2y));
}


double trajectoria_gos(double p, double t){
	double ax=9;
	double w=v_perro/radi;
	double angus;
	double x, x2;
	double u=(3.14159/(2.*w));
	double t_i=2.00000;
	if (t<t_i){
		if (p==0){
			return radi_cercle;
		}
		if (p==1){
			return radi_cercle-by;
		}
	}
	if (2<t && t<(u+t_i)){
		w=v_perro/radi;
		angus=w*(t-2);
		x=radi*sin(angus);
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x+radi_cercle;
		}
		if (p==1){
			return -sqrt(by*by-((x*x)/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u+t_i)<t && t<(u*2+t_i)){	//2
		angus=w*(t-2);
		x=radi*sin(angus);
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x+radi_cercle;
		}
		if (p==1){
			return sqrt(by*by-((x*x)/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*2+t_i)<t && t<(u*2+t_i+(lon/v_perro))){	//3
		if (p==0){
			return radi_cercle-(t-(u*2+t_i))*v_perro;
		}
		if (p==1){
			return radi_cercle+by;
		}
	}
	if ((u*2+t_i)<t && t<(descanso+u*2+t_i+(lon/v_perro))){
		if (p==0){
			return radi_cercle-lon;
		}
		if (p==1){
			return radi_cercle+by;
		}
	}
	if ((u*2+t_i+(lon/v_perro)+descanso)<t && t<(u*3+t_i+(lon/v_perro)+descanso)){	//4
		w=v_perro/radi;
		angus=(w*(t-2-(u*2+(lon/v_perro)+descanso)));
		x=radi*sin(angus);
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x+radi_cercle-lon;
		}
		if (p==1){
			return sqrt(by*by-(((x)*(x))/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*3+t_i+(lon/v_perro)+descanso)<t && t<(u*4+t_i+(lon/v_perro)+descanso)){	//5
		w=v_perro/radi;
		angus=(w*(t-2-(u*2+(lon/v_perro)+descanso)));
		x=radi*sin(angus);
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x+radi_cercle-lon;
		}
		if (p==1){
			return -sqrt(by*by-((x*x)/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*4+t_i+(lon/v_perro)+descanso)<t && t<(u*4+t_i+(lon/v_perro)*2+descanso)){	//6
		if (p==0){
			return radi_cercle-lon-(t-(u*4+t_i+(lon/v_perro)+descanso))*v_perro;
		}
		if (p==1){
			return radi_cercle-by;
		}
	}
	if ((u*4+t_i+(lon/v_perro)*2+descanso)<t && t<(u*4+t_i+(lon/v_perro)*2+descanso*2)){
		if (p==0){
			return radi_cercle-lon*2;
		}
		if (p==1){
			return radi_cercle-by;
		}
	}
	if ((u*4+t_i+(lon/v_perro)*2+descanso*2)<t && t<(u*5+t_i+(lon/v_perro)*2+descanso*2)){	//7
		w=v_perro/radi;
		angus=w*(t-(u*4+t_i+(lon/v_perro)*2+descanso*2));
		x=radi*sin(angus);
		double u=(3.141592/(2.*w)+t_i);
		if (p==0){
			return x+radi_cercle-2*lon;
		}
		if (p==1){
			return -sqrt(by*by-((x*x)/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*5+t_i+(lon/v_perro)*2+descanso*2)<t && t<(u*6+t_i+(lon/v_perro)*2+descanso*2)){	//8
		angus=w*(t-(u*4+t_i+(lon/v_perro)*2+descanso*2));
		x=radi*sin(angus);
		double u=(3.141592/(2.*w)+t_i);
		if (p==0){
			return x+radi_cercle-2*lon;
		}
		if (p==1){
			return sqrt(by*by-((x*x)/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*6+t_i+(lon/v_perro)*2+descanso*2)<t && t<(u*6+t_i+(lon/v_perro)*3+descanso*2)){	//9
		if (p==0){
			return radi_cercle-lon*2-(t-(u*6+t_i+(lon/v_perro)*2+descanso*2))*v_perro;
		}
		if (p==1){
			return radi_cercle+by;
		}
	}
	if ((u*6+t_i+(lon/v_perro)*2+descanso*2)<t && t<(u*6+t_i+(lon/v_perro)*3+descanso*3)){
		if (p==0){
			return radi_cercle-lon*3;
		}
		if (p==1){
			return radi_cercle+by;
		}
	}
	if ((u*6+t_i+(lon/v_perro)*3+descanso*3)<t && t<(u*7+t_i+(lon/v_perro)*3+descanso*3)){	//10
		w=v_perro/radi;
		angus=w*(t-(u*6+t_i+(lon/v_perro)*3+descanso*3));
		x=radi*sin(angus);
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x+radi_cercle-lon*3;
		}
		if (p==1){
			return sqrt(by*by-(((x)*(x))/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*7+t_i+(lon/v_perro)*3+descanso*3)<t && t<(u*8+t_i+(lon/v_perro)*3+descanso*3)){	//11
		w=v_perro/radi;
		angus=w*(t-(u*6+t_i+(lon/v_perro)*3+descanso*3));
		x=radi*sin(angus);
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x+radi_cercle-lon*3;
		}
		if (p==1){
			return -sqrt(by*by-((x*x)/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*8+t_i+(lon/v_perro)*3+descanso*3)<t && t<(u*8+t_i+(lon/v_perro)*4+descanso*3)){	//12
		if (p==0){
			return radi_cercle-lon*3-(t-(u*8+t_i+(lon/v_perro)*3+descanso*3))*v_perro;
		}
		if (p==1){
			return radi_cercle-by;
		}
	}
	if ((u*8+t_i+(lon/v_perro)*4+descanso*3)<t && t<(u*8+t_i+(lon/v_perro)*4+descanso*4)){
		if (p==0){
			return radi_cercle-lon*4;
		}
		if (p==1){
			return radi_cercle-by;
		}
	}
	if ((u*8+t_i+(lon/v_perro)*4+descanso*4)<t && t<(u*9+t_i+(lon/v_perro)*4+descanso*4)){	//10
		w=v_perro/radi;
		angus=w*(t-(u*8+t_i+(lon/v_perro)*4+descanso*4));
		x=radi*sin(angus);
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x+radi_cercle-lon*4;
		}
		if (p==1){
			return -sqrt(by*by-(((x)*(x))/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*9+t_i+(lon/v_perro)*4+descanso*4)<t && t<(u*10+t_i+(lon/v_perro)*4+descanso*4)){	//11
		w=v_perro/radi;
		angus=w*(t-(u*8+t_i+(lon/v_perro)*4+descanso*4));
		x=radi*sin(angus);
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x+radi_cercle-lon*4;
		}
		if (p==1){
			return +sqrt(by*by-((x*x)/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*10+t_i+(lon/v_perro)*4+descanso*4)<t && t<(u*10+t_i+(lon/v_perro)*5+descanso*4)){	//12
		if (p==0){
			return radi_cercle-lon*4-(t-(u*10+t_i+(lon/v_perro)*4+descanso*4))*v_perro;
		}
		if (p==1){
			return radi_cercle+by;
		}
	}
	if ((u*10+t_i+(lon/v_perro)*5+descanso*4)<t && t<(u*10+t_i+(lon/v_perro)*5+descanso*5)){
		if (p==0){
			return radi_cercle-lon*5;
		}
		if (p==1){
			return radi_cercle+by;
		}
	}
	if ((u*10+t_i+(lon/v_perro)*5+descanso*5)<t && t<(u*11+t_i+(lon/v_perro)*5+descanso*5)){	//10
		w=v_perro/radi;
		angus=w*(t-(u*10+t_i+(lon/v_perro)*5+descanso*5));
		x=radi*sin(angus);
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x+radi_cercle-lon*5;
		}
		if (p==1){
			return +sqrt(by*by-(((x)*(x))/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*11+t_i+(lon/v_perro)*5+descanso*5)<t && t<(u*12+t_i+(lon/v_perro)*5+descanso*5)){	//11
		w=v_perro/radi;
		angus=w*(t-(u*10+t_i+(lon/v_perro)*5+descanso*5));
		x=radi*sin(angus);
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x+radi_cercle-lon*5;
		}
		if (p==1){
			return -sqrt(by*by-((x*x)/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*12+t_i+(lon/v_perro)*5+descanso*5)<t && t<(u*12+t_i+(lon/v_perro)*6+descanso*5)){	//12
		if (p==0){
			return radi_cercle-lon*5-(t-(u*12+t_i+(lon/v_perro)*5+descanso*5))*v_perro;
		}
		if (p==1){
			return radi_cercle-by;
		}
	}
	if ((u*12+t_i+(lon/v_perro)*6+descanso*5)<t && t<(u*12+t_i+(lon/v_perro)*6+descanso*6)){
		if (p==0){
			return radi_cercle-lon*6;
		}
		if (p==1){
			return radi_cercle-by;
		}
	}
	if ((u*12+t_i+(lon/v_perro)*6+descanso*6)<t && t<(u*13+t_i+(lon/v_perro)*6+descanso*6)){	//10
		w=v_perro/radi;
		angus=w*(t-(u*12+t_i+(lon/v_perro)*6+descanso*6));
		x=radi*sin(angus);
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x+radi_cercle-lon*6;
		}
		if (p==1){
			return -sqrt(by*by-(((x)*(x))/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*13+t_i+(lon/v_perro)*6+descanso*6)<t && t<(u*14+t_i+(lon/v_perro)*6+descanso*6)){	//10
		w=v_perro/radi;
		angus=w*(t-(u*12+t_i+(lon/v_perro)*6+descanso*6));
		x=radi*sin(angus);
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x+radi_cercle-lon*6;
		}
		if (p==1){
			return sqrt(by*by-(((x)*(x))/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*14+t_i+(lon/v_perro)*6+descanso*6)<t && t<(u*14+t_i+(lon/v_perro)*6+descanso*7)){
		if (p==0){
			return radi_cercle-lon*6;
		}
		if (p==1){
			return radi_cercle+by;
		}
	}
	if ((u*14+t_i+(lon/v_perro)*6+descanso*7)<t && t<(u*15+t_i+(lon/v_perro)*6+descanso*7)){	//10
		w=v_perro/radi;
		angus=w*(t-(u*14+t_i+(lon/v_perro)*6+descanso*7));
		x=radi*sin(angus);
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x+radi_cercle-lon*6;
		}
		if (p==1){
			return sqrt(by*by-(((x)*(x))/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*15+t_i+(lon/v_perro)*6+descanso*7)<t && t<(u*16+t_i+(lon/v_perro)*6+descanso*7)){	//10
		w=v_perro/radi;
		angus=w*(t-(u*14+t_i+(lon/v_perro)*6+descanso*7));
		x=radi*sin(angus);
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x+radi_cercle-lon*6;
		}
		if (p==1){
			return -sqrt(by*by-(((x)*(x))/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*16+t_i+(lon/v_perro)*6+descanso*7)<t && t<(u*16+t_i+(lon/v_perro)*6+descanso*8)){
		if (p==0){
			return radi_cercle-lon*6;
		}
		if (p==1){
			return radi_cercle-by;
		}
	}
	if ((u*16+t_i+(lon/v_perro)*6+descanso*8)<t && t<(u*17+t_i+(lon/v_perro)*6+descanso*8)){	//10
		w=v_perro/radi;
		angus=w*(t-(u*16+t_i+(lon/v_perro)*6+descanso*8));
		x=(radi)*sin(angus);
		x2=(radi-0.6)*sin(angus);
		by=10;
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x2+radi_cercle-lon*6;
		}
		if (p==1){
			return -sqrt(by*by-(((x)*(x))/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*17+t_i+(lon/v_perro)*6+descanso*8)<t && t<(u*18+t_i+(lon/v_perro)*6+descanso*8)){	//10
		w=v_perro/radi;
		angus=w*(t-(u*16+t_i+(lon/v_perro)*6+descanso*8));
		by=10;
		x=(radi)*sin(angus);
		x2=(radi-0.6)*sin(angus);
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x2+radi_cercle-lon*6;
		}
		if (p==1){
			return +sqrt(by*by-(((x)*(x))/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*18+t_i+(lon/v_perro)*6+descanso*8)<t && t<(u*18+t_i+(lon/v_perro)*6+descanso*9)){
		if (p==0){
			return radi_cercle-lon*6;
		}
		if (p==1){
			return radi_cercle+by;
		}
	}
	if ((u*18+t_i+(lon/v_perro)*6+descanso*9)<t && t<(u*19+t_i+(lon/v_perro)*6+descanso*9)){	//10
		w=v_perro/radi;
		angus=w*(t-(u*18+t_i+(lon/v_perro)*6+descanso*9));
		x=(radi)*sin(angus);
		x2=(radi-1.4)*sin(angus);
		by=8;
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x2+radi_cercle-lon*6;
		}
		if (p==1){
			return +sqrt(by*by-(((x)*(x))/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*19+t_i+(lon/v_perro)*6+descanso*9)<t && t<(u*20+t_i+(lon/v_perro)*6+descanso*9)){	//10
		w=v_perro/radi;
		angus=w*(t-(u*18+t_i+(lon/v_perro)*6+descanso*9));
		by=8;
		x=(radi)*sin(angus);
		x2=(radi-1.4)*sin(angus);
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x2+radi_cercle-lon*6;
		}
		if (p==1){
			return -sqrt(by*by-(((x)*(x))/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*20+t_i+(lon/v_perro)*6+descanso*9)<t && t<(u*20+t_i+(lon/v_perro)*6+descanso*10)){
		if (p==0){
			return radi_cercle-lon*6;
		}
		if (p==1){
			return radi_cercle-by;
		}
	}
	if ((u*20+t_i+(lon/v_perro)*6+descanso*10)<t && t<(u*21+t_i+(lon/v_perro)*6+descanso*10)){	//10
		w=v_perro/radi;
		angus=w*(t-(u*20+t_i+(lon/v_perro)*6+descanso*10));
		x=(radi)*sin(angus);
		x2=(radi-2)*sin(angus);
		by=7;
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x2+radi_cercle-lon*6;
		}
		if (p==1){
			return -sqrt(by*by-(((x)*(x))/(ax*ax))*by*by)+(y_centre);
		}
	}
	if ((u*21+t_i+(lon/v_perro)*6+descanso*10)<t && t<(u*22+t_i+(lon/v_perro)*6+descanso*10)){	//10
		w=v_perro/radi;
		angus=w*(t-(u*20+t_i+(lon/v_perro)*6+descanso*10));
		by=7;
		x=(radi)*sin(angus);
		x2=(radi-2.4)*sin(angus);
		double u=(3.141592/(2.*w)+2.);
		if (p==0){
			return x2+radi_cercle-lon*6;
		}
		if (p==1){
			return +sqrt(by*by-(((x)*(x))/(ax*ax))*by*by)+(y_centre);
		}
	}
}


double gos(int p, double ovellaix, double ovellaiy, double gosx, double gosy){				//força del GOS
	double x=(-gosx+ovellaix);
	double y=(-gosy+ovellaiy);
	double r=sqrt((x*x)+(y*y));

	if (p==0){
		return ((x/r)*(Ogos*exp(-(r*r)/(Ngos*Ngos))));
	}
	if (p==1){
		return ((y/r)*(Ogos*exp(-(r*r)/(Ngos*Ngos))));
	}	
}


double ovelles(int p, double ovellajx, double ovellajy, double ovellaix, double ovellaiy){    //força X entre DUES OVELLES sense res més
	double x=(-ovellajx+ovellaix);
	double y=(-ovellajy+ovellaiy);
	double r=sqrt((x*x)+(y*y));

	if (p==0){
		return ((x/r)*(-(Oatr/(Natr*Natr))*(r*r)*exp(-(r*r)/(Natr*Natr))+(exp(-(r*r)))));
	}
	if (p==1){
		return ((y/r)*(-(Oatr/(Natr*Natr))*(r*r)*exp(-(r*r)/(Natr*Natr))+(exp(-(r*r)))));
	}	
}

double tancat(int p, double x){																//força del TANCAT
	
	if (p==0){
		return Opar*exp(-(x*x)/(Npar*Npar));
	}
	if (p==1){
		return 0;
	}	
}


double fregament(int p, double vx, double vy){													//força de FREGAMENT 
	double v=(sqrt((vx*vx)+(vy*vy)));
	
	if (p==0){
		return -vx*Ofr;
	}
	if (p==1){
		return -vy*Ofr;
	}
}



int main(void)
{

	int N_ovelles=40, dim=2, proximitat=0, pos_x, pos_y;
	float posfloat_x, posfloat_y;
	double pos_ovella[N_ovelles][dim], pos_ovella2[N_ovelles][dim]; //dim=0 son les x, dim=1 son les y
	int radi_entero=(int)radi_cercle*20+11;

	
	//situcio inicial ovelles
	
	srand (time(NULL));
	for(int i=0; i<N_ovelles; i++){
		proximitat=0;
		pos_x=(rand()%(radi_entero));
		pos_y=(rand()%(radi_entero));
		posfloat_x=pos_x;
		posfloat_y=pos_y;
		pos_ovella[i][0]=posfloat_x/10;
		pos_ovella[i][1]=posfloat_y/10;
		if(sqrt(pow((pos_ovella[i][0]-radi_cercle),2)+pow((pos_ovella[i][1]-radi_cercle),2))>=radi_cercle){
			proximitat=1;
		}
		for(int j=0; j<i; j++){
			if(dist(pos_ovella[i][0],pos_ovella[i][1],pos_ovella[j][0], pos_ovella[j][1])<dist_separacio){
				proximitat=1;
			}
		}
		if(proximitat==1){
			i--;
		}
	}
	
	
	FILE* fichero;
	fichero = fopen("posicio_inicial_ovelles.txt", "w" ); 

	for(int i=0; i<N_ovelles; i++)
	{
		fprintf(fichero, "%lf %lf \n", pos_ovella[i][0], pos_ovella[i][1]);
	}
	fclose(fichero);

	//RUNGE KUTTA///////////////////////////////////////////////////////////////////////////////////////////////
	
	char buffer[100];
	FILE* output;

	
	double k1[N_ovelles][dim], k2[N_ovelles][dim], k3[N_ovelles][dim], k4[N_ovelles][dim], l1[N_ovelles][dim], l2[N_ovelles][dim], l3[N_ovelles][dim], l4[N_ovelles][dim];
	double vel_ovella[N_ovelles][dim], vel_ovella2[N_ovelles][dim], contposp_ovella[dim], contvelp_ovella[dim], pos_gos[dim];
	double h=0.015, t=0;
	int iteracio=0, deuans=0;
	
	//CONDICIONS INICIALS//////////////////////////////////////////////////////
	for(int i=0; i<N_ovelles; i++){
		for(int coord=0; coord<dim; coord++){
			vel_ovella[i][coord]=0;
		//	vel_ovella[i][1]=0;
		}
	}

	for(int i=0; i<N_ovelles; i++){
		for(int coord=0; coord<dim; coord++){
			pos_ovella[i][coord]=pos_ovella[i][coord];
		}
	}
	
	for(int i=0; i<N_ovelles; i++){
		for(int coord=0; coord<dim; coord++){
			pos_ovella2[i][coord]=pos_ovella[i][coord];
			vel_ovella2[i][coord]=vel_ovella[i][coord];
		}
	}


	while(t<temps_final){
		
		for(int coord=0;coord<dim;coord++){
			pos_gos[coord]=trajectoria_gos(coord, t);
		}
		
		deuans=0;
		
		for(int i=0; i<N_ovelles; i++){
			
			if(pos_ovella[i][0]>50){
				deuans=deuans+1;
			}
			if(deuans==N_ovelles){
				printf("%lf",t);
			}
			//http://www.sc.ehu.es/sbweb/fisica_/numerico/diferencial/segundo.html
				
			if(pos_ovella[i][0]<0 && pos_ovella[i][1]<(radi_cercle+radi_cercle/5) && pos_ovella[i][1]>(radi_cercle-radi_cercle/5)){
				pos_ovella2[i][0]=i*100+1000;
				pos_ovella2[i][1]=i/10;
				vel_ovella2[i][0]=0;
				vel_ovella2[i][1]=0;
			}
			
			else if(pos_ovella[i][0]<0){
				pos_ovella2[i][0]=0;
				vel_ovella2[i][0]=0;
			}
			
			else{				
				
				//RK OVELLES/////////////////////////////////////////////////////
				for(int j=0; j<N_ovelles; j++){												//K1
					for(int coord=0; coord<dim; coord++){
						if(j!=i){
							k1[j][coord]=vel_ovella[i][coord]*h;
						}
					}
				}																				
																			
				for(int j=0; j<N_ovelles; j++){												//L1
					for(int coord=0; coord<dim; coord++){
						if(j!=i){
							l1[j][coord]=h*ovelles(coord, pos_ovella[j][0], pos_ovella[j][1], pos_ovella[i][0], pos_ovella[i][1]);
						}
					}
				}

				for(int j=0; j<N_ovelles; j++){												//K2
					for(int coord=0; coord<dim; coord++){
						if(j!=i){
							k2[j][coord]=h*(vel_ovella[i][coord]+(1/2*l1[j][coord]));					
						}
					}
				}					
				
				for(int j=0; j<N_ovelles; j++){												//L2
					for(int coord=0; coord<dim; coord++){
						if(j!=i){
							l2[j][coord]=h*ovelles(coord, pos_ovella[j][0]+(1/2)*k1[j][coord], pos_ovella[j][1]+(1/2)*k1[j][coord], pos_ovella[i][0]+(1/2)*k1[j][coord], pos_ovella[i][1]+(1/2)*k1[j][coord]);
						}
					}
				}																				
																		
				for(int j=0; j<N_ovelles; j++){												//K3
					for(int coord=0; coord<dim; coord++){
						if(j!=i){
							k3[j][coord]=h*(vel_ovella[i][coord]+((1/2)*l2[j][coord]));
						}
					}
				}		
															
				for(int j=0; j<N_ovelles; j++){												//L3
					for(int coord=0; coord<dim; coord++){
						if(j!=i){
							l3[j][coord]=h*ovelles(coord, pos_ovella[j][0]+(1/2)*k2[j][coord], pos_ovella[j][1]+(1/2)*k2[j][coord], pos_ovella[i][0]+(1/2)*k2[j][coord], pos_ovella[i][1]+(1/2)*k2[j][coord]);
						}
					}
				}
				
				for(int j=0; j<N_ovelles; j++){												//K4
					for(int coord=0; coord<dim; coord++){
						if(j!=i){
							k4[j][coord]=h*(vel_ovella[i][coord]+(l3[j][coord]));
						}
					}
				}																				
		
				for(int j=0; j<N_ovelles; j++){												//L4
					for(int coord=0; coord<dim; coord++){
						if(j!=i){
							l4[j][coord]=h*ovelles(coord, pos_ovella[j][0]+k3[j][coord], pos_ovella[j][1]+k3[j][coord], pos_ovella[i][0]+k3[j][coord], pos_ovella[i][1]+k3[j][coord]);
						}
					}
				}
				
				for(int coord=0; coord<dim; coord++){
					contposp_ovella[coord]=0;													//CONTRIBUCIÓ DE CADA OBELLA REINICIALITZADA A 0
					contvelp_ovella[coord]=0;
				}
				
				for(int coord=0; coord<dim; coord++){											//CONTRIBUCIÓ DE LES OVELLES
					for(int j=0; j<N_ovelles; j++){
						if(j!=i){
							contposp_ovella[coord]=contposp_ovella[coord]+(0.166666)*(k1[j][coord]+2*k2[j][coord]+2*k3[j][coord]+k4[j][coord]);
							contvelp_ovella[coord]=contvelp_ovella[coord]+(0.166666)*(l1[j][coord]+2*l2[j][coord]+2*l3[j][coord]+l4[j][coord]);
						}
					}
				}

				for(int coord=0; coord<dim; coord++){
					pos_ovella2[i][coord]=pos_ovella[i][coord]+contposp_ovella[coord];			
					vel_ovella2[i][coord]=vel_ovella[i][coord]+contvelp_ovella[coord];
				}
				
				
				
				//RK FREGAMENT/////////////////////////////////////////////////
				for(int coord=0; coord<dim; coord++){			//K1
					k1[i][coord]=vel_ovella[i][coord]*h;
				}
				
				for(int coord=0; coord<dim; coord++){			//L1
					l1[i][coord]=h*fregament(coord, vel_ovella[i][0], vel_ovella[i][1]);
				}

				for(int coord=0; coord<dim; coord++){			//K2
					k2[i][coord]=h*(vel_ovella[i][coord]+(1/2*l1[i][coord]));					
				}
				
				for(int coord=0; coord<dim; coord++){			//L2
					l2[i][coord]=h*fregament(coord, vel_ovella[i][0]+(1/2)*k1[i][coord], vel_ovella[i][1]+(1/2)*k1[i][coord]);
				}																			
																		
				for(int coord=0; coord<dim; coord++){			//K3
					k3[i][coord]=h*(vel_ovella[i][coord]+((1/2)*l2[i][coord]));
				}
															
				for(int coord=0; coord<dim; coord++){			//L3
					l3[i][coord]=h*fregament(coord, vel_ovella[i][0]+(1/2)*k2[i][coord], vel_ovella[i][1]+(1/2)*k2[i][coord]);
				}

				for(int coord=0; coord<dim; coord++){			//K4
					k4[i][coord]=h*(vel_ovella[i][coord]+(l3[i][coord]));
				}																				
		
				for(int coord=0; coord<dim; coord++){			//L4
					l4[i][coord]=h*fregament(coord, vel_ovella[i][0]+k3[i][coord], vel_ovella[i][1]+k3[i][coord]);
				}


				for(int coord=0; coord<dim; coord++){												//CONTRIBUCIÓ DEL FREGAMENT
					pos_ovella2[i][coord]=pos_ovella2[i][coord]+(0.166666)*(k1[i][coord]+2*k2[i][coord]+2*k3[i][coord]+k4[i][coord]);			
					vel_ovella2[i][coord]=vel_ovella2[i][coord]+(0.166666)*(l1[i][coord]+2*l2[i][coord]+2*l3[i][coord]+l4[i][coord]);
				}
				
				if(pos_ovella[i][1]>(radi_cercle+radi_cercle/3) || pos_ovella[i][1]<(radi_cercle-radi_cercle/3)){
				
					//RK TANCAT//////////////////////////////////////
					for(int coord=0; coord<dim; coord++){			//K1
						k1[i][coord]=vel_ovella[i][coord]*h;
					}
					
					for(int coord=0; coord<dim; coord++){			//L1
						l1[i][coord]=h*tancat(coord, pos_ovella[i][coord]);
					}
	
					for(int coord=0; coord<dim; coord++){			//K2
						k2[i][coord]=h*(vel_ovella[i][coord]+(1/2*l1[i][coord]));					
					}
					
					for(int coord=0; coord<dim; coord++){			//L2
						l2[i][coord]=h*tancat(coord, pos_ovella[i][coord]+(1/2)*k1[i][coord]);
					}																			
																			
					for(int coord=0; coord<dim; coord++){			//K3
						k3[i][coord]=h*(vel_ovella[i][coord]+((1/2)*l2[i][coord]));
					}
																
					for(int coord=0; coord<dim; coord++){			//L3
						l3[i][coord]=h*tancat(coord, pos_ovella[i][coord]+(1/2)*k2[i][coord]);
					}
	
					for(int coord=0; coord<dim; coord++){			//K4
						k4[i][coord]=h*(vel_ovella[i][coord]+(l3[i][coord]));
					}																				
			
					for(int coord=0; coord<dim; coord++){			//L4
						l4[i][coord]=h*tancat(coord, pos_ovella[i][coord]+k3[i][coord]);
					}
	
	
					for(int coord=0; coord<dim; coord++){												//CONTRIBUCIÓ DEL TANCAT
						pos_ovella2[i][coord]=pos_ovella2[i][coord]+(0.166666)*(k1[i][coord]+2*k2[i][coord]+2*k3[i][coord]+k4[i][coord]);			
						vel_ovella2[i][coord]=vel_ovella2[i][coord]+(0.166666)*(l1[i][coord]+2*l2[i][coord]+2*l3[i][coord]+l4[i][coord])/100;
					}
				}
		
				//RK GOS/////////////////////////////////////////////////
				for(int coord=0; coord<dim; coord++){			//K1
					k1[i][coord]=vel_ovella[i][coord]*h;
				}
				
				for(int coord=0; coord<dim; coord++){			//L1
					l1[i][coord]=h*gos(coord, pos_ovella[i][0], pos_ovella[i][1], pos_gos[0], pos_gos[1]);
				}

				for(int coord=0; coord<dim; coord++){			//K2
					k2[i][coord]=h*(vel_ovella[i][coord]+(1/2*l1[i][coord]));					
				}
				
				for(int coord=0; coord<dim; coord++){			//L2
					l2[i][coord]=h*gos(coord, pos_ovella[i][0]+(1/2)*k1[i][coord], pos_ovella[i][1]+(1/2)*k1[i][coord], pos_gos[0]+(1/2)*k1[i][coord], pos_gos[1]+(1/2)*k1[i][coord]);
				}																			
																		
				for(int coord=0; coord<dim; coord++){			//K3
					k3[i][coord]=h*(vel_ovella[i][coord]+((1/2)*l2[i][coord]));
				}
															
				for(int coord=0; coord<dim; coord++){			//L3
					l3[i][coord]=h*gos(coord, pos_ovella[i][0]+(1/2)*k2[i][coord], pos_ovella[i][1]+(1/2)*k2[i][coord], pos_gos[0]+(1/2)*k2[i][coord], pos_gos[1]+(1/2)*k2[i][coord]);
				}

				for(int coord=0; coord<dim; coord++){			//K4
					k4[i][coord]=h*(vel_ovella[i][coord]+(l3[i][coord]));
				}																				
		
				for(int coord=0; coord<dim; coord++){			//L4
					l4[i][coord]=h*gos(coord, pos_ovella[i][0]+k3[i][coord], pos_ovella[i][1]+k3[i][coord], pos_gos[0]+k3[i][coord], pos_gos[1]+k3[i][coord]);
				}


				for(int coord=0; coord<dim; coord++){												//CONTRIBUCIÓ DEL GOS
					pos_ovella2[i][coord]=pos_ovella2[i][coord]+(0.166666)*(k1[i][coord]+2*k2[i][coord]+2*k3[i][coord]+k4[i][coord]);			
					vel_ovella2[i][coord]=vel_ovella2[i][coord]+(0.166666)*(l1[i][coord]+2*l2[i][coord]+2*l3[i][coord]+l4[i][coord]);
				}
		
			}
			
				
		}

		for(int i=0; i<N_ovelles; i++){
			for(int coord=0; coord<dim; coord++){
				pos_ovella[i][coord]=pos_ovella2[i][coord];
				vel_ovella[i][coord]=vel_ovella2[i][coord];
			}
		}
		if(iteracio%20==0){
			sprintf(buffer, "posicions%d.txt", iteracio/20);	
			output=fopen(buffer, "w");
			for(int i=0; i<N_ovelles; i++)
			{
				double x=pos_ovella2[i][0];
				double y=pos_ovella2[i][1];
				fprintf(output, "%lf %lf\n", x, y);
			}
			fprintf(output, "%lf %lf\n", pos_gos[0], pos_gos[1]);
		}
		t+=h;
		iteracio++;
	}
}
