#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int k=0;k<n;k++)
	{
		int a[11];
		int length=0;
		int min=100;
		for(int i=0;i<10;i++)
		{
			int temp;
			cin>>temp;
			a[temp]=i;
		}
		for(int j0=1;j0<10;j0++)
		{
			int p0=a[j0];
			int t0=abs(a[j0+1]-a[j0]);
			length+=t0;
			//cout<<"length0="<<length<<endl;
			a[j0]=a[j0+1];
			for(int j1=1;j1<10;j1++)
			if(j1!=j0)
			{
				int p1=a[j1];
				int t1=abs(a[j1+1]-a[j1]);
				length+=t1;
				cout<<"length1="<<length<<endl;
				a[j1]=a[j1+1];
				for(int j2=1;j2<10;j2++)
				if(j2!=j1&&j2!=j0)
				{
					int p2=a[j2];
					int t2=abs(a[j2+1]-a[j2]);
					length+=t2;
					cout<<"length2="<<length<<endl;
					a[j2]=a[j2+1];
					for(int j3=1;j3<10;j3++)
					if(j3!=j2&&j3!=j1&&j3!=j0)
					{
						int p3=a[j3];
						int t3=abs(a[j3+1]-a[j3]);
						length+=t3;
						cout<<"length3="<<length<<endl;
						a[j3]=a[j3+1];
						for(int j4=1;j4<10;j4++)
						if(j4!=j0&&j4!=j1&&j4!=j2&&j4!=j3)
						{
							int p4=a[j4];
							int t4=abs(a[j4+1]-a[j4]);
							length+=t4;
							cout<<"length4="<<length<<endl;
							a[j4]=a[j4+1];
							for(int j5=1;j5<10;j5++)
							if(j5!=j1&&j5!=j0&&j5!=j3&&j5!=j2&&j5!=j4)
							{
								int p5=a[j5];
								int t5=abs(a[j5+1]-a[j5]);
								length+=t5;
								cout<<"length5="<<length<<endl;
								a[j5]=a[j5+1];
								for(int j6=1;j6<10;j6++)
								if(j6!=j5&&j6!=j4&&j6!=j3&&j6!=j2&&j6!=j1&&j6!=j0)
								{	
									cout<<"length6="<<length<<endl;
									int p6=a[j6];
									int t6=abs(a[j6+1]-a[j6]);
									length+=t6;
								
									a[j6]=a[j6+1];
									for(int j7=1;j7<10;j7++)
									if(j7!=j6&&j7!=j5&&j7!=j4&&j7!=j3&&j7!=j2&&j7!=j1&&j7!=j0)
									{
										cout<<"length7="<<length<<endl;
										int p7=a[j7];
										int t7=abs(a[j7+1]-a[j7]);
										length+=t7;
										a[j7]=a[j7+1];
										for(int j8=1;j8<10;j8++)
										if(j8!=j7&&j8!=j6&&j8!=j5&&j8!=j4&&j8!=j3&&j8!=j2&&j8!=j1&&j8!=j0)
										{
											
											int t8=abs(a[j8+1]-a[j8]);
											length+=t8;
											cout<<"length8="<<length<<endl;
											//int p8=a[j8];
											//a[j8]=a[j8+1];
											cout<<j0<<' '<<j1<<' '<<j2<<' '<<j3<<' '<<j4<<' '<<j5<<' '<<j6<<' '<<j7<<' '<<j8<<endl;
											if(min>length)
											{
												//cout<<j0<<' '<<j1<<' '<<j2<<' '<<j3<<' '<<j4<<' '<<j5<<' '<<j6<<' '<<j7<<' '<<j8<<endl;
												
												min=length;
												cout<<"min="<<min<<endl;
											}
											length-=t8;
											//a[j8]=p8;
											cout<<"length8="<<length<<endl;
											int temp;
											cin>>temp;
										}
										length-=t7;
										a[j7]=p7;
										cout<<"length7 2="<<length<<endl;
									}
									length-=t6;
									a[j6]=p6;
									cout<<"length6 2="<<length<<endl;
								}
								length-=t5;
								a[j5]=p5;
								//cout<<"length="<<length<<endl;
							}
							length-=t4;
							a[j4]=p4;
							//cout<<"length="<<length<<endl;
						}
						length-=t3;
						a[j3]=p3;
						//cout<<"length="<<length<<endl;
					}
					length-=t2;
					a[j2]=p2;
					//cout<<"length="<<length<<endl;
				}
				length-=t1;
				a[j1]=p1;
				//cout<<"length="<<length<<endl;
			}
			length-=t0;
			a[j0]=p0;
			//cout<<"length="<<length<<endl;
		}
		cout<<min;
		if(k!=n)
			cout<<endl;
	}
	return 0;
}