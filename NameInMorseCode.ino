#include <vector>
#include <map>
#include <string>

const int LED_1 = D6;
const int UNIT = 1000;

const std::map<char, std::vector<bool>> letters =
{
    { 'a', { 0, 1 } },
    { 'h', { 0, 0, 0, 0 } },
    { 'n', { 1, 0 } },
    { 's', { 0, 0, 0 } },
    { 'u', { 0, 0, 1 }}
};

void setup() 
{
	pinMode(LED_1, OUTPUT);
}

void dot()
{
    digitalWrite(LED_1, HIGH);
    delay(UNIT);
    digitalWrite(LED_1, LOW);
    delay(UNIT);
}

void dash()
{
    digitalWrite(LED_1, HIGH);
    delay(3 * UNIT);
    digitalWrite(LED_1, LOW);
    delay(UNIT);
}

void letter(const std::vector<bool>& symbols)
{
    for (bool symbol : symbols)
    {
        if (symbol == 0) dot();
        else dash();
    }
    
    delay(5 * UNIT);
}

void word(const std::string wrd)
{
    for (char ch : wrd)
    {
        ch = std::tolower(ch);
        
        if (letters.find(ch) != letters.end()) letter(letters.at(ch));
    }
    
    delay(7 * UNIT);
}

void loop()
{
    word("Shaun");
}
