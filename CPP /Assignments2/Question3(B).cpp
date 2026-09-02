#include<iostream>
using namespace std;

namespace Physics {
    double clamp(double val, double min, double max){
        // clamp a velocity
        if(val >= min and val <= max){
            return val;
        }else if(val < min){
            return min;
        }else{
            return max;
        }
    }
    double lerp(double a, double b, double t){
        // linear interpolation for
        return a + t * (b-a);
    }
}

namespace GameMath {
    int clamp(int val, int min, int max){
        // clamp an integer stat (health, level)
        if(val >= min and val <= max){
            return val;
        }else if(val < min){
            return min;
        }else{
            return max; 
        }
    }
    double lerp(double a, double b, double t){
        // lerp for UI animations
        return a+t*(b-a);
    }
}
int main()
{
    // Physics namespace
    using namespace Physics;
    double velocity = clamp(10, 20, 30);
    cout << "Clamped velocity: " << velocity << endl;

    double physicsValue = lerp(10, 20, 0.5);
    cout << "Physics lerp: " << physicsValue << endl;


    // GameMath namespace
    int health = GameMath::clamp(120, 0, 100);
    cout << "Clamped health: " << health << endl;

    double uiValue = GameMath::lerp(0, 100, 0.25);
    cout << "GameMath lerp: " << uiValue << endl;

    return 0;
}
