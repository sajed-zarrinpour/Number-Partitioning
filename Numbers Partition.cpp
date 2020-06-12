#include<fstream>
#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

//sakhtare gereh
struct Node{
      std::string cnt;
      Node*  P;
      Node*  N;
      Node*  R;
      Node*  L;
}*Root;
std::string _INPUT;//used for stor the input number to used everywhere it need
//------------------------------------------------------------------------------
//-------------------------------- functions -----------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//get the first eleman of a partition
std::string get_first_eleman(std::string cnt);
//------------------------------------------------------------------------------
//tabee tashkhise jahate harkat
std::string GuessDirection (Node* p);
//------------------------------------------------------------------------------
//tabee sakht avalin efraze badihi
std::string CreateFirstPartion(int n);
//------------------------------------------------------------------------------
//shomarande tedade + ke dar taiine andaze araye voroodi be tabe split karbord dare
int PlusCounter(std::string my_string);
//------------------------------------
//shomareshe tadade yek haye dar mohtaviate
int OneCounter(std::string my_string);
//------------------------------------------------------------------------------
//joda konnande string
void split(std::string content,std::string buffer[],int n);
//------------------------------------------------------------------------------
//casting :
int str2num(std::string str);
//------------------------------------
std::string num2str(int cnt);
//------------------------------------------------------------------------------
//sakhte mohtaviate gereh
std::string CreateContent(std::string content,std::string direction);
//------------------------------------------------------------------------------
//modire daraje 1 tavabe
void Create(int n);
//------------------------------------
std::string Create_R_Content(std::string);
//------------------------------------
std::string Create_N_Content(std::string);
//------------------------------------------------------------------------------
//print for use in console
void Print(Node* p);
//------------------------------------------------------------------------------
//for create Log File
void WriteDetails(std::string filename,int n);
//##############################################################################
//--------------------------------    main   -----------------------------------
//##############################################################################
int main(){
 int n;char ch;
 _START :
 system("cls");
 cout<<"\n--------------------------      Numbers Pertition      -------------------------";
 cout<<"\n--------------------------    By : sajed zarrin pour   -------------------------";
 cout<<"\n----------------------------------      2015     -------------------------------";
 cout<<"\n--------------------------  Mail :samim56b@Gmail.com   -------------------------";
 cout<<"\n--------------------------------------------------------------------------------";
 cout<<"\nGive Me A Positive Integer Number \"Enter 0 To Exit\">\t";
 cin>>n;
 if(n<0)goto _START;
 if(!n)return 0;
 cout<<"\n--------------------------------------------------------------------------------";
 cout<<"\nDo You Want To Save Progress On Loge File ? y,n >\t";
 char c;
 c=_getch();
 if(c=='y' || c=='Y')WriteDetails(num2str(n),n);
 else if(c=='N' || c=='n'){
 cout<<"\n--------------------------------------------------------------------------------";
 cout<<"\n--------------------------------------------------------------------------------";
 cout<<"\nTechnical Viwe On Progress:\n";
 Create(n);
 cout<<"\n--------------------------------------------------------------------------------";  
 cout<<"\nGenerel View On Progress: (press any key to continue....>\n";
 _getch();
 Print(Root);
 cout<<"\n--------------------------------------------------------------------------------";
 }
 cout<<"\nDo You Want To Continue ? y/n>";
 ch= _getch();
 if (ch=='y' || ch=='Y')goto _START;
    return 0;
}
//##############################################################################
//--------------------------   get_first_eleman   ------------------------------
//##############################################################################
std::string get_first_eleman(std::string cnt){
     std::string buffer;
  int j=0;
  if(cnt.length()!=0){
            int i;
            for(i = 0; i < cnt.length(); (i++))
            {
                  if(cnt[i]==*"+")break;
            }
    //cout<<"index "<<index<<"\n";
    //cout<<"cnt.length "<<cnt.length()<<"\n";
     buffer=cnt.substr(0, i); 
     }
     return buffer;
}
//##############################################################################
//---------------------------   GuessDirection   -------------------------------
//##############################################################################
//tabee tashkhise jahate raft
std::string GuessDirection (Node* p){
            if(_INPUT!="1" && p->N==NULL && CreateContent(p->cnt,"N")!="null")/*if _INPUT==1 then we have some calc error unless if it happens we handele it manuali.as you see in the first phrase in thif conditional command,actuali it try to sum something with 1;becauase of that N is null and the function i build for move to front have no suitable thing for some string with just One 1,so we handle it manuali here*/
            return "N";
            else 
            if(_INPUT!="2" && p->R==NULL && CreateContent(p->cnt,"R")!="null")/*if _INPUT==2 then we have some calc error unless if it happens we handele it manuali.ass you see in the first phrase in thif conditional command,actauly that result will be 1+1,2 and we know the second phrase is not acceptable.so we handle that and so the out put will be just 1+1*/
            return "R"; 
            if(p->P!= NULL)
            return "P";
            else
            if(p->L!=NULL)
            return "L";
            else
            return "nonedirection";
}
//##############################################################################
//-------------------------   CreateFirstPartion   -----------------------------
//##############################################################################
//tabee sakht avalin efraze badihi
std::string CreateFirstPartion(int n){
  std::string p="";
  std::string s1="1+";
  std::string s2="1";
  for(int i=0;i<(n-1);i++)p=p+s1; 
    p=p+s2;
  return p;
}
//##############################################################################
//-----------------------------   PlusCounter   --------------------------------
//##############################################################################
//shomarande tedade + ke dar taiine andaze araye voroodi be tabe split karbord dare
int PlusCounter(std::string my_string){
    //const char* s=str.c_str();
    int counter=0;
    int i;
    for(i = 0; i < my_string.length(); (i++))
    {
          if(my_string[i]==*"+"){
          counter++;
          //cout<<my_string[i]<<"  "<<i<<"\n";
        }
    }
    return counter;
}
//##############################################################################
//-----------------------------   OneCounter   ---------------------------------
//##############################################################################
//shomareshe tadade yek haye dar mohtaviate
int OneCounter(std::string my_string){
    //const char* s=str.c_str();
    int counter=0;
    int i,index=0;
    int n=PlusCounter(my_string);++n;
    std::string p[n];
    split(my_string,p,n);
    for(i=0;i<n;i++){
     if(p[i]=="1")counter++;
    }           
    return counter;
}
//##############################################################################
//-------------------------------   split   ------------------------------------
//##############################################################################
//joda konnande string
void split(std::string content,std::string buffer[],int n){
  if (n==1) {
            buffer[0]=content;
            //cout<<"\nn=1;buffer[0]="<<buffer[0];
            return;
            }
  else{
  std::string cnt=content;
  int j=0;
  while(cnt.length()!=0){
            int i,index;
            for(i = 0; i < cnt.length(); (i++))
            {
                  if(cnt[i]==*"+")break;
                  index=i;
            }
    //cout<<"index "<<index<<"\n";
    //cout<<"cnt.length "<<cnt.length()<<"\n";
   if(cnt.length()!=1){
     buffer[j]=cnt.substr(0, ++index);
    //cout<<"buffer["<<j<<"] "<<buffer[j]<<"\n";
    cnt.erase(0, ++index);
    }else{
    buffer[j]=cnt;
    //cout<<"buffer["<<j<<"] "<<buffer[j]<<"\n";
    cnt.erase(0, cnt.length());
    }
    //cout<<"cnt "<<cnt<<"\n";
    ++j;
  }
}
}
//##############################################################################
//------------------------------   str2num   -----------------------------------
//##############################################################################
//casting :
int str2num(std::string str){
           int i,cnt=0;
            for(i = 0; i < str.length(); (i++))
            {
             cnt*=10;
            if(str[i]==*"1")cnt=cnt+1;
             else
              if(str[i]==*"2")cnt=cnt+2;
             else
              if(str[i]==*"3")cnt=cnt+3;
             else
              if(str[i]==*"4")cnt=cnt+4;
             else
              if(str[i]==*"5")cnt=cnt+5;
             else
              if(str[i]==*"6")cnt=cnt+6;
             else
              if(str[i]==*"7")cnt=cnt+7;
             else 
             if(str[i]==*"8")cnt=cnt+8;
             else 
             if(str[i]==*"9")cnt=cnt+9;
             else
              cnt=cnt+0;
            }
           // cout<<"num2str: "<<cnt;
            return cnt;
}
//##############################################################################
//------------------------------   num2str   -----------------------------------
//##############################################################################
std::string num2str(int cnt){
            std::string str="";
            int k=0;
            while(cnt/10!=0){
              k=cnt/10;
              cnt=cnt-k*10;
              switch(k){
               case 1:str=str+"1";break;
               case 2:str=str+"2";break;
               case 3:str=str+"3";break;
               case 4:str=str+"4";break;
               case 5:str=str+"5";break;
               case 6:str=str+"6";break;
               case 7:str=str+"7";break;
               case 8:str=str+"8";break;
               case 9:str=str+"9";break;
               case 0:str=str+"0";break;
               }
            }
            k=cnt%10;
             switch(k){
               case 1:str=str+"1";break;
               case 2:str=str+"2";break;
               case 3:str=str+"3";break;
               case 4:str=str+"4";break;
               case 5:str=str+"5";break;
               case 6:str=str+"6";break;
               case 7:str=str+"7";break;
               case 8:str=str+"8";break;
               case 9:str=str+"9";break;
               case 0:str=str+"0";break;
               }         
            return str;
}
//##############################################################################
//-------------------------   Create_R_Content   -------------------------------
//##############################################################################
//sakhte mohtaviate gereh
std::string Create_R_Content(std::string my_string){
            int _1_Count=OneCounter(my_string);
            if(_1_Count==1)return "null";
            else{
            int i,index=0;
            int n=PlusCounter(my_string);++n;
          // cout<<"n : "<<n<<"\n";
            std::string p[n];
            split(my_string,p,n);
            std::string res="";
            for(int i=0;i<n;i++){
              if(p[i]=="1")break;
              else {
                   res= res+ p[i]+"+";
                   ++index;
                   }
            }
           // cout<<"index "<<index<<"\n";
            res= res+ "2";
            for(int i=index+2;i<(n);i++){
                   res= res+ "+"+p[i];
            }
            //res= res+ p[n-1];
            //cout<<"\nfinal resualt : "<<res;
            return res;
            }
}
//##############################################################################
//-------------------------   Create_N_Content   -------------------------------
//##############################################################################

