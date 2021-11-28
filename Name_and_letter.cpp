#include "std_lib_facilities.h"

int main()
{
    cout << "Enter the name of the person you want to write to:\n";
    string first_name;
    cin >> first_name;
    cout << "Dear" << first_name << ",\n";
    cout << "How are you?\n";
    cout << "It's been long since I heard from you!\n";
    cout << "Enter a friend's name:\n";
    string friend_name;
    cin >> friend_name;
    cout << "Have you seen " << friend_name << "lately?\n";
    cout << "Enter given friend's sex (m or f):\n";
    string friend_sex;
    cin >> friend_sex;
    if (friend_sex == "m")
        cout << "If you see " << friend_name << ", please ask him to call me.\n";
    if (friend_sex == "f")
        cout << "If you see " << friend_name << ", please ask her to call me.\n";
    cout << "Please enter age:\n";
    int (age);
    cin >> age;
    cout << "I heard you just had a birthday and you are " << age << "years old.\n";
    if (age <= 0 || age >= 110)
        simple_error ("You're kidding!");
    if (age <= 12)
        cout << "Next year, you will be " << age+1 << "!\n";
    if (age <= 17)
        cout << "Next year, you will be able to vote!\n";
    if (age >= 70)
        cout << "I hope you are enjoying retirement.\n";
    cout << "Do you have a special someone?\n";
    string answer = "";
    cin >> answer;
    if (answer == "Yes")
        cout << "How is your pair called as?\n";
        string pair_name;
        cin >> pair_name;
        cout << "I hope you and " << pair_name << "are being well!\n";
    if (answer == "No")
        cout << "Are you meeting with others often?\n";
    cout << "Yours sincerely,\n";
    cout << " \n";
    cout << " \n";
}