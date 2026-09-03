#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Texture
{
private:
    string name;
    int width;
    int height;

public:
    // Constructor
    Texture(string n, int w, int h)
    {
        name = n;
        width = w;
        height = h;

        cout << "[Texture Loaded]" << endl;
    }

    // Destructor
    ~Texture()
    {
        cout << "[Texture Released]" << endl;
    }

    // Display function
    void display() const
    {
        cout << "Texture Name : " << name << endl;
        cout << "Dimensions   : " << width << " x " << height << endl;
    }
};

int main()
{
    // 1. Create Texture using make_unique
    auto tex1 = make_unique<Texture>("player_sprite", 512, 512);

    // 2. Call display through unique_ptr
    tex1->display();

    // 3. Copying unique_ptr is NOT allowed
    // unique_ptr<Texture> tex2 = tex1;
    // ERROR: unique_ptr cannot be copied because it has exclusive ownership.

    // 4. Transfer ownership using move()
    unique_ptr<Texture> tex2 = move(tex1);

    // tex1 no longer owns the Texture
    cout << "tex1 is null: "
         << (tex1 == nullptr ? "YES" : "NO") << endl;

    // tex2 now owns the Texture
    cout << "tex2 owns the Texture." << endl;

    tex2->display();

    // 5. tex2 goes out of scope here.
    // Destructor automatically runs.

    return 0;
}
