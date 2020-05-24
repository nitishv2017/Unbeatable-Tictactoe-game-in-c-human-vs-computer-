#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define forr(i,n) for(ll i=0;i<n;i++)
#define fora(i,a,b) for(ll i=a;i<b;i++)
#define inp(a,n) for(ll i=0;i<n;i++) cin>>a[i]
#define out(a,n) for(ll i=0;i<n;i++) cout<<a[i]<<" "
#define test ll t; cin>>t;while(t--)
ll maxm(ll a,ll b)
{
if(a>=b)
return a;
return b;
}

ll minm(ll a,ll b)
{
if(a<=b)
return a;
return b;
}

struct place
{
ll r;
ll c;
};
char c='C',h='H';

bool iml(char a[3][3])
{
fora(i,0,3)
{
	fora(j,0,3)
	{
	if(a[i][j]==c || a[i][j]==h);
	else return true;  
	}

}
return false;
}


ll evaluate(char a[3][3])
{
fora(i,0,3)
{
if(a[i][0]==a[i][1] && a[i][1]==a[i][2])
{
if(a[i][0]==c)
return 10;
else if(a[i][0]==h)
return -10;
}
}

fora(i,0,3)
{
if(a[0][i]==a[1][i] && a[1][i]==a[2][i])
{
if(a[0][i]==c)
return 10;
else if(a[0][i]==h)
return -10;
}
}

if(a[0][0]==a[1][1] && a[1][1]==a[2][2])
{
if(a[0][0]==c)
return 10;
else if(a[0][0]==h)
return -10; 
}

if(a[1][1]==a[0][2] && a[1][1]==a[2][0])
{
if(a[1][1]==c)
return 10;
else if(a[1][1]==h)
return -10;
}

return 0;
}

ll minimax(char a[3][3],ll depth,bool iscomp)
{
char temp;
ll score=evaluate(a);

if(score==10 || score==-10)
return score;

if(iml(a)==false)
return 0;

if(iscomp)
{
ll b=-1000;
	
fora(i,0,3)
{
	fora(j,0,3)
	{
	if(a[i][j]==c || a[i][j]==h);
	else{
	temp=a[i][j];
	a[i][j]=c;
	
	b=maxm(b,minimax(a,depth+1,!iscomp));	
	a[i][j]=temp;	
	}	 

	}

}
return b-depth;

}
else
{
ll b=1000;
char temp;	
fora(i,0,3)
{
	fora(j,0,3)
	{
	if(a[i][j]==c || a[i][j]==h);
	else{
	temp=a[i][j];
	a[i][j]=h;
	
	b=minm(b,minimax(a,depth+1,!iscomp));	
	a[i][j]=temp;	
	}	 

	}

}
return b+depth;

}

}

place findbest(char a[3][3])
{
ll b=-1000,value;
place bestmove;
bestmove.r=-1;
bestmove.c=-1;
fora(i,0,3)
{
	fora(j,0,3)
	{
	if(a[i][j]==c || a[i][j]==h);
	else
	{
		char temp=a[i][j];
		a[i][j]=c;
		value=minimax(a,0,false);	
		a[i][j]=temp;	
			 
		if(value>b)
		{
		b=value;
		bestmove.r=i;
		bestmove.c=j;
		}
	}
	}

}

return bestmove;
}



int main()
{
cout<<"README : While playing you have to choose the place value where you want your mark(H=HUMAN or C=COMPUTER) to be placed."<<endl;
ll y=0,z=0,g=0;
cout<<"ENTER TOTAL ROUNDS TO BE PLAYED : ";
test
{
if(g==1)
{cout<<"NEXT ROUND"<<"\n";}
place bestmove;
set<char>s1;
ll n=0,m=1,i,j,x,X,Y,flag=0,k=1;
char a[3][3];
ll s;

a[0][0]='1';
a[0][1]='2';
a[0][2]='3';
a[1][0]='4';
a[1][1]='5';
a[1][2]='6';
a[2][0]='7';
a[2][1]='8';
a[2][2]='9';
fora(i,0,3)
{
fora(j,0,3)
{
cout<<a[i][j]<<" ";
}
cout<<endl;

}
while(k<10)
{
cout<<"Your chance : ";
cin>>s;
while(1)
{
if(s1.find(s)==s1.end())
{s1.insert(s);break;}
else
{
cout<<"Invalid Move"<<endl;
cout<<"Your Move : ";
cin>>s;
}
}
switch(s)
{
case 1:a[0][0]=h;X=0;Y=0;break;
case 2: a[0][1]=h;X=0;Y=1;break;
case 3: a[0][2]=h;X=0;Y=2;break;
case 4:a[1][0]=h;X=1;Y=0;break;
case 5: a[1][1]=h;X=1;Y=1;break;
case 6: a[1][2]=h;X=1;Y=2;break;
case 7: a[2][0]=h;X=2;Y=0;break;
case 8: a[2][1]=h;X=2;Y=1;break;
case 9: a[2][2]=h;X=2;Y=2;break;

}
if(evaluate(a)==-10)
{cout<<"YOU WIN THIS ROUND"<<"\n";y++;break;}
else if(evaluate(a)==10)
{cout<<"YOU LOSE THIS ROUND"<<"\n";z++;break;}
flag=0;
fora(i,0,3)
{
fora(j,0,3)
{
if(a[i][j]==c || a[i][j]==h)
flag++;
}
}
if(flag==9 )
{cout<<"ITS A DRAW IN THIS ROUND"<<"\n";break;}
if(iml(a)==false)
break;
bestmove=findbest(a);
s1.insert(a[bestmove.r][bestmove.c]-'0');
a[bestmove.r][bestmove.c]=c;

fora(i,0,3)
{
fora(j,0,3)
{
cout<<a[i][j]<<" ";
}
cout<<endl;

}
if(evaluate(a)==-10)
{cout<<"YOU WIN THIS ROUND"<<"\n";y++;break;}
else if(evaluate(a)==10)
{cout<<"YOU LOSE THIS ROUND"<<"\n";z++;break;}
flag=0;
fora(i,0,3)
{
fora(j,0,3)
{
if(a[i][j]==c || a[i][j]==h)
flag++;
}
}
if(flag==9 )
{cout<<"ITS A DRAW IN THIS ROUND"<<"\n";break;}
if(iml(a)==false)
break;
k++;
}
g=1;
}
if(y>z)
cout<<"!!!YOU WON THE TOURNAMENT!!!"<<endl<<"WINNER WINNER CHICKEN DINNER"<<endl;
if(y<z)
cout<<"!!!YOU LOSE THE TOURNAMENT!!!"<<endl<<"BETTER LUCK NEXT TIME MOTHERFUCKER"<<endl;
if(y==z)
cout<<"!!!ITS A DRAW!!! AUKAAD H TO JEET KE BATA"<<endl;
return 0;
}
