#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <sstream>
using namespace std;

struct Node {
	int Str, Dex, Con, Wis, Int, Cha,lev;
	string Name, Class, Race,redbr;
	Node *next;
};
class characterSheet {
	int S, D, C, W, I, Ch;
	string N, Cl, R;
	Node* head;
	public:
		characterSheet(){
			head=NULL;
		 }
		void insertStats (int Level,string N,string Cl,string R,int S, int D, int C, int I, int W, int Ch){
			Node* nn=new Node;
			nn->lev=Level;
			nn->Name=N;
			nn->Class=Cl;
			nn->Race=R;
			nn->Str=S;
			nn->Dex=D;
			nn->Con=C;
			nn->Int=I;
			nn->Wis=W;
			nn->Cha=Ch;
			nn->next=NULL;
			if(head==NULL){
				head=nn;
			}
			else{
				nn->next=head;
				head=nn;
			}
		}
			void display(){
				Node* temp=head;
				ofstream dat;
				while(temp!=NULL){
					cout<<"**************************************************************"<<endl;
					cout<<"Name--->"<<" ";
					cout<<temp->Name;
					cout<<endl;
					cout<<"Class--->"<<" ";
					cout<<temp->Class;
					cout<<endl;
					cout<<"Race--->"<<" ";
					cout<<temp->Race;
					cout<<endl;
					cout<<"Level--->"<<" ";
					cout<<temp->lev;
					cout<<endl;
					cout<<"Strenght:"<<" ";
					cout<<temp->Str<<" ";
					cout<<endl;
					cout<<"Dexterity:"<<" ";
					cout<<temp->Dex<<" ";
					cout<<endl;
					cout<<"Consitution:"<<" ";
					cout<<temp->Con<<" ";
					cout<<endl;
					cout<<"Intelligence:"<<" ";
					cout<<temp->Int<<" ";
					cout<<endl;
					cout<<"Wisdom:"<<" ";
					cout<<temp->Wis<<" ";
					cout<<endl;
					cout<<"Charisma:"<<" ";
					cout<<temp->Cha<<" ";
					cout<<endl;
					cout<<"**************************************************************"<<endl;
					temp=temp->next;
				}
				cout<<endl;
	}
			void changelevel(string vr,string vrr,int lev){
				Node* temp=head;
				while(temp!=NULL){
					if(temp->Name==vr || temp->Class==vrr){
						temp->lev=lev;
						}
						temp=temp->next;
					}
				}
				
			void trazenjeclasa(string vr){
				Node* temp=head;
				cout<<"**************************************************************"<<endl;
				while(temp!=NULL){
					if(temp->Class==vr){
						cout<<temp->Name<<" "<<temp->Class<<" "<<temp->Race<<" "<<temp->lev<<" "<<temp->Str<<" "<<temp->Dex<<" "<<temp->Con<<" "<<temp->Int<<" "<<temp->Wis<<" "<<temp->Cha<<endl;
						}
						temp=temp->next;
				}
				cout<<"**************************************************************"<<endl;	
			}
			
			void trazenjaimena(string vr){
				Node* temp=head;
				cout<<"**************************************************************"<<endl;
				while(temp!=NULL){
					if(temp->Name==vr){
					cout<<temp->Name<<" "<<temp->Class<<" "<<temp->Race<<" "<<temp->lev<<" "<<temp->Str<<" "<<temp->Dex<<" "<<temp->Con<<" "<<temp->Int<<" "<<temp->Wis<<" "<<temp->Cha<<endl;
					
					}
					temp=temp->next;
				}
				cout<<"**************************************************************"<<endl;
			}
			void indata(){
			Node* temp=head;
			fstream dat("characters.txt", ios::app);
			while(temp!=NULL){
					dat<<temp->Name<<" "<<temp->Class<<" "<<temp->Race<<" "<<temp->lev<<" "<<temp->Str<<" "<<temp->Dex<<" "<<temp->Con<<" "<<temp->Int<<" "<<temp->Wis<<" "<<temp->Cha<<endl;
					temp=temp->next;
			}
			dat.close();
		}
		void remove(string val,string var){
			if(head->Name==val || head->Class==var){
				delete head;
				head=head->next;
				return;
			}
			if(head->next==NULL){
				if(head->Name==val || head->Class==var){
					delete head;
					head=NULL;
					return;
				}
				cout<<"Vrijednost nije pronadjena";
				return;
			}
			Node* temp=head;
			while(temp->next!=NULL){
			if(temp->next->Name==val || head->next->Class==var){
				Node* temp_ptr=temp->next->next;
				delete temp->next;
				temp->next=temp_ptr;
				return;
			}
			temp=temp->next;
		}
		cout<<"Vrijednost nije pronadjena";
	}
	void inlista(){
                head=NULL;
                string linija, temp;
                fstream dat("characters.txt", ios::in);
                while(getline(dat, linija)){
                    Node* new_node=new Node;
                    int i, j, k=0;
                    for(i=0;i<linija.length();i++){
                        fstream tmp("temp.txt", ios::app);
                        j=i;
                        while(linija[j]>=47 && linija[j]<=57 || linija[j]>=65 && linija[j]<=122){
                            tmp<<linija[j];
                            j++;
                            i++;
                        }
                        tmp.close();
                        fstream dat2("temp.txt", ios::in);
                        getline(dat2, temp);
                        dat2.close();
                        system("del temp.txt");
                        stringstream xx(temp);
                        if(k==0){
                            new_node->Name=temp;
                        }
                        else if(k==1){
                            new_node->Class=temp;
                        }
                        else if(k==2){
                            new_node->Race=temp;
                        }
                        else if(k==3){
                            xx>>new_node->lev;
                         
                        }
                        else if(k==4){
                            xx>>new_node->Str;
                            
                        }
                        else if(k==5){
                            xx>>new_node->Dex;
                            
                        }
                        else if(k==6){
                            xx>>new_node->Con;
                            
                        }
                        else if(k==7){
                            xx>>new_node->Int;
                            
                        }
                        else if(k==8){
                            xx>>new_node->Wis;
                           
                        }
                        else if(k==9){
                            xx>>new_node->Cha;
                            new_node->next=NULL;
                        }
                        k++;
                    }
                    if(head==NULL){
                        head=new_node;
                    }
                    else{
                        new_node->next=head;
                        head=new_node;    
                    }
                    
                }
                dat.close();
            }	
        
				
};

