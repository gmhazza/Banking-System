#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <cstdlib>

namespace io
{
    void print_with_delay(std::string, int);
}
namespace bank
{
    int opt = 0;
    bool loop = true;
    std::fstream flag = std::fstream("data.txt", std::ios::in | std::ios::app);
    void start_menu();
    void login_menu();
    void signup_menu();
    void admin_menu();
}

int main()
{
    std::system("cls");
    while(bank::loop)
    {
        bank::start_menu();
    }
    return 0;
}

void bank::start_menu()
{
    std::cout << "Banking System" << std::endl << std::endl;
    std::cout << "1. Login\n2. Sign up\n3. Admin\n4. Exit\nChoice: ";
    std::cin >> bank::opt;
    switch(bank::opt)
    {
        case 1:
            bank::login_menu();
            break;
        case 2:
            bank::signup_menu();
            break;
        case 3:
            //bank::admin_menu();
            break;
        case 4:
            bank::loop = false;
            bank::flag.close();
            break;
        default:
            io::print_with_delay("Invalid Option Entered", 150);
            break;
    }
    return;
}

void bank::login_menu()
{
    std::string uname;
    std::string upass;
    std::cout << "Enter your Username: ";
    std::cin >> uname;
    bank::flag.seekg(0);
    while(!bank::flag.eof())
    {
        std::string data;
        bank::flag >> data;
        if(uname == data)
        {
            uname = "1";
            break;
        }
        bank::flag >> data;
    }
    std::cout << "Enter your password: ";
    std::cin >> upass;
    std::string data;
    bank::flag >> data;
    if(upass == data)
    {
        upass = "1";
    }
    if((uname == "1") and (upass == "1"))
    {
        io::print_with_delay("Login Successfully", 150);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    else
    {
        io::print_with_delay("Details didn't matched", 150);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    std::system("cls");
    return;
}

void bank::signup_menu()
{
    std::string uname;
    std::string upass;
    std::cout << "Assign your Username: ";
    std::cin >> uname;
    bank::flag.seekg(0);
    while(!bank::flag.eof())
    {
        std::string data;
        bank::flag >> data;
        if(uname == data)
        {
            std::cout << "Username already exists" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::system("cls");
            return;
        }
        bank::flag >> data;
    }
    std::cout << "Assign your Password: ";
    std::cin >> upass;
    bank::flag << uname + " " + upass + " ";
    io::print_with_delay("Account Created Successfully!", 150);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::system("cls");
    return;

}

void io::print_with_delay(std::string data, int delay)
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data.at(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    std::cout << std::endl;
}