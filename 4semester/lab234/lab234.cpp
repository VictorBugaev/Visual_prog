#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <cmath>


using namespace std;

class Coordinates{
private:
    int X, Y;
public:
    Coordinates(int x, int y){
        X = x;
        Y = y;
    }

};
int dist_coord(int x1, int y1, int x2, int y2){
    int xx = pow((x2 - x1), 2);
    int yy = pow((y2 - y1), 2);
    return sqrt( xx + yy );
}

struct Object{
private:
    int ID;
    int x, y;
    int speed;
    int count_coord;
    vector<Coordinates*> path;
    int rast = 0;
    
public:
    Object(int id, int x1, int y1, int sp ){
        ID = id;
        x = x1;
        y = y1;
        speed = sp;
        count_coord = 1;
        Coordinates *C = new Coordinates(x, y);
        path.push_back(C);
    }
    int get_ID(){
        return ID;
    }
    int get_count_coord(){
        return path.size();
    }
    int get_speed(){
        return speed;
    }
    void set_speed(int sp){
        speed = sp;
    }
    int get_rast(){
        return rast;
    }
    int get_x(){
        return x;
    }
    int get_y(){
        return y;
    }
    int rast_to_object(Object *OBJ){
        return dist_coord(x, y, OBJ->get_x(), OBJ->get_y());
    }
    void RandomWalk(int SIZE_X, int SIZE_Y){
        int rw = rand() % 4;
        if(rw == 0){
            if(x + speed < SIZE_X){
                int x_old = x;
                x += speed;
                Coordinates *C = new Coordinates(x, y);
                path.push_back(C);
                rast += dist_coord(x_old, y, x, y);
            }
        }
        else if(rw == 1){
            if(x - speed > 0){
                int x_old = x;
                x -= speed; 
                Coordinates *C = new Coordinates(x, y);
                path.push_back(C);
                rast += dist_coord(x_old, y, x, y);
            }
        }
        else if(rw == 2){
            if(y + speed < SIZE_Y){
                int y_old = y;
                y -= speed; 
                Coordinates *C = new Coordinates(x, y);
                path.push_back(C);
                rast += dist_coord(x, y_old, x, y);
            }
        }
        else if(rw == 3){
            if(y - speed > 0){
                int y_old = y;
                y -= speed; 
                Coordinates *C = new Coordinates(x, y);
                path.push_back(C);
                rast += dist_coord(x, y_old, x, y);
            }
        }
        //rast += dist_coord()
    }
    void Gaussian_M(){

    }
    void Chains(){

    }
    void Waypoint(){

    }

};



int main(){
    int i, i2;
    int count_ob;
    int count_move;
    int SIZE_X = 1000, SIZE_Y = 1000;

    cout<<"Input count objects: ";
    cin>>count_ob;
    cout<<"Input count move: ";
    cin>>count_move;

    Object **obj = new Object*[count_ob];
    int ID;
    int srav;
    for(i = 0; i < count_ob; ++i){
        while(1){
            srav = 1;
            ID = 10 + (rand() % 99999);
        
            for(i2 = 0; i2 < i; ++i2){
                if(obj[i2]->get_ID() == ID){
                    srav = 0;
                    break;
                }
            }
            if(srav == 1){
                break;
            }
        }
        obj[i] = new Object(ID, rand() % SIZE_X, rand() % SIZE_Y, (rand() % 20) + 30);
        
        cout<<"new id = "<<obj[i]->get_ID()<<"\n";
    }
    for(i = 0; i < count_move; ++i){
    
        for(i2 = 0; i2 < count_ob; ++i2){
            obj[i2]->RandomWalk(SIZE_X, SIZE_Y);
        }
    }
    cout<<"movement completed: "<<count_move<<"\n";
    
    for(i = 0; i < count_ob; ++i){
        cout<<"ID: "<<obj[i]->get_ID()<<"\n";
        cout<<"\tcount coord = "<<obj[i]->get_count_coord()<<"\n";
        cout<<"\trast = "<<obj[i]->get_rast()<<"\n";
        cout<<"\tspeed = "<<obj[i]->get_speed()<<"\n";

    }
    int ind;
    if(count_ob > 1){
        cout<<"Input id: ";
        cin>>ID;
        srav = 0;
        for(i = 0; i < count_ob; ++i){
            if(ID == obj[i]->get_ID()){
                srav = 1;
                ind = i;
                break;
            }
        }
        if(srav == 1){
            for(i = 0; i < count_ob; ++i){
                if(obj[i]->get_ID() != ID){
                     cout<<"rast to id("<<obj[i]->get_ID()<<") = "<<obj[ind]->rast_to_object(obj[i])<<"\n";
                }
               
            }
        }
        else{
            cout<<"Not found ID\n";
        }
    }

    cout<<"END\n";
}
