#include <iostream>
#include <list>
#include<cstdlib>
using namespace std;


class Doctor {
public:
  virtual void getFed(){
  };

  virtual void getDrink(){
  };
  
  virtual void getToolKit(){
  };

  virtual void changeMood(){
  };

  virtual void receiveCompliments(){
  };
  

  virtual bool getMood(){
  };
  
  virtual void startFresh(){
  }
  
  virtual char getName(){
  }
};

class Male:public Doctor {

  bool isDrunk;
  bool isHungry;
  bool isHappy;
  bool complimentReceived;
  char name;
  bool toolKit;

  
  public:
  	
  	Male()
  	{
  	name='m';
	  }
  void getFed() {
    isHungry = false;
  }
  
  char getName()
  {
  	return name;
  }

  void getDrink() {
    isDrunk = true;
  }
  void getToolKit()
  {
  	toolKit=true;
  }
  void startFresh()
	  {
	  			isHungry = true;
	  			isHappy=false;
	  			isDrunk=false;
	  			complimentReceived=false;
	  			toolKit=false;
	  }

  void receiveCompliments() {
    complimentReceived = true;
  }

  void changeMood() {
    if (!isHungry && isDrunk) {
      isHappy = true;
    }
    if (complimentReceived) {
      isHappy = false;
    }
  }

  bool getMood() {
    return isHappy;
  }
};

class Female: public Doctor {

  bool isDrunk;
  bool isHungry;
  bool isHappy;
  bool isFlirty;
  bool complimentReceived;
  char name;
  bool toolKit;
  
  public:
  	
  	Female()
  	{
  		isDrunk = true;
  		isFlirty = true;
  		name='f';
	  }
	  
	  

  void getFed() {
    isHungry = false;
  }
  
  char getName()
  {
  	return name;
  }

 void getDrink() {
    isDrunk = true;
  }
  
  void getToolKit()
  {
  	toolKit=true;
  }
  void startFresh()
	  {
	  		isHungry = true;
	  			isHappy=false;
	  			isDrunk=true;
	  			complimentReceived=false;
	  			isFlirty = true;
	  			toolKit=false;
	  }

 void receiveCompliments() {
    complimentReceived = true;
  }

  void changeMood() {
    if (complimentReceived && isFlirty && isDrunk && !isHungry) {
      isHappy = true;
    }
  }

  bool getMood() {
    return isHappy;
  }

 void setFlirtiness(bool f) {
    isFlirty = f;
  }

};

class DoctorsData {
   public:
  Doctor *data;
  DoctorsData* next;
  DoctorsData(Doctor *val)
  {
  	data=val;
  	next=NULL;
  }
  
  DoctorsData(Doctor *val, DoctorsData *tempNext)
  {
  	data=val;
  	next=tempNext;
  }
 
  
};
class ListOfDoctors
{
    
    DoctorsData* head;

  public:
   
    ListOfDoctors():head(NULL)
    {
    }

    void insert(Doctor *val)
    {
     
      DoctorsData* new_DoctorsData = new DoctorsData(val);
	 if (head == NULL)
      {
        head = new_DoctorsData;
      }
     
      else
      {
      	DoctorsData*temp=head;
      	while(temp->next!=NULL)
      	{
      		temp=temp->next;
		  }
		  
		  temp->next=new_DoctorsData;
        
      }
    }
    
    void deletee(int key)
    {
    	DoctorsData*temp=head;
    	DoctorsData*temp1=head;
    	temp=temp->next;
    	
    	int count=1;
    	while(1)
    	{
    		
    		if(count==key)
    		{
    			if(temp->next!=NULL)
    			temp1->next=temp->next;
    			else
    			{
    				temp1->next=NULL;
				}
    			break;
			}
			temp=temp->next;
			temp1=temp1->next;
		}
    	
	}
	
	
    
    
    DoctorsData* returnn()
    {
    	return head;
	}
	
	char getName(int key)
	{
		DoctorsData *temp=head;
		int count=0;
		while(1)
		{
			if(count==key)
			{
				return temp->data->getName();
			}
			temp=temp->next;
			count++;
		}
	}


};
class Nurse {

  public:
  char name;

  Nurse(char name) {
    this->name = name;
  }
  
  void startFresh(Doctor *r)
  {
  	r->startFresh();
  }

  void feed(Doctor *r) {
    r->getFed();
  }

  void giveWater(Doctor *r) {
    r->getDrink();
  }

  void giveCompliments(Doctor *r) {
    r->receiveCompliments();
  }
  
  void changeMood(Doctor *r)
  {
  	r->changeMood();
  }
  
  void getToolKit(Doctor *r)
  {
  	r->getToolKit();
  }

  bool checkIfYouWillContinue(ListOfDoctors l) {
  	
  	DoctorsData* h=l.returnn();
  	int flag=0;
  	
  	while(h->next!=NULL)
     {
     	if(h->data->getMood()==false)
     	flag=1;
     	
     	h=h->next;
	 }
	 if(h!=NULL)
	 {
	 	if(h->data->getMood()==false)
     	flag=1;
	 }
  	
    if(flag==1)
    return false;
    else
    return true;
  }
  
