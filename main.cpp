
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <filesystem>

int main()
{
    srand(time(NULL));

    const int WIDTH  = 1000;
    const int HEIGHT = 1000;
    const float UI_TOP_HEIGHT = 50;
    const float UI_BOT_HEIGHT = 50;
    const int R = 50; //promien kuli (strzały)

    int _i;
    float _x, _y, tmp_vx, tmp_vy, tg;

    int p_width = 60; // szerokosc platformy (tarczy)
    int p_hieght = 300; // wysokosc platformy (tarczy)
    float p_dx = 12; // szypkosc platform (tarczy)
    int margin = 75; // odleglość platrofmy (tarczy) od sciany (brzegu)
    int score[2] = {0, 0};

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Hit The Bucket");
    window.setFramerateLimit(60);

    sf::Font roboto;
    roboto.loadFromFile("./hit-the-bucket/assets/fonts/Roboto-Regular.ttf");

    std::cout << "Current path is " << std::filesystem::current_path() << '\n';

    // textury
    sf::Texture sea_texture;
    sea_texture.setSmooth(true);
    sea_texture.loadFromFile("./hit-the-bucket/assets/images/main_background.png");

    sf::Texture tornado_texture;
    tornado_texture.setSmooth(true);
    tornado_texture.loadFromFile("./hit-the-bucket/assets/images/tornado.png");

    sf::Texture ship_left_texture;
    ship_left_texture.setSmooth(true);
    ship_left_texture.loadFromFile("./hit-the-bucket/assets/images/statek-lewy.png");

    sf::Texture ship_right_texture;
    ship_right_texture.setSmooth(true);
    ship_right_texture.loadFromFile("./hit-the-bucket/assets/images/statek-prawy.png");

    // sea
    sf::RectangleShape sea;
    sea.setPosition(sf::Vector2f(0, UI_TOP_HEIGHT));
    sea.setSize(sf::Vector2f(WIDTH, HEIGHT - UI_TOP_HEIGHT - UI_BOT_HEIGHT));
    sea.setTexture(&sea_texture);

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

    score_txt[0].setString(std::to_string(score[0]));
    score_txt[1].setString(std::to_string(score[1]));
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
    // platforma[0].setFillColor(sf::Color::Red);
    platforma[0].setSize(sf::Vector2f(p_width, p_hieght));
    platforma[0].setTexture(&ship_left_texture);

    platforma[1].setPosition(sf::Vector2f(WIDTH-p_width-margin, (HEIGHT-p_hieght)/2 ));
    // platforma[1].setFillColor(sf::Color::Red);
    platforma[1].setSize(sf::Vector2f(p_width, p_hieght));
    platforma[1].setTexture(&ship_right_texture);

    // pierwszy strzal
    float vx = 8.0, vy = 0.0;
    if(rand()%2) vx = -vx;

    // kula
    sf::CircleShape ball;
    ball.setRadius(R);
    // ball.setFillColor(sf::Color::Blue);
    ball.setPosition(sf::Vector2f(WIDTH/2-R, HEIGHT/2-R));
    ball.setTexture(&tornado_texture);

    while( window.isOpen() )
    {
        // czy zamknac program
        sf::Event e;
        while( window.pollEvent(e) )
        {
            // jesli escape lub przyciksk zamkniecia okna
            if( e.type == sf::Event::Closed || (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) )
                window.close();

            // restart game
            if( e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::R )
            {
                vx = 12.0;
                vy = 0.0;
                if(rand()%2) vx = -vx;
                ball.setPosition(sf::Vector2f(WIDTH/2-R, HEIGHT/2-R));
                score[0] = 0;
                score[1] = 0;
                score_txt[0].setString(std::to_string(score[0]));
                score_txt[1].setString(std::to_string(score[1]));
            }
                
        }

        // pozycja platform
        // lewa
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
        {
            _x = platforma[0].getPosition().x;
            _y = platforma[0].getPosition().y;
            _y -= p_dx;

            if( _y <= UI_TOP_HEIGHT )
                _y = UI_TOP_HEIGHT;
            platforma[0].setPosition(sf::Vector2f(_x, _y));
        }
        else if( sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
        {
            _x = platforma[0].getPosition().x;
            _y = platforma[0].getPosition().y;
            _y += p_dx;

            if( _y >= HEIGHT - p_hieght - UI_BOT_HEIGHT )
                _y = HEIGHT - p_hieght - UI_BOT_HEIGHT;
            platforma[0].setPosition(sf::Vector2f(_x, _y));
        }
        // prawa
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
        {
            _x = platforma[1].getPosition().x;
            _y = platforma[1].getPosition().y;
            _y -= p_dx;

            if( _y <= UI_TOP_HEIGHT )
                _y = UI_TOP_HEIGHT;
            platforma[1].setPosition(sf::Vector2f(_x, _y));
        }
        else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
        {
            _x = platforma[1].getPosition().x;
            _y = platforma[1].getPosition().y;
            _y += p_dx;

            if( _y >= HEIGHT - p_hieght - UI_BOT_HEIGHT )
                _y = HEIGHT - p_hieght - UI_BOT_HEIGHT;
            platforma[1].setPosition(sf::Vector2f(_x, _y));
        }
        
        // odbija kule jesli trafi na tarcze
        _x = ball.getPosition().x;
        _y = ball.getPosition().y;
        // cout << _x << "\t" << _y <<  "\t|\t" << vx << "\t" << vy << "\t" << endl;
        _x += vx;
        _y += vy;
        ball.setPosition(sf::Vector2f(_x, _y));
        // lewy
        if( _x < margin + R && ball.getGlobalBounds().intersects(platforma[0].getGlobalBounds()) )
        {
            ball.setPosition(sf::Vector2f(margin + R, _y));
            vx *= -1;
            vy += rand()%21-10;
            vy = vy > 10 ? 10:vy;
            vy = vy < -10 ? -10:vy;

        }
        // prawy
        if( _x > WIDTH - p_width - margin - 2*R && ball.getGlobalBounds().intersects(platforma[1].getGlobalBounds()) )
        {
            ball.setPosition(sf::Vector2f(WIDTH - p_width - margin - 2*R, _y));
            vx *= -1;
            vy += rand()%21-10;
            vy = vy > 10 ? 10:vy;
            vy = vy < -10 ? -10:vy;
        }

        // odbija pilke jesli trafi na gurna lub dolna krawec
        if( _y < UI_TOP_HEIGHT )
        {
            _y = 0;
            vy *= -1;
        }
        else if( _y > HEIGHT - 2*R - UI_BOT_HEIGHT)
        {
            _y = HEIGHT - 2*R;
            vy *= -1;
        }

        // restartuje pilke i nalicza pkt jestli trafi w sciane
        // + pkt dla lewego
        if( _x >= HEIGHT - 2*R )
        {
            score[0]++;
            vx = 12.0;
            vy = 0.0;
            if(rand()%2) vx = -vx;
            ball.setPosition(sf::Vector2f(WIDTH/2-R, HEIGHT/2-R));
            score_txt[0].setString(std::to_string(score[0]));
        }
        // + pkt dla prawego
        if( _x <= 0 )
        {
            score[1]++;
            vx = 12.0;
            vy = 0.0;
            if(rand()%2) vx = -vx;
            ball.setPosition(sf::Vector2f(WIDTH/2-R, HEIGHT/2-R));
            score_txt[1].setString(std::to_string(score[1]));
        }

        //rysuje
        window.clear();

        window.draw(sea);

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