#include<iostream>    //header files
#include<string>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;
/* LINKED LIST*/
struct node{
  string name;
  int price;
  struct node *next;
 }*start;

class customer {
  public:           //customer class
    string name,address,email;
    int cus;
    long ph_no;
  public:
    void getData() {            //getting input from customer
      cout<<"****************** WELCOME TO THE SHOPPING MALL**************************"<<endl;
      cout<<"ARE YOU SHOPPING WITH US FOR THE FIRST TIME (press '1' for
      'yes', '0' for 'no'): "<<endl;
      cin>>cus;
      if(cus==1){
        cout<<"PLEASE ENTER YOUR NAME:";
        cin.get();
        getline(cin,name);
        cout<<"PLEASE ENTER YOUR PHONE NUMBER:";
        cin>>ph_no;
        cout<<"PLEASE ENTER YOUR ELECTRONIC MAIL ADDRESS:";
        cin.get();
        getline(cin,email);
        cout<<"PLEASE ENTER YOUR RESIDENTAL ADDRESS:";
        cin.get();
        getline(cin,address);
        cout<<"*********************************************************************************"<<endl;
      }
    else {
      cout<<"PLEASE ENTER YOUR NAME:";
      cin.get();
      getline(cin,name);
      cout<<"ENTER YOUR PHONE NUMBER:";
      cin>>ph_no;cout<<"*********************************************************************************"<<endl;
    }
  }
}c;

class single_llist:public customer{
  public:
    node* create_node(int, string);
    void insert_last(int, string);
    void delete_pos();
    void display();
    void sorting();
    void searching();
    single_llist(){
      start = NULL;
    }
 };