  void remove(ListOfDoctors l,int key)
  {
  	char name1=l.getName(key);
  	if(name1=='f')
  	cout<<"removing one of "<<"female"<<" doctors"<<endl;
  	else
  	cout<<"removing one of "<<"male"<<" doctors"<<endl;
  	
  	
  	l.deletee(key);
  }
  void insertt(ListOfDoctors l,int key)
  {
  	if(key==0)
		 	{
		 		Doctor *k1 = new Doctor;
    			k1=new Male;
    			l.insert(k1);
    			
  	cout<<"adding one  "<<"male"<<" doctors"<<endl;
    			
    
			 }
			 else
			 {
			 	Doctor *q1 = new Doctor;
    			q1=new Female;
    			l.insert(q1);
    			cout<<"adding one  "<<"female"<<" doctors"<<endl;
			 }
  }
};
int com=-1;
int scenario(Nurse Nurse, int compliment,ListOfDoctors l) {
	
	cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<Nurse.name<<" turn"<<endl<<endl;
	
	
	
    
	DoctorsData* h4=l.returnn();
    
     
     while(h4->next!=NULL)
     {
     	Nurse.startFresh(h4->data);
     	if(h4->data->getName()=='f')
     	{
     			cout<<"Feeding "<<"female doctor"<<endl;
		 }
		 else
		 {
		 	cout<<"Feeding "<<"male doctor"<<endl;
		 }
     	
     	Nurse.feed(h4->data);
     	if(h4->data->getName()=='f')
     	{
     			cout<<"Provide Drink to "<<"female doctor"<<endl;
		 }
		 else
		 {
		 	cout<<"Provide Drink to "<<"male doctor"<<endl;
		 }
     
     	Nurse.giveWater(h4->data);
     	
     	h4=h4->next;
	 }
	 if(h4!=NULL)
	 {
	 	Nurse.startFresh(h4->data);
	 	if(h4->data->getName()=='f')
     	{
     			cout<<"Feeding "<<"female doctor"<<endl;
		 }
		 else
		 {
		 	cout<<"Feeding "<<"male doctor"<<endl;
		 }
     	
     	Nurse.feed(h4->data);
     	if(h4->data->getName()=='f')
     	{
     			cout<<"Provide Drink to "<<"female doctor"<<endl;
		 }
		 else
		 {
		 	cout<<"Provide Drink to "<<"male doctor"<<endl;
		 }
     	Nurse.giveWater(h4->data);
	 }
	 
	 

    DoctorsData* h1=l.returnn();
    int count=0;
    int flag=-1;
     
     while(h1->next!=NULL)
     {
     	if(count==compliment)
     	break;
     	
     	h1=h1->next;
	 }
	 if(h1!=NULL)
	 {
	 	Nurse.getToolKit(h1->data);
	 	cout<<"Provide toolKit"<<endl;
	 	if(h1->data->getName()=='f')
	 	{
	 		
	 		cout<<"Give compliment to one of female doctors"<<endl;
	 		flag=1;
		 }
		 else
		 {
		 	cout<<"Give compliment to one of male doctors"<<endl;
		 	flag=2;
		 }
	 	
	 	Nurse.giveCompliments(h1->data);
	 }
	 
	 h1=l.returnn();
	 
	 
	 while(h1->next!=NULL)
	 {
	 	if(h1->data->getName()=='f'&&flag==1)
	 	{
	 			Nurse.giveCompliments(h1->data);
		 }
		 else if(h1->data->getName()=='m'&&flag==2)
		 {
		 		Nurse.giveCompliments(h1->data);
		 }
		 h1=h1->next;
		 
	 }
	 if(h1!=NULL)
	 {
	 	if(h1->data->getName()=='f'&&flag==1)
	 	{
	 			Nurse.giveCompliments(h1->data);
		 }
		 else if(h1->data->getName()=='m'&&flag==2)
		 {
		 		Nurse.giveCompliments(h1->data);
		 }
	 }

     DoctorsData* h=l.returnn();
     
     while(h->next!=NULL)
     {
     	Nurse.changeMood(h->data);
     	
     	h=h->next;
	 }
	 if(h!=NULL)
	 {
	 	Nurse.changeMood(h->data);
	 }
  
    if (Nurse.checkIfYouWillContinue(l)) {
    	cout<<Nurse.name<<" will continue"<<endl;
      
    } else {
    	cout<<Nurse.name<<" will not continue"<<endl;
      
    }
    
    if(Nurse.checkIfYouWillContinue(l))
    {
	
	 	int randd=rand()%2;
	 	
	 	if(randd==1)
	 	{
	 		while(1)
	 		{
	 		randd=rand()%com;
	 		if(randd!=0)
	 		{
	 			break;
			 }
		 	}
		 	Nurse.remove(l,randd);
		 	
		 	randd=randd%2;
		 Nurse.insertt(l,randd);
			 randd=randd%2;
		 	Nurse.insertt(l,randd);
		 	cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
		 	return 1;
		 }
		 else
		 {
		 	randd=randd%2;
		 	Nurse.insertt(l,randd);
		 	cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
		 	return 0;
		 }
		 
		 
	}

    

}
int main()
{
	Doctor *k = new Doctor;
    k=new Male;
    Doctor *q = new Doctor;
    q=new Female;
    com=2;
    ListOfDoctors l;
    l.insert(k);
    l.insert(q);
	char nurses[7]={'A','B','C','D','E','F','G'};
	int continuee[7];
	int i;
	for(i=0;i<7;i++)
	{
		
		Nurse n(nurses[i]);
		continuee[i]=scenario(n,rand()%com,l);	
	}
	cout<<"at the end of the week ";
	for(int i=0;i<7;i++)
	{
		if(continuee[i]==1)
		{
			cout<<nurses[i]<<" ";
		}
	}
	cout<<"will continue to work";

}
