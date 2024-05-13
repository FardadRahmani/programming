#include <iostream>
#include "Vector3.hpp"
#include "Shape.hpp"
#include "Cube.hpp"
#include "Player.hpp"
#include "Sphere.hpp"
#include <vector>
#include <memory>



using namespace std;

enum Menu {
    AddShape = 1,
    DisplayShapes = 2,
    EditShapes = 3,
    SaveAll = 4

};


int main() {
    
    vector<shared_ptr<Shape>> shapes{};
    bool startEngine;
    Menu menuSelect;

    cout << "Start up engine? 0: No, 1: Yes" << endl;
    cin >> startEngine;

    while (startEngine)
    {
        cout << "1: Add Shape   2: Display Shapes   3: Edit Shapes   4: Save Progress";
        int selection{ Menu::SaveAll };
        cin >> selection;

        switch (menuSelect)
        {
        case 1:
            cout << "Add:" << endl;
            cout << "1:Cube   2:Sphere   3: Light   4: Player Character" << endl;
            int objSelection;
            cin >> objSelection;
            if (objSelection == 1) 
            { 
                cout << "Please enter the Size of the Cube:" << endl;
                float w, l, h;
                cout << "width="; cin >> w;
                cout << "length="; cin >> l;
                cout << "height="; cin >> h;
                shapes.push_back(make_shared<Cube>(0, 0, 0, w, l, h));
                                
            }
            else if (objSelection == 2)
            {
                cout << "Please enter the Radius of the Sphere:" << endl;
                float r;
                cout << "Radius="; cin >> r;
                shapes.push_back(make_shared<Sphere>(0, 0, 0, r));
            }
            else if (objSelection == 4) 
            {
                bool npc; string name;
                cout << "0: Playable Character   1: NPC" << endl;                
                cin >> npc;
                cout << "Name=" << endl; cin >> name;
                shapes.push_back(make_shared<Player>(0, 0, 0, npc, name));
            }
            break;
        }

    }

    return 0;
}