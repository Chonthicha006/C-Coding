#include<stdio.h>
#include<conio.h>
#include<math.h>

void display(float x[101],float y[101],int n);
float mean(float x[101],int n);
float cov(float x[101],float y[101],int n);

int main()
	{	int i,n,N=0,flag;
		float x[101],y[101],x_mean,y_mean,cov_xx,cov_xy,a,b;
		FILE *fp;
		fp = fopen("DATA.text","r");
  		for(i=1;;i++)
		{	printf("x[%d]= ",i);
			scanf("%f",&x[i]);
			if(x[i]<=0)break;
		}
		n = i-1;
        printf("\n");
		for(i=1;;i++)
		{	
            printf("y[%d]= ",i);
			scanf("%f",&y[i]);
			if(y[i]<=0)break;
		}
		
		fclose(fp);
		display(x,y,n);
		x_mean = mean(x,n);
		y_mean = mean(y,n);
		cov_xx = cov(x,x,n);
		cov_xy = cov(x,y,n);
		a = cov_xy/cov_xx;
		b = y_mean - a*x_mean;
		printf("Linear regression by least square method is : y = ax + b\n");
		printf("\t=> a = %15.10f\n",a);
		printf("\t=> b = %15.10f\n",b);
		fp = fopen("RESULT.txt","w");
		fprintf(fp,"Linear regression by least square method is : y = ax + b\n");
		fprintf(fp,"\t=> a = %15.1f\n",a);
		fprintf(fp,"\t=> b = %15.1f\n",b);
		fclose(fp);					
		getch();
		return 0;
	}
	
void display(float x[101],float y[101],int n)
	{	int i;
		for(i=1;i<=n;i++)
			printf("x[%3d] = %10.4f\ty[%3d] = %10.4f\n",i,x[i],i,y[i]);
	}
	
float mean(float x[101],int n)
	{	int i;
		float sum=0,mean_value;
		
		for(i=1;i<=n;i++)
			sum = sum + x[i];
		mean_value = sum/n;
		return mean_value;
	}
	
float cov(float x[101],float y[101],int n)
	{	int i;
		float sum = 0,mean_1,mean_2,cov_value;
		
		mean_1 = mean(x,n);
		mean_2 = mean(y,n);
		for(i=1;i<n;i++)
			sum = sum + (mean_1 - x[i])*(mean_2 - y[i]);
		cov_value = sum/n;
		return cov_value;
	}
