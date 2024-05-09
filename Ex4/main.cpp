#include <iostream>

using namespace std;

class Fueltank{
    private:
        int m_FueltankCapacity;
        int m_Gas_grade;
    public:
        Fueltank(int FueltankCapacity=3000, int Gas=98){
            m_FueltankCapacity=FueltankCapacity;
            m_Gas_grade=Gas;
        }
    int fuel_up(int v, int gas){
        if (v>3000){
            cout<<"Error: FueltankCapacity: "<<m_FueltankCapacity<<endl;
        }
        else if(gas!=m_Gas_grade){
            cout<<"Error: Correct Gas_grade: "<<m_Gas_grade<<endl;
        }
        return 0;
    };
    int set_Gas_grade(int Gas_grade){
        m_Gas_grade=Gas_grade;
        return Gas_grade;
    }
    int get_Gas_grade(){
        return m_Gas_grade;
    };
};

class Car {
    private:
        int m_price;
        Fueltank m_fueltank;
    
    public:
        string m_brand;
        string m_model;
        int m_year;
        int m_seat;
        Car(string x, string y, int z, int s){
            m_brand=x;
            m_model=y;
            m_year=z;
            m_seat=s;
            m_price=10000;
        }
        int get_MaxSeating(){
            return m_seat;
        }
        int get_Price(){
            return m_price*m_seat;
        }
        int get_Gas_grade(){
            return m_fueltank.get_Gas_grade();
        }
        int set_Gas_grade(int Gas_grade){
            return m_fueltank.set_Gas_grade(Gas_grade);
        }
        int fuel_up(int v, int gas=98){
            return m_fueltank.fuel_up(v,gas);
        }
        
};

class BMW_Car : public Car{
    private:
    string m_DriveMode;
    
    public:
    BMW_Car(string y,int z,int s):Car("BMW",y,z,s){
        cout<<"Constructing BMW_Car\n";
        m_DriveMode = "Rear_wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};

class Audi_Car : public Car{
    private:
    string m_DriveMode;
    
    public:
    Audi_Car(string y,int z,int s):Car("Audi",y,z,s){
        cout<<"Constructing Audi_Car\n";
        m_DriveMode = "Front_wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};

class Benz_Car : public Car{
    private:
    string m_DriveMode;
    
    public:
    Benz_Car(string y,int z,int s):Car("Benz",y,z,s){
        cout<<"Constructing BMW_Car\n";
        m_DriveMode = "Front_wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};


int main(){
    Audi_Car car_2("A1", 2021, 2);
    cout << car_2.m_brand << ": Gas_grade = " << car_2.get_Gas_grade() << endl;
    car_2.set_Gas_grade(95);
    cout << car_2.m_brand << ": Gas_grade = " << car_2.get_Gas_grade() << endl;
    car_2.fuel_up(300, 99);

    return 0;
}
