//ThangNN - chuong trinh nguon tao tu luong vao ra chuan
#include<bits/stdc++.h>
#include <windows.h>
#include <direct.h>
#define int long long
using namespace std;
ofstream fo;
ifstream fi;
char Name_file[] = "BAI01";
char exe_file[100] = "";
char inp_file[100] = "";
char out_file[100] = "";
string folder = "TestXX"; //XX will change value during running test

void Rename_file(int test)
{
  folder[4] = test/10 + 48;  //tao ten cuoi cho folder tu 00-->99
  folder[5] = test%10 + 48;
  mkdir(&folder[0]);
  string output_path = folder + "\\" + inp_file;
  CopyFile(inp_file, &output_path[0], false);
  output_path = folder + "\\" + out_file;
  CopyFile(out_file, &output_path[0], false);
}
void Make_file_name()
{
  strcpy(exe_file,Name_file);
  strcpy(inp_file,Name_file);
  strcpy(out_file,Name_file);
  strcat(exe_file,".exe");
  strcat(inp_file,".inp");
  strcat(out_file,".out");
}
bool ktcp(int n)
{
  if(n==round(sqrt(n))*round(sqrt(n)))
    return 1;
  else
    return 0;
}
int tong(int n)
{
  int cnt=0;
  while(n>0)
  {
    cnt=cnt+n%10;
    n=n/10;
  }
  return cnt;
}
int dem=21;  //test dau tien la dem=1
void make_sub(int cnt, int LOW, int HIGH)    //tao bo test cho sub có cnt test, gioi han trong tu LOW den HIGH
{
  int step=(HIGH-LOW)/cnt,n;
  for(int i=0; i<cnt; i++,dem++)
  {
    fo.open(inp_file);  //tao test
    n=LOW+i*step;
    n=n+rand()%n;
//    for(int j=1; j<=1000; j++)
//    {
//      int m=tong(n+j);
//      if(ktcp(m))
//      {
//        n=n+j;
//        break;
//      }
//    }
    fo<<n<<endl;
    fo.close();
    //tao file ket qua
    freopen(inp_file,"r",stdin);
    freopen(out_file,"w",stdout);
    system(exe_file);
    //Xoa file
    Rename_file(dem); //Luu lai file ket qua
  }
}

main()
{
  srand(time(NULL));
  Make_file_name();
  make_sub(20,1000000,1000000000000000);
//  make_sub(12,10000,100000);
  DeleteFile(inp_file);
  DeleteFile(out_file);
  return 0;
}
