#include <SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
int state=9;
int clrdep=0;
int statusMsg=0;
using namespace sf;
int func(Text& text);


void hover(Text& text, RenderWindow& window)
{


    auto mouse_position = Vector2f(Mouse::getPosition(window));
        if(text.getGlobalBounds().contains(mouse_position))
        {
            text.setFillColor(Color::Cyan);
            if(Mouse::isButtonPressed(Mouse::Button::Left))

            {
                text.setFillColor(Color::Yellow);

                func(text);
            }

        }
        else
            {
            text.setFillColor(Color::White);
            }
}
int func(Text& text)
{
    if(text.getString()=="Check\nBalance")
    {
        state=1;
    }
    else if(text.getString()=="Deposit")
    {

        state=2;
    }

    else if(text.getString()=="Withdraw")
    {
        state=3;
    }

    else if(text.getString()=="Return")
    {
        clrdep=1;
        state=0;
        statusMsg=0;


    }
    else if(text.getString()=="Transaction\nHistory")
    {
        state=4;
    } else if(text.getString()=="Exit")
    {
        state=5;

    }

    return clrdep;


}


/** Main**/

int getBalance ()
{

    std::ifstream file("balance.txt");

    int balance2;
    file>>balance2;

    file.close();
    return balance2;
}

/** Deposit Backend**/




