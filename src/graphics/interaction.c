#include "interaction.h"
#include "raylib.h"

bool	is_btn_clicked(Rectangle rectangle)
{
	Vector2 mouse;

	mouse = GetMousePosition();
	return (CheckCollisionPointRec(mouse, rectangle) == true &&
			IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true);
}

bool	is_mouse_hover(Rectangle rectangle)
{
	Vector2 mouse;

	mouse = GetMousePosition();
	return (CheckCollisionPointRec(mouse, rectangle) == true);
}
