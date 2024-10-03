#include<iostream>
using namespace std;

const int max_flight=10;

class FlightRecord
{
	protected:
		string flight_name,flight_id,flight_arrival_time,flight_departure_time,flight_class;
		int flight_capacity;
	public:
		FlightRecord(string fn,string fid,string at,string dt,string fc,int c)
		{
			flight_name=fn;
			flight_id=fid;
			flight_arrival_time=at;
			flight_departure_time=dt;
			flight_class=fc;
			flight_capacity=c;
		}
		
		virtual void displaydetails()
		{
			cout<<"Flight Name: "<<flight_name<<endl;
			cout<<"Flight ID: "<<flight_id<<endl;
			cout<<"Arrival time: "<<flight_arrival_time<<endl;
			cout<<"Departure time: "<<flight_departure_time<<endl;
			cout<<"Flight Class: "<<flight_class<<endl;
			cout<<"Flight Capacity: "<<flight_capacity<<endl;
		}	
};

class VIPFlight: public FlightRecord
{
	private:
		string vip_category;
	public:
		VIPFlight(string fn,string fid,string at,string dt,string fc,int c,string vc):FlightRecord(fn,fid,at,dt,fc,c)
		{
			vip_category=vc;
		}
		void displaydetails()
		{
			cout<<"Flight Name: "<<flight_name<<endl;
			cout<<"Flight ID: "<<flight_id<<endl;
			cout<<"Arrival time: "<<flight_arrival_time<<endl;
			cout<<"Departure time: "<<flight_departure_time<<endl;
			cout<<"Flight Class: "<<flight_class<<endl;
			cout<<"Flight Capacity: "<<flight_capacity<<endl;
			cout<<"VIP category: "<<vip_category<<endl;
		}
};

class VVIPFlight: public FlightRecord
{
	private:
		string vvip_name;
	public:
		VVIPFlight(string fn,string fid,string at,string dt,string fc,int c,string vvn):FlightRecord(fn,fid,at,dt,fc,c)
		{
			vvip_name=vvn;
		}
		void displaydetails()
		{
			cout<<"Flight Name: "<<flight_name<<endl;
			cout<<"Flight ID: "<<flight_id<<endl;
			cout<<"Arrival time: "<<flight_arrival_time<<endl;
			cout<<"Departure time: "<<flight_departure_time<<endl;
			cout<<"Flight Class: "<<flight_class<<endl;
			cout<<"Flight Capacity: "<<flight_capacity<<endl;
			cout<<"VVIP Name: "<<vvip_name<<endl;
		}
};

class PublicFlight: public FlightRecord
{
	private:
		string source,destination;
	public:
		PublicFlight(string fn,string fid,string at,string dt,string fc,int c,string src,string des):FlightRecord(fn,fid,at,dt,fc,c)
		{
			source=src;
			destination=des;
		}
		void displaydetails()
		{
			cout<<"Flight Name: "<<flight_name<<endl;
			cout<<"Flight ID: "<<flight_id<<endl;
			cout<<"Arrival time: "<<flight_arrival_time<<endl;
			cout<<"Departure time: "<<flight_departure_time<<endl;
			cout<<"Flight Class: "<<flight_class<<endl;
			cout<<"Flight Capacity: "<<flight_capacity<<endl;
			cout<<"Source: "<<source<<endl;
			cout<<"Destination: "<<destination<<endl;
		}
};

class FlightManager
{
	private:
		FlightRecord* flight[max_flight];
		int flight_num;
	public:
		FlightManager()
		{
			flight_num=0;
		}
		void insert_flight(string fn,string fid,string at,string dt,string fc,int c)
		{
			if(flight_num<max_flight)
			{
				flight[flight_num]=new FlightRecord(fn,fid,at,dt,fc,c);
				flight_num++;
			}
			else
			{
				cout<<"Database is Full!! cannot insert more flights"<<endl;
			}
		}
		void insert_VIP_flight(string fn,string fid,string at, string dt,string fc,int c,string vc)
		{
			if(flight_num<max_flight)
			{
				flight[flight_num]= new VIPFlight(fn,fid,at,dt,fc,c,vc);
				flight_num++;	
			}
			else
			{
				cout<<"Database is Full!! cannot insert more flights"<<endl;
			}
		}
		void insert_VVIP_flight(string fn,string fid,string at, string dt,string fc,int c,string vn)
		{
			if(flight_num<max_flight)
			{
				flight[flight_num]= new VVIPFlight(fn,fid,at,dt,fc,c,vn);
				flight_num++;	
			}
			else
			{
				cout<<"Database is Full!! cannot insert more flights"<<endl;
			}
		}
		void insert_publicflight(string fn,string fid,string at, string dt,string fc,int c,string src,string des)
		{
			if(flight_num<max_flight)
			{
				flight[flight_num]= new PublicFlight(fn,fid,at,dt,fc,c,src,des);
				flight_num++;	
			}
			else
			{
				cout<<"Database is Full!! cannot insert more flights"<<endl;
			}
		}
		void num_of_flights()
		{
			cout<<"No of flights are: "<<flight_num<<endl;
		}
		void displaydetail()
		{
			for(int i=0;i<max_flight;i++)
			{
				flight[i]->displaydetails();
				cout<<endl;
			}
			
		}
};

int main()
{
	FlightManager objf;
	objf.insert_VVIP_flight("AIRINDIA","AIB191","16:30","20:45","IAF",289,"Prime Minister");
	objf.insert_VIP_flight("AKASAAIR","AAR281","08:00","10:45","First",189,"Z+");
	objf.insert_publicflight("AIRASIA","AIB191","16:30","20:45","E,B",269,"NAG","IGI");
	objf.insert_flight("INDIGO","AIB191","01:20","20:45","E,B,F",160);
	
	objf.displaydetail();
	
}


