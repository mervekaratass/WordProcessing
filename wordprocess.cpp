#include <iostream>
#include<time.h>
using namespace std;
struct dugum
{
	string veri;
	dugum *onceki, *sonraki;
};
class list
{
public:
	dugum* bas, * son;
	list()
	{
		bas = NULL;
		son = NULL;
	}
};
list liste = list();
list liste2 =list();


void listele()
{
	struct dugum* ptr;
	ptr = liste.bas;

	while (ptr != NULL)
	{
		cout << ptr->veri<<" ";
		ptr = ptr->sonraki;
	}
	cout << endl;
}


void kelime_basa_ekle(string sozcuk)
{
	dugum* gecici = new dugum;
	gecici->veri = sozcuk;
	if (liste.bas == NULL)
	{
		gecici->onceki = gecici->sonraki = NULL;
		liste.bas = gecici;
		liste.son = gecici;
		
	}
	else
	{
		gecici->onceki = NULL;
		gecici->sonraki = liste.bas;
		liste.bas->onceki = gecici;
		liste.bas = gecici;
	

	}
}
void kelime_sona_ekle(string sozcuk)
{
	dugum* gecici = new dugum;
	gecici->veri = sozcuk;
	gecici->sonraki = NULL;
	gecici->onceki = liste.son;
	liste.son->sonraki = gecici;
	liste.son = gecici;
	

}
void metin_girme()
{   clock_t start;
    start=clock();
	string sozcuk,metin;
	int uzunluk;
	cout << "Metninizi giriniz:";
	getline(cin, metin);
    uzunluk=metin.length();
    metin[uzunluk]=' ';
	for (int i =0,j=0; i <= uzunluk; i++)
	{
		if (metin[i] != ' ')
		{
			sozcuk = sozcuk + metin[i];
			
		}
		else if(metin[i] == ' ')
		{
		   
			if (j == 0)
			{
				kelime_basa_ekle(sozcuk);
				sozcuk = "";
				j++;
				
			}
			else {
				kelime_sona_ekle(sozcuk);
				sozcuk = "";
				j++;
				
			}
		}
	}
	start=clock()-start;
	cout<<"Islemin gerceklesme suresi:"<<(float)start/CLOCKS_PER_SEC<<"saniye"<<endl<<endl;
}

int kelime_ara(string sozcuk)
{       clock_t start;
    start=clock();
	    int k=0;
		dugum *ptr;
		ptr=liste.bas;
		int sayac=1;
		cout<<"Bulunan konumlar:";
		while(ptr != NULL)
		{
		   	if(ptr->veri==sozcuk)
			{cout<<sayac<<"-";
			k++;
			}
			ptr=ptr->sonraki;
			sayac+=1;
		}
		if(k==0)
	   {
	   	cout<<"Istenilen kelime metinde bulunamadi!";
	   }
    start=clock()-start;
	cout<<"Islemin gerceklesme suresi:"<<(float)start/CLOCKS_PER_SEC<<"saniye"<<endl<<endl;
}
void kelime_sil(string sozcuk)
{     clock_t start;
    start=clock();
	    dugum*ptr;
	    int k=0;
	    ptr=liste.bas;
	    while(ptr != NULL)
	   {
	    	if(ptr->veri==sozcuk)
	        {
			ptr->veri="";
			k++;
			}
			
	        ptr=ptr->sonraki;
	   }  
	   
	   if(k==0)
	   {
	   	cout<<"Istenilen kelime metinde bulunamadi!"<<endl;
	   }
	   cout<<"Silme islemi sonrasinda metnin son durumu:"<<endl;
      	listele();
      	start=clock()-start;
     	cout<<"Islemin gerceklesme suresi:"<<(float)start/CLOCKS_PER_SEC<<"saniye"<<endl<<endl;
      	
    
}
void kelime_degistirme(string sozcuk,string yeni)
{clock_t start;
    start=clock();
    
        int k=0;
		dugum *ptr;
		ptr=liste.bas;
		while(ptr!=NULL)
		{
			if(ptr->veri==sozcuk)
			{
				ptr->veri=yeni;
				k++;
			}
			ptr=ptr->sonraki;
		}
		if(k==0)
	   {
	   	cout<<"Istenilen kelime metinde bulunamadi!"<<endl;
	   }
	   cout<<"Degistirme islemi sonrasinda metnin son durumu:\n";
		listele();
		start=clock()-start;
    	cout<<"Islemin gerceklesme suresi:"<<(float)start/CLOCKS_PER_SEC<<"saniye"<<endl<<endl;
	
}
	
