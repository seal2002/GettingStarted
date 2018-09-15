#version 330 core

in vec3 ourPos;
out vec4 color;

void main()
{
	color = vec4(ourPos, 1.0f);
}