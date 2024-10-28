#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Car {
    string registrationPlate;
    int engineCapacity;
};

int main() {
    cout << "Cars that are available in the garage but not ready for departure: \n";
    queue<Car> randomQueue;
    queue<Car> departureQueue;

    randomQueue.push({ "1245", 1500 });
    randomQueue.push({ "1246", 1300 });
    randomQueue.push({ "1248", 1600 });
    randomQueue.push({ "1247", 1100 });

    while (!randomQueue.empty()) {
        Car car = randomQueue.front();
        randomQueue.pop();

        if ((car.registrationPlate.back() - '0') % 5 == 0) {  
            departureQueue.push(car);
        }
        else {
            cout << "\nCar with registration plate " << car.registrationPlate
                << " that is not ready for departure .\n";
        }
    }

    int choice;
    while (true) {
        cout << "\nSelect an action:\n";
        cout << "Press 1: Depart the car with the smallest engine capacity.\n";
        cout << "Press 2: Display the number of cars remaining in the queue for departure.\n";
        
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (departureQueue.empty()) {
                cout << "No cars are available for departure.\n";
                continue;
            }

            queue<Car> tempQueue;
            Car carToDepart = departureQueue.front();
            departureQueue.pop();

            // Find the car with the smallest engine capacity
            while (!departureQueue.empty()) {
                Car currentCar = departureQueue.front();
                departureQueue.pop();
                if (currentCar.engineCapacity < carToDepart.engineCapacity) {
                    tempQueue.push(carToDepart);
                    carToDepart = currentCar;
                }
                else {
                    tempQueue.push(currentCar);
                }
            }

            cout << "Departing car with registration plate " << carToDepart.registrationPlate
                << " and engine capacity " << carToDepart.engineCapacity << "cc.\n";

            departureQueue = tempQueue;
        }
        else if (choice == 2) {
            cout << "Cars that are remaining in the queue for departure: " << departureQueue.size() << "\n";
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
