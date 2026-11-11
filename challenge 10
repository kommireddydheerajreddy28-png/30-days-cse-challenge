#include <stdio.h>

#define Z 5
#define D 7

float t[Z][D], h[Z][D], a[Z][D];
float at[Z], ah[Z], aa[Z], gi[Z];
int risk[Z], ready = 0;

void inputData() {
    int i, j;
    for(i=0;i<Z;i++) {
        printf("\nZone %d\n",i+1);
        for(j=0;j<D;j++) {
            printf("Enter Temp, Humidity, AQI: ");
            scanf("%f%f%f",&t[i][j],&h[i][j],&a[i][j]);
            if(t[i][j]<10 || t[i][j]>50 ||
               h[i][j]<0 || h[i][j]>100 ||
               a[i][j]<0 || a[i][j]>500) {
                printf("Invalid! Enter again.\n");
                j--;
            }
        }
    }
    ready=1;
}

void calculateAverages() {
    int i,j;
    for(i=0;i<Z;i++) {
        at[i]=ah[i]=aa[i]=0;
        for(j=0;j<D;j++) {
            at[i]+=t[i][j];
            ah[i]+=h[i][j];
            aa[i]+=a[i][j];
        }
        at[i]/=D;
        ah[i]/=D;
        aa[i]/=D;
    }
}

void detectRiskDays() {
    int i,j;
    for(i=0;i<Z;i++) {
        risk[i]=0;
        for(j=0;j<D;j++)
            if(a[i][j]>150 || t[i][j]>35 || h[i][j]>80)
                risk[i]++;
    }
}

void computeGreenIndex() {
    int i;
    float x,y,z;
    for(i=0;i<Z;i++) {
        x=100-aa[i]/5;
        y=100-4*(at[i]>25?at[i]-25:25-at[i]);
        z=100-2*(ah[i]>50?ah[i]-50:50-ah[i]);

        if(x<0) x=0;
        if(y<0) y=0;
        if(z<0) z=0;

        gi[i]=0.4*x+0.3*y+0.3*z;
    }
}

void displayData() {
    int i,j;
    for(i=0;i<Z;i++) {
        printf("\nZone %d\n",i+1);
        for(j=0;j<D;j++)
            printf("%.1f %.1f %.1f\n",t[i][j],h[i][j],a[i][j]);
    }
}

void displayRanking() {
    int i,j,k,rank[Z]={1,2,3,4,5};
    for(i=0;i<Z;i++)
        for(j=i+1;j<Z;j++)
            if(gi[rank[j]-1]>gi[rank[i]-1]) {
                k=rank[i]; rank[i]=rank[j]; rank[j]=k;
            }

    for(i=0;i<Z;i++)
        printf("\nRank %d: Zone %d (%.2f)",
               i+1,rank[i],gi[rank[i]-1]);
}

void displayRecommendations() {
    int i;
    for(i=0;i<Z;i++) {
        printf("\nZone %d: ",i+1);
        if(aa[i]>150)
            printf("Reduce vehicle emissions. ");
        if(at[i]>35)
            printf("Provide shade and greenery. ");
        if(ah[i]>80)
            printf("Improve ventilation. ");
        if(risk[i]==0)
            printf("Continue monitoring.");
        printf(" Risk days: %d\n",risk[i]);
    }
}

int main() {
    int ch;
    do {
        printf("\n1.Input Data\n2.Display Data");
        printf("\n3.Averages\n4.Risk Days");
        printf("\n5.Green Index and Ranking");
        printf("\n6.Recommendations\n7.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        if(ch==1) inputData();
        else if(ch>=2 && ch<=6 && !ready)
            printf("Enter data first!\n");
        else if(ch==2) displayData();
        else if(ch==3) {
            calculateAverages();
            for(int i=0;i<Z;i++)
                printf("\nZone %d: %.2f %.2f %.2f",
                i+1,at[i],ah[i],aa[i]);
        }
        else if(ch==4) {
            detectRiskDays();
            for(int i=0;i<Z;i++)
                printf("\nZone %d: %d risk days",i+1,risk[i]);
        }
        else if(ch==5) {
            calculateAverages();
            computeGreenIndex();
            displayRanking();
        }
        else if(ch==6) {
            calculateAverages();
            detectRiskDays();
            displayRecommendations();
        }
        else if(ch==7) printf("Exit");
        else printf("Invalid choice");

    } while(ch!=7);

    return 0;
}
