int main()
{
string binary;
string binary2;
cout << "Enter a binary string: ";
cin >> binary;
int decimal = 0;
int power = 1;
for (int i = binary.length() - 1; i >= 0; i--)
{
    if (binary[i] == '1')
    {
        decimal += power;
    }
    power *= 2;

}
cout << binary << " = " << decimal << " in decimal." << endl;

cout << endl;
cout << "Enter a decimal number: ";
cin >> decimal;
int dec2;
cout << "Enter a second decimal number: ";
cin >> dec2;
binary = "";
power = 1;
while (power <= decimal)
{
    power *= 2;



}
power /= 2;
while (power >= 1)
{
    if (decimal >= power)
    {
        binary += "1";
        decimal -= power;

    }
    else
    {
        binary += "0";

    }
    power /= 2;

}

cout << decimal << " = " << binary << " in binary." << endl;
power = 1;
binary2 = "";
while (power <= dec2)
{
    power *= 2;



}
power /= 2;
while (power >= 1)
{
    if (dec2 >= power)
    {
        binary2 += "1";
        dec2 -= power;

    }
    else
    {
        binary2 += "0";

    }
    power /= 2;

}
cout << dec2 << " = " << binary2 << " in binary." << endl;
string binary3="";
//"A & B = "
for (int i = binary.length() - 1; i >= 0; i--)
{
    if (binary[i] == '1' && binary2[i] == '1')
    {
        binary3 += "1";

    }
    else
    {
        binary3 += "0";

    }

}
cout << "A & B = "<< binary3 << endl;
string binary4 = "";
//"A || B = "
for (int i = binary.length() - 1; i >= 0; i--)
{
    if (binary[i] == '1' || binary2[i] == '1')
    {
        binary4 += "1";
    }
    else
    {
        binary4 += "0";
    }
}
cout << "A || B = " << binary4 << endl;


string binary5 = "";
//"A XOR B = "
for (int i = binary.length() - 1; i >= 0; i--)
{
    if (binary[i] == '0' && binary2[i] == '1')
    {
        binary5 += "1";

    }
    else if (binary[i] == '1' && binary2[i] == '0')
    {
        binary5 += "1";

    }
    else
    {
        binary5 += "0";

    }

}
cout << "A XOR B = " << binary5 << endl;

return 0;
}