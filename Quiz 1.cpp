#include<iostream>
using namespace std;

class Smart_Ride{
	protected:
		string passengerName;
		int rideId;
		double baseFare;
		
		virtual double calculateFare()
		{
			return 0.0;
		}
		virtual void displayRideinfo()
		{
		
		}
		
	public:
		Smart_Ride(string passengerName , int rideId , double baseFare)
		{
			this->passengerName = passengerName;
			this->rideId = rideId;
			this->baseFare = baseFare;
		}		
};
class Economy_Ride : public Smart_Ride{
	public:
		double distanceKm;
	Economy_Ride(string passengerName , int rideId , double baseFare , double distanceKm) : Smart_Ride(passengerName , rideId , baseFare)
	{
		this->distanceKm = distanceKm;
	}
	double calculateFare() override
	{
		double FinalFare = baseFare + (distanceKm*8);
		return FinalFare;
	}
	void displayRideinfo()
	{
		cout<<"Passenger Name: "<<passengerName<<endl;
		cout<<"Ride Id: "<<rideId<<endl;
		cout<<"Final Fare: "<<calculateFare();
	}
		
};
class Luxury_Ride : public Smart_Ride{
	public:
		double serviceCharge;
		double distanceKm;
	Luxury_Ride(string passengerName , int rideId , double baseFare , double distanceKm , double serviceCharge) : Smart_Ride(passengerName , rideId , baseFare)
	{
		this->serviceCharge = serviceCharge;
		this->distanceKm = distanceKm;
	}
	double calculateFare() override
	{
		double FinalFare = baseFare + (distanceKm * 12) + serviceCharge;
		return FinalFare;
	}
	void displayRideinfo()
	{
		cout<<"Passenger Name: "<<passengerName<<endl;
		cout<<"Ride Id: "<<rideId<<endl;
		cout<<"Final Fare: "<<calculateFare();
	}
};
int main()
{
	Economy_Ride e1("Hamza",804,200,10);
	e1.calculateFare();
	e1.displayRideinfo();
	
	cout<<endl;
	cout<<"------------------------"<<endl;
	
	Luxury_Ride L1("Sara",903,500,20 ,50);
	L1.calculateFare();
	L1.displayRideinfo();
	
	return 0;
}






