node *single_llist::create_node(int value, string name){
  struct node *temp, *s;
  temp = new(struct node);
  if (temp == NULL){
    cout<<"Memory not allocated "<<endl;
    return 0;
  }
  else{
    temp->name = name;
    temp->price = value;
    temp->next = NULL;
    return temp;
  }
}
void single_llist::insert_last(int value, string name) {
  struct node *temp, *s;
  temp = create_node(value, name);
  s = start;
   if(s != NULL) {
    while (s->next)
      s = s->next;
    s->next = temp;
    }
  else
    start = temp;
    cout<<"Element is Inserted "<<endl;
}
void single_llist::delete_pos(){
  int pos, i,counter = 0;
  char ch;
  if (start == NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  cout<<"Enter the position of value to be deleted: ";
  cin>>pos;
  struct node *s, *ptr;
  s = start;
  if (pos == 1){
    start = s->next;
  }
  else{
    while (s != NULL){
      s = s->next;
      counter++;
    }
    if (pos > 0 && pos <= counter){
      s = start;
      for (i = 1;i < pos;i++){
        ptr = s;
        s = s->next;
      }
      ptr->next = s->next;
    }
    else{
      cout<<"Position out of range"<<endl;
    }
  cout<<"Element Deleted"<<endl;
  }
}

void single_llist::display(){
  system("cls");
  int total = 0,count =0;
  char ch1;
  time_t tt;
  struct tm *ti;    //variables to display the local time
  time(&tt);
  ti=localtime(&tt);
  sorting();      //function to sort the elements of the bill on the basis of the price
  struct node *temp;
  if (start == NULL){
      cout<<"The Bill is Empty"<<endl;
      return;
  }
  temp = start;
  cout<<endl;
  cout<<"BILL:"<<endl;
  cout<<"DATE & TIME:"<<asctime(ti);
  cout<<endl<<setw(7)<<left<<"SRNO."<<setw(20)<<"ITEMS"<<setw(10)<<"PRICE"<<endl;
  while (temp != NULL) {
    count ++;
    cout<<setw(7)<<count<<setw(20)<<temp->name<<setw(10)<<temp->price<<endl;
    total += temp->price;
    temp = temp->next;
    }
  cout<<endl;
  cout<<"TOTAL:Rs "<<total<<endl;
}

void single_llist::sorting() {
  node *p=start,*q=start;
  while(p->next!=NULL){
    while(q->next!=NULL){
      if(q->price < q->next->price){
        swap(q->price,q->next->price);
        swap(q->name,q->next->name);
      }
      q=q->next;
     }
    p=p->next;
    q=start;
  }
}

void single_llist::searching(){     //function to search an element from the bill
  node *p=start;
  string toFind;
  bool flag=true;
  cout<<"Enter the name of item you want to search from the bill:";
  cin.get();
  getline(cin,toFind);
  while(p!=NULL){
    if(toFind==p->name){
      cout<<"The price of the item is:Rs "<<p->price<<endl;
      flag=false;
      break;
    }
    p=p->next;
  }
  if(flag)
    cout<<"Item is not present in the bill."<<endl;
 }
/* END LL**/
//***********************************main function******************************
int main (){
  single_llist sl;
  start = NULL;
  c.getData();
  while(1) {
    char ch;
    cout << "Do you want to add items(y/n)?";
    cin >>ch;
    cout <<endl;
    if(ch == 'n'||ch=='N')
      break;
    system("cls");
    int choice, choice1, choice2;
    cout<<"Enter '1' for 'grocery' "<<endl;
    cout<<"Enter '2' for 'dairy products' "<<endl;
    cout<<"Enter '3' for 'home needs' "<<endl;
    cout<<"Enter '4' for 'personal care' "<<endl;
    cout<<"Enter '5' for 'packed foods' "<<endl;
    cin >> choice;
    if(choice==1) {
      cout<<"Enter '1' for 'cooking oil' "<<endl;
      cout<<"Enter '2' for 'dals' "<<endl;
      cout<<"Enter '3' for 'dry fruits' "<<endl;
      cout<<"Enter '4' for 'masala and spices' "<<endl;
      cout<<"Enter '5 for 'pulses' "<<endl;
      cin>>choice1;
      if(choice1==1) {
        cout<<"Enter '1' for 'dalda: 200 Rs.' "<<endl;
        cout<<"Enter '2' for 'sunflower: 350 Rs.' "<<endl;
        cout<<"Enter '3' for 'mustard: 500 Rs.' "<<endl;
        cin >> choice2;
        if(choice2 == 1)
          sl.insert_last( 200, "dalda");
        else if(choice2 == 2)
          sl.insert_last( 350, "sunflower");
        else if(choice2==3)
          sl.insert_last( 500, "mustard");
        else
          cout<<"Invalid choice"<<endl;
      }
      else if(choice1==2) {
      cout<<"Enter '1' for 'beans: 200 Rs.' "<<endl;
      cout<<"Enter '2' for 'masoor: 450 Rs.' "<<endl;
      cout<<"Enter '3' for 'rajma: 350 Rs.' "<<endl;
      cin >> choice2;
      if(choice2 == 1)
        sl.insert_last( 200, "beans");
      else if(choice2 == 2)
        sl.insert_last( 450, "masoor");
      else if(choice2==3)
        sl.insert_last( 350, "rajma");
      else
        cout<<"Invalid choice"<<endl;
      }
      else if(choice1==3) {
        cout<<"Enter '1' for 'raisin: 249 Rs.' "<<endl;
        cout<<"Enter '2' for 'almonds: 279 Rs.' "<<endl;
        cout<<"Enter '3' for 'walnuts: 299 Rs.' "<<endl;
        cin >> choice2;
        if(choice2 == 1)
          sl.insert_last( 249, "raisin");
        else if(choice2 == 2)
          sl.insert_last( 279, "almonds");
        else if(choice2==3)
          sl.insert_last( 299, "walnuts");
        else
          cout<<"Invalid choice"<<endl;
      }
      else if(choice1==4) {
        cout<<"Enter '1' for 'black pepper: 15 Rs.' "<<endl;
        cout<<"Enter '2' for 'cinnamon: 19 Rs.' "<<endl;
        cout<<"Enter '3' for 'garam masala: 125 Rs.' "<<endl;
        cin >> choice2;
        if(choice2 == 1)
          sl.insert_last( 15, "black pepper");
        else if(choice2 == 2)
          sl.insert_last( 19, "cinnamon");
        else if(choice2==3)
            sl.insert_last( 125, "garam masala");
        else
            cout<<"Invalid choice"<<endl;
      }
      else if(choice1==5) {
        cout<<"Enter '1' for 'green peas: 17 Rs.' "<<endl;
        cout<<"Enter '2' for 'lentils: 47 Rs.' "<<endl;
        cout<<"Enter '3' for 'pea nuts: 57 Rs.' "<<endl;
        cin >> choice2;
        if(choice2 == 1)
          sl.insert_last( 17, "green peas");
        else if(choice2 == 2)
          sl.insert_last( 47, "lentils");
        else if(choice2==3)
          sl.insert_last( 57, "pea nuts");
        else
          cout<<"Invalid choice"<<endl;
      }
    }
    else if(choice==2) {
      cout<<"Enter '1' for 'butter' "<<endl;
      cout<<"Enter '2' for 'chesse' "<<endl;
      cout<<"Enter '3' for 'milk' "<<endl;
      cout<<"Enter '4' for 'curd' "<<endl;
      cout<<"Enter '5 for 'shrikhand' "<<endl;
      cin >> choice1;
      if(choice1==1) {
        cout<<"Enter '1' for 'britania: 122 Rs.' "<<endl;
        cout<<"Enter '2' for 'amul: 129 Rs.' "<<endl;
        cout<<"Enter '3' for 'kwality: 133 Rs.' "<<endl;
        cin >> choice2;
        if(choice2 == 1)
          sl.insert_last( 122, "britania");
        else if(choice2 == 2)
          sl.insert_last( 129, "amul");
        else if(choice2==3)
          sl.insert_last( 133, "kwality");
        else
          cout<<"Invalid choice"<<endl;
      }
      else if(choice1==2) {
        cout<<"Enter '1' for 'amul: 17 Rs.' "<<endl;
        cout<<"Enter '2' for 'govardhan: 23 Rs.' "<<endl;
        cout<<"Enter '3' for 'le ferme: 27 Rs.' "<<endl;
        cin >> choice2;
        if(choice2 == 1)
          sl.insert_last( 17, "amul");
        else if(choice2 == 2)
          sl.insert_last( 23, "govardhan");
        else if(choice2==3)
          sl.insert_last( 27, "le ferme");
        else
          cout<<"Invalid choice"<<endl;
      }
      else if(choice1==3) {
        cout<<"Enter '1' for 'sumul: 19 Rs.' "<<endl;
        cout<<"Enter '2' for 'mother dairy: 20 Rs.' "<<endl;
        cout<<"Enter '3' for 'amul: 22 Rs.' "<<endl;
        cin >> choice2;
        if(choice2 == 1)
          sl.insert_last( 19, "sumul");
        else if(choice2 == 2)
          sl.insert_last( 20, "mother dairy");
        else if(choice2==3)
          sl.insert_last( 22, "amul");
        else
          cout<<"Invalid choice"<<endl;
       }
      else if(choice1==4) {
        cout<<"Enter '1' for 'kiwi kiss: 23 Rs.' "<<endl;
        cout<<"Enter '2' for 'amul: 25 Rs.' "<<endl;
        cout<<"Enter '3' for 'nestle: 26 Rs.' "<<endl;
        cin >> choice2;
        if(choice2 == 1)
          sl.insert_last( 23, "kiwi kiss");
        else if(choice2 == 2)
          sl.insert_last( 25, "amul");
        else if(choice2==3)
          sl.insert_last( 26, "nestle");
        else
          cout<<"Invalid choice"<<endl;
      }
     else if(choice1==5) {
        cout<<"Enter '1' for 'kesar: 190 Rs.' "<<endl;
        cout<<"Enter '2' for 'mango: 210 Rs.' "<<endl;
        cout<<"Enter '3' for 'choco-strawberry: 250 Rs.' "<<endl;
        cin >> choice2;
        if(choice2 == 1)
          sl.insert_last( 190, "kesar" );
        else if(choice2 == 2)
          sl.insert_last( 210, "mango");
        else if(choice2==3)
          sl.insert_last( 250, "choco-strawberry");
        else
          cout<<"Invalid choice"<<endl;
        }
      }
  else if(choice==3) {
    cout<<"Enter '1' for 'detergent' "<<endl;
    cout<<"Enter '2' for 'cleaners' "<<endl;
    cout<<"Enter '3' for 'air freshners' "<<endl;
    cout<<"Enter '4' for 'pooja' "<<endl;
    cout<<"Enter '5 for 'lights and bulbs' "<<endl;
    cin >> choice1;
    if(choice1==1) {
      cout<<"Enter '1' for 'surf excel: 70 Rs.' "<<endl;
      cout<<"Enter '2' for 'rin: 75 Rs.' "<<endl;
      cout<<"Enter '3' for 'ariel: 79 Rs.' "<<endl;
      cin >> choice2;
      if(choice2 == 1)
        sl.insert_last( 70, "surf excel");
      else if(choice2 == 2)
        sl.insert_last( 75, "rin");
      else if(choice2==3)
        sl.insert_last( 79, "ariel");
      else
        cout<<"Invalid choice"<<endl;
      }
      else if(choice1==2) {
        cout<<"Enter '1' for 'domestos: 180 Rs.' "<<endl;
        cout<<"Enter '2' for 'mr muscels: 199 Rs.' "<<endl;
        cout<<"Enter '3' for 'colorox: 223 Rs.' "<<endl;
        cin >> choice2;
        if(choice2 == 1)
          sl.insert_last( 180, "domestos");
        else if(choice2 == 2)
          sl.insert_last( 199, "mr muscels");
        else if(choice2==3)
          sl.insert_last( 223, "colorox");
        else
          cout<<"Invalid choice"<<endl;
      }
      else if(choice1==3) {
        cout<<"Enter '1' for 'airwick: 98 Rs.' "<<endl;
        cout<<"Enter '2' for 'godrej: 112 Rs.' "<<endl;
        cout<<"Enter '3' for 'odonil: 143 Rs.' "<<endl;
        cin >> choice2;
        if(choice2 == 1)
          sl.insert_last( 98, "airwick");
        else if(choice2 == 2)
          sl.insert_last( 112, "gogrej");
        else if(choice2==3)
          sl.insert_last( 143, "odonil");
        else
        cout<<"Invalid choice"<<endl;
       }
      else if(choice1==4) {
        cout<<"Enter '1' for 'agarbati: 27 Rs.' "<<endl;
        cout<<"Enter '2' for 'dhoop stick: 35 Rs.' "<<endl;
        cout<<"Enter '3' for 'wax: 45 Rs.' "<<endl;
        cin >> choice2;
        if(choice2 == 1)
          sl.insert_last( 27, "agarbati");
        else if(choice2 == 2)
          sl.insert_last( 35, "dhoop stick");
        else if(choice2==3)
          sl.insert_last( 45, "wax");
        else
          cout<<"Invalid choice"<<endl;
      }
    else if(choice1==5) {
      cout<<"Enter '1' for 'night bulb: 15 Rs.' "<<endl;
      cout<<"Enter '2' for 'tube light: 55 Rs.' "<<endl;
      cout<<"Enter '3' for '100w bulb: 88 Rs.' "<<endl;
      cin >> choice2;
      if(choice2 == 1)
        sl.insert_last( 15, "night bulb");
      else if(choice2 == 2)
        sl.insert_last( 55, "tube light");
      else if(choice2==3)
        sl.insert_last( 88, "100w bulb");
      else
        cout<<"Invalid choice"<<endl;
    }
  }
  else if(choice==4) {
    cout<<"Enter '1' for 'skin care' "<<endl;
    cout<<"Enter '2' for 'hair care' "<<endl;
    cout<<"Enter '3' for 'shaving needs' "<<endl;
    cout<<"Enter '4' for 'deos and perfumes' "<<endl;
    cout<<"Enter '5 for 'oral care' "<<endl;
    cin >> choice1;
    if(choice1==1) {
      cout<<"Enter '1' for 'cold cream: 79 Rs.' "<<endl;
      cout<<"Enter '2' for 'suns cream: 110 Rs.' "<<endl;
      cout<<"Enter '3' for 'moisturizer: 189 Rs.' "<<endl;
      cin >> choice2;
      if(choice2 == 1)
        sl.insert_last( 79, "cold cream");
      else if(choice2 == 2)
        sl.insert_last( 110, "suns cream");
      else if(choice2==3)
        sl.insert_last( 189, "moisturizer");
      else
        cout<<"Invalid choice"<<endl;
      }
    else if(choice1==2) {
      cout<<"Enter '1' for 'oils: 49 Rs.' "<<endl;
      cout<<"Enter '2' for 'conditioner: 115 Rs.' "<<endl;
      cout<<"Enter '3' for 'shampoo: 200 Rs.' "<<endl;
      cin >> choice2;
      if(choice2 == 1)
        sl.insert_last( 49, "oils");
      else if(choice2 == 2)
        sl.insert_last( 115, "conditioner");  
      else if(choice2==3)
        sl.insert_last( 200, "shampoo");
      else
        cout<<"Invalid choice"<<endl;
      }
    else if(choice1==3) {
      cout<<"Enter '1' for 'shaving cream: 178 Rs.' "<<endl;
      cout<<"Enter '2' for 'after shave: 300 Rs.' "<<endl;
      cout<<"Enter '3' for 'trimer: 1999 Rs.' "<<endl;
      cin >> choice2;
      if(choice2 == 1)
        sl.insert_last( 178, "shaving cream");
      else if(choice2 == 2)
        sl.insert_last( 300, "after shave");
      else if(choice2==3)
        sl.insert_last( 1999, "trimer");
      else
        cout<<"Invalid choice"<<endl;
      }
    else if(choice1==4) {
      cout<<"Enter '1' for 'park avenue: 200 Rs.' "<<endl;
      cout<<"Enter '2' for 'nivia: 235 Rs.' "<<endl;
      cout<<"Enter '3' for 'nike: 300 Rs.' "<<endl;
      cin >> choice2;
      if(choice2 == 1)
        sl.insert_last( 200, "park avenue");
      else if(choice2 == 2)
        sl.insert_last( 235, "nivia");
      else if(choice2==3)
        sl.insert_last( 300, "nike");
      else
        cout<<"Invalid choice"<<endl;
      }
    else if(choice1==5) {
      cout<<"Enter '1' for 'brush: 79 Rs.' "<<endl;
      cout<<"Enter '2' for 'tooth paste: 149 Rs.' "<<endl;
      cout<<"Enter '3' for 'water flosser: 227 Rs.' "<<endl;cin >> choice2;
      if(choice2 == 1)
        sl.insert_last( 79, "brush");
      else if(choice2 == 2)
        sl.insert_last( 149, "tooth paste");
      else if(choice2==3)
        sl.insert_last( 227, "water flosser");
      else
        cout<<"Invalid choice"<<endl;
      }
    }
    else if(choice==5) {
      cout<<"Enter '1' for 'biscuits' "<<endl;
      cout<<"Enter '2' for 'breakfast cerels' "<<endl;
      cout<<"Enter '3' for 'jams and spreads' "<<endl;
      cout<<"Enter '4' for 'choclate' "<<endl;
      cout<<"Enter '5 for 'canned food' "<<endl;
      cin >> choice1;
      if(choice1==1) {
        cout<<"Enter '1' for 'parle-G: 10 Rs.' "<<endl;
        cout<<"Enter '2' for 'tiger: 12 Rs.' "<<endl;
        cout<<"Enter '3' for 'marigold: 16 Rs.' "<<endl;
        cin >> choice2;
        if(choice2 == 1)
          sl.insert_last( 10, "parle-G");
        else if(choice2 == 2)
          sl.insert_last( 12, "tiger");
        else if(choice2==3)
          sl.insert_last( 16, "marigold");
        else
          cout<<"Invalid choice"<<endl;
        }
      else if(choice1==2) {
        cout<<"Enter '1' for 'oats: 116 Rs.' "<<endl;
        cout<<"Enter '2' for 'kellogg's: 200 Rs.' "<<endl;
        cout<<"Enter '3' for 'chocos: 250 Rs.' "<<endl;
        cin >> choice2;
        if(choice2 == 1)
          sl.insert_last( 116, "oats");
        else if(choice2 == 2)
          sl.insert_last( 200, "kellogg");
        else if(choice2==3)
          sl.insert_last( 250, "chocos");
        else
          cout<<"Invalid choice"<<endl;
        }
      else if(choice1==3) {
      cout<<"Enter '1' for 'kissan: 199 Rs.' "<<endl;
      cout<<"Enter '2' for 'mapro: 229 Rs.' "<<endl;
      cout<<"Enter '3' for 'nuttela: 359 Rs.' "<<endl;
      cin >> choice2;
      if(choice2 == 1)
        sl.insert_last( 199, "kissan");
      else if(choice2 == 2)
        sl.insert_last( 229, "mapro");
      else if(choice2==3)
        sl.insert_last( 359, "nuttela");
      else
        cout<<"Invalid choice"<<endl;
      }
    else if(choice1==4) {
      cout<<"Enter '1' for 'silk: 65 Rs.' "<<endl;
      cout<<"Enter '2' for 'dark choclate: 100 Rs.' "<<endl;
      cout<<"Enter '3' for 'ferrero rocher: 500 Rs.' "<<endl;
      cin >> choice2;
      if(choice2 == 1)
        sl.insert_last( 65, "silk");
      else if(choice2 == 2)
        sl.insert_last( 100, "dark choclate");
      else if(choice2==3)
        sl.insert_last( 500, "ferrero rocher");
      else
        cout<<"Invalid choice"<<endl;
      }
    else if(choice1==5) {
      cout<<"Enter '1' for 'maggi: 29 Rs.' "<<endl;
      cout<<"Enter '2' for 'instant pakoda: 79 Rs.' "<<endl;
      cout<<"Enter '3' for 'rasgulla : 120 Rs.' "<<endl;
      cin >> choice2;
      if(choice2 == 1)
        sl.insert_last( 29, "maggi");
      else if(choice2 == 2)
        sl.insert_last( 79, "instant pakoda");
      else if(choice2==3)
        sl.insert_last(120 , "rasgulla");
      else
        cout<<"Invalid choice"<<endl;
      }
    }
    else
    cout<<"Invalid choice"<<endl;
  }
  sl.display();
  char ch1;
  while(1){
    cout<<"Do you want to search an item from the list(y/n)?";
    cin>>ch1;
    if(ch1=='y' || ch1=='Y')
        sl.searching();     //function to search an element from the bill
    else
      break;
  }
  while(1){
    cout<<"Do you want to delete item(y/n)?";
    cin>>ch1;
    if(ch1=='y' || ch1=='Y'){
      sl.delete_pos();
      sl.display();
    }
    else
      break;
  }
  sl.display();
  last:
    cout<<"\t\t\tTHANK YOU FOR JOINING US!!!!! \n\t\t\tPLEASE VISIT AGAIN...... "<<endl;
    return 0;
}
