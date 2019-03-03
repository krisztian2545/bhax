#include <stdio.h>
#include <math.h>

#define DAMPING 0.0000000001

/*double distance(double*,double*, int);
void printArray(double*, int, char*);

void calculatePageRank(double[4][4], char*);*/

double distance(double* arr1 ,double* arr2, int length)
{
    double dis = 0;
    
    for(int i=0; i<length; i++)
    {
        dis += (arr2[i] - arr1[i])*(arr2[i] - arr1[i]);
    }
    
    return sqrt(dis);
    
    
}
void printArray(double* arr, int length, char* msg)
{
    printf("%s\n", msg);
    
    for(int i=0; i<length; i++)
    {
        printf("%f\n", arr[i]);
    }
    
}
void calculatePageRank(double linkData[4][4], char* msg)
{
    double pageRanks[4] = {0.0,0.0,0.0,0.0};
    double initPageRanks[4]  = {1.0/4.0, 1.0/4.0, 1.0/4.0, 1.0/4.0};
    
    for(;;)
    {
        for(int i=0; i<4; i++)
        {
            pageRanks[i] = 0.0;
            for(int j=0; j<4; j++)
            {
                pageRanks[i] += linkData[i][j] * initPageRanks[j]; //matrix mul
            }
        }
        
        if(distance(pageRanks,initPageRanks,4) < DAMPING)
            break;
        
        for(int i=0; i<4; i++)
            initPageRanks[i] = pageRanks[i];
    }
    
    printArray(pageRanks, 4, msg);
    
    
}


int main()
{
    
    double linkData[4][4]  = 
    {
        {0.0,  0.0,      1.0/3.0,  0.0},
		{1.0,  1.0/2.0,  1.0/3.0,  1.0},
		{0.0,  1.0/2.0,  0.0,      0.0},
		{0.0,  0.0, 	 1.0/3.0,  0.0}
    };
    
    double linkDataIsolatedCase[4][4] = {
		{0.0,  0.0,      1.0/3.0,  0.0},
		{1.0,  1.0/2.0,  1.0/3.0,  0.0},
		{0.0,  1.0/2.0,  0.0,      0.0},
		{0.0,  0.0, 	 1.0/3.0,  0.0}
	};
	
	double linkDataSelfCase[4][4] = {
		{0.0,  0.0,      1.0/3.0,  0.0},
		{1.0,  1.0/2.0,  1.0/3.0,  0.0},
		{0.0,  1.0/2.0,  0.0,      0.0},
		{0.0,  0.0, 	 1.0/3.0,  1.0}
	};
    
    
    
    calculatePageRank(linkData, "A 4 lap pagerank értékei:");
    calculatePageRank(linkDataIsolatedCase, "A 4 lap pagerank értékei, de egyik nem mutat senkire:");
    calculatePageRank(linkDataSelfCase, "A 4 lap pagerank értékei, de egyik csak önmagára mutat:");
    
    return 0;
}

