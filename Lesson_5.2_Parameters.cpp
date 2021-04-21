/*
Lesson 5.2 Samples
Pawelski
4/20/2021
Here are the sameples for todays lesson. Again, pay particular
attention to the syntax!
*/
#include <iostream>
using namespace std;

/*
Here is how to declare a global variable.
Both variables are accessible through the entire file
(i.e., program). Lastly, unless a specific value is given,
global variables are zero-initialized (i.e., stores 0).
*/
int GLOBAL_VAR_1;
int GLOBAL_VAR_2 = 6;

/*
To specific!
Can use parameters to generalize the behavior so it displays
any size rectangle.
*/
void specificRectangle() {
    cout << "# # # # \n# # # # \n\n";
}

/*
Draws a rectangle using the # symbol with the given height and width.
*/
void rectangle(int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << "# ";
        }
        cout << "\n";
    }
    cout << "\n";
}

/*
Draws a triangle with the given height. 
If a height is not specified, it draws a
triangle that is 5 high. This particular function
demonstrates how to use a default parameter.
*/
void triangle(int height = 5)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = height - 1; j > i; j--)
        {
            cout << " ";    // places the spaces before the symbols on a line
        }
        for (int j = 0; j <= i; j++)
        {
            cout << "# ";   // places the symbols on a line
        }
        cout << "\n";       // advances to the next line
    }
    cout << "\n";
}

/*
This function simplifies printing to the console
by wrapping it in a function. If you do not give
the second parameter, the function automatically
advances to the next line.
Notice how the required parameters must be before
any optional parameters.
*/
void print(string text, string end = "\n")
{
    std::cout << text << end;
}

int main()
{
    /*
    Example #1
    Demonstrates the use of global variables and what happens when
    you declare a local variable of the same name.
    */
    int GLOBAL_VAR_1 = 4;
    cout << "GLOBAL_VAR_1 in main() (local copy): " 
        << GLOBAL_VAR_1 << "\n";
    cout << "GLOBAL_VAR_1 in main() (global copy): " 
        << ::GLOBAL_VAR_1 << "\n";
    cout << "GLOBAL_VAR_2 in main(): " 
        << GLOBAL_VAR_2 << "\n";

    /*
    Example #2
    Demonstrates how we use parameters to generalize the behavior
    of a function. This promotes reuse and modularity, as these
    functions can be dropped into another program and still work.
    */
    specificRectangle();    // BAD
    rectangle(2, 4);        // GOOD
    rectangle(5, 9);
    rectangle(5, 5);

    /*
    Example #3
    Demonstrates how default parameters are used. If you don't
    specify a parameter, it uses 5 for the height!
    */
    triangle();
    triangle(3);
    triangle(7);
    triangle(1);

    /*
    Example #4
    Demonstrates what happens when you mix required parameters
    and optional parameters.
    */
    print("Hello, world!");
    print("Hello again,", "");
    print(" but this time it is one line!");

    /*
    Example #5
    In this example, you get to see how you can pass variables
    of the appropriate type as an argument.
    */
    string text;    // this is seperate from the parameter text!
    print("Enter some text to be displayed >> ", "");
    cin >> text;
    print(text);
    print("");  // this could be written better if I used 2 optional parameters
    
    int height, width;
    print("Enter the height for the rectangle >> ", "");
    cin >> height;
    print("Enter the width for the rectangle >> ", "");
    cin >> width;
    rectangle(height, width);

    /*
    This example has the added bonus of showing how you reuse
    functions!
    */
    int side;
    print("Enter the side length for the square >> ", "");
    cin >> side;
    rectangle(side, side);
    return 0;
}
