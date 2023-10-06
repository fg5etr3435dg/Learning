#include <iostream>
#include "string"
#include "iomanip"
#define MAX 1000

using namespace std;

struct  Person
{
    int    m_Sex;
    int    m_Age;
    string m_Name;
    string m_Phone;
    string m_Addr;
};

//ͨѶ¼�ṹ��
struct  Addressbooks
{
    //ͨѶ¼�������ϵ������
    struct Person personArray[MAX]; //ͨѶ¼������
    
    int m_Size;
};

void addPerson  (Addressbooks *abs);
void showPerson (Addressbooks *abs);
void findPerson (Addressbooks *abs);
void deletePerson (Addressbooks *abs);
void newPerson (Addressbooks *abs,int num);

int isExist (Addressbooks *abs,string name);
void showMenu  ( );

int main ()
{
    int select =0;
   //����һ��ͨѶ¼�Ľṹ�����
   Addressbooks abs;
   abs.m_Size=0;//��ʼ��ͨѶ¼�еĽṹ��
   
   while (1)
    { 
        showMenu();
        cin >>select;
        switch (select)
        {
        case 1:
        addPerson(&abs);
            break;
        case 2:
        showPerson(&abs);
            break; 
        case 3:
        deletePerson(&abs);
            break;
        case 4:
        findPerson(&abs);
            break;

        case 5:

            break;
        case 0:
            cout<<"�˳��ɹ�,��ӭ�´�ʹ��......"<<endl;
            system("pause");
            return 0;

        default:

        cout<<"������������������;"<<endl;
        
        cin>>select;
            break;
        }
    }
    system("pause");
    return 0;

}
void showMenu()
{
    cout<<"**************************"<<endl;
    cout<<"*****  1.�����ϵ��  *****"<<endl;
    cout<<"*****  2.��ʾ��ϵ��  *****"<<endl;
    cout<<"*****  3.ɾ����ϵ��  *****"<<endl;
    cout<<"*****  4.������ϵ��  *****"<<endl;
    cout<<"*****  5.�����ϵ��  *****"<<endl;
    cout<<"*****  0.�˳���ϵ��  *****"<<endl;
    cout<<"**************************"<<endl;
} 
void showPerson (Addressbooks *abs)
{
    if (abs->m_Size==0)
    {
        cout<<"��ǰͨѶ¼Ϊ��."<<endl;
        system("pause");
        system("cls");
    }
    else
    {
       system("cls");
       cout<<left <<setw(8)<<"���"<< setw(8)<<"����"<< setw(8)<<"�Ա�"<< setw(8)<<"����"<< setw(15)<<"�绰����"<< setw(20)<<"��ͥ��ַ"<<endl;
       for ( int i = 0; i < abs->m_Size; i++)
       {
        string str;
        abs->personArray->m_Sex? str="Ů":str="��";
        cout<<left <<setw(8)<<i<< setw(8)<<abs->personArray->m_Name<< setw(8)<<str<< setw(8)<<abs->personArray->m_Age<< setw(15)<<abs->personArray->m_Phone<< setw(20)<<abs->personArray->m_Addr<<endl;
       }       
        system("pause");
        system("cls");
    }
}
void deletePerson (Addressbooks *abs)
{
    string name;
    cout<<"��������Ҫɾ����ϵ�˵�����:"<<endl;
    cin>>name;
    int num =isExist(abs,name);
    if(num==-1)
    {
        cout<<"���޴��ˣ�"<<endl;
        system("pause");
        system("cls");
    }    
    else
    {
        system("cls");
        string str;
        cout<<"�����Ƿ�Ҫɾ����ϵ��:"<<name<<"(YES/NO)"<<endl;
        while (1)
        {       
            string Deter;
            cin>>Deter;
            for (int i=0; i <Deter.size(); i++)  Deter[i] = toupper(Deter[i]); //ת��Ϊ��д��ĸ
            
            if(Deter=="YES"||Deter=="Y") 
            { 
                newPerson (abs,num);
                cout<<"��ϵ��  "<<name<<"  ɾ���ɹ�"<<endl;
                system("pause");
                system("cls");
                break;
            }
            else if(Deter=="NO"||Deter=="N")
            {
                system("pause");
                system("cls");
                break;
            }
            else
            {
                cout<<"������������������;"<<endl;
            }
        }   
       
    }
}
void findPerson (Addressbooks *abs)
{
        string name;
        cout<<"��������Ҫ������ϵ�˵�����:"<<endl;
        cin>>name;
        if(isExist(abs,name)==-1)
        {
             cout<<"���޴��ˣ�"<<endl;
        }    
}
int isExist (Addressbooks *abs,string name)  //�������������Ƿ����
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if(abs->personArray->m_Name==name) 
        {
            system("cls");
            string str;
            abs->personArray->m_Sex? str="Ů":str="��";
            cout<<left <<setw(8)<<"���"<< setw(8)<<"����"<< setw(8)<<"�Ա�"<< setw(8)<<"����"<< setw(15)<<"�绰����"<< setw(20)<<"��ͥ��ַ"<<endl;
            cout<<left <<setw(8)<<i<< setw(8)<<abs->personArray->m_Name<< setw(8)<<str<< setw(8)<<abs->personArray->m_Age<< setw(15)<<abs->personArray->m_Phone<< setw(20)<<abs->personArray->m_Addr<<endl;
            system("pause");
            return i;
        }
    }
    return -1;
}
void addPerson  (Addressbooks *abs){
    //�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
    if (abs->m_Size==MAX)
    {
      cout <<"ͨѶ¼����,�޷����"<<endl;
      return ;
    }
    else
    {
        Person Person_input;
        cout<<"����������:"<<endl;
        cin>>Person_input.m_Name;
        abs->personArray[abs->m_Size].m_Name=Person_input.m_Name;

        cout<<"�������Ա�(0/1):"<<endl;
        cout<<"0---��   1---Ů"<<endl;
        cin>>Person_input.m_Sex;
        while (1)
        {
            if (Person_input.m_Sex == 0||Person_input.m_Sex == 1)
            {
                break;
            }
            else
            cout<<"�Ա���������,����������"<<endl;
            cout<<"�����������Ա�(0/1):"<<endl;
            cout<<"0---��   1---Ů"<<endl;
            cin>>Person_input.m_Sex;
        }
        abs->personArray[abs->m_Size].m_Sex=Person_input.m_Sex;

        cout<<"����������:"<<endl;
        cin>>Person_input.m_Age;
        abs->personArray[abs->m_Size].m_Age=Person_input.m_Age;

        cout<<"������绰����:"<<endl;
        cin>>Person_input.m_Phone;
        while (1)
        {
            //cout<<Person_input.m_Phone.length()<<endl;
            if (Person_input.m_Phone.length()==11)  //length()��ȡPerson_input.m_Phone���ַ�������
            {
                break;
            }
            cout<<"������������,����������"<<endl;
            cout<<"�������������:"<<endl;
            cin>>Person_input.m_Phone;
        }
        
    abs->personArray[abs->m_Size].m_Phone=Person_input.m_Phone;
    
    int num=0;
    while(1)
    {   
        
        if (num)
        {
           cout<<"����������סַ:"<<endl; 
        }
        else {cout<<"������סַ:"<<endl;}

        cin>>Person_input.m_Addr;
        cout<<"��ȷ����ӵĵ�ַ�Ƿ�Ϊ:"<<Person_input.m_Addr<<"(YES/NO)"<<endl;

          
        while (1)
        {       
            string Deter;
            cin>>Deter;
            for (int i=0; i <Deter.size(); i++)  Deter[i] = toupper(Deter[i]); //ת��Ϊ��д��ĸ
            
            if(Deter=="YES"||Deter=="Y") {goto tiaochu;}
           
            else if(Deter=="NO"||Deter=="N")
            {
                num++;
                break;
            }
            else
            {
                cout<<"������������������;"<<endl;
            }
        }    
    }
tiaochu:
        abs->personArray[abs->m_Size].m_Addr=Person_input.m_Addr;
        
        //����ͨѶ¼������
        abs->m_Size++;
        cout<<"�����ϵ�˳ɹ�;"<<endl;
    }
    system ("pause");
    system ("cls");
}
void newPerson (Addressbooks *abs,int num)  //ɾ����Ա֮�󣬽���������
{
    for (int i = num; i < abs->m_Size; i++)
    {
        abs->personArray[i]=abs->personArray[i+1];
        //abs->personArray[abs->m_Size]=nup;
     }
     abs->m_Size--;
    
}