std::string Create_N_Content(std::string my_string){
        //cout<<"\n----------------"<<num2str(str2num(_INPUT)-1);
        
       if(get_first_eleman(my_string)==num2str(str2num(_INPUT)-1))return "null";
        else{
         int i,index=0;
            int n=PlusCounter(my_string);++n;
           //cout<<"n : "<<n<<"\n";
            std::string p[n];
            split(my_string,p,n);
            std::string res="";
            for(int i=0;i<n;i++){
              if(p[i+1]=="1")break;
              else {
                   res= res+ p[i]+"+";
                  // cout<<"\nfirst for; p["<<i<<"]="<<p[i];
                  //cout<<"\nfirst for; res "<<res;
                   ++index;
                   }
            }
            //cout<<"\nindex "<<index<<"\n";
            int a= str2num(p[index]);
            int b= str2num(p[++index]);
            //cout<<"\nindex "<<index<<"\n";
            int _J=index; 
                             --index;       
            res= res+ num2str(a+b);
            //cout<<"\n res "<<res;
            //cout<<"\n\ta+b:"<<a+b<<"\n\tp["<<index<<"]"<<p[0];

            if((a+b)>str2num(p[0])&&p[1]!="1")return "null";//tekrar
            if(index>0 && (a+b)>str2num(p[--index])&&p[1]!="1")return "null";//tekrar shart i
            ///cout<<"\nres+ num2str(++a) : "<<res;
            //cout<<"\n\tindex :"<<index;
            for(int i=++_J;i<(n);i++){
                   res= res+ "+"+p[i];
                   //cout<<"\nsecond for; p["<<i<<"]="<<p[i];
                  // cout<<"\nsecound for; res "<<res;
            }
            //res= res+ p[n-1];
            //cout<<"\nfinal resualt : "<<res;
            return res;
            }
}
//##############################################################################
//##############################################################################
  /*
  DERAKHT LKS 
  
  mavared ghabele tavajoh :
          
          1.agar be efraze n+0 reside bashim pas yek dar reshte mojod nist
            va chon in content gerehe badie pas return null
         
          2.age direction rast bashe rooye yekha zanjir misaze
            2.1.chek kardane dar mahdoode boodane majmoo
            2.2.check kardan rooye LKS
          
          3.age direction jelo bashe zanjir ro edame mide
            3.1.agar tedade yek haye baghimande baraye sakht zanjir yek bashad ya kamter retun null
            3.2.chek kardane dar mahdoode boodane majmoo
            3.3.check kardan rooye LKS
          tamame chizaii ke neveshti ro chek kon vase adade do raghami javab nemide
  */
