#include<stdio.h>

int main()
{
	FILE *ip;
	FILE *op;
	int max=0;
	double average=0;
	
	/*open the input file get the data from the input file and compute the total and average it, then close the file*/
	ip=fopen("file_input_WK4.txt", "r");
	/*create a output file as given in the requirement and store max and average valuve computed from the input file, then close the file pointer*/
	op = fopen("answer-hw3.txt", "w");
	if( (ip != NULL) &&  (op != NULL))
	{
		int size;
		fscanf(ip, "%d", &size);
		int data[size];
		while(size!=0)
		{
			fscanf(ip, "%d", &data[size]);
			printf("Value of n=%d\n", data[size]);
			fprintf(op, "%d\t", data[size]);
			average+=data[size];
			if (max < data[size])
			{
				max = data[size];
			}
			size--;
		}
		rewind(ip);
		fscanf(ip, "%d", &size);
		average=average/size;	}
	fclose(ip);
	
	printf("max =%d\n", max);
	printf("average of n=%lf\n", average);
	fprintf(op, "%d\t%lf", max, average);
	fclose(op);
	
	return 0;
}