void kelime_sayisi()
{   clock_t start;
    start=clock();
    int i=0,k=0; 
    dugum *ptr;
   	ptr=liste.bas;
   if(i==0)
    {   
    	while(ptr!=NULL)
    	{  k++;
    	   ptr=ptr->sonraki;
    		
		}
		cout<<"Metindeki toplam kelime sayisi:"<<k<<endl;
	}

     if(i==0){
	int tekiller=1;
     	dugum *klm;
		dugum *sozcuk;
		klm=liste.bas->sonraki;

		while(klm != NULL)
		{
			sozcuk=klm->onceki;
			int sayac=0;
			while(sozcuk != NULL)
			{
			
				if(sozcuk->veri==klm->veri)
					sayac++;
					sozcuk=sozcuk->onceki;
			}
			if(sayac==0)
				tekiller++;

			klm=klm->sonraki;	
		}
      cout<<"Metindeki tekil kelime(farkli) sayisi:"<<tekiller<<endl;
      }
      start=clock()-start;
	cout<<"Islemin gerceklesme suresi:"<<(float)start/CLOCKS_PER_SEC<<"saniye"<<endl<<endl;
     
}
void alfabetik_listeleme()
{   clock_t start;
    start=clock();
   
   //liste 2 louþturup liste1 de deðiþiklik olmamasý için liste1 i liste 2 ye kopyaladým.
	int k=0;
	dugum *ptr=liste.bas;
	while(ptr != NULL)
	{   
	    dugum* gecici = new dugum;
	    
	if(k==0)
	{
		  if (liste2.bas == NULL)
	   {   gecici->veri=ptr->veri;
		   gecici->onceki = gecici->sonraki = NULL;
		   liste2.bas = gecici;
	    	liste2.son = gecici;
	    	k++;
		
	    }
	     else
        {    gecici->veri=ptr->veri;
	    	gecici->onceki = NULL;
	    	gecici->sonraki = liste2.bas;
		    liste2.bas->onceki = gecici;
		    liste2.bas = gecici;
		    k++;
      	}
	}
    else
	{
	dugum* gecici = new dugum;
	gecici->veri = ptr->veri;
	gecici->sonraki = NULL;
	gecici->onceki = liste2.son;
	liste2.son->sonraki = gecici;
	liste2.son = gecici;
	k++;
	}
	ptr=ptr->sonraki;
	}
     //kopyaladýktan sonra hangi islmei yapmak istedigini soruyoruz
	 cout<<"Kelimeleri alfabetik listeleme "<<endl;
		    

	
	//alfabeye göre listeledim;
	dugum *klm=liste2.bas;
	dugum *cmp=liste2.bas;
	while( klm != NULL)
	{    
		while(cmp != NULL)
		{
			if(klm->veri > cmp->veri)
			{   string yedek=klm->veri;
				klm->veri=cmp->veri;;
				cmp->veri=yedek;
			}
			cmp=cmp->sonraki;
		}
		
		klm=klm->sonraki;
		cmp=klm;
	}
   
   
   //buraya kaç kere olduðunu bulucam
   dugum *trb;
   dugum *ts;
   trb=liste2.bas;
   int sayac,s;
   string kelime="sl";
    while(trb!=NULL)
    {    sayac=1;
        ts=trb->sonraki;
    	while(ts!=NULL)
    	{   if(trb->veri==ts->veri)
    	   {
    	   	    sayac++;
    	   	   ts->veri=kelime;
		   }
    		ts=ts->sonraki;
		}
		if(trb->veri != kelime)
		cout<<trb->veri<<"------>"<<sayac<<endl;
		trb=trb->sonraki;
    	
	}
   
  
   //liste2 yi boþaltmazsak  her seferinde önceki listelenenlerin üstüne ilave edip yazýyo bu yüzden liste 2 nin elemanlarini boþaltýyoruz
   dugum *temp=liste2.bas;
   liste2.bas=NULL;
   start=clock()-start;
	cout<<"Islemin gerceklesme suresi:"<<(float)start/CLOCKS_PER_SEC<<"saniye"<<endl<<endl;
  

}



int main()
{
	string islem,yeni;
	int secim;
	bool kontrol=true;
	metin_girme();
	
	
	do
	{
		cout<<"Girdiginiz metinle igili hangi islemi yapmak istersiniz?\n";
		cout<<"1)Kelime sayisi\n2)Kelimeleri listeleme\n3)Kelime arama\n4)Kelime silme\n5)Kelime degistirme\n6)Cikis\n";
		cout<<"Secim:";
		cin>>secim;
		cout<<endl;
		while(secim<1 || secim>6)
		{
			cout<<"Hatali giris yaptiniz! Lutfen 1 ile 6 arasinda secim yapiniz.\nSecim:";
			cin>>secim;
		}
		
		if(secim==1)
		{   
			kelime_sayisi();
			
	    
			
		}
		else if(secim==2)
	    {     
		      alfabetik_listeleme();
		      
			
		 }
			 
		      
			
		
		else if(secim==3)
		{  
			cout<<"Aranan kelimeyi girniz:";
			cin>>islem;
			kelime_ara(islem);
			
			
		}
		else if(secim==4)
		{     
			cout<<"Silmek istediginiz kelimeyi giriniz:";
			cin>>islem;
			kelime_sil(islem);
			
		}
		else if(secim==5)
		{   
			cout<<"Degistimek istediginiz kelimeyi giriniz:";
			cin>>islem;
			cout<<"Yeni kelimeyi giriniz:";
			cin>>yeni;
			kelime_degistirme(islem,yeni);
			
		}
		else
		{  clock_t start;
		  start=clock();
		 kontrol=false;
		 cout<<"Cikis yaptiniz!";
		 start=clock()-start;
	       cout<<"\nIslemin gerceklesme suresi:"<<(float)start/CLOCKS_PER_SEC<<"saniye";
		}
	
	
	}while(kontrol);
	return 0;

}

