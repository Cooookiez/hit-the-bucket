
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    srand(time(NULL));

    const int WIDTH  = 1000;
    const int HEIGHT = 1000;
    const float UI_TOP_HEIGHT = 50;
    const float UI_BOT_HEIGHT = 50;
    const int R = 30; //promien kuli (strzały)

    int _i;
    float _x, _y, sin, cos, alpha;

    int p_width = 30; // szerokosc platformy (tarczy)
    int p_hieght = 150; // wysokosc platformy (tarczy)
    float p_dx = 12; // szypkosc platform (tarczy)
    int margin = 20; // odleglość platrofmy (tarczy) od sciany (brzegu)
    int score[2] = {0, 0};

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Hit The Bucket");
    window.setFramerateLimit(60);

    sf::Font roboto;
    roboto.loadFromFile("assets/fonts/Roboto-Regular.ttf");

    // UI gurne
    sf::RectangleShape ui_top;
    ui_top.setPosition(sf::Vector2f(0, 0));
    ui_top.setSize(sf::Vector2f(WIDTH, UI_TOP_HEIGHT));
    ui_top.setFillColor(sf::Color::Blue);
    // wyniki
    sf::Text score_txt[2];
    score_txt[0].setFont(roboto);
    score_txt[1].setFont(roboto);
    score_txt[0].setCharacterSize(32.0);
    score_txt[1].setCharacterSize(32.0);
    score_txt[0].setFillColor(sf::Color::White);
    score_txt[1].setFillColor(sf::Color::White);

    score_txt[0].setString(to_string(score[0]));
    score_txt[1].setString(to_string(score[1]));
    score_txt[0].setPosition(sf::Vector2f(WIDTH/8*3, UI_TOP_HEIGHT/2-16));
    score_txt[1].setPosition(sf::Vector2f(WIDTH/8*5, UI_TOP_HEIGHT/2-16));
    // separator
    sf::Text score_separator;
    score_separator.setFont(roboto);
    score_separator.setString("-");
    score_separator.setCharacterSize(32.0);
    score_separator.setFillColor(sf::Color::White);
    score_separator.setPosition(sf::Vector2f(WIDTH/2, UI_TOP_HEIGHT/2-16));

    // UI dolne
    sf::RectangleShape ui_bot;
    ui_bot.setPosition(sf::Vector2f(0, HEIGHT - UI_BOT_HEIGHT));
    ui_bot.setSize(sf::Vector2f(WIDTH, UI_BOT_HEIGHT));
    ui_bot.setFillColor(sf::Color::Blue);
    // sterowanie
    sf::Text sterowanie;
    sterowanie.setString("w/s - sterowanie gracza z lewej  |  Up/Down - sterowanie gracza z prawej");
    sterowanie.setFont(roboto);
    sterowanie.setCharacterSize(22.0);
    sterowanie.setFillColor(sf::Color::White);
    sterowanie.setPosition(sf::Vector2f(150, HEIGHT - UI_BOT_HEIGHT/2 - 12 ));


    sf::RectangleShape platforma[2]; // 0 - lewy; 1 - prawy

    platforma[0].setPosition(sf::Vector2f(margin, (HEIGHT-p_hieght)/2 ));
    platforma[0].setFillColor(sf::Color::Red);
    platforma[0].setSize(sf::Vector2f(p_width, p_hieght));

    platforma[1].setPosition(sf::Vector2f(WIDTH-p_width-margin, (HEIGHT-p_hieght)/2 ));
    platforma[1].setFillColor(sf::Color::Red);
    platforma[1].setSize(sf::Vector2f(p_width, p_hieght));

    // pierwszy strzal
    float v = 12.0, vx = 12.0, vy = 0.0;
    if(rand()%2){
        vx = -vx;
    }

    // kula
    sf::CircleShape ball;
    ball.setRadius(R);
    ball.setFillColor(sf::Color::Blue);
    ball.setPosition(sf::Vector2f(WIDTH/2-R, HEIGHT/2-R));

    while( window.isOpen() )
    {
        // czy zamknac program
        sf::Event e;
        while( window.pollEvent(e) )
        {
            // jesli escape lub przyciksk zamkniecia okna
            if( e.type == sf::Event::Closed || (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) )
                window.close();
                
        }

        // pozycja platform
        // lewa
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
        {
            _x = platforma[0].getPosition().x;
            _y = platforma[0].getPosition().y;
            _y -= p_dx;

            if( _y <= 0 )
                _y = 0;
            platforma[0].setPosition(sf::Vector2f(_x, _y));
        }
        else if( sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
        {
            _x = platforma[0].getPosition().x;
            _y = platforma[0].getPosition().y;
            _y += p_dx;

            if( _y >= HEIGHT - p_hieght )
                _y = HEIGHT - p_hieght;
            platforma[0].setPosition(sf::Vector2f(_x, _y));
        }
        // prawa
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
        {
            _x = platforma[1].getPosition().x;
            _y = platforma[1].getPosition().y;
            _y -= p_dx;

            if( _y <= 0 )
                _y = 0;
            platforma[1].setPosition(sf::Vector2f(_x, _y));
        }
        else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
        {
            _x = platforma[1].getPosition().x;
            _y = platforma[1].getPosition().y;
            _y += p_dx;

            if( _y >= HEIGHT - p_hieght )
                _y = HEIGHT - p_hieght;
            platforma[1].setPosition(sf::Vector2f(_x, _y));
        }
        
        // odbija kule jesli trafi na tarcze
        _x = ball.getPosition().x;
        _y = ball.getPosition().y;
        _x += vx;
        _y += vy;
        ball.setPosition(sf::Vector2f(_x, _y));
        // lewy
        if( _x < margin + R && ball.getGlobalBounds().intersects(platforma[0].getGlobalBounds()) )
        {
            ball.setPosition(sf::Vector2f(margin + R, _y));
            vx *= -1;
        }
        // prawy
        if( _x > WIDTH - p_width - margin - 2*R && ball.getGlobalBounds().intersects(platforma[1].getGlobalBounds()) )
        {
            ball.setPosition(sf::Vector2f(WIDTH - p_width - margin - 2*R, _y));
            vx *= -1;
        }

        // odbija pilke jesli trafi na gurna lub dolna krawec
        if( _y < 0 )
        {
            _y = 0;
            vy *= -1;
        }
        else if( _y > HEIGHT - 2*R )
        {
            _y = HEIGHT - 2*R;
            vy *= -1;
        }

        //rysuje
        window.clear();

        window.draw(ball);
        window.draw(platforma[0]);
        window.draw(platforma[1]);

        window.draw(ui_top);
        window.draw(score_txt[0]);
        window.draw(score_txt[1]);
        window.draw(score_separator);

        window.draw(ui_bot);
        window.draw(sterowanie);

        window.display();
    }

    return 0;

}