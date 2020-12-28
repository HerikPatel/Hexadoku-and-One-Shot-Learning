#include<stdio.h>
#include<stdlib.h>
void showmatrixx();
int ansr;
int ansc;
//char* temp_arr;
char temparr[16];
char** matrixx;
int temparray();
char arr[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int arr2[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void resetarr2()
{
for(int i=0;i<16;i++)
{
  arr2[i]=0;}
  for(int i=0;i<16;i++)
  {
    temparr[i]=-1;}
}
void changepositionintemparr(int index)
{
for(int i=index;i<15;i++)
{
  temparr[i]=temparr[i+1];
}
}
char** allocate_matrix(int rows, int cols){
  char** ret_val = malloc(rows * sizeof(char*));
  for(int i = 0; i< rows; i++){
    ret_val[i] = malloc(cols * sizeof(char));
  }
  return ret_val;
}

void checkelement(int a,int b)  // takes row and column from original matrixx where element is to be inserted;
{
  int j=0;
  for(int i=0;i<16;i++)
  {
    while(matrixx[a][i]!=arr[j])
    {
      if(j==15)
      {
        break;
      }
      j++;
    }
    if(matrixx[a][i]==arr[j])
    {
      arr2[j]=1;
    }
    j=0;
  }
  temparray();
}

int temparray()
{int temp=0;
  int count=1;
  /*for(int i=0;i<16;i++)
  {
    if(arr2[i]==0)
    {
      count++;
    }
  }*/
  for(int j=0;j<16;j++)
  {
    if(arr2[j]==0)
    {
      temparr[temp]=arr[j];
      temparr[temp+1]=-1;
      temp++;
    }

  }
  return count;
}
void checkvalidity()
{
  int sum=0;
for(int i=0;i<16;i++)
{
  for(int j=0; j<16;j++)
  {
    if(matrixx[i][j]=='A')
    {
      sum=sum+10;
    }
  else  if(matrixx[i][j]=='B')
    {
      sum=sum+11;
    }
    else if(matrixx[i][j]=='C')
    {
      sum=sum+12;
    }
  else  if(matrixx[i][j]=='D')
    {
      sum=sum+13;
    }
  else  if(matrixx[i][j]=='E')
    {
      sum=sum+14;
    }
    else if(matrixx[i][j]=='F')
    {
      sum=sum+15;
    }
    else  if(matrixx[i][j]=='0')
      {
        sum=sum+0;
      }
      else if(matrixx[i][j]=='1')
      {
        sum=sum+1;
      }
    else  if(matrixx[i][j]=='2')
      {
        sum=sum+2;
      }
      else if(matrixx[i][j]=='3')
      {
        sum=sum+3;
      }
    else  if(matrixx[i][j]=='4')
      {
        sum=sum+4;
      }
    else  if(matrixx[i][j]=='5')
      {
        sum=sum+5;
      }
      else if(matrixx[i][j]=='6')
      {
        sum=sum+6;
      }
      else  if(matrixx[i][j]=='7')
        {
          sum=sum+7;
        }
        else if(matrixx[i][j]=='8')
        {
          sum=sum+8;
        }
        else if(matrixx[i][j]=='9')
        {
          sum=sum+9;
        }
  }
  if(sum!=120)
  {
    printf("no-solution");
    return;
  }
  else{sum=0;}
}
showmatrixx();
}
void checksubmat(int ar,int b,int c ,int d, int row)
{
 //int ar2=0,b2=0,c2=0,d2=0,row2=0; ar2=ar;b2=b;c2=c;d2=d;row2=row;
  int ct=0;
  int dup2=0;
  int dup3;//,dup4;
  int count=0;
  //  int dup=0;
    ac :
  //int temp2;

  //temp2= temp_arr();
for(int i=c;i<ar;i++)// this is for checking if the element in the submatrix is not repeating itself
{
  for(int j=d;j<b;j++)
  {
    if(matrixx[i][j]==temparr[ct])
    {
      ct++;
      i=c;                          // to start to compare elements of submatrix from begining
      j=d;
    }
  }
}
for(int x=0;x<16;x++){
if(matrixx[row][x]=='-')
{
  while(temparr[ct]!=-1)
  {
    for(int i=0;i<16;i++)
    {
      if(matrixx[row][i]==temparr[ct])
      {
        ct++;
        goto ac;
      }
    }
    for(int j=0;j<16;j++)
    {
      if(matrixx[j][x]==temparr[ct])
      {
        ct++;
        goto ac;
      }

    }
    if(count==0){
    dup3=temparr[ct];}
    ct++;
    count++;
    dup2++;
  }

if(count==1)
{
matrixx[row][x]=dup3;
count=0;
}
}
}
}
void addelement()
{
for(int i=0;i<16;i++)
{
  for(int j=0;j<16;j++)
  {
    if(i<4&&j<4)
    {// BRAINSTORMING ANOTHER ARRAY CAN BE USED TO PUT VALUES WHICH CAN BE POTENIALLY BE PRESENT WHILE CHECKING SUBMATRIX
      checkelement(i,j);
      checksubmat(4,4,0,0,i);
    }else if(i<4&&j<8)
    {
    checkelement(i,j);
    checksubmat(4,8,0,4,i);
    }
   else if(i<4&&j<12)
    {
    checkelement(i,j);
    checksubmat(4,12,0,8,i);
  }
     else if(i<4&&j<16)
    {
    checkelement(i,j);
    checksubmat(4,16,0,12,i);
  }
    else if(i<8&&j<4)
    {
    checkelement(i,j);
    checksubmat(8,4,4,0,i);
    }
    else if(i<8&&j<8)
    {
    checkelement(i,j);
    checksubmat(8,8,4,4,i);
    }
    else if(i<8&&j<12)
    {
    checkelement(i,j);
    checksubmat(8,12,4,8,i);
    }
    else if(i<8&&j<16)
    {
    checkelement(i,j);
    checksubmat(8,16,4,12,i);
    }
    else if(i<12&&j<4)
    {
    checkelement(i,j);
    checksubmat(12,4,8,0,i);
    }
    else if(i<12&&j<8)
    {
    checkelement(i,j);
    checksubmat(12,8,8,4,i);
    }
    else if(i<12&&j<12)
    {
    checkelement(i,j);
    checksubmat(12,12,8,8,i);
    }
    else if(i<12&&j<16)
    {
    checkelement(i,j);
    checksubmat(12,16,8,12,i);
    }
    else if(i<16&&j<4)
    {
    checkelement(i,j);
    checksubmat(16,4,12,0,i);
    }
    else if(i<16&&j<8)
    {
    checkelement(i,j);
    checksubmat(16,8,12,4,i);
    }
    else if(i<16&&j<12)
    {
    checkelement(i,j);
    checksubmat(16,12,12,8,i);
    }
    else if(i<16&&j<16)
    {
    checkelement(i,j);
    checksubmat(16,16,12,12,i);
  }
  }
  resetarr2();
}

}
void showmatrixx()
{
  for (  int g=0;g<16;g++) {
    for(int h=0;h<16;h++)
    {
      printf("%c\t",matrixx[g][h]);
    }
    printf("\n");
  }
}
int main(int argc, char** argv){

char c;
int count=1;
int ct=0;
FILE* fp =fopen(argv[1],"r");

while(fscanf(fp,"%c\t",&c)!=EOF)
    {
      matrixx=allocate_matrix(16,16);
      for(int i=0;i<16;i++)
      {
        for(int j=0;j<16;j++)
      {
        matrixx[i][j]=c;
      fscanf(fp,"%c\t",&c);
      }
      ct++;
      }
      count ++;
      ct=0;
    }
    fclose(fp);

for(int i=0;i<10;i++){
addelement();
}
//checkvalidity();
showmatrixx();
return 0;
}
