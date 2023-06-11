#include <iostream>

using namespace std;

class Customer
{
    public :
    
    string email, name, address;
    long telephoneNo;
    
    int addNew()
    {
        cout<<"Enter the email, name, address and telephone no. of the user Please.\n";
        getline(cin, email);
        getline(cin, name);
        getline(cin, address);
        cin>>telephoneNo;
        return 0;
    }
    
    int edit()
    {
        cout<<"Enter new name, email, address and telephone no. of user Please.\n";
        getline(cin, email);
        getline(cin, name);
        getline(cin, address);
        cin>>telephoneNo;
        return 0;
    }
    
    int update()
    {
        cout<<"Enter new email, address and telephone no. of user Mr./Ms. "<<name<<" Please.\n";
        getline(cin, email);
        getline(cin, address);
        cin>>telephoneNo;
        return 0;
    }
    
};


class Order
{
    public :
    
    static int number;
    const float price = 10000.0;
    float payment;
    string state, billingAddress;
    bool created, paymentMade;
    Customer *customer;
    
    Order(Customer *customer)
    {
        number++;
        this->customer = customer;
        payment = price + (0.1f*price);
        state = "West Bengal";
        billingAddress = customer->address;
        created = true;
        paymentMade = false;
    }
    
    int setState(string state)
    {
        this->state = state;
        return 0;
    }
    
    float getPrice()
    {
        return price;
    }
    
};
int Order::number = 0;

class Passenger
{
    public :
    
    string name;
    bool insurance, priorityBoarding;
    float luggage, extraLuggage;
    Order *order;
    
    Passenger()
    {
        name = "";
        insurance = false;
        priorityBoarding = false;
        luggage = 0.0f;
        extraLuggage = 0.0f;
        order = nullptr;
    }
    
    Passenger(Order *order)
    {
        char flag;
        this->order = order;
        name = order->customer->name;
        cout<<"Enter the luggage amount for the customer Mr./Ms. "<<name<<", in kgs Please.\n";
        cin>>luggage;
        if(luggage > 15.0)
            extraLuggage = luggage - 15.0f;
        if(extraLuggage > 0.0)
            this->order->payment += 500.0 * extraLuggage;
        cout<<"Is the customer eligible for insurance. y/n? \n";
        cin>>flag;
        if(flag == 'y')
            insurance = true;
        else
            insurance = false;
        cout<<"Is the customer a priority boarder. y/n? \n";
        cin>>flag;
        if(flag == 'y')
            priorityBoarding = true;
        else
            priorityBoarding = false;
    }
    
    Passenger get()
    {
        return *this;
    }
    
    int edit()
    {
        char flag;
        cout<<"Please re-enter the name of the Passenger.\n";
        getline(cin, name);
        cout<<"Enter the luggage amount for the customer Mr./Ms. "<<name<<", in kgs Please.\n";
        cin>>luggage;
        if(luggage > 15.0)
            extraLuggage = luggage - 15.0f;
        if(extraLuggage > 0.0)
            this->order->payment += 500.0 * extraLuggage;
        cout<<"Is the customer eligible for insurance. y/n? \n";
        cin>>flag;
        if(flag == 'y')
            insurance = true;
        else
            insurance = false;
        cout<<"Is the customer a priority boarder. y/n? \n";
        cin>>flag;
        if(flag == 'y')
            priorityBoarding = true;
        else
            priorityBoarding = false;
        return 0;
    }
    
    int update()
    {
        char flag;
        cout<<"Enter the luggage amount for the customer Mr./Ms. "<<name<<", in kgs Please.\n";
        cin>>luggage;
        if(luggage > 15.0)
            extraLuggage = luggage - 15.0f;
        if(extraLuggage > 0.0)
            this->order->payment += 500.0 * extraLuggage;
        cout<<"Is the customer eligible for insurance. y/n? \n";
        cin>>flag;
        if(flag == 'y')
            insurance = true;
        else
            insurance = false;
        cout<<"Is the customer a priority boarder. y/n? \n";
        cin>>flag;
        if(flag == 'y')
            priorityBoarding = true;
        else
            priorityBoarding = false;
        return 0;
    }

};

class OrderFlight
{
    public :
    
    static int flights;
    Passenger* passenger;
    
    Passenger* addPassenger(Order *order)
    {
        char flag;
        Passenger* passenger = new Passenger(order);
        cout<<"Do you want to edit the info you just entered. y/n?\n";
        cin>>flag;
        if(flag == 'y')
            passenger->edit();
        cout<<"Or do you want to update it. y/n?\n";
        cin>>flag;
        if(flag == 'y')
            passenger->update();
        cout<<"Ok, your order is being proceeded.\n";
        this->passenger = passenger;
        return this->passenger;
    }
    
    int removePassanger()
    {
        delete(&passenger);
        return 0;
    }
    
    
    float getPrice(Passenger *passenger)
    {
        Passenger gPassenger = passenger->get();
        return gPassenger.order->payment;
    }
    
    int getFlights()
    {
        return flights;
    }
};
int OrderFlight::flights = 50;

class ScheduledFlight
{
    public:
    
    static string scheduledData;
    static int capacity;
    static Passenger passengers[150];
    static float currentPrice;
    
    int addPassenger(Passenger *passenger)
    {
        if(capacity == 0)
        {
            cout<<"Sorry, no more space available. Please go to the next flight.";
            return 1;
        }
        passenger[150-capacity] = *passenger;
        capacity--;
        scheduledData += passenger->name + " is ready to board the flight.\n";
        return 0;
    }
    
