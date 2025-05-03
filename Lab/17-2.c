#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef struct employ{
 int id;
 char name[100];
 int age;
 float sal;
}employ;
void highsal(employ *p,int n){
    float max = INT_MIN;
    int m;
    for(int i =0;i<n;i++){
      if(((p+i) -> sal) > max ){
         max = (p+i) -> sal;
         m = i;
      }
    }
    printf("Employee with highest salary ->");
    printf(" Id : %d\n",(p + m) -> id);
    printf("Name : ");
    puts((p+m) -> name );
    printf("age : %d\n",(p + m) -> age);
    printf("salary : %f\n",(p + m) -> sal);
    printf("\n");
}
void agesort(employ *p,int n){
    int arr[n][2];
    for(int i =0;i<n;i++){
       arr[i][1] = (p+i) -> age;
       arr[i][2] = i;
    }
    int temp,t;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][1] < arr[j][1]){
              t = arr[i][1];
                arr[i][1] = arr[j][1];
                arr[j][1] = t;
                temp = arr[i][2];
                arr[i][2] = arr[j][2];
                arr[j][2] = temp;
            }
        }
    }
    for(int k = 0;k<n;k++){
        printf(" Id : %d\n",(p + arr[k][2]) -> id);
    printf("Name : ");
    puts((p+arr[k][2]) -> name );
    printf("age : %d\n",(p + arr[k][2]) -> age);
    printf("salary : %f\n",(p + arr[k][2]) -> sal);
    printf("\n");
    }
}
int main(){
int n;
printf("Enter the no.of employees -> ");
scanf("%d",&n);
employ *p = (employ*)malloc(n*sizeof(employ));
for(int i=0;i<n;i++){
    printf("Id of employee %d -> ",i+1);
    scanf("%d",&(p+i) -> id);
    printf("Name of the employee %d -> ",i+1);
    scanf(" %[^\n]", (p+i) -> name);
    printf("Age of the employee %d -> ",i+1);
    scanf("%d",&(p+i) -> age);
    printf("Salary of the employee %d -> ",i+1);
    scanf("%f",&(p+i) -> sal);
    while(getchar() != '\n');
    while(getchar() != '\n'); 
}
highsal(p,n);
agesort(p,n);
return 0;
}