int main()
{
    bool showMsg=true;
     int amountInt=0;

    sf::RenderWindow window(sf::VideoMode({800, 600}), "ATM");


Texture texture("atmbg.png");
Sprite bg(texture);




    Font font("PixelFont.ttf");


    /// INPUT BOX


    RectangleShape inputBox;
    inputBox.setSize({120,30});
    inputBox.setOrigin({60,15});
    inputBox.setPosition({575,270});
    inputBox.setFillColor(Color::Transparent);
    inputBox.setOutlineThickness({3});
    inputBox.setOutlineColor(Color::White);


    ///Return Option

    Text Return(font,"Return", 20);
    Return.setPosition({85,370});



    /** LOGIN **/

    std::string username="";
        std::string usernameShow="String aint working";

Texture log("login.png");
Sprite loginpage(log);
loginpage.setScale({2.68,1.2});

Text logintext(font, "USERNAME:", 45);
logintext.setPosition({250,120});

RectangleShape usernameBox;
usernameBox.setSize({300,45});
usernameBox.setOrigin({50,25});
usernameBox.setPosition({290, 200});
usernameBox.setFillColor(Color::Transparent);
usernameBox.setOutlineThickness({3});
usernameBox.setOutlineColor(Color::White);

Text loginTextPass(font, "PASSWORD:", 45);
loginTextPass.setPosition({250,250});

RectangleShape passwordBox;
passwordBox.setSize({300,45});
passwordBox.setOrigin({50,25});
passwordBox.setPosition({290, 330});
passwordBox.setFillColor(Color::Transparent);
passwordBox.setOutlineThickness({3});
passwordBox.setOutlineColor(Color::White);

Text userShow(font,username, 50);
userShow.setPosition({290,170});

        std::string password="";


        Text PasShow(font,password, 50);
        PasShow.setPosition({290,300});

        Text wrongPass(font,"Invalid username or password!", 35);
        wrongPass.setPosition({120,480});
        wrongPass.setFillColor(Color(255,0,0));







    /** State 0**/
    Text Balance(font, "Check\nBalance",20);
    Balance.setPosition({85,80});

    Text Deposit(font, "Deposit",20);
    Deposit.setPosition({85,170});

    Text Withdraw(font, "Withdraw",20);
    Withdraw.setPosition({85,240});

    Text History(font, "Transaction\nHistory",20);
    History.setPosition({75,310});


    Text Exit(font, "Exit",20);
    Exit.setPosition({85,390});






/** State 1**/

Texture texture1("terminal.png");
Sprite blnc(texture1);
Text BalanceCheck(font,"CHECK BALANCE", 45);
BalanceCheck.setPosition({260,90});


    ///balance
        int balance=1;


    balance=getBalance();


    Text balanceText(font, "Balance:" + std::to_string(balance), 30);
    balanceText.setPosition({240,250});





/** State 2**/

Text Depotxt(font, "DEPOSIT",40);
Depotxt.setPosition({300,90});

    Text DepoAmount(font, "Enter amount:", 30);
    DepoAmount.setPosition({250,250});



     Text inputText(font);
    inputText.setPosition({545,250});


            Text DepositedMsg(font, "Deposited", 30);
                    DepositedMsg.setPosition({555,290});
                    DepositedMsg.setFillColor(Color::White);





/** State 3**/

Text Withdrawtxt(font, "WITHDRAW",40);
Withdrawtxt.setPosition({300,90});

    Text  WDAmount(font, "Enter amount:", 30);
    WDAmount.setPosition({250,250});


            Text WDMsg(font, "Withdrawed", 30);
                    WDMsg.setPosition({555,290});
                    WDMsg.setFillColor(Color::White);




/** State 4**/

Text Historytxt(font, "Transaction History",40);
Historytxt.setPosition({200,90});

//DEPOSIT HISTORY SHOW

Text DepoHistory(font, "DEPOSITED",30);
DepoHistory.setPosition({250,190});
DepoHistory.setFillColor(Color::White);

//WITHDRAW HISTORY SHOW

Text WithdrawHistory(font, "WITHDRAWED",30);
WithdrawHistory.setPosition({550,190});
WithdrawHistory.setFillColor(Color::White);




    /** Less than avail**/

    Text invaliD(font, "Not enough balance!",30);
    invaliD.setPosition({400,290});
    invaliD.setFillColor(Color::Red);


            int loginNum=0;

        std::string amount="";

    while(window.isOpen())
    {

        while(std::optional event=window.pollEvent())

        {
            if(event->is<Event::Closed>())
                window.close();

            else if(event->is<Event::Resized>())
                {std::cout<<"Resized";}

             if(state==2 || state==3 || state==9)
             {


                if(const auto* textEntered= event->getIf<Event::TextEntered>())

                    if(state==2 || state==3)
                    {


                    if(textEntered->unicode>='0' && textEntered->unicode<='9')
                    {

                        amount+=static_cast<char>(textEntered->unicode);


                    }

                    }
                        else if(state==9 && loginNum==0)
                    {
                        username+=static_cast<char>(textEntered->unicode);
                    }
                        else if(state==9 &&loginNum==1)
                        {
                             if(textEntered->unicode >= '0' && textEntered->unicode <= '9')
                            {

                            password+=static_cast<char>(textEntered->unicode);
                        }

                        }



        }




             if(event->is<Event::KeyPressed>())
             {
                    auto key=event->getIf<Event::KeyPressed>();
                if(key->scancode==Keyboard::Scancode::Enter)
                    {


                    if(state==2 || state==3)
                    {

                        if(!amount.empty())
                        {

                    amountInt= std::stoi(amount);
                        }
                    statusMsg=1;



        if(state==2)
{

balance += amountInt;

std::ofstream file1("balance.txt");
file1<<balance;
file1.close();

std::ofstream file ("DepositH.txt",std::ios::app);
file<<amountInt<<"\n";
file.close();


balanceText.setString("Balance: " + std::to_string(balance));
amount.clear();


}

    else if(state==3)
{
    if(amountInt<=balance)
    {

    balance -= amountInt;

std::ofstream file1("balance.txt");
file1 << balance;
file1.close();

std::ofstream file ("WDH.txt",std::ios::app);
file<<amountInt<<"\n";
file.close();


balanceText.setString("Balance: " + std::to_string(balance));
amount.clear();
    }

    else if(amountInt>balance)
    {
        statusMsg=3;
    }







}


        }
                    else if(state==9 && loginNum==0)
                    {


                        loginNum=1;

                    }
            else
                loginNum=2;



                    }
                }

        }







                hover(Balance,window);
                hover(Deposit,window);
                hover(Withdraw,window);
                hover(History,window);
                hover(Exit,window);
                hover(Return,window);





window.clear();

///DEFAULT STATE

if(state==9)

{
    std::string savedUsername;
        std:: string savedPassword;

     window.setSize(Vector2u({400,600}));
    window.draw(loginpage);

    window.draw(logintext);
    window.draw(usernameBox);

    window.draw(loginTextPass);
    window.draw(passwordBox);

    userShow.setString(username);


    window.draw(userShow);

    if(loginNum==1 || loginNum==2)
    {
        PasShow.setString(password);


    window.draw(PasShow);


}
if(loginNum==2)
{


    std::ifstream file("Accounts.txt");

    while (std::getline(file, savedUsername) &&
       std::getline(file, savedPassword))




    if(savedUsername==username && savedPassword==password)
    {
        window.setSize(Vector2u({800,600}));
        state=0;

    }
    else
        {

        window.draw(wrongPass);
    }


}


}

else if(state==0)
{

    Deposit.setPosition({85,170});

    Withdraw.setPosition({85,240});




        window.draw(bg);
        window.draw(Balance);
        window.draw(Deposit);
        window.draw(Withdraw);
        window.draw(History);
        window.draw(Exit);



}

    ///BALANCE STATE

else if(state==1)
{
    Deposit.setPosition({85,230});

    Withdraw.setPosition({85,300});


    window.draw(blnc);
    window.draw(BalanceCheck);
    window.draw(Deposit);
    window.draw(Withdraw);
    window.draw(Return);
    window.draw(balanceText);


}

    ///DEPOSIT STATE

else if(state==2)
{



    window.draw(blnc);  //bg
    window.draw(Depotxt);   //deposit heading
    window.draw(DepoAmount);    //ask amount

    window.draw(Return);           //return option
    window.draw(inputBox);          //input box rect

     inputText.setString(amount);   //takes and display input

    if(clrdep==1)
    {

    amount.clear();
    clrdep=0;


    }



    window.draw(inputText);

        if(statusMsg==1)
        {

    window.draw(DepositedMsg);


        }



}


    ///WITHDRAW STATE

else if(state==3)
        {

window.draw(blnc);
window.draw(Withdrawtxt);
window.draw(inputBox);
window.draw(WDAmount);
 inputText.setString(amount);
    window.draw(Return);

    if(clrdep==1)
    {

    amount.clear();
    clrdep=0;
    }
window.draw(inputText);

        if(statusMsg==1)
        {

    window.draw(WDMsg);

        }

        if(statusMsg==3)
    {
    window.draw(invaliD);
    }

            }



    ///HISTROY STATE




else if(state==4)
{

window.draw(blnc);
window.draw(Historytxt);
window.draw(Return);

    window.draw(DepoHistory);
    window.draw(WithdrawHistory);

    //DEPOSITED AMOUNT SHOW
{

 std::   ifstream file("DepositH.txt");
 std::string DEPAMT;
    std::vector<std::string> DEPAMT2;

    Text DepoAmtShow(font,DEPAMT,30);

    while(std::getline(file,DEPAMT))

    {

    DEPAMT2.push_back(DEPAMT);


    }

    file.close();




for (int i = 0; i < DEPAMT2.size(); i++)
{

    DepoAmtShow.setString(DEPAMT2[i]);



        DepoAmtShow.setPosition({250,240+i*40});
        window.draw(DepoAmtShow);
}
}



            //WITHDRAW AMOUNT SHOW
{

    std::   ifstream file("WDH.txt");
    std::string WDAMT;
    std::vector<std::string> WDAMT2;

    Text WDAmtShow(font,WDAMT,30);

    while(std::getline(file,WDAMT))

    {

    WDAMT2.push_back(WDAMT);


    }

    file.close();




for (int j = 0; j < WDAMT2.size(); j++)
{

    WDAmtShow.setString(WDAMT2[j]);



        WDAmtShow.setPosition({550,240+j*40});
        window.draw(WDAmtShow);
}
}



}

    ///EXIT STATE

else if(state==5)
{


    window.close();
}


  window.display();
    }




    return 0;

}