int main(int argc, char** argv) {
	characterSheet c;
	int a,b, stat;
	int br=0;
	int str,dex,con,in,wis,cha,level,ll;	
	string name,race,clas,klas,nam;
	ofstream data;
	
	while (1){
		
		cout<<"----------------------------------------------"<<endl;
		cout<<"| 1 - Insert Character "<<endl;
		cout<<"| 2 - Print Characters"<<endl;
		cout<<"| 3 - Search Characters for similar Classes"<<endl;
		cout<<"| 4 - Search Characters for Names"<<endl;
		cout<<"| 5 - Change level"<<endl;
		cout<<"| 6 - Saving in to a file"<<endl;
		cout<<"| 7 - Loading from file to the list"<<endl;
		cout<<"| 8 - Delete unnecessary data"<<endl;
		cout<<"| 0 - Exit"<<endl;
		cout<<"----------------------------------------------"<<endl;
		cin>>a;
		system("CLS");
		
		if(a==0){
			return 0;
		}
		
		if(a==1){
			cin.ignore();
			cout<<"Insert your characters name: ";
			getline(cin,name);
			cout<<"Insert your characters class: ";
			getline(cin,clas);
			cout<<"Insert your characters race: ";
			getline(cin,race);
			do {
			cout<<"Insert level of your character: ";
			cin>>level;
				if(level>20 or level<1) cout<<"\nThe Number can't be higher then 20 or lower then 1.\n";
			}while (level>20 or level<1);
			do {
				cout<<"Insert Strenght: ";
				cin>>str;
				if (str>20 or str<1) cout<<"\nThe Number can't be higher then 20 or lower then 1.\n";
			} while (str>20 or str<1);	
			do {
				cout<<"Insert Dexterity: ";
				cin>>dex;
				if (dex>20 or dex<1) cout<<"\nThe Number can't be higher then 20 or lower then 1.\n";
			} while (dex>20 or dex<1);	
			do {
				cout<<"Insert Constitution: ";
				cin>>con;
				if (con>20 or con<1) cout<<"\nThe Number can't be higher then 20 or lower then 1.\n";
			} while (con>20 or con<1);	
			do {
				cout<<"Insert Intelligence: ";
				cin>>in;
				if (in>20 or in<1) cout<<"\nThe Number can't be higher then 20 or lower then 1.\n";
			} while (in>20 or in<1);	
			do {
				cout<<"Insert Wisdom: ";
				cin>>wis;
				if (wis>20 or wis<1) cout<<"\nThe Number can't be higher then 20 or lower then 1.\n";
			} while (wis>20 or wis<1);	
			do {
				cout<<"Insert Charisma: ";
				cin>>cha;
				if (cha>20 or cha<1) cout<<"\nThe Number can't be higher then 20 or lower then 1.\n";
			} while (cha>20 or cha<1);	
			c.insertStats(level,name,clas,race,str,dex,con,in,wis,cha);
			system("CLS");
		}
		if(a==2){
			c.display();
			system("PAUSE");
			system("CLS");
		}
		
		if(a==3){
			cout<<"Enter your Class to search for some that someone uses: ";
			cin>>klas;
			cout<<endl;
			c.trazenjeclasa(klas);
			system("PAUSE");
			system("CLS");
		}
		
		if(a==4){
			cout<<"Enter your Name to search: ";
			cin>>nam;
			cout<<endl;
			c.trazenjaimena(nam);
			system("PAUSE");
			system("CLS");	
		}
		
		if(a==5){
			cin.ignore();
			cout<<"Enter your name of your character to change his level: ";
			getline(cin,name);
			cout<<"Enter your class of your character to change his level: ";
			getline(cin,clas);
			cout<<"Enter in wich level you want to change: ";
			cin>>level;
			c.changelevel(name,clas,level);
			system("PAUSE");
			system("CLS");
		}
		
		if(a==6){
			br++;
			if(br==2){
				cout<<"No saving for the second time be gone you heretic"<<endl;
			}
			if(br==1){
				cout<<"Your data has been saved in to files.\n/*NOTE/* There is no return back,no saving back,no god can help you"<<endl;
				c.indata();
			}
		}
		
		if(a==7){
			cout<<"Your data from files have been saved to the list"<<endl;
			c.inlista();
		}
		
		if(a==8){
			cin.ignore();
			cout<<"Enter a name for removing: ";
			getline(cin,name);
			cout<<"Enter a class for removing: ";
			getline(cin,clas);
			c.remove(name,clas);
			system("PAUSE");
			system("CLS");
		}	
	}
}
