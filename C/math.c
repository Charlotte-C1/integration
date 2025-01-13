/****** Module manipulant des fonctions mathématiques **********/
#include "math.h"

/****************** Recherche du maximum ***********************/
float maximum (float n1, float n2 )
{
   float max ;
   if (n1 > n2){
	   max= n1;}
   else{ max = n2;}
   return max;
}

/****************** Recherche du minimum ***********************/
float minimum (float n1, float n2 )
{
   float min ;
   if (n1 > n2){
	   min= n2;}
   else{ min = n1;}
   return min;
}

/******************* Addition de nombres ***********************/
float addition (float n1, float n2 )
{
   float add = n1 + n2;
   return add;
}