//##############################################################################
//---------------------------   CreateContent   --------------------------------
//##############################################################################
std::string CreateContent(std::string content,std::string direction){
      if(OneCounter(content)==0) return "null";
      else{
        if(direction=="R"){
             return Create_R_Content(content);
        }//end procees froe r direction
        else{
             return Create_N_Content(content);
        }//end process of n direction
      }
}
//##############################################################################
//-----------------------------   Create   -------------------------------------
//##############################################################################
//modire daraje 1 tavabe
void Create(int n){
  _INPUT=num2str(n);
  std::string Fn=CreateFirstPartion(n);
  std::string D;//Direction
  Node* p=Root=new Node();
  p->cnt=Fn;
  p->N=p->L=p->R=p->P=NULL;//nothing exist in for direction right now
  Root=p;
  cout<<"\nDirecttion | Value";
  cout<<"\n----------- -------";
  cout<<"\n   Root    : "<<Root->cnt;
  do{
    //cout<<"EXEC WHILE";
    D=GuessDirection(p);
       if(D=="N"){
        std::string C=CreateContent(p->cnt,D);
        if(C!="null"){
         p->N=new Node();
         p->N->cnt=C;
         cout<<"\n   N       : "<<C;
         p->N->L=p->N->R=p->N->N=NULL;
         p->N->P=p;
         p=p->N;
         }
        }
        else
        if(D=="R"){
        std::string C=CreateContent(p->cnt,D);
        if(C!="null"){
         p->R=new Node();
         p->R->cnt=C;
         cout<<"\n   R       : "<<C;
         p->R->P=p->R->N=p->R->R=NULL;
         p->R->L=p;
         p=p->R;
         }
        }
        else
        if(D=="P"){
           cout<<"\n   P       |";
           p=p->P;
         }
         else
         if(D=="L"){
           cout<<"\n   L       |" ;       
           p=p->L;
         }      
    //cout<<"\np->cnt : "<<p->cnt;
  }while(p->cnt!=Fn);
}
//##############################################################################
//------------------------------   Print   -------------------------------------
//##############################################################################

