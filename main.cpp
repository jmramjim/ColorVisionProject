#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string getColorName(int color, vector<string> colors);
void checkColorPair(int color1, int color2, bool &safe);

int main()
{
    vector<string> colors = {"Red", "Blue", "Green", "Yellow"};
    ofstream outputFile("colorResults.txt");

    bool safe;
    int color1;
    int color2;
    char again = 'y';

    while (again == 'y')
    {

    cout <<"Color Palette\n\n";

    cout << "1. Red\n";
    cout << "2. Blue\n";
    cout << "3. Green\n";
    cout << "4. Yellow\n";
    cout << "5. Monochromacy\n";
    
    cout << "Choose your first color: ";
    cin >> color1;

    if (color1 == 5)
    {
        cout << "Monochromacy is the rarest form of colorblindness affecting only 1 in 30,000 people. This colorblindness causes people to see no colors at all, the only color they see are shades of gray which means they pretty much see in black and white.";
        cout << "Would you like to test another color pair? (y/n): ";
        cin >> again;
        cout << "\n";
        continue;
    }

    cout << "Choose your second color: ";
    cin >> color2;

    checkColorPair(color1, color2, safe);
    
    outputFile << getColorName(color1, colors) << " and "
               << getColorName(color2, colors) << "\n";
    if (color1 != color2)
    {
      if (safe)
      {
          cout << "This is a safer color combination.\n";
      }
    
      else
      {
          cout << "This color combination may be difficult for people with color blindness.\n";
         cout << "Try using Red and Blue instead, they might be easier to tell apart.\n";    
      }
    }  
    cout << "You chose: ";

    cout << getColorName(color1, colors);

    cout << " and ";

    cout << getColorName(color2, colors);

    if (color1 == color2)
    {
        cout << ": You chose the same color twice, please choose again.\n";
    }

    else if ((color1 == 1 && color2 == 3) || (color1 == 3 && color2 == 1))
    {
        cout << ": These colors would be hard to tell apart for people with Red-Green color blindnesses which could include Deuteranomaly which is reduced sensitivity to the color green, or Protanopia which is reduced sensitivity to the color red Red-Green color blindness is the most common type of color blindness. Depending on the type and the severity, colors like red, green, brown, and orange can be really hard to tell apart which can make seeing things that primarily use these colors hard to understand.\n";
    }
    else if ((color1 == 2 && color2 == 3) || (color1 == 3 && color2 == 2))
    {
        cout << ": These colors would be hard to tell apart for people with Blue-Green color blindnesses which could inlude Tritanopia which is the complete inability to see the color blue and Tritanomaly which is reduced sensitivty to the color blue.\n";
    }
    else if ((color1 == 4 && color2 == 3) || (color1 == 3 && color2 == 4))
    {
        cout << ": There is no specific type of color blindness for Green and Yellow called Green-Yellow or Yellow-Green.\n";
    }
    else if ((color1 == 2 && color2 == 4) || (color1 == 4 && color2 == 2))
    {
        cout << ": These colors would be hard to tell apart for people with Blue- Yellow color blindness which could include Tritanomaly which would make it very hard to tell Blue and Yellow apart (along with the colors green and red) and another colorblindness called Tritanopia in which a person wouldnt be able to tell blue and yellow apart pretty much at all.\n";
    }
    else
    {
        cout <<": These colors would be easy for most color blindness types to tell apart.\n";
    }

    cout<< "Would you like to test another color pair? (y/n):";
    cin >> again;
    cout << "\n";
    }

    outputFile.close();

    cout << "Thank you for wanting to learn about color blindness!";
    
  return 0;
}
string getColorName(int color, vector<string> colors)
{
    return colors[color - 1];
}
void checkColorPair(int color1, int color2, bool &safe)
{
    if ((color1 == 1 && color2 == 3) ||
        (color1 == 3 && color2 == 1) ||
        (color1 == 2 && color2 == 4) ||
        (color1 == 2 && color2 == 3) ||
        (color1 == 3 && color2 == 2) ||
        (color1 == 4 && color2 == 2))
        {
            safe = false;
        }
        else
        {
            safe = true;
        }
}
