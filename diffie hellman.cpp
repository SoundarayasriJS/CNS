#include<stdio.h>
#include<math.h>
int main(){
	int q,alpha,Xa,Xb,Ya,Yb,Ka,Kb;
	printf("Enter prime no q:");
	scanf("%d",&q);
	printf("Enter primitive root:");
	scanf("%d",&alpha);
	//user A:
	printf("Enter Xa:");
	scanf("%d",&Xa);
	Ya=(alpha^Xa) %q;
	printf("The Ya values is:%d",Ya);
	//user :
	printf("Enter Xb:");
	scanf("%d",&Xb);
	Yb=(alpha^Xb)%q;
	printf("The Yb value is:%d",Yb);
	//keys
	Ka=(Yb^Xa)%q;
	Kb=(Ya^Xb)%q;
	printf("The key of User A is:%d",Ka);
	printf("The key of User B is:%d",Kb);
	return 0;
		
}



