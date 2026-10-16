#ifndef M3_H
#define M3_H
#include <iostream>
#include <vector>
using namespace std;
#include "M2.h"
class Rental{
private:
    int rentalID;
    int customerID;
    int vehicleID;
    int days;
    double totalCost;
    bool active;

public:
    Rental(int rid, int cid, int vid, int d, double cost){
        rentalID = rid;
        customerID = cid;
        vehicleID = vid;
        days = d;
        totalCost = cost;
        active = true;
    }
    int getRentalID() const{
        return rentalID;
    }
    int getVehicleID() const{
        return vehicleID;
    }
    bool isActive() const{
        return active;
    }
    void completeRental(){
        active = false;
    }
    void displayRental() const{
        cout << "\nRental ID: " << rentalID;
        cout << "\nCustomer ID: " << customerID;
        cout << "\nVehicle ID: " << vehicleID;
        cout << "\nRental Days: " << days;
        cout << "\nTotal Cost: " << totalCost;
        cout << "\nStatus: "
             << (active ? "Active" : "Completed");
        cout << "\n-----------------------------\n";
    }
};

class RentalManager{
private:
    vector<Rental> rentals;
    int nextRentalID;
public:
    RentalManager(){
        nextRentalID = 1;
    }
    void createBooking(VehicleManager &vm){
        int customerID, vehicleID, days;
        cout << "Enter Customer ID: ";
        cin >> customerID;
        cout << "Enter Vehicle ID: ";
        cin >> vehicleID;
        if (!vm.vehicleExists(vehicleID)){
            cout << "Vehicle Does Not Exist!\n";
            return;
        }
        if (!vm.vehicleIsAvailable(vehicleID)){
            cout << "Vehicle Is Not Available!\n";
            return;
        }
        cout << "Enter Number Of Rental Days: ";
        cin >> days;
        if (days <= 0){
            cout << "Rental Days Must Be Greater Than Zero!\n";
            return;
        }
        double price = vm.getVehiclePrice(vehicleID);
        double cost = price * days;
        if (!vm.rentVehicle(vehicleID))
            return;
        Rental r(
            nextRentalID,
            customerID,
            vehicleID,
            days,
            cost
        );
        rentals.push_back(r);
        cout << "\nBooking Successful!";
        cout << "\nRental ID: " << nextRentalID;
        cout << "\nTotal Rental Cost: " << cost << endl;
        nextRentalID++;
    }
    void displayAllRentals() const{
        if (rentals.empty()){
            cout << "No Rental Records Found.\n";
            return;
        }
        for (const Rental &r : rentals)
            r.displayRental();
    }
    void displayActiveRentals() const{
        bool found = false;
        for (const Rental &r : rentals){
            if (r.isActive()){
                r.displayRental();
                found = true;
            }
        }
        if (!found)
            cout << "No Active Rentals.\n";
    }
    void returnRental(VehicleManager &vm){
        int rentalID;
        cout << "Enter Rental ID: ";
        cin >> rentalID;
        for (Rental &r : rentals){
            if (r.getRentalID() == rentalID && r.isActive()){
                if (!vm.returnVehicle(r.getVehicleID()))
                    return;
                r.completeRental();
                cout << "Rental Completed Successfully!\n";
                return;
            }
        }
        cout << "Active Rental Record Not Found!\n";
    }
};
#endif