//print for use in console
void Print(Node* p){
 cout<<"\n------------------\n"<<p->cnt;
 if (p->N!=NULL)Print(p->N);
 if (p->R!=NULL)Print(p->R);
}
//##############################################################################
//--------------------------   WriteDetails   ----------------------------------
//##############################################################################
void WriteDetails(std::string name,int n){
FILE* f;
std::string buff;
_INPUT=name;
name= name+ "PartitionLOG.txt";
ofstream out(name.c_str());
  buff="\n--------------------------      Numbers Pertition      -------------------------";
  out<<buff;
  buff="\n--------------------------    By : sajed zarrin pour   -------------------------";
  out<<buff;
  buff="\n----------------------------------      2015     -------------------------------";
  out<<buff;
  buff="\n--------------------------  Mail :samim56b@Gmail.com   -------------------------";
  out<<buff;
  buff="\n--------------------------------------------------------------------------------";
  out<<buff;
  out<<"\nNumber : "<<_INPUT;
  buff="\n--------------------------------------------------------------------------------";
  out<<buff;
  buff="\nTechnical Viwe On Progress:\n"; 
  out<<buff;
  buff="\n--------------------------------------------------------------------------------";
  out<<buff;
       _INPUT=num2str(n);
  std::string Fn=CreateFirstPartion(n);
  std::string D;//Direction
  Node* p=Root=new Node();
  p->cnt=Fn;
  p->N=p->L=p->R=p->P=NULL;//nothing exist in for direction right now
  Root=p;
  buff="\nDirecttion | Value";
  out<<buff;
  buff="\n----------- -------";
  out<<buff;
  buff="\n   Root    : "+Root->cnt;
  out<<buff;
  do{
    //cout<<"EXEC WHILE";
    D=GuessDirection(p);
       if(D=="N"){
        std::string C=CreateContent(p->cnt,D);
        if(C!="null"){
         p->N=new Node();
         p->N->cnt=C;
         buff="\n   N       : "+C;
         out<<buff;
         p->N->L=p->N->R=p->N->N=NULL;
         p->N->P=p;
         p=p->N;
         }
        }
        else
        if(D=="R"){
        std::string C=CreateContent(p->cnt,D);
        if(C!="null"){
         p->R=new Node();
         p->R->cnt=C;
         buff="\n   R       : " + C;
         out<<buff;
         p->R->P=p->R->N=p->R->R=NULL;
         p->R->L=p;
         p=p->R;
         }
        }
        else
        if(D=="P"){
           buff="\n   P       |";
           out<<buff;
           p=p->P;
         }
         else
         if(D=="L"){
           buff="\n   L       |" ; 
           out<<buff;     
           p=p->L;
         }      
    //cout<<"\np->cnt : "<<p->cnt;
  }while(p->cnt!=Fn);
  //	fwrite(&buff ,buff.size(),1,f);
  //tabeae fwrite(araye ii ke etelaatesho mikhaym save konim,mizane hafeze lazem vase har khoone araye,tedade khoone haii ke etelaateshoon to un hafeze mire,fili ke bayad roosh save anjam beshe)
	cout<<"\n>>Log Has Been Saved..\n";
	return;
}




















