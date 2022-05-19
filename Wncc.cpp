#include<fstream>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
void Sort(int a[], int n,int b[]) {
  int i, j, min, dummy,temp;
 for (i=0;i<n-1; i++) {
 min=i;
 for(j = i + 1; j < n; j++)
 if(a[j]<a[min])
 min=j;
 temp=b[i];
 dummy= a[i];
 a[i]=a[min];
 a[min]=dummy;
  b[i]=b[min];
  b[min]=temp; }}

void Sort1(int a[], int n,int b[]) {
int temp;
  for(int i=0;i<n;i++)
  {if( (b[i]==b[i+1]) && (a[i]>a[i+1]) )
  {temp=a[i];
   a[i]=a[i+1];
   a[i+1]=temp;}}}

int main(){
int ses=0;
int start_time[22];
int dur[22]; int arr[22];
int p=0;
fstream f1;
f1.open("schedule.txt");
string line;
vector<string> lines;
if(f1.is_open())
{while(f1){
getline(f1,line);
lines.push_back(line);
start_time[p]=(line[5]-48)*10+(line[6]-48);
dur[p]=line[8]-48;
p++;}}
int end_time[22];
for(int i=0;i<22;i++)
{end_time[i]=start_time[i]+dur[i];}
Sort(start_time,22,end_time);
Sort1(start_time,22,end_time);
int max=end_time[0];
for(int i=0;i<22;i++)
{if(end_time[i+1]>max)
{
arr[ses]=i;
max=end_time[i+1];
ses++;
}}
for(int i=0;i<22;i++){cout<<start_time[i]<<" "<<end_time[i]<<endl;}
if(end_time[21]>end_time[20]){arr[ses]=21;ses++;}
int no_of_ses=ses;
cout<<no_of_ses<<endl;}

