#include "UI/UIHelper.hpp"

void UIHelper::centerText(
    sf::Text& text,
    float x,
    float y
)
{
    const sf::FloatRect bounds =
        text.getLocalBounds();

    text.setOrigin(
        bounds.left + bounds.width / 2.f,
        bounds.top + bounds.height / 2.f
    );

    text.setPosition(x, y);
}