    int removePassanger(Passenger *passenger)
    {
        int index = -1;
        for(int i=0;i<150;i++)
        {
            if(passengers[i].name == passenger->name)
                index = i;
        }
        if(index != -1)
        {
            for(int i = index; i < 149; i++)
                passengers[i] = passengers[i+1];
            passengers[149] = nullptr;
            capacity++;
        }
        return 0;
    }
    
    float getCurrentPrice()
    {
        return currentPrice;
    }
};
int ScheduledFlight::capacity = 150;
float ScheduledFlight::currentPrice = 10000.0;
string ScheduledFlight::scheduledData = "";
Passenger ScheduledFlight::passengers[] = {Passenger()};

class Airport
{
    public:
    
    string name, location;
    long code;
    
    Airport(string name, string location, long code)
    {
        this->name = name;
        this->location = location;
        this->code = code;
    }
    
    float getFeesPrice()
    {
        return 1500.0;
    }
};

class Flight
{
    public:
    
    static int number;
    string departure;
    string arrival;
    const float nominalPrice = 10000.0;
    Airport *airport;
    
    string getArrivalAirport(Airport *airport)
    {
        return "The Arrival airport is " + airport->name + " in " + airport->location;
    }
    
    string getDepartureAirport(Airport *airport)
    {
        return "The Departure airport is " + airport->name + " in " + airport->location;
    }
    
    float getAirportFees(Airport *airport)
    {
        return airport->getFeesPrice();
    }
};
int Flight::number = 1;

class Schedule
{
    public :
    
    int addFlight(Flight *flight, string date, Customer *customer)
    {
        char flag;
        string state;
        Order *order = new Order(customer);
        cout<<"Do you want to change user state from West Bengal to any other. y/n?\n";
        cin>>flag;
        if(flag == 'y')
        {
            cout<<"Please Enter new state.\n";
            cin.ignore(100, '\n');
            getline(cin, state);
            order->setState(state);
        }
        cout<<order->getPrice()<<" is the cost of boarding. Do you want to pay now. y/n?\n";
        cin>>flag;
        if(flag == 'y')
        {
            cout<<"Payment proceeded. \n";
            order->paymentMade = true;
        }
        else
            cout<<"Alright then. Be sure to pay it after entering all details.\n";
        
        OrderFlight *orderFlight = new OrderFlight();
        Passenger *passenger = orderFlight->addPassenger(order);
        cout<<"There are currently "<<orderFlight->getFlights()<<" flights left.\n";
        if(orderFlight->getFlights() == 0)
        {
            cout<<"Sorry, there arent any flights available at the moment.\n";
            orderFlight->removePassanger();
            delete orderFlight;
        }
        else
        {
            
            ScheduledFlight *scheduledFlight = new ScheduledFlight();
            scheduledFlight->addPassenger(passenger);
            if(order->paymentMade == false)
            {
                cout<<scheduledFlight->getCurrentPrice()<<" is the price of the flight and "<<orderFlight->getPrice(passenger)<<" is the amount to be paid. Pay now. y/n?\n";
                cin>>flag;
                if(flag == 'y')
                {
                    cout<<"Payment proceeded. \n";
                    passenger->order->paymentMade = true;
                    goto label;
                }
                else
                {
                    cout<<"Sorry then. Your order is being cancelled.\n";
                    scheduledFlight->removePassanger(passenger);
                }
            }
            else
            {
                label:
                
                cout<<"Your order has been accepted!\n";
                cout<<flight->getDepartureAirport(flight->airport)<<endl;
                cout<<"Your flight departs at "<<flight->departure<<" on "<<date<<endl;
                cout<<flight->getArrivalAirport(flight->airport)<<endl;
                cout<<"Your flight will arrive at "<<flight->arrival<<" on "<<date<<endl;
                cout<<"Please pay the airport charge of "<<flight->getAirportFees(flight->airport)<<" as soon as you reach the airport.\n";
                cout<<"Have a safe journey!\n";
            }
        }
        
        return 0;
    }
    
    int removeFlight(Flight *flight)
    {
        delete flight;
        return 0;
    }
    
};

int main()
{
    try
    {
        char flag = 'y';
        string airportName, airportLocation, departureTime, arrivalTime, date;
        long airportCode;
        cout<<"Enter details of the Airport.\n";
        getline(cin, airportName);
        getline(cin, airportLocation);
        cin>>airportCode;
        Airport *airport = new Airport(airportName, airportLocation, airportCode);
        Flight *newFlight = new Flight();
        cout<<"Enter departure time of flight.\n";
        cin.ignore();
        getline(cin, departureTime);
        cout<<"Enter arrival time of flight.\n";
        getline(cin, arrivalTime);
        newFlight->departure = departureTime;
        newFlight->arrival = arrivalTime;
        newFlight->airport = airport;
        Customer *customer = new Customer();
        customer->addNew();
        
        cout<<"Do you want to edit the information. y/n?\n";
        cin>>flag;
        if(flag == 'y')
            customer->edit();
        cout<<"Or do you want to update it. y/n?\n";
        cin>>flag;
        if(flag == 'y')
            customer->update();
        cout<<"Do you want to proceed to order the flight. y/n?\n";
        cin>>flag;
        if(flag == 'y')
        {
            cout<<"Please enter date of departure.\n";
            cin.ignore();
            getline(cin, date);
            Schedule *schedule = new Schedule();
            schedule->addFlight(newFlight, date, customer);
        }
        else
            delete customer;
        ScheduledFlight schedule;
        cout<<"Passengers log -> \n"<<schedule.scheduledData;
    }
    catch(...)
    {
        cout<<"Please enter proper input.\n";
    }
    return 0;
}